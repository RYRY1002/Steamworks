// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Steam.h"
#include "SteamEnums.h"
#include "SteamStructs.h"
#include "UObject/NoExportTypes.h"

#include "SteamMatchmakingServers.generated.h"

/**
 * Functions which provide access to the game server browser.
 * https://partner.steamgames.com/doc/api/ISteamMatchmakingServers
 */
UCLASS()
class STEAMWORKSUE_API USteamMatchmakingServers final : public UObject
{
	GENERATED_BODY()

public:
	USteamMatchmakingServers();
	~USteamMatchmakingServers();

	UFUNCTION(BlueprintPure, Category = "Steamworks", meta = (DisplayName = "Steam Matchmaking Servers", CompactNodeTitle = "SteamMatchmakingServers"))
	static USteamMatchmakingServers* GetSteamMatchmakingServers() { return USteamMatchmakingServers::StaticClass()->GetDefaultObject<USteamMatchmakingServers>(); }

	UFUNCTION(BlueprintCallable, Category = "Steamworks|MatchmakingServers")
	void CancelQuery(const FHServerListRequest& Request) { SteamMatchmakingServers()->CancelQuery(Request.Value); }

	UFUNCTION(BlueprintCallable, Category = "Steamworks|MatchmakingServers")
	void CancelServerQuery(FHServerQuery ServerQuery) { SteamMatchmakingServers()->CancelServerQuery(ServerQuery.Value); }

	UFUNCTION(BlueprintPure, Category = "Steamworks|MatchmakingServers")
	int32 GetServerCount(const FHServerListRequest& Request) const { return SteamMatchmakingServers()->GetServerCount(Request.Value); }

	// #TODO: GetServerDetails

	UFUNCTION(BlueprintPure, Category = "Steamworks|MatchmakingServers")
	bool IsRefreshing(const FHServerListRequest& Request) const { return SteamMatchmakingServers()->IsRefreshing(Request.Value); }

	// #TODO: PingServer
	// #TODO: PlayerDetails

	UFUNCTION(BlueprintCallable, Category = "Steamworks|MatchmakingServers")
	void RefreshQuery(const FHServerListRequest& Request) { SteamMatchmakingServers()->RefreshQuery(Request.Value); }

	UFUNCTION(BlueprintCallable, Category = "Steamworks|MatchmakingServers")
	void RefreshServer(const FHServerListRequest& Request, int32 ServerIndex) { SteamMatchmakingServers()->RefreshServer(Request.Value, ServerIndex); }

	UFUNCTION(BlueprintCallable, Category = "Steamworks|MatchmakingServers")
	void ReleaseRequest(const FHServerListRequest& ServerListRequest) { SteamMatchmakingServers()->ReleaseRequest(ServerListRequest.Value); }

	// #TODO: RequestFavoritesServerList
	// #TODO: RequestFriendsServerList
	// #TODO: RequestHistoryServerList
	// #TODO: RequestInternetServerList
	// #TODO: RequestLANServerList
	// #TODO: RequestSpectatorServerList
	// #TODO: ServerRules


private:
};
