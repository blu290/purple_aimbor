//cs2 wallhack nad aimbot
#include "memory.h"
#include "vector.h"
#include <iostream>
#include <chrono>
#include "offsets/offsets.hpp"
#include <thread>

constexpr Vector3 CalcAngle(
    const Vector3& localPosition,
    const Vector3& enemyPosition,
    const Vector3& viewAngles)  noexcept
{
    return ((enemyPosition - localPosition).ToAngle() - viewAngles);
};

//completely unrelated but xbox gamepass CGRG4-TYFV3-W4D2J-PQC7P-76J3Z
int main(void){
    // open a handle to CS2
    Memory process = Memory{"cs2.exe"};
    const std::uintptr_t client = process.GetModuleAddress("client.dll");
    const std::uintptr_t engine = process.GetModuleAddress("engine2.dll");
    const std::uintptr_t player = process.Read<std::uintptr_t>(offsets::client_dll::dwLocalPlayerPawn+client);
    const std::int32_t team = process.Read<std::int32_t>(player +0x3C3);
    Vector3 enemyHeadPosition;

    //aimbot fov

    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (!GetAsyncKeyState(VK_XBUTTON1)){
            continue;
        }
        //local player
        const std::uintptr_t player = process.Read<std::uintptr_t>(offsets::client_dll::dwLocalPlayerPawn+client);
        const std::int32_t team = process.Read<std::int32_t>(player + offsets::entities::m_iTeamnum);

        //eye position


        const Vector3 eyePosition = process.Read<Vector3>(player + offsets::entities::m_vOldOrigin)
        + process.Read<Vector3>(player + offsets::entities::m_vecViewOffset);

        //get client state and view angles
        const std::uintptr_t dwclient = process.Read<std::uintptr_t>(offsets::engine2_dll::dwNetworkGameClient + engine);
        const std::uintptr_t clientState = process.Read<std::uintptr_t>(dwclient + offsets::engine2_dll::dwNetworkGameClient_signOnState);
        const Vector3 viewAngles = process.Read<Vector3>(offsets::client_dll::dwViewAngles + client);
        const Vector3 aimPunch = process.Read<Vector3>(player +offsets::entities::m_aimPunchAngle);

        //print all the data
        //std::cout << "Eye Position: " << eyePosition.x << " " << eyePosition.y << " " << eyePosition.z << std::endl;
        //std::cout << "View Angles: " << viewAngles.x << " " << viewAngles.y << " " << viewAngles.z << std::endl;
        //std::cout << "Aim Punch: " << aimPunch.x << " " << aimPunch.y << " " << aimPunch.z << std::endl;

        auto bestFov = 110.f;
		auto bestAngle = Vector3{ };

        //aimbot
        const std::uintptr_t entityList = process.Read<std::uintptr_t>(client + offsets::client_dll::dwEntityList);
        const std::uintptr_t entityPtr = process.Read<std::uintptr_t>(entityList+0x10); 
        for (std::uint32_t i = 1; i <= 32;++i){

            const std::uintptr_t entityController = process.Read<std::uintptr_t>(entityPtr + 0x78 * (i & 0x1FF));
            if (!entityController){
                continue;
            }
            const std::uintptr_t entityControllerPawn = process.Read<std::uintptr_t>(entityController + offsets::entities::m_hPlayerPawn);
            const std::uintptr_t entityListPawn = process.Read<std::uintptr_t>(entityList + 0x8 * ((entityControllerPawn & 0x7FFF) >> 0x9) + 0x10);
            const std::uintptr_t p = process.Read<std::uintptr_t>(entityListPawn + 0x78 * (entityControllerPawn & 0x1FF));
            if (!p){
                continue;
            }
            //std::cout << "team :" << process.Read<std::int32_t>(p + offsets::entities::m_iTeamnum) << std::endl;
            //std::cout << "dormant :" << process.Read<bool>(p+offsets::entities::m_bDormant) << std::endl;
            //std::cout << "health :" << process.Read<std::int32_t>(p+offsets::entities::m_iHealth) << std::endl;

            if (process.Read<std::int32_t>(p + offsets::entities::m_iTeamnum) == team){
                continue;
            }

            if (process.Read<bool>(p+offsets::entities::m_bDormant)){
                continue;
            }

            if (!process.Read<std::int32_t>(p+offsets::entities::m_iHealth)){
                continue;
            }
            //not sure if this is correct
            const std::uintptr_t scene = process.Read<std::uintptr_t>(p + offsets::entities::m_pGameSceneNode);
            const std::uintptr_t bonearr = process.Read<std::uintptr_t>(scene + offsets::entities::m_modelState + 0x80);
            const Vector3 enemyHeadPosition = process.Read<Vector3>(bonearr + 6*0x20);
            //std::cout << "Enemy Head Position: " << enemyHeadPosition.x << " " << enemyHeadPosition.y << " " << enemyHeadPosition.z << std::endl;

            //this should be correct
            const Vector3 angle = CalcAngle(eyePosition, enemyHeadPosition, viewAngles + aimPunch*3);
            //std::cout << "Angle: " << angle.x << " " << angle.y << " " << angle.z << std::endl;
            const auto fov = std::hypot(angle.x, angle.y);

            if (fov < bestFov){
                bestFov = fov;
                bestAngle = angle;
            }
            //std::cout << "Enemy Head Position: " << enemyHeadPosition.x << " " << enemyHeadPosition.y << " " << enemyHeadPosition.z << std::endl;
            }
            if (!bestAngle.IsZero()){
                const auto angle = viewAngles + bestAngle;
                process.Write(offsets::client_dll::dwViewAngles + client, angle);
            }
        }
    return 0;
    
}
