#include <iostream>
#include "Node.h"

int Node::getData() const
{
	return this->data;
}

Node * Node::getLeftChild() const
{
	return left;
}

Node * Node::getRightChild() const
{
	return right;
}


Node *& Node::getRight()
{
	return right;
}
Node *& Node::getLeft()
{
	return left;
}

int Node::getHeight()
{
	return height;
}
void Node::setHeight(int newHeight)
{
	height = newHeight;
}

int Node::get_height()
{
	return calc_height(this);
}

int Node::calc_height(Node *node)
{
	if (node == nullptr) 
	{         
		return 0;     
		}     
	if (node->left == nullptr && node->right == nullptr)
	 {         
		 return 1;     
	 }     
	 int leftHeight = calc_height(node->left);
	 int rightHeight = calc_height(node->right);
	 return (max(leftHeight, rightHeight) + 1);

}

int Node::calc_sum(Node *node)
{
	if (node == NULL) {
        return 0;
    }
    int rHeight = 0;
    int lHeight = 0;
    if (node->right != NULL) {
        rHeight = calc_height(node->right);
    }
    if (node->left != NULL) {
        lHeight = calc_height(node->left);
    }
    int balance = (rHeight - lHeight);
    return balance;

}
