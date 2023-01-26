#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node : public NodeInterface
 {

public:
	friend class AVL;
	int data;
	int height = 1;
	Node* left;
	Node* right;

	
	Node()
	{
		left = nullptr;
		right = nullptr;
	}
	Node(int &data) 
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	~Node() 
	{
		
	}
	void setHeight(int newHeight);
	int getHeight();

	int getData() const;

	Node * getLeftChild() const;

	Node * getRightChild() const;

	Node *&getRight();
	Node *&getLeft();

	int calc_sum(Node *node);
	int calc_height(Node *node);
	int get_height();



};