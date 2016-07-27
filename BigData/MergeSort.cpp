// BigData.cpp : 定义控制台应用程序的入口点。
//
//归并排序
#include "stdafx.h"
#include<iostream>
using namespace std;

void merge(int array[], int p, int q, int r)
{
	int i, k;
	int begin1, begin2, end1, end2;
	int* temp = new int[2 * (r - p + 1)];
	begin1 = p;
	end1 = q;
	begin2 = q + 1;
	end2 = r;
	k = 0;
	while ((begin1 <= end1) && (begin2 <= end2))
	{
		if (array[begin1]<array[begin2])
		{
			temp[k] = array[begin1];
			begin1++;
		}
		else
		{
			temp[k] = array[begin2];
			begin2++;
		}
		k++;
	}
	while (begin1 <= end1) temp[k++] = array[begin1++];
	while (begin2 <= end2) temp[k++] = array[begin2++];
	for (i = 0; i<(r - p + 1); i++)
	{
		array[p + i] = temp[i];
	}
	delete[](temp);

}

void merge_Sort(int data[], int left, int right)
{
	if (left<right)
	{
		int mid = (left + right) / 2;
		merge_Sort(data, left, mid);
		merge_Sort(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}

int main() {

	int data[] = { 49,38,65,97,76,13,27,69 };
	merge_Sort(data, 0, 7);
	for (int i = 0; i <= 7; i++)
	{
		cout << data[i] << " ";
	}
	system("pause");
	return 0;

}
