#include "pch.h"
#include "multiapi.h"

NJS_OBJECT* KnuxObjCopy[74] = { 0 };
NJS_OBJECT* KnuxAnimCopy[90] = { 0 };
NJS_MODEL_SADX* KnuxModelCopy[23] = { 0 };

//This whole page manage the character model swap in real time, it's a giant mess due to how the game works.
//Main idea is to backup everything on startup, swap models when transform, then restore everything when destransform.


void CopyKnuxOriginalModel()
{
	for (uint8_t i = 0; i < LengthOfArray(KnuxObjCopy); i++)
	{
		KnuxObjCopy[i] = KNUCKLES_OBJECTS[i];
	}

	//Also copy KNUCKLES_MODELS for upgrade stuff
	for (uint8_t i = 0; i < LengthOfArray(KnuxModelCopy); i++)
	{
		KnuxModelCopy[i] = KNUCKLES_MODELS[i];
	}
}

void RestoreKnuxModels(taskwk* data)
{
	for (uint8_t i = 0; i < LengthOfArray(KnuxObjCopy); i++)
	{
		KNUCKLES_OBJECTS[i] = KnuxObjCopy[i];
	}

	for (uint8_t i = 0; i < LengthOfArray(KnuxModelCopy); i++)
	{
		KNUCKLES_MODELS[i] = KnuxModelCopy[i];
	}

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

	if (modelType != Dreamcast)
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
	if (modelType == Dreamcast)
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

	if (modelType == Dreamcast)
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

void SetHyperKnuxModel()
{
	if (modelType == none || MultiModEnabled && multi_is_active())
		return;

	SetHyperKnuxModel_();
}

void CopyKnuxOriginalAnims()
{
	//anim obj

	for (uint8_t i = 0; i < LengthOfArray(KnuxAnimCopy); i++)
	{
		if (i == 8)
			continue;

		KnuxAnimCopy[i] = KNUCKLES_ACTIONS[i]->object;
	}
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
	if (modelType == none || MultiModEnabled && multi_is_active())
		return;

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

void SetHyperKnuxAnimModel()
{
	SetHyperKnuxModel();
	SetHyperKnuxAnim();
}

void Backup_KnuxModelAnims()
{
	if (modelType == none)
		return;

	if (!AlwaysHyperKnux) {
		CopyKnuxOriginalModel();
		CopyKnuxOriginalAnims();
	}
}

void RestoreKnuxAnimModel(taskwk* data)
{
	if (modelType == none || MultiModEnabled && multi_is_active())
		return;

	RestoreKnuxModels(data);
	RestoreKnuxAnim();
}

void Load_HyperKnuxModels()
{
	if (modelType == none)
		return;

	if (modelType == Dreamcast)
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