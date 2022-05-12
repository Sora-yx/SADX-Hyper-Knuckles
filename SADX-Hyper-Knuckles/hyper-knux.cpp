#include "pch.h"
#include "hyper-knux.h"
#include "audio.h"

int ActualSong = 0;

Trampoline* Knuckles_Main_t = nullptr;
Trampoline* Knuckles_Display_t = nullptr;

bool isDCCharUsed = false;
bool isHyperKnux = false;

static void Knuckles_Display_r(ObjectMaster* tsk)
{
	EntityData1* data = tsk->Data1;

	isHyperKnux = isPlayerOnHyperForm(data->CharIndex) == true ? 1 : 0;

	TARGET_DYNAMIC(Knuckles_Display)(tsk);
}

void HyperKnux_PerformLightingThing() {
	if (isHyperKnux)
		Direct3D_PerformLighting(4);
	else
		Direct3D_PerformLighting(2);
}

NJS_TEXLIST* getHyperKnuxTex()
{
	if (isHyperKnux && textureChanges) {

		if (isDCCharUsed)
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


	isHyperKnux = false;

	EntityData1* data = EntityData1Ptrs[player];
	CharObj2* co2 = CharObj2Ptrs[player];

	if (!data)
		return;

	if (data->CharID == Characters_Knuckles) //fix an issue with charsel
		co2->PhysicsData = PhysicsArray[Characters_Knuckles];

	data->Status = 0;
	ForcePlayerAction(0, 24);


	if (IsIngame())
	{
		if (CurrentSFX == DBZ_SFX)
			PlayVoice(7002);

		RestoreMusic();
	}

	co2->Upgrades &= ~Upgrades_SuperSonic;
	co2->Powerups &= ~Powerups_Invincibility;
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


void SetHyperKnux(CharObj2* co2, EntityData1* data1) {


	taskwk* taskw = (taskwk*)data1;

	if (IsIngame() && CurrentSFX != None)
		PlayVoice(7001);

	co2->Upgrades |= Upgrades_SuperSonic;
	co2->Powerups |= Powerups_Invincibility;

	Load_SuperAura(taskw);
	Load_HyperPhysics(taskw);
	data1->Action = 1;

	return;
}

void HyperKnux_PlayTransfoAnimation(EntityData1* player) {

	if (AlwaysHyperKnux || !AnimationTransfo)
		return;

	ForcePlayerAction(player->Index, 12);
	//player->Action = 75;
	CharObj2Ptrs[player->CharIndex]->AnimationThing.Index = 33;
}

bool CheckUntransform_Input(unsigned char playerID) {

	EntityData1* player = EntityData1Ptrs[playerID];

	if (AlwaysHyperKnux)
		return false;

	if (isKnuxAI(player) && !isPlayerOnHyperForm(0)) {
		unSuper(player->CharIndex);
		return true;
	}

	if (ControllerPointers[playerID]->PressedButtons & TransformButton)
	{
		if (player->Action == glide || player->Action == jump) {
			unSuper(player->CharIndex);
			return true;
		}
	}

	return false;
}


bool CheckPlayer_Input(unsigned char playerID) {

	EntityData1* data = EntityData1Ptrs[playerID];

	if (isKnuxAI(data) && isPlayerOnHyperForm(0)) {
		return true;
	}

	if (ControllerPointers[data->CharIndex]->PressedButtons & TransformButton && (Rings >= 50 || RemoveLimitations))
	{
		if (data->Action == jump || data->Action == glide) {

			return true;
		}
	}

	return false;
}

void HyperKnuxDelete(ObjectMaster* obj) {

	isQuakeEnabled = false;
	unSuper(obj->Data1->CharIndex);
	MusicList[MusicIDs_sprsonic].Name = "sprsonic";
}

void HyperKnux_Manager(ObjectMaster* obj) {

	EntityData1* data = obj->Data1;
	EntityData1* player = EntityData1Ptrs[obj->Data1->CharIndex];

	if (!player || !IsIngame() || EV_MainThread_ptr)
		return;

	if (player->CharID != Characters_Knuckles) //charsel fix
		CheckThingButThenDeleteObject(obj);

	unsigned char playerID = data->CharIndex;
	CharObj2* co2 = CharObj2Ptrs[player->CharIndex];
	int timer = 30;

	switch (data->Action) {

	case hyperKnuxSetTask:
		obj->DeleteSub = HyperKnuxDelete;
		data->Action++;
		break;
	case playerInputCheck:

		if (!AlwaysHyperKnux && !ControlEnabled)
			return;

		if (CheckPlayer_Input(playerID) || AlwaysHyperKnux)
			data->Action++;

		break;
	case hyperKnuxInit:
		data->Index = 0;
		player->Status = 0;

		HyperKnux_PlayTransfoAnimation(player);

		data->Action++;
		break;
	case hyperKnuxWait:

		if (AlwaysHyperKnux)
			timer = 10;

		if (++data->Index == timer)
		{
			ForcePlayerAction(player->Index, 24);
			data->Action++;
		}
		break;
	case hyperKnuxTransfo:

		SetHyperKnux(co2, player);

		if (!isKnuxAI(player)) {
			if (CurrentSuperMusic != None && CurrentSong != MusicIDs_sprsonic)
			{
				ActualSong = LastSong;
				Play_HyperKnuxMusic();
			}
		}

		data->Action++;
		break;
	case hyperKnuxOnFrames:
		SubRings(playerID, data);

		if (CheckUntransform_Input(playerID)) {

			data->Action = playerInputCheck;
		}

		CheckSuperMusic_Restart(playerID);
		CheckKnuxAfterImages(player, co2);
		Knux_EarthQuakeOnGroundCheck(player, co2);

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


void Knux_Main_r(ObjectMaster* obj) {

	EntityData1* data = obj->Data1;
	EntityData1* player = obj->Data1;
	CharObj2* co2 = GetCharObj2(player->Index);

	switch (data->Action)
	{
	case 0:
	{
		ObjectMaster* HyperKnux_ObjManager = LoadObject((LoadObj)2, 0, HyperKnux_Manager);
		HyperKnux_ObjManager->Data1->CharIndex = data->CharIndex;
	}
		break;
	case 60:
		Knux_DoEarthQuakeGround(player, co2);
		break;
	}

	ObjectFunc(origin, Knuckles_Main_t->Target());
	origin(obj);
}

void __cdecl Init_HyperKnuxTextures(const char* path, const HelperFunctions& helperFunctions) {

	HMODULE SA1Char = GetModuleHandle(L"SA1_Chars");

	if (SA1Char)
	{
		for (int i = 0; i < LengthOfArray(HyperKnux_DCEntry); i++) {
			helperFunctions.RegisterCharacterPVM(Characters_Knuckles, HyperKnux_DCEntry[i]);
		}
		isDCCharUsed = true;
	}
	else
	{
		for (int i = 0; i < LengthOfArray(HyperKnux_DXEntry); i++) {
			helperFunctions.RegisterCharacterPVM(Characters_Knuckles, HyperKnux_DXEntry[i]);
		}
		isDCCharUsed = false;
	}
}


void __cdecl HyperKnux_Init(const char* path, const HelperFunctions& helperFunctions)
{

	Init_HyperKnuxTextures(path, helperFunctions);
	Knuckles_Main_t = new Trampoline((int)Knuckles_Main, (int)Knuckles_Main + 0x7, Knux_Main_r);
	Knuckles_Display_t = new Trampoline((int)Knuckles_Display, (int)Knuckles_Display + 0x7, Knuckles_Display_r);


	//Textures init
	WriteCall((void*)0x472255, HyperKnux_PerformLightingThing);
	WriteCall((void*)0x47224E, setHyperKnuxTexture);
}