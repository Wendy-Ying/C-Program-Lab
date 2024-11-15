#include<pthread.h>
#include<stdio.h>

#pragma comment(lib, "pthreadVC2.lib")

void* thread(void* a)
{
	for (int i = 0; i < 30; i++)
	{
		printf("线程执行第 %d 次\n", i + 1);
	}
	return NULL;
}

void main()
{
	pthread_t id;
	int ret = pthread_create(&id, NULL, thread, NULL);
	if (ret != 0)
	{
		printf("线程创建错误！\n");
	}
	for (int i = 0; i < 30; i++)
	{
		printf("main函数执行第 %d 次\n", i + 1);
	}
	pthread_join(id, NULL);
}
