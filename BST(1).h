// BST.h
// Group 2



#ifndef BST_H
#define BST_H

template<typename ItemType>
class BST
{
public:
	BST();
	~BST();

	void insert(ItemType item);
	//ItemType pop();
	void inorderTraversal();
	ItemType getRoot() const;
	bool isEmpty() const;

private:
	struct Node 
	{
		ItemType data;
		Node* left;
		Node* right;

		Node(ItemType item) {
			data = item;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;

	Node* insert(ItemType item, Node* tree);
	//Node* pop(Node* tree);
	void makeEmpty(Node* tree);
};



template<typename ItemType>
BST<ItemType>::BST()
{
	root = nullptr;
}

template<typename ItemType>
BST<ItemType>::~BST()
{
	makeEmpty(root);
}

template<typename ItemType>
void BST<ItemType>::insert(ItemType item)
{
	insert(item, root);
}

//template<typename ItemType>
//ItemType BST<ItemType>::pop()
//{
//	if (root == nullptr) {
//		throw std::runtime_error("BST is empty.");
//	}
//	Node* lowestNode = pop(root);
//	return lowestNode->data;
//}

template<typename ItemType>
ItemType BST<ItemType>::getRoot() const
{
	return root->data;
}

template<typename ItemType>
bool BST<ItemType>::isEmpty() const
{
	return root;
}



template<typename ItemType>
typename BST<ItemType>::Node* BST<ItemType>::insert(ItemType item, Node* tree)
{
	if (tree == nullptr) {
		return new Node(item);
	}
	else if (item < tree->data) {
		tree->left = insert(item, tree->left);
	}
	else {
		tree->right = insert(item, tree->right);
	}
	return tree;
}

//template<typename ItemType>
//typename BST<ItemType>::Node* BST<ItemType>::pop(Node* tree)
//{
//	if (tree->left == nullptr) {
//		Node* temp = tree->right;
//		delete tree;
//		return temp;
//	}
//	tree->left = pop(tree->left);
//	return tree;
//}

template<typename ItemType>
void BST<ItemType>::makeEmpty(Node* tree)
{
	if (tree->right != nullptr) {
		makeEmpty(tree->right);
	}
	if (tree->left != nullptr) {
		makeEmpty(tree->left);
	}
	delete tree;
}

#endif
