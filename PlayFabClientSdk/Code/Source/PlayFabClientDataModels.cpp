#include "StdAfx.h"
#include "PlayFabClientDataModels.h"

using namespace PlayFab;
using namespace ClientModels;
using namespace rapidjson;

AttributeInstallRequest::~AttributeInstallRequest()
{

}

void AttributeInstallRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Idfa.length() > 0) { writer.String("Idfa"); writer.String(Idfa.c_str()); }
    if (Android_Id.length() > 0) { writer.String("Android_Id"); writer.String(Android_Id.c_str()); }

    writer.EndObject();
}

bool AttributeInstallRequest::readFromValue(const rapidjson::Value& obj)
{
    const rapidjson::Value::ConstMemberIterator Idfa_member = obj.FindMember("Idfa");
    if (Idfa_member != obj.MemberEnd() && !Idfa_member->value.IsNull()) Idfa = Idfa_member->value.GetString();
    const rapidjson::Value::ConstMemberIterator Android_Id_member = obj.FindMember("Android_Id");
    if (Android_Id_member != obj.MemberEnd() && !Android_Id_member->value.IsNull()) Android_Id = Android_Id_member->value.GetString();

    return true;
}

AttributeInstallResult::~AttributeInstallResult()
{

}

void AttributeInstallResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool AttributeInstallResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LoginWithEmailAddressRequest::~LoginWithEmailAddressRequest()
{

}

void LoginWithEmailAddressRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("Email"); writer.String(Email.c_str());
    writer.String("Password"); writer.String(Password.c_str());

    writer.EndObject();
}

bool LoginWithEmailAddressRequest::readFromValue(const rapidjson::Value& obj)
{
    const rapidjson::Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const rapidjson::Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const rapidjson::Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

UserSettings::~UserSettings()
{

}

void UserSettings::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("NeedsAttribution"); writer.Bool(NeedsAttribution);

    writer.EndObject();
}

bool UserSettings::readFromValue(const rapidjson::Value& obj)
{
    const rapidjson::Value::ConstMemberIterator NeedsAttribution_member = obj.FindMember("NeedsAttribution");
    if (NeedsAttribution_member != obj.MemberEnd() && !NeedsAttribution_member->value.IsNull()) NeedsAttribution = NeedsAttribution_member->value.GetBool();

    return true;
}

LoginResult::~LoginResult()
{
    if (SettingsForUser != NULL) delete SettingsForUser;

}

void LoginResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SessionTicket.length() > 0) { writer.String("SessionTicket"); writer.String(SessionTicket.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("NewlyCreated"); writer.Bool(NewlyCreated);
    if (SettingsForUser != NULL) { writer.String("SettingsForUser"); SettingsForUser->writeJSON(writer); }
    if (LastLoginTime.notNull()) { writer.String("LastLoginTime"); writeDatetime(LastLoginTime, writer); }

    writer.EndObject();
}

bool LoginResult::readFromValue(const rapidjson::Value& obj)
{
    const rapidjson::Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
    const rapidjson::Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const rapidjson::Value::ConstMemberIterator NewlyCreated_member = obj.FindMember("NewlyCreated");
    if (NewlyCreated_member != obj.MemberEnd() && !NewlyCreated_member->value.IsNull()) NewlyCreated = NewlyCreated_member->value.GetBool();
    const rapidjson::Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
    if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);
    const rapidjson::Value::ConstMemberIterator LastLoginTime_member = obj.FindMember("LastLoginTime");
    if (LastLoginTime_member != obj.MemberEnd() && !LastLoginTime_member->value.IsNull()) LastLoginTime = readDatetime(LastLoginTime_member->value);

    return true;
}
