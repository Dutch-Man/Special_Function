#include "DM_Console_Function.h"

int main()
{
	//���Ի�ȡ����IP�ĺ���GetLocalIP()
	string IP = GetLocalIP();
	printf("Local IP = %s\n", IP.c_str());

	system("pause");
	return 0;
}