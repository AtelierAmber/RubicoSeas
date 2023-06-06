// Copyright Epic Games, Inc. All Rights Reserved.

#include "IsogridEditorMode.h"
#include "IsogridEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "IsogridEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/IsogridSimpleTool.h"
#include "Tools/IsogridInteractiveTool.h"

// step 2: register a ToolBuilder in FIsogridEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "IsogridEditorMode"

const FEditorModeID UIsogridEditorMode::EM_IsogridEditorModeId = TEXT("EM_IsogridEditorMode");

FString UIsogridEditorMode::SimpleToolName = TEXT("Isogrid_ActorInfoTool");
FString UIsogridEditorMode::InteractiveToolName = TEXT("Isogrid_MeasureDistanceTool");


UIsogridEditorMode::UIsogridEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UIsogridEditorMode::EM_IsogridEditorModeId,
		LOCTEXT("ModeName", "Isogrid"),
		FSlateIcon(),
		true);
}


UIsogridEditorMode::~UIsogridEditorMode()
{
}


void UIsogridEditorMode::ActorSelectionChangeNotify()
{
}

void UIsogridEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FIsogridEditorModeCommands& SampleToolCommands = FIsogridEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UIsogridSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UIsogridInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UIsogridEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FIsogridEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UIsogridEditorMode::GetModeCommands() const
{
	return FIsogridEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
