#include <iostream>
#include "AVL.h"

using namespace std;

Node * AVL::getRootNode() const
{
	return this->root;
}


void AVL::balanceTree(Node *&node)
{
	if(node == nullptr)
	{
		return;
	}
	
	int total = node->calc_sum(node);
	if (total < -1)
	//left imbalance
	{
		if (node->calc_sum(node->left) <= 0)
		{
			rotateRight(node);
		}
		else
		{
			rotateLeftRight(node);
		}
	}
	else if (total > 1)
	{
		if (node->calc_sum(node->right) >= 0)
		{
			rotateLeft(node);
		}
		else
		{
			rotateRightLeft(node);
		}
	}
}

void AVL::rotateRight(Node *&localRoot)
{
	Node *temp = localRoot;
	localRoot = localRoot->left;
	temp->left = localRoot->right;
	localRoot->right = temp;
}

void AVL::rotateLeft(Node *&localRoot)
{
	Node *temp = localRoot;
	localRoot = localRoot->right;
	temp->right = localRoot->left;
	localRoot->left = temp;
}

void AVL::rotateRightLeft(Node *&localRoot)
{
	rotateRight(localRoot->right);
	rotateLeft(localRoot);
}

void AVL::rotateLeftRight(Node *&localRoot)
{
	rotateLeft(localRoot->left);
	rotateRight(localRoot);
}

bool AVL::add(int data)
{
	return add(data, this->root);
}

bool AVL::add(int data, Node *&node)
{
	
	if(node == nullptr)
	{
		node = new Node(data);
		return true;
	}
	if(node->getData() == data)
	{
		return false;
	}
	if(data < node->getData())
	{
		bool rval = add(data, node->left);
		if(rval)
		{
			balanceTree(node);
		}
		return rval;
	}
	else
	{
		bool rval = add(data, node->right);
		if(rval)
		{
			balanceTree(node);
		}
		return rval;
	}
	
}


bool AVL::remove(int data)
{
	return remove(this->root, data);
}

bool AVL::remove(Node*& local_root, int data)
{
	if(local_root == nullptr)
	{
		return false;
	}
	else
	{
		if(data < local_root->data)
		{
			bool rval = remove(local_root->left, data);
			if(rval)
			{
				balanceTree(local_root);
			}
			return rval;
		}
		else if(data > local_root->data)
		{
			bool rval = remove(local_root->right,data);
			if(rval)
			{
				balanceTree(local_root);
			}
			return rval;
		}
		else 
		{
			Node* old_root = local_root;
			if(local_root->right == nullptr)
			{
				local_root = local_root->left;
				delete old_root;
				balanceTree(local_root);
			
			}
			else if(local_root->left == nullptr)
			{
				local_root = local_root->right;
				delete old_root;
				balanceTree(local_root);
			}
			else 
			{
				replace(old_root, local_root->left);
				balanceTree(local_root);
			}
			return true;
			
		}
	}
}

void AVL::replace(Node*& old_root, Node*& local_root)
{
	if(local_root->right != nullptr)
	{
		replace(old_root, local_root->right);
	}
	else
	{
		old_root->data = local_root->data;
		remove(old_root->left, local_root->data);
	}
}

void AVL::clear()
{
	recursiveClear(this->root);
	this->root = nullptr;
}

void AVL::recursiveClear(Node *node)
{
	if(node != nullptr)
	{

		recursiveClear(node->getLeft());
		recursiveClear(node->getRight());
		delete node;
	}
}