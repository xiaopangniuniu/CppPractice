#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

class BinTreeNode
{
public:
	BinTreeNode();

	char datum;
	int level;
	int pos;
	BinTreeNode* lChild;
	BinTreeNode* rChild;
}; // ... end of BinTreeNode

#endif
