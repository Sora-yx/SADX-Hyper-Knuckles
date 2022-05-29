#include "pch.h"

Trampoline* KnuxGrabWall_Check_t = nullptr;
Trampoline* carSH_t = nullptr;
Trampoline* carSS_t = nullptr;
Trampoline* Sweep_Main_t = nullptr;

NJS_POINT3 Velo = { 5.0f, 5.0f, 5.0f };

bool isQuakeEnabled = false;

void __cdecl Exe_leg_shock_r(ObjectMaster* obj)
{
	EntityData1* data;
	ObjectMaster* SWColor;
	EntityData1* swColorData;
	EntityData1* swData;
	ObjectMaster* SW;

	data = obj->Data1;
	if (data->Action)
	{
		if (data->Action != 1)
		{
			goto LABEL_11;
		}
	}
	else
	{
		data->Unknown = 30;
		data->Action = 1;
	}
	SWColor = LoadObject(LoadObj_Data1, 6, (void(__cdecl*)(ObjectMaster*))sub_576A90);
	if (SWColor)
	{
		swColorData = SWColor->Data1;
		swColorData->Position = data->Position;
		swColorData->Rotation = data->Rotation;
	}
	SW = LoadObject(LoadObj_Data1, 6, (void(__cdecl*)(ObjectMaster*))sub_5768E0);
	if (SW)
	{
		swData = SW->Data1;
		swData->Position = data->Position;
		swData->Rotation = data->Rotation;
	}
	if ((int)--data->Unknown < 0)
	{
		CheckThingButThenDeleteObject(obj);
	}
LABEL_11:
	data->CollisionInfo->CollisionArray->a = (30.0 - (double)(int)data->Unknown) * 2.4666667;
	AddToCollisionList(data);
}

CollisionData legCol = { 0, 1, 0x0, 0x0, 0x0, {0}, 0.0, 1.0, 0.0, 0.0, 0, 0, 0 };
//use bomb item to kill enemy, then smoke and egg walker shockwave for the effects
void CreateBombQuake(EntityData1* player, CharObj2* co2)
{
	isQuakeEnabled = true;
	stru_3C5AB24 = player->Position;
	bombRadius = 6.0f;
	PlayVoice(7003); //S3k SFX 
	RumbleA(player->CharIndex, 0);

	CreateSmoke(&player->Position, &Velo, 8.0f);
	ObjectMaster* shockwave = LoadObject(LoadObj_Data1, 6, Exe_leg_shock_r);
	if (shockwave) {
		if (shockwave->Data1) {
			shockwave->Data1->Position = player->Position;
			shockwave->Data1->Rotation = player->Rotation;
			shockwave->Data1->Position.y += 2.5f;
			Collision_Init(shockwave, &legCol, 1, 4u);
		}
	}
}

static void Knux_GrabWallCheck_Origin(EntityData1* a1, CharObj2* a2)
{
	auto target = KnuxGrabWall_Check_t->Target();

	__asm
	{
		mov ecx, [a2]
		mov eax, [a1]
		call target
	}
}


void KnuxGrabWallCheck_r(EntityData1* a1, CharObj2* a2)
{
	if (a2->Speed.x > 2.0f && isHyperKnux) {

		CreateBombQuake(a1, a2);
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
		data->Action = 60;
		co2->AnimationThing.Index = 14;
		data->Status &= ~Status_Ball;
		co2->Speed.y -= 6.0f;
		return;
	}
}

void Knux_DoEarthQuakeGround(EntityData1* data, CharObj2* co2)
{
	if ((Controllers[data->Index].PressedButtons & JumpButtons) != 0)
	{
		data->Action = glide;
		co2->AnimationThing.Index = 51;
		co2->Speed.y = 0.0;
		return;
	}

	if ((isHyperKnux && data->Status & (Status_Ground | Status_OnColli)) != 0) {

		CreateBombQuake(data, co2);

		co2->Speed.y = 0.0f;

		if (co2->SurfaceFlags & (ColFlags_Dig)) {

			if (co2->Upgrades & (Upgrades_ShovelClaw))
			{
				co2->Speed = { 0.0f, 0.0f, 0.0f };
				data->Unknown = 0;
				data->Action = 19;
				co2->AnimationThing.Index = 41;
				PlaySound(1260, 0, 0, 0);
				return;
			}
		}

		data->Action = 61;
		co2->AnimationThing.Index = 20;
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

	TaskFunc(origin, Sweep_Main_t->Target());
	origin(obj);
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

	if (isHyperKnux) {

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

			ObjectFunc(origin, carSH_t->Target());
			origin(obj);
		}
	}
	else
	{
		ObjectFunc(origin, carSH_t->Target());
		origin(obj);
	}
}

void ObjectCarSS_r(ObjectMaster* obj)
{
	EntityData1* data = obj->Data1;

	if (isHyperKnux) {

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

			ObjectFunc(origin, carSS_t->Target());
			origin(obj);
		}
	}
	else
	{
		ObjectFunc(origin, carSS_t->Target());
		origin(obj);
	}
}


void init_KnuxEarthquake()
{

	KnuxGrabWall_Check_t = new Trampoline((int)0x4757E0, (int)0x4757E6, KnuxGrabWallCheckASM);
	WriteCall((void*)0x478721, Knux_JumpCancel); //prevent jump cancel to happen when using earthquake
	carSH_t = new Trampoline((int)0x611FC0, (int)0x611FC6, ObjectCarSHRegular_r);
	carSS_t = new Trampoline((int)0x633180, (int)0x633188, ObjectCarSS_r);
	Sweep_Main_t = new Trampoline((int)Sweep_Main, (int)Sweep_Main + 0x5, Sweep_Main_r);
}