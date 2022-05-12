#pragma once

void ReadConfig(const char* path, const HelperFunctions& helperFunctions);

extern HelperFunctions HelperFunctionsGlobal;


#define TARGET_DYNAMIC(name) ((decltype(name##_r)*)name##_t->Target())


enum HyperKnuxMusic {

	None,
	Sonic2,
	Sonic3,
	SonicAndKnuckles,
	SADX,
	SA2,
	Mania,
	Random
};

enum knuxAction {
	jump = 6,
	glide = 11
};

enum SoundEffect {

	SADX_SFX = 1,
	DBZ_SFX
};

extern bool isDCCharUsed;
extern int CurrentSuperMusic;
extern bool RemoveLimitations;
extern int CurrentSFX;
extern bool AnimationTransfo;
extern int ActualSong;
extern bool isHyperKnux;
extern bool AlwaysHyperKnux;
extern bool superAura;
extern bool customPhysics;
extern bool textureChanges;

extern Buttons TransformButton;


#pragma pack(push, 1)
struct ObjUnknownB
{
	int Time;
	int Index;
	int Mode;
	int field_C;
};
#pragma pack(pop)

void __cdecl Audio_Init(const HelperFunctions& helperFunctions);
void WaterHack_Init();
void __cdecl HyperKnux_Init(const char* path, const HelperFunctions& helperFunctions);
NJS_TEXLIST* getHyperKnuxTex();