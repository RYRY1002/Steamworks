// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.

using UnrealBuildTool;

public class SteamworksUE : ModuleRules
{
	public SteamworksUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "Projects",
            "SteamShared"
        });

        AddEngineThirdPartyPrivateStaticDependencies(Target, "Steamworks");

        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "Settings" });
        }
    }
}
