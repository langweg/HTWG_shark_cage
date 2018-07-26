#pragma once

class CageManager
{
public:
	void CageManager::StartCage(SECURITY_ATTRIBUTES security_attributes, const CageData &cage_data);
	bool ProcessAlreadyRunning(const CageData &cage_data);

private:
	void StartCageLabeler(
		HDESK desktop_handle,
		const CageData &cage_data,
		const int work_area_width,
		const std::wstring &labeler_window_class_name);
	bool CageManager::ProcessRunning(const std::wstring &process_path);
	void CageManager::ActivateApp(
		const std::wstring &path,
		const HANDLE &event,
		const HDESK &desktop_handle,
		PROCESS_INFORMATION &process_info,
		SECURITY_ATTRIBUTES security_attributes,
		STARTUPINFO info,
		std::vector<HANDLE> &handles);

	// FIXME: extra class for this? process handling? -> could also do the wait stuff
	static BOOL CALLBACK GetOpenWindowHandles(_In_ HWND hwnd, _In_ LPARAM l_param);
	static BOOL CALLBACK GetOpenProcesses(_In_ HWND hwnd, _In_ LPARAM l_param);
	static BOOL CALLBACK CageManager::ActivateProcess(_In_ HWND hwnd, _In_ LPARAM l_param);
};