#include "StdAfx.h"
#include "PlayFabMatchmakerApi.h"
#include "PlayFabSettings.h"

using namespace PlayFab;
using namespace MatchmakerModels;

// PlayFabMatchmaker Api
PlayFabMatchmakerApi::PlayFabMatchmakerApi() {}

void PlayFabMatchmakerApi::AuthUser(
    AuthUserRequest& request,
    ProcessApiCallback<AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Matchmaker/AuthUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnAuthUserResult(PlayFabRequest* request)
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

void PlayFabMatchmakerApi::PlayerJoined(
    PlayerJoinedRequest& request,
    ProcessApiCallback<PlayerJoinedResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Matchmaker/PlayerJoined"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerJoinedResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerJoinedResult(PlayFabRequest* request)
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

void PlayFabMatchmakerApi::PlayerLeft(
    PlayerLeftRequest& request,
    ProcessApiCallback<PlayerLeftResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Matchmaker/PlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerLeftResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerLeftResult(PlayFabRequest* request)
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

void PlayFabMatchmakerApi::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Matchmaker/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnStartGameResult(PlayFabRequest* request)
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

void PlayFabMatchmakerApi::UserInfo(
    UserInfoRequest& request,
    ProcessApiCallback<UserInfoResponse> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Matchmaker/UserInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUserInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnUserInfoResult(PlayFabRequest* request)
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

