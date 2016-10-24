#ifndef __COMMON_CPP_HEAD__
#define __COMMON_CPP_HEAD__

#include <stdio.h>
#include <iostream>
using namespace std;

#include <string>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")


//使用时需包含命名空间DM_Common_Space
namespace DM_Common_Space
{
	class DM_Common
	{
	public:
		//Function 1
		//获取本机IP，需要系统对应的msvcr120.dll
		static string GetLocalIP();
	};
}

#endif//__COMMON_CPP_HEAD__
