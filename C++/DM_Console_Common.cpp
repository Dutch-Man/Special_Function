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

//std::string转int，需添加头文件 #include <sstream>，转换失败返回-1
int DM_Console_Common::string2int(string s)
{
	if (!(isNum(s)))
	{
		return -1;//字符串包含非数字字符
	}
	stringstream ss;
	int n;
	ss << s;//可以是其他数据类型
	ss >> n; //string -> int
	return n;
}

//std::string转float，需添加头文件 #include <sstream>，转换失败返回-1
float DM_Console_Common::string2float(string s)
{
	if (!(isNum(s)))
	{
		return -1;//字符串包含非数字字符
	}
	stringstream ss;
	float n;
	ss << s;//可以是其他数据类型
	ss >> n; //string -> int
	return n;
}

//去掉string前后的空格
void DM_Console_Common::trim(string &s)
{
	if (s.empty())
	{
		return;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
}


//以字符c为界分割字符串s分割,输出到返回向量中
vector<string> DM_Console_Common::Split_string(string s, char c)
{
	vector<string> ret;
	string s_tmp;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			if (s_tmp.length()>0)
			{
				ret.push_back(s_tmp);
			}
			s_tmp.clear();
			continue;
		}

		s_tmp += s[i];

	}
	if (s_tmp.length()>0)
	{
		ret.push_back(s_tmp);
	}
	return ret;
}

//显示系统时间
void DM_Console_Common::ShowTime()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	printf("Time : %d:%d:%d.%d\n", tm.wHour, tm.wMinute, tm.wSecond, tm.wMilliseconds);
}

//获取系统时间(字符串形式)
string DM_Console_Common::GetTimeStr()
{
	char time_char[100];
	string time;
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	sprintf(time_char,"Time : %d:%d:%d.%d", tm.wHour, tm.wMinute, tm.wSecond, tm.wMilliseconds);
	time = time_char;
	return time;
}

//RGB转CMYK
void DM_Console_Common::RGB2CMYK(BYTE R,BYTE G,BYTE B,BYTE &C,BYTE &M,BYTE &Y,BYTE &K)
{
	double r, g, b;
	r = (double) R;
	g = (double) G;
	b = (double) B;

	r = 1.0 - (r / 255.0);
	g = 1.0 - (g / 255.0);
	b = 1.0 - (b / 255.0);

	double c, m, y, k;
	if (r < g)
		k = r;
	else
		k = g;
	if (b < k)
		k = b;

	c = (r - k)/(1.0 - k);
	m = (g - k)/(1.0 - k);
	y = (b - k)/(1.0 - k);

	c = (c * 100) + 0.5;
	m = (m * 100) + 0.5;
	y = (y * 100) + 0.5;
	k = (k * 100) + 0.5;

	C = (BYTE) c;
	M = (BYTE) m;
	Y = (BYTE) y;
	K = (BYTE) k;
}

//CMYK转RGB
void DM_Console_Common::CMYK2RGB(BYTE C,BYTE M,BYTE Y,BYTE K,BYTE &R,BYTE &G,BYTE &B)
{
	double r, g, b;
	double c, m, y, k;

	c = (double) C;
	m = (double) M;
	y = (double) Y;
	k = (double) K;

	c = c / 255.0;
	m = m / 255.0;
	y = y / 255.0;
	k = k / 255.0;

	r = c * (1.0 - k) + k;
	g = m * (1.0 - k) + k;
	b = y * (1.0 - k) + k;

	r = (1.0 - r) * 255.0 + 0.5;
	g = (1.0 - g) * 255.0 + 0.5;
	b = (1.0 - b) * 255.0 + 0.5;

	R = (BYTE) r;
	G = (BYTE) g;
	B = (BYTE) b;
}