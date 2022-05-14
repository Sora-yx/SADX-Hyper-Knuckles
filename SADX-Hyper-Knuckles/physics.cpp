#include "pch.h"

PhysicsData_t knuxPhysicsCopy;
Trampoline* ResetAngle_t = nullptr;

void __cdecl Knux_SuperPhysics_Delete(ObjectMaster* obj) {

	memcpy(&PhysicsArray[Characters_Knuckles], &knuxPhysicsCopy, sizeof(PhysicsData_t));
}


void __cdecl Knux_SuperPhysics_Load(ObjectMaster* obj)
{
	ObjUnknownB* v1; // esi
	CharObj2* v2; // eax

	v1 = (ObjUnknownB*)obj->UnknownB_ptr;
	v2 = GetCharObj2(v1->Time);
	if (v2)
	{
		memcpy(&knuxPhysicsCopy, &PhysicsArray[Characters_Knuckles], sizeof(PhysicsData_t));

		if (!customPhysics) { //use vanilla broken super sonic physics
			v2->PhysicsData.RollDecel = -0.001f;
			v2->PhysicsData.AirDecel = -0.0020000001f;
			v2->PhysicsData.AirAccel = 0.050000001f;
		}
		else {
			v2->PhysicsData.GroundAccel = 0.065f;
			v2->PhysicsData.RollDecel = -0.006f;
			v2->PhysicsData.AirDecel = -0.01799999999f;
			v2->PhysicsData.AirAccel = 0.040f;
			v2->PhysicsData.MaxAccel = 3.0f;
		}

		obj->DeleteSub = Knux_SuperPhysics_Delete;
		obj->MainSub = Sonic_SuperPhysics_Main;
	}
	else
	{
		DeleteObjectMaster(obj);
	}
}


void Load_HyperPhysics(taskwk* data1) {

	task* v11 = (task*)LoadObject(LoadObj_UnknownB, 2, Knux_SuperPhysics_Load);
	if (v11)
	{
		v11->awp->work.ub[0] = data1->counter.b[0];
	}
}


//fix spring issue, only run if Super Sonic mod is disabled.
static void __cdecl ResetAngle_r(EntityData1* data, EntityData2* data2, CharObj2* co2)
{
	if (CurrentLevel != LevelIDs_PerfectChaos && co2->Upgrades & Upgrades_SuperSonic)
	{
		float v4; // ecx
		float v5; // eax
		float v6; // ecx
		NJS_VECTOR a2a; // [esp+4h] [ebp-Ch] BYREF
		taskwk* twk = (taskwk*)data;

		a2a.x = co2->Speed.x;
		v4 = co2->Speed.z;
		a2a.y = co2->Speed.y;
		a2a.z = v4;
		if (co2->PhysicsData.Run2 * co2->PhysicsData.Run2 >= a2a.z * a2a.z + a2a.y * a2a.y + a2a.x * a2a.x)
		{
			PConvertVector_P2G(twk, &a2a);
			data->Rotation.x = BAMS_SubWrap(data->Rotation.x, GravityAngle_Z, 2048);
			data->Rotation.z = BAMS_SubWrap(data->Rotation.z, GravityAngle_X, 2048);
			PConvertVector_G2P(twk, &a2a);
			v5 = a2a.y;
			v6 = a2a.z;
			co2->Speed.x = a2a.x;
			co2->Speed.y = v5;
			co2->Speed.z = v6;
		}
	}
	else
	{
		TARGET_DYNAMIC(ResetAngle)(data, data2, co2);
	}
}

void Increase_ClimbSPD(taskwk* a1, NJS_POINT3* a2)
{
	float spd = 0.9f;

	if (isHyperKnux)
	{
		if (a2->x > 0.10f)
			a2->x += spd;
		else if (a2->x < -0.10f)
			a2->x -= spd;

		if (a2->y > 0.10f)
			a2->y += spd;
		else if (a2->y < -0.10f)
			a2->y -= spd;

		if (a2->z > 0.10f)
			a2->z += 0.5f;
		else if (a2->z < -0.10f)
			a2->z -= 0.5f;

	}

	PConvertVector_P2G(a1, a2);
}

float glideSPDCAP = 15.0f;

void SetGlidSPD(bool increase)
{
	if (increase)
		glideSPDCAP = 15.0f;
	else
		glideSPDCAP = 3.5f;


	WriteData((float**)0x4445da, &glideSPDCAP);
}

void init_PhysicsHack()
{

	bool bSS = GetModuleHandle(L"Better-Super-Sonic");

	if (!bSS) {
		ResetAngle_t = new Trampoline(0x443AD0, 0x443AD7, ResetAngle_r);
	}

	WriteCall((void*)0x44453F, Increase_ClimbSPD);

}