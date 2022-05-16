#pragma once

enum HyperKnuxM {
	hyperKnuxSetTask,
	playerInputCheck,
	hyperKnuxInit,
	hyperKnuxWait,
	hyperKnuxTransfo,
	hyperKnuxOnFrames,
	hyperKnuxUntransfo,
};


NJS_TEXNAME HYPERKNUX_DC[39];
NJS_TEXNAME HYPERKNUX_DX[31];
NJS_TEXNAME Knux_SuperAura[16];

NJS_TEXLIST HyperKnuxDC_TEXLIST = { arrayptrandlength(HYPERKNUX_DC) };
NJS_TEXLIST HyperKnuxDX_TEXLIST = { arrayptrandlength(HYPERKNUX_DX) };

NJS_TEXLIST Knux_SuperAura_TEXLIST = { arrayptrandlength(Knux_SuperAura) };


PVMEntry HyperKnux_DCEntry[] = {
	{"HYPERKNUX_DC", &HyperKnuxDC_TEXLIST},
	{"SUPERSONIC", &SUPERSONIC_TEXLIST},
	{"HYPE_K_AURA", &Knux_SuperAura_TEXLIST},
	{"EGM2_HAMON", &EGM2_HAMON_TEXLIST},
	{"EGM2_BAKU", &EGM2_BAKU_TEXLIST},
	{"car_destroyed", &EGM2_CAR_TEXLIST},

};

PVMEntry HyperKnux_DXEntry[] = {
	{"HYPERKNUX_DX", &HyperKnuxDX_TEXLIST},
	{"SUPERSONIC", &SUPERSONIC_TEXLIST},
	{"HYPE_K_AURA", &Knux_SuperAura_TEXLIST},
	{"EGM2_HAMON", &EGM2_HAMON_TEXLIST},
	{"EGM2_BAKU", &EGM2_BAKU_TEXLIST},
	{"car_destroyed", &EGM2_CAR_TEXLIST},
};

void Load_HyperPhysics(taskwk* data1);
bool isPlayerOnHyperForm(int player);
void CheckKnuxAfterImages(EntityData1* data, CharObj2* co2);
void Knux_EarthQuake_InputCheck(EntityData1* data, CharObj2* co2);
void Knux_DoEarthQuakeGround(EntityData1* data, CharObj2* co2);
void SetGlidSPD(bool increase);
void InstantMaxHeat_InputCheck(EntityData1* data, CharObj2* co2);
void SetInstantMaxHeat(bool state);
void Set_AuraTextures();
void RestoreOriginalTrailColor();
void SetHyperKnuxAnimModel(EntityData1* data, CharObj2* co2, EntityData2* data2);
void RestoreKnuxAnimModel(EntityData1* data, CharObj2* co2, EntityData2* data2);
