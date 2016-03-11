#include "StdAfx.h"
#include "PlayFabServerApi.h"
#include "PlayFabServerApiWrapper.h"

using namespace PlayFab;
PlayFabServerApiWrapper PlayFabServerApiWrapper::globalWrapper;

// ------------ Generated API call wrappers

void PlayFabServerApiWrapper::AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::AuthenticateSessionTicket(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserAccountInfo(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SendPushNotification(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::DeleteUsers(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetLeaderboard(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetLeaderboardAroundUser(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetPlayerStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserStatistics(ServerModels::GetUserStatisticsRequest& request, ProcessApiCallback<ServerModels::GetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserStatistics(ServerModels::UpdateUserStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetTitleData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetTitleInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetTitleNews(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SetTitleData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SetTitleInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::AddCharacterVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::ConsumeItem(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterInventory(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetUserInventory(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GrantItemsToCharacter(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GrantItemsToUser(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GrantItemsToUsers(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::ModifyItemUses(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::MoveItemToCharacterFromCharacter(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::MoveItemToCharacterFromUser(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::MoveItemToUserFromCharacter(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::RedeemCoupon(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::ReportPlayer(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::RevokeInventoryItem(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SubtractCharacterVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UnlockContainerInstance(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UnlockContainerItem(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserInventoryItemDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateUserInventoryItemCustomData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::NotifyMatchmakerPlayerLeft(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::RedeemMatchmakerTicket(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::AwardSteamAchievement(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::LogEvent(ServerModels::LogEventRequest& request, ProcessApiCallback<ServerModels::LogEventResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::LogEvent(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::CreateSharedGroup(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::DeleteSharedGroup(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetSharedGroupData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::SetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::DeleteCharacterFromUser(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GrantCharacterToUser(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateCharacterData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateCharacterInternalData(request, callback, errorCallback, customData);
}

void PlayFabServerApiWrapper::UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabServerApi::UpdateCharacterReadOnlyData(request, callback, errorCallback, customData);
}

