#include "pch.h"
#include "Trampoline.h"

Trampoline* KnuxGrabWall_Check_t = nullptr;
TaskHook carSH_t(0x611FC0);
TaskHook carSS_t(0x633180);
TaskHook Sweep_Main_t((intptr_t)Sweep_Main);

NJS_POINT3 Velo = { 5.0f, 5.0f, 5.0f };

bool isQuakeEnabled = false;

void __cdecl Exe_leg_shock_r(task* obj)
{
	ObjectMaster* SWColor;
	ObjectMaster* SW;

	auto data = obj->twp;
	if (data->mode)
	{
		if (data->mode != 1)
		{
			goto LABEL_11;
		}
	}
	else
	{
		data->id = 30;
		data->mode = 1;
	}
	SWColor = LoadObject(LoadObj_Data1, 6, (void(__cdecl*)(ObjectMaster*))sub_576A90);
	if (SWColor)
	{
		auto swColorData = (taskwk*)SWColor->Data1;
		swColorData->pos = data->pos;
		swColorData->ang = data->ang;
	}
	SW = LoadObject(LoadObj_Data1, 6, (void(__cdecl*)(ObjectMaster*))sub_5768E0);
	if (SW)
	{
		auto swData = (taskwk*)SW->Data1;
		swData->pos = data->pos;
		swData->ang = data->ang;
	}
	if ((int)--data->id < 0)
	{
		FreeTask(obj);
	}
LABEL_11:
	data->cwp->info->a = (30.0f - (double)(int)data->id) * 2.4666667f;
	EntryColliList(data);
}

CollisionData legCol = { 0, 1, 0x0, 0x0, 0x0, {0}, 0.0, 1.0, 0.0, 0.0, 0, 0, 0 };
//use bomb item to kill enemy, then smoke and egg walker shockwave for the effects
void CreateBombQuake(taskwk* player)
{
	isQuakeEnabled = true;
	stru_3C5AB24 = player->pos;
	bombRadius = 6.0f;
	PlayVoice(7003); //S3k SFX
	RumbleA(player->counter.b[0], 0);

	CreateSmoke(&player->pos, &Velo, 8.0f);
	auto shockwave = CreateElementalTask(LoadObj_Data1, 6, Exe_leg_shock_r);
	if (shockwave) {
		if (shockwave->twp) {
			shockwave->twp->pos = player->pos;
			shockwave->twp->ang = player->ang;
			shockwave->twp->pos.y += 2.5f;
			Collision_Init((ObjectMaster*)shockwave, &legCol, 1, 4u);
		}
	}
}

static void Knux_GrabWallCheck_Origin(taskwk* a1, playerwk* a2)
{
	auto target = KnuxGrabWall_Check_t->Target();

	__asm
	{
		mov ecx, [a2]
		mov eax, [a1]
		call target
	}
}

void KnuxGrabWallCheck_r(taskwk* a1, playerwk* a2)
{
	if (a1 && a2 && a2->spd.x > 2.0f && isHyperKnux) {
		CreateBombQuake(a1);
	}

	Knux_GrabWallCheck_Origin(a1, a2);
}

static void __declspec(naked) KnuxGrabWallCheckASM()
{
	__asm
	{
		push ecx // a2
		push eax // a1
		call KnuxGrabWallCheck_r
		pop eax // a1
		pop ecx // a2
		retn
	}
}

void Knux_EarthQuake_InputCheck(EntityData1* data, CharObj2* co2)
{
	if (!data || data->Action != jump && data->Action != glide)
		return;

	if ((Controllers[data->Index].HeldButtons & (Buttons_X | Buttons_B)) != 0 && (Controllers[data->Index].HeldButtons & TransformButton) == 0)
	{
		if (!isNewTricks() || Controllers[data->Index].HeldButtons & Buttons_X) {
			data->Action = earthQuake;
			co2->AnimationThing.Index = 14;

			co2->Speed.y -= 6.0f;
		}
		data->Status &= ~Status_Ball;
		return;
	}
}

void Knux_DoEarthQuakeGround(taskwk* data, playerwk* co2)
{
	if ((Controllers[data->counter.b[0]].PressedButtons & JumpButtons) != 0)
	{
		data->mode = glide;
		co2->mj.reqaction = 51;
		co2->spd.y = 0.0f;
		return;
	}

	if ((isHyperKnux && data->flag & (Status_Ground | Status_OnColli)) != 0) {
		CreateBombQuake(data);

		co2->spd.y = 0.0f;

		if (co2->attr & (ColFlags_Dig)) {
			if (co2->equipment & (Upgrades_ShovelClaw))
			{
				co2->spd = { 0.0f, 0.0f, 0.0f };
				data->id = 0;
				data->mode = 19;
				co2->mj.reqaction = 41;
				PlaySound(1260, 0, 0, 0);
				return;
			}
		}

		data->mode = 61;
		co2->mj.reqaction = 20;
	}
}

int Knux_JumpCancel_r(CharObj2* a1, EntityData1* data)
{
	if ((AttackButtons & Controllers[data->CharIndex].PressedButtons) == 0 || isHyperKnux)
	{
		return 0;
	}

	data->Action = 9;
	a1->Speed.z = 0.0;
	a1->Speed.y = 0.0;
	a1->Speed.x = 0.0;
	a1->AnimationThing.Index = 19;
	a1->SpindashSpeed = 0.0;
	data->Status &= 0xFAu;
	return 1;
}

static void __declspec(naked) Knux_JumpCancel()
{
	__asm
	{
		push ecx
		push eax
		call Knux_JumpCancel_r
		add esp, 4
		pop ecx
		retn
	}
}

//fix an issue where the game crashes if you use a bomb on those enemy :)
void Sweep_Main_r(task* obj)
{
	taskwk* data = obj->twp;
	ObjectData2* objdata2 = (ObjectData2*)obj->mwp;

	if (data && objdata2) {
		if (data->mode < 3) {
			if (OhNoImDead((EntityData1*)data, objdata2))
			{
				data->mode = 3;
				data->counter.b[1] = 0;
				data->counter.b[2] = 1;
				data->wtimer = 0;
				data->scl.z = 0.34999999;
				return;
			}
		}
	}

	Sweep_Main_t.Original(obj);
}

void DestroyCar(ObjectMaster* obj)
{
	EntityData1* data = obj->Data1;

	MID_EXPLOSION_INFO boom;

	boom.pPos = &data->Position;
	boom.flag = 3;
	boom.nLightStartTime = 0;
	boom.nLightEndTime = 0;
	boom.fLightLength = 0.0;
	boom.angLightSpd = 0;
	boom.nExpStartTime = 0;
	boom.nExpGrowEndTime = 20;
	boom.nExpEndTime = 40;
	boom.nExpTailTime = 60;
	boom.fExpMaxRadius = 25.0;
	egm2MiDexplosion(&boom);
	dsPlay_oneshot_Dolby(475, 0, 0, 64, 120, (taskwk*)data);
	data->Unknown = 30;
	data->Index++;
}

void ObjectCarSHRegular_r(ObjectMaster* obj)
{
	EntityData1* data = obj->Data1;

	if (isHyperKnux && isKnucklesPlayer())
	{
		if (data->Index > 1)
			data->Index = 0;

		NJS_VECTOR pos = data->Position;
		if (IsPlayerInSphere(pos, 100) && isQuakeEnabled)
		{
			if (data->Index == 0)
				DestroyCar(obj);
		}

		if (data->Index == 1)
		{
			egm2_car_broken_main_set(&data->Position);
			EraseDolbyCtrl(data);
			CheckThingButThenDeleteObject(obj);
			return;
		}
		else {
			return carSH_t.Original((task*)obj);
		}
	}
	else
	{
		return carSH_t.Original((task*)obj);
	}
}

void ObjectCarSS_r(ObjectMaster* obj)
{
	EntityData1* data = obj->Data1;

	if (isHyperKnux && isKnucklesPlayer()) {
		if (data->Index > 1)
			data->Index = 0;

		NJS_VECTOR pos = data->Position;
		if (IsPlayerInSphere(pos, 100) && isQuakeEnabled)
		{
			if (data->Index == 0)
				DestroyCar(obj);
		}

		if (data->Index == 1)
		{
			egm2_car_broken_main_set(&data->Position);
			EraseDolbyCtrl(data);
			CheckThingButThenDeleteObject(obj);
			return;
		}
		else {
			return carSS_t.Original((task*)obj);
		}
	}
	else
	{
		return carSS_t.Original((task*)obj);
	}
}

void init_KnuxEarthquake()
{
	KnuxGrabWall_Check_t = new Trampoline((int)0x4757E0, (int)0x4757E6, KnuxGrabWallCheckASM);
	WriteCall((void*)0x478721, Knux_JumpCancel); //prevent jump cancel to happen when using earthquake
	carSH_t.Hook((TaskFuncPtr)ObjectCarSHRegular_r);
	carSS_t.Hook((TaskFuncPtr)ObjectCarSS_r);
	Sweep_Main_t.Hook(Sweep_Main_r);
}