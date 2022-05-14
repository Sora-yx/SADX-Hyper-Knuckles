#include "pch.h"

Trampoline* KnuxGrabWall_Check_t = nullptr;
Trampoline* carSH_t = nullptr;
Trampoline* carSS_t = nullptr;

NJS_POINT3 Velo = { 5.0f, 5.0f, 5.0f };


bool isQuakeEnabled = false;

void DestroyCar(ObjectMaster* obj)
{
    EntityData1* data = obj->Data1;

    MID_EXPLOSION_INFO boom;

    boom.pPos = &data->Position;
    boom.flag = 3;
    boom.nLightStartTime = 0;
    boom.nLightEndTime = 0;
    boom.fLightLength = 0.0;
    boom.angLightSpd = 0;
    boom.nExpStartTime = 0;
    boom.nExpGrowEndTime = 20;
    boom.nExpEndTime = 40;
    boom.nExpTailTime = 60;
    boom.fExpMaxRadius = 25.0;
    egm2MiDexplosion(&boom);
    dsPlay_oneshot_Dolby(475, 0, 0, 64, 120, (taskwk*)data);
    data->Unknown = 30;
    data->Index++;

}

void ObjectCarSHRegular_r(ObjectMaster* obj)
{
    EntityData1* data = obj->Data1;
    int playerID = GetTheNearestPlayerNumber(&data->Position);

    if (isHyperKnux && IsPlayerInsideSphere(&data->Position, 100) && isQuakeEnabled)
    {
        if (data->Index == 0)
            DestroyCar(obj);
    }

    if (data->Index == 1)
    {
        egm2_car_broken_main_set(&data->Position);
        EraseDolbyCtrl(data);
        CheckThingButThenDeleteObject(obj);
        return;
    }
    else {

        ObjectFunc(origin, carSH_t->Target());
        origin(obj);
    }
}

void ObjectCarSS_r(ObjectMaster* obj)
{
    EntityData1* data = obj->Data1;
    int playerID = GetTheNearestPlayerNumber(&data->Position);

    if (data->Index > 1)
        data->Index = 0;

    if (isHyperKnux && IsPlayerInsideSphere(&data->Position, 100) && isQuakeEnabled)
    {
        if (data->Index == 0)
            DestroyCar(obj);
    }

    if (data->Index == 1)
    {
        egm2_car_broken_main_set(&data->Position);
        EraseDolbyCtrl(data);
        data->Index = 0;
        CheckThingButThenDeleteObject(obj);
        return;
    }
    else {

        ObjectFunc(origin, carSS_t->Target());
        origin(obj);
    }
}

CollisionData legCol = { 0, 1, 0x0, 0x0, 0x0, {0}, 0.0, 1.0, 0.0, 0.0, 0, 0, 0 };
//use bomb item to kill enemy, then smoke and egg walker shockwave for the effects
void CreateBombQuake(EntityData1* player, CharObj2* co2)
{
    isQuakeEnabled = true;
    stru_3C5AB24 = player->Position;
    bombRadius = 6.0f;
    PlayVoice(7003); //S3k SFX 
    RumbleA(player->CharIndex, 0);

    CreateSmoke(&player->Position, &Velo, 8.0f);
    ObjectMaster* shockwave = LoadObject(LoadObj_Data1, 6, Exe_leg_shock);
    shockwave->Data1->Position = player->Position;
    shockwave->Data1->Rotation = player->Rotation;
    shockwave->Data1->Position.y += 2.5f;
    Collision_Init(shockwave, &legCol, 1, 4u);
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


void KnuxGrabWallCheck_r(EntityData1* a1, CharObj2* a2)
{
    if (a2->Speed.x > 2.0f && isHyperKnux) {

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

void Knux_EarthQuake_InputCheck(EntityData1* data, CharObj2* co2)
{
    if (!data || data->Action != jump && data->Action != glide)
        return;

  
    if ( (Controllers[data->Index].HeldButtons & (Buttons_X | Buttons_B)) != 0 && (Controllers[data->Index].HeldButtons & TransformButton) == 0)
    {
        data->Action = 60;
        co2->AnimationThing.Index = 14;
        data->Status &= ~Status_Ball;
        co2->Speed.y -= 6.0f;
        return;
    }
}

void Knux_DoEarthQuakeGround(EntityData1* data, CharObj2* co2)
{
    if ( (isHyperKnux && data->Status & (Status_Ground | Status_OnColli)) != 0) {
    
        CreateBombQuake(data, co2);

        if (co2->SurfaceFlags & (ColFlags_Dig)) {

            if (isNewTricks()) {
                return;
            }
            else
            {
                co2->Speed.x = 0.0;
                co2->Speed.y = 0.0;
                co2->Speed.z = 0.0;
                data->Unknown = 0;
                data->Action = 19;
                co2->AnimationThing.Index = 41;
                PlaySound(1260, 0, 0, 0);
            }
        }
        else
        {
            data->Action = 61;
            co2->AnimationThing.Index = 20;
        }
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
    carSH_t = new Trampoline((int)0x611FC0, (int)0x611FC6, ObjectCarSHRegular_r);
    carSS_t = new Trampoline((int)0x633180, (int)0x633188, ObjectCarSS_r);

}