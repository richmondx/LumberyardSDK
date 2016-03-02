#pragma once

#include "PlayFabError.h"
#include "PlayFabHttp.h"
#include "PlayFabClientDataModels.h"

namespace PlayFab
{
    class PlayFabClientAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* customData);

        // Public, Client-Specific
        static void MultiStepClientLogin(bool needsAttribution);
        static bool IsClientLoggedIn();

        // ------------ Generated API calls
        static void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabClientAPI();

        // ------------ Generated result handlers
        static void OnLoginWithEmailAddressResult(PlayFabRequest* request);
        static void OnAttributeInstallResult(PlayFabRequest* request);

        // Private, Client-Specific
        static Aws::String mUserSessionTicket;
    };
};
