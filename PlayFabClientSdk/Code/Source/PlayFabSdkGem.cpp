#include "StdAfx.h"

#include <FlowSystem/Nodes/FlowBaseNode.h>
#include <platform_impl.h> // Resharper says this is unused, but it's still required in some less direct way


#include "PlayFabHttp.h"
#include "PlayFabSdkGem.h"
#include "PlayFabClientApiWrapper.h"

using namespace PlayFab;

PlayFabSdkGem::PlayFabSdkGem() { }
PlayFabSdkGem::~PlayFabSdkGem() { }

void PlayFabSdkGem::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
    switch (event)
    {
    case ESYSTEM_EVENT_FLOW_SYSTEM_REGISTER_EXTERNAL_NODES:
        RegisterFlowNodes();
        break;

    case ESYSTEM_EVENT_GAME_POST_INIT:
        if (gEnv->pGame->GetIGameFramework())
            gEnv->pGame->GetIGameFramework()->RegisterListener(this, "PlayFabSdk Gem", FRAMEWORKLISTENERPRIORITY_HUD);
        break;

    case ESYSTEM_EVENT_FULL_SHUTDOWN:
    case ESYSTEM_EVENT_FAST_SHUTDOWN:
        // Put your shutdown code here
        // Other Gems may have been shutdown already, but none will have destructed
        break;
    }
}

void PlayFabSdkGem::OnPostUpdate(float fDeltaTime)
{
}

int PlayFabSdkGem::GetPendingCalls()
{
    return PlayFabRequestManager::playFabHttp.GetPendingCalls();
}

PlayFabSettings* PlayFabSdkGem::GetPlayFabSettings()
{
    return &PlayFabSettings::playFabSettings;
}

IPlayFabClientApi* PlayFabSdkGem::GetClientApi()
{
    return &PlayFabClientApiWrapper::globalWrapper;
}

GEM_REGISTER(PlayFabSdkGem)
