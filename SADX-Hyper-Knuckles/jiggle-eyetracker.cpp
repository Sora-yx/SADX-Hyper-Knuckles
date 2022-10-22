#include "pch.h"

NJS_OBJECT* HyperKnuxEyeList[3];
NJS_MODEL_SADX* HyperKnuxHeadList[3];
TaskHook KnucklesHeadSpikesShake_t((intptr_t)0x473CE0);

void __cdecl KnucklesHeadSpikeShake_r(task* arg0)
{
	if (isHyperKnux) {
		FreeTask(arg0);
		return;
	}

	KnucklesHeadSpikesShake_t.Original(arg0);
}

void __cdecl HyperKnucklesHeadSpikesShake(ObjectMaster* _this)
{
	NJS_POINT3* headlist_Point;
	NJS_OBJECT* knuxObj;
	NJS_MODEL_SADX* knuxHead; // eax
	NJS_VECTOR* headPoints; // edi
	double v9; // st7
	double result; // st7
	int v11; // eax
	Angle v12; // ecx
	Angle v13; // eax
	int v14; // eax
	int v15; // ebp
	char v19; // c0
	D3DMATRIX* v20; // ecx
	float spd; 
	Sint32 nbPointTimer; 
	motionwk2* playerData2; 
	NJS_VECTOR a2; 

	motionwk2* data2 = (motionwk2*)_this->Data2;
	EntityData1* data = _this->Data1;
	unsigned __int8 pnum = data->CharIndex;

	if (!AlwaysHyperKnux && !isHyperKnux || !EntityData1Ptrs[pnum])
	{
		DeleteObjectMaster(_this);
		return;
	}

	playerData2 = (motionwk2*)EntityData2Ptrs[pnum];
	CharObj2* co2 = GetCharObj2(pnum);
	headlist_Point = HyperKnuxHeadList[0]->points;
	knuxObj = KnucklesAnimData[(unsigned __int16)co2->AnimationThing.Index].Animation->object;

	if (knuxObj == *KNUCKLES_OBJECTS)
	{
		knuxHead = HyperKnuxHeadList[1];
		nbPointTimer = HyperKnuxHeadList[1]->nbPoint;
	}
	else
	{
		if (knuxObj != KNUCKLES_OBJECTS[1])
		{
			return;
		}
		knuxHead = HyperKnuxHeadList[2];
		nbPointTimer = HyperKnuxHeadList[2]->nbPoint;
	}
	headPoints = knuxHead->points;
	if (!data->Action)
	{
		data->Action++;
		_this->DeleteSub = KnuxJiggle_Delete;
		KNUCKLES_OBJECTS[49]->model = HyperKnuxHeadList[0];
		KNUCKLES_OBJECTS[50]->model = HyperKnuxHeadList[0];
	}

	if (data->Action == 1)
	{
		spd = playerData2->spd.x * playerData2->spd.x
			+ playerData2->spd.y * playerData2->spd.y
			+ playerData2->spd.z * playerData2->spd.z;
		v9 = squareroot(spd);
		result = v9 + v9;

		if (fabs(data2->spd.y) < result)
		{
			if (result < 0.0)
			{
				result = -result;
			}
			if (result > 5.0)
			{
				result = 5.0;
			}
			data2->spd.y = result;
		}
		if (data2->spd.y >= 0.2 || data2->spd.y <= -0.2)
		{
			data2->spd.y = data2->spd.y * 0.98000002f;
		}
		else
		{
			data2->spd.y = 0.0;
		}
		v11 = (unsigned __int64)fabs(data2->spd.y * 512.0f) + 2048;
		if (v11 > 5120)
		{
			v11 = 5120;
		}
		v12 = v11 + data2->ang_spd.z;
		data2->ang_spd.z = v12;
		data->Rotation.z = (unsigned __int64)(data2->spd.y * 0.2 * njCos(v12) * 4096.0f);
		njUnitMatrix(&stru_3C52C08._11);
		v13 = data->Rotation.z;
		if (v13)
		{
			njRotateZ(&stru_3C52C08._11, (unsigned __int16)v13);
		}
		njUnitMatrix(&stru_3C52AE0._11);
		v14 = data->Rotation.z >> 1;
		if (v14)
		{
			njRotateZ(&stru_3C52AE0._11, (unsigned __int16)v14);
		}
		njUnitMatrix(&stru_3C52B98._11);
		v15 = data->Rotation.z >> 2;
		if (v15)
		{
			njRotateZ(&stru_3C52B98._11, (unsigned __int16)v15);
		}

		if (!nbPointTimer)
		{
			KNUCKLES_OBJECTS[49]->model = HyperKnuxHeadList[0];
			KNUCKLES_OBJECTS[50]->model = HyperKnuxHeadList[0];
			return;
		}

		while (1)
		{

			if (headPoints->x < -2.0f)
			{
				a2.z = headPoints->z;
				v20 = &stru_3C52AE0;
				goto LABEL_37;
			}
			if (fabs(headPoints->z) > 2.0f)
			{
				a2.z = headPoints->z;
				v20 = &stru_3C52B98;
			LABEL_37:
				a2.x = headPoints->x + 1.0f;
				a2.y = headPoints->y + 3.0f;
				njCalcVector(&v20->_11, &a2, headlist_Point);
				headlist_Point->x -= 1.0f;
				headlist_Point->y -= 3.0f;
			}
			++headPoints;
			++headlist_Point;

			if (!--nbPointTimer)
			{
				KNUCKLES_OBJECTS[49]->model = HyperKnuxHeadList[0];
				KNUCKLES_OBJECTS[50]->model = HyperKnuxHeadList[0];
				return;
			}
		}

	}
	else {

		DeleteObjectMaster(_this);
	}
}

void LoadHyperKnux_Jiggle(uint8_t pnum)
{
	if (charType == none)
		return;

	ObjectMaster* jiggle = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 3, HyperKnucklesHeadSpikesShake);
	if (jiggle)
	{
		jiggle->Data1->CharIndex = pnum;
	}
}

void LoadRegularKnuxJiggle(uint8_t pnum)
{
	ObjectMaster* jiggle = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 3, KnucklesHeadSpikesShake);
	if (jiggle)
	{
		jiggle->Data1->CharIndex = pnum;
	}
}

void Load_EyeTracker(uint8_t pnum)
{
	if (charType == none)
		return;

	InitKnuxEyeTracker((NJS_OBJECT*)HyperKnuxEyeList, pnum);
}


void init_Jiggle_EyeTracker()
{
	if (charType == none)
		return;

	HyperKnuxEyeList[0] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling;
	HyperKnuxEyeList[1] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->child->child->sibling;
	HyperKnuxEyeList[2] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->child->child->sibling;

	KnucklesHeadSpikesShake_t.Hook(KnucklesHeadSpikeShake_r);
	HyperKnuxHeadList[0] = HyperKnux_Model[15]->getmodel()->basicdxmodel;
	HyperKnuxHeadList[1] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->basicdxmodel;
	HyperKnuxHeadList[2] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->basicdxmodel;
}
