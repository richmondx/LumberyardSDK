#include "StdAfx.h"
#include "PlayFabAdminApi.h"
#include "PlayFabSettings.h"

using namespace PlayFab;
using namespace AdminModels;

// PlayFabAdmin Api
PlayFabAdminApi::PlayFabAdminApi() {}

void PlayFabAdminApi::GetUserAccountInfo(
    LookupUserAccountInfoRequest& request,
    ProcessApiCallback<LookupUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserAccountInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        LookupUserAccountInfoResult* outResult = new LookupUserAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<LookupUserAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<LookupUserAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResetUsers(
    ResetUsersRequest& request,
    ProcessApiCallback<BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ResetUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetUsersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        BlankResult* outResult = new BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
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

void PlayFabAdminApi::CreatePlayerStatisticDefinition(
    CreatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<CreatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/CreatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreatePlayerStatisticDefinitionResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        CreatePlayerStatisticDefinitionResult* outResult = new CreatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<CreatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<CreatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteUsers(
    DeleteUsersRequest& request,
    ProcessApiCallback<DeleteUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/DeleteUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteUsersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteUsersResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetDataReport(
    GetDataReportRequest& request,
    ProcessApiCallback<GetDataReportResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetDataReport"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetDataReportResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetDataReportResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetDataReportResult* outResult = new GetDataReportResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetDataReportResult> successCallback = reinterpret_cast<ProcessApiCallback<GetDataReportResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerStatisticDefinitions(

    ProcessApiCallback<GetPlayerStatisticDefinitionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetPlayerStatisticDefinitions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, "", customData, callback, errorCallback, OnGetPlayerStatisticDefinitionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticDefinitionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetPlayerStatisticDefinitionsResult* outResult = new GetPlayerStatisticDefinitionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetPlayerStatisticDefinitionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerStatisticDefinitionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerStatisticVersions(
    GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInternalDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserPublisherInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherInternalDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::IncrementPlayerStatisticVersion(
    IncrementPlayerStatisticVersionRequest& request,
    ProcessApiCallback<IncrementPlayerStatisticVersionResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/IncrementPlayerStatisticVersion"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnIncrementPlayerStatisticVersionResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnIncrementPlayerStatisticVersionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        IncrementPlayerStatisticVersionResult* outResult = new IncrementPlayerStatisticVersionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<IncrementPlayerStatisticVersionResult> successCallback = reinterpret_cast<ProcessApiCallback<IncrementPlayerStatisticVersionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResetUserStatistics(
    ResetUserStatisticsRequest& request,
    ProcessApiCallback<ResetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ResetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetUserStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetUserStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ResetUserStatisticsResult* outResult = new ResetUserStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ResetUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ResetUserStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdatePlayerStatisticDefinition(
    UpdatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticDefinitionResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdatePlayerStatisticDefinitionResult* outResult = new UpdatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserInternalDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserPublisherInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserPublisherReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::UpdateUserReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserReadOnlyDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::AddNews(
    AddNewsRequest& request,
    ProcessApiCallback<AddNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/AddNews"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddNewsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AddNewsResult* outResult = new AddNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AddNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<AddNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddVirtualCurrencyTypes(
    AddVirtualCurrencyTypesRequest& request,
    ProcessApiCallback<BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/AddVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddVirtualCurrencyTypesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        BlankResult* outResult = new BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCatalogItemsResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPublisherDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetRandomResultTables(
    GetRandomResultTablesRequest& request,
    ProcessApiCallback<GetRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetRandomResultTablesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetRandomResultTablesResult* outResult = new GetRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<GetRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetStoreItems(
    GetStoreItemsRequest& request,
    ProcessApiCallback<GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetStoreItemsResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTitleDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::ListVirtualCurrencyTypes(

    ProcessApiCallback<ListVirtualCurrencyTypesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ListVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, "", customData, callback, errorCallback, OnListVirtualCurrencyTypesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnListVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ListVirtualCurrencyTypesResult* outResult = new ListVirtualCurrencyTypesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ListVirtualCurrencyTypesResult> successCallback = reinterpret_cast<ProcessApiCallback<ListVirtualCurrencyTypesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetCatalogItems(
    UpdateCatalogItemsRequest& request,
    ProcessApiCallback<UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateCatalogItemsResult* outResult = new UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetStoreItems(
    UpdateStoreItemsRequest& request,
    ProcessApiCallback<UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetStoreItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateStoreItemsResult* outResult = new UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetTitleData(
    SetTitleDataRequest& request,
    ProcessApiCallback<SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetTitleDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::SetupPushNotification(
    SetupPushNotificationRequest& request,
    ProcessApiCallback<SetupPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetupPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetupPushNotificationResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetupPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetupPushNotificationResult* outResult = new SetupPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetupPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<SetupPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateCatalogItems(
    UpdateCatalogItemsRequest& request,
    ProcessApiCallback<UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCatalogItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateCatalogItemsResult* outResult = new UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateRandomResultTables(
    UpdateRandomResultTablesRequest& request,
    ProcessApiCallback<UpdateRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateRandomResultTablesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateRandomResultTablesResult* outResult = new UpdateRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateStoreItems(
    UpdateStoreItemsRequest& request,
    ProcessApiCallback<UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateStoreItemsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateStoreItemsResult* outResult = new UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetUserInventory(
    GetUserInventoryRequest& request,
    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInventoryResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GrantItemsToUsers(
    GrantItemsToUsersRequest& request,
    ProcessApiCallback<GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GrantItemsToUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUsersResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGrantItemsToUsersResult(PlayFabRequest* request)
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

void PlayFabAdminApi::RevokeInventoryItem(
    RevokeInventoryItemRequest& request,
    ProcessApiCallback<RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/RevokeInventoryItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeInventoryItemResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeInventoryItemResult(PlayFabRequest* request)
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

void PlayFabAdminApi::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetMatchmakerGameInfo(
    GetMatchmakerGameInfoRequest& request,
    ProcessApiCallback<GetMatchmakerGameInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetMatchmakerGameInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetMatchmakerGameInfoResult* outResult = new GetMatchmakerGameInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetMatchmakerGameInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetMatchmakerGameInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetMatchmakerGameModes(
    GetMatchmakerGameModesRequest& request,
    ProcessApiCallback<GetMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameModesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetMatchmakerGameModesResult* outResult = new GetMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<GetMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ModifyMatchmakerGameModes(
    ModifyMatchmakerGameModesRequest& request,
    ProcessApiCallback<ModifyMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ModifyMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyMatchmakerGameModesResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyMatchmakerGameModesResult* outResult = new ModifyMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddServerBuild(
    AddServerBuildRequest& request,
    ProcessApiCallback<AddServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/AddServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddServerBuildResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AddServerBuildResult* outResult = new AddServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AddServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AddServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetServerBuildInfo(
    GetServerBuildInfoRequest& request,
    ProcessApiCallback<GetServerBuildInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetServerBuildInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildInfoResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetServerBuildInfoResult* outResult = new GetServerBuildInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetServerBuildInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetServerBuildInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetServerBuildUploadUrl(
    GetServerBuildUploadURLRequest& request,
    ProcessApiCallback<GetServerBuildUploadURLResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetServerBuildUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildUploadUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetServerBuildUploadURLResult* outResult = new GetServerBuildUploadURLResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetServerBuildUploadURLResult> successCallback = reinterpret_cast<ProcessApiCallback<GetServerBuildUploadURLResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ListServerBuilds(

    ProcessApiCallback<ListBuildsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ListServerBuilds"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, "", customData, callback, errorCallback, OnListServerBuildsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnListServerBuildsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ListBuildsResult* outResult = new ListBuildsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ListBuildsResult> successCallback = reinterpret_cast<ProcessApiCallback<ListBuildsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ModifyServerBuild(
    ModifyServerBuildRequest& request,
    ProcessApiCallback<ModifyServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ModifyServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyServerBuildResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ModifyServerBuildResult* outResult = new ModifyServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ModifyServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RemoveServerBuild(
    RemoveServerBuildRequest& request,
    ProcessApiCallback<RemoveServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/RemoveServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveServerBuildResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemoveServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        RemoveServerBuildResult* outResult = new RemoveServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<RemoveServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetPublisherData(
    SetPublisherDataRequest& request,
    ProcessApiCallback<SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublisherDataResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublisherDataResult(PlayFabRequest* request)
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

void PlayFabAdminApi::GetCloudScriptRevision(
    GetCloudScriptRevisionRequest& request,
    ProcessApiCallback<GetCloudScriptRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetCloudScriptRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptRevisionResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCloudScriptRevisionResult* outResult = new GetCloudScriptRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCloudScriptRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCloudScriptRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCloudScriptVersions(

    ProcessApiCallback<GetCloudScriptVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetCloudScriptVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, "", customData, callback, errorCallback, OnGetCloudScriptVersionsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetCloudScriptVersionsResult* outResult = new GetCloudScriptVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetCloudScriptVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCloudScriptVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetPublishedRevision(
    SetPublishedRevisionRequest& request,
    ProcessApiCallback<SetPublishedRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/SetPublishedRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublishedRevisionResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublishedRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        SetPublishedRevisionResult* outResult = new SetPublishedRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<SetPublishedRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<SetPublishedRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateCloudScript(
    UpdateCloudScriptRequest& request,
    ProcessApiCallback<UpdateCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/UpdateCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCloudScriptResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        UpdateCloudScriptResult* outResult = new UpdateCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<UpdateCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteContent(
    DeleteContentRequest& request,
    ProcessApiCallback<BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/DeleteContent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteContentResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteContentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        BlankResult* outResult = new BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetContentList(
    GetContentListRequest& request,
    ProcessApiCallback<GetContentListResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetContentList"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentListResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetContentListResult* outResult = new GetContentListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetContentListResult> successCallback = reinterpret_cast<ProcessApiCallback<GetContentListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetContentUploadUrl(
    GetContentUploadUrlRequest& request,
    ProcessApiCallback<GetContentUploadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/GetContentUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentUploadUrlResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GetContentUploadUrlResult* outResult = new GetContentUploadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GetContentUploadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetContentUploadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResetCharacterStatistics(
    ResetCharacterStatisticsRequest& request,
    ProcessApiCallback<ResetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
    )
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings.getURL("/Admin/ResetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings.developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp.AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ResetCharacterStatisticsResult* outResult = new ResetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ResetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ResetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

