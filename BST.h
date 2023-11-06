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
	ItemType remove();
	ItemType getRoot() const;
	bool isEmpty() const;

private:
	struct Node 
	{
		ItemType data;
		Node* right;
		Node* left;
	};

	Node* root;

	Node* insert(ItemType item, Node* tree);
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

}

template<typename ItemType>
void BST<ItemType>::insert(ItemType item)
{
	insert(item, root);
}

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
		tree = new Node;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (item < tree->data) {
		tree->left = insert(item, tree);
	}
	else {
		tree->right = insert(item, tree);
	}
	return tree;
}

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
