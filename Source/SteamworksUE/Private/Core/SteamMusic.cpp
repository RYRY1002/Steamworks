// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#include "Core/SteamMusic.h"

#include "SteamworksUEUtils.h"

USteamMusic::USteamMusic()
{
	OnPlaybackStatusHasChangedCallback.Register(this, &USteamMusic::OnPlaybackStatusHasChanged);
	OnVolumeHasChangedCallback.Register(this, &USteamMusic::OnVolumeHasChanged);
}

USteamMusic::~USteamMusic()
{
	OnPlaybackStatusHasChangedCallback.Unregister();
	OnVolumeHasChangedCallback.Unregister();
}

void USteamMusic::OnPlaybackStatusHasChanged(PlaybackStatusHasChanged_t* pParam)
{
	m_OnPlaybackStatusHasChanged.Broadcast();
}

void USteamMusic::OnVolumeHasChanged(VolumeHasChanged_t* pParam)
{
	m_OnVolumeHasChanged.Broadcast(pParam->m_flNewVolume);
}