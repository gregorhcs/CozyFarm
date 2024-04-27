// Copyright 2024 Thieves of the Night. All Rights Reserved.

using UnrealBuildTool;

// ReSharper disable once InconsistentNaming
public class GASEasierInputExtension : ModuleRules
{
	public GASEasierInputExtension(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
			
		
		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core", 
				"GameplayAbilities",
			}
		);
			
		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"GameplayTasks",
			}
		);
	}
}
