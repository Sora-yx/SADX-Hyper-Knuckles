#include "pch.h"
#include "ScaleInfo.h"

FunctionHook<void> HudDisplayLife_t(HudDisplayRingTimeLife);

extern NJS_TEXLIST KnuxLifeIcon_Texlist;

static NJS_TEXANIM HYPERKNUX_EXTRA_TEXANIM = { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 0, 0x20 };
static NJS_SPRITE HYPERKNUX_EXTRA_SPRITE = { {0}, 1.0f, 1.0f, 0, &KnuxLifeIcon_Texlist, &HYPERKNUX_EXTRA_TEXANIM };

bool isInActionStage()
{
	return CurrentLevel < LevelIDs_StationSquare || CurrentLevel > LevelIDs_Past && CurrentLevel < LevelIDs_SSGarden;
}

void __cdecl DisplayHyperKnux_Icon()
{
	if (!lifeIcon || !playertwp[0] || playertwp[0]->counter.b[1] != Characters_Knuckles || !isHyperKnux[0] || !isInActionStage())
		return;

	HelperFunctionsGlobal.PushScaleUI(uiscale::Align_Automatic, false, 1.0f, 1.0f);
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);

	njSetTexture(&KnuxLifeIcon_Texlist);

	if (HideLives >= 0)
	{
		HYPERKNUX_EXTRA_SPRITE.p.x = 16.0f;

		if (isDCConversion() && !hudPlus)
			HYPERKNUX_EXTRA_SPRITE.p.y = VerticalStretch * 480.0f - 80.0f;
		else
			HYPERKNUX_EXTRA_SPRITE.p.y = VerticalStretch * 480.0f - 64.0f;

		njDrawSprite2D_ForcePriority(&HYPERKNUX_EXTRA_SPRITE, 0, -1.501, NJD_SPRITE_ALPHA);
		ClampGlobalColorThing_Thing();
	}

	HelperFunctionsGlobal.PopScaleUI();
}
