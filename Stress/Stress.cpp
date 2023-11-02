

/* 创建第一个线程。主进程结束，则撤销线程。 */
#include <iostream> 
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#define N 10
DWORD WINAPI ThreadFunc(LPVOID);
void Occupancy(int percent);
void  Occupancy_step_up(int percent);

void main()
{

	HANDLE hThread[N], hThread1, hThread2, hThread3;
	DWORD  threadId[N],threadId1, threadId2, threadId3;


	for (int i = 0; i < 10; i++)
	{
		hThread[i] = CreateThread(NULL, 0, ThreadFunc, 0, 0, &threadId[i]);
		Sleep(1000);
	}

	printf("我是主线程， pid = %d\n", GetCurrentThreadId());  //输出主线程pid
	Sleep(20000000);
}

DWORD WINAPI ThreadFunc(LPVOID p)
{
	printf("我是子线程， pid = %d\n", GetCurrentThreadId());   //输出子线程pid
	int i = 0;
	Occupancy_step_up(50);
	
	return 0;
}

void  Occupancy_step_up(int percent) 
{
	//模拟进程workload越来越重，从0到percent
	int i = 0;
	while (i < percent) {
		Occupancy(i);
		Occupancy(i);
		Occupancy(i);
		Occupancy(i);
		i++;
	}
	while (1) {
		Occupancy(percent);
		continue;
	}

}



void Occupancy(int percent)
{
	int s_stime = clock();
	
	while ((clock() - s_stime) < 16 * percent / 100) {
		continue;
	}
}




