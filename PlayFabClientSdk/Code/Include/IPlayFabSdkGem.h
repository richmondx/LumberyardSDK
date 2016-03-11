#pragma once

#include "IGem.h"
#include "StdAfx.h"
#include "PlayFabSettings.h"
#include "IPlayFabClientApi.h"

namespace PlayFab
{
    class IPlayFabSdkGem : public IGem
    {
        CRYINTERFACE_DECLARE(IPlayFabSdkGem, 0xcb5bfd1042a143b3, 0xa674e3649c8aca23);
    public:
        virtual int GetPendingCalls() = 0;
        virtual PlayFabSettings* GetPlayFabSettings() = 0;
        virtual IPlayFabClientApi* GetClientApi() = 0;
    };
} // namespace PlayFab
