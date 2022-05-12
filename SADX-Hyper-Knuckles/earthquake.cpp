#include "pch.h"

Trampoline* KnuxGrabWall_Check_t = nullptr;

DataPointer(NJS_VECTOR, stru_3C5AB24, 0x3C5AB24);
DataPointer(float, bombRadius, 0x3C5A9D0);

NJS_POINT3 Velo = { 5, 5, 5 };

void CreateBombQuake(EntityData1* player, CharObj2* co2)
{
    stru_3C5AB24 = player->Position;
    CreateSmoke(&player->Position, &Velo, 10.0f);
    bombRadius = 6.0f;
}

static void Knux_GrabWallCheck_Origin(EntityData1* a1, CharObj2* a2)
{
    auto target = KnuxGrabWall_Check_t->Target();

    __asm
    {
        mov ecx, [a2]
        mov eax, [a1]
        call target
    }
}

bool isQuakeEnabled = false;
void KnuxGrabWallCheck_r(EntityData1* a1, CharObj2* a2)
{
    if (a2->Speed.x > 2.0f) {
        PlayVoice(7003);
        RumbleA(a1->CharIndex, 0);
        CreateBombQuake(a1, a2);
        isQuakeEnabled = true;
    }

    Knux_GrabWallCheck_Origin(a1, a2);
}

static void __declspec(naked) KnuxGrabWallCheckASM()
{
    __asm
    {
        push ecx // a2
        push eax // a1
        call KnuxGrabWallCheck_r
        pop eax // a1
        pop ecx // a2
        retn
    }
}

void init_KnuxEarthquake()
{
    KnuxGrabWall_Check_t = new Trampoline((int)0x4757E0, (int)0x4757E6, KnuxGrabWallCheckASM);
}