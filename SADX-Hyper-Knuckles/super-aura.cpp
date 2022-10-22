#include "pch.h"

extern NJS_TEXLIST Knux_SuperAura_TEXLIST;

TaskHook SuperAura_Display_t(0x55E620);

static NJS_TEXNAME SADXAuratexid0 = { (char*)"k_aura01", 0, 0 };
static NJS_TEXNAME SADXAuratexid1 = { (char*)"k_aura02", 0, 0 };
static NJS_TEXNAME SADXAuratexid2 = { (char*)"k_aura03", 0, 0 };
static NJS_TEXNAME SADXAuratexid3 = { (char*)"k_aura04", 0, 0 };
static NJS_TEXNAME SADXAuratexid4 = { (char*)"k_aura05", 0, 0 };
static NJS_TEXNAME SADXAuratexid5 = { (char*)"k_aura06", 0, 0 };
static NJS_TEXNAME SADXAuratexid6 = { (char*)"k_aura07", 0, 0 };
static NJS_TEXNAME SADXAuratexid7 = { (char*)"k_aura08", 0, 0 };

static NJS_TEXLIST KnuxSuperAuraTexListArray[8] = {
	&SADXAuratexid0, 1,
	&SADXAuratexid1, 1,
	&SADXAuratexid2, 1,
	&SADXAuratexid3, 1,
	&SADXAuratexid4, 1,
	&SADXAuratexid5, 1,
	&SADXAuratexid6, 1,
	&SADXAuratexid7, 1
};

static NJS_TEXNAME SADXAuratexid8 = { (char*)"k_aura2_01", 0, 0 };
static NJS_TEXNAME SADXAuratexid9 = { (char*)"k_aura2_02", 0, 0 };
static NJS_TEXNAME SADXAuratexid10 = { (char*)"k_aura2_03", 0, 0 };
static NJS_TEXNAME SADXAuratexid11 = { (char*)"k_aura2_04", 0, 0 };
static NJS_TEXNAME SADXAuratexid12 = { (char*)"k_aura2_05", 0, 0 };
static NJS_TEXNAME SADXAuratexid13 = { (char*)"k_aura2_06", 0, 0 };
static NJS_TEXNAME SADXAuratexid14 = { (char*)"k_aura2_07", 0, 0 };
static NJS_TEXNAME SADXAuratexid15 = { (char*)"k_aura2_08", 0, 0 };

static NJS_TEXLIST KnuxSuperAuraTexListArray2[8] = {
	&SADXAuratexid8, 1,
	&SADXAuratexid9, 1,
	&SADXAuratexid10, 1,
	&SADXAuratexid11, 1,
	&SADXAuratexid12, 1,
	&SADXAuratexid13, 1,
	&SADXAuratexid14, 1,
	&SADXAuratexid15, 1
};

void njTexlistSetSuperAura(NJS_TEXLIST* texlist)
{
	if (isHyperKnux)
		texlist = KnuxSuperAuraTexListArray;

	njSetTexture(texlist);
}

void njTexlistSetSuperAura2(NJS_TEXLIST* texlist)
{
	if (isHyperKnux)
		texlist = KnuxSuperAuraTexListArray2;

	njSetTexture(texlist);
}

void Set_AuraTextures() {

	for (uint8_t i = 0; i < LengthOfArray(KnuxSuperAuraTexListArray); i++) {

		KnuxSuperAuraTexListArray[i].textures[0] = Knux_SuperAura_TEXLIST.textures[i];
		KnuxSuperAuraTexListArray2[i].textures[0] = Knux_SuperAura_TEXLIST.textures[i + 8];
	}

	//swap trail color
	WriteData((uint8_t*)0x4C1678, (uint8_t)64); // Blue from 0 to 64

	return;
}

void RestoreOriginalTrailColor()
{
	WriteData((uint8_t*)0x4C1678, (uint8_t)00); // B
}

void SuperAuraKnux_Display(task* obj)
{
	taskwk* data;
	taskwk* playerData;
	CharObj2* co2;
	int v4;
	int v5;
	NJS_OBJECT* v6;
	int v7;
	int v8;
	float XScale;
	float XScaleA;
	float YScale;
	float ZScale;

	data = obj->twp;
	playerData = (taskwk*)EntityData1Ptrs[(unsigned __int8)data->counter.b[0]];
	co2 = GetCharObj2(data->counter.b[0]);
	EntityData1* pData = (EntityData1*)playerData;

	if (MissedFrames)
		return;

	njSetTexture(&KnuxSuperAuraTexListArray[data->btimer & 7]);
	njControl3D_Backup();
	njControl3D(NJD_CONTROL_3D_CONSTANT_MATERIAL);
	SetMaterialAndSpriteColor_Float(1.0, 1.0, 1.0, 1.0);
	njPushMatrix(0);
	njTranslateV(0, &playerData->cwp->info->center);
	v4 = playerData->ang.z;
	if (v4)
	{
		njRotateZ(0, (unsigned __int16)v4);
	}
	v5 = playerData->ang.x;
	if (v5)
	{
		njRotateX(0, (unsigned __int16)v5);
	}
	if (playerData->ang.y)
	{
		njRotateY(0, (unsigned __int16)-LOWORD(playerData->ang.y));
	}
	njScale(0, -1.0, 1.0, 1.0);
	if (co2->Speed.x <= 13.0)
	{
		if (co2->Speed.x <= 7.0)
		{
			ProcessModelNode_A_WrapperB(SONIC_OBJECTS[74], QueuedModelFlagsB_SomeTextureThing);
		}
		else
		{

			njSetTexture(&KnuxSuperAuraTexListArray[((unsigned __int8)data->btimer >> 1) & 7]);
			ProcessModelNode_A_WrapperB(SONIC_OBJECTS[75], QueuedModelFlagsB_SomeTextureThing);
		}
	}
	else
	{
		njSetTexture(KnuxSuperAuraTexListArray2 + (((unsigned __int8)data->btimer >> 1) & 7));
		ProcessModelNode_A_WrapperB(SONIC_OBJECTS[76], QueuedModelFlagsB_SomeTextureThing);
	}
	njPopMatrix(1u);
	ClampGlobalColorThing_Thing();
	njControl3D_Restore();
}

void __cdecl SuperAura_Display_r(task* obj)
{
	taskwk* data = obj->twp;
	taskwk* playerData = (taskwk*)EntityData1Ptrs[(unsigned __int8)data->counter.b[0]];
	EntityData1* pData = (EntityData1*)playerData;

	if (isHyperKnux && pData->CharID == Characters_Knuckles && !isPerfectChasoLevel())
	{
		SuperAuraKnux_Display(obj);
	}
	else
	{
		SuperAura_Display_t.Original(obj);
	}
}

void init_AuraHack()
{
	SuperAura_Display_t.Hook(SuperAura_Display_r);
}