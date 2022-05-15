#include "pch.h"

NJS_OBJECT* KnuxObjCopy[73];
NJS_OBJECT* KnuxAnimCopy[90];

void CopyKnuxOriginalModel()
{
	for (int i = 0; i < LengthOfArray(KnuxObjCopy); i++)
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
	KnuxObjCopy[23]->model = KNUCKLES_OBJECTS[23]->model;


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

void SetHyperKnuxModel()
{

	if (charType == none)
		return;

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

	KNUCKLES_OBJECTS[23]->model = KNUCKLES_OBJECTS[9]->model;
}


void SetHyperKnuxAnimModel()
{

	if (charType == none)
		return;

	NJS_OBJECT* Root = HyperKnux_Model[root]->getmodel();

	KNUCKLES_ACTIONS[0]->object = Root;
	KNUCKLES_ACTIONS[1]->object = Root;
	KNUCKLES_ACTIONS[2]->object = Root;
	KNUCKLES_ACTIONS[3]->object = Root;
	KNUCKLES_ACTIONS[4]->object = Root;
	KNUCKLES_ACTIONS[5]->object = Root;
	KNUCKLES_ACTIONS[6]->object = Root;
	KNUCKLES_ACTIONS[7]->object = Root;
	//8 is empty
	KNUCKLES_ACTIONS[9]->object = Root;
	KNUCKLES_ACTIONS[10]->object = Root;
	KNUCKLES_ACTIONS[11]->object = Root;
	KNUCKLES_ACTIONS[12]->object = Root;
	KNUCKLES_ACTIONS[13]->object = Root;
	KNUCKLES_ACTIONS[14]->object = Root;
	KNUCKLES_ACTIONS[15]->object = Root;
	KNUCKLES_ACTIONS[16]->object = Root;
	KNUCKLES_ACTIONS[17]->object = Root;
	KNUCKLES_ACTIONS[18]->object = Root;
	KNUCKLES_ACTIONS[19]->object = Root;
	KNUCKLES_ACTIONS[20]->object = Root;
	KNUCKLES_ACTIONS[21]->object = Root;
	KNUCKLES_ACTIONS[22]->object = Root;
	KNUCKLES_ACTIONS[23]->object = Root;
	KNUCKLES_ACTIONS[24]->object = Root;
	KNUCKLES_ACTIONS[25]->object = Root;
	KNUCKLES_ACTIONS[26]->object = Root;
	KNUCKLES_ACTIONS[27]->object = Root;
	KNUCKLES_ACTIONS[28]->object = Root;
	KNUCKLES_ACTIONS[29]->object = Root;
	KNUCKLES_ACTIONS[30]->object = Root;
	KNUCKLES_ACTIONS[31]->object = Root;
	KNUCKLES_ACTIONS[32]->object = Root;
	KNUCKLES_ACTIONS[33]->object = Root;
	KNUCKLES_ACTIONS[34]->object = Root;
	KNUCKLES_ACTIONS[35]->object = Root;
	KNUCKLES_ACTIONS[36]->object = Root;
	KNUCKLES_ACTIONS[37]->object = Root;
	KNUCKLES_ACTIONS[38]->object = Root;
	KNUCKLES_ACTIONS[39]->object = Root;
	KNUCKLES_ACTIONS[40]->object = Root;
	KNUCKLES_ACTIONS[41]->object = Root;
	KNUCKLES_ACTIONS[42]->object = Root;
	KNUCKLES_ACTIONS[43]->object = Root;
	KNUCKLES_ACTIONS[44]->object = Root;
	KNUCKLES_ACTIONS[45]->object = Root;
	KNUCKLES_ACTIONS[46]->object = Root;
	KNUCKLES_ACTIONS[47]->object = Root;
	KNUCKLES_ACTIONS[48]->object = Root;
	KNUCKLES_ACTIONS[49]->object = Root;
	KNUCKLES_ACTIONS[50]->object = Root;
	KNUCKLES_ACTIONS[51]->object = Root;
	KNUCKLES_ACTIONS[52]->object = Root;
	KNUCKLES_ACTIONS[53]->object = Root;
	KNUCKLES_ACTIONS[54]->object = Root;
	KNUCKLES_ACTIONS[55]->object = Root;
	KNUCKLES_ACTIONS[56]->object = Root;
	KNUCKLES_ACTIONS[58]->object = Root;
	KNUCKLES_ACTIONS[59]->object = Root;
	KNUCKLES_ACTIONS[60]->object = Root;

	KNUCKLES_ACTIONS[61]->object = HyperKnux_Model[curl]->getmodel();
	KNUCKLES_ACTIONS[62]->object = HyperKnux_Model[ball]->getmodel();

	KNUCKLES_ACTIONS[63]->object = Root;
	KNUCKLES_ACTIONS[64]->object = Root;
	KNUCKLES_ACTIONS[65]->object = Root;
	KNUCKLES_ACTIONS[66]->object = Root;
	KNUCKLES_ACTIONS[67]->object = Root;
	KNUCKLES_ACTIONS[68]->object = Root;
	KNUCKLES_ACTIONS[69]->object = Root;
	KNUCKLES_ACTIONS[70]->object = Root;
	KNUCKLES_ACTIONS[71]->object = Root;
	KNUCKLES_ACTIONS[72]->object = Root;
	KNUCKLES_ACTIONS[73]->object = Root;
	KNUCKLES_ACTIONS[74]->object = Root;
	KNUCKLES_ACTIONS[75]->object = Root;
	KNUCKLES_ACTIONS[76]->object = Root;
	KNUCKLES_ACTIONS[77]->object = Root;
	KNUCKLES_ACTIONS[78]->object = Root;
	KNUCKLES_ACTIONS[79]->object = Root;
	KNUCKLES_ACTIONS[80]->object = Root;
	KNUCKLES_ACTIONS[81]->object = Root;
	KNUCKLES_ACTIONS[82]->object = Root;
	KNUCKLES_ACTIONS[83]->object = Root;
	KNUCKLES_ACTIONS[84]->object = Root;
	KNUCKLES_ACTIONS[85]->object = Root;
	KNUCKLES_ACTIONS[86]->object = Root;
	KNUCKLES_ACTIONS[87]->object = Root;
	KNUCKLES_ACTIONS[88]->object = Root;
	KNUCKLES_ACTIONS[89]->object = Root;

	//SetHyperKnuxModel();

}

void RestoreKnuxAnimModel()
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

/**void __cdecl InitHyperKnucklesWeldInfo(int ID, ObjectMaster* character)
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
}*/


/**void init_Chrmodels()
{



	//KNUCKLES_OBJECTS[0] = HyperKnux_Model[root]->getmodel();

	KNUCKLES_OBJECTS[1] = KNUCKLES_OBJECTS[0];
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
	KNUCKLES_OBJECTS[22] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;


	//WriteJump(InitKnucklesWeldInfo, InitHyperKnucklesWeldInfo);


}*/