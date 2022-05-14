#include "pch.h"

extern ModelInfo* HyperKnux_Model[5];
NJS_OBJECT* KnuxObjCopy[73];
NJS_ACTION* KnuxAnimCopy[115];

void __cdecl InitHyperKnucklesWeldInfo(int ID, ObjectMaster* character)
{
	NJS_OBJECT* Root = HyperKnux_Model[root]->getmodel();

	KnucklesWeldInfo[0].BaseModel = Root;
	KnucklesWeldInfo[0].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //2
	KnucklesWeldInfo[0].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //3
	KnucklesWeldInfo[0].anonymous_5 = 0;
	KnucklesWeldInfo[0].VertexBuffer = 0;
	KnucklesWeldInfo[0].VertexPairCount = 4;
	KnucklesWeldInfo[0].WeldType = 2;
	KnucklesWeldInfo[0].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[1].BaseModel = Root;
	KnucklesWeldInfo[1].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //3
	KnucklesWeldInfo[1].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling; //4 
	KnucklesWeldInfo[1].VertexPairCount = 4;
	KnucklesWeldInfo[1].WeldType = 2;
	KnucklesWeldInfo[1].anonymous_5 = 0;
	KnucklesWeldInfo[1].VertexBuffer = 0;
	KnucklesWeldInfo[1].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[2].BaseModel = Root;
	KnucklesWeldInfo[2].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //6
	KnucklesWeldInfo[2].VertIndexes = Knuckles_UpperArmIndices;
	KnucklesWeldInfo[2].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //7
	KnucklesWeldInfo[2].VertexPairCount = 4;
	KnucklesWeldInfo[2].WeldType = 2;
	KnucklesWeldInfo[2].anonymous_5 = 0;
	KnucklesWeldInfo[2].VertexBuffer = 0;
	KnucklesWeldInfo[3].BaseModel = Root;
	KnucklesWeldInfo[3].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;//7
	KnucklesWeldInfo[3].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling; //KNUCKLES_OBJECTS[8];
	KnucklesWeldInfo[3].VertexPairCount = 4;
	KnucklesWeldInfo[3].WeldType = 2;
	KnucklesWeldInfo[3].anonymous_5 = 0;
	KnucklesWeldInfo[3].VertexBuffer = 0;
	KnucklesWeldInfo[3].VertIndexes = Knuckles_LowerArmIndices;
	KnucklesWeldInfo[4].BaseModel = Root;
	KnucklesWeldInfo[4].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //10
	KnucklesWeldInfo[4].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;  //11
	KnucklesWeldInfo[4].VertexPairCount = 4;
	KnucklesWeldInfo[4].WeldType = 2;
	KnucklesWeldInfo[4].anonymous_5 = 0;
	KnucklesWeldInfo[4].VertexBuffer = 0;
	KnucklesWeldInfo[4].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[5].BaseModel = Root;
	KnucklesWeldInfo[5].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //11
	KnucklesWeldInfo[5].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;//12
	KnucklesWeldInfo[5].VertexPairCount = 4;
	KnucklesWeldInfo[5].WeldType = 2;
	KnucklesWeldInfo[5].anonymous_5 = 0;
	KnucklesWeldInfo[5].VertexBuffer = 0;
	KnucklesWeldInfo[5].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[6].BaseModel = Root;
	KnucklesWeldInfo[6].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //13
	KnucklesWeldInfo[6].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //14;
	KnucklesWeldInfo[6].VertexPairCount = 4;
	KnucklesWeldInfo[6].WeldType = 2;
	KnucklesWeldInfo[6].anonymous_5 = 0;
	KnucklesWeldInfo[6].VertexBuffer = 0;
	KnucklesWeldInfo[6].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[7].BaseModel = Root;
	KnucklesWeldInfo[7].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //14
	KnucklesWeldInfo[7].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling; //15
	KnucklesWeldInfo[7].VertexPairCount = 4;
	KnucklesWeldInfo[7].WeldType = 2;
	KnucklesWeldInfo[7].anonymous_5 = 0;
	KnucklesWeldInfo[7].VertexBuffer = 0;
	KnucklesWeldInfo[7].VertIndexes = (unsigned __int16*)&Knuckles_LegIndices;
	KnucklesWeldInfo[8].BaseModel = Root;
	KnucklesWeldInfo[8].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;//16
	KnucklesWeldInfo[8].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //17
	KnucklesWeldInfo[8].VertexPairCount = 9;
	KnucklesWeldInfo[8].WeldType = 2;
	KnucklesWeldInfo[8].anonymous_5 = 0;
	KnucklesWeldInfo[8].VertexBuffer = 0;
	KnucklesWeldInfo[8].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[9].BaseModel = Root;
	KnucklesWeldInfo[9].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling; //18

	KnucklesWeldInfo[9].VertIndexes = (unsigned __int16*)&Knuckles_ShoeIndices;
	KnucklesWeldInfo[9].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //19
	KnucklesWeldInfo[9].VertexPairCount = 9;
	KnucklesWeldInfo[9].WeldType = 2;
	KnucklesWeldInfo[9].anonymous_5 = 0;
	KnucklesWeldInfo[9].VertexBuffer = 0;
	KnucklesWeldInfo[10].BaseModel = Root;
	KnucklesWeldInfo[10].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling; //20
	KnucklesWeldInfo[10].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling; //5
	KnucklesWeldInfo[10].VertexPairCount = 8;
	KnucklesWeldInfo[10].WeldType = 2;
	KnucklesWeldInfo[10].anonymous_5 = 0;
	KnucklesWeldInfo[10].VertexBuffer = 0;
	KnucklesWeldInfo[10].VertIndexes = Knuckles_HandIndices;
	KnucklesWeldInfo[11].BaseModel = Root;
	KnucklesWeldInfo[11].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;//22
	KnucklesWeldInfo[11].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //9
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
	KnucklesWeldInfo[24].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling; //5
	KnucklesWeldInfo[24].ModelB = 0;
	KnucklesWeldInfo[24].VertexPairCount = 2;
	KnucklesWeldInfo[24].WeldType = 4;
	KnucklesWeldInfo[24].anonymous_5 = 0;
	KnucklesWeldInfo[24].VertexBuffer = 0;
	KnucklesWeldInfo[24].VertIndexes = 0;
	KnucklesWeldInfo[25].BaseModel = Root;
	KnucklesWeldInfo[25].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //9
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
	KnucklesWeldInfo[26].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //17
	KnucklesWeldInfo[26].WeldType = 6;
	KnucklesWeldInfo[27].BaseModel = Root;

	KnucklesWeldInfo[27].ModelB = 0;
	KnucklesWeldInfo[27].VertexPairCount = 0;
	KnucklesWeldInfo[27].anonymous_5 = 0;
	KnucklesWeldInfo[27].VertexBuffer = 0;
	KnucklesWeldInfo[27].VertIndexes = 0;
	KnucklesWeldInfo[27].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child; //19
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
	*(_DWORD*)&KnucklesWeldInfo[29].VertexPairCount = 0;
	KnucklesWeldInfo[29].VertexBuffer = 0;
	KnucklesWeldInfo[28].ModelA = Root->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling;
	KnucklesWeldInfo[28].WeldType = 8;
	KnucklesWeldInfo[29].VertIndexes = 0;

	//KNUCKLES_OBJECTS[0] = KnuxRootCopy;

	InitCharacterVars(ID, character);
}

void CopyKnuxOriginalModel()
{
	for (int i = 0; i < 23; i++)
	{
		KnuxObjCopy[i] = KNUCKLES_OBJECTS[i];
	}

	KnuxObjCopy[0]->model = KNUCKLES_OBJECTS[0]->model;
	KnuxObjCopy[1]->model = KNUCKLES_OBJECTS[1]->model;
	KnuxObjCopy[2]->model = KNUCKLES_OBJECTS[2]->model;
	KnuxObjCopy[3]->model = KNUCKLES_OBJECTS[3]->model;
	KnuxObjCopy[4]->model = KNUCKLES_OBJECTS[4]->model;
	KnuxObjCopy[5]->model = KNUCKLES_OBJECTS[5]->model;
	KnuxObjCopy[6]->model = KNUCKLES_OBJECTS[6]->model;
	KnuxObjCopy[7]->model = KNUCKLES_OBJECTS[7]->model;
	KnuxObjCopy[8]->model = KNUCKLES_OBJECTS[8]->model;
	KnuxObjCopy[9]->model = KNUCKLES_OBJECTS[9]->model;
	KnuxObjCopy[10]->model = KNUCKLES_OBJECTS[10]->model;
	KnuxObjCopy[11]->model = KNUCKLES_OBJECTS[11]->model;
	KnuxObjCopy[12]->model = KNUCKLES_OBJECTS[12]->model;
	KnuxObjCopy[13]->model = KNUCKLES_OBJECTS[13]->model;
	KnuxObjCopy[14]->model = KNUCKLES_OBJECTS[14]->model;
	KnuxObjCopy[15]->model = KNUCKLES_OBJECTS[15]->model;
	KnuxObjCopy[16]->model = KNUCKLES_OBJECTS[16]->model;

	KnuxObjCopy[17]->model = KNUCKLES_OBJECTS[17]->model;
	KnuxObjCopy[18]->model = KNUCKLES_OBJECTS[18]->model;
	KnuxObjCopy[19]->model = KNUCKLES_OBJECTS[19]->model;
	KnuxObjCopy[20]->model = KNUCKLES_OBJECTS[20]->model;
	KnuxObjCopy[21]->model = KNUCKLES_OBJECTS[21]->model;
	KnuxObjCopy[22]->model = KNUCKLES_OBJECTS[22]->model;
}

void RestoreKnuxOriginalModel()
{
	for (uint8_t i = 0; i < 23; i++)
	{
		if (KnuxObjCopy[i])
		{
			KNUCKLES_OBJECTS[i] = KnuxObjCopy[i];
		}
	}
}


void SetHyperKnuxModels()
{

	NJS_OBJECT* Root = HyperKnux_Model[root]->getmodel();

	KNUCKLES_OBJECTS[0]->model = Root->model;
	KNUCKLES_OBJECTS[1]->model = Root->model;
	KNUCKLES_OBJECTS[2]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling->model; //2
	KNUCKLES_OBJECTS[3]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->model; //3);	
	KNUCKLES_OBJECTS[4]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[5]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling->model;
	KNUCKLES_OBJECTS[6]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->model;
	KNUCKLES_OBJECTS[7]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[8]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[9]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->model;
	KNUCKLES_OBJECTS[10]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->model;
	KNUCKLES_OBJECTS[11]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[12]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[13]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling->model;
	KNUCKLES_OBJECTS[14]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[15]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->model;
	KNUCKLES_OBJECTS[16]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->model;

	KNUCKLES_OBJECTS[17]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->model;
	KNUCKLES_OBJECTS[18]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->model;
	KNUCKLES_OBJECTS[19]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->model;
	KNUCKLES_OBJECTS[20]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->model;
	KNUCKLES_OBJECTS[21]->model = KNUCKLES_OBJECTS[5]->model;
	KNUCKLES_OBJECTS[22]->model = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->model;
	KNUCKLES_OBJECTS[58]->model = KNUCKLES_OBJECTS[8]->model;

	KNUCKLES_ACTIONS[0]->object->child = Root->child;
}

void SetHyperKnuxAnimModel()
{
	CopyKnuxOriginalModel();
	SetHyperKnuxModels();
}

void RestoreKnuxAnimModel()
{

	RestoreKnuxOriginalModel();

	KNUCKLES_OBJECTS[0]->model = KnuxObjCopy[0]->model;
	KNUCKLES_OBJECTS[1]->model = KnuxObjCopy[1]->model;
	KNUCKLES_OBJECTS[2]->model = KnuxObjCopy[2]->model;
	KNUCKLES_OBJECTS[3]->model = KnuxObjCopy[3]->model;
	KNUCKLES_OBJECTS[4]->model = KnuxObjCopy[4]->model;
	KNUCKLES_OBJECTS[5]->model = KnuxObjCopy[5]->model;
	KNUCKLES_OBJECTS[6]->model = KnuxObjCopy[6]->model;
	KNUCKLES_OBJECTS[7]->model = KnuxObjCopy[7]->model;
	KNUCKLES_OBJECTS[8]->model = KnuxObjCopy[8]->model;
	KNUCKLES_OBJECTS[9]->model = KnuxObjCopy[9]->model;
	KNUCKLES_OBJECTS[10]->model = KnuxObjCopy[10]->model;
	KNUCKLES_OBJECTS[11]->model = KnuxObjCopy[11]->model;
	KNUCKLES_OBJECTS[12]->model = KnuxObjCopy[12]->model;
	KNUCKLES_OBJECTS[13]->model = KnuxObjCopy[13]->model;
	KNUCKLES_OBJECTS[14]->model = KnuxObjCopy[14]->model;
	KNUCKLES_OBJECTS[15]->model = KnuxObjCopy[15]->model;
	KNUCKLES_OBJECTS[16]->model = KnuxObjCopy[16]->model;

	KNUCKLES_OBJECTS[17]->model = KnuxObjCopy[17]->model;
	KNUCKLES_OBJECTS[18]->model = KnuxObjCopy[18]->model;
	KNUCKLES_OBJECTS[19]->model = KnuxObjCopy[19]->model;
	KNUCKLES_OBJECTS[20]->model = KnuxObjCopy[20]->model;
	KNUCKLES_OBJECTS[21]->model = KnuxObjCopy[21]->model;
	KNUCKLES_OBJECTS[22]->model = KnuxObjCopy[22]->model;


	KNUCKLES_ACTIONS[0]->object = KNUCKLES_OBJECTS[0];
	KNUCKLES_ACTIONS[0]->object->child = KNUCKLES_OBJECTS[0]->child;
}

void init_Chrmodels()
{



	//KNUCKLES_OBJECTS[0] = HyperKnux_Model[root]->getmodel();

	/**KNUCKLES_OBJECTS[1] = KNUCKLES_OBJECTS[0];
	KNUCKLES_OBJECTS[2] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //2
	KNUCKLES_OBJECTS[3] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //3);
	KNUCKLES_OBJECTS[4] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[5] = KNUCKLES_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KNUCKLES_OBJECTS[6] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[7] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[8] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[9] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[10] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[11] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[12] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[13] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KNUCKLES_OBJECTS[14] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KNUCKLES_OBJECTS[15] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[16] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;

	KNUCKLES_OBJECTS[17] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[18] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[19] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[20] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[21] = KNUCKLES_OBJECTS[5];
	KNUCKLES_OBJECTS[22] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;*/


	//WriteJump(InitKnucklesWeldInfo, InitHyperKnucklesWeldInfo);


}