#pragma once

#include "Windows.h"
#include <string>
#include "FullWorkArea.h"

class CageDesktop
{
public:
	CageDesktop(
		PSECURITY_DESCRIPTOR p_sd, 
		const int work_area_width,
		const std::wstring &desktop_name);
	~CageDesktop();
	bool Init(HDESK &desktop_handle);
private:
	HDESK old_desktop;
	HDESK new_desktop;
	FullWorkArea full_work_area;
};