#pragma once

ModelInfo* LoadBasicModel(const char* name);

void LoadModelListFuncPtr(const char** names, int count, ModelInfo** mdls, ModelInfo* (*func)(const char*));

void FreeMDL(ModelInfo* pointer);

void LoadAnimation(AnimationFile** info, const char* name, const HelperFunctions& helperFunctions);

inline AnimationFile* LoadANM(const char* type, const char* name);

void LookAt(NJS_VECTOR* unit, Angle* outx, Angle* outy);
void LookAt(NJS_VECTOR* from, NJS_VECTOR* to, Angle* outx, Angle* outy);
void PlayerLookAt(NJS_VECTOR* from, NJS_VECTOR* to, Angle* outx, Angle* outy);
bool isKnuxAI(EntityData1* data1);

void njRotateX_(Angle x);
void njRotateY_(Angle y);
void njRotateZ_(Angle z);
void CamShakes();
bool isNewTricks();

int IsPlayerInSphere(NJS_VECTOR pos, float r);
bool isDCConversion();
bool isPerfectChasoLevel();
bool isKnucklesPlayer();