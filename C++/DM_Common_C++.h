#ifndef __COMMON_CPP_HEAD__
#define __COMMON_CPP_HEAD__

#include <stdio.h>
#include <iostream> 
#include <algorithm>
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
		//string大小写转换,flag=true标示字符串转大写，flag=false表示字符串转小写，默认转大写
		static void str_trans(string &src, bool flag = true);
	};
}

#endif//__COMMON_CPP_HEAD__
