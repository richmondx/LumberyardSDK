#include "StdAfx.h"
#include "PlayFabSettings.h"

using namespace PlayFab;

const Aws::String PlayFabSettings::playFabSDKVersion = "0.0.160302";
const Aws::String PlayFabSettings::playFabVersionString = "LumberyardSDK-0.0.160302";

bool PlayFabSettings::useDevelopmentEnvironment = false;
Aws::String PlayFabSettings::serverURL;
Aws::String PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
Aws::String PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
Aws::String PlayFabSettings::titleId;
ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;
Aws::String PlayFabSettings::developerSecretKey;

