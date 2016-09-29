#pragma once
#include <string>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")


//获取本机IP，需要系统对应的msvcr120.dll
string GetLocalIP();