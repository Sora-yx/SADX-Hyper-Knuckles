#include "pch.h"

int CurrentSuperMusic = Random;
int CurrentSFX = SADX_SFX;
bool AnimationTransfo = true;
bool RemoveLimitations = false;
bool AlwaysHyperKnux = false;
bool superAura = true;
bool customPhysics = true;
bool textureChanges = true;
bool modelChanges = true;

Buttons TransformButton = Buttons_Y;

static const Buttons ButtonsList[]
{
	Buttons_B,
	Buttons_Y,
	Buttons_X,
};

void ReadConfig(const char* path, const HelperFunctions& helperFunctions) {
	//Ini file Configuration
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	textureChanges = config->getBool("General", "textureChanges", true);
	modelChanges = config->getBool("General", "modelChanges", true);
	TransformButton = ButtonsList[config->getInt("General", "TransformButton", 1)];
	AnimationTransfo = config->getBool("General", "AnimationTransfo", true);
	RemoveLimitations = config->getBool("General", "RemoveLimitations", false);
	AlwaysHyperKnux = config->getBool("General", "AlwaysSuperMiles", false);
	superAura = config->getBool("General", "superAura", true);
	customPhysics = config->getBool("General", "customPhysics", true);

	CurrentSuperMusic = config->getInt("Audio", "CurrentSuperMusic", Random);
	CurrentSFX = config->getInt("Audio", "GetVoice", SADX_SFX);
	delete config;
	return;
}