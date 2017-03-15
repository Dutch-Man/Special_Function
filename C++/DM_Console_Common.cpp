#include "DM_Console_Common.h"
using namespace DM_Console_Common_Space;

//获取本机IP，需要系统对应的msvcr120.dll
string DM_Console_Common::GetLocalIP()
{
	std::string IP_string = "";
	WSADATA wsaData;
	char name[155];
	char *ip;
	PHOSTENT hostinfo;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
		if (gethostname(name, sizeof(name)) == 0) {
			if ((hostinfo = gethostbyname(name)) != NULL) { //这些就是获得IP的函数
				ip = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
				IP_string = ip;

			}
		}
		WSACleanup();
	}
	return IP_string;
}

//string大小写转换,flag=true标示字符串转大写，flag=false表示字符串转小写，默认转大写
void DM_Console_Common::str_trans(string &src, bool flag)
{
	transform(src.begin(), src.end(), src.begin(), flag ? toupper : tolower);
}

//判断string是否由纯数字组成
bool DM_Console_Common::isNum(string s)
{
	if (s.length()==0)
	{
		return   false;
	}
	for (int i = 0; i<s.size(); i++)
	{
		if (((s.at(i)>'9') || (s.at(i)<'0')) && (s.at(i) != '.')&&(s.at(i)!='-'))
		{
			return   false;
		}
	}
	return   true;
}