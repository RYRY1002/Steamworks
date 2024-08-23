// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

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
