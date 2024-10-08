// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Steam.h"
#include "SteamEnums.h"

#include "SteamStructs.generated.h"

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUint64
{
	GENERATED_BODY()

	uint64 Value;

	operator uint64() { return Value; }
	operator uint64() const { return Value; }

	FUint64() :
		Value(0) {}
	FUint64(uint64 value) :
		Value(value) {}
	FUint64(const FUint64& InValue) :
		FUint64(InValue.Value) {}
};
FORCEINLINE uint32 GetTypeHash(const FUint64& InValue)
{
	return FCrc::MemCrc32(&InValue, sizeof(FUint64));
}

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUint32
{
	GENERATED_BODY()

	uint32 Value;

	operator uint32() { return Value; }
	operator uint32() const { return Value; }

	FUint32() :
		Value(0) {}
	FUint32(uint32 value) :
		Value(value) {}
	FUint32(const FUint32& InValue) :
		FUint32(InValue.Value) {}
};
FORCEINLINE uint32 GetTypeHash(const FUint32& InValue)
{
	return FCrc::MemCrc32(&InValue, sizeof(FUint32));
}

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInt32
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Value;

	operator int32() { return Value; }
	operator int32() const { return Value; }

	FInt32() :
		Value(0) {}
	FInt32(int32 InValue) :
		Value(InValue) {}
	FInt32(const FInt32& InValue) :
		FInt32(InValue.Value) {}
};
FORCEINLINE uint32 GetTypeHash(const FInt32& InValue)
{
	return FCrc::MemCrc32(&InValue, sizeof(FInt32));
}

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInt16
{
	GENERATED_BODY()

	int16 Value;

	operator int16() { return Value; }
	operator int16() const { return Value; }

	FInt16() :
		Value(0) {}
	FInt16(int16 InValue) :
		Value(InValue) {}
	FInt16(const FInt16& InValue) :
		FInt16(InValue.Value) {}
};
FORCEINLINE uint32 GetTypeHash(const FInt16& InValue)
{
	return FCrc::MemCrc32(&InValue, sizeof(FInt16));
}

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHServerListRequest
{
	GENERATED_BODY()

	void* Value;

	FHServerListRequest() :
		Value(nullptr) {}
	FHServerListRequest(void* InValue) :
		Value(InValue) {}
	FHServerListRequest(const FHServerListRequest& InValue) :
		FHServerListRequest(InValue.Value) {}
};
FORCEINLINE uint32 GetTypeHash(const FHServerListRequest& InValue)
{
	return FCrc::MemCrc32(&InValue, sizeof(FHServerListRequest));
}

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamID : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;

	operator CSteamID() const { return CSteamID(Value); }
	bool IsValid() const { return CSteamID(Value).IsValid(); }
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamAPICall : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamItemInstanceID : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamInventoryUpdateHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHAuthTicket : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHSteamUser : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FAppID : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FAccountID : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FScreenshotHandle : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamFriendsGroupID : public FInt16
{
	GENERATED_BODY()
	using FInt16::FInt16;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamInventoryResult : public FInt32
{
	GENERATED_BODY()
	using FInt32::FInt32;
};

// This type causing an error at Engine/Source/Runtime/Core/Public/Containers/Map.h(118).
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamItemDef : public FInt32
{
	GENERATED_BODY()
	using FInt32::FInt32;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHServerQuery : public FInt32
{
	GENERATED_BODY()
	using FInt32::FInt32;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInputActionSetHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInputAnalogActionHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInputDigitalActionHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FInputHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FPartyBeaconID : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUGCHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FPublishedFileId : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FPublishedFileUpdateHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUGCFileWriteStreamHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamLeaderboardEntries : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamLeaderboard : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUGCQueryHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FUGCUpdateHandle : public FUint64
{
	GENERATED_BODY()
	using FUint64::FUint64;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHTTPCookieContainerHandle : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};
USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHTTPRequestHandle : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FHHTMLBrowser : public FUint32
{
	GENERATED_BODY()
	using FUint32::FUint32;
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamInputAnalogActionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	ESteamControllerSourceMode Mode;

	UPROPERTY(BlueprintReadWrite)
	float X;

	UPROPERTY(BlueprintReadWrite)
	float Y;

	UPROPERTY(BlueprintReadWrite)
	bool bActive;

	FSteamInputAnalogActionData() {}
	FSteamInputAnalogActionData(ESteamControllerSourceMode mode, float x, float y, bool bactive) :
		Mode(mode), X(x), Y(y), bActive(bactive) {}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamInputDigitalActionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	bool bState;

	UPROPERTY(BlueprintReadWrite)
	bool bActive;

	FSteamInputDigitalActionData() {}
	FSteamInputDigitalActionData(bool bstate, bool bactive) :
		bState(bstate), bActive(bactive) {}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamInputMotionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FQuat RotQuat;

	UPROPERTY(BlueprintReadWrite)
	FVector PosAccel;

	UPROPERTY(BlueprintReadWrite)
	FVector RotVel;

	FSteamInputMotionData() {}
	FSteamInputMotionData(const FQuat& quat, const FVector& pos, const FVector& rotvel) :
		RotQuat(quat), PosAccel(pos), RotVel(rotvel) {}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamItemDetails
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FSteamItemInstanceID ItemID;

	UPROPERTY(BlueprintReadWrite)
	FSteamItemDef Definition;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity;

	UPROPERTY(BlueprintReadWrite)
	TArray<ESteamItemFlags_> Flags;

	FSteamItemDetails() {}
	FSteamItemDetails(FSteamItemInstanceID instance, FSteamItemDef itemdef, int32 quantity, const TArray<ESteamItemFlags_>& flags) :
		ItemID(instance), Definition(itemdef), Quantity(quantity), Flags(flags) {}
	FSteamItemDetails(const SteamItemDetails_t& details)
	{
		ItemID = details.m_itemId;
		Definition = details.m_iDefinition;
		Quantity = details.m_unQuantity;
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::NoTrade)
		{
			Flags.Add(ESteamItemFlags_::NoTrade);
		}
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::ItemRemoved)
		{
			Flags.Add(ESteamItemFlags_::ItemRemoved);
		}
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::ItemConsumed)
		{
			Flags.Add(ESteamItemFlags_::ItemConsumed);
		}
	}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamPartyBeaconLocation
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	ESteamPartyBeaconLocation Type;

	UPROPERTY(BlueprintReadWrite)
	int64 LocationID;

	operator SteamPartyBeaconLocation_t() const
	{
		SteamPartyBeaconLocation_t o;
		o.m_eType = (ESteamPartyBeaconLocationType)Type;
		o.m_ulLocationID = LocationID;
		return o;
	}

	FSteamPartyBeaconLocation() {}
	FSteamPartyBeaconLocation(ESteamPartyBeaconLocation type, uint64 id) :
		Type(Type), LocationID(id) {}
	FSteamPartyBeaconLocation(const SteamPartyBeaconLocation_t& type) :
		Type((ESteamPartyBeaconLocation)type.m_eType), LocationID(type.m_ulLocationID) {}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamLeaderboardEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FSteamID SteamIDUser;

	UPROPERTY(BlueprintReadWrite)
	int32 GlobalRank;

	UPROPERTY(BlueprintReadWrite)
	int32 Score;

	UPROPERTY(BlueprintReadWrite)
	int32 Details;

	UPROPERTY(BlueprintReadWrite)
	FUGCHandle UGC;

	FSteamLeaderboardEntry() {}
	FSteamLeaderboardEntry(FSteamID steamid, int32 glob, int32 score, int32 details, FUGCHandle handle) :
		SteamIDUser(steamid), GlobalRank(glob), Score(score), Details(details), UGC(handle) {}
	FSteamLeaderboardEntry(const LeaderboardEntry_t& type) :
		SteamIDUser(type.m_steamIDUser.ConvertToUint64()), GlobalRank(type.m_nGlobalRank), Score(type.m_nScore), Details(type.m_cDetails), UGC(type.m_hUGC) {}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamUGCDetails
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FPublishedFileId PublishedFileId;

	UPROPERTY(BlueprintReadWrite)
	ESteamResult Result;  // The result of the operation.

	UPROPERTY(BlueprintReadWrite)
	ESteamWorkshopFileType FileType;  // Type of the file

	UPROPERTY(BlueprintReadWrite)
	int32 CreatorAppID;  // ID of the app that created this file.

	UPROPERTY(BlueprintReadWrite)
	int32 ConsumerAppID;  // ID of the app that will consume this file.

	UPROPERTY(BlueprintReadWrite)
	FString Title;  // title of document

	UPROPERTY(BlueprintReadWrite)
	FString Description;  // description of document

	UPROPERTY(BlueprintReadWrite)
	FSteamID SteamIDOwner;  // Steam ID of the user who created this content.

	UPROPERTY(BlueprintReadWrite)
	int32 TimeCreated;  // time when the published file was created

	UPROPERTY(BlueprintReadWrite)
	int32 TimeUpdated;  // time when the published file was last updated

	UPROPERTY(BlueprintReadWrite)
	int32 TimeAddedToUserList;  // time when the user added the published file to their list (not always applicable)

	UPROPERTY(BlueprintReadWrite)
	ESteamRemoteStoragePublishedFileVisibility Visibility;  // visibility

	UPROPERTY(BlueprintReadWrite)
	bool bBanned;  // whether the file was banned

	UPROPERTY(BlueprintReadWrite)
	bool bAcceptedForUse;  // developer has specifically flagged this item as accepted in the Workshop

	UPROPERTY(BlueprintReadWrite)
	bool bTagsTruncated;  // whether the list of tags was too long to be returned in the provided buffer

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> Tags;  // comma separated list of all tags associated with this file

	UPROPERTY(BlueprintReadWrite)
	FUGCHandle File;  // The handle of the primary file

	UPROPERTY(BlueprintReadWrite)
	FUGCHandle PreviewFile;  // The handle of the preview file

	UPROPERTY(BlueprintReadWrite)
	FString FileName;  // The cloud filename of the primary file

	UPROPERTY(BlueprintReadWrite)
	int32 FileSize;  // Size of the primary file

	UPROPERTY(BlueprintReadWrite)
	int32 PreviewFileSize;  // Size of the preview file

	UPROPERTY(BlueprintReadWrite)
	FString URL;  // URL (for a video or a website)

	UPROPERTY(BlueprintReadWrite)
	int32 VotesUp;  // number of votes up

	UPROPERTY(BlueprintReadWrite)
	int32 VotesDown;  // number of votes down

	UPROPERTY(BlueprintReadWrite)
	float Score;  // calculated score

	UPROPERTY(BlueprintReadWrite)
	int32 NumChildren;

	FSteamUGCDetails() :
		PublishedFileId(0), Result(ESteamResult::None), FileType(ESteamWorkshopFileType::Max), CreatorAppID(0), ConsumerAppID(0), Title(""), Description(""), SteamIDOwner(0), TimeCreated(0), TimeUpdated(0), TimeAddedToUserList(0), Visibility(ESteamRemoteStoragePublishedFileVisibility::Public), bBanned(false), bAcceptedForUse(false), bTagsTruncated(false), Tags({}), File(0), PreviewFile(0), FileName(""), FileSize(0), PreviewFileSize(0), URL(""), VotesUp(0), VotesDown(0), Score(0.0f), NumChildren(0) {}

	FSteamUGCDetails(const SteamUGCDetails_t& data) :
		PublishedFileId(data.m_nPublishedFileId), Result((ESteamResult)data.m_eResult), FileType((ESteamWorkshopFileType)data.m_eFileType), CreatorAppID(data.m_nCreatorAppID), ConsumerAppID(data.m_nConsumerAppID), Title(FString(UTF8_TO_TCHAR(data.m_rgchTitle))), Description(FString(UTF8_TO_TCHAR(data.m_rgchDescription))), SteamIDOwner(data.m_ulSteamIDOwner), TimeCreated(data.m_rtimeCreated), TimeUpdated(data.m_rtimeUpdated), TimeAddedToUserList(data.m_rtimeAddedToUserList), Visibility((ESteamRemoteStoragePublishedFileVisibility)data.m_eVisibility), bBanned(data.m_bBanned), bAcceptedForUse(data.m_bAcceptedForUse), bTagsTruncated(data.m_bTagsTruncated), File(data.m_hFile), PreviewFile(data.m_hPreviewFile), FileName(data.m_pchFileName), FileSize(data.m_nFileSize), PreviewFileSize(data.m_nPreviewFileSize), URL(UTF8_TO_TCHAR(data.m_rgchURL)), VotesUp(data.m_unVotesUp), VotesDown(data.m_unVotesDown), Score(data.m_flScore), NumChildren(data.m_unNumChildren)
	{
		FString(UTF8_TO_TCHAR(data.m_rgchTags)).ParseIntoArray(Tags, TEXT(","), true);
	}
};

USTRUCT(BlueprintType)
struct STEAMWORKSUE_API FSteamItemPriceData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FSteamItemDef ItemDef;

	UPROPERTY(BlueprintReadWrite)
	int64 CurrentPrice;

	UPROPERTY(BlueprintReadWrite)
	int64 BasePrice;

	FSteamItemPriceData() {}
	FSteamItemPriceData(FSteamItemDef def, int64 currentPrice, int64 basePrice) : ItemDef(def), CurrentPrice(currentPrice), BasePrice(basePrice) {}
};
