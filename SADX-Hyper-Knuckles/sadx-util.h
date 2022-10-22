#pragma once

FunctionPointer(void, PResetPosition, (taskwk* data, motionwk2* mwp, playerwk* pwp), 0x43EE70);

DataArray(NJS_TEXLIST, texlist_aura, 0x1422160, 8);
DataArray(NJS_TEXLIST, texlist_aura2, 0x14221A0, 8);
DataArray(NJS_TEXLIST, texlist_water_wave, 0x1422160, 16);
DataPointer(NJS_MODEL_SADX, model_o_cl_grid1_cl_grid1, 0x1427FA4);

DataPointer(NJS_VECTOR, stru_3C5AB24, 0x3C5AB24);
DataPointer(float, bombRadius, 0x3C5A9D0);
ObjectFunc(Exe_leg_shock, 0x576E00);

struct MID_EXPLOSION_INFO
{
	NJS_POINT3* pPos;
	int flag;
	int nLightStartTime;
	int nLightEndTime;
	float fLightLength;
	int angLightSpd;
	int nExpStartTime;
	int nExpGrowEndTime;
	int nExpEndTime;
	int nExpTailTime;
	float fExpMaxRadius;
};

FunctionPointer(void, egm2MiDexplosion, (MID_EXPLOSION_INFO* a1), 0x57BFD0);

// void __usercall(EntityData1 *data1@<ebx>, ObjectData2 *data2)
static const void* const egm2_car_broken_ptr = (void*)0x57BA20;
static inline void egm2_car_broken_main_set(NJS_VECTOR* a1)
{
	__asm
	{
		mov edi, [a1]
		call egm2_car_broken_ptr
	}
}

FunctionPointer(void, EraseDolbyCtrl, (EntityData1* a1), 0x424840);
VoidFunc(KnuEffectPutCharge0, 0x4C2210);
FunctionPointer(void, StopSoundEffect, (EntityData1* data), 0x424240);

DataArray(AnimData, KnucklesAnimData, 0x3C532A0, 115);
ObjectFunc(sub_576A90, 0x576A90);
ObjectFunc(sub_5768E0, 0x576A90);

DataArray(NJS_MODEL_SADX*, knuckles_headlist, 0x3C53290, 3);
DataArray(NJS_OBJECT*, knuckles_headEyelist, 0x3C52D58, 3);

static const void* const InitKnuxEyeTracker_ptr = (void*)0x477D30;
static inline signed int InitKnuxEyeTracker(NJS_OBJECT* a1, char a2)
{
	int result;
	__asm
	{
		push[a2]
		mov edi, [a1]
		call InitKnuxEyeTracker_ptr
		add esp, 4
		mov result, eax
	}

	return result;
}

DataPointer(D3DMATRIX, stru_3C52AE0, 0x3C52AE0);
DataPointer(D3DMATRIX, stru_3C52B98, 0x3C52B98);
DataPointer(D3DMATRIX, stru_3C52C08, 0x3C52C08);
ObjectFunc(KnuxJiggle_Delete, 0x473CB0);
ObjectFunc(KnucklesHeadSpikesShake, 0x473CE0);