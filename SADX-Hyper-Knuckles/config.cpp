#include "pch.h"

int CurrentSuperMusic = Random;
int CurrentSFX = SADX_SFX;
bool AnimationTransfo = true;
bool RemoveLimitations = false;
bool AlwaysHyperKnux = false;
bool superAura = true;
bool customPhysics = true;
uint8_t modelType = Dreamcast;
bool redAura = false;
std::string auraPVM = "HYPE_K_AURA";
Buttons TransformButton = Buttons_B;
bool lifeIcon = true;

static const Buttons ButtonsList[]
{
	Buttons_B,
	Buttons_Y,
	Buttons_X,
};

void ReadConfig(const char* path, const HelperFunctions& helperFunctions) {
	//Ini file Configuration
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	modelType = config->getInt("appearance", "charType", Dreamcast);
	superAura = config->getBool("appearance", "superAura", true);
	redAura = config->getBool("appearance", "redAura", false);
	lifeIcon = config->getBool("appearance", "lifeIcon", true);

	TransformButton = ButtonsList[config->getInt("General", "TransformButton", 0)];
	AnimationTransfo = config->getBool("General", "AnimationTransfo", true);
	RemoveLimitations = config->getBool("General", "RemoveLimitations", false);
	AlwaysHyperKnux = config->getBool("General", "AlwaysHyperKnux", false);

	customPhysics = config->getBool("General", "customPhysics", true);

	CurrentSuperMusic = config->getInt("Audio", "CurrentSuperMusic", Random);
	CurrentSFX = config->getInt("Audio", "GetVoice", SADX_SFX);
	delete config;

	if (redAura)
		auraPVM = "HYPE_K_AURA_RED";

	return;
}