#pragma once
#include <string>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")


//��ȡ����IP����Ҫϵͳ��Ӧ��msvcr120.dll
string GetLocalIP();