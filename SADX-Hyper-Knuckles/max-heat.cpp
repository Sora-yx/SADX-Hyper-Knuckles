#include "pch.h"

void SetInstantMaxHeat(bool state)
{
	if (state) {
		WriteData<2>((int*)0x47210b, 0x90);
	}
	else
	{
		WriteData<1>((int*)0x47210b, 0x75);
		WriteData<1>((int*)0x47210c, 0x42);
	}
}

void InstantMaxHeat_InputCheck(EntityData1* data, CharObj2* co2)
{
	if (!isHyperKnux || ((co2->Upgrades & Upgrades_FightingGloves) == 0)
		|| ((WhistleButtons & Controllers[data->CharIndex].PressedButtons) == 0) || data->Action != jump && data->Action != glide && data->Action > glide)
	{
		return;
	}

	data->Status &= ~Status_Ball;
	PlaySound2(792, data, 1, 0);
	KnuEffectPutCharge0();
	StopSoundEffect(data);
	PlaySound(21, 0, 0, 0);
	co2->field_84 = 120;
	SetInstantMaxHeat(true);
}