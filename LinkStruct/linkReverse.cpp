#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void print(struct Node* head);
struct Node* reverse(struct Node* head);
struct Node* reverseRecursion(struct Node* head);

int main(int argc, char *argv[])
{
	struct Node *pHead = NULL;
	struct Node *pNode1 = pHead, *pNode2;
	int data;
	/* test case:
	 * 1: c 空
	 * 2: 1c 1个节点
	 * 3: 1 2c 2个节点
	 * 4: 1 2 3 4 5c 5个节点
	 */
	while(cin >> data)
	{
		pNode2 = new(struct Node);
		if (!pHead)
			pHead = pNode1 = pNode2;
		pNode2->data = data;
		pNode1->next = pNode2;
		pNode1 = pNode2;
	}
	pNode2->next = NULL;
	print(pHead);
	
	// reverse link
	pHead = reverse(pHead);
	print(pHead);
	// reverse link by recursion
	pHead = reverseRecursion(pHead);
	print(pHead);
	
	return 0;
}

void print(struct Node* head)
{
	struct Node *pNode1 = head;
	while(pNode1)
	{
		cout << pNode1->data << "|--> ";
		pNode1 = pNode1->next;
	}
	cout << "NULL" << endl;
}

struct Node* reverse(struct Node* head)
{
	if (NULL == head || NULL == head->next)
		return head;
	struct Node *p1, *p2, *p3; // 需要3个指针
	p1 = head;
	p2 = p1->next;
	while(p2) // 注意这里是p2
	{
		// 简单的4步
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;
	return head;
}

struct Node* reverseRecursion(struct Node* head)
{
	if (NULL == head || NULL == head->next)
		return head;
	// 用与遍历树相同的理解方法，层层递归
	// 到最后一层相当于newHead = tail节点，head为newHead的上一个节点，返回
	struct Node *newHead = reverseRecursion(head->next);
	// 从最后两个节点开始反转
	head->next->next = head; // 注意：这里不能写成newHead->next = head; 因为返回的总是newHead，也就是之前的tail节点
	head->next = NULL;
	// 反转结束，递归反转前n-1个结点
	return newHead;
}