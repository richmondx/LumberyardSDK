#include "StdAfx.h"
#include "PlayFabMatchmakerAPI.h"
#include "PlayFabSettings.h"
#include "PlayFabSdkGem.h"

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

// PlayFabMatchmaker API
PlayFabMatchmakerAPI::PlayFabMatchmakerAPI() {}

void PlayFabMatchmakerAPI::AuthUser(
    AuthUserRequest& request,
    ProcessApiCallback<AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Matchmaker/AuthUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerAPI::OnAuthUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AuthUserResponse* outResult = new AuthUserResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AuthUserResponse> successCallback = reinterpret_cast<ProcessApiCallback<AuthUserResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerAPI::PlayerJoined(
    PlayerJoinedRequest& request,
    ProcessApiCallback<PlayerJoinedResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Matchmaker/PlayerJoined"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerJoinedResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerAPI::OnPlayerJoinedResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        PlayerJoinedResponse* outResult = new PlayerJoinedResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<PlayerJoinedResponse> successCallback = reinterpret_cast<ProcessApiCallback<PlayerJoinedResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerAPI::PlayerLeft(
    PlayerLeftRequest& request,
    ProcessApiCallback<PlayerLeftResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Matchmaker/PlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerLeftResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerAPI::OnPlayerLeftResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        PlayerLeftResponse* outResult = new PlayerLeftResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<PlayerLeftResponse> successCallback = reinterpret_cast<ProcessApiCallback<PlayerLeftResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerAPI::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Matchmaker/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerAPI::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        StartGameResponse* outResult = new StartGameResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<StartGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<StartGameResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerAPI::UserInfo(
    UserInfoRequest& request,
    ProcessApiCallback<UserInfoResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Matchmaker/UserInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUserInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerAPI::OnUserInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UserInfoResponse* outResult = new UserInfoResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UserInfoResponse> successCallback = reinterpret_cast<ProcessApiCallback<UserInfoResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}


