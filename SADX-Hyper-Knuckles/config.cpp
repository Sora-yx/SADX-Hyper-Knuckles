#include "pch.h"

int CurrentSuperMusic = Random;
int CurrentSFX = SADX_SFX;
bool AnimationTransfo = true;
bool RemoveLimitations = false;
bool AlwaysHyperKnux = false;
bool superAura = true;
bool customPhysics = true;
uint8_t charType = Dreamcast;

Buttons TransformButton = Buttons_B;

static const Buttons ButtonsList[]
{
	Buttons_B,
	Buttons_Y,
	Buttons_X,
};

void ReadConfig(const char* path, const HelperFunctions& helperFunctions) {
	//Ini file Configuration
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	charType = config->getInt("appearance", "charType", Dreamcast);
	superAura = config->getBool("appearance", "superAura", true);

	TransformButton = ButtonsList[config->getInt("General", "TransformButton", 0)];
	AnimationTransfo = config->getBool("General", "AnimationTransfo", true);
	RemoveLimitations = config->getBool("General", "RemoveLimitations", false);
	AlwaysHyperKnux = config->getBool("General", "AlwaysHyperKnux", false);

	customPhysics = config->getBool("General", "customPhysics", true);

	CurrentSuperMusic = config->getInt("Audio", "CurrentSuperMusic", Random);
	CurrentSFX = config->getInt("Audio", "GetVoice", SADX_SFX);
	delete config;
	return;
}