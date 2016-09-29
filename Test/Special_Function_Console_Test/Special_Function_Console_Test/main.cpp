#include "DM_Console_Function.h"

int main()
{
	//测试获取本机IP的函数GetLocalIP()
	string IP = GetLocalIP();
	printf("Local IP = %s\n", IP.c_str());

	system("pause");
	return 0;
}