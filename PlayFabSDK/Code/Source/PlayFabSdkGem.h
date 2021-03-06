#pragma once

#include "IPlayFabSdkGem.h"
#include "IGameFramework.h"

namespace PlayFab
{
    class PlayFabSdkGem : public IPlayFabSdkGem, IGameFrameworkListener
    {
        GEM_IMPLEMENT_WITH_INTERFACE(PlayFabSdkGem, IPlayFabSdkGem, 0x6d932d60b2564e18, 0xa4cad0b6a4cbf5b8)

    public:
        void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;
        void OnPostUpdate(float fDeltaTime) override;

        int GetPendingCalls() override;
        PlayFabSettings* GetPlayFabSettings() override;
        IPlayFabAdminApi* GetAdminApi() override;
        IPlayFabMatchmakerApi* GetMatchmakerApi() override;
        IPlayFabServerApi* GetServerApi() override;
        IPlayFabClientApi* GetClientApi() override;
    };
} // namespace PlayFab
