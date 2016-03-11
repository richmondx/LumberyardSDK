#pragma once

#include "PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static PlayFabSettings playFabSettings; // Global settings for all Apis

        const Aws::String playFabSDKVersion;
        const Aws::String playFabVersionString;

        bool useDevelopmentEnvironment;
        Aws::String developmentEnvironmentURL;
        Aws::String productionEnvironmentURL;
        Aws::String titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        ErrorCallback globalErrorHandler;
        Aws::String developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)

        PlayFabSettings();

        Aws::String getURL(const Aws::String& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://"+titleId+(useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }

    private:
        Aws::String serverURL; // A cache of the constructed url string
    };
}
