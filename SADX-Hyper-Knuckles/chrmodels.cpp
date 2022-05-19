#include "pch.h"

NJS_OBJECT* KnuxObjCopy[74];
NJS_OBJECT* KnuxAnimCopy[90];
WeldInfo BackupKnuxWeld_r[30];
NJS_MODEL_SADX* KnuxModelCopy[4];

//This whole page manage the character model and welds swap in real time, it's a giant mess due to how the game works.
//Main idea is to backup everything on startup, swap model and weld when transform, then restore everything when destransform.
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

void SaveWeldsInfo()
{
	memcpy(BackupKnuxWeld_r, KnucklesWeldInfo, sizeof(WeldInfo) * 30); //save current welds of the character
}

void __cdecl InitHyperKnucklesDC_WeldsInfo()
{
	NJS_OBJECT* v0;
	NJS_OBJECT* v1;
	NJS_OBJECT* v2;
	NJS_OBJECT* v3;
	NJS_OBJECT* v4;
	NJS_OBJECT* v5;
	KnucklesWeldInfo[0].BaseModel = HyperKnux_Model[root]->getmodel();
	NJS_OBJECT* Root = KnucklesWeldInfo[0].BaseModel;

	KnucklesWeldInfo[0].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[0].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[0].anonymous_5 = 0;
	KnucklesWeldInfo[0].VertexBuffer = 0;
	KnucklesWeldInfo[0].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo[0].WeldType = 2;
	KnucklesWeldInfo[0].VertIndexes = Knuckles_UpperArmIndices_DC;

	KnucklesWeldInfo[1].BaseModel = Root;
	KnucklesWeldInfo[1].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[1].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[1].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo[1].WeldType = 2;
	KnucklesWeldInfo[1].anonymous_5 = 0;
	KnucklesWeldInfo[1].VertexBuffer = 0;
	KnucklesWeldInfo[1].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo[2].BaseModel = Root;
	KnucklesWeldInfo[2].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	v0 = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[2].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo[2].ModelB = v0;
	KnucklesWeldInfo[2].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo[2].WeldType = 2;
	KnucklesWeldInfo[2].anonymous_5 = 0;
	KnucklesWeldInfo[2].VertexBuffer = 0;
	KnucklesWeldInfo[3].BaseModel = Root;
	KnucklesWeldInfo[3].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[3].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[3].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo[3].WeldType = 2;
	KnucklesWeldInfo[3].anonymous_5 = 0;
	KnucklesWeldInfo[3].VertexBuffer = 0;
	KnucklesWeldInfo[3].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo[4].BaseModel = Root;
	KnucklesWeldInfo[4].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[4].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[4].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[4].WeldType = 2;
	KnucklesWeldInfo[4].anonymous_5 = 0;
	KnucklesWeldInfo[4].VertexBuffer = 0;
	KnucklesWeldInfo[4].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[5].BaseModel = Root;
	KnucklesWeldInfo[5].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[5].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[5].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[5].WeldType = 2;
	KnucklesWeldInfo[5].anonymous_5 = 0;
	KnucklesWeldInfo[5].VertexBuffer = 0;
	KnucklesWeldInfo[5].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[6].BaseModel = Root;
	KnucklesWeldInfo[6].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[6].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[6].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[6].WeldType = 2;
	KnucklesWeldInfo[6].anonymous_5 = 0;
	KnucklesWeldInfo[6].VertexBuffer = 0;
	KnucklesWeldInfo[6].VertIndexes = Knuckles_LegIndices_DC;

	KnucklesWeldInfo[7].BaseModel = Root;
	KnucklesWeldInfo[7].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[7].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[7].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[7].WeldType = 2;
	KnucklesWeldInfo[7].anonymous_5 = 0;
	KnucklesWeldInfo[7].VertexBuffer = 0;
	KnucklesWeldInfo[7].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[8].BaseModel = Root;
	KnucklesWeldInfo[8].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[8].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[8].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo[8].WeldType = 2;
	KnucklesWeldInfo[8].anonymous_5 = 0;
	KnucklesWeldInfo[8].VertexBuffer = 0;
	KnucklesWeldInfo[8].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo[9].BaseModel = Root;
	KnucklesWeldInfo[9].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	v1 = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[9].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo[9].ModelB = v1;
	KnucklesWeldInfo[9].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo[9].WeldType = 2;
	KnucklesWeldInfo[9].anonymous_5 = 0;
	KnucklesWeldInfo[9].VertexBuffer = 0;

	//10 HAND RIGHT HIERARCHY IS DIFFERENT WITH DC MODEL
	KnucklesWeldInfo[10].BaseModel = Root;
	KnucklesWeldInfo[10].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[10].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[10].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo[10].WeldType = 2;
	KnucklesWeldInfo[10].anonymous_5 = 0;
	KnucklesWeldInfo[10].VertexBuffer = 0;
	KnucklesWeldInfo[10].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo[11].BaseModel = Root;
	KnucklesWeldInfo[11].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[11].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[11].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo[11].WeldType = 2;
	KnucklesWeldInfo[11].anonymous_5 = 0;
	KnucklesWeldInfo[11].VertexBuffer = 0;
	KnucklesWeldInfo[11].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo[12].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[12].ModelA = KNUCKLES_OBJECTS[24];
	KnucklesWeldInfo[12].ModelB = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo[12].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo[12].WeldType = 2;
	KnucklesWeldInfo[12].anonymous_5 = 0;
	KnucklesWeldInfo[12].VertexBuffer = 0;
	KnucklesWeldInfo[12].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo[13].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[13].ModelA = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo[13].ModelB = KNUCKLES_OBJECTS[26];
	KnucklesWeldInfo[13].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo[13].WeldType = 2;
	KnucklesWeldInfo[13].anonymous_5 = 0;
	KnucklesWeldInfo[13].VertexBuffer = 0;
	KnucklesWeldInfo[13].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo[14].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[14].ModelA = KNUCKLES_OBJECTS[28];
	KnucklesWeldInfo[14].ModelB = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo[14].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_UpperArmIndices_DC) / 2);
	KnucklesWeldInfo[14].WeldType = 2;
	KnucklesWeldInfo[14].anonymous_5 = 0;
	KnucklesWeldInfo[14].VertexBuffer = 0;
	KnucklesWeldInfo[14].VertIndexes = Knuckles_UpperArmIndices_DC;
	KnucklesWeldInfo[15].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[15].ModelA = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo[15].ModelB = KNUCKLES_OBJECTS[30];
	KnucklesWeldInfo[15].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LowerArmIndices_DC) / 2);
	KnucklesWeldInfo[15].WeldType = 2;
	KnucklesWeldInfo[15].anonymous_5 = 0;
	KnucklesWeldInfo[15].VertexBuffer = 0;
	KnucklesWeldInfo[15].VertIndexes = Knuckles_LowerArmIndices_DC;
	KnucklesWeldInfo[16].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[16].ModelA = KNUCKLES_OBJECTS[32];
	KnucklesWeldInfo[16].ModelB = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo[16].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[16].WeldType = 2;
	KnucklesWeldInfo[16].anonymous_5 = 0;
	KnucklesWeldInfo[16].VertexBuffer = 0;
	KnucklesWeldInfo[16].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[17].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[17].ModelA = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo[17].ModelB = KNUCKLES_OBJECTS[34];
	KnucklesWeldInfo[17].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[17].WeldType = 2;
	KnucklesWeldInfo[17].anonymous_5 = 0;
	KnucklesWeldInfo[17].VertexBuffer = 0;
	KnucklesWeldInfo[17].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[18].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[18].ModelA = KNUCKLES_OBJECTS[35];
	KnucklesWeldInfo[18].ModelB = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo[18].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[18].WeldType = 2;
	KnucklesWeldInfo[18].anonymous_5 = 0;
	KnucklesWeldInfo[18].VertexBuffer = 0;
	KnucklesWeldInfo[18].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[19].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[19].ModelA = KNUCKLES_OBJECTS[36];
	v2 = KNUCKLES_OBJECTS[37];
	KnucklesWeldInfo[19].VertIndexes = Knuckles_LegIndices_DC;
	KnucklesWeldInfo[19].ModelB = v2;
	KnucklesWeldInfo[19].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_LegIndices_DC) / 2);
	KnucklesWeldInfo[19].WeldType = 2;
	KnucklesWeldInfo[19].anonymous_5 = 0;
	KnucklesWeldInfo[19].VertexBuffer = 0;
	KnucklesWeldInfo[20].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[20].ModelA = KNUCKLES_OBJECTS[38];
	KnucklesWeldInfo[20].ModelB = KNUCKLES_OBJECTS[39];
	KnucklesWeldInfo[20].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo[20].WeldType = 2;
	KnucklesWeldInfo[20].anonymous_5 = 0;
	KnucklesWeldInfo[20].VertexBuffer = 0;
	KnucklesWeldInfo[20].VertIndexes = Knuckles_ShoeIndices_DC;
	KnucklesWeldInfo[21].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[21].ModelA = KNUCKLES_OBJECTS[40];
	KnucklesWeldInfo[21].ModelB = KNUCKLES_OBJECTS[41];
	KnucklesWeldInfo[21].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_ShoeIndices_DC) / 2);
	KnucklesWeldInfo[21].WeldType = 2;
	KnucklesWeldInfo[21].anonymous_5 = 0;
	KnucklesWeldInfo[21].VertexBuffer = 0;
	KnucklesWeldInfo[21].VertIndexes = Knuckles_ShoeIndices_DC;

	//22 RIGHT HAND  HIERARCHY IS DIFFERENT WITH DC MODEL
	KnucklesWeldInfo[22].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[22].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[22].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[22].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo[22].WeldType = 2;
	KnucklesWeldInfo[22].anonymous_5 = 0;
	KnucklesWeldInfo[22].VertexBuffer = 0;
	KnucklesWeldInfo[22].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo[23].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[23].ModelA = KNUCKLES_OBJECTS[44];
	KnucklesWeldInfo[23].ModelB = KNUCKLES_OBJECTS[31];
	KnucklesWeldInfo[23].VertexPairCount = (uint8_t)(LengthOfArray(Knuckles_HandIndices_DC) / 2);
	KnucklesWeldInfo[23].WeldType = 2;
	KnucklesWeldInfo[23].anonymous_5 = 0;
	KnucklesWeldInfo[23].VertexBuffer = 0;
	KnucklesWeldInfo[23].VertIndexes = Knuckles_HandIndices_DC;
	KnucklesWeldInfo[24].BaseModel = Root;
	KnucklesWeldInfo[24].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo[24].ModelB = 0;
	KnucklesWeldInfo[24].VertexPairCount = 2;
	KnucklesWeldInfo[24].WeldType = 4;
	KnucklesWeldInfo[24].anonymous_5 = 0;
	KnucklesWeldInfo[24].VertexBuffer = 0;
	KnucklesWeldInfo[24].VertIndexes = 0;
	KnucklesWeldInfo[25].BaseModel = Root;
	KnucklesWeldInfo[25].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[25].ModelB = 0;
	KnucklesWeldInfo[25].VertexPairCount = 2;
	KnucklesWeldInfo[25].WeldType = 5;
	KnucklesWeldInfo[25].anonymous_5 = 0;
	KnucklesWeldInfo[25].VertexBuffer = 0;
	KnucklesWeldInfo[25].VertIndexes = 0;
	KnucklesWeldInfo[26].BaseModel = Root;
	v3 = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[26].ModelB = 0;
	KnucklesWeldInfo[26].VertexPairCount = 0;
	KnucklesWeldInfo[26].anonymous_5 = 0;
	KnucklesWeldInfo[26].VertexBuffer = 0;
	KnucklesWeldInfo[26].VertIndexes = 0;
	KnucklesWeldInfo[26].ModelA = v3;
	KnucklesWeldInfo[26].WeldType = 6;
	KnucklesWeldInfo[27].BaseModel = Root;
	v4 = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[27].ModelB = 0;
	KnucklesWeldInfo[27].VertexPairCount = 0;
	KnucklesWeldInfo[27].anonymous_5 = 0;
	KnucklesWeldInfo[27].VertexBuffer = 0;
	KnucklesWeldInfo[27].VertIndexes = 0;
	KnucklesWeldInfo[27].ModelA = v4;
	KnucklesWeldInfo[27].WeldType = 7;
	KnucklesWeldInfo[28].BaseModel = Root;
	v5 = KNUCKLES_OBJECTS[54];
	KnucklesWeldInfo[28].ModelB = 0;
	KnucklesWeldInfo[28].VertexPairCount = 0;
	KnucklesWeldInfo[28].anonymous_5 = 0;
	KnucklesWeldInfo[28].VertexBuffer = 0;
	KnucklesWeldInfo[28].VertIndexes = 0;
	KnucklesWeldInfo[29].BaseModel = 0;
	KnucklesWeldInfo[29].ModelA = 0;
	KnucklesWeldInfo[29].ModelB = 0;
	KnucklesWeldInfo[29].VertexPairCount = 0;
	KnucklesWeldInfo[29].VertexBuffer = 0;
	KnucklesWeldInfo[28].ModelA = v5;
	KnucklesWeldInfo[28].WeldType = 8;
	KnucklesWeldInfo[29].VertIndexes = 0;
}


void __cdecl InitHyperKnucklesDX_WeldsInfo()
{
	KnucklesWeldInfo[0].BaseModel = HyperKnux_Model[root]->getmodel();

	NJS_OBJECT* Root = KnucklesWeldInfo[0].BaseModel;

	KnucklesWeldInfo[0].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[0].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[0].anonymous_5 = 0;
	KnucklesWeldInfo[0].VertexBuffer = 0;
	KnucklesWeldInfo[0].VertexPairCount = 4;
	KnucklesWeldInfo[0].WeldType = 2;
	KnucklesWeldInfo[0].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[1].BaseModel = Root;
	KnucklesWeldInfo[1].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[1].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[1].VertexPairCount = 4;
	KnucklesWeldInfo[1].WeldType = 2;
	KnucklesWeldInfo[1].anonymous_5 = 0;
	KnucklesWeldInfo[1].VertexBuffer = 0;
	KnucklesWeldInfo[1].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[2].BaseModel = Root;
	KnucklesWeldInfo[2].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[2].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[2].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[2].VertexPairCount = 4;
	KnucklesWeldInfo[2].WeldType = 2;
	KnucklesWeldInfo[2].anonymous_5 = 0;
	KnucklesWeldInfo[2].VertexBuffer = 0;
	KnucklesWeldInfo[3].BaseModel = Root;
	KnucklesWeldInfo[3].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[3].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[3].VertexPairCount = 4;
	KnucklesWeldInfo[3].WeldType = 2;
	KnucklesWeldInfo[3].anonymous_5 = 0;
	KnucklesWeldInfo[3].VertexBuffer = 0;
	KnucklesWeldInfo[3].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[4].BaseModel = Root;
	KnucklesWeldInfo[4].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[4].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[4].VertexPairCount = 4;
	KnucklesWeldInfo[4].WeldType = 2;
	KnucklesWeldInfo[4].anonymous_5 = 0;
	KnucklesWeldInfo[4].VertexBuffer = 0;
	KnucklesWeldInfo[4].VertIndexes = (unsigned short*)&Knuckles_LegIndices;
	KnucklesWeldInfo[5].BaseModel = Root;
	KnucklesWeldInfo[5].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[5].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[5].WeldType = 2;
	KnucklesWeldInfo[5].anonymous_5 = 0;
	KnucklesWeldInfo[5].VertexBuffer = 0;
	KnucklesWeldInfo[5].VertIndexes = (unsigned short*)&Knuckles_LegIndices;
	KnucklesWeldInfo[6].BaseModel = Root;
	KnucklesWeldInfo[6].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnucklesWeldInfo[6].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[6].VertexPairCount = 4;
	KnucklesWeldInfo[6].WeldType = 2;
	KnucklesWeldInfo[6].anonymous_5 = 0;
	KnucklesWeldInfo[6].VertexBuffer = 0;
	KnucklesWeldInfo[6].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[7].BaseModel = Root;
	KnucklesWeldInfo[7].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnucklesWeldInfo[7].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnucklesWeldInfo[7].VertexPairCount = 4;
	KnucklesWeldInfo[7].WeldType = 2;
	KnucklesWeldInfo[7].anonymous_5 = 0;
	KnucklesWeldInfo[7].VertexBuffer = 0;
	KnucklesWeldInfo[7].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[8].BaseModel = Root;
	KnucklesWeldInfo[8].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[8].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[8].VertexPairCount = 9;
	KnucklesWeldInfo[8].WeldType = 2;
	KnucklesWeldInfo[8].anonymous_5 = 0;
	KnucklesWeldInfo[8].VertexBuffer = 0;
	KnucklesWeldInfo[8].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[9].BaseModel = Root;
	KnucklesWeldInfo[9].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[9].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[9].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[9].VertexPairCount = 9;
	KnucklesWeldInfo[9].WeldType = 2;
	KnucklesWeldInfo[9].anonymous_5 = 0;
	KnucklesWeldInfo[9].VertexBuffer = 0;

	KnucklesWeldInfo[10].BaseModel = Root;
	KnucklesWeldInfo[10].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[10].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo[10].VertexPairCount = 8;
	KnucklesWeldInfo[10].WeldType = 2;
	KnucklesWeldInfo[10].anonymous_5 = 0;
	KnucklesWeldInfo[10].VertexBuffer = 0;
	KnucklesWeldInfo[10].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo[11].BaseModel = Root;
	KnucklesWeldInfo[11].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnucklesWeldInfo[11].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[11].VertexPairCount = 8;
	KnucklesWeldInfo[11].WeldType = 2;
	KnucklesWeldInfo[11].anonymous_5 = 0;
	KnucklesWeldInfo[11].VertexBuffer = 0;
	KnucklesWeldInfo[11].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo[12].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[12].ModelA = KNUCKLES_OBJECTS[24];
	KnucklesWeldInfo[12].ModelB = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo[12].VertexPairCount = 4;
	KnucklesWeldInfo[12].WeldType = 2;
	KnucklesWeldInfo[12].anonymous_5 = 0;
	KnucklesWeldInfo[12].VertexBuffer = 0;
	KnucklesWeldInfo[12].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[13].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[13].ModelA = KNUCKLES_OBJECTS[25];
	KnucklesWeldInfo[13].ModelB = KNUCKLES_OBJECTS[26];
	KnucklesWeldInfo[13].VertexPairCount = 4;
	KnucklesWeldInfo[13].WeldType = 2;
	KnucklesWeldInfo[13].anonymous_5 = 0;
	KnucklesWeldInfo[13].VertexBuffer = 0;
	KnucklesWeldInfo[13].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[14].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[14].ModelA = KNUCKLES_OBJECTS[28];
	KnucklesWeldInfo[14].ModelB = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo[14].VertexPairCount = 4;
	KnucklesWeldInfo[14].WeldType = 2;
	KnucklesWeldInfo[14].anonymous_5 = 0;
	KnucklesWeldInfo[14].VertexBuffer = 0;
	KnucklesWeldInfo[14].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[15].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[15].ModelA = KNUCKLES_OBJECTS[29];
	KnucklesWeldInfo[15].ModelB = KNUCKLES_OBJECTS[30];
	KnucklesWeldInfo[15].VertexPairCount = 4;
	KnucklesWeldInfo[15].WeldType = 2;
	KnucklesWeldInfo[15].anonymous_5 = 0;
	KnucklesWeldInfo[15].VertexBuffer = 0;
	KnucklesWeldInfo[15].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[16].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[16].ModelA = KNUCKLES_OBJECTS[32];
	KnucklesWeldInfo[16].ModelB = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo[16].VertexPairCount = 4;
	KnucklesWeldInfo[16].WeldType = 2;
	KnucklesWeldInfo[16].anonymous_5 = 0;
	KnucklesWeldInfo[16].VertexBuffer = 0;
	KnucklesWeldInfo[16].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[17].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[17].ModelA = KNUCKLES_OBJECTS[33];
	KnucklesWeldInfo[17].ModelB = KNUCKLES_OBJECTS[34];
	KnucklesWeldInfo[17].VertexPairCount = 4;
	KnucklesWeldInfo[17].WeldType = 2;
	KnucklesWeldInfo[17].anonymous_5 = 0;
	KnucklesWeldInfo[17].VertexBuffer = 0;
	KnucklesWeldInfo[17].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[18].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[18].ModelA = KNUCKLES_OBJECTS[35];
	KnucklesWeldInfo[18].ModelB = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo[18].VertexPairCount = 4;
	KnucklesWeldInfo[18].WeldType = 2;
	KnucklesWeldInfo[18].anonymous_5 = 0;
	KnucklesWeldInfo[18].VertexBuffer = 0;
	KnucklesWeldInfo[18].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[19].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[19].ModelA = KNUCKLES_OBJECTS[36];
	KnucklesWeldInfo[19].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[19].ModelB = KNUCKLES_OBJECTS[37];
	KnucklesWeldInfo[19].VertexPairCount = 4;
	KnucklesWeldInfo[19].WeldType = 2;
	KnucklesWeldInfo[19].anonymous_5 = 0;
	KnucklesWeldInfo[19].VertexBuffer = 0;

	KnucklesWeldInfo[20].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[20].ModelA = KNUCKLES_OBJECTS[38];
	KnucklesWeldInfo[20].ModelB = KNUCKLES_OBJECTS[39];
	KnucklesWeldInfo[20].VertexPairCount = 9;
	KnucklesWeldInfo[20].WeldType = 2;
	KnucklesWeldInfo[20].anonymous_5 = 0;
	KnucklesWeldInfo[20].VertexBuffer = 0;
	KnucklesWeldInfo[20].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[21].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[21].ModelA = KNUCKLES_OBJECTS[40];
	KnucklesWeldInfo[21].ModelB = KNUCKLES_OBJECTS[41];
	KnucklesWeldInfo[21].VertexPairCount = 9;
	KnucklesWeldInfo[21].WeldType = 2;
	KnucklesWeldInfo[21].anonymous_5 = 0;
	KnucklesWeldInfo[21].VertexBuffer = 0;
	KnucklesWeldInfo[21].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[22].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[22].ModelA = KNUCKLES_OBJECTS[42];
	KnucklesWeldInfo[22].ModelB = KNUCKLES_OBJECTS[27];
	KnucklesWeldInfo[22].VertexPairCount = 8;
	KnucklesWeldInfo[22].WeldType = 2;
	KnucklesWeldInfo[22].anonymous_5 = 0;
	KnucklesWeldInfo[22].VertexBuffer = 0;
	KnucklesWeldInfo[22].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo[23].BaseModel = KNUCKLES_OBJECTS[1];
	KnucklesWeldInfo[23].ModelA = KNUCKLES_OBJECTS[44];
	KnucklesWeldInfo[23].ModelB = KNUCKLES_OBJECTS[31];
	KnucklesWeldInfo[23].VertexPairCount = 8;
	KnucklesWeldInfo[23].WeldType = 2;
	KnucklesWeldInfo[23].anonymous_5 = 0;
	KnucklesWeldInfo[23].VertexBuffer = 0;
	KnucklesWeldInfo[23].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo[24].BaseModel = Root;
	KnucklesWeldInfo[24].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnucklesWeldInfo[24].ModelB = 0;
	KnucklesWeldInfo[24].VertexPairCount = 2;
	KnucklesWeldInfo[24].WeldType = 4;
	KnucklesWeldInfo[24].anonymous_5 = 0;
	KnucklesWeldInfo[24].VertexBuffer = 0;
	KnucklesWeldInfo[24].VertIndexes = 0;
	KnucklesWeldInfo[25].BaseModel = Root;
	KnucklesWeldInfo[25].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[25].ModelB = 0;
	KnucklesWeldInfo[25].VertexPairCount = 2;
	KnucklesWeldInfo[25].WeldType = 5;
	KnucklesWeldInfo[25].anonymous_5 = 0;
	KnucklesWeldInfo[25].VertexBuffer = 0;
	KnucklesWeldInfo[25].VertIndexes = 0;
	KnucklesWeldInfo[26].BaseModel = Root;
	KnucklesWeldInfo[26].ModelB = 0;
	KnucklesWeldInfo[26].VertexPairCount = 0;
	KnucklesWeldInfo[26].anonymous_5 = 0;
	KnucklesWeldInfo[26].VertexBuffer = 0;
	KnucklesWeldInfo[26].VertIndexes = 0;
	KnucklesWeldInfo[26].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[26].WeldType = 6;
	KnucklesWeldInfo[27].BaseModel = Root;
	KnucklesWeldInfo[27].ModelB = 0;
	KnucklesWeldInfo[27].VertexPairCount = 0;
	KnucklesWeldInfo[27].anonymous_5 = 0;
	KnucklesWeldInfo[27].VertexBuffer = 0;
	KnucklesWeldInfo[27].VertIndexes = 0;
	KnucklesWeldInfo[27].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnucklesWeldInfo[27].WeldType = 7;
	KnucklesWeldInfo[28].BaseModel = Root;
	KnucklesWeldInfo[28].ModelB = 0;
	KnucklesWeldInfo[28].VertexPairCount = 0;
	KnucklesWeldInfo[28].anonymous_5 = 0;
	KnucklesWeldInfo[28].VertexBuffer = 0;
	KnucklesWeldInfo[28].VertIndexes = 0;
	KnucklesWeldInfo[29].BaseModel = 0;
	KnucklesWeldInfo[29].ModelA = 0;
	KnucklesWeldInfo[29].ModelB = 0;
	KnucklesWeldInfo[29].VertexPairCount = 0;
	KnucklesWeldInfo[29].VertexBuffer = 0;
	KnucklesWeldInfo[28].ModelA = KNUCKLES_OBJECTS[54];
	KnucklesWeldInfo[28].WeldType = 8;
	KnucklesWeldInfo[29].VertIndexes = 0;
}

void DeleteKnucklesWeld(CharObj2* co2, EntityData1* data1, EntityData2* data2)
{
	co2->AnimationThing.field_2 = 2;
	ProcessVertexWelds(data1, data2, co2);
}

void InitKnucklesWelds(CharObj2* co2, EntityData1* data1, EntityData2* data2)
{
	co2->AnimationThing.field_2 = 0;
	ProcessVertexWelds(data1, data2, co2);
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

	//head and wrist upgrade stuff
	KnuxModelCopy[0] = KNUCKLES_MODELS[4];
	KnuxModelCopy[1] = KNUCKLES_MODELS[5];
	KnuxModelCopy[2] = KNUCKLES_MODELS[15];
	KnuxModelCopy[3] = KNUCKLES_MODELS[19];
}

void RestoreKnuxModels(EntityData1* data, CharObj2* co2, EntityData2* data2)
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

	KNUCKLES_MODELS[4] = KnuxModelCopy[0];
	KNUCKLES_MODELS[5] = KnuxModelCopy[1];
	KNUCKLES_MODELS[15] = KnuxModelCopy[2];
	KNUCKLES_MODELS[19] = KnuxModelCopy[3];

	DeleteKnucklesWeld(co2, data, data2);
	memcpy(KnucklesWeldInfo, BackupKnuxWeld_r, sizeof(WeldInfo) * 30);
	InitKnucklesWelds(co2, data, data2);
}


void SetHyperKnuxModel(EntityData1* data, CharObj2* co2, EntityData2* data2)
{
	if (charType == none)
		return;

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

	//upgrades stuff
	KNUCKLES_MODELS[4] = HyperKnux_Model[root]->getmodel()->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->basicdxmodel;
	KNUCKLES_MODELS[5] = KNUCKLES_MODELS[4];
	KNUCKLES_MODELS[15] = HyperKnux_Model[lw]->getmodel()->basicdxmodel;
	KNUCKLES_MODELS[19] = HyperKnux_Model[rw]->getmodel()->basicdxmodel;

	KNUCKLES_OBJECTS[58] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[59] = KNUCKLES_OBJECTS[22];
	KNUCKLES_OBJECTS[60] = KNUCKLES_OBJECTS[9];
	KNUCKLES_OBJECTS[61] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KNUCKLES_OBJECTS[62] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
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
	KNUCKLES_OBJECTS[70] = KNUCKLES_OBJECTS[62];
	KNUCKLES_OBJECTS[71] = KNUCKLES_OBJECTS[63];
	KNUCKLES_OBJECTS[72] = KNUCKLES_OBJECTS[64];
	KNUCKLES_OBJECTS[73] = KNUCKLES_OBJECTS[65];


	SaveWeldsInfo();
	DeleteKnucklesWeld(co2, data, data2);

	if (charType == Dreamcast)
		InitHyperKnucklesDC_WeldsInfo();
	else
		InitHyperKnucklesDX_WeldsInfo();

	InitKnucklesWelds(co2, data, data2);
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
	KNUCKLES_ACTIONS[0]->object = KnuxAnimCopy[0];
	KNUCKLES_ACTIONS[1]->object = KnuxAnimCopy[1];
	KNUCKLES_ACTIONS[2]->object = KnuxAnimCopy[2];
	KNUCKLES_ACTIONS[3]->object = KnuxAnimCopy[3];
	KNUCKLES_ACTIONS[4]->object = KnuxAnimCopy[4];
	KNUCKLES_ACTIONS[5]->object = KnuxAnimCopy[5];
	KNUCKLES_ACTIONS[6]->object = KnuxAnimCopy[6];
	KNUCKLES_ACTIONS[7]->object = KnuxAnimCopy[7];

	KNUCKLES_ACTIONS[9]->object = KnuxAnimCopy[9];
	KNUCKLES_ACTIONS[10]->object = KnuxAnimCopy[10];
	KNUCKLES_ACTIONS[11]->object = KnuxAnimCopy[11];
	KNUCKLES_ACTIONS[12]->object = KnuxAnimCopy[12];
	KNUCKLES_ACTIONS[13]->object = KnuxAnimCopy[13];
	KNUCKLES_ACTIONS[14]->object = KnuxAnimCopy[14];
	KNUCKLES_ACTIONS[15]->object = KnuxAnimCopy[15];
	KNUCKLES_ACTIONS[16]->object = KnuxAnimCopy[16];
	KNUCKLES_ACTIONS[17]->object = KnuxAnimCopy[17];
	KNUCKLES_ACTIONS[18]->object = KnuxAnimCopy[18];
	KNUCKLES_ACTIONS[19]->object = KnuxAnimCopy[19];
	KNUCKLES_ACTIONS[20]->object = KnuxAnimCopy[20];
	KNUCKLES_ACTIONS[21]->object = KnuxAnimCopy[21];
	KNUCKLES_ACTIONS[22]->object = KnuxAnimCopy[22];
	KNUCKLES_ACTIONS[23]->object = KnuxAnimCopy[23];
	KNUCKLES_ACTIONS[24]->object = KnuxAnimCopy[24];
	KNUCKLES_ACTIONS[25]->object = KnuxAnimCopy[25];
	KNUCKLES_ACTIONS[26]->object = KnuxAnimCopy[26];
	KNUCKLES_ACTIONS[27]->object = KnuxAnimCopy[27];
	KNUCKLES_ACTIONS[28]->object = KnuxAnimCopy[28];
	KNUCKLES_ACTIONS[29]->object = KnuxAnimCopy[29];
	KNUCKLES_ACTIONS[30]->object = KnuxAnimCopy[30];
	KNUCKLES_ACTIONS[31]->object = KnuxAnimCopy[31];
	KNUCKLES_ACTIONS[32]->object = KnuxAnimCopy[32];
	KNUCKLES_ACTIONS[33]->object = KnuxAnimCopy[33];
	KNUCKLES_ACTIONS[34]->object = KnuxAnimCopy[34];
	KNUCKLES_ACTIONS[35]->object = KnuxAnimCopy[35];
	KNUCKLES_ACTIONS[36]->object = KnuxAnimCopy[36];
	KNUCKLES_ACTIONS[37]->object = KnuxAnimCopy[37];
	KNUCKLES_ACTIONS[38]->object = KnuxAnimCopy[38];
	KNUCKLES_ACTIONS[39]->object = KnuxAnimCopy[39];
	KNUCKLES_ACTIONS[40]->object = KnuxAnimCopy[40];
	KNUCKLES_ACTIONS[41]->object = KnuxAnimCopy[41];
	KNUCKLES_ACTIONS[42]->object = KnuxAnimCopy[42];
	KNUCKLES_ACTIONS[43]->object = KnuxAnimCopy[43];
	KNUCKLES_ACTIONS[44]->object = KnuxAnimCopy[44];
	KNUCKLES_ACTIONS[45]->object = KnuxAnimCopy[45];
	KNUCKLES_ACTIONS[46]->object = KnuxAnimCopy[46];
	KNUCKLES_ACTIONS[47]->object = KnuxAnimCopy[47];
	KNUCKLES_ACTIONS[48]->object = KnuxAnimCopy[48];
	KNUCKLES_ACTIONS[49]->object = KnuxAnimCopy[49];
	KNUCKLES_ACTIONS[50]->object = KnuxAnimCopy[50];
	KNUCKLES_ACTIONS[51]->object = KnuxAnimCopy[51];
	KNUCKLES_ACTIONS[52]->object = KnuxAnimCopy[52];
	KNUCKLES_ACTIONS[53]->object = KnuxAnimCopy[53];
	KNUCKLES_ACTIONS[54]->object = KnuxAnimCopy[54];
	KNUCKLES_ACTIONS[55]->object = KnuxAnimCopy[55];
	KNUCKLES_ACTIONS[56]->object = KnuxAnimCopy[56];
	KNUCKLES_ACTIONS[57]->object = KnuxAnimCopy[57];
	KNUCKLES_ACTIONS[58]->object = KnuxAnimCopy[58];
	KNUCKLES_ACTIONS[59]->object = KnuxAnimCopy[59];
	KNUCKLES_ACTIONS[60]->object = KnuxAnimCopy[60];

	KNUCKLES_ACTIONS[61]->object = KnuxAnimCopy[61];
	KNUCKLES_ACTIONS[62]->object = KnuxAnimCopy[62];
	KNUCKLES_ACTIONS[63]->object = KnuxAnimCopy[63];
	KNUCKLES_ACTIONS[64]->object = KnuxAnimCopy[64];
	KNUCKLES_ACTIONS[65]->object = KnuxAnimCopy[65];
	KNUCKLES_ACTIONS[66]->object = KnuxAnimCopy[66];
	KNUCKLES_ACTIONS[67]->object = KnuxAnimCopy[67];
	KNUCKLES_ACTIONS[68]->object = KnuxAnimCopy[68];
	KNUCKLES_ACTIONS[69]->object = KnuxAnimCopy[69];
	KNUCKLES_ACTIONS[70]->object = KnuxAnimCopy[70];
	KNUCKLES_ACTIONS[71]->object = KnuxAnimCopy[71];
	KNUCKLES_ACTIONS[72]->object = KnuxAnimCopy[72];
	KNUCKLES_ACTIONS[73]->object = KnuxAnimCopy[73];
	KNUCKLES_ACTIONS[74]->object = KnuxAnimCopy[74];
	KNUCKLES_ACTIONS[75]->object = KnuxAnimCopy[75];
	KNUCKLES_ACTIONS[76]->object = KnuxAnimCopy[76];
	KNUCKLES_ACTIONS[77]->object = KnuxAnimCopy[77];
	KNUCKLES_ACTIONS[78]->object = KnuxAnimCopy[78];
	KNUCKLES_ACTIONS[79]->object = KnuxAnimCopy[79];
	KNUCKLES_ACTIONS[80]->object = KnuxAnimCopy[80];
	KNUCKLES_ACTIONS[81]->object = KnuxAnimCopy[81];
	KNUCKLES_ACTIONS[82]->object = KnuxAnimCopy[82];
	KNUCKLES_ACTIONS[83]->object = KnuxAnimCopy[83];
	KNUCKLES_ACTIONS[84]->object = KnuxAnimCopy[84];
	KNUCKLES_ACTIONS[85]->object = KnuxAnimCopy[85];
	KNUCKLES_ACTIONS[86]->object = KnuxAnimCopy[86];
	KNUCKLES_ACTIONS[87]->object = KnuxAnimCopy[87];
	KNUCKLES_ACTIONS[88]->object = KnuxAnimCopy[88];
	KNUCKLES_ACTIONS[89]->object = KnuxAnimCopy[89];
}

void SetHyperKnuxAnim()
{
	KNUCKLES_ACTIONS[0]->object = HyperKnux_Model[root]->getmodel();
	KNUCKLES_ACTIONS[1]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[2]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[3]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[4]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[5]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[6]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[7]->object = KNUCKLES_ACTIONS[0]->object;
	//8 is empty
	KNUCKLES_ACTIONS[9]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[10]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[11]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[12]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[13]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[14]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[15]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[16]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[17]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[18]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[19]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[20]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[21]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[22]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[23]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[24]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[25]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[26]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[27]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[28]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[29]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[30]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[31]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[32]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[33]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[34]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[35]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[36]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[37]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[38]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[39]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[40]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[41]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[42]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[43]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[44]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[45]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[46]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[47]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[48]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[49]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[50]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[51]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[52]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[53]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[54]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[55]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[56]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[57]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[58]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[59]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[60]->object = KNUCKLES_ACTIONS[0]->object;

	KNUCKLES_ACTIONS[61]->object = HyperKnux_Model[curl]->getmodel();
	KNUCKLES_ACTIONS[62]->object = HyperKnux_Model[ball]->getmodel();

	KNUCKLES_ACTIONS[63]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[64]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[65]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[66]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[67]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[68]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[69]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[70]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[71]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[72]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[73]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[74]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[75]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[76]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[77]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[78]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[79]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[80]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[81]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[82]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[83]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[84]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[85]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[86]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[87]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[88]->object = KNUCKLES_ACTIONS[0]->object;
	KNUCKLES_ACTIONS[89]->object = KNUCKLES_ACTIONS[0]->object;
}

void SetHyperKnuxAnimModel(EntityData1* data, CharObj2* co2, EntityData2* data2)
{
	if (charType == none)
		return;

	SetHyperKnuxModel(data, co2, data2);
	SetHyperKnuxAnim();
}

void Backup_KnuxModelAnims()
{
	if (charType == none)
		return;

	CopyKnuxOriginalModel();
	CopyKnuxOriginalAnims();

	return;
}


void RestoreKnuxAnimModel(EntityData1* data, CharObj2* co2, EntityData2* data2)
{
	if (charType == none)
		return;

	RestoreKnuxModels(data, co2, data2);
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
}

void Free_HyperKnuxModels()
{
	for (uint8_t i = 0; i < LengthOfArray(HyperKnux_Model); i++) {
		FreeMDL(HyperKnux_Model[i]);
	}
}