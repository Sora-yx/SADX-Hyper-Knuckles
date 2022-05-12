#include "pch.h"

Trampoline* KnuxGrabWall_Check_t = nullptr;

DataPointer(NJS_VECTOR, stru_3C5AB24, 0x3C5AB24);
DataPointer(float, bombRadius, 0x3C5A9D0);
ObjectFunc(Exe_leg_shock, 0x576E00);

NJS_POINT3 Velo = { 5.0f, 5.0f, 5.0f };

void CreateBombQuake(EntityData1* player, CharObj2* co2)
{
    isQuakeEnabled = true;
    stru_3C5AB24 = player->Position;
    bombRadius = 6.0f;
    PlayVoice(7003);
    RumbleA(player->CharIndex, 0);

    CreateSmoke(&player->Position, &Velo, 8.0f);
    ObjectMaster* shockwave = LoadObject(LoadObj_Data1, 6, Exe_leg_shock);
    shockwave->Data1->Position = player->Position;
    shockwave->Data1->Rotation = player->Rotation;
    shockwave->Data1->Position.y += 2.5f;
    Collision_Init(shockwave, (CollisionData*)0x15EC4E0, 1, 4u);

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

        CreateBombQuake(a1, a2);
 
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


void Knux_EarthQuakeOnGroundCheck(EntityData1* data, CharObj2* co2)
{
    if (!data || data->Action != jump && data->Action != glide)
        return;

    if ( (Controllers[data->Index].HeldButtons & (Buttons_X | Buttons_B)) != 0)
    {
        data->Action = 60;
        data->Status &= ~Status_Ball;
        co2->Speed.y -= 7.0f;
        return;
    }
}

void Knux_DoEarthQuakeGround(EntityData1* data, CharObj2* co2)
{
    if ( (isHyperKnux && data->Status & (Status_Ground | Status_OnColli)) != 0)
    {
        data->Action = 1;
        co2->AnimationThing.Index = 20;
        CreateBombQuake(data, co2);
    }
}

int Knux_JumpCancel_r(CharObj2* a1, EntityData1* data)
{
 
    if ((AttackButtons & Controllers[data->CharIndex].PressedButtons) == 0 || isHyperKnux)
    {
        return 0;
    }

    data->Action = 9;
    a1->Speed.z = 0.0;
    a1->Speed.y = 0.0;
    a1->Speed.x = 0.0;
    a1->AnimationThing.Index = 19;
    a1->SpindashSpeed = 0.0;
    data->Status &= 0xFAu;
    return 1;
}

static void __declspec(naked) Knux_JumpCancel()
{
    __asm
    {
        push ecx 
        push eax 
        call Knux_JumpCancel_r
        add esp, 4 
        pop ecx 
        retn
    }
}

void init_KnuxEarthquake()
{
    KnuxGrabWall_Check_t = new Trampoline((int)0x4757E0, (int)0x4757E6, KnuxGrabWallCheckASM);
    WriteCall((void*)0x478721, Knux_JumpCancel); //prevent jump cancel to happen when using earthquake
}