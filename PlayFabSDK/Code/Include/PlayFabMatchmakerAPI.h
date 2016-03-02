#pragma once

#include "PlayFabError.h"
#include "PlayFabHttp.h"
#include "PlayFabMatchmakerDataModels.h"

namespace PlayFab
{
    class PlayFabMatchmakerAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* customData);

        // ------------ Generated API calls
        static void AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMatchmakerAPI();

        // ------------ Generated result handlers
        static void OnAuthUserResult(PlayFabRequest* request);
        static void OnPlayerJoinedResult(PlayFabRequest* request);
        static void OnPlayerLeftResult(PlayFabRequest* request);
        static void OnStartGameResult(PlayFabRequest* request);
        static void OnUserInfoResult(PlayFabRequest* request);
    };
};
