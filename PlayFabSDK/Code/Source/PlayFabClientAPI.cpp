#include "StdAfx.h"
#include "PlayFabClientApi.h"
#include "PlayFabSettings.h"

using namespace PlayFab;
using namespace ClientModels;

// Client-Specific
Aws::String PlayFabClientApi::mUserSessionTicket;

bool PlayFabClientApi::IsClientLoggedIn()
{
    return mUserSessionTicket.length() != 0;
}

void PlayFabClientApi::MultiStepClientLogin(bool needsAttribution)
{
    if (needsAttribution && !PlayFabSettings::playFabSettings.disableAdvertising && PlayFabSettings::playFabSettings.advertisingIdType.length() > 0 && PlayFabSettings::playFabSettings.advertisingIdValue.length() > 0)
    {
        AttributeInstallRequest request;
        if (PlayFabSettings::playFabSettings.advertisingIdType == PlayFabSettings::playFabSettings.AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::playFabSettings.advertisingIdValue;
        else if (PlayFabSettings::playFabSettings.advertisingIdType == PlayFabSettings::playFabSettings.AD_TYPE_ANDROID_ID)
            request.Android_Id = PlayFabSettings::playFabSettings.advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}

// PlayFabClient Api
PlayFabClientApi::PlayFabClientApi() {}

void PlayFabClientApi::GetPhotonAuthenticationToken(
    GetPhotonAuthenticationTokenRequest& request,
    ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPhotonAuthenticationToken"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPhotonAuthenticationTokenResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPhotonAuthenticationTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPhotonAuthenticationTokenResult* outResult = new GetPhotonAuthenticationTokenResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPhotonAuthenticationTokenResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPhotonAuthenticationTokenResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithAndroidDeviceID(
    LoginWithAndroidDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithCustomID(
    LoginWithCustomIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithCustomID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithEmailAddress(
    LoginWithEmailAddressRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithEmailAddress"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithEmailAddressResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithEmailAddressResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithFacebook(
    LoginWithFacebookRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithFacebook"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithFacebookResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithFacebookResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithGameCenter(
    LoginWithGameCenterRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithGameCenter"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGameCenterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGameCenterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithGoogleAccount(
    LoginWithGoogleAccountRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithIOSDeviceID(
    LoginWithIOSDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithKongregate(
    LoginWithKongregateRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithKongregate"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithPlayFab(
    LoginWithPlayFabRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithPlayFab"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithPlayFabResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithPlayFabResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithSteam(
    LoginWithSteamRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LoginWithSteam"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithSteamResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithSteamResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RegisterPlayFabUser(
    RegisterPlayFabUserRequest& request,
    ProcessApiCallback<RegisterPlayFabUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::playFabSettings.titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings.titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RegisterPlayFabUser"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterPlayFabUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterPlayFabUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RegisterPlayFabUserResult* outResult = new RegisterPlayFabUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RegisterPlayFabUserResult> successCallback = reinterpret_cast<ProcessApiCallback<RegisterPlayFabUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddUsernamePassword(
    AddUsernamePasswordRequest& request,
    ProcessApiCallback<AddUsernamePasswordResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AddUsernamePassword"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUsernamePasswordResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUsernamePasswordResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AddUsernamePasswordResult* outResult = new AddUsernamePasswordResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AddUsernamePasswordResult> successCallback = reinterpret_cast<ProcessApiCallback<AddUsernamePasswordResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetAccountInfo(
    GetAccountInfoRequest& request,
    ProcessApiCallback<GetAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAccountInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetAccountInfoResult* outResult = new GetAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromFacebookIDsResult* outResult = new GetPlayFabIDsFromFacebookIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(
    GetPlayFabIDsFromGameCenterIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayFabIDsFromGameCenterIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGameCenterIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGameCenterIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromGameCenterIDsResult* outResult = new GetPlayFabIDsFromGameCenterIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(
    GetPlayFabIDsFromGoogleIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayFabIDsFromGoogleIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGoogleIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGoogleIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromGoogleIDsResult* outResult = new GetPlayFabIDsFromGoogleIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(
    GetPlayFabIDsFromKongregateIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayFabIDsFromKongregateIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromKongregateIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromKongregateIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromKongregateIDsResult* outResult = new GetPlayFabIDsFromKongregateIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromSteamIDs(
    GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromSteamIDsResult* outResult = new GetPlayFabIDsFromSteamIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserCombinedInfo(
    GetUserCombinedInfoRequest& request,
    ProcessApiCallback<GetUserCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserCombinedInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserCombinedInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserCombinedInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserCombinedInfoResult* outResult = new GetUserCombinedInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserCombinedInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserCombinedInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkAndroidDeviceID(
    LinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkAndroidDeviceIDResult* outResult = new LinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkCustomID(
    LinkCustomIDRequest& request,
    ProcessApiCallback<LinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkCustomIDResult* outResult = new LinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkFacebookAccount(
    LinkFacebookAccountRequest& request,
    ProcessApiCallback<LinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkFacebookAccountResult* outResult = new LinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkGameCenterAccount(
    LinkGameCenterAccountRequest& request,
    ProcessApiCallback<LinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkGameCenterAccountResult* outResult = new LinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkGoogleAccount(
    LinkGoogleAccountRequest& request,
    ProcessApiCallback<LinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkGoogleAccountResult* outResult = new LinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkIOSDeviceID(
    LinkIOSDeviceIDRequest& request,
    ProcessApiCallback<LinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkIOSDeviceIDResult* outResult = new LinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkKongregate(
    LinkKongregateAccountRequest& request,
    ProcessApiCallback<LinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkKongregateAccountResult* outResult = new LinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkSteamAccount(
    LinkSteamAccountRequest& request,
    ProcessApiCallback<LinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkSteamAccountResult* outResult = new LinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ReportPlayer(
    ReportPlayerClientRequest& request,
    ProcessApiCallback<ReportPlayerClientResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnReportPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ReportPlayerClientResult* outResult = new ReportPlayerClientResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ReportPlayerClientResult> successCallback = reinterpret_cast<ProcessApiCallback<ReportPlayerClientResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SendAccountRecoveryEmailResult* outResult = new SendAccountRecoveryEmailResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<SendAccountRecoveryEmailResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkAndroidDeviceID(
    UnlinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkAndroidDeviceIDResult* outResult = new UnlinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkCustomID(
    UnlinkCustomIDRequest& request,
    ProcessApiCallback<UnlinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkCustomIDResult* outResult = new UnlinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkFacebookAccount(

    ProcessApiCallback<UnlinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkFacebookAccountResult* outResult = new UnlinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkGameCenterAccount(

    ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkGameCenterAccountResult* outResult = new UnlinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkGoogleAccount(

    ProcessApiCallback<UnlinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkGoogleAccountResult* outResult = new UnlinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkIOSDeviceID(
    UnlinkIOSDeviceIDRequest& request,
    ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkIOSDeviceIDResult* outResult = new UnlinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkKongregate(

    ProcessApiCallback<UnlinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkKongregateAccountResult* outResult = new UnlinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkSteamAccount(

    ProcessApiCallback<UnlinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkSteamAccountResult* outResult = new UnlinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateUserTitleDisplayNameResult* outResult = new UpdateUserTitleDisplayNameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendLeaderboard(
    GetFriendLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetFriendLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardResult* outResult = new GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendLeaderboardAroundCurrentUser(
    GetFriendLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetFriendLeaderboardAroundCurrentUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundCurrentUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardAroundCurrentUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetFriendLeaderboardAroundCurrentUserResult* outResult = new GetFriendLeaderboardAroundCurrentUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendLeaderboardAroundPlayer(
    GetFriendLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetFriendLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetFriendLeaderboardAroundPlayerResult* outResult = new GetFriendLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboard(
    GetLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardResult* outResult = new GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardAroundCurrentUser(
    GetLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetLeaderboardAroundCurrentUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCurrentUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundCurrentUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardAroundCurrentUserResult* outResult = new GetLeaderboardAroundCurrentUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundCurrentUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundCurrentUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardAroundPlayer(
    GetLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardAroundPlayerResult* outResult = new GetLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerStatistics(
    GetPlayerStatisticsRequest& request,
    ProcessApiCallback<GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayerStatisticsResult* outResult = new GetPlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerStatisticVersions(
    GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayerStatisticVersionsResult* outResult = new GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserDataResult* outResult = new GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserDataResult* outResult = new GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserDataResult* outResult = new GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserDataResult* outResult = new GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserStatistics(

    ProcessApiCallback<GetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserStatisticsResult* outResult = new GetUserStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdatePlayerStatistics(
    UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdatePlayerStatisticsResult* outResult = new UpdatePlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdatePlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdatePlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateUserDataResult* outResult = new UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateUserDataResult* outResult = new UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserStatistics(
    UpdateUserStatisticsRequest& request,
    ProcessApiCallback<UpdateUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateUserStatisticsResult* outResult = new UpdateUserStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCatalogItemsResult* outResult = new GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPublisherDataResult* outResult = new GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetStoreItems(
    GetStoreItemsRequest& request,
    ProcessApiCallback<GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetStoreItemsResult* outResult = new GetStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetTitleDataResult* outResult = new GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTitleNews(
    GetTitleNewsRequest& request,
    ProcessApiCallback<GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetTitleNewsResult* outResult = new GetTitleNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetTitleNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetTitleNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyUserVirtualCurrencyResult* outResult = new ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ConfirmPurchase(
    ConfirmPurchaseRequest& request,
    ProcessApiCallback<ConfirmPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ConfirmPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConfirmPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnConfirmPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ConfirmPurchaseResult* outResult = new ConfirmPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ConfirmPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ConfirmPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ConsumeItem(
    ConsumeItemRequest& request,
    ProcessApiCallback<ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnConsumeItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ConsumeItemResult* outResult = new ConsumeItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ConsumeItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ConsumeItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    ProcessApiCallback<GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCharacterInventoryResult* outResult = new GetCharacterInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCharacterInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPurchase(
    GetPurchaseRequest& request,
    ProcessApiCallback<GetPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPurchaseResult* outResult = new GetPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserInventory(

    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserInventoryResult* outResult = new GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::PayForPurchase(
    PayForPurchaseRequest& request,
    ProcessApiCallback<PayForPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/PayForPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPayForPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnPayForPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        PayForPurchaseResult* outResult = new PayForPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<PayForPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<PayForPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::PurchaseItem(
    PurchaseItemRequest& request,
    ProcessApiCallback<PurchaseItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/PurchaseItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPurchaseItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnPurchaseItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        PurchaseItemResult* outResult = new PurchaseItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<PurchaseItemResult> successCallback = reinterpret_cast<ProcessApiCallback<PurchaseItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RedeemCoupon(
    RedeemCouponRequest& request,
    ProcessApiCallback<RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRedeemCouponResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RedeemCouponResult* outResult = new RedeemCouponResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RedeemCouponResult> successCallback = reinterpret_cast<ProcessApiCallback<RedeemCouponResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::StartPurchase(
    StartPurchaseRequest& request,
    ProcessApiCallback<StartPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/StartPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnStartPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        StartPurchaseResult* outResult = new StartPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<StartPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<StartPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyUserVirtualCurrencyResult* outResult = new ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlockContainerInstance(
    UnlockContainerInstanceRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlockContainerItemResult* outResult = new UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlockContainerItemResult* outResult = new UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddFriend(
    AddFriendRequest& request,
    ProcessApiCallback<AddFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AddFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddFriendResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAddFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AddFriendResult* outResult = new AddFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AddFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<AddFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendsList(
    GetFriendsListRequest& request,
    ProcessApiCallback<GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetFriendsList"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendsListResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendsListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetFriendsListResult* outResult = new GetFriendsListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetFriendsListResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendsListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RemoveFriend(
    RemoveFriendRequest& request,
    ProcessApiCallback<RemoveFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RemoveFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveFriendResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RemoveFriendResult* outResult = new RemoveFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RemoveFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SetFriendTags(
    SetFriendTagsRequest& request,
    ProcessApiCallback<SetFriendTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/SetFriendTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetFriendTagsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnSetFriendTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetFriendTagsResult* outResult = new SetFriendTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetFriendTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<SetFriendTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RegisterForIOSPushNotification(
    RegisterForIOSPushNotificationRequest& request,
    ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RegisterForIOSPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRegisterForIOSPushNotificationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterForIOSPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RegisterForIOSPushNotificationResult* outResult = new RegisterForIOSPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RegisterForIOSPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<RegisterForIOSPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RestoreIOSPurchases(
    RestoreIOSPurchasesRequest& request,
    ProcessApiCallback<RestoreIOSPurchasesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RestoreIOSPurchases"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRestoreIOSPurchasesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRestoreIOSPurchasesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RestoreIOSPurchasesResult* outResult = new RestoreIOSPurchasesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RestoreIOSPurchasesResult> successCallback = reinterpret_cast<ProcessApiCallback<RestoreIOSPurchasesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateIOSReceipt(
    ValidateIOSReceiptRequest& request,
    ProcessApiCallback<ValidateIOSReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ValidateIOSReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateIOSReceiptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateIOSReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ValidateIOSReceiptResult* outResult = new ValidateIOSReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ValidateIOSReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateIOSReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCurrentGames(
    CurrentGamesRequest& request,
    ProcessApiCallback<CurrentGamesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCurrentGames"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCurrentGamesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCurrentGamesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        CurrentGamesResult* outResult = new CurrentGamesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<CurrentGamesResult> successCallback = reinterpret_cast<ProcessApiCallback<CurrentGamesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetGameServerRegions(
    GameServerRegionsRequest& request,
    ProcessApiCallback<GameServerRegionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetGameServerRegions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetGameServerRegionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetGameServerRegionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GameServerRegionsResult* outResult = new GameServerRegionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GameServerRegionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GameServerRegionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::Matchmake(
    MatchmakeRequest& request,
    ProcessApiCallback<MatchmakeResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/Matchmake"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnMatchmakeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnMatchmakeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakeResult* outResult = new MatchmakeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakeResult> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        StartGameResult* outResult = new StartGameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<StartGameResult> successCallback = reinterpret_cast<ProcessApiCallback<StartGameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AndroidDevicePushNotificationRegistration(
    AndroidDevicePushNotificationRegistrationRequest& request,
    ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AndroidDevicePushNotificationRegistration"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAndroidDevicePushNotificationRegistrationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAndroidDevicePushNotificationRegistrationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AndroidDevicePushNotificationRegistrationResult* outResult = new AndroidDevicePushNotificationRegistrationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> successCallback = reinterpret_cast<ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateGooglePlayPurchase(
    ValidateGooglePlayPurchaseRequest& request,
    ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ValidateGooglePlayPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateGooglePlayPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateGooglePlayPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ValidateGooglePlayPurchaseResult* outResult = new ValidateGooglePlayPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ValidateGooglePlayPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateGooglePlayPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LogEvent(
    LogEventRequest& request,
    ProcessApiCallback<LogEventResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/LogEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLogEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnLogEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LogEventResult* outResult = new LogEventResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LogEventResult> successCallback = reinterpret_cast<ProcessApiCallback<LogEventResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WriteCharacterEvent(
    WriteClientCharacterEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/WriteCharacterEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteCharacterEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteCharacterEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        WriteEventResponse* outResult = new WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WritePlayerEvent(
    WriteClientPlayerEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/WritePlayerEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWritePlayerEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnWritePlayerEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        WriteEventResponse* outResult = new WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WriteTitleEvent(
    WriteTitleEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/WriteTitleEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteTitleEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteTitleEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        WriteEventResponse* outResult = new WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    ProcessApiCallback<AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAddSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AddSharedGroupMembersResult* outResult = new AddSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AddSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<AddSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    ProcessApiCallback<CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnCreateSharedGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        CreateSharedGroupResult* outResult = new CreateSharedGroupResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<CreateSharedGroupResult> successCallback = reinterpret_cast<ProcessApiCallback<CreateSharedGroupResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    ProcessApiCallback<GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetSharedGroupDataResult* outResult = new GetSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RemoveSharedGroupMembersResult* outResult = new RemoveSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RemoveSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateSharedGroupDataResult* outResult = new UpdateSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ExecuteCloudScript(
    ExecuteCloudScriptRequest& request,
    ProcessApiCallback<ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ExecuteCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnExecuteCloudScriptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnExecuteCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ExecuteCloudScriptResult* outResult = new ExecuteCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<ExecuteCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCloudScriptUrl(
    GetCloudScriptUrlRequest& request,
    ProcessApiCallback<GetCloudScriptUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCloudScriptUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCloudScriptUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCloudScriptUrlResult* outResult = new GetCloudScriptUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

if (outResult->Url.length() > 0) PlayFabSettings::playFabSettings.logicServerURL = outResult->Url;

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCloudScriptUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCloudScriptUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RunCloudScript(
    RunCloudScriptRequest& request,
    ProcessApiCallback<RunCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/RunCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRunCloudScriptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnRunCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RunCloudScriptResult* outResult = new RunCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RunCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<RunCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    ProcessApiCallback<GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetContentDownloadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetContentDownloadUrlResult* outResult = new GetContentDownloadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetContentDownloadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetContentDownloadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetAllUsersCharacters(
    ListUsersCharactersRequest& request,
    ProcessApiCallback<ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAllUsersCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ListUsersCharactersResult* outResult = new ListUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ListUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ListUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCharacterLeaderboardResult* outResult = new GetCharacterLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCharacterLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterStatistics(
    GetCharacterStatisticsRequest& request,
    ProcessApiCallback<GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCharacterStatisticsResult* outResult = new GetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardAroundCharacterResult* outResult = new GetLeaderboardAroundCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardForUsersCharactersResult* outResult = new GetLeaderboardForUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardForUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    ProcessApiCallback<GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGrantCharacterToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GrantCharacterToUserResult* outResult = new GrantCharacterToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GrantCharacterToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GrantCharacterToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateCharacterStatistics(
    UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateCharacterStatisticsResult* outResult = new UpdateCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCharacterDataResult* outResult = new GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCharacterDataResult* outResult = new GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateCharacterDataResult* outResult = new UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateAmazonIAPReceipt(
    ValidateAmazonReceiptRequest& request,
    ProcessApiCallback<ValidateAmazonReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/ValidateAmazonIAPReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateAmazonIAPReceiptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateAmazonIAPReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ValidateAmazonReceiptResult* outResult = new ValidateAmazonReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ValidateAmazonReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateAmazonReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AcceptTrade(
    AcceptTradeRequest& request,
    ProcessApiCallback<AcceptTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AcceptTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAcceptTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAcceptTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AcceptTradeResponse* outResult = new AcceptTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AcceptTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<AcceptTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::CancelTrade(
    CancelTradeRequest& request,
    ProcessApiCallback<CancelTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/CancelTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCancelTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnCancelTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        CancelTradeResponse* outResult = new CancelTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<CancelTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<CancelTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerTrades(
    GetPlayerTradesRequest& request,
    ProcessApiCallback<GetPlayerTradesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetPlayerTrades"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTradesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerTradesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayerTradesResponse* outResult = new GetPlayerTradesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayerTradesResponse> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerTradesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTradeStatus(
    GetTradeStatusRequest& request,
    ProcessApiCallback<GetTradeStatusResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/GetTradeStatus"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTradeStatusResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTradeStatusResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetTradeStatusResponse* outResult = new GetTradeStatusResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetTradeStatusResponse> successCallback = reinterpret_cast<ProcessApiCallback<GetTradeStatusResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::OpenTrade(
    OpenTradeRequest& request,
    ProcessApiCallback<OpenTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/OpenTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnOpenTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnOpenTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        OpenTradeResponse* outResult = new OpenTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<OpenTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<OpenTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AttributeInstall(
    AttributeInstallRequest& request,
    ProcessApiCallback<AttributeInstallResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Client/AttributeInstall"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAttributeInstallResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientApi::OnAttributeInstallResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AttributeInstallResult* outResult = new AttributeInstallResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::playFabSettings.advertisingIdType += "_Successful";

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<AttributeInstallResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

