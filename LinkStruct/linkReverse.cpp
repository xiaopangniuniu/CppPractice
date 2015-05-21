#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

int main(int argc, char *argv[])
{
	struct Node *pHead = NULL;
	struct Node *pNode1 = pHead, *pNode2;
	int data;
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
	pNode1 = pHead;
	while(pNode1)
	{
		cout << pNode1->data << "|--> ";
		pNode1 = pNode1->next;
	}
	cout << "NULL" << endl;
	
	return 0;
}

struct Node* reverse(struct Node* input)
{
	if (NULL == input || NULL == input->next)
		return input;
	
}