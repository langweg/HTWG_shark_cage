
#include "stdafx.h"
#include <boost/test/included/unit_test.hpp>
#include "CageService.h"

BOOST_AUTO_TEST_CASE(existCageService)
{
	CageService service = CageService();
	BOOST_TEST(service != NULL);
	BOOST_TEST(service.CageManagerRunning() == false);
}

BOOST_AUTO_TEST_CASE(cageManagerRunning)
{
	CageService service = CageService();
	DWORD session_id = ::WTSGetActiveConsoleSessionId();
	service.StartCageManager(session_id);
	
	BOOST_TEST(service.CageManagerRunning() == true);
}

BOOST_AUTO_TEST_CASE(cageManagerRunning)
{
	CageService service = CageService();
	DWORD session_id = ::WTSGetActiveConsoleSessionId();
	wstring app_name = "%windir%\\notepad.exe";
	service.StartCageManager(&app_name, std::nullopt, session_id);

	BOOST_TEST(service.CageManagerRunning() == true)
}
