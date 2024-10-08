// Copyright RYRY1002 <riley@riley.technology> (https://links.riley.technology). All Rights Reserved.
// Copyright 2020-2021 Russ 'trdwll' Treadwell <trdwll.com>. All Rights Reserved.
// Some portions of this code are Copyright Valve Corporation (https://www.valvesoftware.com). All Rights Reserved.

#include "Core/SteamHTTP.h"

#include "SteamworksUEUtils.h"

USteamHTTP::USteamHTTP()
{
	OnHTTPRequestCompletedCallback.Register(this, &USteamHTTP::OnHTTPRequestCompleted);
	OnHTTPRequestDataReceivedCallback.Register(this, &USteamHTTP::OnHTTPRequestDataReceived);
	OnHTTPRequestHeadersReceivedCallback.Register(this, &USteamHTTP::OnHTTPRequestHeadersReceived);
}

USteamHTTP::~USteamHTTP()
{
	OnHTTPRequestCompletedCallback.Unregister();
	OnHTTPRequestDataReceivedCallback.Unregister();
	OnHTTPRequestHeadersReceivedCallback.Unregister();
}

void USteamHTTP::OnHTTPRequestCompleted(HTTPRequestCompleted_t* pParam)
{
	m_OnHTTPRequestCompleted.Broadcast(pParam->m_hRequest, pParam->m_ulContextValue, pParam->m_bRequestSuccessful, (ESteamHTTPStatus::Type)pParam->m_eStatusCode, pParam->m_unBodySize);
}

void USteamHTTP::OnHTTPRequestDataReceived(HTTPRequestDataReceived_t* pParam)
{
	m_OnHTTPRequestDataReceived.Broadcast(pParam->m_hRequest, pParam->m_ulContextValue, pParam->m_cOffset, pParam->m_cBytesReceived);
}

void USteamHTTP::OnHTTPRequestHeadersReceived(HTTPRequestHeadersReceived_t* pParam)
{
	m_OnHTTPRequestHeadersReceived.Broadcast(pParam->m_hRequest, pParam->m_ulContextValue);
}
