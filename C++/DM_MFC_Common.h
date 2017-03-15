#pragma once

#include "stdafx.h"  //涉及到MFC
#include <stdio.h>
#include <string>
using namespace std;


//使用时需包含命名空间DM_MFC_Common_Space
namespace DM_MFC_Common_Space
{
	class DM_MFC_Common
	{
	public:
		//MFC若使用Unicode字符集，可以使用下面函数把CString类型转换为std::string类型
		static string CString2string(CString CS);
		//MFC若使用Unicode字符集，可以使用下面函数把string类型转换为CString类型
		static CString string2CString(string CS);
	};
}

