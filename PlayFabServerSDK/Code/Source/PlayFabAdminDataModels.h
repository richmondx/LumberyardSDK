#pragma once

#include "PlayFabBaseModel.h"
#include "aws\core\utils\json\JsonSerializer.h"

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

            ~AddNewsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~AddNewsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

        void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer);
        Region readRegionFromValue(const rapidjson::Value& obj);

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

            ~AddServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        void writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer);
        GameBuildStatus readGameBuildStatusFromValue(const rapidjson::Value& obj);

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

            ~AddServerBuildResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~AddUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~VirtualCurrencyData();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~AddVirtualCurrencyTypesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~BlankResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~CatalogItemConsumableInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~CatalogItemContainerInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~CatalogItemBundleInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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
                Consumable(NULL),
                Container(NULL),
                Bundle(NULL),
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
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : NULL),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : NULL),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : NULL),
                CanBecomeCharacter(src.CanBecomeCharacter),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemImageUrl(src.ItemImageUrl)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~CloudScriptFile();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~CloudScriptVersionStatus();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ContentInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        void writeStatisticResetIntervalOptionEnumJSON(StatisticResetIntervalOption enumVal, PFStringJsonWriter& writer);
        StatisticResetIntervalOption readStatisticResetIntervalOptionFromValue(const rapidjson::Value& obj);

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            CreatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Uint32 CurrentVersion;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                StatisticName(),
                CurrentVersion(0),
                VersionChangeInterval()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CurrentVersion(src.CurrentVersion),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            PlayerStatisticDefinition(const rapidjson::Value& obj) : PlayerStatisticDefinition()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticDefinition();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(NULL)
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : NULL)
            {}

            CreatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

        void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer);
        Currency readCurrencyFromValue(const rapidjson::Value& obj);

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

            ~DeleteContentRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~DeleteUsersRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~DeleteUsersResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct GameModeInfo : public PlayFabBaseModel
        {
            Aws::String Gamemode;
            Uint32 MinPlayerCount;
            Uint32 MaxPlayerCount;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MinPlayerCount(0),
                MaxPlayerCount(0)
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MinPlayerCount(src.MinPlayerCount),
                MaxPlayerCount(src.MaxPlayerCount)
            {}

            GameModeInfo(const rapidjson::Value& obj) : GameModeInfo()
            {
                readFromValue(obj);
            }

            ~GameModeInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCatalogItemsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCatalogItemsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCloudScriptRevisionRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCloudScriptRevisionResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCloudScriptVersionsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetCloudScriptVersionsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetContentListRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetContentListResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetContentUploadUrlRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetContentUploadUrlResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetDataReportRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetDataReportResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetMatchmakerGameInfoRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetMatchmakerGameInfoResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetMatchmakerGameModesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetMatchmakerGameModesResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPlayerStatisticDefinitionsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPlayerStatisticDefinitionsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPlayerStatisticVersionsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        void writeStatisticVersionArchivalStatusEnumJSON(StatisticVersionArchivalStatus enumVal, PFStringJsonWriter& writer);
        StatisticVersionArchivalStatus readStatisticVersionArchivalStatusFromValue(const rapidjson::Value& obj);

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

            ~PlayerStatisticVersion();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPlayerStatisticVersionsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPublisherDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetPublisherDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetRandomResultTablesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer);
        ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj);

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

            ~ResultTableNode();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RandomResultTableListing();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetRandomResultTablesResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetServerBuildInfoRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetServerBuildInfoResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetServerBuildUploadURLRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetServerBuildUploadURLResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetStoreItemsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~StoreItem();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetStoreItemsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetTitleDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetTitleDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetUserDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer);
        UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj);

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

            ~UserDataRecord();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetUserDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetUserInventoryRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ItemInstance();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~VirtualCurrencyRechargeTime();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GetUserInventoryResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GrantedItemInstance();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ItemGrant();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GrantItemsToUsersRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~GrantItemsToUsersResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~IncrementPlayerStatisticVersionRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct IncrementPlayerStatisticVersionResult : public PlayFabBaseModel
        {
            PlayerStatisticVersion* StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabBaseModel(),
                StatisticVersion(NULL)
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabBaseModel(),
                StatisticVersion(src.StatisticVersion ? new PlayerStatisticVersion(*src.StatisticVersion) : NULL)
            {}

            IncrementPlayerStatisticVersionResult(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionResult()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ListBuildsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ListBuildsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ListVirtualCurrencyTypesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ListVirtualCurrencyTypesResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~LookupUserAccountInfoRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

        void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer);
        UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj);

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

            ~UserTitleInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserPrivateAccountInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserFacebookInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer);
        TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj);

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

            ~UserSteamInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserGameCenterInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserIosDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserAndroidDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserKongregateInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserPsnInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserGoogleInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserXboxInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserCustomIdInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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
                TitleInfo(NULL),
                PrivateInfo(NULL),
                FacebookInfo(NULL),
                SteamInfo(NULL),
                GameCenterInfo(NULL),
                IosDeviceInfo(NULL),
                AndroidDeviceInfo(NULL),
                KongregateInfo(NULL),
                PsnInfo(NULL),
                GoogleInfo(NULL),
                XboxInfo(NULL),
                CustomIdInfo(NULL)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Created(src.Created),
                Username(src.Username),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : NULL),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : NULL),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : NULL),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : NULL),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : NULL),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : NULL),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : NULL),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : NULL),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : NULL)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct LookupUserAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabBaseModel(),
                UserInfo(NULL)
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : NULL)
            {}

            LookupUserAccountInfoResult(const rapidjson::Value& obj) : LookupUserAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ModifyMatchmakerGameModesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ModifyMatchmakerGameModesResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ModifyServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ModifyServerBuildResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ModifyUserVirtualCurrencyResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RandomResultTable();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RemoveServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RemoveServerBuildResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ResetCharacterStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ResetCharacterStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UserCredentials();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ResetUsersRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ResetUserStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~ResetUserStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RevokeInventoryItemRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~RevokeInventoryResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SendAccountRecoveryEmailRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SendAccountRecoveryEmailResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetPublishedRevisionRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetPublishedRevisionResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetPublisherDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetPublisherDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetTitleDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetTitleDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetupPushNotificationRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SetupPushNotificationResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~SubtractUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateCatalogItemsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateCatalogItemsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct UpdateCloudScriptRequest : public PlayFabBaseModel
        {
            OptionalInt32 Version;
            std::list<CloudScriptFile> Files;

            UpdateCloudScriptRequest() :
                PlayFabBaseModel(),
                Version(),
                Files()
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Files(src.Files)
            {}

            UpdateCloudScriptRequest(const rapidjson::Value& obj) : UpdateCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            UpdatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(NULL)
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : NULL)
            {}

            UpdatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateRandomResultTablesRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateRandomResultTablesResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateStoreItemsRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateStoreItemsResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateUserDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateUserDataResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateUserInternalDataRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateUserTitleDisplayNameRequest();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
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

            ~UpdateUserTitleDisplayNameResult();

            void writeJSON(PFStringJsonWriter& writer) override;
            bool readFromValue(const rapidjson::Value& obj) override;
        };


    }
}
