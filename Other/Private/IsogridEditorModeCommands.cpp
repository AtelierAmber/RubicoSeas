// Copyright Epic Games, Inc. All Rights Reserved.

#include "IsogridEditorModeCommands.h"
#include "IsogridEditorMode.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "IsogridEditorModeCommands"

FIsogridEditorModeCommands::FIsogridEditorModeCommands()
	: TCommands<FIsogridEditorModeCommands>("IsogridEditorMode",
		NSLOCTEXT("IsogridEditorMode", "IsogridEditorModeCommands", "Isogrid Editor Mode"),
		NAME_None,
		FEditorStyle::GetStyleSetName())
{
}

void FIsogridEditorModeCommands::RegisterCommands()
{
	TArray <TSharedPtr<FUICommandInfo>>& ToolCommands = Commands.FindOrAdd(NAME_Default);

	UI_COMMAND(SimpleTool, "Show Actor Info", "Opens message box with info about a clicked actor", EUserInterfaceActionType::Button, FInputChord());
	ToolCommands.Add(SimpleTool);

	UI_COMMAND(InteractiveTool, "Measure Distance", "Measures distance between 2 points (click to set origin, shift-click to set end point)", EUserInterfaceActionType::ToggleButton, FInputChord());
	ToolCommands.Add(InteractiveTool);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> FIsogridEditorModeCommands::GetCommands()
{
	return FIsogridEditorModeCommands::Get().Commands;
}

#undef LOCTEXT_NAMESPACE
