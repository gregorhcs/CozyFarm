// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CozyScapeTarget : TargetRules
{
	public CozyScapeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("CozyScape");

		bOverrideBuildEnvironment = true;
		GlobalDefinitions.Add("ALLOW_CONSOLE_IN_SHIPPING=1");
		GlobalDefinitions.Add("UE_WITH_CHEAT_MANAGER=1");
	}
}
