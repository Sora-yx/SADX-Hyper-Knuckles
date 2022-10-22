#include "pch.h"


NJS_OBJECT* KnuxObjCopy[74] = { 0 };
NJS_OBJECT* KnuxAnimCopy[90] = { 0 };
NJS_MODEL_SADX* KnuxModelCopy[23] = { 0 };
WeldInfo KnucklesWeldInfo_r[60] = { 0 };

static FunctionHook<void> InitKnucklesWeldInfo_t((intptr_t)InitKnucklesWeldInfo);

//This whole page manage the character model swap in real time, it's a giant mess due to how the game works.
//Main idea is to backup everything on startup, swap models when transform, then restore everything when destransform.
//No you can't use loop to copy / assign everything, I wish you could.

uint16_t Knuckles_UpperArmIndices_DC[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Knuckles_LowerArmIndices_DC[] = {
	0, 10,
	1, 11,
	4, 14,
	5, 15,
};

uint16_t Knuckles_LegIndices_DC[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Knuckles_ShoeIndices_DC[] = {
	2, 3,
	12, 8,
	0, 1,
	1, 0,
	17, 13,
	3, 2,
};

uint16_t Knuckles_HandIndices_DC[] = {
	8, 24,
	0, 11,
	1, 13,
	5, 15,
	4, 10,
};

uint16_t Knuckles_ShovelClawIndices_DC[] = {
	8, 14,
	0, 1,
	1, 3,
	5, 5,
	4, 0,
};


void __cdecl InitHyperKnucklesDC_WeldsInfo()
{

	KnucklesWeldInfo_r[29].BaseModel = HyperKnux_Model[root]->getmodel();
	NJS_OBJECT* Root = KnucklesWeldInfo_r[29].BaseModel;

	KnucklesWeldInfo_r[29].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[29].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[29].anonymous_5 = 0;
	KnucklesWeldInfo_r[29].VertexBuffer = 0;
	KnucklesWeldInfo_r[29].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo_r[29].WeldType = 2;
	KnucklesWeldInfo_r[29].VertIndexes = Knuckles_UpperArmIndices_DC;

	KnucklesWeldInfo_r[30].BaseModel = Root;
	KnucklesWeldInfo_r[30].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[30].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[30].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo_r[30].WeldType = 2;
	KnucklesWeldInfo_r[30].anonymous_5 = 0;
	KnucklesWeldInfo_r[30].VertexBuffer = 0;
	KnucklesWeldInfo_r[30].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo_r[31].BaseModel = Root;
	KnucklesWeldInfo_r[31].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;  
	KnucklesWeldInfo_r[31].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo_r[31].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[31].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo_r[31].WeldType = 2;
	KnucklesWeldInfo_r[31].anonymous_5 = 0;
	KnucklesWeldInfo_r[31].VertexBuffer = 0;
	KnucklesWeldInfo_r[32].BaseModel = Root;
	KnucklesWeldInfo_r[32].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[32].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[32].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo_r[32].WeldType = 2;
	KnucklesWeldInfo_r[32].anonymous_5 = 0;
	KnucklesWeldInfo_r[32].VertexBuffer = 0;
	KnucklesWeldInfo_r[32].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo_r[33].BaseModel = Root;
	KnucklesWeldInfo_r[33].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[33].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[33].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[33].WeldType = 2;
	KnucklesWeldInfo_r[33].anonymous_5 = 0;
	KnucklesWeldInfo_r[33].VertexBuffer = 0;
	KnucklesWeldInfo_r[33].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[34].BaseModel = Root;
	KnucklesWeldInfo_r[34].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[34].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[34].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[34].WeldType = 2;
	KnucklesWeldInfo_r[34].anonymous_5 = 0;
	KnucklesWeldInfo_r[34].VertexBuffer = 0;
	KnucklesWeldInfo_r[34].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[35].BaseModel = Root;
	KnucklesWeldInfo_r[35].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[35].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[35].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[35].WeldType = 2;
	KnucklesWeldInfo_r[35].anonymous_5 = 0;
	KnucklesWeldInfo_r[35].VertexBuffer = 0;
	KnucklesWeldInfo_r[35].VertIndexes = Knuckles_LegIndices_DC;

	KnucklesWeldInfo_r[36].BaseModel = Root;
	KnucklesWeldInfo_r[36].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[36].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[36].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[36].WeldType = 2;
	KnucklesWeldInfo_r[36].anonymous_5 = 0;
	KnucklesWeldInfo_r[36].VertexBuffer = 0;
	KnucklesWeldInfo_r[36].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[37].BaseModel = Root;
	KnucklesWeldInfo_r[37].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[37].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[37].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo_r[37].WeldType = 2;
	KnucklesWeldInfo_r[37].anonymous_5 = 0;
	KnucklesWeldInfo_r[37].VertexBuffer = 0;
	KnucklesWeldInfo_r[37].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo_r[38].BaseModel = Root;
	KnucklesWeldInfo_r[38].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[38].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo_r[38].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[38].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo_r[38].WeldType = 2;
	KnucklesWeldInfo_r[38].anonymous_5 = 0;
	KnucklesWeldInfo_r[38].VertexBuffer = 0;

	//10 HAND RIGHT HIERARCHY IS DIFFERENT WITH DC MODEL
	KnucklesWeldInfo_r[39].BaseModel = Root;
	KnucklesWeldInfo_r[39].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[39].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[39].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo_r[39].WeldType = 2;
	KnucklesWeldInfo_r[39].anonymous_5 = 0;
	KnucklesWeldInfo_r[39].VertexBuffer = 0;
	KnucklesWeldInfo_r[39].VertIndexes = Knuckles_HandIndices_DC;

	KnucklesWeldInfo_r[40].BaseModel = Root;
	KnucklesWeldInfo_r[40].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[40].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[40].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo_r[40].WeldType = 2;
	KnucklesWeldInfo_r[40].anonymous_5 = 0;
	KnucklesWeldInfo_r[40].VertexBuffer = 0;
	KnucklesWeldInfo_r[40].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo_r[41].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[41].ModelA = KNUCKLES_OBJECTS[24];
	KnucklesWeldInfo_r[41].ModelB = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo_r[41].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo_r[41].WeldType = 2;
	KnucklesWeldInfo_r[41].anonymous_5 = 0;
	KnucklesWeldInfo_r[41].VertexBuffer = 0;
	KnucklesWeldInfo_r[41].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo_r[42].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[42].ModelA = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo_r[42].ModelB = KNUCKLES_OBJECTS[26];
	KnucklesWeldInfo_r[42].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo_r[42].WeldType = 2;
	KnucklesWeldInfo_r[42].anonymous_5 = 0;
	KnucklesWeldInfo_r[42].VertexBuffer = 0;
	KnucklesWeldInfo_r[42].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo_r[43].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[43].ModelA = KNUCKLES_OBJECTS[28];
	KnucklesWeldInfo_r[43].ModelB = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo_r[43].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo_r[43].WeldType = 2;
	KnucklesWeldInfo_r[43].anonymous_5 = 0;
	KnucklesWeldInfo_r[43].VertexBuffer = 0;
	KnucklesWeldInfo_r[43].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo_r[44].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[44].ModelA = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo_r[44].ModelB = KNUCKLES_OBJECTS[30];
	KnucklesWeldInfo_r[44].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo_r[44].WeldType = 2;
	KnucklesWeldInfo_r[44].anonymous_5 = 0;
	KnucklesWeldInfo_r[44].VertexBuffer = 0;
	KnucklesWeldInfo_r[44].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo_r[45].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[45].ModelA = KNUCKLES_OBJECTS[32];
	KnucklesWeldInfo_r[45].ModelB = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo_r[45].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[45].WeldType = 2;
	KnucklesWeldInfo_r[45].anonymous_5 = 0;
	KnucklesWeldInfo_r[45].VertexBuffer = 0;
	KnucklesWeldInfo_r[45].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[46].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[46].ModelA = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo_r[46].ModelB = KNUCKLES_OBJECTS[34];
	KnucklesWeldInfo_r[46].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[46].WeldType = 2;
	KnucklesWeldInfo_r[46].anonymous_5 = 0;
	KnucklesWeldInfo_r[46].VertexBuffer = 0;
	KnucklesWeldInfo_r[46].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[47].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[47].ModelA = KNUCKLES_OBJECTS[35];
	KnucklesWeldInfo_r[47].ModelB = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo_r[47].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[47].WeldType = 2;
	KnucklesWeldInfo_r[47].anonymous_5 = 0;
	KnucklesWeldInfo_r[47].VertexBuffer = 0;
	KnucklesWeldInfo_r[47].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[48].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[48].ModelA = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo_r[48].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo_r[48].ModelB = KNUCKLES_OBJECTS[37];
	KnucklesWeldInfo_r[48].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo_r[48].WeldType = 2;
	KnucklesWeldInfo_r[48].anonymous_5 = 0;
	KnucklesWeldInfo_r[48].VertexBuffer = 0;
	KnucklesWeldInfo_r[49].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[49].ModelA = KNUCKLES_OBJECTS[38];
	KnucklesWeldInfo_r[49].ModelB = KNUCKLES_OBJECTS[39];
	KnucklesWeldInfo_r[49].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo_r[49].WeldType = 2;
	KnucklesWeldInfo_r[49].anonymous_5 = 0;
	KnucklesWeldInfo_r[49].VertexBuffer = 0;
	KnucklesWeldInfo_r[49].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo_r[50].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[50].ModelA = KNUCKLES_OBJECTS[40];
	KnucklesWeldInfo_r[50].ModelB = KNUCKLES_OBJECTS[41];
	KnucklesWeldInfo_r[50].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo_r[50].WeldType = 2;
	KnucklesWeldInfo_r[50].anonymous_5 = 0;
	KnucklesWeldInfo_r[50].VertexBuffer = 0;
	KnucklesWeldInfo_r[50].VertIndexes = Knuckles_ShoeIndices_DC;

	//22 RIGHT HAND  HIERARCHY IS DIFFERENT WITH DC MODEL
	KnucklesWeldInfo_r[51].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[51].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[51].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[51].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo_r[51].WeldType = 2;
	KnucklesWeldInfo_r[51].anonymous_5 = 0;
	KnucklesWeldInfo_r[51].VertexBuffer = 0;
	KnucklesWeldInfo_r[51].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo_r[52].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[52].ModelA = KNUCKLES_OBJECTS[44];
	KnucklesWeldInfo_r[52].ModelB = KNUCKLES_OBJECTS[31];
	KnucklesWeldInfo_r[52].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo_r[52].WeldType = 2;
	KnucklesWeldInfo_r[52].anonymous_5 = 0;
	KnucklesWeldInfo_r[52].VertexBuffer = 0;
	KnucklesWeldInfo_r[52].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo_r[53].BaseModel = Root;
	KnucklesWeldInfo_r[53].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo_r[53].ModelB = 0;
	KnucklesWeldInfo_r[53].VertexPairCount = 2;
	KnucklesWeldInfo_r[53].WeldType = 4;
	KnucklesWeldInfo_r[53].anonymous_5 = 0;
	KnucklesWeldInfo_r[53].VertexBuffer = 0;
	KnucklesWeldInfo_r[53].VertIndexes = 0;
	KnucklesWeldInfo_r[54].BaseModel = Root;
	KnucklesWeldInfo_r[54].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[54].ModelB = 0;
	KnucklesWeldInfo_r[54].VertexPairCount = 2;
	KnucklesWeldInfo_r[54].WeldType = 5;
	KnucklesWeldInfo_r[54].anonymous_5 = 0;
	KnucklesWeldInfo_r[54].VertexBuffer = 0;
	KnucklesWeldInfo_r[54].VertIndexes = 0;
	KnucklesWeldInfo_r[55].BaseModel = Root;
	KnucklesWeldInfo_r[55].ModelB = 0;
	KnucklesWeldInfo_r[55].VertexPairCount = 0;
	KnucklesWeldInfo_r[55].anonymous_5 = 0;
	KnucklesWeldInfo_r[55].VertexBuffer = 0;
	KnucklesWeldInfo_r[55].VertIndexes = 0;
	KnucklesWeldInfo_r[55].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[55].WeldType = 6;
	KnucklesWeldInfo_r[56].BaseModel = Root;
	KnucklesWeldInfo_r[56].ModelB = 0;
	KnucklesWeldInfo_r[56].VertexPairCount = 0;
	KnucklesWeldInfo_r[56].anonymous_5 = 0;
	KnucklesWeldInfo_r[56].VertexBuffer = 0;
	KnucklesWeldInfo_r[56].VertIndexes = 0;
	KnucklesWeldInfo_r[56].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[56].WeldType = 7;
	KnucklesWeldInfo_r[57].BaseModel = Root;
	KnucklesWeldInfo_r[57].ModelB = 0;
	KnucklesWeldInfo_r[57].VertexPairCount = 0;
	KnucklesWeldInfo_r[57].anonymous_5 = 0;
	KnucklesWeldInfo_r[57].VertexBuffer = 0;
	KnucklesWeldInfo_r[57].VertIndexes = 0;
	KnucklesWeldInfo_r[57].ModelA = KNUCKLES_OBJECTS[54];
	KnucklesWeldInfo_r[57].WeldType = 8;
	KnucklesWeldInfo_r[58] = { 0 };
}


void __cdecl InitHyperKnucklesDX_WeldsInfo()
{
	KnucklesWeldInfo_r[29].BaseModel = HyperKnux_Model[root]->getmodel();

	NJS_OBJECT* Root = KnucklesWeldInfo_r[29].BaseModel;

	KnucklesWeldInfo_r[29].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[29].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[29].anonymous_5 = 0;
	KnucklesWeldInfo_r[29].VertexBuffer = 0;
	KnucklesWeldInfo_r[29].VertexPairCount = 4;
	KnucklesWeldInfo_r[29].WeldType = 2;
	KnucklesWeldInfo_r[29].VertIndexes = Knuckles_UpperArmIndices;

	KnucklesWeldInfo_r[30].BaseModel = Root;
	KnucklesWeldInfo_r[30].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[30].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[30].VertexPairCount = 4;
	KnucklesWeldInfo_r[30].WeldType = 2;
	KnucklesWeldInfo_r[30].anonymous_5 = 0;
	KnucklesWeldInfo_r[30].VertexBuffer = 0;
	KnucklesWeldInfo_r[30].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo_r[31].BaseModel = Root;
	KnucklesWeldInfo_r[31].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[31].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo_r[31].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[31].VertexPairCount = 4;
	KnucklesWeldInfo_r[31].WeldType = 2;
	KnucklesWeldInfo_r[31].anonymous_5 = 0;
	KnucklesWeldInfo_r[31].VertexBuffer = 0;
	KnucklesWeldInfo_r[32].BaseModel = Root;
	KnucklesWeldInfo_r[32].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[32].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[32].VertexPairCount = 4;
	KnucklesWeldInfo_r[32].WeldType = 2;
	KnucklesWeldInfo_r[32].anonymous_5 = 0;
	KnucklesWeldInfo_r[32].VertexBuffer = 0;
	KnucklesWeldInfo_r[32].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo_r[33].BaseModel = Root;
	KnucklesWeldInfo_r[33].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[33].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[33].VertexPairCount = 4;
	KnucklesWeldInfo_r[33].WeldType = 2;
	KnucklesWeldInfo_r[33].anonymous_5 = 0;
	KnucklesWeldInfo_r[33].VertexBuffer = 0;
	KnucklesWeldInfo_r[33].VertIndexes = (unsigned short*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[34].BaseModel = Root;
	KnucklesWeldInfo_r[34].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[34].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[34].WeldType = 2;
	KnucklesWeldInfo_r[34].anonymous_5 = 0;
	KnucklesWeldInfo_r[34].VertexBuffer = 0;
	KnucklesWeldInfo_r[34].VertIndexes = (unsigned short*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[35].BaseModel = Root;
	KnucklesWeldInfo_r[35].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo_r[35].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[35].VertexPairCount = 4;
	KnucklesWeldInfo_r[35].WeldType = 2;
	KnucklesWeldInfo_r[35].anonymous_5 = 0;
	KnucklesWeldInfo_r[35].VertexBuffer = 0;
	KnucklesWeldInfo_r[35].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[36].BaseModel = Root;
	KnucklesWeldInfo_r[36].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo_r[36].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo_r[36].VertexPairCount = 4;
	KnucklesWeldInfo_r[36].WeldType = 2;
	KnucklesWeldInfo_r[36].anonymous_5 = 0;
	KnucklesWeldInfo_r[36].VertexBuffer = 0;
	KnucklesWeldInfo_r[36].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[37].BaseModel = Root;
	KnucklesWeldInfo_r[37].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[37].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[37].VertexPairCount = 9;
	KnucklesWeldInfo_r[37].WeldType = 2;
	KnucklesWeldInfo_r[37].anonymous_5 = 0;
	KnucklesWeldInfo_r[37].VertexBuffer = 0;
	KnucklesWeldInfo_r[37].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo_r[38].BaseModel = Root;
	KnucklesWeldInfo_r[38].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[38].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo_r[38].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[38].VertexPairCount = 9;
	KnucklesWeldInfo_r[38].WeldType = 2;
	KnucklesWeldInfo_r[38].anonymous_5 = 0;
	KnucklesWeldInfo_r[38].VertexBuffer = 0;
	KnucklesWeldInfo_r[39].BaseModel = Root;
	KnucklesWeldInfo_r[39].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[39].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo_r[39].VertexPairCount = 8;
	KnucklesWeldInfo_r[39].WeldType = 2;
	KnucklesWeldInfo_r[39].anonymous_5 = 0;
	KnucklesWeldInfo_r[39].VertexBuffer = 0;
	KnucklesWeldInfo_r[39].VertIndexes = Knuckles_HandIndices;

	KnucklesWeldInfo_r[40].BaseModel = Root;
	KnucklesWeldInfo_r[40].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo_r[40].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[40].VertexPairCount = 8;
	KnucklesWeldInfo_r[40].WeldType = 2;
	KnucklesWeldInfo_r[40].anonymous_5 = 0;
	KnucklesWeldInfo_r[40].VertexBuffer = 0;
	KnucklesWeldInfo_r[40].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo_r[41].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[41].ModelA = KNUCKLES_OBJECTS[24];
	KnucklesWeldInfo_r[41].ModelB = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo_r[41].VertexPairCount = 4;
	KnucklesWeldInfo_r[41].WeldType = 2;
	KnucklesWeldInfo_r[41].anonymous_5 = 0;
	KnucklesWeldInfo_r[41].VertexBuffer = 0;
	KnucklesWeldInfo_r[41].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo_r[42].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[42].ModelA = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo_r[42].ModelB = KNUCKLES_OBJECTS[26];
	KnucklesWeldInfo_r[42].VertexPairCount = 4;
	KnucklesWeldInfo_r[42].WeldType = 2;
	KnucklesWeldInfo_r[42].anonymous_5 = 0;
	KnucklesWeldInfo_r[42].VertexBuffer = 0;
	KnucklesWeldInfo_r[42].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo_r[43].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[43].ModelA = KNUCKLES_OBJECTS[28];
	KnucklesWeldInfo_r[43].ModelB = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo_r[43].VertexPairCount = 4;
	KnucklesWeldInfo_r[43].WeldType = 2;
	KnucklesWeldInfo_r[43].anonymous_5 = 0;
	KnucklesWeldInfo_r[43].VertexBuffer = 0;
	KnucklesWeldInfo_r[43].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo_r[44].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[44].ModelA = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo_r[44].ModelB = KNUCKLES_OBJECTS[30];
	KnucklesWeldInfo_r[44].VertexPairCount = 4;
	KnucklesWeldInfo_r[44].WeldType = 2;
	KnucklesWeldInfo_r[44].anonymous_5 = 0;
	KnucklesWeldInfo_r[44].VertexBuffer = 0;
	KnucklesWeldInfo_r[44].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo_r[45].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[45].ModelA = KNUCKLES_OBJECTS[32];
	KnucklesWeldInfo_r[45].ModelB = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo_r[45].VertexPairCount = 4;
	KnucklesWeldInfo_r[45].WeldType = 2;
	KnucklesWeldInfo_r[45].anonymous_5 = 0;
	KnucklesWeldInfo_r[45].VertexBuffer = 0;
	KnucklesWeldInfo_r[45].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[46].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[46].ModelA = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo_r[46].ModelB = KNUCKLES_OBJECTS[34];
	KnucklesWeldInfo_r[46].VertexPairCount = 4;
	KnucklesWeldInfo_r[46].WeldType = 2;
	KnucklesWeldInfo_r[46].anonymous_5 = 0;
	KnucklesWeldInfo_r[46].VertexBuffer = 0;
	KnucklesWeldInfo_r[46].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[47].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[47].ModelA = KNUCKLES_OBJECTS[35];
	KnucklesWeldInfo_r[47].ModelB = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo_r[47].VertexPairCount = 4;
	KnucklesWeldInfo_r[47].WeldType = 2;
	KnucklesWeldInfo_r[47].anonymous_5 = 0;
	KnucklesWeldInfo_r[47].VertexBuffer = 0;
	KnucklesWeldInfo_r[47].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[48].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[48].ModelA = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo_r[48].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo_r[48].ModelB = KNUCKLES_OBJECTS[37];
	KnucklesWeldInfo_r[48].VertexPairCount = 4;
	KnucklesWeldInfo_r[48].WeldType = 2;
	KnucklesWeldInfo_r[48].anonymous_5 = 0;
	KnucklesWeldInfo_r[48].VertexBuffer = 0;
	KnucklesWeldInfo_r[49].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[49].ModelA = KNUCKLES_OBJECTS[38];
	KnucklesWeldInfo_r[49].ModelB = KNUCKLES_OBJECTS[39];
	KnucklesWeldInfo_r[49].VertexPairCount = 9;
	KnucklesWeldInfo_r[49].WeldType = 2;
	KnucklesWeldInfo_r[49].anonymous_5 = 0;
	KnucklesWeldInfo_r[49].VertexBuffer = 0;
	KnucklesWeldInfo_r[49].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;

	KnucklesWeldInfo_r[50].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[50].ModelA = KNUCKLES_OBJECTS[40];
	KnucklesWeldInfo_r[50].ModelB = KNUCKLES_OBJECTS[41];
	KnucklesWeldInfo_r[50].VertexPairCount = 9;
	KnucklesWeldInfo_r[50].WeldType = 2;
	KnucklesWeldInfo_r[50].anonymous_5 = 0;
	KnucklesWeldInfo_r[50].VertexBuffer = 0;
	KnucklesWeldInfo_r[50].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo_r[52].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[52].ModelA = KNUCKLES_OBJECTS[42];
	KnucklesWeldInfo_r[52].ModelB = KNUCKLES_OBJECTS[27];
	KnucklesWeldInfo_r[52].VertexPairCount = 8;
	KnucklesWeldInfo_r[52].WeldType = 2;
	KnucklesWeldInfo_r[52].anonymous_5 = 0;
	KnucklesWeldInfo_r[52].VertexBuffer = 0;
	KnucklesWeldInfo_r[52].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo_r[53].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo_r[53].ModelA = KNUCKLES_OBJECTS[44];
	KnucklesWeldInfo_r[53].ModelB = KNUCKLES_OBJECTS[31];
	KnucklesWeldInfo_r[53].VertexPairCount = 8;
	KnucklesWeldInfo_r[53].WeldType = 2;
	KnucklesWeldInfo_r[53].anonymous_5 = 0;
	KnucklesWeldInfo_r[53].VertexBuffer = 0;
	KnucklesWeldInfo_r[53].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo_r[54].BaseModel = Root;
	KnucklesWeldInfo_r[54].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo_r[54].ModelB = 0;
	KnucklesWeldInfo_r[54].VertexPairCount = 2;
	KnucklesWeldInfo_r[54].WeldType = 4;
	KnucklesWeldInfo_r[54].anonymous_5 = 0;
	KnucklesWeldInfo_r[54].VertexBuffer = 0;
	KnucklesWeldInfo_r[54].VertIndexes = 0;
	KnucklesWeldInfo_r[55].BaseModel = Root;
	KnucklesWeldInfo_r[55].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[55].ModelB = 0;
	KnucklesWeldInfo_r[55].VertexPairCount = 2;
	KnucklesWeldInfo_r[55].WeldType = 5;
	KnucklesWeldInfo_r[55].anonymous_5 = 0;
	KnucklesWeldInfo_r[55].VertexBuffer = 0;
	KnucklesWeldInfo_r[55].VertIndexes = 0;
	KnucklesWeldInfo_r[56].BaseModel = Root;
	KnucklesWeldInfo_r[56].ModelB = 0;
	KnucklesWeldInfo_r[56].VertexPairCount = 0;
	KnucklesWeldInfo_r[56].anonymous_5 = 0;
	KnucklesWeldInfo_r[56].VertexBuffer = 0;
	KnucklesWeldInfo_r[56].VertIndexes = 0;
	KnucklesWeldInfo_r[56].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[56].WeldType = 6;
	KnucklesWeldInfo_r[57].BaseModel = Root;
	KnucklesWeldInfo_r[57].ModelB = 0;
	KnucklesWeldInfo_r[57].VertexPairCount = 0;
	KnucklesWeldInfo_r[57].anonymous_5 = 0;
	KnucklesWeldInfo_r[57].VertexBuffer = 0;
	KnucklesWeldInfo_r[57].VertIndexes = 0;
	KnucklesWeldInfo_r[57].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo_r[57].WeldType = 7;
	KnucklesWeldInfo_r[58].BaseModel = Root;
	KnucklesWeldInfo_r[58].ModelB = 0;
	KnucklesWeldInfo_r[58].VertexPairCount = 0;
	KnucklesWeldInfo_r[58].anonymous_5 = 0;
	KnucklesWeldInfo_r[58].VertexBuffer = 0;
	KnucklesWeldInfo_r[58].ModelA = KNUCKLES_OBJECTS[54];
	KnucklesWeldInfo_r[58].WeldType = 8;
	KnucklesWeldInfo_r[58].VertIndexes = 0;

	KnucklesWeldInfo_r[59] = { 0 };
}

void CopyKnuxOriginalModel()
{
	KnuxObjCopy[0] = KNUCKLES_OBJECTS[0];
	KnuxObjCopy[1] = KNUCKLES_OBJECTS[1];
	KnuxObjCopy[2] = KNUCKLES_OBJECTS[2];
	KnuxObjCopy[3] = KNUCKLES_OBJECTS[3];
	KnuxObjCopy[4] = KNUCKLES_OBJECTS[4];
	KnuxObjCopy[5] = KNUCKLES_OBJECTS[5];
	KnuxObjCopy[6] = KNUCKLES_OBJECTS[6];
	KnuxObjCopy[7] = KNUCKLES_OBJECTS[7];
	KnuxObjCopy[8] = KNUCKLES_OBJECTS[8];
	KnuxObjCopy[9] = KNUCKLES_OBJECTS[9];

	KnuxObjCopy[10] = KNUCKLES_OBJECTS[10];
	KnuxObjCopy[11] = KNUCKLES_OBJECTS[11];
	KnuxObjCopy[12] = KNUCKLES_OBJECTS[12];
	KnuxObjCopy[13] = KNUCKLES_OBJECTS[13];
	KnuxObjCopy[14] = KNUCKLES_OBJECTS[14];
	KnuxObjCopy[15] = KNUCKLES_OBJECTS[15];
	KnuxObjCopy[16] = KNUCKLES_OBJECTS[16];
	KnuxObjCopy[17] = KNUCKLES_OBJECTS[17];
	KnuxObjCopy[18] = KNUCKLES_OBJECTS[18];
	KnuxObjCopy[19] = KNUCKLES_OBJECTS[19];

	KnuxObjCopy[20] = KNUCKLES_OBJECTS[20];
	KnuxObjCopy[21] = KNUCKLES_OBJECTS[21];
	KnuxObjCopy[22] = KNUCKLES_OBJECTS[22];
	KnuxObjCopy[23] = KNUCKLES_OBJECTS[23];
	KnuxObjCopy[24] = KNUCKLES_OBJECTS[24];
	KnuxObjCopy[25] = KNUCKLES_OBJECTS[25];
	KnuxObjCopy[26] = KNUCKLES_OBJECTS[26];
	KnuxObjCopy[27] = KNUCKLES_OBJECTS[27];
	KnuxObjCopy[28] = KNUCKLES_OBJECTS[28];
	KnuxObjCopy[29] = KNUCKLES_OBJECTS[29];

	KnuxObjCopy[30] = KNUCKLES_OBJECTS[30];
	KnuxObjCopy[31] = KNUCKLES_OBJECTS[31];
	KnuxObjCopy[32] = KNUCKLES_OBJECTS[32];
	KnuxObjCopy[33] = KNUCKLES_OBJECTS[33];
	KnuxObjCopy[34] = KNUCKLES_OBJECTS[34];
	KnuxObjCopy[35] = KNUCKLES_OBJECTS[35];
	KnuxObjCopy[36] = KNUCKLES_OBJECTS[36];
	KnuxObjCopy[37] = KNUCKLES_OBJECTS[37];
	KnuxObjCopy[38] = KNUCKLES_OBJECTS[38];
	KnuxObjCopy[39] = KNUCKLES_OBJECTS[39];

	KnuxObjCopy[40] = KNUCKLES_OBJECTS[40];
	KnuxObjCopy[41] = KNUCKLES_OBJECTS[41];
	KnuxObjCopy[42] = KNUCKLES_OBJECTS[42];
	KnuxObjCopy[43] = KNUCKLES_OBJECTS[43];
	KnuxObjCopy[44] = KNUCKLES_OBJECTS[44];
	KnuxObjCopy[45] = KNUCKLES_OBJECTS[45];
	KnuxObjCopy[46] = KNUCKLES_OBJECTS[46];
	KnuxObjCopy[47] = KNUCKLES_OBJECTS[47];
	KnuxObjCopy[48] = KNUCKLES_OBJECTS[48];
	KnuxObjCopy[49] = KNUCKLES_OBJECTS[49];

	KnuxObjCopy[50] = KNUCKLES_OBJECTS[50];
	KnuxObjCopy[51] = KNUCKLES_OBJECTS[51];
	KnuxObjCopy[52] = KNUCKLES_OBJECTS[52];
	KnuxObjCopy[53] = KNUCKLES_OBJECTS[53];
	KnuxObjCopy[54] = KNUCKLES_OBJECTS[54];
	KnuxObjCopy[55] = KNUCKLES_OBJECTS[55];
	KnuxObjCopy[56] = KNUCKLES_OBJECTS[56];
	KnuxObjCopy[57] = KNUCKLES_OBJECTS[57];
	KnuxObjCopy[58] = KNUCKLES_OBJECTS[58];
	KnuxObjCopy[59] = KNUCKLES_OBJECTS[59];

	KnuxObjCopy[60] = KNUCKLES_OBJECTS[60];
	KnuxObjCopy[61] = KNUCKLES_OBJECTS[61];
	KnuxObjCopy[62] = KNUCKLES_OBJECTS[62];
	KnuxObjCopy[63] = KNUCKLES_OBJECTS[63];
	KnuxObjCopy[64] = KNUCKLES_OBJECTS[64];
	KnuxObjCopy[65] = KNUCKLES_OBJECTS[65];
	KnuxObjCopy[66] = KNUCKLES_OBJECTS[66];
	KnuxObjCopy[67] = KNUCKLES_OBJECTS[67];
	KnuxObjCopy[68] = KNUCKLES_OBJECTS[68];
	KnuxObjCopy[69] = KNUCKLES_OBJECTS[69];

	KnuxObjCopy[70] = KNUCKLES_OBJECTS[70];
	KnuxObjCopy[71] = KNUCKLES_OBJECTS[71];
	KnuxObjCopy[72] = KNUCKLES_OBJECTS[72];
	KnuxObjCopy[73] = KNUCKLES_OBJECTS[73];

	//Also copy KNUCKLES_MODELS for upgrade stuff
	KnuxModelCopy[0] = KNUCKLES_MODELS[0];
	KnuxModelCopy[1] = KNUCKLES_MODELS[1];
	KnuxModelCopy[2] = KNUCKLES_MODELS[2];
	KnuxModelCopy[3] = KNUCKLES_MODELS[3];
	KnuxModelCopy[4] = KNUCKLES_MODELS[4];
	KnuxModelCopy[5] = KNUCKLES_MODELS[5];
	KnuxModelCopy[6] = KNUCKLES_MODELS[6];
	KnuxModelCopy[7] = KNUCKLES_MODELS[7];
	KnuxModelCopy[8] = KNUCKLES_MODELS[8];
	KnuxModelCopy[9] = KNUCKLES_MODELS[9];
	KnuxModelCopy[10] = KNUCKLES_MODELS[10];
	KnuxModelCopy[11] = KNUCKLES_MODELS[11];
	KnuxModelCopy[12] = KNUCKLES_MODELS[12];
	KnuxModelCopy[13] = KNUCKLES_MODELS[13];
	KnuxModelCopy[14] = KNUCKLES_MODELS[14];
	KnuxModelCopy[15] = KNUCKLES_MODELS[15];
	KnuxModelCopy[16] = KNUCKLES_MODELS[16];
	KnuxModelCopy[17] = KNUCKLES_MODELS[17];
	KnuxModelCopy[18] = KNUCKLES_MODELS[18];
	KnuxModelCopy[19] = KNUCKLES_MODELS[19];
	KnuxModelCopy[20] = KNUCKLES_MODELS[20];
	KnuxModelCopy[21] = KNUCKLES_MODELS[21];
	KnuxModelCopy[22] = KNUCKLES_MODELS[22];
}

void RestoreKnuxModels(taskwk* data)
{
	KNUCKLES_OBJECTS[0] = KnuxObjCopy[0];
	KNUCKLES_OBJECTS[1] = KnuxObjCopy[1];
	KNUCKLES_OBJECTS[2] = KnuxObjCopy[2];
	KNUCKLES_OBJECTS[3] = KnuxObjCopy[3];
	KNUCKLES_OBJECTS[4] = KnuxObjCopy[4];
	KNUCKLES_OBJECTS[5] = KnuxObjCopy[5];
	KNUCKLES_OBJECTS[6] = KnuxObjCopy[6];
	KNUCKLES_OBJECTS[7] = KnuxObjCopy[7];
	KNUCKLES_OBJECTS[8] = KnuxObjCopy[8];

	KNUCKLES_OBJECTS[9] = KnuxObjCopy[9];
	KNUCKLES_OBJECTS[10] = KnuxObjCopy[10];
	KNUCKLES_OBJECTS[11] = KnuxObjCopy[11];
	KNUCKLES_OBJECTS[12] = KnuxObjCopy[12];
	KNUCKLES_OBJECTS[13] = KnuxObjCopy[13];
	KNUCKLES_OBJECTS[14] = KnuxObjCopy[14];
	KNUCKLES_OBJECTS[15] = KnuxObjCopy[15];
	KNUCKLES_OBJECTS[16] = KnuxObjCopy[16];
	KNUCKLES_OBJECTS[17] = KnuxObjCopy[17];
	KNUCKLES_OBJECTS[18] = KnuxObjCopy[18];
	KNUCKLES_OBJECTS[19] = KnuxObjCopy[19];

	KNUCKLES_OBJECTS[20] = KnuxObjCopy[20];
	KNUCKLES_OBJECTS[21] = KnuxObjCopy[21];
	KNUCKLES_OBJECTS[22] = KnuxObjCopy[22];
	KNUCKLES_OBJECTS[23] = KnuxObjCopy[23];
	KNUCKLES_OBJECTS[24] = KnuxObjCopy[24];
	KNUCKLES_OBJECTS[25] = KnuxObjCopy[25];
	KNUCKLES_OBJECTS[26] = KnuxObjCopy[26];
	KNUCKLES_OBJECTS[27] = KnuxObjCopy[27];
	KNUCKLES_OBJECTS[28] = KnuxObjCopy[28];
	KNUCKLES_OBJECTS[29] = KnuxObjCopy[29];

	KNUCKLES_OBJECTS[30] = KnuxObjCopy[30];
	KNUCKLES_OBJECTS[31] = KnuxObjCopy[31];
	KNUCKLES_OBJECTS[32] = KnuxObjCopy[32];
	KNUCKLES_OBJECTS[33] = KnuxObjCopy[33];
	KNUCKLES_OBJECTS[34] = KnuxObjCopy[34];
	KNUCKLES_OBJECTS[35] = KnuxObjCopy[35];
	KNUCKLES_OBJECTS[36] = KnuxObjCopy[36];
	KNUCKLES_OBJECTS[37] = KnuxObjCopy[37];
	KNUCKLES_OBJECTS[38] = KnuxObjCopy[38];
	KNUCKLES_OBJECTS[39] = KnuxObjCopy[39];

	KNUCKLES_OBJECTS[40] = KnuxObjCopy[40];
	KNUCKLES_OBJECTS[41] = KnuxObjCopy[41];
	KNUCKLES_OBJECTS[42] = KnuxObjCopy[42];
	KNUCKLES_OBJECTS[43] = KnuxObjCopy[43];
	KNUCKLES_OBJECTS[44] = KnuxObjCopy[44];
	KNUCKLES_OBJECTS[45] = KnuxObjCopy[45];
	KNUCKLES_OBJECTS[46] = KnuxObjCopy[46];
	KNUCKLES_OBJECTS[47] = KnuxObjCopy[47];
	KNUCKLES_OBJECTS[48] = KnuxObjCopy[48];
	KNUCKLES_OBJECTS[49] = KnuxObjCopy[49];

	KNUCKLES_OBJECTS[50] = KnuxObjCopy[50];
	KNUCKLES_OBJECTS[51] = KnuxObjCopy[51];
	KNUCKLES_OBJECTS[52] = KnuxObjCopy[52];
	KNUCKLES_OBJECTS[53] = KnuxObjCopy[53];
	KNUCKLES_OBJECTS[54] = KnuxObjCopy[54];
	KNUCKLES_OBJECTS[55] = KnuxObjCopy[55];
	KNUCKLES_OBJECTS[56] = KnuxObjCopy[56];
	KNUCKLES_OBJECTS[57] = KnuxObjCopy[57];
	KNUCKLES_OBJECTS[58] = KnuxObjCopy[58];
	KNUCKLES_OBJECTS[59] = KnuxObjCopy[59];

	KNUCKLES_OBJECTS[60] = KnuxObjCopy[60];
	KNUCKLES_OBJECTS[61] = KnuxObjCopy[61];
	KNUCKLES_OBJECTS[62] = KnuxObjCopy[62];
	KNUCKLES_OBJECTS[63] = KnuxObjCopy[63];
	KNUCKLES_OBJECTS[64] = KnuxObjCopy[64];
	KNUCKLES_OBJECTS[65] = KnuxObjCopy[65];
	KNUCKLES_OBJECTS[66] = KnuxObjCopy[66];
	KNUCKLES_OBJECTS[67] = KnuxObjCopy[67];
	KNUCKLES_OBJECTS[68] = KnuxObjCopy[68];
	KNUCKLES_OBJECTS[69] = KnuxObjCopy[69];

	KNUCKLES_OBJECTS[70] = KnuxObjCopy[70];
	KNUCKLES_OBJECTS[71] = KnuxObjCopy[71];
	KNUCKLES_OBJECTS[72] = KnuxObjCopy[72];

	KNUCKLES_MODELS[0] = KnuxModelCopy[0];
	KNUCKLES_MODELS[1] = KnuxModelCopy[1];
	KNUCKLES_MODELS[2] = KnuxModelCopy[2];
	KNUCKLES_MODELS[3] = KnuxModelCopy[3];
	KNUCKLES_MODELS[4] = KnuxModelCopy[4];
	KNUCKLES_MODELS[5] = KnuxModelCopy[5];
	KNUCKLES_MODELS[6] = KnuxModelCopy[6];
	KNUCKLES_MODELS[7] = KnuxModelCopy[7];
	KNUCKLES_MODELS[8] = KnuxModelCopy[8];
	KNUCKLES_MODELS[9] = KnuxModelCopy[9];
	KNUCKLES_MODELS[10] = KnuxModelCopy[10];
	KNUCKLES_MODELS[11] = KnuxModelCopy[11];
	KNUCKLES_MODELS[12] = KnuxModelCopy[12];
	KNUCKLES_MODELS[13] = KnuxModelCopy[13];
	KNUCKLES_MODELS[14] = KnuxModelCopy[14];
	KNUCKLES_MODELS[15] = KnuxModelCopy[15];
	KNUCKLES_MODELS[16] = KnuxModelCopy[16];
	KNUCKLES_MODELS[17] = KnuxModelCopy[17];
	KNUCKLES_MODELS[18] = KnuxModelCopy[18];
	KNUCKLES_MODELS[19] = KnuxModelCopy[19];
	KNUCKLES_MODELS[20] = KnuxModelCopy[20];
	KNUCKLES_MODELS[21] = KnuxModelCopy[21];
	KNUCKLES_MODELS[22] = KnuxModelCopy[22];

	if (data) {
		LoadRegularKnuxJiggle(data->counter.b[0]);
	}
}

void SetHyperKnuxModel_()
{
	KNUCKLES_OBJECTS[0] = HyperKnux_Model[root]->getmodel();
	KNUCKLES_OBJECTS[1] = HyperKnux_Model[root]->getmodel();

	KNUCKLES_OBJECTS[2] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //2

	KNUCKLES_OBJECTS[3] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //3);
	KNUCKLES_OBJECTS[4] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;

	if (charType != Dreamcast)
		KNUCKLES_OBJECTS[5] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	else
		KNUCKLES_OBJECTS[5] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;

	KNUCKLES_OBJECTS[6] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[7] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[8] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;

	KNUCKLES_OBJECTS[9] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[10] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[11] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[12] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[13] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[14] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[15] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[16] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;

	KNUCKLES_OBJECTS[17] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[18] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[19] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[20] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[21] = KNUCKLES_OBJECTS[5];
	KNUCKLES_OBJECTS[22] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;

	KNUCKLES_OBJECTS[23] = KNUCKLES_OBJECTS[9];

	KNUCKLES_OBJECTS[24] = KNUCKLES_OBJECTS[2];
	KNUCKLES_OBJECTS[25] = KNUCKLES_OBJECTS[3];
	KNUCKLES_OBJECTS[26] = KNUCKLES_OBJECTS[4];
	KNUCKLES_OBJECTS[27] = KNUCKLES_OBJECTS[5];
	KNUCKLES_OBJECTS[28] = KNUCKLES_OBJECTS[6];
	KNUCKLES_OBJECTS[29] = KNUCKLES_OBJECTS[7];
	KNUCKLES_OBJECTS[30] = KNUCKLES_OBJECTS[8];
	KNUCKLES_OBJECTS[31] = KNUCKLES_OBJECTS[9];
	KNUCKLES_OBJECTS[32] = KNUCKLES_OBJECTS[10];
	KNUCKLES_OBJECTS[33] = KNUCKLES_OBJECTS[11];
	KNUCKLES_OBJECTS[34] = KNUCKLES_OBJECTS[12];
	KNUCKLES_OBJECTS[35] = KNUCKLES_OBJECTS[13];
	KNUCKLES_OBJECTS[36] = KNUCKLES_OBJECTS[14];
	KNUCKLES_OBJECTS[37] = KNUCKLES_OBJECTS[15];
	KNUCKLES_OBJECTS[38] = KNUCKLES_OBJECTS[16];
	KNUCKLES_OBJECTS[39] = KNUCKLES_OBJECTS[17];
	KNUCKLES_OBJECTS[40] = KNUCKLES_OBJECTS[18];
	KNUCKLES_OBJECTS[41] = KNUCKLES_OBJECTS[19];
	KNUCKLES_OBJECTS[42] = KNUCKLES_OBJECTS[20];
	KNUCKLES_OBJECTS[43] = KNUCKLES_OBJECTS[21];
	KNUCKLES_OBJECTS[44] = KNUCKLES_OBJECTS[22];
	KNUCKLES_OBJECTS[45] = KNUCKLES_OBJECTS[23];
	
	KNUCKLES_OBJECTS[49] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling; //head
	KNUCKLES_OBJECTS[50] = KNUCKLES_OBJECTS[49];
	KNUCKLES_OBJECTS[51] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling; // FACE ROOT
	KNUCKLES_OBJECTS[52] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->child->child->sibling; // right eye
	KNUCKLES_OBJECTS[53] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->child->child->sibling; // left eye

	KNUCKLES_OBJECTS[54] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling; //left eye ROOT
	KNUCKLES_OBJECTS[55] = KNUCKLES_OBJECTS[49];


	KNUCKLES_OBJECTS[58] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[59] = KNUCKLES_OBJECTS[22];
	KNUCKLES_OBJECTS[60] = KNUCKLES_OBJECTS[9];
	KNUCKLES_OBJECTS[61] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KNUCKLES_OBJECTS[62] = KNUCKLES_OBJECTS[4];
	KNUCKLES_OBJECTS[63] = KNUCKLES_OBJECTS[20];
	KNUCKLES_OBJECTS[64] = KNUCKLES_OBJECTS[5];

	//Thumb model hiearchy is also different with DC Glide Model.
	if (charType == Dreamcast)
		KNUCKLES_OBJECTS[65] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	else
		KNUCKLES_OBJECTS[65] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;

	KNUCKLES_OBJECTS[66] = KNUCKLES_OBJECTS[58];
	KNUCKLES_OBJECTS[67] = KNUCKLES_OBJECTS[22];
	KNUCKLES_OBJECTS[68] = KNUCKLES_OBJECTS[9];
	KNUCKLES_OBJECTS[69] = KNUCKLES_OBJECTS[61];
	KNUCKLES_OBJECTS[70] = KNUCKLES_OBJECTS[4];
	KNUCKLES_OBJECTS[71] = KNUCKLES_OBJECTS[63];
	KNUCKLES_OBJECTS[72] = KNUCKLES_OBJECTS[64];
	KNUCKLES_OBJECTS[73] = KNUCKLES_OBJECTS[65];

	//upgrades stuff
	KNUCKLES_MODELS[0] = HyperKnux_Model[11]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[1] = HyperKnux_Model[12]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[2] = HyperKnux_Model[13]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[3] = HyperKnux_Model[14]->getmodel()->basicdxmodel;

	KNUCKLES_MODELS[4] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->basicdxmodel;
	KNUCKLES_MODELS[5] = KNUCKLES_MODELS[4];
	KNUCKLES_MODELS[6] = HyperKnux_Model[15]->getmodel()->basicdxmodel; //morph head

	KNUCKLES_MODELS[7] = KNUCKLES_OBJECTS[8]->getbasicdxmodel();
	KNUCKLES_MODELS[8] = KNUCKLES_OBJECTS[22]->getbasicdxmodel();
	KNUCKLES_MODELS[9] = KNUCKLES_OBJECTS[23]->getbasicdxmodel();

	KNUCKLES_MODELS[10] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling->getbasicdxmodel();

	KNUCKLES_MODELS[11] = KNUCKLES_OBJECTS[4]->getbasicdxmodel();
	KNUCKLES_MODELS[12] = KNUCKLES_OBJECTS[20]->getbasicdxmodel();
	KNUCKLES_MODELS[13] = KNUCKLES_OBJECTS[5]->getbasicdxmodel();

	if (charType == Dreamcast)
		KNUCKLES_MODELS[14] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling->getbasicdxmodel();
	else
		KNUCKLES_MODELS[14] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->getbasicdxmodel();

	KNUCKLES_MODELS[15] = HyperKnux_Model[lw]->getmodel()->basicdxmodel;

	KNUCKLES_MODELS[16] = HyperKnux_Model[5]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[17] = HyperKnux_Model[6]->getmodel()->basicdxmodel;

	KNUCKLES_MODELS[18] = HyperKnux_Model[7]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[19] = HyperKnux_Model[rw]->getmodel()->basicdxmodel;

	KNUCKLES_MODELS[20] = HyperKnux_Model[8]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[21] = HyperKnux_Model[9]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[22] = HyperKnux_Model[10]->getmodel()->basicdxmodel;
}

void SetHyperKnuxModel(EntityData1* data, CharObj2* co2, EntityData2* data2)
{
	if (charType == none)
		return;

	SetHyperKnuxModel_();
}


void CopyKnuxOriginalAnims()
{
	//anim obj
	KnuxAnimCopy[0] = KNUCKLES_ACTIONS[0]->object;
	KnuxAnimCopy[1] = KNUCKLES_ACTIONS[1]->object;
	KnuxAnimCopy[2] = KNUCKLES_ACTIONS[2]->object;
	KnuxAnimCopy[3] = KNUCKLES_ACTIONS[3]->object;
	KnuxAnimCopy[4] = KNUCKLES_ACTIONS[4]->object;
	KnuxAnimCopy[5] = KNUCKLES_ACTIONS[5]->object;
	KnuxAnimCopy[6] = KNUCKLES_ACTIONS[6]->object;
	KnuxAnimCopy[7] = KNUCKLES_ACTIONS[7]->object;

	KnuxAnimCopy[9] = KNUCKLES_ACTIONS[9]->object;
	KnuxAnimCopy[10] = KNUCKLES_ACTIONS[10]->object;
	KnuxAnimCopy[11] = KNUCKLES_ACTIONS[11]->object;
	KnuxAnimCopy[12] = KNUCKLES_ACTIONS[12]->object;
	KnuxAnimCopy[13] = KNUCKLES_ACTIONS[13]->object;
	KnuxAnimCopy[14] = KNUCKLES_ACTIONS[14]->object;
	KnuxAnimCopy[15] = KNUCKLES_ACTIONS[15]->object;
	KnuxAnimCopy[16] = KNUCKLES_ACTIONS[16]->object;
	KnuxAnimCopy[17] = KNUCKLES_ACTIONS[17]->object;
	KnuxAnimCopy[18] = KNUCKLES_ACTIONS[18]->object;
	KnuxAnimCopy[19] = KNUCKLES_ACTIONS[19]->object;
	KnuxAnimCopy[20] = KNUCKLES_ACTIONS[20]->object;
	KnuxAnimCopy[21] = KNUCKLES_ACTIONS[21]->object;
	KnuxAnimCopy[22] = KNUCKLES_ACTIONS[22]->object;
	KnuxAnimCopy[23] = KNUCKLES_ACTIONS[23]->object;
	KnuxAnimCopy[24] = KNUCKLES_ACTIONS[24]->object;
	KnuxAnimCopy[25] = KNUCKLES_ACTIONS[25]->object;
	KnuxAnimCopy[26] = KNUCKLES_ACTIONS[26]->object;
	KnuxAnimCopy[27] = KNUCKLES_ACTIONS[27]->object;
	KnuxAnimCopy[28] = KNUCKLES_ACTIONS[28]->object;
	KnuxAnimCopy[29] = KNUCKLES_ACTIONS[29]->object;
	KnuxAnimCopy[30] = KNUCKLES_ACTIONS[30]->object;
	KnuxAnimCopy[31] = KNUCKLES_ACTIONS[31]->object;
	KnuxAnimCopy[32] = KNUCKLES_ACTIONS[32]->object;
	KnuxAnimCopy[33] = KNUCKLES_ACTIONS[33]->object;
	KnuxAnimCopy[34] = KNUCKLES_ACTIONS[34]->object;
	KnuxAnimCopy[35] = KNUCKLES_ACTIONS[35]->object;
	KnuxAnimCopy[36] = KNUCKLES_ACTIONS[36]->object;
	KnuxAnimCopy[37] = KNUCKLES_ACTIONS[37]->object;
	KnuxAnimCopy[38] = KNUCKLES_ACTIONS[38]->object;
	KnuxAnimCopy[39] = KNUCKLES_ACTIONS[39]->object;
	KnuxAnimCopy[40] = KNUCKLES_ACTIONS[40]->object;
	KnuxAnimCopy[41] = KNUCKLES_ACTIONS[41]->object;
	KnuxAnimCopy[42] = KNUCKLES_ACTIONS[42]->object;
	KnuxAnimCopy[43] = KNUCKLES_ACTIONS[43]->object;
	KnuxAnimCopy[44] = KNUCKLES_ACTIONS[44]->object;
	KnuxAnimCopy[45] = KNUCKLES_ACTIONS[45]->object;
	KnuxAnimCopy[46] = KNUCKLES_ACTIONS[46]->object;
	KnuxAnimCopy[47] = KNUCKLES_ACTIONS[47]->object;
	KnuxAnimCopy[48] = KNUCKLES_ACTIONS[48]->object;
	KnuxAnimCopy[49] = KNUCKLES_ACTIONS[49]->object;
	KnuxAnimCopy[50] = KNUCKLES_ACTIONS[50]->object;
	KnuxAnimCopy[51] = KNUCKLES_ACTIONS[51]->object;
	KnuxAnimCopy[52] = KNUCKLES_ACTIONS[52]->object;
	KnuxAnimCopy[53] = KNUCKLES_ACTIONS[53]->object;
	KnuxAnimCopy[54] = KNUCKLES_ACTIONS[54]->object;
	KnuxAnimCopy[55] = KNUCKLES_ACTIONS[55]->object;
	KnuxAnimCopy[56] = KNUCKLES_ACTIONS[56]->object;
	KnuxAnimCopy[57] = KNUCKLES_ACTIONS[57]->object;
	KnuxAnimCopy[58] = KNUCKLES_ACTIONS[58]->object;
	KnuxAnimCopy[59] = KNUCKLES_ACTIONS[59]->object;
	KnuxAnimCopy[60] = KNUCKLES_ACTIONS[60]->object;
	KnuxAnimCopy[61] = KNUCKLES_ACTIONS[61]->object;
	KnuxAnimCopy[62] = KNUCKLES_ACTIONS[62]->object;
	KnuxAnimCopy[63] = KNUCKLES_ACTIONS[63]->object;
	KnuxAnimCopy[64] = KNUCKLES_ACTIONS[64]->object;
	KnuxAnimCopy[65] = KNUCKLES_ACTIONS[65]->object;
	KnuxAnimCopy[66] = KNUCKLES_ACTIONS[66]->object;
	KnuxAnimCopy[67] = KNUCKLES_ACTIONS[67]->object;
	KnuxAnimCopy[68] = KNUCKLES_ACTIONS[68]->object;
	KnuxAnimCopy[69] = KNUCKLES_ACTIONS[69]->object;
	KnuxAnimCopy[70] = KNUCKLES_ACTIONS[70]->object;
	KnuxAnimCopy[71] = KNUCKLES_ACTIONS[71]->object;
	KnuxAnimCopy[72] = KNUCKLES_ACTIONS[72]->object;
	KnuxAnimCopy[73] = KNUCKLES_ACTIONS[73]->object;
	KnuxAnimCopy[74] = KNUCKLES_ACTIONS[74]->object;
	KnuxAnimCopy[75] = KNUCKLES_ACTIONS[75]->object;
	KnuxAnimCopy[76] = KNUCKLES_ACTIONS[76]->object;
	KnuxAnimCopy[77] = KNUCKLES_ACTIONS[77]->object;
	KnuxAnimCopy[78] = KNUCKLES_ACTIONS[78]->object;
	KnuxAnimCopy[79] = KNUCKLES_ACTIONS[79]->object;
	KnuxAnimCopy[80] = KNUCKLES_ACTIONS[80]->object;
	KnuxAnimCopy[81] = KNUCKLES_ACTIONS[81]->object;
	KnuxAnimCopy[82] = KNUCKLES_ACTIONS[82]->object;
	KnuxAnimCopy[83] = KNUCKLES_ACTIONS[83]->object;
	KnuxAnimCopy[84] = KNUCKLES_ACTIONS[84]->object;
	KnuxAnimCopy[85] = KNUCKLES_ACTIONS[85]->object;
	KnuxAnimCopy[86] = KNUCKLES_ACTIONS[86]->object;
	KnuxAnimCopy[87] = KNUCKLES_ACTIONS[87]->object;
	KnuxAnimCopy[88] = KNUCKLES_ACTIONS[88]->object;
	KnuxAnimCopy[89] = KNUCKLES_ACTIONS[89]->object;
}


void RestoreKnuxAnim()
{
	for (uint8_t i = 0; i < LengthOfArray(KnuxAnimCopy); i++)
	{
		if (i == 8)
			continue;

		KNUCKLES_ACTIONS[i]->object = KnuxAnimCopy[i];
	}
}

void SetHyperKnuxAnim()
{
	for (uint8_t i = 0; i < LengthOfArray(KnuxAnimCopy); i++)
	{
		//8 is empty
		if (i == 8 || i == 61 || i == 62)
			continue;

		KNUCKLES_ACTIONS[i]->object = HyperKnux_Model[root]->getmodel();
	}

	KNUCKLES_ACTIONS[61]->object = HyperKnux_Model[curl]->getmodel();
	KNUCKLES_ACTIONS[62]->object = HyperKnux_Model[ball]->getmodel();
}

void SetHyperKnuxAnimModel(EntityData1* data, CharObj2* co2, EntityData2* data2)
{
	if (charType == none || AlwaysHyperKnux)
		return;

	SetHyperKnuxModel(data, co2, data2);
	SetHyperKnuxAnim();
}

void InitKnucklesWeldInfo_r()
{

	InitKnucklesWeldInfo_t.Original();

	memcpy(KnucklesWeldInfo_r, KnucklesWeldInfo, sizeof(WeldInfo) * KnucklesWeldInfo.size());

	if (charType == Dreamcast)
	{
		InitHyperKnucklesDC_WeldsInfo();
	}
	else
	{
		InitHyperKnucklesDX_WeldsInfo();
	}
}

void Backup_KnuxModelAnims()
{
	if (charType == none)
		return;

	if (!AlwaysHyperKnux) {
		CopyKnuxOriginalModel();
		CopyKnuxOriginalAnims();
	}
	else
	{
		SetHyperKnuxModel_();
		SetHyperKnuxAnim();
	}


	InitKnucklesWeldInfo_t.Hook(InitKnucklesWeldInfo_r);
	WriteData((WeldInfo**)0x47a89E, KnucklesWeldInfo_r);

	return;
}


void RestoreKnuxAnimModel(taskwk* data)
{
	if (charType == none)
		return;

	RestoreKnuxModels(data);
	RestoreKnuxAnim();
}


void Load_HyperKnuxModels()
{
	if (charType == none)
		return;

	if (charType == Dreamcast)
	{
		HyperKnux_Model[root] = LoadBasicModel("HYPEKNUX_DC");
		HyperKnux_Model[curl] = LoadBasicModel("HYPECURL_DC");
		HyperKnux_Model[ball] = LoadBasicModel("HYPEBALL_DC");
		HyperKnux_Model[lw] = LoadBasicModel("HYPE_LW_DC");
		HyperKnux_Model[rw] = LoadBasicModel("HYPE_RW_DC");
	}
	else
	{
		HyperKnux_Model[root] = LoadBasicModel("HYPEKNUX_DX");
		HyperKnux_Model[curl] = LoadBasicModel("HYPECURL_DX");
		HyperKnux_Model[ball] = LoadBasicModel("HYPEBALL_DX");
		HyperKnux_Model[lw] = LoadBasicModel("HYPE_LW_DX");
		HyperKnux_Model[rw] = LoadBasicModel("HYPE_RW_DX");
	}

	//fighting gloves stuff
	HyperKnux_Model[5] = LoadBasicModel("16");
	HyperKnux_Model[6] = LoadBasicModel("17");
	HyperKnux_Model[7] = LoadBasicModel("18");
	HyperKnux_Model[8] = LoadBasicModel("20");
	HyperKnux_Model[9] = LoadBasicModel("21");
	HyperKnux_Model[10] = LoadBasicModel("22");
	//shovel claw stuff
	HyperKnux_Model[11] = LoadBasicModel("0");
	HyperKnux_Model[12] = LoadBasicModel("1");
	HyperKnux_Model[13] = LoadBasicModel("2");
	HyperKnux_Model[14] = LoadBasicModel("3");
	HyperKnux_Model[15] = LoadBasicModel("6");
}

void Free_HyperKnuxModels()
{
	for (uint8_t i = 0; i < LengthOfArray(HyperKnux_Model); i++) {
		FreeMDL(HyperKnux_Model[i]);
	}
}