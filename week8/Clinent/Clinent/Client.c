#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <winsock2.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <stdio.h> 
#pragma comment(lib, "WS2_32") // 链接到WS2_32.lib 

#define server_IP "127.0.0.1"	//127.0.0.1是本机IP地址
//#define server_IP "10.27.44.83"

//初始化Socket
void CInitSock(BYTE minorVer, BYTE majorVer)
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
	//设置类型	
	typedef struct
	{
		int stu_number;
		char name[20];
		int score;
	}score;
	score Transcripts[10];

	int i, j;
	for (i = 0; i < 10; i++)
	{
		Transcripts[i].stu_number = 0;
		Transcripts[i].name[0] = '\0';
		Transcripts[i].score = 0;
	}

	/*	for(i=0;i<10;i++)
		{
			printf("number:%d\t\tname:%s\t\tscore:%d\n",Transcripts[i].stu_number,Transcripts[i].name,Transcripts[i].score);
		}
		printf("\n");
	*/

	//打开二进制文件，开始读取数据
	FILE* pfile;
	pfile = fopen("D:/Study/studyc/data.bin", "rb");

	//按照score结构体读取十次，放到Transcripts数组
	fread(Transcripts, sizeof(score), 10, pfile);

	/*	for(i=0;i<10;i++)
		{
			printf("number:%d\t\tname:%s\t\tscore:%d\n",Transcripts[i].stu_number,Transcripts[i].name,Transcripts[i].score);
		}
		printf("\n");
	*/
	//读取数据完毕

	//排序	
	score temp;
	for (i = 0; i < 9; i++)
	{
		for (j = 8 - i; j >= 0; j--)
		{
			if (Transcripts[j].score < Transcripts[j + 1].score)
			{
				temp = Transcripts[j];
				Transcripts[j] = Transcripts[j + 1];
				Transcripts[j + 1] = temp;
			}
		}
	}

	//打印排序之后的数据
	for (i = 0; i < 10; i++)
	{
		printf("number:%d\t\tname:%s\t\tscore:%d\n", Transcripts[i].stu_number, Transcripts[i].name, Transcripts[i].score);
	}
	//排序完毕


	CInitSock(2, 2);//设置版本信息

	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);// 创建套节字，以TCP协议
	//若没有创建成功，直接退出
	if (sockfd == INVALID_SOCKET)
	{
		printf(" Failed socket() \n");
		return 0;
	}

	// 填写远程地址信息 
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);	//服务器端口号
	// 注意，这里要填写服务器程序（TCPServer程序）所在机器的IP地址 
	// 如果你的计算机没有联网，直接使用127.0.0.1即可 
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//服务器地址

	//连接TCP服务器，若失败，直接退出
	if (connect(sockfd, (const struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" Failed connect() \n");
		return 0;
	}
	char buff[256];
	char szText[256];

	//按照数组发送十次，每发送一次，等待服务器返回信息，但该返回信息仅打印，没有校验或者确认动作
	for(i=0; i<9; i++)
	{
		//从服务器端接收数据 
		int length = sizeof(servAddr);
		//先接收服务器返回信息
		int nRecv = recvfrom(sockfd, buff, 256, 0, (struct sockaddr*)&servAddr, &length);
		//int nRecv = recv(sockfd, buff, 256, 0);
		if (nRecv > 0)
			printf("接收到数据：%s\n", buff);

		// 向服务器端发送数据 
		//scanf_s("%s", Transcripts, 256);


		//send(sockfd, szText, strlen(szText), 0);

		//将数组元素依次打印到szText
		sprintf_s(szText, 256, "%d, %s, %d\n", Transcripts[i].stu_number, Transcripts[i].name, Transcripts[i].score);

		//将szText发送给服务器
		sendto(sockfd, szText, strlen(szText), 0, (const struct sockaddr*)&servAddr, sizeof(servAddr));
		//打印发送的字节数
		printf("Send %d Bytes\t", (int)strlen(szText));
	}
	//组成最后一帧的数据，即告知服务器结束
	szText[0] = '$';
	szText[1] = '\0';

	int length = sizeof(servAddr);
	//同样先接收最后一个从服务器返回的确认信息
	int nRecv = recvfrom(sockfd, buff, 256, 0, (struct sockaddr*)&servAddr, &length);
	//int nRecv = recv(sockfd, buff, 256, 0);
	if (nRecv > 0)
		printf("接收到数据：%s\n", buff);
	//发送最后一帧数据，client先退出
	sendto(sockfd, szText, strlen(szText) + 1, 0, (const struct sockaddr*)&servAddr, sizeof(servAddr));

	// 关闭套节字 
	closesocket(sockfd);

	//等待用户输入回车，结束程序
	getchar();
	return 0;
}
