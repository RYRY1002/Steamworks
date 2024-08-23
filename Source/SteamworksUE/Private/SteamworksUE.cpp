// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#include "SteamBridge.h"

#include "Developer/Settings/Public/ISettingsContainer.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsSection.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformProcess.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "Steam.h"
#include "SteamworksUESettings.h"

#define LOCTEXT_NAMESPACE "FSteamworksUEModule"

void FSteamworksUEModule::StartupModule()
{
	RegisterSettings();

	FString SteamDir = FPaths::EngineDir() / TEXT("Binaries/ThirdParty/Steamworks") / SDK_VER;
	FString SDKPath = "";

	bool bIs64Bit = false;
#if PLATFORM_64BITS
	bIs64Bit = true;
#endif

#if PLATFORM_WINDOWS
	SteamDir = FString::Printf(TEXT("%s/%s"), *SteamDir, bIs64Bit ? *FString("Win64/") : *FString("Win32/"));
	SDKPath = FPaths::Combine(*SteamDir, FString::Printf(TEXT("steam_api%s.dll"), bIs64Bit ? *FString("64") : *FString("")));
	m_SteamLibSDKHandle = FPlatformProcess::GetDllHandle(*(SDKPath));
#elif PLATFORM_LINUX
	SteamDir = FString::Printf(TEXT("%s/%s"), *SteamDir, bIs64Bit ? *FString("x86_64-unknown-linux-gnu/") : *FString("i686-unknown-linux-gnu/"));
	SDKPath = FPaths::Combine(*SteamDir, "libsteam_api.so");
	m_SteamLibSDKHandle = FPlatformProcess::GetDllHandle(*(SDKPath));
#endif
}

void FSteamworksUEModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		SteamAPI_Shutdown();
		SteamGameServer_Shutdown();

		UnregisterSettings();

		if (m_SteamLibSDKHandle != nullptr)
		{
			FPlatformProcess::FreeDllHandle(m_SteamLibSDKHandle);
		}
	}
}

bool FSteamworksUEModule::Tick(float DeltaTime)
{
	SteamAPI_RunCallbacks();
	SteamGameServer_RunCallbacks();

	return true;
}

bool FSteamworksUEModule::HandleSettingsSaved()
{
#if WITH_EDITOR
	USteamworksUESettings* Settings = GetMutableDefault<USteamworksUESettings>();
	bool ResaveSettings = false;

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}
#endif  // WITH_EDITOR

	return true;
}

void FSteamworksUEModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		/*ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("SteamworksUE",
			LOCTEXT("RuntimeWDCategoryName", "SteamworksUE"),
			LOCTEXT("RuntimeWDCategoryDescription", "Game configuration for the SteamworksUE game module"));*/

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Project", "SteamworksUE",
			LOCTEXT("RuntimeGeneralSettingsName", "SteamworksUE"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Configure Steamworks settings."),
			GetMutableDefault<USteamBridgeSettings>());

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FSteamworksUEModule::HandleSettingsSaved);
		}
	}
#endif  // WITH_EDITOR
}

void FSteamworksUEModule::UnregisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Project", "SteamworksUE");
	}
#endif  // WITH_EDITOR
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSteamworksUEModule, SteamworksUE)
