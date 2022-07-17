#include <iostream>

using namespace std;

class BST {
private:
	//Node class
	class BinNode {
	public:
		int data;
		BinNode* left;
		BinNode* right;
		BinNode() = default;
		BinNode(int d, BinNode* l = NULL, BinNode* r = NULL) :data(d), left(l), right(r) {}
	};
	BinNode* root; //root

public:
	//default constructor
	BST() { 
		root = 0; 
	}

	//destructor
	~BST() {
		_destroyRecursively(root);
	}

	//copy constructor
	BST(const BST& other) {
		root = _copyConstructorHelper(other.root);
	}

	//assignment operator
	const BST& operator=(const BST& other) {
		if (this != &other) {
			this->~BST();
			root = NULL;
			if (!other.empty()) {
				root = _copyConstructorHelper(other.root);
			}
		}
		return *this;
	}

	//empty
	bool empty() const {
		return root == NULL;
	}

	//Insert Iteratively element
	void insertIteratively(int item) {
		_iterativeInsertion(item);
	}

	//Insert Recursively element
	void insertRecursively(int item) {
		_recursiveInsertion(root, item);
	}

	//Delete Node Iteratively
	void deleteIteratively(int item) {
		_iterativeDeletion(item);
	}

	//Delete Node Recursively
	void deleteRecursively(int item) {
		_deleteNodeRecursively(root, item);
	}

	//Search item Iteratively
	bool searchIteratively(int item) {
		bool found = false;
		BinNode* rootPtr = root;
		BinNode* parent = nullptr;

		while (rootPtr != nullptr && !found) {
			parent = rootPtr;
			if (item == rootPtr->data)
				found = true;
			else if (item > rootPtr->data)
				rootPtr = rootPtr->right;
			else if (item < rootPtr->data) {
				rootPtr = rootPtr->left;
			}
		}
		return found;
	}

	//Search item Recursively
	bool searchRecursively(int item) {
		return _recursiveSearch(root, item);
	}

	//Display functions:
	void displayIn() { //inorder
		_inOrder(root);
		cout << endl;
	}
	void displayPre() { //preorder
		_preOrder(root);
		cout << endl;
	}
	void displayPost() { //postorder
		_postOrder(root);
		cout << endl;
	}

	int heigh() {
		return _findHeight(root);
	}

private: //PRIVATE helper FUNCTIONS

	//Destructor recursively
	void _destroyRecursively(BinNode* node) {
		if (node != 0) {
			_destroyRecursively(node->left);
			_destroyRecursively(node->right);
			delete node;
		}
	}

	//Copy constructor helper
	BinNode* _copyConstructorHelper(BinNode* other) {
		if (other == NULL)
			return NULL;
		BinNode* newNode = new BinNode(other->data);

		newNode->left = _copyConstructorHelper(other->left);
		newNode->right = _copyConstructorHelper(other->right);

		return newNode;
	}

	//Display helper functions
	void _inOrder(BinNode* root) {
		if (root != 0) {
			_inOrder(root->left);
			cout << root->data << " ";
			_inOrder(root->right);
		}
	}
	void _preOrder(BinNode* root) {
		if (root != 0) {
			_preOrder(root->left);
			_preOrder(root->right);
			cout << root->data << " ";
		}
	}
	void _postOrder(BinNode* root) {
		if (root != 0) {
			cout << root->data << " ";
			_postOrder(root->left);
			_postOrder(root->right);
		}
	}

	//Insert Iteratively
	void _iterativeInsertion(int item)
	{
		BinNode* newNode = new BinNode(item);
		BinNode* rootPtr = root;
		BinNode* parent = nullptr;
		bool found = false;
		while (rootPtr != nullptr && !found) {
			parent = rootPtr;
			if (item > rootPtr->data) {
				rootPtr = rootPtr->right;
			}
			else if (item < rootPtr->data) {
				rootPtr = rootPtr->left;
			}
			else {
				found = true;
			}
		}

		if (!found) {
			if (parent == nullptr)
				root = newNode;
			else {
				if (item > parent->data)
					parent->right = newNode;
				else
					parent->left = newNode;
			}
		}
		else
			cout << "item already inserted\n";

	}

	//Insert Recursively
	void _recursiveInsertion(BinNode* &root, int item) {
		if (root == nullptr)
			root = new BinNode(item);
		else if( item == root->data)
			cout << "item already inserted\n";
		else if (item > root->data)
			_recursiveInsertion(root->right, item);
		else if (item < root->data)
			_recursiveInsertion(root->left, item);

	}

	//Search function for iterative deletion. It checks if item exists, finds Node to be deleted and its parent
	void _searchForIterativeDeletion(const int& item, bool& found, BinNode*& locPtr, BinNode*& parent)const {
		locPtr = root;
		parent = 0;
		found = false;
		while (locPtr != NULL && !found) {
			if (item == locPtr->data)
				found = true;
			else if (item > locPtr->data)
			{
				parent = locPtr;
				locPtr = locPtr->right;
			}
			else if (item < locPtr->data)
			{
				parent = locPtr;
				locPtr = locPtr->left;
			}
		}
	}
	//Deletion Iteratively
	void _iterativeDeletion(int item){
		bool found = false; // signals if item is found
		BinNode* x;			// points to node to be deleted
		BinNode* parent;	// parent of x and xSucc
		_searchForIterativeDeletion(item, found, x, parent);

		if (!found) {
			cout << "Item is not in the BST to delete\n";
			return;
		}

		if (x->left != 0 && x->right != 0) { // node has 2 children
			// Find x's inorder successor and its parent
			BinNode* xSuccessor = x->right; 
			parent = x;

			while (xSuccessor->left != 0) { // descend left
				parent = xSuccessor;
				xSuccessor = xSuccessor->left;
			}

			// Move contents of xSucc to x and change x 
			// to point to successor, which will be removed.
			x->data = xSuccessor->data;
			x = xSuccessor;

		} // end if node has 2 children

		// Now proceed with case where node has 0 or 2 child
		BinNode* subtree = x->left;  // pointer to a subtree of x (the one that is being removed)
		if (subtree == 0)
			subtree = x->left;
		if (parent == 0)   // root being removed
			root = subtree;
		else if (parent->left == x)  // left child of parent
			parent->left = subtree;
		else if (parent->right == x) // right child of parent
			parent->right = subtree;

		delete x; //removing node

	}

	//Deletion Recursively
	BinNode* _deleteNodeRecursively(BinNode* root, int item) {
		if (root == NULL)
			return root;
		else if (item < root->data)
			root->left = _deleteNodeRecursively(root->left, item);
		else if (item > root->data)
			root->right = _deleteNodeRecursively(root->right, item);
		else //item to be deleted is found and now we are going to remove it from tree
		{
			//case 1: If no child
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
				return root;
			}
			//case 2: One child
			else if (root->left == NULL) {
				BinNode* temp = root;
				root = root->right;
				delete temp;
				//return root;
			}
			else if (root->right == NULL) {
				BinNode* temp = root;
				root = root->left;
				delete temp;
				//return root;
			}
			//case 3: Two children
			else {
				//finding root's(element that will be deleted) rightside leftmost element's value (minimum of right subtree)
				//to replace the node that will be deleted
				int temp = _successor(root);
				root->data = temp;
				root->right = _deleteNodeRecursively(root->right, temp);
			}
		}
		return root;


		//if (root == NULL)
		//	return NULL;
		//else if (item > root->data)
		//	return _deleteNodeRecursively(root->right, item);
		//else if (item < root->data)
		//	return _deleteNodeRecursively(root->left, item);
		//else {
		//	if (root->left == NULL && root->right == NULL)
		//		return NULL;
		//	else if (root->right != NULL) {
		//		root->data = _successor(root);
		//		root->left = _deleteNodeRecursively(root->left, root->data);
		//	}
		//	else {
		//		root->data = _predecessor(root);
		//		root->left = _deleteNodeRecursively(root->right, root->data);
		//	}
		//}
		//return root;
	}

	//Search Recursively
	bool _recursiveSearch(BinNode* root, int item) {
		if (root == nullptr)
			return false;
		else if (item == root->data )
			return true;
		else if (item > root->data)
			_recursiveSearch(root->right, item);
		else if (item < root->data)
			_recursiveSearch(root->left, item);
	}

	//Successor finder of node
	int _successor(BinNode* root) {
		if (!empty()) {
			BinNode* successorPtr = root->right;
			while (successorPtr->left != NULL) {
				successorPtr = successorPtr->left;
			}
			return successorPtr->data;
		}
		else {
			cout << "BST is empty no successor\n";
			int* temp = new (int);
			int garbage = *temp;
			delete temp;
			return garbage;
		}
	}

	//Predecessor finder of node
	int _predecessor(BinNode* root) {
		if (!empty()) {
			BinNode* successorPtr = root->left;
			while (successorPtr->right!= NULL) {
				successorPtr = successorPtr->right;
			}
			return successorPtr->data;
		}
		else {
			cout << "BST is empty no successor\n";
			int* temp = new (int);
			int garbage = *temp;
			delete temp;
			return garbage;
		}
	}

	//Find height of BST
	int _findHeight(BinNode* root)
	{
		if (root == NULL)
			return -1;

		int leftHeight = _findHeight(root->left);
		int rightHeight = _findHeight(root->right);

		return max(leftHeight, rightHeight) + 1;
	}


};
