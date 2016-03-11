#include "StdAfx.h"
#include "PlayFabSettings.h"

using namespace PlayFab;

PlayFabSettings PlayFabSettings::playFabSettings; // Global settings for all Apis

PlayFabSettings::PlayFabSettings() :
playFabSDKVersion("0.0.160302"),
playFabVersionString("LumberyardSDK-0.0.160302"),
useDevelopmentEnvironment(false),
developmentEnvironmentURL(".playfabsandbox.com"),
productionEnvironmentURL(".playfabapi.com"),
titleId(), // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
globalErrorHandler(nullptr),
developerSecretKey(), // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
serverURL()
{};
