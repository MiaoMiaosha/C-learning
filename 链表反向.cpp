#include<iostream>

using namespace std;

typedef struct Node    //һ�������Ľڵ�
{
	int data;//������
	struct Node * pNext;//ָ����
}NODE, *PNODE; 

PNODE init_list()
{
	int len;//����ĳ���
	int i;//ѭ������
	int val;//�ڵ��ֵ

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//���ͷ���

	if (NULL == pHead)
	{
		printf("����̬����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	else
	{
		printf("������Ҫ��������ĳ���len=");
		scanf_s("%d", &len);

		if (0 == len)
		{
			pHead->pNext = NULL;
			return pHead;  //�Կ�����Ĵ���
		}
		if (len<0)  //�Գ���Ϊ�����Ĵ���
		{
			printf("����ĳ��Ȳ���Ϊ������\n");
			exit(-1);
		}

		PNODE pTail = pHead;//pTailָ�����β�ڵ�
		pTail->pNext = NULL;

		for (i = 0; i<len; i++)
		{
			PNODE pNew = (PNODE)malloc(sizeof(NODE));//����µĽڵ�
			printf("�������%d���ڵ����ֵval =", i + 1);
			scanf_s("%d", &val);

			pNew->data = val;  //��ֵ
			pTail->pNext = pNew; //�����µĽڵ�
			pTail = pNew;      //pTail����
		}
		pTail->pNext = NULL;//���һ���ڵ��ָ�������Ϊ��
		return pHead; //����ͷ�����������ʾ��������


	}
}

Node* ReverseList(Node* pHead)
{
	Node* pReversedHead = NULL;
	Node* pNode = pHead;
	Node* pPrev = NULL;
	while (pNode != NULL)
	{
		Node* pNext = pNode->pNext;

		if (pNext == NULL)
		{
			pReversedHead = pNode;
		}

		pNode->pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}
int main()
{
	Node *p1 = init_list();
	cout << ReverseList(p1)->pNext->pNext->data << endl;
	system("pause");
}