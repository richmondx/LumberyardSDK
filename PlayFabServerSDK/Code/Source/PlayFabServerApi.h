#pragma once

#include "PlayFabError.h"
#include "PlayFabHttp.h"
#include "IPlayFabServerApi.h"
#include "PlayFabServerDataModels.h"

namespace PlayFab
{
    class PlayFabServerApi
    {
    public:        // ------------ Generated Api calls
        static void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserStatistics(ServerModels::GetUserStatisticsRequest& request, ProcessApiCallback<ServerModels::GetUserStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserStatistics(ServerModels::UpdateUserStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateUserStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserInventoryItemDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LogEvent(ServerModels::LogEventRequest& request, ProcessApiCallback<ServerModels::LogEventResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabServerApi();

        // ------------ Generated result handlers
        static void OnAuthenticateSessionTicketResult(PlayFabRequest* request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request);
        static void OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request);
        static void OnGetUserAccountInfoResult(PlayFabRequest* request);
        static void OnSendPushNotificationResult(PlayFabRequest* request);
        static void OnDeleteUsersResult(PlayFabRequest* request);
        static void OnGetLeaderboardResult(PlayFabRequest* request);
        static void OnGetLeaderboardAroundUserResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticsResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticVersionsResult(PlayFabRequest* request);
        static void OnGetUserDataResult(PlayFabRequest* request);
        static void OnGetUserInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnGetUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnGetUserStatisticsResult(PlayFabRequest* request);
        static void OnUpdatePlayerStatisticsResult(PlayFabRequest* request);
        static void OnUpdateUserDataResult(PlayFabRequest* request);
        static void OnUpdateUserInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateUserStatisticsResult(PlayFabRequest* request);
        static void OnGetCatalogItemsResult(PlayFabRequest* request);
        static void OnGetTitleDataResult(PlayFabRequest* request);
        static void OnGetTitleInternalDataResult(PlayFabRequest* request);
        static void OnGetTitleNewsResult(PlayFabRequest* request);
        static void OnSetTitleDataResult(PlayFabRequest* request);
        static void OnSetTitleInternalDataResult(PlayFabRequest* request);
        static void OnAddCharacterVirtualCurrencyResult(PlayFabRequest* request);
        static void OnAddUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnConsumeItemResult(PlayFabRequest* request);
        static void OnGetCharacterInventoryResult(PlayFabRequest* request);
        static void OnGetUserInventoryResult(PlayFabRequest* request);
        static void OnGrantItemsToCharacterResult(PlayFabRequest* request);
        static void OnGrantItemsToUserResult(PlayFabRequest* request);
        static void OnGrantItemsToUsersResult(PlayFabRequest* request);
        static void OnModifyItemUsesResult(PlayFabRequest* request);
        static void OnMoveItemToCharacterFromCharacterResult(PlayFabRequest* request);
        static void OnMoveItemToCharacterFromUserResult(PlayFabRequest* request);
        static void OnMoveItemToUserFromCharacterResult(PlayFabRequest* request);
        static void OnRedeemCouponResult(PlayFabRequest* request);
        static void OnReportPlayerResult(PlayFabRequest* request);
        static void OnRevokeInventoryItemResult(PlayFabRequest* request);
        static void OnSubtractCharacterVirtualCurrencyResult(PlayFabRequest* request);
        static void OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnUnlockContainerInstanceResult(PlayFabRequest* request);
        static void OnUnlockContainerItemResult(PlayFabRequest* request);
        static void OnUpdateUserInventoryItemCustomDataResult(PlayFabRequest* request);
        static void OnNotifyMatchmakerPlayerLeftResult(PlayFabRequest* request);
        static void OnRedeemMatchmakerTicketResult(PlayFabRequest* request);
        static void OnAwardSteamAchievementResult(PlayFabRequest* request);
        static void OnLogEventResult(PlayFabRequest* request);
        static void OnAddSharedGroupMembersResult(PlayFabRequest* request);
        static void OnCreateSharedGroupResult(PlayFabRequest* request);
        static void OnDeleteSharedGroupResult(PlayFabRequest* request);
        static void OnGetPublisherDataResult(PlayFabRequest* request);
        static void OnGetSharedGroupDataResult(PlayFabRequest* request);
        static void OnRemoveSharedGroupMembersResult(PlayFabRequest* request);
        static void OnSetPublisherDataResult(PlayFabRequest* request);
        static void OnUpdateSharedGroupDataResult(PlayFabRequest* request);
        static void OnGetContentDownloadUrlResult(PlayFabRequest* request);
        static void OnDeleteCharacterFromUserResult(PlayFabRequest* request);
        static void OnGetAllUsersCharactersResult(PlayFabRequest* request);
        static void OnGetCharacterLeaderboardResult(PlayFabRequest* request);
        static void OnGetCharacterStatisticsResult(PlayFabRequest* request);
        static void OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request);
        static void OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request);
        static void OnGrantCharacterToUserResult(PlayFabRequest* request);
        static void OnUpdateCharacterStatisticsResult(PlayFabRequest* request);
        static void OnGetCharacterDataResult(PlayFabRequest* request);
        static void OnGetCharacterInternalDataResult(PlayFabRequest* request);
        static void OnGetCharacterReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterInternalDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterReadOnlyDataResult(PlayFabRequest* request);
    };
};
