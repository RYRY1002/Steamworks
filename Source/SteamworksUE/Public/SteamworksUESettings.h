// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SteamworksUESettings.generated.h"

/**
 * 
 */
UCLASS(config = Engine)
class STEAMWORKSUE_API USteamworksUESettings final : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bTest;

	// #TODO Implement OSS Steam settings to remove the requirement of setting the info via text editor
};
