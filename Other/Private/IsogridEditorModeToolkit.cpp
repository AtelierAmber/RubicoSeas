// Copyright Epic Games, Inc. All Rights Reserved.

#include "IsogridEditorModeToolkit.h"
#include "IsogridEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "IsogridEditorModeToolkit"

FIsogridEditorModeToolkit::FIsogridEditorModeToolkit()
{
}

void FIsogridEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FIsogridEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FIsogridEditorModeToolkit::GetToolkitFName() const
{
	return FName("IsogridEditorMode");
}

FText FIsogridEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "IsogridEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
