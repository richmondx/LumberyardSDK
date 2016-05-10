#pragma once

#include "PlayFabBaseModel.h"
#include "aws/core/utils/json/JsonSerializer.h"

using namespace rapidjson;

namespace PlayFab
{
    namespace AdminModels
    {
        struct AddNewsRequest : public PlayFabBaseModel
        {
            OptionalTime Timestamp;
            Aws::String Title;
            Aws::String Body;

            AddNewsRequest() :
                PlayFabBaseModel(),
                Timestamp(),
                Title(),
                Body()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                Title(src.Title),
                Body(src.Body)
            {}

            AddNewsRequest(const rapidjson::Value& obj) : AddNewsRequest()
            {
                readFromValue(obj);
            }

            ~AddNewsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
                writer.String("Title"); writer.String(Title.c_str());
                writer.String("Body"); writer.String(Body.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
                if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

                return true;
            }
        };

        struct AddNewsResult : public PlayFabBaseModel
        {
            Aws::String NewsId;

            AddNewsResult() :
                PlayFabBaseModel(),
                NewsId()
            {}

            AddNewsResult(const AddNewsResult& src) :
                PlayFabBaseModel(),
                NewsId(src.NewsId)
            {}

            AddNewsResult(const rapidjson::Value& obj) : AddNewsResult()
            {
                readFromValue(obj);
            }

            ~AddNewsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
                if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();

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

        struct AddServerBuildRequest : public PlayFabBaseModel
        {
            Aws::String BuildId;
            Aws::String CommandLineTemplate;
            Aws::String ExecutablePath;
            std::list<Region> ActiveRegions;
            Aws::String Comment;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                CommandLineTemplate(),
                ExecutablePath(),
                ActiveRegions(),
                Comment(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0)
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                ActiveRegions(src.ActiveRegions),
                Comment(src.Comment),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots)
            {}

            AddServerBuildRequest(const rapidjson::Value& obj) : AddServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~AddServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId"); writer.String(BuildId.c_str());
                if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
                if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
                if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();

                return true;
            }
        };

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        inline void writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case GameBuildStatusAvailable: writer.String("Available"); break;
            case GameBuildStatusValidating: writer.String("Validating"); break;
            case GameBuildStatusInvalidBuildPackage: writer.String("InvalidBuildPackage"); break;
            case GameBuildStatusProcessing: writer.String("Processing"); break;
            case GameBuildStatusFailedToProcess: writer.String("FailedToProcess"); break;

            }
        }

        inline GameBuildStatus readGameBuildStatusFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, GameBuildStatus> _GameBuildStatusMap;
            if (_GameBuildStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _GameBuildStatusMap["Available"] = GameBuildStatusAvailable;
                _GameBuildStatusMap["Validating"] = GameBuildStatusValidating;
                _GameBuildStatusMap["InvalidBuildPackage"] = GameBuildStatusInvalidBuildPackage;
                _GameBuildStatusMap["Processing"] = GameBuildStatusProcessing;
                _GameBuildStatusMap["FailedToProcess"] = GameBuildStatusFailedToProcess;

            }

            auto output = _GameBuildStatusMap.find(obj.GetString());
            if (output != _GameBuildStatusMap.end())
                return output->second;

            return GameBuildStatusAvailable; // Basically critical fail
        }

        struct AddServerBuildResult : public PlayFabBaseModel
        {
            Aws::String BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Aws::String CommandLineTemplate;
            Aws::String ExecutablePath;
            Aws::String Comment;
            time_t Timestamp;
            Aws::String TitleId;
            Boxed<GameBuildStatus> Status;

            AddServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
            {}

            AddServerBuildResult(const rapidjson::Value& obj) : AddServerBuildResult()
            {
                readFromValue(obj);
            }

            ~AddServerBuildResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
                if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
                writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
                if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.String("Timestamp"); writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

                return true;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            Aws::String CurrencyCode;
            Aws::String DisplayName;
            OptionalInt32 InitialDeposit;
            OptionalInt32 RechargeRate;
            OptionalInt32 RechargeMax;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeRate(),
                RechargeMax()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeRate(src.RechargeRate),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyData(const rapidjson::Value& obj) : VirtualCurrencyData()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyData()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str());
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (InitialDeposit.notNull()) { writer.String("InitialDeposit"); writer.Int(InitialDeposit); }
                if (RechargeRate.notNull()) { writer.String("RechargeRate"); writer.Int(RechargeRate); }
                if (RechargeMax.notNull()) { writer.String("RechargeMax"); writer.Int(RechargeMax); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator InitialDeposit_member = obj.FindMember("InitialDeposit");
                if (InitialDeposit_member != obj.MemberEnd() && !InitialDeposit_member->value.IsNull()) InitialDeposit = InitialDeposit_member->value.GetInt();
                const Value::ConstMemberIterator RechargeRate_member = obj.FindMember("RechargeRate");
                if (RechargeRate_member != obj.MemberEnd() && !RechargeRate_member->value.IsNull()) RechargeRate = RechargeRate_member->value.GetInt();
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

                return true;
            }
        };

        struct AddVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            AddVirtualCurrencyTypesRequest() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            AddVirtualCurrencyTypesRequest(const AddVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            AddVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : AddVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~AddVirtualCurrencyTypesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("VirtualCurrencies");
    writer.StartArray();
    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
    if (VirtualCurrencies_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencies_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
        }
    }

                return true;
            }
        };

        struct BlankResult : public PlayFabBaseModel
        {

            BlankResult() :
                PlayFabBaseModel()
            {}

            BlankResult(const BlankResult& src) :
                PlayFabBaseModel()
            {}

            BlankResult(const rapidjson::Value& obj) : BlankResult()
            {
                readFromValue(obj);
            }

            ~BlankResult()
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

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            OptionalUint32 UsageCount;
            OptionalUint32 UsagePeriod;
            Aws::String UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemConsumableInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UsageCount.notNull()) { writer.String("UsageCount"); writer.Uint(UsageCount); }
                if (UsagePeriod.notNull()) { writer.String("UsagePeriod"); writer.Uint(UsagePeriod); }
                if (UsagePeriodGroup.length() > 0) { writer.String("UsagePeriodGroup"); writer.String(UsagePeriodGroup.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UsageCount_member = obj.FindMember("UsageCount");
                if (UsageCount_member != obj.MemberEnd() && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriod_member = obj.FindMember("UsagePeriod");
                if (UsagePeriod_member != obj.MemberEnd() && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
                if (UsagePeriodGroup_member != obj.MemberEnd() && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

                return true;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            Aws::String KeyItemId;
            std::list<Aws::String> ItemContents;
            std::list<Aws::String> ResultTableContents;
            std::map<Aws::String, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                KeyItemId(),
                ItemContents(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                KeyItemId(src.KeyItemId),
                ItemContents(src.ItemContents),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemContainerInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KeyItemId.length() > 0) { writer.String("KeyItemId"); writer.String(KeyItemId.c_str()); }
                if (!ItemContents.empty()) {
    writer.String("ItemContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!ResultTableContents.empty()) {
    writer.String("ResultTableContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!VirtualCurrencyContents.empty()) {
    writer.String("VirtualCurrencyContents");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
                if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
    if (ItemContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator ResultTableContents_member = obj.FindMember("ResultTableContents");
    if (ResultTableContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ResultTableContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ResultTableContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
    if (VirtualCurrencyContents_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyContents_member->value.MemberBegin(); iter != VirtualCurrencyContents_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyContents[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            std::list<Aws::String> BundledItems;
            std::list<Aws::String> BundledResultTables;
            std::map<Aws::String, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemBundleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BundledItems.empty()) {
    writer.String("BundledItems");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!BundledResultTables.empty()) {
    writer.String("BundledResultTables");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!BundledVirtualCurrencies.empty()) {
    writer.String("BundledVirtualCurrencies");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BundledItems_member = obj.FindMember("BundledItems");
    if (BundledItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledItems.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator BundledResultTables_member = obj.FindMember("BundledResultTables");
    if (BundledResultTables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledResultTables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledResultTables.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
    if (BundledVirtualCurrencies_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = BundledVirtualCurrencies_member->value.MemberBegin(); iter != BundledVirtualCurrencies_member->value.MemberEnd(); ++iter) {
            BundledVirtualCurrencies[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            Aws::String ItemId;
            Aws::String ItemClass;
            Aws::String CatalogVersion;
            Aws::String DisplayName;
            Aws::String Description;
            std::map<Aws::String, Uint32> VirtualCurrencyPrices;
            std::map<Aws::String, Uint32> RealCurrencyPrices;
            std::list<Aws::String> Tags;
            Aws::String CustomData;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            bool IsStackable;
            bool IsTradable;
            Aws::String ItemImageUrl;

            CatalogItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                CatalogVersion(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                Tags(),
                CustomData(),
                Consumable(nullptr),
                Container(nullptr),
                Bundle(nullptr),
                CanBecomeCharacter(false),
                IsStackable(false),
                IsTradable(false),
                ItemImageUrl()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                CatalogVersion(src.CatalogVersion),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                CustomData(src.CustomData),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : nullptr),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : nullptr),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : nullptr),
                CanBecomeCharacter(src.CanBecomeCharacter),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemImageUrl(src.ItemImageUrl)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem()
            {
                if (Consumable != nullptr) delete Consumable;
                if (Container != nullptr) delete Container;
                if (Bundle != nullptr) delete Bundle;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId"); writer.String(ItemId.c_str());
                if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
                if (!VirtualCurrencyPrices.empty()) {
    writer.String("VirtualCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!RealCurrencyPrices.empty()) {
    writer.String("RealCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
                if (Consumable != nullptr) { writer.String("Consumable"); Consumable->writeJSON(writer); }
                if (Container != nullptr) { writer.String("Container"); Container->writeJSON(writer); }
                if (Bundle != nullptr) { writer.String("Bundle"); Bundle->writeJSON(writer); }
                writer.String("CanBecomeCharacter"); writer.Bool(CanBecomeCharacter);
                writer.String("IsStackable"); writer.Bool(IsStackable);
                writer.String("IsTradable"); writer.Bool(IsTradable);
                if (ItemImageUrl.length() > 0) { writer.String("ItemImageUrl"); writer.String(ItemImageUrl.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
                const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
                if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
                const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
                if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
                const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
                if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
                const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
                if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
                const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
                if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
                const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
                if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
                const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
                if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();

                return true;
            }
        };

        struct CloudScriptFile : public PlayFabBaseModel
        {
            Aws::String Filename;
            Aws::String FileContents;

            CloudScriptFile() :
                PlayFabBaseModel(),
                Filename(),
                FileContents()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                Filename(src.Filename),
                FileContents(src.FileContents)
            {}

            CloudScriptFile(const rapidjson::Value& obj) : CloudScriptFile()
            {
                readFromValue(obj);
            }

            ~CloudScriptFile()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Filename"); writer.String(Filename.c_str());
                writer.String("FileContents"); writer.String(FileContents.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Filename_member = obj.FindMember("Filename");
                if (Filename_member != obj.MemberEnd() && !Filename_member->value.IsNull()) Filename = Filename_member->value.GetString();
                const Value::ConstMemberIterator FileContents_member = obj.FindMember("FileContents");
                if (FileContents_member != obj.MemberEnd() && !FileContents_member->value.IsNull()) FileContents = FileContents_member->value.GetString();

                return true;
            }
        };

        struct CloudScriptVersionStatus : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 PublishedRevision;
            Int32 LatestRevision;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                Version(0),
                PublishedRevision(0),
                LatestRevision(0)
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                PublishedRevision(src.PublishedRevision),
                LatestRevision(src.LatestRevision)
            {}

            CloudScriptVersionStatus(const rapidjson::Value& obj) : CloudScriptVersionStatus()
            {
                readFromValue(obj);
            }

            ~CloudScriptVersionStatus()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version"); writer.Int(Version);
                writer.String("PublishedRevision"); writer.Int(PublishedRevision);
                writer.String("LatestRevision"); writer.Int(LatestRevision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator PublishedRevision_member = obj.FindMember("PublishedRevision");
                if (PublishedRevision_member != obj.MemberEnd() && !PublishedRevision_member->value.IsNull()) PublishedRevision = PublishedRevision_member->value.GetInt();
                const Value::ConstMemberIterator LatestRevision_member = obj.FindMember("LatestRevision");
                if (LatestRevision_member != obj.MemberEnd() && !LatestRevision_member->value.IsNull()) LatestRevision = LatestRevision_member->value.GetInt();

                return true;
            }
        };

        struct ContentInfo : public PlayFabBaseModel
        {
            Aws::String Key;
            Uint32 Size;
            time_t LastModified;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                Size(0),
                LastModified(0)
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Size(src.Size),
                LastModified(src.LastModified)
            {}

            ContentInfo(const rapidjson::Value& obj) : ContentInfo()
            {
                readFromValue(obj);
            }

            ~ContentInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
                writer.String("Size"); writer.Uint(Size);
                writer.String("LastModified"); writeDatetime(LastModified, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetUint();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);

                return true;
            }
        };

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        inline void writeStatisticResetIntervalOptionEnumJSON(StatisticResetIntervalOption enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticResetIntervalOptionNever: writer.String("Never"); break;
            case StatisticResetIntervalOptionHour: writer.String("Hour"); break;
            case StatisticResetIntervalOptionDay: writer.String("Day"); break;
            case StatisticResetIntervalOptionWeek: writer.String("Week"); break;
            case StatisticResetIntervalOptionMonth: writer.String("Month"); break;

            }
        }

        inline StatisticResetIntervalOption readStatisticResetIntervalOptionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, StatisticResetIntervalOption> _StatisticResetIntervalOptionMap;
            if (_StatisticResetIntervalOptionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticResetIntervalOptionMap["Never"] = StatisticResetIntervalOptionNever;
                _StatisticResetIntervalOptionMap["Hour"] = StatisticResetIntervalOptionHour;
                _StatisticResetIntervalOptionMap["Day"] = StatisticResetIntervalOptionDay;
                _StatisticResetIntervalOptionMap["Week"] = StatisticResetIntervalOptionWeek;
                _StatisticResetIntervalOptionMap["Month"] = StatisticResetIntervalOptionMonth;

            }

            auto output = _StatisticResetIntervalOptionMap.find(obj.GetString());
            if (output != _StatisticResetIntervalOptionMap.end())
                return output->second;

            return StatisticResetIntervalOptionNever; // Basically critical fail
        }

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void writeStatisticAggregationMethodEnumJSON(StatisticAggregationMethod enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticAggregationMethodLast: writer.String("Last"); break;
            case StatisticAggregationMethodMin: writer.String("Min"); break;
            case StatisticAggregationMethodMax: writer.String("Max"); break;
            case StatisticAggregationMethodSum: writer.String("Sum"); break;

            }
        }

        inline StatisticAggregationMethod readStatisticAggregationMethodFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, StatisticAggregationMethod> _StatisticAggregationMethodMap;
            if (_StatisticAggregationMethodMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticAggregationMethodMap["Last"] = StatisticAggregationMethodLast;
                _StatisticAggregationMethodMap["Min"] = StatisticAggregationMethodMin;
                _StatisticAggregationMethodMap["Max"] = StatisticAggregationMethodMax;
                _StatisticAggregationMethodMap["Sum"] = StatisticAggregationMethodSum;

            }

            auto output = _StatisticAggregationMethodMap.find(obj.GetString());
            if (output != _StatisticAggregationMethodMap.end())
                return output->second;

            return StatisticAggregationMethodLast; // Basically critical fail
        }

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            CreatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
                if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Uint32 CurrentVersion;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                StatisticName(),
                CurrentVersion(0),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CurrentVersion(src.CurrentVersion),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            PlayerStatisticDefinition(const rapidjson::Value& obj) : PlayerStatisticDefinition()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticDefinition()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.String("CurrentVersion"); writer.Uint(CurrentVersion);
                if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
                if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator CurrentVersion_member = obj.FindMember("CurrentVersion");
                if (CurrentVersion_member != obj.MemberEnd() && !CurrentVersion_member->value.IsNull()) CurrentVersion = CurrentVersion_member->value.GetUint();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(nullptr)
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : nullptr)
            {}

            CreatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionResult()
            {
                if (Statistic != nullptr) delete Statistic;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Statistic != nullptr) { writer.String("Statistic"); Statistic->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
                if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

                return true;
            }
        };

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CurrencyAED: writer.String("AED"); break;
            case CurrencyAFN: writer.String("AFN"); break;
            case CurrencyALL: writer.String("ALL"); break;
            case CurrencyAMD: writer.String("AMD"); break;
            case CurrencyANG: writer.String("ANG"); break;
            case CurrencyAOA: writer.String("AOA"); break;
            case CurrencyARS: writer.String("ARS"); break;
            case CurrencyAUD: writer.String("AUD"); break;
            case CurrencyAWG: writer.String("AWG"); break;
            case CurrencyAZN: writer.String("AZN"); break;
            case CurrencyBAM: writer.String("BAM"); break;
            case CurrencyBBD: writer.String("BBD"); break;
            case CurrencyBDT: writer.String("BDT"); break;
            case CurrencyBGN: writer.String("BGN"); break;
            case CurrencyBHD: writer.String("BHD"); break;
            case CurrencyBIF: writer.String("BIF"); break;
            case CurrencyBMD: writer.String("BMD"); break;
            case CurrencyBND: writer.String("BND"); break;
            case CurrencyBOB: writer.String("BOB"); break;
            case CurrencyBRL: writer.String("BRL"); break;
            case CurrencyBSD: writer.String("BSD"); break;
            case CurrencyBTN: writer.String("BTN"); break;
            case CurrencyBWP: writer.String("BWP"); break;
            case CurrencyBYR: writer.String("BYR"); break;
            case CurrencyBZD: writer.String("BZD"); break;
            case CurrencyCAD: writer.String("CAD"); break;
            case CurrencyCDF: writer.String("CDF"); break;
            case CurrencyCHF: writer.String("CHF"); break;
            case CurrencyCLP: writer.String("CLP"); break;
            case CurrencyCNY: writer.String("CNY"); break;
            case CurrencyCOP: writer.String("COP"); break;
            case CurrencyCRC: writer.String("CRC"); break;
            case CurrencyCUC: writer.String("CUC"); break;
            case CurrencyCUP: writer.String("CUP"); break;
            case CurrencyCVE: writer.String("CVE"); break;
            case CurrencyCZK: writer.String("CZK"); break;
            case CurrencyDJF: writer.String("DJF"); break;
            case CurrencyDKK: writer.String("DKK"); break;
            case CurrencyDOP: writer.String("DOP"); break;
            case CurrencyDZD: writer.String("DZD"); break;
            case CurrencyEGP: writer.String("EGP"); break;
            case CurrencyERN: writer.String("ERN"); break;
            case CurrencyETB: writer.String("ETB"); break;
            case CurrencyEUR: writer.String("EUR"); break;
            case CurrencyFJD: writer.String("FJD"); break;
            case CurrencyFKP: writer.String("FKP"); break;
            case CurrencyGBP: writer.String("GBP"); break;
            case CurrencyGEL: writer.String("GEL"); break;
            case CurrencyGGP: writer.String("GGP"); break;
            case CurrencyGHS: writer.String("GHS"); break;
            case CurrencyGIP: writer.String("GIP"); break;
            case CurrencyGMD: writer.String("GMD"); break;
            case CurrencyGNF: writer.String("GNF"); break;
            case CurrencyGTQ: writer.String("GTQ"); break;
            case CurrencyGYD: writer.String("GYD"); break;
            case CurrencyHKD: writer.String("HKD"); break;
            case CurrencyHNL: writer.String("HNL"); break;
            case CurrencyHRK: writer.String("HRK"); break;
            case CurrencyHTG: writer.String("HTG"); break;
            case CurrencyHUF: writer.String("HUF"); break;
            case CurrencyIDR: writer.String("IDR"); break;
            case CurrencyILS: writer.String("ILS"); break;
            case CurrencyIMP: writer.String("IMP"); break;
            case CurrencyINR: writer.String("INR"); break;
            case CurrencyIQD: writer.String("IQD"); break;
            case CurrencyIRR: writer.String("IRR"); break;
            case CurrencyISK: writer.String("ISK"); break;
            case CurrencyJEP: writer.String("JEP"); break;
            case CurrencyJMD: writer.String("JMD"); break;
            case CurrencyJOD: writer.String("JOD"); break;
            case CurrencyJPY: writer.String("JPY"); break;
            case CurrencyKES: writer.String("KES"); break;
            case CurrencyKGS: writer.String("KGS"); break;
            case CurrencyKHR: writer.String("KHR"); break;
            case CurrencyKMF: writer.String("KMF"); break;
            case CurrencyKPW: writer.String("KPW"); break;
            case CurrencyKRW: writer.String("KRW"); break;
            case CurrencyKWD: writer.String("KWD"); break;
            case CurrencyKYD: writer.String("KYD"); break;
            case CurrencyKZT: writer.String("KZT"); break;
            case CurrencyLAK: writer.String("LAK"); break;
            case CurrencyLBP: writer.String("LBP"); break;
            case CurrencyLKR: writer.String("LKR"); break;
            case CurrencyLRD: writer.String("LRD"); break;
            case CurrencyLSL: writer.String("LSL"); break;
            case CurrencyLYD: writer.String("LYD"); break;
            case CurrencyMAD: writer.String("MAD"); break;
            case CurrencyMDL: writer.String("MDL"); break;
            case CurrencyMGA: writer.String("MGA"); break;
            case CurrencyMKD: writer.String("MKD"); break;
            case CurrencyMMK: writer.String("MMK"); break;
            case CurrencyMNT: writer.String("MNT"); break;
            case CurrencyMOP: writer.String("MOP"); break;
            case CurrencyMRO: writer.String("MRO"); break;
            case CurrencyMUR: writer.String("MUR"); break;
            case CurrencyMVR: writer.String("MVR"); break;
            case CurrencyMWK: writer.String("MWK"); break;
            case CurrencyMXN: writer.String("MXN"); break;
            case CurrencyMYR: writer.String("MYR"); break;
            case CurrencyMZN: writer.String("MZN"); break;
            case CurrencyNAD: writer.String("NAD"); break;
            case CurrencyNGN: writer.String("NGN"); break;
            case CurrencyNIO: writer.String("NIO"); break;
            case CurrencyNOK: writer.String("NOK"); break;
            case CurrencyNPR: writer.String("NPR"); break;
            case CurrencyNZD: writer.String("NZD"); break;
            case CurrencyOMR: writer.String("OMR"); break;
            case CurrencyPAB: writer.String("PAB"); break;
            case CurrencyPEN: writer.String("PEN"); break;
            case CurrencyPGK: writer.String("PGK"); break;
            case CurrencyPHP: writer.String("PHP"); break;
            case CurrencyPKR: writer.String("PKR"); break;
            case CurrencyPLN: writer.String("PLN"); break;
            case CurrencyPYG: writer.String("PYG"); break;
            case CurrencyQAR: writer.String("QAR"); break;
            case CurrencyRON: writer.String("RON"); break;
            case CurrencyRSD: writer.String("RSD"); break;
            case CurrencyRUB: writer.String("RUB"); break;
            case CurrencyRWF: writer.String("RWF"); break;
            case CurrencySAR: writer.String("SAR"); break;
            case CurrencySBD: writer.String("SBD"); break;
            case CurrencySCR: writer.String("SCR"); break;
            case CurrencySDG: writer.String("SDG"); break;
            case CurrencySEK: writer.String("SEK"); break;
            case CurrencySGD: writer.String("SGD"); break;
            case CurrencySHP: writer.String("SHP"); break;
            case CurrencySLL: writer.String("SLL"); break;
            case CurrencySOS: writer.String("SOS"); break;
            case CurrencySPL: writer.String("SPL"); break;
            case CurrencySRD: writer.String("SRD"); break;
            case CurrencySTD: writer.String("STD"); break;
            case CurrencySVC: writer.String("SVC"); break;
            case CurrencySYP: writer.String("SYP"); break;
            case CurrencySZL: writer.String("SZL"); break;
            case CurrencyTHB: writer.String("THB"); break;
            case CurrencyTJS: writer.String("TJS"); break;
            case CurrencyTMT: writer.String("TMT"); break;
            case CurrencyTND: writer.String("TND"); break;
            case CurrencyTOP: writer.String("TOP"); break;
            case CurrencyTRY: writer.String("TRY"); break;
            case CurrencyTTD: writer.String("TTD"); break;
            case CurrencyTVD: writer.String("TVD"); break;
            case CurrencyTWD: writer.String("TWD"); break;
            case CurrencyTZS: writer.String("TZS"); break;
            case CurrencyUAH: writer.String("UAH"); break;
            case CurrencyUGX: writer.String("UGX"); break;
            case CurrencyUSD: writer.String("USD"); break;
            case CurrencyUYU: writer.String("UYU"); break;
            case CurrencyUZS: writer.String("UZS"); break;
            case CurrencyVEF: writer.String("VEF"); break;
            case CurrencyVND: writer.String("VND"); break;
            case CurrencyVUV: writer.String("VUV"); break;
            case CurrencyWST: writer.String("WST"); break;
            case CurrencyXAF: writer.String("XAF"); break;
            case CurrencyXCD: writer.String("XCD"); break;
            case CurrencyXDR: writer.String("XDR"); break;
            case CurrencyXOF: writer.String("XOF"); break;
            case CurrencyXPF: writer.String("XPF"); break;
            case CurrencyYER: writer.String("YER"); break;
            case CurrencyZAR: writer.String("ZAR"); break;
            case CurrencyZMW: writer.String("ZMW"); break;
            case CurrencyZWD: writer.String("ZWD"); break;

            }
        }

        inline Currency readCurrencyFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, Currency> _CurrencyMap;
            if (_CurrencyMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CurrencyMap["AED"] = CurrencyAED;
                _CurrencyMap["AFN"] = CurrencyAFN;
                _CurrencyMap["ALL"] = CurrencyALL;
                _CurrencyMap["AMD"] = CurrencyAMD;
                _CurrencyMap["ANG"] = CurrencyANG;
                _CurrencyMap["AOA"] = CurrencyAOA;
                _CurrencyMap["ARS"] = CurrencyARS;
                _CurrencyMap["AUD"] = CurrencyAUD;
                _CurrencyMap["AWG"] = CurrencyAWG;
                _CurrencyMap["AZN"] = CurrencyAZN;
                _CurrencyMap["BAM"] = CurrencyBAM;
                _CurrencyMap["BBD"] = CurrencyBBD;
                _CurrencyMap["BDT"] = CurrencyBDT;
                _CurrencyMap["BGN"] = CurrencyBGN;
                _CurrencyMap["BHD"] = CurrencyBHD;
                _CurrencyMap["BIF"] = CurrencyBIF;
                _CurrencyMap["BMD"] = CurrencyBMD;
                _CurrencyMap["BND"] = CurrencyBND;
                _CurrencyMap["BOB"] = CurrencyBOB;
                _CurrencyMap["BRL"] = CurrencyBRL;
                _CurrencyMap["BSD"] = CurrencyBSD;
                _CurrencyMap["BTN"] = CurrencyBTN;
                _CurrencyMap["BWP"] = CurrencyBWP;
                _CurrencyMap["BYR"] = CurrencyBYR;
                _CurrencyMap["BZD"] = CurrencyBZD;
                _CurrencyMap["CAD"] = CurrencyCAD;
                _CurrencyMap["CDF"] = CurrencyCDF;
                _CurrencyMap["CHF"] = CurrencyCHF;
                _CurrencyMap["CLP"] = CurrencyCLP;
                _CurrencyMap["CNY"] = CurrencyCNY;
                _CurrencyMap["COP"] = CurrencyCOP;
                _CurrencyMap["CRC"] = CurrencyCRC;
                _CurrencyMap["CUC"] = CurrencyCUC;
                _CurrencyMap["CUP"] = CurrencyCUP;
                _CurrencyMap["CVE"] = CurrencyCVE;
                _CurrencyMap["CZK"] = CurrencyCZK;
                _CurrencyMap["DJF"] = CurrencyDJF;
                _CurrencyMap["DKK"] = CurrencyDKK;
                _CurrencyMap["DOP"] = CurrencyDOP;
                _CurrencyMap["DZD"] = CurrencyDZD;
                _CurrencyMap["EGP"] = CurrencyEGP;
                _CurrencyMap["ERN"] = CurrencyERN;
                _CurrencyMap["ETB"] = CurrencyETB;
                _CurrencyMap["EUR"] = CurrencyEUR;
                _CurrencyMap["FJD"] = CurrencyFJD;
                _CurrencyMap["FKP"] = CurrencyFKP;
                _CurrencyMap["GBP"] = CurrencyGBP;
                _CurrencyMap["GEL"] = CurrencyGEL;
                _CurrencyMap["GGP"] = CurrencyGGP;
                _CurrencyMap["GHS"] = CurrencyGHS;
                _CurrencyMap["GIP"] = CurrencyGIP;
                _CurrencyMap["GMD"] = CurrencyGMD;
                _CurrencyMap["GNF"] = CurrencyGNF;
                _CurrencyMap["GTQ"] = CurrencyGTQ;
                _CurrencyMap["GYD"] = CurrencyGYD;
                _CurrencyMap["HKD"] = CurrencyHKD;
                _CurrencyMap["HNL"] = CurrencyHNL;
                _CurrencyMap["HRK"] = CurrencyHRK;
                _CurrencyMap["HTG"] = CurrencyHTG;
                _CurrencyMap["HUF"] = CurrencyHUF;
                _CurrencyMap["IDR"] = CurrencyIDR;
                _CurrencyMap["ILS"] = CurrencyILS;
                _CurrencyMap["IMP"] = CurrencyIMP;
                _CurrencyMap["INR"] = CurrencyINR;
                _CurrencyMap["IQD"] = CurrencyIQD;
                _CurrencyMap["IRR"] = CurrencyIRR;
                _CurrencyMap["ISK"] = CurrencyISK;
                _CurrencyMap["JEP"] = CurrencyJEP;
                _CurrencyMap["JMD"] = CurrencyJMD;
                _CurrencyMap["JOD"] = CurrencyJOD;
                _CurrencyMap["JPY"] = CurrencyJPY;
                _CurrencyMap["KES"] = CurrencyKES;
                _CurrencyMap["KGS"] = CurrencyKGS;
                _CurrencyMap["KHR"] = CurrencyKHR;
                _CurrencyMap["KMF"] = CurrencyKMF;
                _CurrencyMap["KPW"] = CurrencyKPW;
                _CurrencyMap["KRW"] = CurrencyKRW;
                _CurrencyMap["KWD"] = CurrencyKWD;
                _CurrencyMap["KYD"] = CurrencyKYD;
                _CurrencyMap["KZT"] = CurrencyKZT;
                _CurrencyMap["LAK"] = CurrencyLAK;
                _CurrencyMap["LBP"] = CurrencyLBP;
                _CurrencyMap["LKR"] = CurrencyLKR;
                _CurrencyMap["LRD"] = CurrencyLRD;
                _CurrencyMap["LSL"] = CurrencyLSL;
                _CurrencyMap["LYD"] = CurrencyLYD;
                _CurrencyMap["MAD"] = CurrencyMAD;
                _CurrencyMap["MDL"] = CurrencyMDL;
                _CurrencyMap["MGA"] = CurrencyMGA;
                _CurrencyMap["MKD"] = CurrencyMKD;
                _CurrencyMap["MMK"] = CurrencyMMK;
                _CurrencyMap["MNT"] = CurrencyMNT;
                _CurrencyMap["MOP"] = CurrencyMOP;
                _CurrencyMap["MRO"] = CurrencyMRO;
                _CurrencyMap["MUR"] = CurrencyMUR;
                _CurrencyMap["MVR"] = CurrencyMVR;
                _CurrencyMap["MWK"] = CurrencyMWK;
                _CurrencyMap["MXN"] = CurrencyMXN;
                _CurrencyMap["MYR"] = CurrencyMYR;
                _CurrencyMap["MZN"] = CurrencyMZN;
                _CurrencyMap["NAD"] = CurrencyNAD;
                _CurrencyMap["NGN"] = CurrencyNGN;
                _CurrencyMap["NIO"] = CurrencyNIO;
                _CurrencyMap["NOK"] = CurrencyNOK;
                _CurrencyMap["NPR"] = CurrencyNPR;
                _CurrencyMap["NZD"] = CurrencyNZD;
                _CurrencyMap["OMR"] = CurrencyOMR;
                _CurrencyMap["PAB"] = CurrencyPAB;
                _CurrencyMap["PEN"] = CurrencyPEN;
                _CurrencyMap["PGK"] = CurrencyPGK;
                _CurrencyMap["PHP"] = CurrencyPHP;
                _CurrencyMap["PKR"] = CurrencyPKR;
                _CurrencyMap["PLN"] = CurrencyPLN;
                _CurrencyMap["PYG"] = CurrencyPYG;
                _CurrencyMap["QAR"] = CurrencyQAR;
                _CurrencyMap["RON"] = CurrencyRON;
                _CurrencyMap["RSD"] = CurrencyRSD;
                _CurrencyMap["RUB"] = CurrencyRUB;
                _CurrencyMap["RWF"] = CurrencyRWF;
                _CurrencyMap["SAR"] = CurrencySAR;
                _CurrencyMap["SBD"] = CurrencySBD;
                _CurrencyMap["SCR"] = CurrencySCR;
                _CurrencyMap["SDG"] = CurrencySDG;
                _CurrencyMap["SEK"] = CurrencySEK;
                _CurrencyMap["SGD"] = CurrencySGD;
                _CurrencyMap["SHP"] = CurrencySHP;
                _CurrencyMap["SLL"] = CurrencySLL;
                _CurrencyMap["SOS"] = CurrencySOS;
                _CurrencyMap["SPL"] = CurrencySPL;
                _CurrencyMap["SRD"] = CurrencySRD;
                _CurrencyMap["STD"] = CurrencySTD;
                _CurrencyMap["SVC"] = CurrencySVC;
                _CurrencyMap["SYP"] = CurrencySYP;
                _CurrencyMap["SZL"] = CurrencySZL;
                _CurrencyMap["THB"] = CurrencyTHB;
                _CurrencyMap["TJS"] = CurrencyTJS;
                _CurrencyMap["TMT"] = CurrencyTMT;
                _CurrencyMap["TND"] = CurrencyTND;
                _CurrencyMap["TOP"] = CurrencyTOP;
                _CurrencyMap["TRY"] = CurrencyTRY;
                _CurrencyMap["TTD"] = CurrencyTTD;
                _CurrencyMap["TVD"] = CurrencyTVD;
                _CurrencyMap["TWD"] = CurrencyTWD;
                _CurrencyMap["TZS"] = CurrencyTZS;
                _CurrencyMap["UAH"] = CurrencyUAH;
                _CurrencyMap["UGX"] = CurrencyUGX;
                _CurrencyMap["USD"] = CurrencyUSD;
                _CurrencyMap["UYU"] = CurrencyUYU;
                _CurrencyMap["UZS"] = CurrencyUZS;
                _CurrencyMap["VEF"] = CurrencyVEF;
                _CurrencyMap["VND"] = CurrencyVND;
                _CurrencyMap["VUV"] = CurrencyVUV;
                _CurrencyMap["WST"] = CurrencyWST;
                _CurrencyMap["XAF"] = CurrencyXAF;
                _CurrencyMap["XCD"] = CurrencyXCD;
                _CurrencyMap["XDR"] = CurrencyXDR;
                _CurrencyMap["XOF"] = CurrencyXOF;
                _CurrencyMap["XPF"] = CurrencyXPF;
                _CurrencyMap["YER"] = CurrencyYER;
                _CurrencyMap["ZAR"] = CurrencyZAR;
                _CurrencyMap["ZMW"] = CurrencyZMW;
                _CurrencyMap["ZWD"] = CurrencyZWD;

            }

            auto output = _CurrencyMap.find(obj.GetString());
            if (output != _CurrencyMap.end())
                return output->second;

            return CurrencyAED; // Basically critical fail
        }

        struct DeleteContentRequest : public PlayFabBaseModel
        {
            Aws::String Key;

            DeleteContentRequest() :
                PlayFabBaseModel(),
                Key()
            {}

            DeleteContentRequest(const DeleteContentRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key)
            {}

            DeleteContentRequest(const rapidjson::Value& obj) : DeleteContentRequest()
            {
                readFromValue(obj);
            }

            ~DeleteContentRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();

                return true;
            }
        };

        struct DeleteUsersRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> PlayFabIds;
            Aws::String TitleId;

            DeleteUsersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            DeleteUsersRequest(const rapidjson::Value& obj) : DeleteUsersRequest()
            {
                readFromValue(obj);
            }

            ~DeleteUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.String("TitleId"); writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct DeleteUsersResult : public PlayFabBaseModel
        {

            DeleteUsersResult() :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const rapidjson::Value& obj) : DeleteUsersResult()
            {
                readFromValue(obj);
            }

            ~DeleteUsersResult()
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

        struct GameModeInfo : public PlayFabBaseModel
        {
            Aws::String Gamemode;
            Uint32 MinPlayerCount;
            Uint32 MaxPlayerCount;
            OptionalBool StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MinPlayerCount(0),
                MaxPlayerCount(0),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MinPlayerCount(src.MinPlayerCount),
                MaxPlayerCount(src.MaxPlayerCount),
                StartOpen(src.StartOpen)
            {}

            GameModeInfo(const rapidjson::Value& obj) : GameModeInfo()
            {
                readFromValue(obj);
            }

            ~GameModeInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Gamemode"); writer.String(Gamemode.c_str());
                writer.String("MinPlayerCount"); writer.Uint(MinPlayerCount);
                writer.String("MaxPlayerCount"); writer.Uint(MaxPlayerCount);
                if (StartOpen.notNull()) { writer.String("StartOpen"); writer.Bool(StartOpen); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Gamemode_member = obj.FindMember("Gamemode");
                if (Gamemode_member != obj.MemberEnd() && !Gamemode_member->value.IsNull()) Gamemode = Gamemode_member->value.GetString();
                const Value::ConstMemberIterator MinPlayerCount_member = obj.FindMember("MinPlayerCount");
                if (MinPlayerCount_member != obj.MemberEnd() && !MinPlayerCount_member->value.IsNull()) MinPlayerCount = MinPlayerCount_member->value.GetUint();
                const Value::ConstMemberIterator MaxPlayerCount_member = obj.FindMember("MaxPlayerCount");
                if (MaxPlayerCount_member != obj.MemberEnd() && !MaxPlayerCount_member->value.IsNull()) MaxPlayerCount = MaxPlayerCount_member->value.GetUint();
                const Value::ConstMemberIterator StartOpen_member = obj.FindMember("StartOpen");
                if (StartOpen_member != obj.MemberEnd() && !StartOpen_member->value.IsNull()) StartOpen = StartOpen_member->value.GetBool();

                return true;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct GetCatalogItemsResult : public PlayFabBaseModel
        {
            std::list<CatalogItem> Catalog;

            GetCatalogItemsResult() :
                PlayFabBaseModel(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog)
            {}

            GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Catalog.empty()) {
    writer.String("Catalog");
    writer.StartArray();
    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Catalog_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Catalog.push_back(CatalogItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetCloudScriptRevisionRequest : public PlayFabBaseModel
        {
            OptionalInt32 Version;
            OptionalInt32 Revision;

            GetCloudScriptRevisionRequest() :
                PlayFabBaseModel(),
                Version(),
                Revision()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            GetCloudScriptRevisionRequest(const rapidjson::Value& obj) : GetCloudScriptRevisionRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
                if (Revision.notNull()) { writer.String("Revision"); writer.Int(Revision); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct GetCloudScriptRevisionResult : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;

            GetCloudScriptRevisionResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0),
                CreatedAt(0),
                Files(),
                IsPublished(false)
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished)
            {}

            GetCloudScriptRevisionResult(const rapidjson::Value& obj) : GetCloudScriptRevisionResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version"); writer.Int(Version);
                writer.String("Revision"); writer.Int(Revision);
                writer.String("CreatedAt"); writeDatetime(CreatedAt, writer);
                if (!Files.empty()) {
    writer.String("Files");
    writer.StartArray();
    for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.String("IsPublished"); writer.Bool(IsPublished);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
                const Value::ConstMemberIterator CreatedAt_member = obj.FindMember("CreatedAt");
                if (CreatedAt_member != obj.MemberEnd() && !CreatedAt_member->value.IsNull()) CreatedAt = readDatetime(CreatedAt_member->value);
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Files_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Files.push_back(CloudScriptFile(memberList[i]));
        }
    }
                const Value::ConstMemberIterator IsPublished_member = obj.FindMember("IsPublished");
                if (IsPublished_member != obj.MemberEnd() && !IsPublished_member->value.IsNull()) IsPublished = IsPublished_member->value.GetBool();

                return true;
            }
        };

        struct GetCloudScriptVersionsRequest : public PlayFabBaseModel
        {

            GetCloudScriptVersionsRequest() :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const GetCloudScriptVersionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const rapidjson::Value& obj) : GetCloudScriptVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsRequest()
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

        struct GetCloudScriptVersionsResult : public PlayFabBaseModel
        {
            std::list<CloudScriptVersionStatus> Versions;

            GetCloudScriptVersionsResult() :
                PlayFabBaseModel(),
                Versions()
            {}

            GetCloudScriptVersionsResult(const GetCloudScriptVersionsResult& src) :
                PlayFabBaseModel(),
                Versions(src.Versions)
            {}

            GetCloudScriptVersionsResult(const rapidjson::Value& obj) : GetCloudScriptVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Versions.empty()) {
    writer.String("Versions");
    writer.StartArray();
    for (std::list<CloudScriptVersionStatus>::iterator iter = Versions.begin(); iter != Versions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Versions_member = obj.FindMember("Versions");
    if (Versions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Versions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Versions.push_back(CloudScriptVersionStatus(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetContentListRequest : public PlayFabBaseModel
        {
            Aws::String Prefix;

            GetContentListRequest() :
                PlayFabBaseModel(),
                Prefix()
            {}

            GetContentListRequest(const GetContentListRequest& src) :
                PlayFabBaseModel(),
                Prefix(src.Prefix)
            {}

            GetContentListRequest(const rapidjson::Value& obj) : GetContentListRequest()
            {
                readFromValue(obj);
            }

            ~GetContentListRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Prefix.length() > 0) { writer.String("Prefix"); writer.String(Prefix.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Prefix_member = obj.FindMember("Prefix");
                if (Prefix_member != obj.MemberEnd() && !Prefix_member->value.IsNull()) Prefix = Prefix_member->value.GetString();

                return true;
            }
        };

        struct GetContentListResult : public PlayFabBaseModel
        {
            Int32 ItemCount;
            Uint32 TotalSize;
            std::list<ContentInfo> Contents;

            GetContentListResult() :
                PlayFabBaseModel(),
                ItemCount(0),
                TotalSize(0),
                Contents()
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabBaseModel(),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize),
                Contents(src.Contents)
            {}

            GetContentListResult(const rapidjson::Value& obj) : GetContentListResult()
            {
                readFromValue(obj);
            }

            ~GetContentListResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemCount"); writer.Int(ItemCount);
                writer.String("TotalSize"); writer.Uint(TotalSize);
                if (!Contents.empty()) {
    writer.String("Contents");
    writer.StartArray();
    for (std::list<ContentInfo>::iterator iter = Contents.begin(); iter != Contents.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemCount_member = obj.FindMember("ItemCount");
                if (ItemCount_member != obj.MemberEnd() && !ItemCount_member->value.IsNull()) ItemCount = ItemCount_member->value.GetInt();
                const Value::ConstMemberIterator TotalSize_member = obj.FindMember("TotalSize");
                if (TotalSize_member != obj.MemberEnd() && !TotalSize_member->value.IsNull()) TotalSize = TotalSize_member->value.GetUint();
                const Value::ConstMemberIterator Contents_member = obj.FindMember("Contents");
    if (Contents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Contents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Contents.push_back(ContentInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetContentUploadUrlRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String ContentType;

            GetContentUploadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                ContentType()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                ContentType(src.ContentType)
            {}

            GetContentUploadUrlRequest(const rapidjson::Value& obj) : GetContentUploadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (ContentType.length() > 0) { writer.String("ContentType"); writer.String(ContentType.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator ContentType_member = obj.FindMember("ContentType");
                if (ContentType_member != obj.MemberEnd() && !ContentType_member->value.IsNull()) ContentType = ContentType_member->value.GetString();

                return true;
            }
        };

        struct GetContentUploadUrlResult : public PlayFabBaseModel
        {
            Aws::String URL;

            GetContentUploadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentUploadUrlResult(const GetContentUploadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentUploadUrlResult(const rapidjson::Value& obj) : GetContentUploadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
                if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

                return true;
            }
        };

        struct GetDataReportRequest : public PlayFabBaseModel
        {
            Aws::String ReportName;
            Int32 Year;
            Int32 Month;
            Int32 Day;

            GetDataReportRequest() :
                PlayFabBaseModel(),
                ReportName(),
                Year(0),
                Month(0),
                Day(0)
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabBaseModel(),
                ReportName(src.ReportName),
                Year(src.Year),
                Month(src.Month),
                Day(src.Day)
            {}

            GetDataReportRequest(const rapidjson::Value& obj) : GetDataReportRequest()
            {
                readFromValue(obj);
            }

            ~GetDataReportRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReportName"); writer.String(ReportName.c_str());
                writer.String("Year"); writer.Int(Year);
                writer.String("Month"); writer.Int(Month);
                writer.String("Day"); writer.Int(Day);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReportName_member = obj.FindMember("ReportName");
                if (ReportName_member != obj.MemberEnd() && !ReportName_member->value.IsNull()) ReportName = ReportName_member->value.GetString();
                const Value::ConstMemberIterator Year_member = obj.FindMember("Year");
                if (Year_member != obj.MemberEnd() && !Year_member->value.IsNull()) Year = Year_member->value.GetInt();
                const Value::ConstMemberIterator Month_member = obj.FindMember("Month");
                if (Month_member != obj.MemberEnd() && !Month_member->value.IsNull()) Month = Month_member->value.GetInt();
                const Value::ConstMemberIterator Day_member = obj.FindMember("Day");
                if (Day_member != obj.MemberEnd() && !Day_member->value.IsNull()) Day = Day_member->value.GetInt();

                return true;
            }
        };

        struct GetDataReportResult : public PlayFabBaseModel
        {
            Aws::String DownloadUrl;

            GetDataReportResult() :
                PlayFabBaseModel(),
                DownloadUrl()
            {}

            GetDataReportResult(const GetDataReportResult& src) :
                PlayFabBaseModel(),
                DownloadUrl(src.DownloadUrl)
            {}

            GetDataReportResult(const rapidjson::Value& obj) : GetDataReportResult()
            {
                readFromValue(obj);
            }

            ~GetDataReportResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DownloadUrl.length() > 0) { writer.String("DownloadUrl"); writer.String(DownloadUrl.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
                if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameInfoRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;

            GetMatchmakerGameInfoRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            GetMatchmakerGameInfoRequest(const GetMatchmakerGameInfoRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            GetMatchmakerGameInfoRequest(const rapidjson::Value& obj) : GetMatchmakerGameInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameInfoResult : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            Aws::String TitleId;
            time_t StartTime;
            OptionalTime EndTime;
            Aws::String Mode;
            Aws::String BuildVersion;
            Boxed<Region> pfRegion;
            std::list<Aws::String> Players;
            Aws::String ServerAddress;
            Uint32 ServerPort;

            GetMatchmakerGameInfoResult() :
                PlayFabBaseModel(),
                LobbyId(),
                TitleId(),
                StartTime(0),
                EndTime(),
                Mode(),
                BuildVersion(),
                pfRegion(),
                Players(),
                ServerAddress(),
                ServerPort(0)
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                TitleId(src.TitleId),
                StartTime(src.StartTime),
                EndTime(src.EndTime),
                Mode(src.Mode),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                Players(src.Players),
                ServerAddress(src.ServerAddress),
                ServerPort(src.ServerPort)
            {}

            GetMatchmakerGameInfoResult(const rapidjson::Value& obj) : GetMatchmakerGameInfoResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                writer.String("StartTime"); writeDatetime(StartTime, writer);
                if (EndTime.notNull()) { writer.String("EndTime"); writeDatetime(EndTime, writer); }
                if (Mode.length() > 0) { writer.String("Mode"); writer.String(Mode.c_str()); }
                if (BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
                if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
                if (!Players.empty()) {
    writer.String("Players");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Players.begin(); iter != Players.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (ServerAddress.length() > 0) { writer.String("ServerAddress"); writer.String(ServerAddress.c_str()); }
                writer.String("ServerPort"); writer.Uint(ServerPort);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator StartTime_member = obj.FindMember("StartTime");
                if (StartTime_member != obj.MemberEnd() && !StartTime_member->value.IsNull()) StartTime = readDatetime(StartTime_member->value);
                const Value::ConstMemberIterator EndTime_member = obj.FindMember("EndTime");
                if (EndTime_member != obj.MemberEnd() && !EndTime_member->value.IsNull()) EndTime = readDatetime(EndTime_member->value);
                const Value::ConstMemberIterator Mode_member = obj.FindMember("Mode");
                if (Mode_member != obj.MemberEnd() && !Mode_member->value.IsNull()) Mode = Mode_member->value.GetString();
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator Players_member = obj.FindMember("Players");
    if (Players_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Players_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Players.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator ServerAddress_member = obj.FindMember("ServerAddress");
                if (ServerAddress_member != obj.MemberEnd() && !ServerAddress_member->value.IsNull()) ServerAddress = ServerAddress_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();

                return true;
            }
        };

        struct GetMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            Aws::String BuildVersion;

            GetMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion()
            {}

            GetMatchmakerGameModesRequest(const GetMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion)
            {}

            GetMatchmakerGameModesRequest(const rapidjson::Value& obj) : GetMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion"); writer.String(BuildVersion.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameModesResult : public PlayFabBaseModel
        {
            std::list<GameModeInfo> GameModes;

            GetMatchmakerGameModesResult() :
                PlayFabBaseModel(),
                GameModes()
            {}

            GetMatchmakerGameModesResult(const GetMatchmakerGameModesResult& src) :
                PlayFabBaseModel(),
                GameModes(src.GameModes)
            {}

            GetMatchmakerGameModesResult(const rapidjson::Value& obj) : GetMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!GameModes.empty()) {
    writer.String("GameModes");
    writer.StartArray();
    for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
    if (GameModes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameModes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameModes.push_back(GameModeInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabBaseModel
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsRequest()
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

        struct GetPlayerStatisticDefinitionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticDefinition> Statistics;

            GetPlayerStatisticDefinitionsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticDefinitionsResult(const GetPlayerStatisticDefinitionsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticDefinitionsResult(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<PlayerStatisticDefinition>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(PlayerStatisticDefinition(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        inline void writeStatisticVersionArchivalStatusEnumJSON(StatisticVersionArchivalStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticVersionArchivalStatusNotScheduled: writer.String("NotScheduled"); break;
            case StatisticVersionArchivalStatusScheduled: writer.String("Scheduled"); break;
            case StatisticVersionArchivalStatusQueued: writer.String("Queued"); break;
            case StatisticVersionArchivalStatusInProgress: writer.String("InProgress"); break;
            case StatisticVersionArchivalStatusComplete: writer.String("Complete"); break;

            }
        }

        inline StatisticVersionArchivalStatus readStatisticVersionArchivalStatusFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, StatisticVersionArchivalStatus> _StatisticVersionArchivalStatusMap;
            if (_StatisticVersionArchivalStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticVersionArchivalStatusMap["NotScheduled"] = StatisticVersionArchivalStatusNotScheduled;
                _StatisticVersionArchivalStatusMap["Scheduled"] = StatisticVersionArchivalStatusScheduled;
                _StatisticVersionArchivalStatusMap["Queued"] = StatisticVersionArchivalStatusQueued;
                _StatisticVersionArchivalStatusMap["InProgress"] = StatisticVersionArchivalStatusInProgress;
                _StatisticVersionArchivalStatusMap["Complete"] = StatisticVersionArchivalStatusComplete;

            }

            auto output = _StatisticVersionArchivalStatusMap.find(obj.GetString());
            if (output != _StatisticVersionArchivalStatusMap.end())
                return output->second;

            return StatisticVersionArchivalStatusNotScheduled; // Basically critical fail
        }

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Uint32 Version;
            OptionalTime ScheduledActivationTime;
            time_t ActivationTime;
            OptionalTime ScheduledDeactivationTime;
            OptionalTime DeactivationTime;
            Boxed<StatisticVersionArchivalStatus> ArchivalStatus;
            Aws::String ArchiveDownloadUrl;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0),
                ScheduledActivationTime(),
                ActivationTime(0),
                ScheduledDeactivationTime(),
                DeactivationTime(),
                ArchivalStatus(),
                ArchiveDownloadUrl()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ActivationTime(src.ActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                DeactivationTime(src.DeactivationTime),
                ArchivalStatus(src.ArchivalStatus),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.String("Version"); writer.Uint(Version);
                if (ScheduledActivationTime.notNull()) { writer.String("ScheduledActivationTime"); writeDatetime(ScheduledActivationTime, writer); }
                writer.String("ActivationTime"); writeDatetime(ActivationTime, writer);
                if (ScheduledDeactivationTime.notNull()) { writer.String("ScheduledDeactivationTime"); writeDatetime(ScheduledDeactivationTime, writer); }
                if (DeactivationTime.notNull()) { writer.String("DeactivationTime"); writeDatetime(DeactivationTime, writer); }
                if (ArchivalStatus.notNull()) { writer.String("ArchivalStatus"); writeStatisticVersionArchivalStatusEnumJSON(ArchivalStatus, writer); }
                if (ArchiveDownloadUrl.length() > 0) { writer.String("ArchiveDownloadUrl"); writer.String(ArchiveDownloadUrl.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
                const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
                if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
                const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
                if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
                const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
                if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
                const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
                if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);
                const Value::ConstMemberIterator ArchivalStatus_member = obj.FindMember("ArchivalStatus");
                if (ArchivalStatus_member != obj.MemberEnd() && !ArchivalStatus_member->value.IsNull()) ArchivalStatus = readStatisticVersionArchivalStatusFromValue(ArchivalStatus_member->value);
                const Value::ConstMemberIterator ArchiveDownloadUrl_member = obj.FindMember("ArchiveDownloadUrl");
                if (ArchiveDownloadUrl_member != obj.MemberEnd() && !ArchiveDownloadUrl_member->value.IsNull()) ArchiveDownloadUrl = ArchiveDownloadUrl_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!StatisticVersions.empty()) {
    writer.String("StatisticVersions");
    writer.StartArray();
    for (std::list<PlayerStatisticVersion>::iterator iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersions_member = obj.FindMember("StatisticVersions");
    if (StatisticVersions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticVersions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticVersions.push_back(PlayerStatisticVersion(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> Keys;

            GetPublisherDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetPublisherDataResult : public PlayFabBaseModel
        {
            std::map<Aws::String, Aws::String> Data;

            GetPublisherDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct GetRandomResultTablesRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;

            GetRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetRandomResultTablesRequest(const rapidjson::Value& obj) : GetRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
            case ResultTableNodeTypeTableId: writer.String("TableId"); break;

            }
        }

        inline ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, ResultTableNodeType> _ResultTableNodeTypeMap;
            if (_ResultTableNodeTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ResultTableNodeTypeMap["ItemId"] = ResultTableNodeTypeItemId;
                _ResultTableNodeTypeMap["TableId"] = ResultTableNodeTypeTableId;

            }

            auto output = _ResultTableNodeTypeMap.find(obj.GetString());
            if (output != _ResultTableNodeTypeMap.end())
                return output->second;

            return ResultTableNodeTypeItemId; // Basically critical fail
        }

        struct ResultTableNode : public PlayFabBaseModel
        {
            ResultTableNodeType ResultItemType;
            Aws::String ResultItem;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItemType(),
                ResultItem(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItemType(src.ResultItemType),
                ResultItem(src.ResultItem),
                Weight(src.Weight)
            {}

            ResultTableNode(const rapidjson::Value& obj) : ResultTableNode()
            {
                readFromValue(obj);
            }

            ~ResultTableNode()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ResultItemType"); writeResultTableNodeTypeEnumJSON(ResultItemType, writer);
                writer.String("ResultItem"); writer.String(ResultItem.c_str());
                writer.String("Weight"); writer.Int(Weight);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ResultItemType_member = obj.FindMember("ResultItemType");
                if (ResultItemType_member != obj.MemberEnd() && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
                const Value::ConstMemberIterator ResultItem_member = obj.FindMember("ResultItem");
                if (ResultItem_member != obj.MemberEnd() && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
                const Value::ConstMemberIterator Weight_member = obj.FindMember("Weight");
                if (Weight_member != obj.MemberEnd() && !Weight_member->value.IsNull()) Weight = Weight_member->value.GetInt();

                return true;
            }
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableId(),
                Nodes()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId),
                Nodes(src.Nodes)
            {}

            RandomResultTableListing(const rapidjson::Value& obj) : RandomResultTableListing()
            {
                readFromValue(obj);
            }

            ~RandomResultTableListing()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("TableId"); writer.String(TableId.c_str());
                writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetRandomResultTablesResult : public PlayFabBaseModel
        {
            std::map<Aws::String, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabBaseModel(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabBaseModel(),
                Tables(src.Tables)
            {}

            GetRandomResultTablesResult(const rapidjson::Value& obj) : GetRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Tables.empty()) {
    writer.String("Tables");
    writer.StartObject();
    for (std::map<Aws::String, RandomResultTableListing>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
    if (Tables_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tables_member->value.MemberBegin(); iter != Tables_member->value.MemberEnd(); ++iter) {
            Tables[iter->name.GetString()] = RandomResultTableListing(iter->value);
        }
    }

                return true;
            }
        };

        struct GetServerBuildInfoRequest : public PlayFabBaseModel
        {
            Aws::String BuildId;

            GetServerBuildInfoRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildInfoRequest(const GetServerBuildInfoRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildInfoRequest(const rapidjson::Value& obj) : GetServerBuildInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId"); writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildInfoResult : public PlayFabBaseModel
        {
            Aws::String BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Aws::String Comment;
            time_t Timestamp;
            Aws::String TitleId;
            Boxed<GameBuildStatus> Status;
            Aws::String ErrorMessage;

            GetServerBuildInfoResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status(),
                ErrorMessage()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status),
                ErrorMessage(src.ErrorMessage)
            {}

            GetServerBuildInfoResult(const rapidjson::Value& obj) : GetServerBuildInfoResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
                if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
                writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.String("Timestamp"); writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
                if (ErrorMessage.length() > 0) { writer.String("ErrorMessage"); writer.String(ErrorMessage.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
                if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildUploadURLRequest : public PlayFabBaseModel
        {
            Aws::String BuildId;

            GetServerBuildUploadURLRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildUploadURLRequest(const GetServerBuildUploadURLRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildUploadURLRequest(const rapidjson::Value& obj) : GetServerBuildUploadURLRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId"); writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildUploadURLResult : public PlayFabBaseModel
        {
            Aws::String URL;

            GetServerBuildUploadURLResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetServerBuildUploadURLResult(const GetServerBuildUploadURLResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetServerBuildUploadURLResult(const rapidjson::Value& obj) : GetServerBuildUploadURLResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
                if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

                return true;
            }
        };

        struct GetStoreItemsRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String StoreId;

            GetStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            GetStoreItemsRequest(const rapidjson::Value& obj) : GetStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("StoreId"); writer.String(StoreId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

                return true;
            }
        };

        struct StoreItem : public PlayFabBaseModel
        {
            Aws::String ItemId;
            std::map<Aws::String, Uint32> VirtualCurrencyPrices;
            std::map<Aws::String, Uint32> RealCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices)
            {}

            StoreItem(const rapidjson::Value& obj) : StoreItem()
            {
                readFromValue(obj);
            }

            ~StoreItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId"); writer.String(ItemId.c_str());
                if (!VirtualCurrencyPrices.empty()) {
    writer.String("VirtualCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!RealCurrencyPrices.empty()) {
    writer.String("RealCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct GetStoreItemsResult : public PlayFabBaseModel
        {
            std::list<StoreItem> Store;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                Store()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                Store(src.Store)
            {}

            GetStoreItemsResult(const rapidjson::Value& obj) : GetStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Store.empty()) {
    writer.String("Store");
    writer.StartArray();
    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
    if (Store_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Store_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Store.push_back(StoreItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> Keys;

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetTitleDataResult : public PlayFabBaseModel
        {
            std::map<Aws::String, Aws::String> Data;

            GetTitleDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~GetTitleDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<Aws::String> Keys;
            OptionalInt32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Keys(src.Keys),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
            {
                readFromValue(obj);
            }

            ~GetUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Int(IfChangedFromDataVersion); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetInt();

                return true;
            }
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserDataPermissionPrivate: writer.String("Private"); break;
            case UserDataPermissionPublic: writer.String("Public"); break;

            }
        }

        inline UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, UserDataPermission> _UserDataPermissionMap;
            if (_UserDataPermissionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserDataPermissionMap["Private"] = UserDataPermissionPrivate;
                _UserDataPermissionMap["Public"] = UserDataPermissionPublic;

            }

            auto output = _UserDataPermissionMap.find(obj.GetString());
            if (output != _UserDataPermissionMap.end())
                return output->second;

            return UserDataPermissionPrivate; // Basically critical fail
        }

        struct UserDataRecord : public PlayFabBaseModel
        {
            Aws::String Value;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            UserDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdated(0),
                Permission()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
            {
                readFromValue(obj);
            }

            ~UserDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct GetUserDataResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Uint32 DataVersion;
            std::map<Aws::String, UserDataRecord> Data;

            GetUserDataResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                DataVersion(0),
                Data()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DataVersion(src.DataVersion),
                Data(src.Data)
            {}

            GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
            {
                readFromValue(obj);
            }

            ~GetUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.String("DataVersion"); writer.Uint(DataVersion);
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }

                return true;
            }
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
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

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<ItemInstance> Inventory;
            std::map<Aws::String, Int32> VirtualCurrency;
            std::map<Aws::String, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
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
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

                return true;
            }
        };

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            bool Result;
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

            GrantedItemInstance() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Result(false),
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

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Result(src.Result),
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

            GrantedItemInstance(const rapidjson::Value& obj) : GrantedItemInstance()
            {
                readFromValue(obj);
            }

            ~GrantedItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("Result"); writer.Bool(Result);
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
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
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

        struct ItemGrant : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String ItemId;
            Aws::String Annotation;
            Aws::String CharacterId;

            ItemGrant() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemId(),
                Annotation(),
                CharacterId()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemId(src.ItemId),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId)
            {}

            ItemGrant(const rapidjson::Value& obj) : ItemGrant()
            {
                readFromValue(obj);
            }

            ~ItemGrant()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("ItemId"); writer.String(ItemId.c_str());
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GrantItemsToUsersRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemGrants(src.ItemGrants)
            {}

            GrantItemsToUsersRequest(const rapidjson::Value& obj) : GrantItemsToUsersRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("ItemGrants");
    writer.StartArray();
    for (std::list<ItemGrant>::iterator iter = ItemGrants.begin(); iter != ItemGrants.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator ItemGrants_member = obj.FindMember("ItemGrants");
    if (ItemGrants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrants.push_back(ItemGrant(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GrantItemsToUsersResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToUsersResult(const rapidjson::Value& obj) : GrantItemsToUsersResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!ItemGrantResults.empty()) {
    writer.String("ItemGrantResults");
    writer.StartArray();
    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrantResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct IncrementPlayerStatisticVersionRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            IncrementPlayerStatisticVersionRequest(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionRequest()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct IncrementPlayerStatisticVersionResult : public PlayFabBaseModel
        {
            PlayerStatisticVersion* StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabBaseModel(),
                StatisticVersion(nullptr)
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabBaseModel(),
                StatisticVersion(src.StatisticVersion ? new PlayerStatisticVersion(*src.StatisticVersion) : nullptr)
            {}

            IncrementPlayerStatisticVersionResult(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionResult()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionResult()
            {
                if (StatisticVersion != nullptr) delete StatisticVersion;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticVersion != nullptr) { writer.String("StatisticVersion"); StatisticVersion->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
                if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = new PlayerStatisticVersion(StatisticVersion_member->value);

                return true;
            }
        };

        struct ListBuildsRequest : public PlayFabBaseModel
        {

            ListBuildsRequest() :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const ListBuildsRequest& src) :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const rapidjson::Value& obj) : ListBuildsRequest()
            {
                readFromValue(obj);
            }

            ~ListBuildsRequest()
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

        struct ListBuildsResult : public PlayFabBaseModel
        {
            std::list<GetServerBuildInfoResult> Builds;

            ListBuildsResult() :
                PlayFabBaseModel(),
                Builds()
            {}

            ListBuildsResult(const ListBuildsResult& src) :
                PlayFabBaseModel(),
                Builds(src.Builds)
            {}

            ListBuildsResult(const rapidjson::Value& obj) : ListBuildsResult()
            {
                readFromValue(obj);
            }

            ~ListBuildsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Builds.empty()) {
    writer.String("Builds");
    writer.StartArray();
    for (std::list<GetServerBuildInfoResult>::iterator iter = Builds.begin(); iter != Builds.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Builds_member = obj.FindMember("Builds");
    if (Builds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Builds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Builds.push_back(GetServerBuildInfoResult(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ListVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {

            ListVirtualCurrencyTypesRequest() :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const ListVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : ListVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesRequest()
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

        struct ListVirtualCurrencyTypesResult : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            ListVirtualCurrencyTypesResult() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            ListVirtualCurrencyTypesResult(const ListVirtualCurrencyTypesResult& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ListVirtualCurrencyTypesResult(const rapidjson::Value& obj) : ListVirtualCurrencyTypesResult()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!VirtualCurrencies.empty()) {
    writer.String("VirtualCurrencies");
    writer.StartArray();
    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
    if (VirtualCurrencies_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencies_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
        }
    }

                return true;
            }
        };

        struct LookupUserAccountInfoRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String Email;
            Aws::String Username;
            Aws::String TitleDisplayName;

            LookupUserAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Email(),
                Username(),
                TitleDisplayName()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Email(src.Email),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName)
            {}

            LookupUserAccountInfoRequest(const rapidjson::Value& obj) : LookupUserAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();

                return true;
            }
        };

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse
        };

        inline void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserOriginationOrganic: writer.String("Organic"); break;
            case UserOriginationSteam: writer.String("Steam"); break;
            case UserOriginationGoogle: writer.String("Google"); break;
            case UserOriginationAmazon: writer.String("Amazon"); break;
            case UserOriginationFacebook: writer.String("Facebook"); break;
            case UserOriginationKongregate: writer.String("Kongregate"); break;
            case UserOriginationGamersFirst: writer.String("GamersFirst"); break;
            case UserOriginationUnknown: writer.String("Unknown"); break;
            case UserOriginationIOS: writer.String("IOS"); break;
            case UserOriginationLoadTest: writer.String("LoadTest"); break;
            case UserOriginationAndroid: writer.String("Android"); break;
            case UserOriginationPSN: writer.String("PSN"); break;
            case UserOriginationGameCenter: writer.String("GameCenter"); break;
            case UserOriginationCustomId: writer.String("CustomId"); break;
            case UserOriginationXboxLive: writer.String("XboxLive"); break;
            case UserOriginationParse: writer.String("Parse"); break;

            }
        }

        inline UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, UserOrigination> _UserOriginationMap;
            if (_UserOriginationMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserOriginationMap["Organic"] = UserOriginationOrganic;
                _UserOriginationMap["Steam"] = UserOriginationSteam;
                _UserOriginationMap["Google"] = UserOriginationGoogle;
                _UserOriginationMap["Amazon"] = UserOriginationAmazon;
                _UserOriginationMap["Facebook"] = UserOriginationFacebook;
                _UserOriginationMap["Kongregate"] = UserOriginationKongregate;
                _UserOriginationMap["GamersFirst"] = UserOriginationGamersFirst;
                _UserOriginationMap["Unknown"] = UserOriginationUnknown;
                _UserOriginationMap["IOS"] = UserOriginationIOS;
                _UserOriginationMap["LoadTest"] = UserOriginationLoadTest;
                _UserOriginationMap["Android"] = UserOriginationAndroid;
                _UserOriginationMap["PSN"] = UserOriginationPSN;
                _UserOriginationMap["GameCenter"] = UserOriginationGameCenter;
                _UserOriginationMap["CustomId"] = UserOriginationCustomId;
                _UserOriginationMap["XboxLive"] = UserOriginationXboxLive;
                _UserOriginationMap["Parse"] = UserOriginationParse;

            }

            auto output = _UserOriginationMap.find(obj.GetString());
            if (output != _UserOriginationMap.end())
                return output->second;

            return UserOriginationOrganic; // Basically critical fail
        }

        struct UserTitleInfo : public PlayFabBaseModel
        {
            Aws::String DisplayName;
            Boxed<UserOrigination> Origination;
            time_t Created;
            OptionalTime LastLogin;
            OptionalTime FirstLogin;
            OptionalBool isBanned;

            UserTitleInfo() :
                PlayFabBaseModel(),
                DisplayName(),
                Origination(),
                Created(0),
                LastLogin(),
                FirstLogin(),
                isBanned()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (Origination.notNull()) { writer.String("Origination"); writeUserOriginationEnumJSON(Origination, writer); }
                writer.String("Created"); writeDatetime(Created, writer);
                if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
                if (FirstLogin.notNull()) { writer.String("FirstLogin"); writeDatetime(FirstLogin, writer); }
                if (isBanned.notNull()) { writer.String("isBanned"); writer.Bool(isBanned); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
                if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
                const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
                if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();

                return true;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            Aws::String Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserPrivateAccountInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            Aws::String FacebookId;
            Aws::String FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
                if (FullName.length() > 0) { writer.String("FullName"); writer.String(FullName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator FullName_member = obj.FindMember("FullName");
                if (FullName_member != obj.MemberEnd() && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

                return true;
            }
        };

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TitleActivationStatusNone: writer.String("None"); break;
            case TitleActivationStatusActivatedTitleKey: writer.String("ActivatedTitleKey"); break;
            case TitleActivationStatusPendingSteam: writer.String("PendingSteam"); break;
            case TitleActivationStatusActivatedSteam: writer.String("ActivatedSteam"); break;
            case TitleActivationStatusRevokedSteam: writer.String("RevokedSteam"); break;

            }
        }

        inline TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, TitleActivationStatus> _TitleActivationStatusMap;
            if (_TitleActivationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TitleActivationStatusMap["None"] = TitleActivationStatusNone;
                _TitleActivationStatusMap["ActivatedTitleKey"] = TitleActivationStatusActivatedTitleKey;
                _TitleActivationStatusMap["PendingSteam"] = TitleActivationStatusPendingSteam;
                _TitleActivationStatusMap["ActivatedSteam"] = TitleActivationStatusActivatedSteam;
                _TitleActivationStatusMap["RevokedSteam"] = TitleActivationStatusRevokedSteam;

            }

            auto output = _TitleActivationStatusMap.find(obj.GetString());
            if (output != _TitleActivationStatusMap.end())
                return output->second;

            return TitleActivationStatusNone; // Basically critical fail
        }

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Aws::String SteamId;
            Aws::String SteamCountry;
            Boxed<Currency> SteamCurrency;
            Boxed<TitleActivationStatus> SteamActivationStatus;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamId(),
                SteamCountry(),
                SteamCurrency(),
                SteamActivationStatus()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamId(src.SteamId),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamActivationStatus(src.SteamActivationStatus)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
                if (SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
                if (SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
                if (SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
                if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
                const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
                if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
                const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
                if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
                const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
                if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);

                return true;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            Aws::String GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
            {
                readFromValue(obj);
            }

            ~UserGameCenterInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

                return true;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            Aws::String IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (IosDeviceId.length() > 0) { writer.String("IosDeviceId"); writer.String(IosDeviceId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IosDeviceId_member = obj.FindMember("IosDeviceId");
                if (IosDeviceId_member != obj.MemberEnd() && !IosDeviceId_member->value.IsNull()) IosDeviceId = IosDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            Aws::String AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) { writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            Aws::String KongregateId;
            Aws::String KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) { writer.String("KongregateId"); writer.String(KongregateId.c_str()); }
                if (KongregateName.length() > 0) { writer.String("KongregateName"); writer.String(KongregateName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator KongregateName_member = obj.FindMember("KongregateName");
                if (KongregateName_member != obj.MemberEnd() && !KongregateName_member->value.IsNull()) KongregateName = KongregateName_member->value.GetString();

                return true;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            Aws::String PsnAccountId;
            Aws::String PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PsnAccountId.length() > 0) { writer.String("PsnAccountId"); writer.String(PsnAccountId.c_str()); }
                if (PsnOnlineId.length() > 0) { writer.String("PsnOnlineId"); writer.String(PsnOnlineId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PsnAccountId_member = obj.FindMember("PsnAccountId");
                if (PsnAccountId_member != obj.MemberEnd() && !PsnAccountId_member->value.IsNull()) PsnAccountId = PsnAccountId_member->value.GetString();
                const Value::ConstMemberIterator PsnOnlineId_member = obj.FindMember("PsnOnlineId");
                if (PsnOnlineId_member != obj.MemberEnd() && !PsnOnlineId_member->value.IsNull()) PsnOnlineId = PsnOnlineId_member->value.GetString();

                return true;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            Aws::String GoogleId;
            Aws::String GoogleEmail;
            Aws::String GoogleLocale;
            Aws::String GoogleGender;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleId(),
                GoogleEmail(),
                GoogleLocale(),
                GoogleGender()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                GoogleEmail(src.GoogleEmail),
                GoogleLocale(src.GoogleLocale),
                GoogleGender(src.GoogleGender)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GoogleId.length() > 0) { writer.String("GoogleId"); writer.String(GoogleId.c_str()); }
                if (GoogleEmail.length() > 0) { writer.String("GoogleEmail"); writer.String(GoogleEmail.c_str()); }
                if (GoogleLocale.length() > 0) { writer.String("GoogleLocale"); writer.String(GoogleLocale.c_str()); }
                if (GoogleGender.length() > 0) { writer.String("GoogleGender"); writer.String(GoogleGender.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
                if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
                const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
                if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();
                const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
                if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();

                return true;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            Aws::String XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (XboxUserId.length() > 0) { writer.String("XboxUserId"); writer.String(XboxUserId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator XboxUserId_member = obj.FindMember("XboxUserId");
                if (XboxUserId_member != obj.MemberEnd() && !XboxUserId_member->value.IsNull()) XboxUserId = XboxUserId_member->value.GetString();

                return true;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            Aws::String CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CustomId.length() > 0) { writer.String("CustomId"); writer.String(CustomId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            time_t Created;
            Aws::String Username;
            UserTitleInfo* TitleInfo;
            UserPrivateAccountInfo* PrivateInfo;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            UserPsnInfo* PsnInfo;
            UserGoogleInfo* GoogleInfo;
            UserXboxInfo* XboxInfo;
            UserCustomIdInfo* CustomIdInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                Created(0),
                Username(),
                TitleInfo(nullptr),
                PrivateInfo(nullptr),
                FacebookInfo(nullptr),
                SteamInfo(nullptr),
                GameCenterInfo(nullptr),
                IosDeviceInfo(nullptr),
                AndroidDeviceInfo(nullptr),
                KongregateInfo(nullptr),
                PsnInfo(nullptr),
                GoogleInfo(nullptr),
                XboxInfo(nullptr),
                CustomIdInfo(nullptr)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Created(src.Created),
                Username(src.Username),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : nullptr),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : nullptr),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : nullptr),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : nullptr),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : nullptr),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : nullptr),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : nullptr),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : nullptr),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : nullptr)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo()
            {
                if (TitleInfo != nullptr) delete TitleInfo;
                if (PrivateInfo != nullptr) delete PrivateInfo;
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (IosDeviceInfo != nullptr) delete IosDeviceInfo;
                if (AndroidDeviceInfo != nullptr) delete AndroidDeviceInfo;
                if (KongregateInfo != nullptr) delete KongregateInfo;
                if (PsnInfo != nullptr) delete PsnInfo;
                if (GoogleInfo != nullptr) delete GoogleInfo;
                if (XboxInfo != nullptr) delete XboxInfo;
                if (CustomIdInfo != nullptr) delete CustomIdInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.String("Created"); writeDatetime(Created, writer);
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (TitleInfo != nullptr) { writer.String("TitleInfo"); TitleInfo->writeJSON(writer); }
                if (PrivateInfo != nullptr) { writer.String("PrivateInfo"); PrivateInfo->writeJSON(writer); }
                if (FacebookInfo != nullptr) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
                if (SteamInfo != nullptr) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
                if (GameCenterInfo != nullptr) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
                if (IosDeviceInfo != nullptr) { writer.String("IosDeviceInfo"); IosDeviceInfo->writeJSON(writer); }
                if (AndroidDeviceInfo != nullptr) { writer.String("AndroidDeviceInfo"); AndroidDeviceInfo->writeJSON(writer); }
                if (KongregateInfo != nullptr) { writer.String("KongregateInfo"); KongregateInfo->writeJSON(writer); }
                if (PsnInfo != nullptr) { writer.String("PsnInfo"); PsnInfo->writeJSON(writer); }
                if (GoogleInfo != nullptr) { writer.String("GoogleInfo"); GoogleInfo->writeJSON(writer); }
                if (XboxInfo != nullptr) { writer.String("XboxInfo"); XboxInfo->writeJSON(writer); }
                if (CustomIdInfo != nullptr) { writer.String("CustomIdInfo"); CustomIdInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
                if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
                const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
                if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
                if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
                const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
                if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
                const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
                if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
                const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
                if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
                const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
                if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
                const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
                if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);
                const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
                if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);

                return true;
            }
        };

        struct LookupUserAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabBaseModel(),
                UserInfo(nullptr)
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : nullptr)
            {}

            LookupUserAccountInfoResult(const rapidjson::Value& obj) : LookupUserAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoResult()
            {
                if (UserInfo != nullptr) delete UserInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UserInfo != nullptr) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
                if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

                return true;
            }
        };

        struct ModifyMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            Aws::String BuildVersion;
            std::list<GameModeInfo> GameModes;

            ModifyMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameModes()
            {}

            ModifyMatchmakerGameModesRequest(const ModifyMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameModes(src.GameModes)
            {}

            ModifyMatchmakerGameModesRequest(const rapidjson::Value& obj) : ModifyMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion"); writer.String(BuildVersion.c_str());
                writer.String("GameModes");
    writer.StartArray();
    for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
    if (GameModes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameModes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameModes.push_back(GameModeInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ModifyMatchmakerGameModesResult : public PlayFabBaseModel
        {

            ModifyMatchmakerGameModesResult() :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const ModifyMatchmakerGameModesResult& src) :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const rapidjson::Value& obj) : ModifyMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesResult()
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

        struct ModifyServerBuildRequest : public PlayFabBaseModel
        {
            Aws::String BuildId;
            OptionalTime Timestamp;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Aws::String CommandLineTemplate;
            Aws::String ExecutablePath;
            Aws::String Comment;

            ModifyServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Timestamp(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Timestamp(src.Timestamp),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment)
            {}

            ModifyServerBuildRequest(const rapidjson::Value& obj) : ModifyServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId"); writer.String(BuildId.c_str());
                if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
                if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
                writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
                if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

                return true;
            }
        };

        struct ModifyServerBuildResult : public PlayFabBaseModel
        {
            Aws::String BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Aws::String CommandLineTemplate;
            Aws::String ExecutablePath;
            Aws::String Comment;
            time_t Timestamp;
            Aws::String TitleId;
            Boxed<GameBuildStatus> Status;

            ModifyServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
            {}

            ModifyServerBuildResult(const rapidjson::Value& obj) : ModifyServerBuildResult()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
                if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
                writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
                if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.String("Timestamp"); writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

                return true;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 BalanceChange;
            Int32 Balance;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                BalanceChange(0),
                Balance(0)
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                BalanceChange(src.BalanceChange),
                Balance(src.Balance)
            {}

            ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyUserVirtualCurrencyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
                writer.String("BalanceChange"); writer.Int(BalanceChange);
                writer.String("Balance"); writer.Int(Balance);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
                if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
                const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
                if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

                return true;
            }
        };

        struct RandomResultTable : public PlayFabBaseModel
        {
            Aws::String TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTable() :
                PlayFabBaseModel(),
                TableId(),
                Nodes()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                TableId(src.TableId),
                Nodes(src.Nodes)
            {}

            RandomResultTable(const rapidjson::Value& obj) : RandomResultTable()
            {
                readFromValue(obj);
            }

            ~RandomResultTable()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TableId"); writer.String(TableId.c_str());
                writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }

                return true;
            }
        };

        struct RemoveServerBuildRequest : public PlayFabBaseModel
        {
            Aws::String BuildId;

            RemoveServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            RemoveServerBuildRequest(const RemoveServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            RemoveServerBuildRequest(const rapidjson::Value& obj) : RemoveServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId"); writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct RemoveServerBuildResult : public PlayFabBaseModel
        {

            RemoveServerBuildResult() :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const RemoveServerBuildResult& src) :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const rapidjson::Value& obj) : RemoveServerBuildResult()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildResult()
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

        struct ResetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;

            ResetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId)
            {}

            ResetCharacterStatisticsRequest(const rapidjson::Value& obj) : ResetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct ResetCharacterStatisticsResult : public PlayFabBaseModel
        {

            ResetCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const ResetCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const rapidjson::Value& obj) : ResetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsResult()
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

        struct UserCredentials : public PlayFabBaseModel
        {
            Aws::String Username;
            Aws::String Password;

            UserCredentials() :
                PlayFabBaseModel(),
                Username(),
                Password()
            {}

            UserCredentials(const UserCredentials& src) :
                PlayFabBaseModel(),
                Username(src.Username),
                Password(src.Password)
            {}

            UserCredentials(const rapidjson::Value& obj) : UserCredentials()
            {
                readFromValue(obj);
            }

            ~UserCredentials()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Username"); writer.String(Username.c_str());
                writer.String("Password"); writer.String(Password.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

                return true;
            }
        };

        struct ResetUsersRequest : public PlayFabBaseModel
        {
            std::list<UserCredentials> Users;

            ResetUsersRequest() :
                PlayFabBaseModel(),
                Users()
            {}

            ResetUsersRequest(const ResetUsersRequest& src) :
                PlayFabBaseModel(),
                Users(src.Users)
            {}

            ResetUsersRequest(const rapidjson::Value& obj) : ResetUsersRequest()
            {
                readFromValue(obj);
            }

            ~ResetUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Users");
    writer.StartArray();
    for (std::list<UserCredentials>::iterator iter = Users.begin(); iter != Users.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Users_member = obj.FindMember("Users");
    if (Users_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Users_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Users.push_back(UserCredentials(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ResetUserStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ResetUserStatisticsRequest(const rapidjson::Value& obj) : ResetUserStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ResetUserStatisticsResult : public PlayFabBaseModel
        {

            ResetUserStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const rapidjson::Value& obj) : ResetUserStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsResult()
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

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ItemInstanceId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct RevokeInventoryResult : public PlayFabBaseModel
        {

            RevokeInventoryResult() :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const rapidjson::Value& obj) : RevokeInventoryResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryResult()
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

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            Aws::String Email;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            SendAccountRecoveryEmailRequest(const rapidjson::Value& obj) : SendAccountRecoveryEmailRequest()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Email"); writer.String(Email.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabBaseModel
        {

            SendAccountRecoveryEmailResult() :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult& src) :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const rapidjson::Value& obj) : SendAccountRecoveryEmailResult()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailResult()
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

        struct SetPublishedRevisionRequest : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;

            SetPublishedRevisionRequest() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            SetPublishedRevisionRequest(const rapidjson::Value& obj) : SetPublishedRevisionRequest()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version"); writer.Int(Version);
                writer.String("Revision"); writer.Int(Revision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct SetPublishedRevisionResult : public PlayFabBaseModel
        {

            SetPublishedRevisionResult() :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const SetPublishedRevisionResult& src) :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const rapidjson::Value& obj) : SetPublishedRevisionResult()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionResult()
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

        struct SetPublisherDataRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String Value;

            SetPublisherDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetPublisherDataRequest(const rapidjson::Value& obj) : SetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetPublisherDataResult : public PlayFabBaseModel
        {

            SetPublisherDataResult() :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const SetPublisherDataResult& src) :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const rapidjson::Value& obj) : SetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataResult()
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

        struct SetTitleDataRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String Value;

            SetTitleDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetTitleDataRequest(const rapidjson::Value& obj) : SetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~SetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetTitleDataResult : public PlayFabBaseModel
        {

            SetTitleDataResult() :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const SetTitleDataResult& src) :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const rapidjson::Value& obj) : SetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~SetTitleDataResult()
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

        struct SetupPushNotificationRequest : public PlayFabBaseModel
        {
            Aws::String Name;
            Aws::String Platform;
            Aws::String Key;
            Aws::String Credential;
            bool OverwriteOldARN;

            SetupPushNotificationRequest() :
                PlayFabBaseModel(),
                Name(),
                Platform(),
                Key(),
                Credential(),
                OverwriteOldARN(false)
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Platform(src.Platform),
                Key(src.Key),
                Credential(src.Credential),
                OverwriteOldARN(src.OverwriteOldARN)
            {}

            SetupPushNotificationRequest(const rapidjson::Value& obj) : SetupPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name"); writer.String(Name.c_str());
                writer.String("Platform"); writer.String(Platform.c_str());
                if (Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
                writer.String("Credential"); writer.String(Credential.c_str());
                writer.String("OverwriteOldARN"); writer.Bool(OverwriteOldARN);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Credential_member = obj.FindMember("Credential");
                if (Credential_member != obj.MemberEnd() && !Credential_member->value.IsNull()) Credential = Credential_member->value.GetString();
                const Value::ConstMemberIterator OverwriteOldARN_member = obj.FindMember("OverwriteOldARN");
                if (OverwriteOldARN_member != obj.MemberEnd() && !OverwriteOldARN_member->value.IsNull()) OverwriteOldARN = OverwriteOldARN_member->value.GetBool();

                return true;
            }
        };

        struct SetupPushNotificationResult : public PlayFabBaseModel
        {
            Aws::String ARN;

            SetupPushNotificationResult() :
                PlayFabBaseModel(),
                ARN()
            {}

            SetupPushNotificationResult(const SetupPushNotificationResult& src) :
                PlayFabBaseModel(),
                ARN(src.ARN)
            {}

            SetupPushNotificationResult(const rapidjson::Value& obj) : SetupPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ARN.length() > 0) { writer.String("ARN"); writer.String(ARN.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ARN_member = obj.FindMember("ARN");
                if (ARN_member != obj.MemberEnd() && !ARN_member->value.IsNull()) ARN = ARN_member->value.GetString();

                return true;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct UpdateCatalogItemsRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            std::list<CatalogItem> Catalog;

            UpdateCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Catalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Catalog(src.Catalog)
            {}

            UpdateCatalogItemsRequest(const rapidjson::Value& obj) : UpdateCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (!Catalog.empty()) {
    writer.String("Catalog");
    writer.StartArray();
    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Catalog_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Catalog.push_back(CatalogItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct UpdateCatalogItemsResult : public PlayFabBaseModel
        {

            UpdateCatalogItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const UpdateCatalogItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const rapidjson::Value& obj) : UpdateCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsResult()
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

        struct UpdateCloudScriptRequest : public PlayFabBaseModel
        {
            OptionalInt32 Version;
            std::list<CloudScriptFile> Files;
            bool Publish;

            UpdateCloudScriptRequest() :
                PlayFabBaseModel(),
                Version(),
                Files(),
                Publish(false)
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Files(src.Files),
                Publish(src.Publish)
            {}

            UpdateCloudScriptRequest(const rapidjson::Value& obj) : UpdateCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
                writer.String("Files");
    writer.StartArray();
    for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.String("Publish"); writer.Bool(Publish);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Files_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Files.push_back(CloudScriptFile(memberList[i]));
        }
    }
                const Value::ConstMemberIterator Publish_member = obj.FindMember("Publish");
                if (Publish_member != obj.MemberEnd() && !Publish_member->value.IsNull()) Publish = Publish_member->value.GetBool();

                return true;
            }
        };

        struct UpdateCloudScriptResult : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;

            UpdateCloudScriptResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            UpdateCloudScriptResult(const rapidjson::Value& obj) : UpdateCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version"); writer.Int(Version);
                writer.String("Revision"); writer.Int(Revision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            UpdatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
                if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(nullptr)
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : nullptr)
            {}

            UpdatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionResult()
            {
                if (Statistic != nullptr) delete Statistic;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Statistic != nullptr) { writer.String("Statistic"); Statistic->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
                if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

                return true;
            }
        };

        struct UpdateRandomResultTablesRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Tables(src.Tables)
            {}

            UpdateRandomResultTablesRequest(const rapidjson::Value& obj) : UpdateRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (!Tables.empty()) {
    writer.String("Tables");
    writer.StartArray();
    for (std::list<RandomResultTable>::iterator iter = Tables.begin(); iter != Tables.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
    if (Tables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tables.push_back(RandomResultTable(memberList[i]));
        }
    }

                return true;
            }
        };

        struct UpdateRandomResultTablesResult : public PlayFabBaseModel
        {

            UpdateRandomResultTablesResult() :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const UpdateRandomResultTablesResult& src) :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const rapidjson::Value& obj) : UpdateRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesResult()
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

        struct UpdateStoreItemsRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String StoreId;
            std::list<StoreItem> Store;

            UpdateStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId(),
                Store()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                Store(src.Store)
            {}

            UpdateStoreItemsRequest(const rapidjson::Value& obj) : UpdateStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("StoreId"); writer.String(StoreId.c_str());
                if (!Store.empty()) {
    writer.String("Store");
    writer.StartArray();
    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
    if (Store_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Store_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Store.push_back(StoreItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct UpdateStoreItemsResult : public PlayFabBaseModel
        {

            UpdateStoreItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const UpdateStoreItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const rapidjson::Value& obj) : UpdateStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsResult()
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

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateUserDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DataVersion"); writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateUserInternalDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInternalDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameRequest(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("DisplayName"); writer.String(DisplayName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabBaseModel
        {
            Aws::String DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameResult(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };


    }
}
