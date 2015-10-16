/***
排序算法实现：
冒泡、插入、快速、希尔、选择、归并
***/

#include<iostream>
#include<assert.h>
#include <stack>
#include <vector>
using namespace std;

/***冒泡排序***/
void bubble_sort(int *a, int len)
{
	int j;
	for (int i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < a[i])
			{
				swap(a[j], a[i]);
			}
		}
	}
}

void swap(int i, int j)
{
	int tmp;
	tmp = i;
	i = j;
	j = tmp;	
}

/***插入排序***/
void insert_sort(int *a, int left, int right)
{
	int tmp, j;
	int len = right - left + 1;
	for (int i = left+1; i <left+ len; i++)
	{
		tmp = a[i];
		for (j = i ; j > left && a[j-1] > tmp; j--)
		{
		//	a[j-1] = a[j]; 赋值颠倒后会发生有趣现象
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}

}

/***快速排序***/
void swap(int *a, int i, int j)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
int middle(int *a, int left,  int right)
{
	//三点确定中值法
	int mid = (left + right) / 2;
	if (a[left] > a[right])
		swap(a,left, right);
	//swap(a[left], a[right]);
	if (a[mid] > a[right])
		swap(a,mid, right);
		//swap(a[mid], a[right]);
	if (a[left] > a[mid])
		swap(a,left, mid);
		//swap(a[left], a[mid]);
	  //第一种swap不能使用，因为它只是实现了middle中a副本的交换，对真正的a数组并未起作用
	swap(a, mid, right - 1);
	return a[right - 1];
}

void quick_sort(int *a, int left, int right)
{
	int pivot = middle(a, left, right);
	if (left + 10 < right)
	{
		int i = left, j = right - 1;
		while (1){
			while (a[++i] < pivot){}
			while (a[--j]>pivot){}
			if (i < j)
			{
				swap(a[i], a[j]);
			}
			else
				break;
		}
		swap(a, i, right - 1);

		/* 这里不应该以mid划分
		quicksort(a, left, mid - 1);
		quicksort(a, mid + 1, right);
	*/
		quick_sort(a, left, i - 1);
		quick_sort(a, i + 1, right);
	}
	else
		insert_sort(a, left, right);
}

/***希尔排序***/
void shell_sort(int *a,int len)
{
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = 0; i < len; i++)
		{
			int j;
			int tmp = a[i];
			for (j = i; j >= gap && a[j-gap]>tmp; j -= gap)
				a[j] = a[j - gap];
			a[j] = tmp;
		}
	}
}

/***选择排序***/
void select_sort(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		int tmp = a[i],j;
			for (j = i; j < len; j++)
			{
				if (a[j] < tmp)
				{
					swap(a,j, i);
					tmp = a[i];
				}
			}
	}
}
/***归并排序***/
void merge(int *a, int leftPos,  int rightPos, int rightEnd)
{
	int len = rightEnd - leftPos + 1;
	int leftEnd = rightPos - 1;
	int *tmp=new int[len];
	int i = leftPos, j = rightPos, k = 0;
	while (i <= leftEnd && j <= rightEnd)
	{
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while (i <=leftEnd)
		tmp[k++] = a[i++];
	while (j <= rightEnd)
		tmp[k++] = a[j++];

	for (int v = 0; v < k; v++)
	{
		a[leftPos + v] = tmp[v];
	}

}
void merge_sort(int *a, int leftPos, int rightEnd)
{
	int mid = (leftPos + rightEnd) / 2;
	if (leftPos < rightEnd)
	{
		merge_sort(a, leftPos, mid);
		merge_sort(a, mid+1, rightEnd);
		merge(a, leftPos, mid+1, rightEnd);
	}
}

int main(void)
{

	int a[5] = { 4, 2, 8, 5, 0 };
	int b[12] = { 4, 2, 8, 5, 0, 1, 3, 6, 7, 9, 11, 10 };
	int len = 5;
	//insertSort(a, len);
	//quicksort(b, 0, 11);
	//quicksort(a, 0, 4);
	//shellsort(a,5);
	//selectsort(b,12);
	merge_sort(b, 0, 11);
	for (int i = 0; i < 12; i++)
	{
		printf("%d\n", b[i]);
	}
	
	
	system("pause");
}