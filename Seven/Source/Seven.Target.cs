// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
//comment
using UnrealBuildTool;
using System.Collections.Generic;

public class SevenTarget : TargetRules
{
	public SevenTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("Seven");
	}
}
