#pragma once

#include "PlayFabBaseModel.h"
#include "aws/core/utils/json/JsonSerializer.h"

using namespace rapidjson;

namespace PlayFab
{
    namespace MatchmakerModels
    {
        struct AuthUserRequest : public PlayFabBaseModel
        {
            Aws::String AuthorizationTicket;

            AuthUserRequest() :
                PlayFabBaseModel(),
                AuthorizationTicket()
            {}

            AuthUserRequest(const AuthUserRequest& src) :
                PlayFabBaseModel(),
                AuthorizationTicket(src.AuthorizationTicket)
            {}

            AuthUserRequest(const rapidjson::Value& obj) : AuthUserRequest()
            {
                readFromValue(obj);
            }

            ~AuthUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("AuthorizationTicket"); writer.String(AuthorizationTicket.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AuthorizationTicket_member = obj.FindMember("AuthorizationTicket");
                if (AuthorizationTicket_member != obj.MemberEnd() && !AuthorizationTicket_member->value.IsNull()) AuthorizationTicket = AuthorizationTicket_member->value.GetString();

                return true;
            }
        };

        struct AuthUserResponse : public PlayFabBaseModel
        {
            bool Authorized;
            Aws::String PlayFabId;

            AuthUserResponse() :
                PlayFabBaseModel(),
                Authorized(false),
                PlayFabId()
            {}

            AuthUserResponse(const AuthUserResponse& src) :
                PlayFabBaseModel(),
                Authorized(src.Authorized),
                PlayFabId(src.PlayFabId)
            {}

            AuthUserResponse(const rapidjson::Value& obj) : AuthUserResponse()
            {
                readFromValue(obj);
            }

            ~AuthUserResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Authorized"); writer.Bool(Authorized);
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Authorized_member = obj.FindMember("Authorized");
                if (Authorized_member != obj.MemberEnd() && !Authorized_member->value.IsNull()) Authorized = Authorized_member->value.GetBool();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            Aws::String ItemId;
            Aws::String ItemInstanceId;
            Aws::String ItemClass;
            OptionalTime PurchaseDate;
            OptionalTime Expiration;
            OptionalInt32 RemainingUses;
            OptionalInt32 UsesIncrementedBy;
            Aws::String Annotation;
            Aws::String CatalogVersion;
            Aws::String BundleParent;
            Aws::String DisplayName;
            Aws::String UnitCurrency;
            Uint32 UnitPrice;
            std::list<Aws::String> BundleContents;
            std::map<Aws::String, Aws::String> CustomData;

            ItemInstance() :
                PlayFabBaseModel(),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
                if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
                if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
                if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
                if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
                if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
                if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
                writer.String("UnitPrice"); writer.Uint(UnitPrice);
                if (!BundleContents.empty()) {
    writer.String("BundleContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!CustomData.empty()) {
    writer.String("CustomData");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
                const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
                if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
                if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
                if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
                const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
                if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
                const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct PlayerJoinedRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            Aws::String PlayFabId;

            PlayerJoinedRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerJoinedRequest(const PlayerJoinedRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            PlayerJoinedRequest(const rapidjson::Value& obj) : PlayerJoinedRequest()
            {
                readFromValue(obj);
            }

            ~PlayerJoinedRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct PlayerJoinedResponse : public PlayFabBaseModel
        {

            PlayerJoinedResponse() :
                PlayFabBaseModel()
            {}

            PlayerJoinedResponse(const PlayerJoinedResponse& src) :
                PlayFabBaseModel()
            {}

            PlayerJoinedResponse(const rapidjson::Value& obj) : PlayerJoinedResponse()
            {
                readFromValue(obj);
            }

            ~PlayerJoinedResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct PlayerLeftRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            Aws::String PlayFabId;

            PlayerLeftRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerLeftRequest(const PlayerLeftRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            PlayerLeftRequest(const rapidjson::Value& obj) : PlayerLeftRequest()
            {
                readFromValue(obj);
            }

            ~PlayerLeftRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct PlayerLeftResponse : public PlayFabBaseModel
        {

            PlayerLeftResponse() :
                PlayFabBaseModel()
            {}

            PlayerLeftResponse(const PlayerLeftResponse& src) :
                PlayFabBaseModel()
            {}

            PlayerLeftResponse(const rapidjson::Value& obj) : PlayerLeftResponse()
            {
                readFromValue(obj);
            }

            ~PlayerLeftResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case RegionUSCentral: writer.String("USCentral"); break;
            case RegionUSEast: writer.String("USEast"); break;
            case RegionEUWest: writer.String("EUWest"); break;
            case RegionSingapore: writer.String("Singapore"); break;
            case RegionJapan: writer.String("Japan"); break;
            case RegionBrazil: writer.String("Brazil"); break;
            case RegionAustralia: writer.String("Australia"); break;

            }
        }

        inline Region readRegionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, Region> _RegionMap;
            if (_RegionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _RegionMap["USCentral"] = RegionUSCentral;
                _RegionMap["USEast"] = RegionUSEast;
                _RegionMap["EUWest"] = RegionEUWest;
                _RegionMap["Singapore"] = RegionSingapore;
                _RegionMap["Japan"] = RegionJapan;
                _RegionMap["Brazil"] = RegionBrazil;
                _RegionMap["Australia"] = RegionAustralia;

            }

            auto output = _RegionMap.find(obj.GetString());
            if (output != _RegionMap.end())
                return output->second;

            return RegionUSCentral; // Basically critical fail
        }

        struct StartGameRequest : public PlayFabBaseModel
        {
            Aws::String Build;
            Region pfRegion;
            Aws::String GameMode;
            Aws::String CustomCommandLineData;
            Aws::String ExternalMatchmakerEventEndpoint;

            StartGameRequest() :
                PlayFabBaseModel(),
                Build(),
                pfRegion(),
                GameMode(),
                CustomCommandLineData(),
                ExternalMatchmakerEventEndpoint()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                Build(src.Build),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                CustomCommandLineData(src.CustomCommandLineData),
                ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint)
            {}

            StartGameRequest(const rapidjson::Value& obj) : StartGameRequest()
            {
                readFromValue(obj);
            }

            ~StartGameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Build"); writer.String(Build.c_str());
                writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
                writer.String("GameMode"); writer.String(GameMode.c_str());
                if (CustomCommandLineData.length() > 0) { writer.String("CustomCommandLineData"); writer.String(CustomCommandLineData.c_str()); }
                writer.String("ExternalMatchmakerEventEndpoint"); writer.String(ExternalMatchmakerEventEndpoint.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Build_member = obj.FindMember("Build");
                if (Build_member != obj.MemberEnd() && !Build_member->value.IsNull()) Build = Build_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
                if (CustomCommandLineData_member != obj.MemberEnd() && !CustomCommandLineData_member->value.IsNull()) CustomCommandLineData = CustomCommandLineData_member->value.GetString();
                const Value::ConstMemberIterator ExternalMatchmakerEventEndpoint_member = obj.FindMember("ExternalMatchmakerEventEndpoint");
                if (ExternalMatchmakerEventEndpoint_member != obj.MemberEnd() && !ExternalMatchmakerEventEndpoint_member->value.IsNull()) ExternalMatchmakerEventEndpoint = ExternalMatchmakerEventEndpoint_member->value.GetString();

                return true;
            }
        };

        struct StartGameResponse : public PlayFabBaseModel
        {
            Aws::String GameID;
            Aws::String ServerHostname;
            Uint32 ServerPort;

            StartGameResponse() :
                PlayFabBaseModel(),
                GameID(),
                ServerHostname(),
                ServerPort(0)
            {}

            StartGameResponse(const StartGameResponse& src) :
                PlayFabBaseModel(),
                GameID(src.GameID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort)
            {}

            StartGameResponse(const rapidjson::Value& obj) : StartGameResponse()
            {
                readFromValue(obj);
            }

            ~StartGameResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GameID.length() > 0) { writer.String("GameID"); writer.String(GameID.c_str()); }
                if (ServerHostname.length() > 0) { writer.String("ServerHostname"); writer.String(ServerHostname.c_str()); }
                writer.String("ServerPort"); writer.Uint(ServerPort);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameID_member = obj.FindMember("GameID");
                if (GameID_member != obj.MemberEnd() && !GameID_member->value.IsNull()) GameID = GameID_member->value.GetString();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();

                return true;
            }
        };

        struct UserInfoRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Int32 MinCatalogVersion;

            UserInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                MinCatalogVersion(0)
            {}

            UserInfoRequest(const UserInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                MinCatalogVersion(src.MinCatalogVersion)
            {}

            UserInfoRequest(const rapidjson::Value& obj) : UserInfoRequest()
            {
                readFromValue(obj);
            }

            ~UserInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("MinCatalogVersion"); writer.Int(MinCatalogVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator MinCatalogVersion_member = obj.FindMember("MinCatalogVersion");
                if (MinCatalogVersion_member != obj.MemberEnd() && !MinCatalogVersion_member->value.IsNull()) MinCatalogVersion = MinCatalogVersion_member->value.GetInt();

                return true;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 SecondsToRecharge;
            time_t RechargeTime;
            Int32 RechargeMax;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                SecondsToRecharge(0),
                RechargeTime(0),
                RechargeMax(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                SecondsToRecharge(src.SecondsToRecharge),
                RechargeTime(src.RechargeTime),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SecondsToRecharge"); writer.Int(SecondsToRecharge);
                writer.String("RechargeTime"); writeDatetime(RechargeTime, writer);
                writer.String("RechargeMax"); writer.Int(RechargeMax);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
                if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
                const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
                if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

                return true;
            }
        };

        struct UserInfoResponse : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String Username;
            Aws::String TitleDisplayName;
            std::list<ItemInstance> Inventory;
            std::map<Aws::String, Int32> VirtualCurrency;
            std::map<Aws::String, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;
            bool IsDeveloper;
            Aws::String SteamId;

            UserInfoResponse() :
                PlayFabBaseModel(),
                PlayFabId(),
                Username(),
                TitleDisplayName(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes(),
                IsDeveloper(false),
                SteamId()
            {}

            UserInfoResponse(const UserInfoResponse& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes),
                IsDeveloper(src.IsDeveloper),
                SteamId(src.SteamId)
            {}

            UserInfoResponse(const rapidjson::Value& obj) : UserInfoResponse()
            {
                readFromValue(obj);
            }

            ~UserInfoResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
                if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (!VirtualCurrencyRechargeTimes.empty()) {
    writer.String("VirtualCurrencyRechargeTimes");
    writer.StartObject();
    for (std::map<Aws::String, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.String("IsDeveloper"); writer.Bool(IsDeveloper);
                if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }
                const Value::ConstMemberIterator IsDeveloper_member = obj.FindMember("IsDeveloper");
                if (IsDeveloper_member != obj.MemberEnd() && !IsDeveloper_member->value.IsNull()) IsDeveloper = IsDeveloper_member->value.GetBool();
                const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
                if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();

                return true;
            }
        };


    }
}
