#pragma once

#include <stdio.h>
#include <algorithm>
#include <string>
#include<winsock2.h>
#include <conio.h>
#include <sstream>
#include <vector>
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
		//std::string转int，需添加头文件 #include <sstream>，转换失败返回-1
		static int string2int(string s);
		//std::string转float，需添加头文件 #include <sstream>，转换失败返回-1
		static float string2float(string s);
		//去掉string前后的空格
		static void trim(string &s);
		//以字符c为界分割字符串s分割,输出到返回向量中
		static vector<string> Split_string(string s, char c);
		//显示系统时间
		static void ShowTime();
		//获取系统时间(string字符串形式)
		static string GetTimeStr();
		//RGB转CMYK
		static void RGB2CMYK(BYTE R,BYTE G,BYTE B,BYTE &C,BYTE &M,BYTE &Y,BYTE &K);
		//CMYK转RGB
		static void CMYK2RGB(BYTE C,BYTE M,BYTE Y,BYTE K,BYTE &R,BYTE &G,BYTE &B);
	};
}

