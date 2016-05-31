#include "StdAfx.h"
#include "PlayFabAdminApi.h"
#include "PlayFabAdminApiWrapper.h"

using namespace PlayFab;
PlayFabAdminApiWrapper PlayFabAdminApiWrapper::globalWrapper;

// ------------ Generated API call wrappers

void PlayFabAdminApiWrapper::GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserAccountInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetUsers(AdminModels::ResetUsersRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::CreatePlayerStatisticDefinition(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteUsers(AdminModels::DeleteUsersRequest& request, ProcessApiCallback<AdminModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetDataReport(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerStatisticDefinitions(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::IncrementPlayerStatisticVersion(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RefundPurchase(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetUserStatistics(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResolvePurchaseDispute(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdatePlayerStatisticDefinition(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddNews(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddVirtualCurrencyTypes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetRandomResultTables(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetTitleData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ListVirtualCurrencyTypes(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetStoreSegmentOverrides(AdminModels::SetStoreSegmentOverridesRequest& request, ProcessApiCallback<AdminModels::SetStoreSegemntOverridesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetStoreSegmentOverrides(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetTitleData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetupPushNotification(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateRandomResultTables(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserInventory(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GrantItemsToUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RevokeInventoryItem(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetMatchmakerGameInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetMatchmakerGameModes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ModifyMatchmakerGameModes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetServerBuildInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetServerBuildUploadUrl(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ListServerBuilds(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ModifyServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RemoveServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCloudScriptRevision(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCloudScriptVersions(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetPublishedRevision(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateCloudScript(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteContent(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetContentList(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetContentUploadUrl(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetCharacterStatistics(request, callback, errorCallback, customData);
}

