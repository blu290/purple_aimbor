#pragma once

#include <cstddef>

    namespace offsets {
        // Module: client.dll
        namespace client_dll {
            constexpr std::ptrdiff_t dwCSGOInput = 0x1A26B90;
            constexpr std::ptrdiff_t dwEntityList = 0x19BCC38;
            constexpr std::ptrdiff_t dwGameEntitySystem = 0x1ADBBB8;
            constexpr std::ptrdiff_t dwGameEntitySystem_getHighestEntityIndex = 0x1510;
            constexpr std::ptrdiff_t dwGameRules = 0x1A1A6A8;
            constexpr std::ptrdiff_t dwGlobalVars = 0x1816638;
            constexpr std::ptrdiff_t dwGlowManager = 0x1A19D90;
            constexpr std::ptrdiff_t dwLocalPlayerController = 0x1A0CA08;
            constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x18229F8;
            constexpr std::ptrdiff_t dwPlantedC4 = 0x1A23F00;
            constexpr std::ptrdiff_t dwPrediction = 0x18228B0;
            constexpr std::ptrdiff_t dwSensitivity = 0x1A1B378;
            constexpr std::ptrdiff_t dwSensitivity_sensitivity = 0x40;
            constexpr std::ptrdiff_t dwViewAngles = 0x1A2BFA8;
            constexpr std::ptrdiff_t dwViewMatrix = 0x1A1ED00;
            constexpr std::ptrdiff_t dwViewRender = 0x1A1F618;
            constexpr std::ptrdiff_t dwWeaponC4 = 0x19C0AC0;
        }
        // Module: engine2.dll
        namespace engine2_dll {
            constexpr std::ptrdiff_t dwEngineViewData = 0x5ECC3C;
            constexpr std::ptrdiff_t dwNetworkGameClient = 0x52EBA0;
            constexpr std::ptrdiff_t dwNetworkGameClient_clientTickCount = 0x178;
            constexpr std::ptrdiff_t dwNetworkGameClient_deltaTick = 0x278;
            constexpr std::ptrdiff_t dwNetworkGameClient_isBackgroundMap = 0x281477;
            constexpr std::ptrdiff_t dwNetworkGameClient_localPlayer = 0xF0;
            constexpr std::ptrdiff_t dwNetworkGameClient_maxClients = 0x270;
            constexpr std::ptrdiff_t dwNetworkGameClient_serverTickCount = 0x174;
            constexpr std::ptrdiff_t dwNetworkGameClient_signOnState = 0x260;
            constexpr std::ptrdiff_t dwSoundService = 0x5ECBA0;
            constexpr std::ptrdiff_t dwWindowHeight = 0x5F0454;
            constexpr std::ptrdiff_t dwWindowWidth = 0x5F0450;
        }
        // Module: inputsystem.dll
        namespace inputsystem_dll {
            constexpr std::ptrdiff_t dwInputSystem = 0x387F0;
        }
        // Module: matchmaking.dll
        namespace matchmaking_dll {
            constexpr std::ptrdiff_t dwGameTypes = 0x1A41C0;
            constexpr std::ptrdiff_t dwGameTypes_mapName = 0x1A42E0;
        }
        namespace entities {
            constexpr std::ptrdiff_t m_iTeamNum = 0x3C3; // uint8
            constexpr std::ptrdiff_t m_vecOrigin = 0x548; // Vector
            constexpr std::ptrdiff_t m_vecViewOffset = 0xC50; // CNetworkViewOffsetVector
            constexpr std::ptrdiff_t m_bDormant = 0xEF; // bool
            constexpr std::ptrdiff_t m_iHealth = 0x324; // int32
            constexpr std::ptrdiff_t m_matLocal = 0xED0; // matrix3x4_t
            constexpr std::ptrdiff_t m_iPlayerState = 0x12FC; // CSPlayerState
            constexpr std::ptrdiff_t m_hPlayerPawn = 0x7DC; // CHandle<C_CSPlayerPawn>
            constexpr std::ptrdiff_t m_pGameSceneNode = 0x308; // CGameSceneNode*
            constexpr std::ptrdiff_t m_modelState = 0x170; // CModelState
            constexpr std::ptrdiff_t m_vecAbsOrigin = 0xD0; // Vector
            constexpr std::ptrdiff_t m_vOldOrigin = 0x1274; // Vector
            constexpr std::ptrdiff_t m_aimPunchAngle = 0x14CC; // QAngle
            constexpr std::ptrdiff_t m_iShotsFired = 0x22A4; // int32
        }
    }   