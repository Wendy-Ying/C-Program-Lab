#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <winsock2.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <stdio.h> 
#pragma comment(lib, "WS2_32") // 链接到WS2_32.lib 

//初始化Socket函数，若初始化失败，直接退出
void CInitSock_func(BYTE minorVer, BYTE majorVer)
{
	// 初始化WS2_32.dll 
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(minorVer, majorVer);
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		exit(0);
	}
}



int main()
{
	CInitSock_func(2, 2);	//版本号：2.2
	//CDeleteSock_func();
	// 创建套节字 

	//创建一个文本文件，用于保存接收的内容
	FILE* pfile;
	fopen_s(&pfile, "Recv.csv", "w+");
	//如果创建失败，则直接退出
	if (pfile == NULL)
		return -1;

	//创建一个套接字句柄，采用TCP协议
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//用来指定套接字使用的地址格式，通常使用AF_INET 
	//指定套接字的类型，若是SOCK_DGRAM，则用的是udp不可靠传输 
	//配合type参数使用，指定使用的协议类型（当指定套接字类型后，可以设置为0，因为默认为UDP或TCP） 
	if (sockfd == INVALID_SOCKET)
	{
		printf("Failed socket() \n");
		return 0;
	}
	// 填充sockaddr_in结构 ,是个结构体 

	struct sockaddr_in sin;
	sin.sin_family = AF_INET;	//支持的协议簇
	sin.sin_port = htons(4567); //1024 ~ 49151：普通用户注册的端口号 ，目前采用4567端口
	sin.sin_addr.S_un.S_addr = INADDR_ANY;	//允许任何设备接入
	// 绑定这个套节字到一个本地地址 
	// TCP Server要先自己绑定后，进行侦听
	if (bind(sockfd, &sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("Failed bind() \n");
		return 0;
	}
	// 进入监听模式 
	//2指的是，监听队列中允许保持的尚未处理的最大连接数 
	if (listen(sockfd, 2) == SOCKET_ERROR)
	{
		printf("Failed listen() \n");
		return 0;
	}
	// 接受客户的连接请求 
	struct sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	SOCKET sClient = 0;
	char szText[] = " TCP Server connected! \r\n";

	// 接受一个新连接 
	//（(SOCKADDR*)&remoteAddr）一个指向sockaddr_in结构的指针，用于获取对方地址 
	sClient = accept(sockfd, &remoteAddr, &nAddrLen);
	if (sClient == INVALID_SOCKET)
	{
		printf("Failed accept()");
		return 0;
	}
	printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
	send(sClient, szText, strlen(szText) + 1, 0);// 向客户端发送数据 

	while (TRUE)
	{
		// 从客户端接收数据 
		char buff[256];
		int nRecv = recv(sClient, buff, 255, 0);	//完成一次接收
		if (nRecv > 0)
		{
			//当收到“$”时，直接结束侦听模式
			if (strstr(buff, "$") != NULL)
				break;
			buff[nRecv] = '\0';	//在接收到的字符串最后一个字节加'\0'，表示字符串结束
			printf(" 接收到数据：%d Bytes = %s\n", nRecv, buff);	//打印收到的字符串
			fwrite(buff, strlen(buff), 1, pfile);	//将收到的字符串写入文件
			send(sClient, buff, strlen(buff), 0);	//将收到的字符串返回发送给Client
		}
	}
	if(pfile)	//确认文件句柄有效
		fclose(pfile);	//关闭文件句柄
	closesocket(sClient);// 关闭同客户端的连接 

	closesocket(sockfd);// 关闭监听套节字 
	getchar();	//等待用户输入后，结束程序
	return 0;
}

