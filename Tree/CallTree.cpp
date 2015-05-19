#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

BinTreeNode* CreateBinTreePreOrder();
void TraverseBinTreePreOrder(BinTreeNode* binTree);
void TraverseBinTreeInOrder(BinTreeNode* binTree);
void TraverseBinTreePostOrder(BinTreeNode* binTree);
void BreadthFirstTraverse(BinTreeNode* root);

int main()
{
	// 创建一个指针，指向根节点
	BinTreeNode* binTree;
	// 测试数据：-+a##*b##-c##d##/e##f##
	binTree = CreateBinTreePreOrder();
	// 打印树
	cout << "\nTraverseBinTreePreOrder: " << endl;
	TraverseBinTreePreOrder(binTree);
	cout << "\n\nTraverseBinTreeInOrder: " << endl;
	TraverseBinTreeInOrder(binTree);
	cout << "\n\nTraverseBinTreePostOrder: " << endl;
	TraverseBinTreePostOrder(binTree);
	cout << "\n\nBreadthFirstTraverse: " << endl;
	BreadthFirstTraverse(binTree);
	return 0;
}

// 先序建立二叉树
BinTreeNode* CreateBinTreePreOrder()
{
	char node_value;
	cin >> node_value;
	BinTreeNode* binTree;
	// 输入#表结束
	if ('#' == node_value)
	{
		binTree = NULL;
	}
	else
	{
		binTree = new BinTreeNode;
		binTree->datum = node_value;
		binTree->lChild = CreateBinTreePreOrder();
		binTree->rChild = CreateBinTreePreOrder();
	}
	return binTree;
}

// 先序（前序）遍历二叉树，即根节点先访问
void TraverseBinTreePreOrder(BinTreeNode* binTree)
{
	if (NULL == binTree)
		return;
	cout << binTree->datum; // Visit(T)
	TraverseBinTreePreOrder(binTree->lChild);
	TraverseBinTreePreOrder(binTree->rChild);
}

// 深度优先：中序遍历二叉树，即根节点在中间访问
// 可确定二叉树中的pos值
void TraverseBinTreeInOrder(BinTreeNode* binTree)
{
	if (NULL == binTree)
		return;
	static int pos = 0;
	TraverseBinTreeInOrder(binTree->lChild);
	// Visit(T)
	binTree->pos = pos++;
	cout << binTree->datum;
	TraverseBinTreeInOrder(binTree->rChild);
}

// 后序遍历，即根节点在最后访问
void TraverseBinTreePostOrder(BinTreeNode* binTree)
{
	if (NULL == binTree)
		return;
	TraverseBinTreePostOrder(binTree->lChild);
	TraverseBinTreePostOrder(binTree->rChild);
	cout << binTree->datum; // Visit(T)
}

// 广度优先，不能用递归，用队列
// 可确定二叉树各节点所在的层次level
void BreadthFirstTraverse(BinTreeNode* root)
{
	queue<BinTreeNode *> nodeQueue; // STL中的queue
	int level = 0;
	nodeQueue.push(root);
	BinTreeNode *tmpNode = NULL;
	// 入一个空节点，表示root层结束; 在引入level值，实际上可以不需要用空节点了
	// 但作为练习目的，此段代码保留
	nodeQueue.push(tmpNode);
	BinTreeNode *node;
	while (!nodeQueue.empty())
	{
		node = nodeQueue.front(); // get队首元素
		nodeQueue.pop();
		if (NULL == node)
		{
			cout << endl;
			++level;
			if (NULL != nodeQueue.front())
				nodeQueue.push(tmpNode); // 入一个空节点，表示当前层结束
			continue;
		}
		// if (NULL != node)
		node->level = level;
		cout << node->datum << " level: " << node->level << " pos: " << node->pos << " ";
		if (NULL != node->lChild)
			nodeQueue.push(node->lChild); // 左节点入队
		if (NULL != node->rChild)
			nodeQueue.push(node->rChild); // 右节点入队
	}
}