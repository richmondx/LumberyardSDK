#pragma once

#include "PlayFabBaseModel.h"
#include "aws\core\utils\json\JsonSerializer.h"

namespace PlayFab
{
    namespace ClientModels
    {
        template <typename BoxedType>
        class Boxed
        {
        public:
            BoxedType mValue;

            Boxed() : mValue(), mIsSet(false) {}
            Boxed(BoxedType value) : mValue(value), mIsSet(true) {}

            Boxed& operator=(BoxedType value) { mValue = value; mIsSet = true; return *this; }
            operator BoxedType() { return mValue; }

            void setNull() { mIsSet = false; }
            bool notNull() const { return mIsSet; }
            bool isNull() const { return !mIsSet; }
        private:
            bool mIsSet;
        };

        typedef Boxed<time_t> OptionalTime;

        struct AttributeInstallRequest : public PlayFabBaseModel
        {
            Aws::String Idfa;
            Aws::String Android_Id;

            AttributeInstallRequest() :
                PlayFabBaseModel(),
                Idfa(),
                Android_Id()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabBaseModel(),
                Idfa(src.Idfa),
                Android_Id(src.Android_Id)
            {}

            AttributeInstallRequest(const rapidjson::Value& obj) : AttributeInstallRequest()
            {
                readFromValue(obj);
            }

            ~AttributeInstallRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct AttributeInstallResult : public PlayFabBaseModel
        {

            AttributeInstallResult() :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const AttributeInstallResult& src) :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const rapidjson::Value& obj) : AttributeInstallResult()
            {
                readFromValue(obj);
            }

            ~AttributeInstallResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct LoginWithEmailAddressRequest : public PlayFabBaseModel
        {
            Aws::String TitleId;
            Aws::String Email;
            Aws::String Password;

            LoginWithEmailAddressRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Email(),
                Password()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Email(src.Email),
                Password(src.Password)
            {}

            LoginWithEmailAddressRequest(const rapidjson::Value& obj) : LoginWithEmailAddressRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithEmailAddressRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct UserSettings : public PlayFabBaseModel
        {
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                NeedsAttribution(false)
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                NeedsAttribution(src.NeedsAttribution)
            {}

            UserSettings(const rapidjson::Value& obj) : UserSettings()
            {
                readFromValue(obj);
            }

            ~UserSettings();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct LoginResult : public PlayFabBaseModel
        {
            Aws::String SessionTicket;
            Aws::String PlayFabId;
            bool NewlyCreated;
            UserSettings* SettingsForUser;
            OptionalTime LastLoginTime;

            LoginResult() :
                PlayFabBaseModel(),
                SessionTicket(),
                PlayFabId(),
                NewlyCreated(false),
                SettingsForUser(nullptr),
                LastLoginTime()
            {}

            LoginResult(const LoginResult& src) :
                PlayFabBaseModel(),
                SessionTicket(src.SessionTicket),
                PlayFabId(src.PlayFabId),
                NewlyCreated(src.NewlyCreated),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : nullptr),
                LastLoginTime(src.LastLoginTime)
            {}

            LoginResult(const rapidjson::Value& obj) : LoginResult()
            {
                readFromValue(obj);
            }

            ~LoginResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };
    }
}
