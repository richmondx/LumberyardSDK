#include "StdAfx.h"
#include "PlayFabServerAPI.h"
#include "PlayFabSettings.h"
#include "PlayFabSdkGem.h"

using namespace PlayFab;
using namespace PlayFab::ServerModels;

// PlayFabServer API
PlayFabServerAPI::PlayFabServerAPI() {}

void PlayFabServerAPI::AuthenticateSessionTicket(
    AuthenticateSessionTicketRequest& request,
    ProcessApiCallback<AuthenticateSessionTicketResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/AuthenticateSessionTicket"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthenticateSessionTicketResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnAuthenticateSessionTicketResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AuthenticateSessionTicketResult* outResult = new AuthenticateSessionTicketResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AuthenticateSessionTicketResult> successCallback = reinterpret_cast<ProcessApiCallback<AuthenticateSessionTicketResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetPlayFabIDsFromSteamIDs(
    GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserAccountInfo(
    GetUserAccountInfoRequest& request,
    ProcessApiCallback<GetUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserAccountInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetUserAccountInfoResult* outResult = new GetUserAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetUserAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::SendPushNotification(
    SendPushNotificationRequest& request,
    ProcessApiCallback<SendPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SendPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSendPushNotificationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSendPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SendPushNotificationResult* outResult = new SendPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SendPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<SendPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::DeleteUsers(
    DeleteUsersRequest& request,
    ProcessApiCallback<DeleteUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/DeleteUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteUsersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnDeleteUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DeleteUsersResult* outResult = new DeleteUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DeleteUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<DeleteUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GetLeaderboard(
    GetLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetLeaderboardResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetLeaderboardAroundUser(
    GetLeaderboardAroundUserRequest& request,
    ProcessApiCallback<GetLeaderboardAroundUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetLeaderboardAroundUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetLeaderboardAroundUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetLeaderboardAroundUserResult* outResult = new GetLeaderboardAroundUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GetPlayerStatistics(
    GetPlayerStatisticsRequest& request,
    ProcessApiCallback<GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetPlayerStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetPlayerStatisticVersions(
    GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserPublisherInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserPublisherInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserStatistics(
    GetUserStatisticsRequest& request,
    ProcessApiCallback<GetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdatePlayerStatistics(
    UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserPublisherInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserPublisherReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserStatistics(
    UpdateUserStatisticsRequest& request,
    ProcessApiCallback<UpdateUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCatalogItemsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetTitleDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetTitleInternalData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetTitleInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetTitleNews(
    GetTitleNewsRequest& request,
    ProcessApiCallback<GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetTitleNewsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::SetTitleData(
    SetTitleDataRequest& request,
    ProcessApiCallback<SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetTitleDataResult* outResult = new SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::SetTitleInternalData(
    SetTitleDataRequest& request,
    ProcessApiCallback<SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetTitleDataResult* outResult = new SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::AddCharacterVirtualCurrency(
    AddCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/AddCharacterVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddCharacterVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnAddCharacterVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyCharacterVirtualCurrencyResult* outResult = new ModifyCharacterVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabServerAPI::ConsumeItem(
    ConsumeItemRequest& request,
    ProcessApiCallback<ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnConsumeItemResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    ProcessApiCallback<GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterInventoryResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetUserInventory(
    GetUserInventoryRequest& request,
    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetUserInventoryResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GrantItemsToCharacter(
    GrantItemsToCharacterRequest& request,
    ProcessApiCallback<GrantItemsToCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GrantItemsToCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGrantItemsToCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GrantItemsToCharacterResult* outResult = new GrantItemsToCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GrantItemsToCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<GrantItemsToCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GrantItemsToUser(
    GrantItemsToUserRequest& request,
    ProcessApiCallback<GrantItemsToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GrantItemsToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGrantItemsToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GrantItemsToUserResult* outResult = new GrantItemsToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GrantItemsToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GrantItemsToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GrantItemsToUsers(
    GrantItemsToUsersRequest& request,
    ProcessApiCallback<GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GrantItemsToUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUsersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGrantItemsToUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GrantItemsToUsersResult* outResult = new GrantItemsToUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GrantItemsToUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<GrantItemsToUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::ModifyItemUses(
    ModifyItemUsesRequest& request,
    ProcessApiCallback<ModifyItemUsesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/ModifyItemUses"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyItemUsesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnModifyItemUsesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyItemUsesResult* outResult = new ModifyItemUsesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyItemUsesResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyItemUsesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::MoveItemToCharacterFromCharacter(
    MoveItemToCharacterFromCharacterRequest& request,
    ProcessApiCallback<MoveItemToCharacterFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/MoveItemToCharacterFromCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToCharacterFromCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnMoveItemToCharacterFromCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MoveItemToCharacterFromCharacterResult* outResult = new MoveItemToCharacterFromCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MoveItemToCharacterFromCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<MoveItemToCharacterFromCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::MoveItemToCharacterFromUser(
    MoveItemToCharacterFromUserRequest& request,
    ProcessApiCallback<MoveItemToCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/MoveItemToCharacterFromUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToCharacterFromUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnMoveItemToCharacterFromUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MoveItemToCharacterFromUserResult* outResult = new MoveItemToCharacterFromUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MoveItemToCharacterFromUserResult> successCallback = reinterpret_cast<ProcessApiCallback<MoveItemToCharacterFromUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::MoveItemToUserFromCharacter(
    MoveItemToUserFromCharacterRequest& request,
    ProcessApiCallback<MoveItemToUserFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/MoveItemToUserFromCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToUserFromCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnMoveItemToUserFromCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MoveItemToUserFromCharacterResult* outResult = new MoveItemToUserFromCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MoveItemToUserFromCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<MoveItemToUserFromCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::RedeemCoupon(
    RedeemCouponRequest& request,
    ProcessApiCallback<RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnRedeemCouponResult(PlayFabRequest* request)
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

void PlayFabServerAPI::ReportPlayer(
    ReportPlayerServerRequest& request,
    ProcessApiCallback<ReportPlayerServerResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnReportPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ReportPlayerServerResult* outResult = new ReportPlayerServerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ReportPlayerServerResult> successCallback = reinterpret_cast<ProcessApiCallback<ReportPlayerServerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::RevokeInventoryItem(
    RevokeInventoryItemRequest& request,
    ProcessApiCallback<RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/RevokeInventoryItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeInventoryItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnRevokeInventoryItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RevokeInventoryResult* outResult = new RevokeInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RevokeInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<RevokeInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::SubtractCharacterVirtualCurrency(
    SubtractCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SubtractCharacterVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractCharacterVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSubtractCharacterVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyCharacterVirtualCurrencyResult* outResult = new ModifyCharacterVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UnlockContainerInstance(
    UnlockContainerInstanceRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUnlockContainerInstanceResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUnlockContainerItemResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateUserInventoryItemCustomData(
    UpdateUserInventoryItemDataRequest& request,
    ProcessApiCallback<UpdateUserInventoryItemDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateUserInventoryItemCustomData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInventoryItemCustomDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateUserInventoryItemCustomDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateUserInventoryItemDataResult* outResult = new UpdateUserInventoryItemDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateUserInventoryItemDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserInventoryItemDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::NotifyMatchmakerPlayerLeft(
    NotifyMatchmakerPlayerLeftRequest& request,
    ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/NotifyMatchmakerPlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnNotifyMatchmakerPlayerLeftResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnNotifyMatchmakerPlayerLeftResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        NotifyMatchmakerPlayerLeftResult* outResult = new NotifyMatchmakerPlayerLeftResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> successCallback = reinterpret_cast<ProcessApiCallback<NotifyMatchmakerPlayerLeftResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::RedeemMatchmakerTicket(
    RedeemMatchmakerTicketRequest& request,
    ProcessApiCallback<RedeemMatchmakerTicketResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/RedeemMatchmakerTicket"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRedeemMatchmakerTicketResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnRedeemMatchmakerTicketResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RedeemMatchmakerTicketResult* outResult = new RedeemMatchmakerTicketResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RedeemMatchmakerTicketResult> successCallback = reinterpret_cast<ProcessApiCallback<RedeemMatchmakerTicketResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::AwardSteamAchievement(
    AwardSteamAchievementRequest& request,
    ProcessApiCallback<AwardSteamAchievementResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/AwardSteamAchievement"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAwardSteamAchievementResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnAwardSteamAchievementResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AwardSteamAchievementResult* outResult = new AwardSteamAchievementResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AwardSteamAchievementResult> successCallback = reinterpret_cast<ProcessApiCallback<AwardSteamAchievementResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::LogEvent(
    LogEventRequest& request,
    ProcessApiCallback<LogEventResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/LogEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnLogEventResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnLogEventResult(PlayFabRequest* request)
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

void PlayFabServerAPI::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    ProcessApiCallback<AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnAddSharedGroupMembersResult(PlayFabRequest* request)
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

void PlayFabServerAPI::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    ProcessApiCallback<CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnCreateSharedGroupResult(PlayFabRequest* request)
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

void PlayFabServerAPI::DeleteSharedGroup(
    DeleteSharedGroupRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/DeleteSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteSharedGroupResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnDeleteSharedGroupResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetPublisherDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    ProcessApiCallback<GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetSharedGroupDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
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

void PlayFabServerAPI::SetPublisherData(
    SetPublisherDataRequest& request,
    ProcessApiCallback<SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/SetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnSetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetPublisherDataResult* outResult = new SetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<SetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    ProcessApiCallback<GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetContentDownloadUrlResult(PlayFabRequest* request)
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

void PlayFabServerAPI::DeleteCharacterFromUser(
    DeleteCharacterFromUserRequest& request,
    ProcessApiCallback<DeleteCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/DeleteCharacterFromUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteCharacterFromUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnDeleteCharacterFromUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DeleteCharacterFromUserResult* outResult = new DeleteCharacterFromUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DeleteCharacterFromUserResult> successCallback = reinterpret_cast<ProcessApiCallback<DeleteCharacterFromUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabServerAPI::GetAllUsersCharacters(
    ListUsersCharactersRequest& request,
    ProcessApiCallback<ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetAllUsersCharactersResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterStatistics(
    GetCharacterStatisticsRequest& request,
    ProcessApiCallback<GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    ProcessApiCallback<GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGrantCharacterToUserResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateCharacterStatistics(
    UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterInternalData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateCharacterDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateCharacterInternalData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateCharacterInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateCharacterInternalDataResult(PlayFabRequest* request)
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

void PlayFabServerAPI::UpdateCharacterReadOnlyData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::getURL("/Server/UpdateCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFab::PlayFabSettings::developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabServerAPI::OnUpdateCharacterReadOnlyDataResult(PlayFabRequest* request)
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


