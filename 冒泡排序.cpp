#include<iostream>
#include<assert.h>
#include <stack>
#include <vector>
using namespace std;

/***ц╟ещеепР***/
void BubbleSort(int *a, int len)
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
int main(void)
{

	int a[5] = { 4, 2, 1, 0, 3, };
	int len = 5;
	BubbleSort(a, len);
	
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", a[i]);
	}
	
	
	system("pause");
}