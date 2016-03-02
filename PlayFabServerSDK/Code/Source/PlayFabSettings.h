#pragma once

#include "PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static const Aws::String playFabSDKVersion;
        static const Aws::String playFabVersionString;

        static bool useDevelopmentEnvironment;
        static Aws::String developmentEnvironmentURL;
        static Aws::String productionEnvironmentURL;
        static Aws::String titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static ErrorCallback globalErrorHandler;
        static Aws::String developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)

        static Aws::String getURL(const Aws::String& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://"+titleId+(useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }

    private:
        static Aws::String serverURL; // A cache of the constructed url string
    };
}
