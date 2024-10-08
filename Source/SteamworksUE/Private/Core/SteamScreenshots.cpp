// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#include "Core/SteamScreenshots.h"

#include "SteamworksUEUtils.h"
#include "Engine/Texture2D.h"

USteamScreenshots::USteamScreenshots()
{
	OnScreenshotReadyCallback.Register(this, &USteamScreenshots::OnScreenshotReady);
	OnScreenshotRequestedCallback.Register(this, &USteamScreenshots::OnScreenshotRequested);
}

USteamScreenshots::~USteamScreenshots()
{
	OnScreenshotReadyCallback.Unregister();
	OnScreenshotRequestedCallback.Unregister();
}

FScreenshotHandle USteamScreenshots::AddScreenshotToLibrary(const FString& FileName, const FString& ThumbnailFileName, const FIntPoint& Size /*= { 1920, 1080 }*/) const
{
	return SteamScreenshots()->AddScreenshotToLibrary(TCHAR_TO_UTF8(*FileName), TCHAR_TO_UTF8(*ThumbnailFileName), Size.X, Size.Y);
}

FScreenshotHandle USteamScreenshots::AddVRScreenshotToLibrary(ESteamVRScreenshotType Type, const FString& FileName, const FString& VRFileName) const
{
	return SteamScreenshots()->AddVRScreenshotToLibrary((EVRScreenshotType)Type, TCHAR_TO_UTF8(*FileName), TCHAR_TO_UTF8(*VRFileName));
}

FScreenshotHandle USteamScreenshots::WriteScreenshot(UTexture2D* Image) const
{
	FTexture2DMipMap* TmpMipMap = &Image->GetPlatformData()->Mips[0];
	FByteBulkData* TmpData = &TmpMipMap->BulkData;
	return SteamScreenshots()->WriteScreenshot(TmpData, TmpData->GetBulkDataSize(), Image->GetSizeX(), Image->GetSizeY());
}

void USteamScreenshots::OnScreenshotReady(ScreenshotReady_t* pParam)
{
	m_OnScreenshotReady.Broadcast(pParam->m_hLocal, (ESteamResult)pParam->m_eResult);
}

void USteamScreenshots::OnScreenshotRequested(ScreenshotRequested_t* pParam)
{
	m_OnScreenshotRequested.Broadcast();
}
