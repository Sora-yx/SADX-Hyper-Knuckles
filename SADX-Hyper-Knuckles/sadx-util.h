#pragma once

FunctionPointer(void, PResetPosition, (EntityData1* data, EntityData2* mwp, CharObj2* pwp), 0x43EE70);

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