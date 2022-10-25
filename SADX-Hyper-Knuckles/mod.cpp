#include "pch.h"

HelperFunctions HelperFunctionsGlobal;
std::string modpath;

bool MultiModEnabled = false;

extern "C" {
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		if (helperFunctions.Version < 11)
		{
			MessageBox(WindowHandle,
				L"Error, your version of the mod loader does not support API version 11. Some functionality will not be available.\nPlease exit the game and update the mod loader for the best experience.",
				L"Hyper Knuckles: Mod Loader out of date", MB_OK | MB_ICONERROR);
		}

		HelperFunctionsGlobal = helperFunctions; // Save the helper pointer for external use

		modpath = path;

		ReadConfig(path, helperFunctions);
		HyperKnux_Init(path, helperFunctions);
		Audio_Init(helperFunctions);
		init_PhysicsHack();
		WaterHack_Init();
		init_KnuxEarthquake();
		init_AuraHack();
		init_HudHack();
		init_Jiggle_EyeTracker();

		MultiModEnabled = GetModuleHandle(L"sadx-multiplayer") != nullptr;
	}

	__declspec(dllexport) void __cdecl OnInitEnd()
	{
		Backup_KnuxModelAnims();
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		CamShakes();
	}

	__declspec(dllexport) void __cdecl OnExit()
	{
		Free_HyperKnuxModels();
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}