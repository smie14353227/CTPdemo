#include <iostream>
#include <fstream>
#include "MdSpi.h"

using namespace std;

extern CThostFtdcMdApi *p_MdUserApi;
TThostFtdcBrokerIDType broker_id = "9999";
TThostFtdcInvestorIDType investor_id = "113771";
extern TThostFtdcPasswordType pwd = "";
char *pInstrumentID[] = {"cu1805","i1805","CF805","T1806"};
int InstrumentNum = 4;


///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void MdSpi::OnFrontConnected()
{
	cout<<"*连接成功!*\n";
	CThostFtdcReqUserLoginField loginReq;
	memset(&loginReq,0,sizeof(loginReq));
	strcpy(loginReq.BrokerID,broker_id);
	strcpy(loginReq.UserID,investor_id);
	strcpy(loginReq.Password,pwd);
	int i = p_MdUserApi->ReqUserLogin(&loginReq,0);
	if(!i)
		cout<<" 请求登录成功.\n";
	else
		cout<<" 请求登录失败.\n";

}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nTimeLapse 距离上次接收报文的时间
void MdSpi::OnFrontDisconnected(int nReason)
{
	cout<<"连接断开."<<endl;
	cout<<"错误编号:"<<nReason<<endl;
}

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void MdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cout<<"心跳超时警告."<<endl;
	cout<<"距离上次接受报文时间:"<<nTimeLapse<<endl;
}

///登录请求响应
void MdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**登录成功!**\n";
		cout<<"  日期:"<<pRspUserLogin->TradingDay<<endl;
		cout<<"  登录时间:"<<pRspUserLogin->LoginTime<<endl;
		cout<<"  经纪公司代码:"<<pRspUserLogin->BrokerID;
		cout<<"  用户代码:"<<pRspUserLogin->UserID;
		//subscribemarketdata
		int i = p_MdUserApi->SubscribeMarketData(pInstrumentID,InstrumentNum);
		if(!i)
			cout<<"  订阅行情成功!\n";
		else
			cout<<"  订阅行情失败!\n";
	}
	else
		cout<<"**登录失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg;
}

///登出请求响应
void MdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**登出成功!**\n";
		cout<<"  经纪公司代码:"<<pUserLogout->BrokerID<<endl;
		cout<<"  用户代码:"<<pUserLogout->UserID<<endl;
	}
	else
		cout<<"登出成功失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///错误应答
void MdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
		cout<<"错误应答.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///订阅行情应答
void MdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**订阅行情成功!**\n";
		cout<<"  合约代码:"<<pSpecificInstrument->InstrumentID<<endl;
		//输出到文件，定义表头
		char path[100];
		sprintf(path,"../data/%s_market_data.csv",pSpecificInstrument->InstrumentID);
		ofstream out1;
		out1.open(path,ios::out);
		out1<<"合约代码,交易日期,时间,最新价,上次结算价,昨收盘,昨持仓量,今开盘,最高价,最低价,数量,成交金额,持仓量,今收盘,本次结算价,涨停板价,跌停板价"<<endl;
		out1.close();
	}
	else
		cout<<"订阅行情失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///取消订阅行情应答
void MdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**取消订阅行情成功**!\n";
		cout<<"  合约代码:"<<pSpecificInstrument->InstrumentID<<endl;
	}
	else
		cout<<"取消订阅行情失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///订阅询价应答
void MdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**订阅询价成功!**\n";
		cout<<"  合约代码:"<<pSpecificInstrument->InstrumentID<<endl;
	}
	else
		cout<<"订阅询价失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///取消订阅询价应答
void MdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(!(pRspInfo && (pRspInfo->ErrorID!=0)))
	{
		cout<<"**取消订阅询价成功!**\n";
		cout<<"  合约代码:"<<pSpecificInstrument->InstrumentID<<endl;
	}
	else
		cout<<"取消订阅询价失败.错误代码:"<<pRspInfo->ErrorID<<" , 错误信息:"<<pRspInfo->ErrorMsg<<endl;
}

///深度行情通知
void MdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	cout<<"***深度行情***:"<<pDepthMarketData->InstrumentID<<" "<<pDepthMarketData->UpdateTime<<endl;
	//输出到本地文件
	char path[100];
	sprintf(path,"../data/%s_market_data.csv",pDepthMarketData->InstrumentID);
	ofstream out1;
	out1.open(path,ios::app);
	out1<<pDepthMarketData->InstrumentID<<","
		<<pDepthMarketData->TradingDay<<","
		<<pDepthMarketData->UpdateTime<<","
		<<pDepthMarketData->LastPrice<<","
		<<pDepthMarketData->PreSettlementPrice<<","
		<<pDepthMarketData->PreClosePrice<<","
		<<pDepthMarketData->PreOpenInterest<<","
		<<pDepthMarketData->OpenPrice<<","
		<<pDepthMarketData->HighestPrice<<","
		<<pDepthMarketData->LowestPrice<<","
		<<pDepthMarketData->Volume<<","
		<<pDepthMarketData->Turnover<<","
		<<pDepthMarketData->OpenInterest<<","
		<<pDepthMarketData->ClosePrice<<","
		<<pDepthMarketData->SettlementPrice<<","
		<<pDepthMarketData->UpperLimitPrice<<","
		<<pDepthMarketData->LowerLimitPrice<<endl;
	out1.close();
}

///询价通知
void MdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	cout<<"***询价***\n";
	cout<<"交易日:"<<pForQuoteRsp->TradingDay<<endl;
	cout<<"合约代码:"<<pForQuoteRsp->InstrumentID<<endl;
	cout<<"询价编号:"<<pForQuoteRsp->ForQuoteSysID<<endl;
	cout<<"询价时间:"<<pForQuoteRsp->ForQuoteTime<<endl;
	cout<<"业务日期:"<<pForQuoteRsp->ActionDay<<endl;
}











