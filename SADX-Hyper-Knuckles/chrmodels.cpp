#include "pch.h"

NJS_OBJECT* KnuxObjCopy[74];
NJS_OBJECT* KnuxAnimCopy[90];
WeldInfo KnuxWeld_r[60];
Trampoline* Knux_welds_t = nullptr;


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

void Backup_KnuxModelAnims()
{
	CopyKnuxOriginalModel();
	CopyKnuxOriginalAnims();
	return;
}

void __cdecl InitHyperKnucklesWelds();

void SetHyperKnuxModel()
{
	if (charType == none)
		return;


	NJS_OBJECT* Root = HyperKnux_Model[root]->getmodel();

	KNUCKLES_OBJECTS[0] = Root;
	KNUCKLES_OBJECTS[1] = Root;

	KNUCKLES_OBJECTS[2] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling; //2

	KNUCKLES_OBJECTS[3] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling; //3);
	KNUCKLES_OBJECTS[4] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[5] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
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


	/**KNUCKLES_OBJECTS[49] = Root->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling; //head

	KNUCKLES_OBJECTS[50] = KNUCKLES_OBJECTS[49];
	KNUCKLES_OBJECTS[51] = Root->child->child->sibling->sibling->sibling->sibling; //face root
	KNUCKLES_OBJECTS[52] = Root->child->child->sibling->sibling->sibling->sibling->child->child->sibling->child->child->sibling; //right eye
	KNUCKLES_OBJECTS[53] = Root->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->child->child->sibling; //left eye
	KNUCKLES_OBJECTS[54] = Root->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling; //Left eye root (17 in SAMDL)
	KNUCKLES_OBJECTS[55] = KNUCKLES_OBJECTS[50];
	KNUCKLES_OBJECTS[58] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[59] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[60] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KNUCKLES_OBJECTS[61] = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KNUCKLES_OBJECTS[62] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KNUCKLES_OBJECTS[63] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KNUCKLES_OBJECTS[64] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KNUCKLES_OBJECTS[65] = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;*/

}


void SetHyperKnuxAnim()
{
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
}

void SetHyperKnuxAnimModel()
{
	if (charType == none)
		return;

	SetHyperKnuxModel();
	SetHyperKnuxAnim();
}

void RestoreKnuxModels()
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
}

void RestoreKnuxAnimModel()
{
	RestoreKnuxModels();

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

void __cdecl InitHyperKnucklesWelds()
{

	NJS_OBJECT* Root = HyperKnux_Model[root]->getmodel();
	bool isDC = charType == Dreamcast;

	KnuxWeld_r[30].BaseModel = Root;
	KnuxWeld_r[30].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnuxWeld_r[30].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[30].anonymous_5 = 0;
	KnuxWeld_r[30].VertexBuffer = 0;

	KnuxWeld_r[30].VertexPairCount = 4;
	KnuxWeld_r[30].WeldType = 2;

	KnuxWeld_r[30].VertIndexes = isDC ? Knuckles_UpperArmIndices_DC : Knuckles_UpperArmIndices;

	KnuxWeld_r[31].BaseModel = Root;
	KnuxWeld_r[31].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[31].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnuxWeld_r[31].VertexPairCount = 4;
	KnuxWeld_r[31].WeldType = 2;
	KnuxWeld_r[31].anonymous_5 = 0;
	KnuxWeld_r[31].VertexBuffer = 0;
	KnuxWeld_r[31].VertIndexes = isDC ? Knuckles_LowerArmIndices_DC : Knuckles_LowerArmIndices;
	KnuxWeld_r[32].BaseModel = Root;
	KnuxWeld_r[32].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnuxWeld_r[32].VertIndexes = isDC ? Knuckles_UpperArmIndices_DC : Knuckles_UpperArmIndices;
	KnuxWeld_r[32].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[32].VertexPairCount = 4;
	KnuxWeld_r[32].WeldType = 2;
	KnuxWeld_r[32].anonymous_5 = 0;
	KnuxWeld_r[32].VertexBuffer = 0;
	KnuxWeld_r[33].BaseModel = Root;
	KnuxWeld_r[33].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[33].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnuxWeld_r[33].VertexPairCount = 4;
	KnuxWeld_r[33].WeldType = 2;
	KnuxWeld_r[33].anonymous_5 = 0;
	KnuxWeld_r[33].VertexBuffer = 0;
	KnuxWeld_r[33].VertIndexes = isDC ? Knuckles_LowerArmIndices_DC : Knuckles_LowerArmIndices;
	KnuxWeld_r[34].BaseModel = Root;
	KnuxWeld_r[34].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnuxWeld_r[34].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[34].VertexPairCount = 4;
	KnuxWeld_r[34].WeldType = 2;
	KnuxWeld_r[34].anonymous_5 = 0;
	KnuxWeld_r[34].VertexBuffer = 0;
	KnuxWeld_r[34].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned short*)&Knuckles_LegIndices;
	KnuxWeld_r[35].BaseModel = Root;
	KnuxWeld_r[35].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[35].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnuxWeld_r[35].WeldType = 2;
	KnuxWeld_r[35].anonymous_5 = 0;
	KnuxWeld_r[35].VertexBuffer = 0;
	KnuxWeld_r[35].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned short*)&Knuckles_LegIndices;
	KnuxWeld_r[36].BaseModel = Root;
	KnuxWeld_r[36].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->sibling;
	KnuxWeld_r[36].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[36].VertexPairCount = 4;
	KnuxWeld_r[36].WeldType = 2;
	KnuxWeld_r[36].anonymous_5 = 0;
	KnuxWeld_r[36].VertexBuffer = 0;
	KnuxWeld_r[36].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[37].BaseModel = Root;
	KnuxWeld_r[37].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->sibling;
	KnuxWeld_r[37].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling;
	KnuxWeld_r[37].VertexPairCount = 4;
	KnuxWeld_r[37].WeldType = 2;
	KnuxWeld_r[37].anonymous_5 = 0;
	KnuxWeld_r[37].VertexBuffer = 0;
	KnuxWeld_r[37].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[38].BaseModel = Root;
	KnuxWeld_r[38].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnuxWeld_r[38].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[38].VertexPairCount = 9;
	KnuxWeld_r[38].WeldType = 2;
	KnuxWeld_r[38].anonymous_5 = 0;
	KnuxWeld_r[38].VertexBuffer = 0;
	KnuxWeld_r[38].VertIndexes = isDC ? Knuckles_ShoeIndices_DC : (unsigned __int16*)&Knuckles_ShoeIndices;
	KnuxWeld_r[39].BaseModel = Root;
	KnuxWeld_r[39].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnuxWeld_r[39].VertIndexes = isDC ? Knuckles_ShoeIndices_DC : (unsigned __int16*)&Knuckles_ShoeIndices;
	KnuxWeld_r[39].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[39].VertexPairCount = 9;
	KnuxWeld_r[39].WeldType = 2;
	KnuxWeld_r[39].anonymous_5 = 0;
	KnuxWeld_r[39].VertexBuffer = 0;

	KnuxWeld_r[40].BaseModel = Root;
	KnuxWeld_r[40].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnuxWeld_r[40].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnuxWeld_r[40].VertexPairCount = 8;
	KnuxWeld_r[40].WeldType = 2;
	KnuxWeld_r[40].anonymous_5 = 0;
	KnuxWeld_r[40].VertexBuffer = 0;
	KnuxWeld_r[40].VertIndexes = isDC ? Knuckles_HandIndices_DC : Knuckles_HandIndices;
	KnuxWeld_r[41].BaseModel = Root;
	KnuxWeld_r[41].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling;
	KnuxWeld_r[41].ModelB = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[41].VertexPairCount = 8;
	KnuxWeld_r[41].WeldType = 2;
	KnuxWeld_r[41].anonymous_5 = 0;
	KnuxWeld_r[41].VertexBuffer = 0;
	KnuxWeld_r[41].VertIndexes = isDC ? Knuckles_HandIndices_DC : Knuckles_HandIndices;
	KnuxWeld_r[42].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[42].ModelA = KNUCKLES_OBJECTS[24];
	KnuxWeld_r[42].ModelB = KNUCKLES_OBJECTS[25];
	KnuxWeld_r[42].VertexPairCount = 4;
	KnuxWeld_r[42].WeldType = 2;
	KnuxWeld_r[42].anonymous_5 = 0;
	KnuxWeld_r[42].VertexBuffer = 0;
	KnuxWeld_r[42].VertIndexes = isDC ? Knuckles_UpperArmIndices_DC : Knuckles_UpperArmIndices;
	KnuxWeld_r[43].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[43].ModelA = KNUCKLES_OBJECTS[25];
	KnuxWeld_r[43].ModelB = KNUCKLES_OBJECTS[26];
	KnuxWeld_r[43].VertexPairCount = 4;
	KnuxWeld_r[43].WeldType = 2;
	KnuxWeld_r[43].anonymous_5 = 0;
	KnuxWeld_r[43].VertexBuffer = 0;
	KnuxWeld_r[43].VertIndexes = isDC ? Knuckles_LowerArmIndices_DC : Knuckles_LowerArmIndices;
	KnuxWeld_r[44].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[44].ModelA = KNUCKLES_OBJECTS[28];
	KnuxWeld_r[44].ModelB = KNUCKLES_OBJECTS[29];
	KnuxWeld_r[44].VertexPairCount = 4;
	KnuxWeld_r[44].WeldType = 2;
	KnuxWeld_r[44].anonymous_5 = 0;
	KnuxWeld_r[44].VertexBuffer = 0;
	KnuxWeld_r[44].VertIndexes = isDC ? Knuckles_UpperArmIndices_DC : Knuckles_UpperArmIndices;
	KnuxWeld_r[45].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[45].ModelA = KNUCKLES_OBJECTS[29];
	KnuxWeld_r[45].ModelB = KNUCKLES_OBJECTS[30];
	KnuxWeld_r[45].VertexPairCount = 4;
	KnuxWeld_r[45].WeldType = 2;
	KnuxWeld_r[45].anonymous_5 = 0;
	KnuxWeld_r[45].VertexBuffer = 0;
	KnuxWeld_r[45].VertIndexes = isDC ? Knuckles_LowerArmIndices_DC : Knuckles_LowerArmIndices;
	KnuxWeld_r[46].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[46].ModelA = KNUCKLES_OBJECTS[32];
	KnuxWeld_r[46].ModelB = KNUCKLES_OBJECTS[33];
	KnuxWeld_r[46].VertexPairCount = 4;
	KnuxWeld_r[46].WeldType = 2;
	KnuxWeld_r[46].anonymous_5 = 0;
	KnuxWeld_r[46].VertexBuffer = 0;
	KnuxWeld_r[46].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[47].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[47].ModelA = KNUCKLES_OBJECTS[33];
	KnuxWeld_r[47].ModelB = KNUCKLES_OBJECTS[34];
	KnuxWeld_r[47].VertexPairCount = 4;
	KnuxWeld_r[47].WeldType = 2;
	KnuxWeld_r[47].anonymous_5 = 0;
	KnuxWeld_r[47].VertexBuffer = 0;
	KnuxWeld_r[47].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[48].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[48].ModelA = KNUCKLES_OBJECTS[35];
	KnuxWeld_r[48].ModelB = KNUCKLES_OBJECTS[36];
	KnuxWeld_r[48].VertexPairCount = 4;
	KnuxWeld_r[48].WeldType = 2;
	KnuxWeld_r[48].anonymous_5 = 0;
	KnuxWeld_r[48].VertexBuffer = 0;
	KnuxWeld_r[48].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[49].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[49].ModelA = KNUCKLES_OBJECTS[36];
	KnuxWeld_r[49].VertIndexes = isDC ? Knuckles_LegIndices_DC : (unsigned __int16*)&Knuckles_LegIndices;
	KnuxWeld_r[49].ModelB = KNUCKLES_OBJECTS[37];
	KnuxWeld_r[49].VertexPairCount = 4;
	KnuxWeld_r[49].WeldType = 2;
	KnuxWeld_r[49].anonymous_5 = 0;
	KnuxWeld_r[49].VertexBuffer = 0;

	KnuxWeld_r[50].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[50].ModelA = KNUCKLES_OBJECTS[38];
	KnuxWeld_r[50].ModelB = KNUCKLES_OBJECTS[39];
	KnuxWeld_r[50].VertexPairCount = 9;
	KnuxWeld_r[50].WeldType = 2;
	KnuxWeld_r[50].anonymous_5 = 0;
	KnuxWeld_r[50].VertexBuffer = 0;
	KnuxWeld_r[50].VertIndexes = isDC ? Knuckles_ShoeIndices_DC : (unsigned __int16*)&Knuckles_ShoeIndices;
	KnuxWeld_r[51].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[51].ModelA = KNUCKLES_OBJECTS[40];
	KnuxWeld_r[51].ModelB = KNUCKLES_OBJECTS[41];
	KnuxWeld_r[51].VertexPairCount = 9;
	KnuxWeld_r[51].WeldType = 2;
	KnuxWeld_r[51].anonymous_5 = 0;
	KnuxWeld_r[51].VertexBuffer = 0;
	KnuxWeld_r[51].VertIndexes = isDC ? Knuckles_ShoeIndices_DC : (unsigned __int16*)&Knuckles_ShoeIndices;
	KnuxWeld_r[52].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[52].ModelA = KNUCKLES_OBJECTS[42];
	KnuxWeld_r[52].ModelB = KNUCKLES_OBJECTS[27];
	KnuxWeld_r[52].VertexPairCount = 8;
	KnuxWeld_r[52].WeldType = 2;
	KnuxWeld_r[52].anonymous_5 = 0;
	KnuxWeld_r[52].VertexBuffer = 0;
	KnuxWeld_r[52].VertIndexes = isDC ? Knuckles_HandIndices_DC : Knuckles_HandIndices;
	KnuxWeld_r[53].BaseModel = KNUCKLES_OBJECTS[1];
	KnuxWeld_r[53].ModelA = KNUCKLES_OBJECTS[44];
	KnuxWeld_r[53].ModelB = KNUCKLES_OBJECTS[31];
	KnuxWeld_r[53].VertexPairCount = 8;
	KnuxWeld_r[53].WeldType = 2;
	KnuxWeld_r[53].anonymous_5 = 0;
	KnuxWeld_r[53].VertexBuffer = 0;
	KnuxWeld_r[53].VertIndexes = isDC ? Knuckles_HandIndices_DC : Knuckles_HandIndices;
	KnuxWeld_r[54].BaseModel = Root;
	KnuxWeld_r[54].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child->sibling;
	KnuxWeld_r[54].ModelB = 0;
	KnuxWeld_r[54].VertexPairCount = 2;
	KnuxWeld_r[54].WeldType = 4;
	KnuxWeld_r[54].anonymous_5 = 0;
	KnuxWeld_r[54].VertexBuffer = 0;
	KnuxWeld_r[54].VertIndexes = 0;
	KnuxWeld_r[55].BaseModel = Root;
	KnuxWeld_r[55].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[55].ModelB = 0;
	KnuxWeld_r[55].VertexPairCount = 2;
	KnuxWeld_r[55].WeldType = 5;
	KnuxWeld_r[55].anonymous_5 = 0;
	KnuxWeld_r[55].VertexBuffer = 0;
	KnuxWeld_r[55].VertIndexes = 0;
	KnuxWeld_r[56].BaseModel = Root;
	KnuxWeld_r[56].ModelB = 0;
	KnuxWeld_r[56].VertexPairCount = 0;
	KnuxWeld_r[56].anonymous_5 = 0;
	KnuxWeld_r[56].VertexBuffer = 0;
	KnuxWeld_r[56].VertIndexes = 0;
	KnuxWeld_r[56].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[56].WeldType = 6;
	KnuxWeld_r[57].BaseModel = Root;
	KnuxWeld_r[57].ModelB = 0;
	KnuxWeld_r[57].VertexPairCount = 0;
	KnuxWeld_r[57].anonymous_5 = 0;
	KnuxWeld_r[57].VertexBuffer = 0;
	KnuxWeld_r[57].VertIndexes = 0;
	KnuxWeld_r[57].ModelA = Root->child->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->child->child->child->child->sibling->sibling->child;
	KnuxWeld_r[57].WeldType = 7;
	KnuxWeld_r[58].BaseModel = Root;
	KnuxWeld_r[58].ModelB = 0;
	KnuxWeld_r[58].VertexPairCount = 0;
	KnuxWeld_r[58].anonymous_5 = 0;
	KnuxWeld_r[58].VertexBuffer = 0;
	KnuxWeld_r[58].VertIndexes = 0;
	KnuxWeld_r[59].BaseModel = 0;
	KnuxWeld_r[59].ModelA = 0;
	KnuxWeld_r[59].ModelB = 0;
	KnuxWeld_r[59].VertexPairCount = 0;
	KnuxWeld_r[59].VertexBuffer = 0;
	KnuxWeld_r[58].ModelA = KNUCKLES_OBJECTS[54];
	KnuxWeld_r[58].WeldType = 8;
	KnuxWeld_r[59].VertIndexes = 0;
}

void __cdecl InitKnucklesWeldInfo_r(int ID, ObjectMaster* character)
{
	FunctionPointer(void, origin, (int ID, ObjectMaster * character), Knux_welds_t->Target());
	origin(ID, character);

	memcpy(KnuxWeld_r, KnucklesWeldInfo, sizeof(WeldInfo) * 30);
	InitHyperKnucklesWelds();
}


void init_WeldsHack()
{

	Knux_welds_t = new Trampoline((int)InitKnucklesWeldInfo, (int)InitKnucklesWeldInfo + 0x5, InitKnucklesWeldInfo_r);
	WriteData((WeldInfo**)0x47A89E, KnuxWeld_r);
}
