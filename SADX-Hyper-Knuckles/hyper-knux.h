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


NJS_TEXNAME HYPERKNUX_DC[23];
NJS_TEXNAME HYPERKNUX_DX[14];

NJS_TEXLIST HyperKnuxDC_TEXLIST = { arrayptrandlength(HYPERKNUX_DC) };
NJS_TEXLIST HyperKnuxDX_TEXLIST = { arrayptrandlength(HYPERKNUX_DX) };


PVMEntry HyperKnux_DCEntry[] = {
	{"HYPERKNUX_DC", &HyperKnuxDC_TEXLIST},
	{"SUPERSONIC", &SUPERSONIC_TEXLIST},
};

PVMEntry HyperKnux_DXEntry[] = {
	{"HYPERKNUX_DX", &HyperKnuxDX_TEXLIST},
	{"SUPERSONIC", &SUPERSONIC_TEXLIST},
};

void Load_HyperPhysics(taskwk* data1);
bool isPlayerOnHyperForm(int player);