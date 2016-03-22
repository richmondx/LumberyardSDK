#include "StdAfx.h"
#include "PlayFabClientApi.h"
#include "PlayFabClientApiWrapper.h"

using namespace PlayFab;
PlayFabClientApiWrapper PlayFabClientApiWrapper::globalWrapper;

// Client-Specific
bool PlayFabClientApiWrapper::IsClientLoggedIn()
{
    return PlayFabClientApi::IsClientLoggedIn();
}

// ------------ Generated API call wrappers

void PlayFabClientApiWrapper::GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPhotonAuthenticationToken(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithAndroidDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithCustomID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithEmailAddress(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithFacebook(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithGameCenter(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithGoogleAccount(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithIOSDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithKongregate(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithPlayFab(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LoginWithSteam(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RegisterPlayFabUser(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AddUsernamePassword(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetAccountInfo(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserCombinedInfo(ClientModels::GetUserCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetUserCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserCombinedInfo(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkAndroidDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkCustomID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkFacebookAccount(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkGameCenterAccount(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkGoogleAccount(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkIOSDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkKongregate(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LinkSteamAccount(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkAndroidDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkCustomID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkFacebookAccount(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkGameCenterAccount(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkGoogleAccount(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkIOSDeviceID(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkKongregate(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlinkSteamAccount(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetFriendLeaderboardAroundCurrentUser(ClientModels::GetFriendLeaderboardAroundCurrentUserRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundCurrentUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetFriendLeaderboardAroundCurrentUser(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetFriendLeaderboardAroundPlayer(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetLeaderboard(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetLeaderboardAroundCurrentUser(ClientModels::GetLeaderboardAroundCurrentUserRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCurrentUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetLeaderboardAroundCurrentUser(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetLeaderboardAroundPlayer(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayerStatistics(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserStatistics(ProcessApiCallback<ClientModels::GetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserStatistics(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateUserData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateUserStatistics(ClientModels::UpdateUserStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateUserStatistics(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetStoreItems(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetTitleData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetTitleNews(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ConfirmPurchase(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ConsumeItem(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCharacterInventory(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPurchase(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetUserInventory(callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::PayForPurchase(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::PurchaseItem(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RedeemCoupon(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ReportPlayer(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::StartPurchase(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlockContainerInstance(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UnlockContainerItem(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AddFriend(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetFriendsList(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RemoveFriend(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::SetFriendTags(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RegisterForIOSPushNotification(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RestoreIOSPurchases(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ValidateIOSReceipt(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCurrentGames(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetGameServerRegions(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::Matchmake(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::StartGame(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AndroidDevicePushNotificationRegistration(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ValidateGooglePlayPurchase(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::LogEvent(ClientModels::LogEventRequest& request, ProcessApiCallback<ClientModels::LogEventResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::LogEvent(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::CreateSharedGroup(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetSharedGroupData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ExecuteCloudScript(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCloudScriptUrl(ClientModels::GetCloudScriptUrlRequest& request, ProcessApiCallback<ClientModels::GetCloudScriptUrlResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCloudScriptUrl(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::RunCloudScript(ClientModels::RunCloudScriptRequest& request, ProcessApiCallback<ClientModels::RunCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::RunCloudScript(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCharacterStatistics(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GrantCharacterToUser(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCharacterData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::UpdateCharacterData(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::ValidateAmazonIAPReceipt(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AcceptTrade(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::CancelTrade(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetPlayerTrades(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::GetTradeStatus(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::OpenTrade(request, callback, errorCallback, customData);
}

void PlayFabClientApiWrapper::AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabClientApi::AttributeInstall(request, callback, errorCallback, customData);
}

