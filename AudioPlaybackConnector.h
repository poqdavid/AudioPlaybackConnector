#pragma once

#include "resource.h"

using namespace winrt::Windows::Data::Json;
using namespace winrt::Windows::Devices::Enumeration;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Media::Audio;
using namespace winrt::Windows::UI::Xaml;
using namespace Controls;
using namespace Hosting;
namespace fs = std::filesystem;

constexpr UINT WM_NOTIFYICON = WM_APP + 1;
constexpr UINT WM_CONNECTDEVICE = WM_APP + 2;

inline HINSTANCE g_hInst;
inline HWND g_hWnd;
inline HWND g_hWndXaml;
inline Canvas g_xamlCanvas = nullptr;
inline Flyout g_xamlFlyout = nullptr;
inline MenuFlyout g_xamlMenu = nullptr;
inline FocusState g_menuFocusState = FocusState::Unfocused;
inline DevicePicker g_devicePicker = nullptr;
inline std::unordered_map<std::wstring, std::pair<DeviceInformation, AudioPlaybackConnection>>
g_audioPlaybackConnections;
inline HICON g_hIconLight = nullptr;
inline HICON g_hIconDark = nullptr;
inline NOTIFYICONDATAW g_nid = {
	.cbSize = sizeof(g_nid),
	.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP | NIF_SHOWTIP,
	.uCallbackMessage = WM_NOTIFYICON,
	.uVersion = NOTIFYICON_VERSION_4
};
inline NOTIFYICONIDENTIFIER g_niid = {
	.cbSize = sizeof(g_niid)
};
inline UINT WM_TASKBAR_CREATED = 0;
inline bool g_reconnect = false;
inline std::vector<std::wstring> g_lastDevices;

#include "Util.hpp"
#include "I18n.hpp"
#include "SettingsUtil.hpp"
#include "Direct2DSvg.hpp"
