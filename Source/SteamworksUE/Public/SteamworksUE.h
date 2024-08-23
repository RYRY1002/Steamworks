// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Containers/Ticker.h"

class FSteamworksUEModule : public IModuleInterface, public FTSTickerObjectBase
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool Tick(float DeltaTime) override;

private:

	bool HandleSettingsSaved();
	void RegisterSettings();
	void UnregisterSettings();

	void* m_SteamLibSDKHandle;
};
