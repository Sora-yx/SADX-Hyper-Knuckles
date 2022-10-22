#include "pch.h"
#include "hyper-knux.h"
#include "audio.h"

int ActualSong = 0;

TaskHook KnuxExec_t(KnucklesTheEchidna);
TaskHook KnuxDisplay_t(KnucklesDisplay);
TaskHook Invincibility_restart_t(0x441F80);
FunctionHook<void> Init_CharSel_LoadA_t(CharSel_LoadA);
ModelInfo* HyperKnux_Model[16] = { 0 };

int HKDXAnimTextures[] = { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };//Texture IDs for animation
int HKDCAnimTextures[] = { 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38 };//Texture IDs for animation

const int animSPD = 2;

bool isHyperKnux = false;
bool decrease = false;
float green = 0.0f;

void animateTextures()
{
	if (!isHyperKnux || GameState != 15 || charType == none)
		return;

	uint16_t texid = charType == Dreamcast ? HKDCAnimTextures[(FrameCounter / animSPD) % (LengthOfArray(HKDCAnimTextures))] : HKDXAnimTextures[(FrameCounter / animSPD) % (LengthOfArray(HKDXAnimTextures))];

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->basicdxmodel->mats[0].attr_texId = texid; //head
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->basicdxmodel->mats[0].attr_texId = texid; //chest

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg right 1
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg right 2
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg right 3

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg left 1
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg left 2
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //leg left 3

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //arm right 1
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //arm right 2

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->basicdxmodel->mats[1].attr_texId = texid; //arm right 3

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //arm left 1
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //arm left 2
	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->basicdxmodel->mats[1].attr_texId = texid; //arm left 3

	HyperKnux_Model[0]->getmodel()->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->basicdxmodel->mats[0].attr_texId = texid; //tail
}

static void Knuckles_Display_r(task* tsk)
{
	auto data = tsk->twp;

	if (!AlwaysHyperKnux)
		isHyperKnux = isPlayerOnHyperForm(data->counter.b[0]) == true ? 1 : 0;
	else
		isHyperKnux = true;

	animateTextures();
	KnuxDisplay_t.Original(tsk);
}

NJS_TEXLIST* getHyperKnuxTex()
{
	if (isHyperKnux && charType != none) {
		if (charType == Dreamcast)
			return &HyperKnuxDC_TEXLIST;
		else
			return &HyperKnuxDX_TEXLIST;
	}

	return &KNUCKLES_TEXLIST;
}

// Sets the texture list to use when rendering.
Sint32 __cdecl setHyperKnuxTexture(NJS_TEXLIST* texlist)
{
	texlist = getHyperKnuxTex();
	return njSetTexture(texlist);
}

void SubRings(unsigned char player, EntityData1* data) {
	if (RemoveLimitations || AlwaysHyperKnux || EntityData1Ptrs[player]->CharID != Characters_Knuckles
		|| !isHyperKnux || isKnuxAI(EntityData1Ptrs[player]) || !ControlEnabled || !TimeThing || GameState != 15)
		return;

	if (FrameCounterUnpaused % 60 == 0 && Rings > 0) {
		AddRings(-1);
	}

	if (Rings <= 0) {
		data->Action = hyperKnuxUntransfo;
	}

	return;
}

void unSuper(unsigned char player) {
	if (AlwaysHyperKnux)
		return;

	auto data = playertwp[player];
	auto data2 = playermwp[player];
	auto co2 = playerpwp[player];

	isQuakeEnabled = false;
	RestoreOriginalTrailColor();

	if (!data)
		return;

	if (data->counter.b[1] == Characters_Knuckles) //fix an issue with charsel
		co2->p = *(player_parameter*)&PhysicsArray[Characters_Knuckles];

	data->flag = 0;
	ForcePlayerAction(player, 24);

	if (IsIngame())
	{
		if (CurrentSFX == DBZ_SFX)
			PlayVoice(7002);

		RestoreMusic();
	}

	RestoreKnuxAnimModel(data);
	SetGlidSPD(false);
	co2->item &= ~Powerups_Invincibility;
	co2->equipment &= ~Upgrades_SuperSonic;
	return;
}

void Load_SuperAura(taskwk* data1) {
	if (!superAura) {
		return;
	}

	task* superAura = (task*)LoadObject(LoadObj_Data1, 2, Sonic_SuperAura_Load);
	if (superAura)
	{
		superAura->twp->counter.b[0] = data1->counter.b[0];
	}
}

void SetHyperKnux(CharObj2* co2, EntityData1* data1, EntityData2* data2) {
	taskwk* taskw = (taskwk*)data1;

	if (IsIngame() && CurrentSFX != None && !isPerfectChasoLevel())
		PlayVoice(7001);

	co2->Upgrades |= Upgrades_SuperSonic;
	co2->Powerups |= Powerups_Invincibility;

	SetHyperKnuxAnimModel(data1, co2, data2);
	Load_SuperAura(taskw);
	Load_HyperPhysics(taskw);
	SetGlidSPD(true);
	LoadHyperKnux_Jiggle(data1->CharIndex);
	data1->Action = 1;

	return;
}

void HyperKnux_PlayTransfoAnimation(taskwk* player) {
	if (AlwaysHyperKnux || !AnimationTransfo)
		return;

	playerpwp[player->counter.b[0]]->mj.reqaction = 38;
}

bool CheckUntransform_Input(unsigned char playerID) {
	auto player = EntityData1Ptrs[playerID];

	if (AlwaysHyperKnux)
		return false;

	if (isKnuxAI(player) && !isPlayerOnHyperForm(0)) {
		unSuper(player->CharIndex);
		return true;
	}

	if (ControllerPointers[playerID]->PressedButtons & TransformButton && !isPerfectChasoLevel())
	{
		if (player->Action == jump) {
			player->NextAction = 12;
			player->Action = 16;
			unSuper(player->CharIndex);
			return true;
		}
	}

	return false;
}

bool CheckPlayer_Input(unsigned char playerID) {
	auto data = EntityData1Ptrs[playerID];

	if (isKnuxAI(data) && isPlayerOnHyperForm(0)) {
		return true;
	}

	if (ControllerPointers[data->CharIndex]->PressedButtons & TransformButton && (Rings >= 50 || RemoveLimitations))
	{
		if (data->Action == jump) {
			data->NextAction = 12;
			data->Action = 16;
			return true;
		}
	}

	return false;
}

void HyperKnuxDelete(ObjectMaster* obj) {
	unSuper(obj->Data1->CharIndex);
	MusicList[MusicIDs_sprsonic].Name = "sprsonic";
}

void HyperKnux_Manager(ObjectMaster* obj) {
	auto data = obj->Data1;
	auto player = playertwp[obj->Data1->CharIndex];
	auto playerData2 = EntityData2Ptrs[obj->Data1->CharIndex];

	if (!player || !IsIngame())
		return;

	unsigned char playerID = data->CharIndex;
	CharObj2* co2 = CharObj2Ptrs[player->counter.b[0]];

	if (EV_MainThread_ptr)
	{
		if (co2 && isPlayerOnHyperForm(playerID))
			unSuper(playerID);

		return;
	}

	if (player->counter.b[1] != Characters_Knuckles || player->counter.b[0] == 1 && CharacterBossActive) //charsel fix
		CheckThingButThenDeleteObject(obj);

	int timer = 30;

	switch (data->Action) {
	case hyperKnuxSetTask:
		Set_AuraTextures();
		obj->DeleteSub = HyperKnuxDelete;
		data->Action++;
		break;
	case playerInputCheck:

		if (!AlwaysHyperKnux && !ControlEnabled)
			return;

		if (CheckPlayer_Input(playerID) || AlwaysHyperKnux || isPerfectChasoLevel())
			data->Action++;

		break;
	case hyperKnuxInit:
		data->Index = 0;
		player->flag &= ~Status_Ball;

		HyperKnux_PlayTransfoAnimation(player);

		data->Action++;
		break;
	case hyperKnuxWait:

		if (AlwaysHyperKnux)
			timer = 10;

		if (++data->Index == timer)
		{
			//ForcePlayerAction(player->Index, 24);
			data->Action++;
		}
		break;
	case hyperKnuxTransfo:

		SetHyperKnux(co2, (EntityData1*)player, playerData2);

		if (!isKnuxAI((EntityData1*)player) && !isPerfectChasoLevel()) {
			if (CurrentSuperMusic != None && CurrentSong != MusicIDs_sprsonic)
			{
				ActualSong = LastSong;
				Play_HyperKnuxMusic();
			}
		}
		data->Action++;
		break;
	case hyperKnuxOnFrames:

		if (!isPerfectChasoLevel()) {
			SubRings(playerID, data);
			CheckSuperMusic_Restart(playerID);
		}

		CheckKnuxAfterImages((EntityData1*)player, co2);

		if (KnucklesCheckInput((taskwk*)player, (motionwk2*)playerData2, (playerwk*)co2))
			break;

		if (CheckUntransform_Input(playerID)) {
			data->Action = playerInputCheck;
		}

		Knux_EarthQuake_InputCheck((EntityData1*)player, co2);
		InstantMaxHeat_InputCheck((EntityData1*)player, co2);
		break;
	case hyperKnuxUntransfo:
		unSuper(playerID);
		data->Action = playerInputCheck;
		break;
	default:
		CheckThingButThenDeleteObject(obj);
		break;
	}
}

int resetTimer = 0;

void Knux_Main_r(task* obj) {
	auto playerData = obj->twp;
	auto pnum = playerData->counter.b[0];
	auto co2 = (playerwk*)GetCharObj2(pnum);
	auto data2 = (motionwk2*)obj->mwp;

	switch (playerData->mode)
	{
	case 0:
	{
		Load_EyeTracker(pnum);
		ObjectMaster* HyperKnux_ObjManager = LoadObject((LoadObj)2, 0, HyperKnux_Manager);
		HyperKnux_ObjManager->Data1->CharIndex = pnum;
	}
	break;
	case 18:
		SetInstantMaxHeat(false);
		break;
	case earthQuake:
		Knux_DoEarthQuakeGround(playerData, co2);

		PResetAngle(playerData, (motionwk2*)data2, (playerwk*)co2);
		PGetRotation(playerData, (motionwk2*)data2, (playerwk*)co2);
		PGetAcceleration(playerData, (motionwk2*)data2, (playerwk*)co2);
		PGetSpeed(playerData, (motionwk2*)data2, (playerwk*)co2);
		PSetPosition(playerData, (motionwk2*)data2, (playerwk*)co2);
		PResetPosition(playerData, data2, co2);

		break;
	case 61:

		if (++resetTimer == 20) {
			playerData->mode = 1;
			co2->mj.reqaction = 0;
			resetTimer = 0;
		}

		break;
	}

	KnuxExec_t.Original(obj);
}

void __cdecl Init_HyperKnuxTextures(const char* path, const HelperFunctions& helperFunctions) {
	for (uint8_t i = 0; i < LengthOfArray(HyperKnux_DCEntry); i++) {
		helperFunctions.RegisterCharacterPVM(Characters_Knuckles, charType == Dreamcast ? HyperKnux_DCEntry[i] : HyperKnux_DXEntry[i]);
	}

	if (AlwaysHyperKnux) {
		KNUCKLES_TEXLIST = charType == Dreamcast ? HyperKnuxDC_TEXLIST : HyperKnuxDX_TEXLIST;
		std::string texPath = modpath + "\\textures\\";
		texPath += charType == Dreamcast ? "HYPERKNUX_DC" : "HYPERKNUX_DX";
		texPath += ".pvmx";
		helperFunctions.ReplaceFile("system\\KNUCKLES.PVM", texPath.c_str());
	}
}

void InitKnuxCharSelAnim_r()
{
	Init_CharSel_LoadA_t.Original();

	CharSelDataList[2].anonymous_1[0]->object = HyperKnux_Model[root]->getmodel();
	CharSelDataList[2].anonymous_1[1]->object = HyperKnux_Model[root]->getmodel();
	CharSelDataList[2].anonymous_1[2]->object = HyperKnux_Model[root]->getmodel();

	if (charType == Dreamcast) {
		CharSelDataList[2].TextureList = &HyperKnuxDC_TEXLIST;
	}
	else {
		CharSelDataList[2].TextureList = &HyperKnuxDX_TEXLIST;
	}
}

//fix character not invincibile in superform after a restart lol
void InvincibilityRestart_r(task* obj)
{
	auto data = obj->twp;
	char pID = data->counter.b[0];

	if (playerpwp[pID] && playerpwp[pID]->equipment & Upgrades_SuperSonic)
	{
		FreeTask(obj);
		return;
	}

	Invincibility_restart_t.Original(obj);
}

void __cdecl HyperKnux_Init(const char* path, const HelperFunctions& helperFunctions)
{
	Init_HyperKnuxTextures(path, helperFunctions);

	KnuxExec_t.Hook(Knux_Main_r);
	KnuxDisplay_t.Hook(Knuckles_Display_r);
	Invincibility_restart_t.Hook(InvincibilityRestart_r);

	//Textures init
	WriteCall((void*)0x47224E, setHyperKnuxTexture);

	//models
	Load_HyperKnuxModels();
	if (AlwaysHyperKnux && charType != none) {
		Init_CharSel_LoadA_t.Hook(InitKnuxCharSelAnim_r);
	}
}