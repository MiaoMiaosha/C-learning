#include<iostream>

using namespace std;

int main()
{
	int **data;
	int m, n;
	cin >> m >> n;
	data = new int*[m]; //������ ��ֱ��int **data=new int*[m]; һ��ָ��ָ��һ��ָ�����顣

	for (int j = 0; j<m; j++)
	{
		data[j] = new int[n];        //���ָ�������ÿ��ָ��Ԫ����ָ��һ�����顣
	}

	for (int i = 0; i<m; i++)

	{
		for (int j = 0; j<n; j++)
		{
			
			printf("%d��%d��Ԫ�أ�\n", i+1, j+1);
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

	cout << "��ת�������Ϊ:" << endl;
	for (int i = 0; i<n; i++)

	{
		for (int j = 0; j<m; j++)
		{

			printf("%d��%d��Ԫ�أ�%d\n", i + 1, j + 1,reverse[i][j]);


		}

	}


	for (int i = 0; i<m; i++)
	{
		delete[] data[i]; //�ȳ���ָ��Ԫ����ָ�������
	}
	delete[] data;

	for (int i = 0; i<n; i++)
	{
		delete[] reverse[i]; //�ȳ���ָ��Ԫ����ָ�������
	}
	delete[] reverse;
	
	system("pause");
}