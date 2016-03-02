#include "StdAfx.h"
#include "PlayFabClientAPI.h"
#include "PlayFabSettings.h"
#include "PlayFabSdkGem.h"

using namespace PlayFab;

Aws::String PlayFabClientAPI::mUserSessionTicket; // Private, Client-Specific

PlayFabClientAPI::PlayFabClientAPI() {}

// "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey

void PlayFabClientAPI::AttributeInstall(
    ClientModels::AttributeInstallRequest& request,
    ProcessApiCallback<ClientModels::AttributeInstallResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AttributeInstall"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAttributeInstallResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAttributeInstallResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AttributeInstallResult* outResult = new ClientModels::AttributeInstallResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::advertisingIdType += "_Successful";

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AttributeInstallResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete request;
    }
}

void PlayFabClientAPI::LoginWithEmailAddress(
    ClientModels::LoginWithEmailAddressRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId.c_str();

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithEmailAddress"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithEmailAddressResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithEmailAddressResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete request;
    }
}

void PlayFabClientAPI::MultiStepClientLogin(bool needsAttribution)
{
    if (needsAttribution && !PlayFabSettings::disableAdvertising && PlayFabSettings::advertisingIdType.length() > 0 && PlayFabSettings::advertisingIdValue.length() > 0)
    {
        ClientModels::AttributeInstallRequest request;
        if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::advertisingIdValue;
        else if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_ANDROID_ID)
            request.Android_Id = PlayFabSettings::advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}

bool PlayFabClientAPI::IsClientLoggedIn()
{
    return mUserSessionTicket.length() != 0;
}
