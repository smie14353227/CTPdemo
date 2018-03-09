#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "MdSpi.h"

using namespace std;

TThostFtdcPasswordType pwd = "";

//获取行情，Api负责向后台发送请求，Spi由后台调用回报可自行实现
CThostFtdcMdApi *p_MdUserApi = NULL;
char front_addr[] = "tcp://180.168.146.187:10011";

//执行交易，Api，Spi同上



int main()
{
    //MD行情操作
    cout<<"获取行情\n";
    cout<<"password:";
    scanf("%s",pwd);
    p_MdUserApi = CThostFtdcMdApi::CreateFtdcMdApi();
    CThostFtdcMdSpi *p_MdUserSpi = new MdSpi;
    p_MdUserApi->RegisterSpi(p_MdUserSpi);
    p_MdUserApi->RegisterFront(front_addr);
    p_MdUserApi->Init();

    p_MdUserApi->Join();
    delete p_MdUserSpi;
    p_MdUserApi->Release();

    //Trader交易操作



    return 0;
}


