#include<iostream>

using namespace std;

int main()
{
	int **data;
	int m, n;
	cin >> m >> n;
	data = new int*[m]; //设置行 或直接int **data=new int*[m]; 一个指针指向一个指针数组。

	for (int j = 0; j<m; j++)
	{
		data[j] = new int[n];        //这个指针数组的每个指针元素又指向一个数组。
	}

	for (int i = 0; i<m; i++)

	{
		for (int j = 0; j<n; j++)
		{
			
			printf("%d行%d列元素：\n", i+1, j+1);
			scanf_s("%d", &data[i][j]);
			
		}

	}

	int **reverse = new int*[n];
	for (int i = 0; i < n; i++)
	{
		reverse[i] = new int[m];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			reverse[j][i] = data[i][j];
		}
	}

	cout << "翻转后的数组为:" << endl;
	for (int i = 0; i<n; i++)

	{
		for (int j = 0; j<m; j++)
		{

			printf("%d行%d列元素：%d\n", i + 1, j + 1,reverse[i][j]);


		}

	}


	for (int i = 0; i<m; i++)
	{
		delete[] data[i]; //先撤销指针元素所指向的数组
	}
	delete[] data;

	for (int i = 0; i<n; i++)
	{
		delete[] reverse[i]; //先撤销指针元素所指向的数组
	}
	delete[] reverse;
	
	system("pause");
}