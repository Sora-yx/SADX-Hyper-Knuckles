#pragma once

FunctionPointer(void, PResetPosition, (EntityData1* data, EntityData2* mwp, CharObj2* pwp), 0x43EE70);

DataArray(NJS_TEXLIST, texlist_aura, 0x1422160, 8);
DataArray(NJS_TEXLIST, texlist_aura2, 0x14221A0, 8);
DataArray(NJS_TEXLIST, texlist_water_wave, 0x14221E0, 8);
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