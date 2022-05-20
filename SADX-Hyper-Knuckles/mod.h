#pragma once

void ReadConfig(const char* path, const HelperFunctions& helperFunctions);

extern HelperFunctions HelperFunctionsGlobal;
extern std::string modpath;

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

enum ChangeType
{
	none,
	Dreamcast,
	DX,
};


extern int CurrentSuperMusic;
extern bool RemoveLimitations;
extern int CurrentSFX;
extern bool AnimationTransfo;
extern int ActualSong;
extern bool isHyperKnux;
extern bool AlwaysHyperKnux;
extern bool superAura;
extern bool customPhysics;
extern uint8_t charType;
extern bool isQuakeEnabled;
extern bool redAura;


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
void init_KnuxEarthquake();
void init_PhysicsHack();
void Free_HyperKnuxModels();
void init_AuraHack();

enum hyperKnuxModelE {
	root,
	curl,
	ball,
	lw, //upgrade stuff
	rw,
};

extern ModelInfo* HyperKnux_Model[11];
extern NJS_OBJECT* KnuxObjCopy[74];

void Backup_KnuxModelAnims();
void init_HudHack();