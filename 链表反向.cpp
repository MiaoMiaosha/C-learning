//链表初始化和三个反向方法

#include<iostream>
using namespace std;
typedef struct Node    //一个单独的节点
{
	int data;//数据域
	struct Node * pNext;//指针域
}NODE, *PNODE; 

PNODE init_list()
{
	int len;//链表的长度
	int i;//循环开关
	int val;//节点的值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));//造出头结点

	if (NULL == pHead)
	{
		printf("链表动态分配失败！程序终止！\n");
		exit(-1);
	}
	else
	{
		printf("请输入要创建链表的长度len=");
		scanf_s("%d", &len);

		if (0 == len)
		{
			pHead->pNext = NULL;
			return pHead;  //对空链表的处理
		}
		if (len<0)  //对长度为负数的处理
		{
			printf("链表的长度不能为负数！\n");
			exit(-1);
		}

		PNODE pTail = pHead;//pTail指向的是尾节点
		pTail->pNext = NULL;

		for (i = 0; i<len; i++)
		{
			PNODE pNew = (PNODE)malloc(sizeof(NODE));//造出新的节点
			printf("请输入第%d个节点的数值val =", i + 1);
			scanf_s("%d", &val);

			pNew->data = val;  //赋值
			pTail->pNext = pNew; //连接新的节点
			pTail = pNew;      //pTail后移
		}
		pTail->pNext = NULL;//最后一个节点的指针域必须为空
		return pHead; //返回头结点以用来表示整个链表


	}
}

Node* reverse1(Node* pHead)
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

NODE* reverse2(NODE * head)
{
	NODE *pre = NULL;
	NODE* next;
	while (head)
	{
		next = head->pNext;
		head->pNext = pre;
		pre = head;
		head = next;
	}
	return pre;
}


NODE* reverse3(NODE * head)
{
	if (head == NULL || head->pNext == NULL)
		return head;
	NODE* newhead = NULL;
	newhead = reverse3(head->pNext);
	head->pNext->pNext = head;
	head->pNext = NULL;

	return newhead;
}

int main()
{
	Node *p1 = init_list();
	cout << reverse3(p1)->pNext->data << endl;
	system("pause");
}