#include "StdAfx.h"
#include "PlayFabClientAPI.h"
#include "PlayFabSettings.h"
#include "PlayFabSdkGem.h"

using namespace PlayFab;
using namespace PlayFab::ClientModels;

// Client-Specific
Aws::String PlayFabClientAPI::mUserSessionTicket;

bool PlayFabClientAPI::IsClientLoggedIn()
{
    return mUserSessionTicket.length() != 0;
}

void PlayFabClientAPI::MultiStepClientLogin(bool needsAttribution)
{
    if (needsAttribution && !PlayFabSettings::disableAdvertising && PlayFabSettings::advertisingIdType.length() > 0 && PlayFabSettings::advertisingIdValue.length() > 0)
    {
        AttributeInstallRequest request;
        if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::advertisingIdValue;
        else if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_ANDROID_ID)
            request.Android_Id = PlayFabSettings::advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}

// PlayFabClient API
PlayFabClientAPI::PlayFabClientAPI() {}

void PlayFabClientAPI::GetPhotonAuthenticationToken(
    GetPhotonAuthenticationTokenRequest& request,
    ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPhotonAuthenticationToken"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPhotonAuthenticationTokenResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LoginWithAndroidDeviceID(
    LoginWithAndroidDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithCustomID(
    LoginWithCustomIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithCustomID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithEmailAddress(
    LoginWithEmailAddressRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithEmailAddress"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithEmailAddressResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithEmailAddressResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithFacebook(
    LoginWithFacebookRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithFacebook"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithFacebookResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithFacebookResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithGameCenter(
    LoginWithGameCenterRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithGameCenter"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGameCenterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithGameCenterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithGoogleAccount(
    LoginWithGoogleAccountRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithIOSDeviceID(
    LoginWithIOSDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithKongregate(
    LoginWithKongregateRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithKongregate"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithPlayFab(
    LoginWithPlayFabRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithPlayFab"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithPlayFabResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithPlayFabResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithPSN(
    LoginWithPSNRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithPSN"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithPSNResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithPSNResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithSteam(
    LoginWithSteamRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithSteam"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithSteamResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithSteamResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::LoginWithXbox(
    LoginWithXboxRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LoginWithXbox"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithXboxResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLoginWithXboxResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LoginResult* outResult = new LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::RegisterPlayFabUser(
    RegisterPlayFabUserRequest& request,
    ProcessApiCallback<RegisterPlayFabUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RegisterPlayFabUser"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterPlayFabUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRegisterPlayFabUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RegisterPlayFabUserResult* outResult = new RegisterPlayFabUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
            PlayFabClientAPI::mUserSessionTicket = outResult->SessionTicket;
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

void PlayFabClientAPI::AddUsernamePassword(
    AddUsernamePasswordRequest& request,
    ProcessApiCallback<AddUsernamePasswordResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AddUsernamePassword"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUsernamePasswordResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAddUsernamePasswordResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetAccountInfo(
    GetAccountInfoRequest& request,
    ProcessApiCallback<GetAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAccountInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetAccountInfoResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(
    GetPlayFabIDsFromGameCenterIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromGameCenterIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGameCenterIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromGameCenterIDsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(
    GetPlayFabIDsFromGoogleIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromGoogleIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGoogleIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromGoogleIDsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(
    GetPlayFabIDsFromKongregateIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromKongregateIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromKongregateIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromKongregateIDsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayFabIDsFromPSNAccountIDs(
    GetPlayFabIDsFromPSNAccountIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromPSNAccountIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromPSNAccountIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromPSNAccountIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayFabIDsFromPSNAccountIDsResult* outResult = new GetPlayFabIDsFromPSNAccountIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::GetPlayFabIDsFromSteamIDs(
    GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserCombinedInfo(
    GetUserCombinedInfoRequest& request,
    ProcessApiCallback<GetUserCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserCombinedInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserCombinedInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserCombinedInfoResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkAndroidDeviceID(
    LinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkCustomID(
    LinkCustomIDRequest& request,
    ProcessApiCallback<LinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkCustomIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkFacebookAccount(
    LinkFacebookAccountRequest& request,
    ProcessApiCallback<LinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkFacebookAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkGameCenterAccount(
    LinkGameCenterAccountRequest& request,
    ProcessApiCallback<LinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkGameCenterAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkGoogleAccount(
    LinkGoogleAccountRequest& request,
    ProcessApiCallback<LinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkGoogleAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkIOSDeviceID(
    LinkIOSDeviceIDRequest& request,
    ProcessApiCallback<LinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkIOSDeviceIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkKongregate(
    LinkKongregateAccountRequest& request,
    ProcessApiCallback<LinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkKongregateResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkPSNAccount(
    LinkPSNAccountRequest& request,
    ProcessApiCallback<LinkPSNAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkPSNAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkPSNAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkPSNAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkPSNAccountResult* outResult = new LinkPSNAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkPSNAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkPSNAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::LinkSteamAccount(
    LinkSteamAccountRequest& request,
    ProcessApiCallback<LinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkSteamAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LinkXboxAccount(
    LinkXboxAccountRequest& request,
    ProcessApiCallback<LinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LinkXboxAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkXboxAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLinkXboxAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LinkXboxAccountResult* outResult = new LinkXboxAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LinkXboxAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkXboxAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkAndroidDeviceID(
    UnlinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkCustomID(
    UnlinkCustomIDRequest& request,
    ProcessApiCallback<UnlinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkCustomIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkCustomIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkFacebookAccount(
    
    ProcessApiCallback<UnlinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkFacebookAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkGameCenterAccount(
    
    ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkGoogleAccount(
    
    ProcessApiCallback<UnlinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkGoogleAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkIOSDeviceID(
    UnlinkIOSDeviceIDRequest& request,
    ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkKongregate(
    
    ProcessApiCallback<UnlinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkKongregateResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkKongregateResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkPSNAccount(
    
    ProcessApiCallback<UnlinkPSNAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkPSNAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkPSNAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkPSNAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkPSNAccountResult* outResult = new UnlinkPSNAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkPSNAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkPSNAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::UnlinkSteamAccount(
    
    ProcessApiCallback<UnlinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkSteamAccountResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlinkXboxAccount(
    UnlinkXboxAccountRequest& request,
    ProcessApiCallback<UnlinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlinkXboxAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkXboxAccountResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlinkXboxAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UnlinkXboxAccountResult* outResult = new UnlinkXboxAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UnlinkXboxAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkXboxAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetFriendLeaderboard(
    GetFriendLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetFriendLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetFriendLeaderboardResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetFriendLeaderboardAroundCurrentUser(
    GetFriendLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetFriendLeaderboardAroundCurrentUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundCurrentUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetFriendLeaderboardAroundCurrentUserResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetFriendLeaderboardAroundPlayer(
    GetFriendLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetFriendLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetFriendLeaderboardAroundPlayerResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetLeaderboard(
    GetLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetLeaderboardResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetLeaderboardAroundCurrentUser(
    GetLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetLeaderboardAroundCurrentUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCurrentUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCurrentUserResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetLeaderboardAroundPlayer(
    GetLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetLeaderboardAroundPlayerResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayerStatistics(
    GetPlayerStatisticsRequest& request,
    ProcessApiCallback<GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayerStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserStatistics(
    
    ProcessApiCallback<GetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdatePlayerStatistics(
    UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateUserDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateUserStatistics(
    UpdateUserStatisticsRequest& request,
    ProcessApiCallback<UpdateUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateUserStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCatalogItemsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetStoreItems(
    GetStoreItemsRequest& request,
    ProcessApiCallback<GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetStoreItemsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetTitleDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetTitleNews(
    GetTitleNewsRequest& request,
    ProcessApiCallback<GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetTitleNewsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ConfirmPurchase(
    ConfirmPurchaseRequest& request,
    ProcessApiCallback<ConfirmPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ConfirmPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConfirmPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnConfirmPurchaseResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ConsumeItem(
    ConsumeItemRequest& request,
    ProcessApiCallback<ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnConsumeItemResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    ProcessApiCallback<GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCharacterInventoryResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPurchase(
    GetPurchaseRequest& request,
    ProcessApiCallback<GetPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPurchaseResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetUserInventory(
    
    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetUserInventoryResult(PlayFabRequest* request)
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

void PlayFabClientAPI::PayForPurchase(
    PayForPurchaseRequest& request,
    ProcessApiCallback<PayForPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/PayForPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPayForPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnPayForPurchaseResult(PlayFabRequest* request)
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

void PlayFabClientAPI::PurchaseItem(
    PurchaseItemRequest& request,
    ProcessApiCallback<PurchaseItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/PurchaseItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPurchaseItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnPurchaseItemResult(PlayFabRequest* request)
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

void PlayFabClientAPI::RedeemCoupon(
    RedeemCouponRequest& request,
    ProcessApiCallback<RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRedeemCouponResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ReportPlayer(
    ReportPlayerClientRequest& request,
    ProcessApiCallback<ReportPlayerClientResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnReportPlayerResult(PlayFabRequest* request)
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

void PlayFabClientAPI::StartPurchase(
    StartPurchaseRequest& request,
    ProcessApiCallback<StartPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/StartPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnStartPurchaseResult(PlayFabRequest* request)
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

void PlayFabClientAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlockContainerInstance(
    UnlockContainerInstanceRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlockContainerInstanceResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUnlockContainerItemResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AddFriend(
    AddFriendRequest& request,
    ProcessApiCallback<AddFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AddFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddFriendResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAddFriendResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetFriendsList(
    GetFriendsListRequest& request,
    ProcessApiCallback<GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetFriendsList"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendsListResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetFriendsListResult(PlayFabRequest* request)
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

void PlayFabClientAPI::RemoveFriend(
    RemoveFriendRequest& request,
    ProcessApiCallback<RemoveFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RemoveFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveFriendResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRemoveFriendResult(PlayFabRequest* request)
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

void PlayFabClientAPI::SetFriendTags(
    SetFriendTagsRequest& request,
    ProcessApiCallback<SetFriendTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/SetFriendTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetFriendTagsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnSetFriendTagsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::RegisterForIOSPushNotification(
    RegisterForIOSPushNotificationRequest& request,
    ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RegisterForIOSPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRegisterForIOSPushNotificationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(PlayFabRequest* request)
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

void PlayFabClientAPI::RestoreIOSPurchases(
    RestoreIOSPurchasesRequest& request,
    ProcessApiCallback<RestoreIOSPurchasesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RestoreIOSPurchases"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRestoreIOSPurchasesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRestoreIOSPurchasesResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ValidateIOSReceipt(
    ValidateIOSReceiptRequest& request,
    ProcessApiCallback<ValidateIOSReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ValidateIOSReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateIOSReceiptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnValidateIOSReceiptResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCurrentGames(
    CurrentGamesRequest& request,
    ProcessApiCallback<CurrentGamesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCurrentGames"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCurrentGamesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCurrentGamesResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetGameServerRegions(
    GameServerRegionsRequest& request,
    ProcessApiCallback<GameServerRegionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetGameServerRegions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetGameServerRegionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetGameServerRegionsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::Matchmake(
    MatchmakeRequest& request,
    ProcessApiCallback<MatchmakeResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/Matchmake"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnMatchmakeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnMatchmakeResult(PlayFabRequest* request)
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

void PlayFabClientAPI::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnStartGameResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
    AndroidDevicePushNotificationRegistrationRequest& request,
    ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AndroidDevicePushNotificationRegistration"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAndroidDevicePushNotificationRegistrationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ValidateGooglePlayPurchase(
    ValidateGooglePlayPurchaseRequest& request,
    ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ValidateGooglePlayPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateGooglePlayPurchaseResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(PlayFabRequest* request)
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

void PlayFabClientAPI::LogEvent(
    LogEventRequest& request,
    ProcessApiCallback<LogEventResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/LogEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLogEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnLogEventResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    ProcessApiCallback<AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAddSharedGroupMembersResult(PlayFabRequest* request)
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

void PlayFabClientAPI::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    ProcessApiCallback<CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnCreateSharedGroupResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPublisherDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    ProcessApiCallback<GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetSharedGroupDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ConsumePSNEntitlements(
    ConsumePSNEntitlementsRequest& request,
    ProcessApiCallback<ConsumePSNEntitlementsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ConsumePSNEntitlements"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConsumePSNEntitlementsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnConsumePSNEntitlementsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ConsumePSNEntitlementsResult* outResult = new ConsumePSNEntitlementsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ConsumePSNEntitlementsResult> successCallback = reinterpret_cast<ProcessApiCallback<ConsumePSNEntitlementsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::RefreshPSNAuthToken(
    RefreshPSNAuthTokenRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RefreshPSNAuthToken"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRefreshPSNAuthTokenResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRefreshPSNAuthTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EmptyResult* outResult = new EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::GetCloudScriptUrl(
    GetCloudScriptUrlRequest& request,
    ProcessApiCallback<GetCloudScriptUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCloudScriptUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCloudScriptUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCloudScriptUrlResult* outResult = new GetCloudScriptUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

if (outResult->Url.length() > 0) PlayFabSettings::logicServerURL = outResult->Url;

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCloudScriptUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCloudScriptUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientAPI::RunCloudScript(
    RunCloudScriptRequest& request,
    ProcessApiCallback<RunCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/RunCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRunCloudScriptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnRunCloudScriptResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    ProcessApiCallback<GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetContentDownloadUrlResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetAllUsersCharacters(
    ListUsersCharactersRequest& request,
    ProcessApiCallback<ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetAllUsersCharactersResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCharacterStatistics(
    GetCharacterStatisticsRequest& request,
    ProcessApiCallback<GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCharacterStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    ProcessApiCallback<GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGrantCharacterToUserResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateCharacterStatistics(
    UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCharacterData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCharacterDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnUpdateCharacterDataResult(PlayFabRequest* request)
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

void PlayFabClientAPI::ValidateAmazonIAPReceipt(
    ValidateAmazonReceiptRequest& request,
    ProcessApiCallback<ValidateAmazonReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/ValidateAmazonIAPReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateAmazonIAPReceiptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnValidateAmazonIAPReceiptResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AcceptTrade(
    AcceptTradeRequest& request,
    ProcessApiCallback<AcceptTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/AcceptTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAcceptTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnAcceptTradeResult(PlayFabRequest* request)
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

void PlayFabClientAPI::CancelTrade(
    CancelTradeRequest& request,
    ProcessApiCallback<CancelTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/CancelTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCancelTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnCancelTradeResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetPlayerTrades(
    GetPlayerTradesRequest& request,
    ProcessApiCallback<GetPlayerTradesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetPlayerTrades"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTradesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetPlayerTradesResult(PlayFabRequest* request)
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

void PlayFabClientAPI::GetTradeStatus(
    GetTradeStatusRequest& request,
    ProcessApiCallback<GetTradeStatusResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/GetTradeStatus"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTradeStatusResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnGetTradeStatusResult(PlayFabRequest* request)
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

void PlayFabClientAPI::OpenTrade(
    OpenTradeRequest& request,
    ProcessApiCallback<OpenTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Client/OpenTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnOpenTradeResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabClientAPI::OnOpenTradeResult(PlayFabRequest* request)
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

void PlayFabClientAPI::AttributeInstall(
    AttributeInstallRequest& request,
    ProcessApiCallback<AttributeInstallResult> callback,
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
        AttributeInstallResult* outResult = new AttributeInstallResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::advertisingIdType += "_Successful";

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<AttributeInstallResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}


