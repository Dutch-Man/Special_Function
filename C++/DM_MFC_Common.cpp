#include "DM_MFC_Common.h"
using namespace DM_MFC_Common_Space;

//CStringתstd::string
string DM_MFC_Common::CString2string(CString CS)
{
	USES_CONVERSION;
	string s(W2A(CS));
	return s;
}

//stringתCString
CString DM_MFC_Common::string2CString(string CS)
{
	return (CString)CS.c_str();
}

