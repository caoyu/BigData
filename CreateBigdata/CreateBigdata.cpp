//purpose:  生成随机的不重复的测试数据  
//copyright@ 2011.04.19 yansha  
//1000w数据量，要保证生成不重复的数据量，一般的程序没有做到。  
//但，本程序做到了。  
//July、2010.05.30。 
#include "stdafx.h"
#include <iostream>  
#include <time.h>  
#include <assert.h>  
using namespace std;

const int m_size = 10000000;
int num[m_size];

int main()
{
	int n;
	FILE *fp = NULL;
	fopen_s(&fp, "data.txt", "w");
	assert(fp);

	for (n = 1; n <= m_size; n++)
		//之前此处写成了n=0;n<size。导致下面有一段小程序的测试数据出现了0，特此订正。  
		num[n] = n;
	srand((unsigned)time(NULL));
	int i, j;

	for (n = 0; n < m_size; n++)
	{
		i = (rand() * RAND_MAX + rand()) % 10000000;
		j = (rand() * RAND_MAX + rand()) % 10000000;
		swap(num[i], num[j]);
	}

	for (n = 0; n < m_size; n++)
		fprintf(fp, "%d ", num[n]);
	fclose(fp);
	return 0;
}