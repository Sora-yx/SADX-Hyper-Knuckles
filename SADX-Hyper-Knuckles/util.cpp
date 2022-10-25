#include "pch.h"

ModelInfo* LoadBasicModel(const char* name) {
	PrintDebug("[Hyper Knux Mod] Loading basic model: %s... ", name);

	std::string modelFolder = "DX\\";

	if (modelType == Dreamcast)
		modelFolder = "DC\\";

	std::string fullPath = "system\\models\\" + modelFolder;
	fullPath = fullPath + name + ".sa1mdl";

	ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (mdl->getformat() != ModelFormat_Basic) {
		PrintDebug("Failed!\n");
		delete mdl;
		return nullptr;
	}

	PrintDebug("Done.\n");
	return mdl;
}

void LoadModelListFuncPtr(const char** names, int count, ModelInfo** mdls, ModelInfo* (*func)(const char*)) {
	for (int i = 0; i < count; ++i) {
		mdls[i] = func(names[i]);
	}
}

void FreeMDL(ModelInfo* pointer) {
	if (pointer) {
		PrintDebug("[Hyper Knux Mod] Freeing model: %s... \n", pointer->getdescription().c_str());
		delete(pointer);
		pointer = nullptr;
	}
}

// Animation file functions

void LoadAnimation(AnimationFile** info, const char* name, const HelperFunctions& helperFunctions) {
	std::string fullPath = "system\\anims\\";
	fullPath = fullPath + name + ".saanim";

	AnimationFile* anm = new AnimationFile(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (anm->getmodelcount() == 0) {
		delete anm;
		*info = nullptr;
	}
	else {
		*info = anm;
	}
};

inline AnimationFile* LoadANM(const char* type, const char* name) {
	std::string fullPath = "system\\";
	fullPath = fullPath + type + "\\" + name + ".saanim";

	AnimationFile* temp = new AnimationFile(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (temp->getmodelcount()) {
		PrintDebug("Done.\n");
		return temp;
	}
	else {
		PrintDebug("Failed.\n");
		delete temp;
		return nullptr;
	}
}

void LookAt(NJS_VECTOR* unit, Angle* outx, Angle* outy) {
	if (outy) {
		*outy = static_cast<Angle>(atan2f(unit->x, unit->z) * 65536.0f * 0.1591549762031479f);
	}

	if (outx) {
		Float len = 1.0f / squareroot(unit->z * unit->z + unit->x * unit->x + unit->y * unit->y);

		*outx = static_cast<Angle>((acos(len * 3.3499999f) * 65536.0f * 0.1591549762031479f)
			- (acos(-(len * unit->y)) * 65536.0f * 0.1591549762031479f));
	}
}

void LookAt(NJS_VECTOR* from, NJS_VECTOR* to, Angle* outx, Angle* outy) {
	if (!from || !to)
		return;

	NJS_VECTOR unit = *to;

	njSubVector(&unit, from);

	if (outy) {
		*outy = static_cast<Angle>(atan2f(unit.x, unit.z) * 65536.0f * 0.1591549762031479f);
	}

	if (outx) {
		if (from->y == to->y) {
			*outx = 0;
		}
		else {
			Float len = 1.0f / squareroot(unit.z * unit.z + unit.x * unit.x + unit.y * unit.y);

			*outx = static_cast<Angle>((acos(len * 3.3499999f) * 65536.0f * 0.1591549762031479f)
				- (acos(-(len * unit.y)) * 65536.0f * 0.1591549762031479f));
		}
	}
}

void PlayerLookAt(NJS_VECTOR* from, NJS_VECTOR* to, Angle* outx, Angle* outy) {
	LookAt(from, to, outx, outy);

	if (outy) {
		*outy = -(*outy) + 0x4000;
	}
}

bool isKnuxAI(EntityData1* data1) {
	if (TailsAI_ptr != nullptr && data1->CharIndex == 1 && data1->CharID == Characters_Knuckles)
		return true;

	return false;
}

bool isPlayerOnHyperForm(int player) {
	if (playerpwp[player] && playertwp[player] && playertwp[player]->counter.b[1] == Characters_Knuckles && playerpwp[player]->equipment & Upgrades_SuperSonic)
		return true;

	return false;
}

void njRotateX_(Angle x)
{
	if (x)
	{
		njRotateX(_nj_current_matrix_ptr_, x);
	}
}

void njRotateY_(Angle y)
{
	if (y)
	{
		njRotateY(_nj_current_matrix_ptr_, y);
	}
}

void njRotateZ_(Angle z)
{
	if (z)
	{
		njRotateZ(_nj_current_matrix_ptr_, z);
	}
}

int timerShake = 0;
int pass = 0;

void CamShakes()
{
	if (!isQuakeEnabled || !IsIngame() || !Camera_Data1)
		return;

	if (!timerShake) {
		Camera_Data1->Position.x += 2.0;
		pass++;
	}

	if (timerShake == 2) {
		Camera_Data1->Position.x -= 2.0;
		pass++;
	}

	if (pass > 12)
	{
		pass = 0;
		isQuakeEnabled = false;
		return;
	}

	if (timerShake > 6)
		timerShake = 0;
	else
		timerShake++;
}

bool isNewTricks()
{
	return GetModuleHandle(L"sadx-new-tricks") != NULL;
}

bool isDCConversion()
{
	return GetModuleHandle(L"DCMods_Main") != NULL;
}

float GetDistance(NJS_VECTOR* v1, NJS_VECTOR* v2)
{
	return sqrtf((v2->x - v1->x) * (v2->x - v1->x) +
		(v2->y - v1->y) * (v2->y - v1->y) +
		(v2->z - v1->z) * (v2->z - v1->z));
}

int IsPlayerInSphere(NJS_POINT3* p, float r)
{
	for (int i = 0; i < 8; ++i)
	{
		if (playertwp[i])
		{
			if (GetDistance(&playertwp[i]->pos, p) < r)
			{
				return i + 1;
			}
		}
	}

	return 0;
}

int IsPlayerInSphere(NJS_VECTOR pos, float r)
{
	return IsPlayerInSphere(&pos, r);
}

bool isPerfectChasoLevel()
{
	return CurrentLevel == LevelIDs_PerfectChaos && CurrentAct == 0;
}

bool isKnucklesPlayer()
{
	for (uint8_t i = 0; i < 8; i++)
	{
		if (EntityData1Ptrs[i] && EntityData1Ptrs[i]->CharID == Characters_Knuckles)
			return true;
	}

	return false;
}