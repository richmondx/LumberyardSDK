#include "StdAfx.h"
#include "PlayFabMatchmakerApi.h"
#include "PlayFabMatchmakerApiWrapper.h"

using namespace PlayFab;
PlayFabMatchmakerApiWrapper PlayFabMatchmakerApiWrapper::globalWrapper;

// ------------ Generated API call wrappers

void PlayFabMatchmakerApiWrapper::AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabMatchmakerApi::AuthUser(request, callback, errorCallback, customData);
}

void PlayFabMatchmakerApiWrapper::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabMatchmakerApi::PlayerJoined(request, callback, errorCallback, customData);
}

void PlayFabMatchmakerApiWrapper::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabMatchmakerApi::PlayerLeft(request, callback, errorCallback, customData);
}

void PlayFabMatchmakerApiWrapper::StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabMatchmakerApi::StartGame(request, callback, errorCallback, customData);
}

void PlayFabMatchmakerApiWrapper::UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabMatchmakerApi::UserInfo(request, callback, errorCallback, customData);
}

