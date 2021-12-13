// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShootyNumbers : ModuleRules
{
	public ShootyNumbers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
