#include <iostream>
#include "AVLInterface.h"
#include "Node.h"



class AVL : public AVLInterface {
public:

	AVL() 
	{
		root = nullptr;
	}
	

	~AVL() 
	{
		clear();
	}

	Node * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();

	bool remove(Node*& local_root, int data);
	
	void replace(Node*& old_root, Node*& local_root);

	//int calc_height(Node *node);

	void balanceTree(Node *&node);

	//int get_height(Node *node);
		//int get_height();
	void rotateRight(Node *&localRoot);

	void rotateLeft(Node *&localRoot);

	void rotateRightLeft(Node *&localRoot);

	void rotateLeftRight(Node *&localRoot);

	//int calc_sum(Node *node);

	private:
		bool add(int data, Node *&node);
		void recursiveClear(Node *node);
		Node * root;
	
};