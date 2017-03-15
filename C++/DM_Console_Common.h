#pragma once

#include <stdio.h>
#include <algorithm>
#include <string>
#include<winsock2.h>
#include <conio.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//使用时需包含命名空间DM_Console_Common_Space
namespace DM_Console_Common_Space
{
	class DM_Console_Common
	{
	public:
		//Function 1
		//获取本机IP，需要系统对应的msvcr120.dll
		static string GetLocalIP();
		//string大小写转换,flag=true标示字符串转大写，flag=false表示字符串转小写，默认转大写
		static void str_trans(string &src, bool flag = true);
		//判断string是否由纯数字组成，需添加头文件 #include <conio.h>
		static bool isNum(string s);
	};
}

