// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tarea1_CPP : ModuleRules
{
	public Tarea1_CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG" });
	}
}
