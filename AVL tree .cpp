#include <iostream>

using namespace std;

class AVL {
private: //data members
	
	class Node {
	public:
		int data;
		int height;
		Node* left;
		Node* right;

		Node(int val) {
			data = val;
			left = right = nullptr;
			height = 1;
		}

	};
	
	Node* root;

private:// functions

	// calculate height
	int height(Node* root) {
		if (root == nullptr)
			return 0;
		return root->height;
	}

	//calculating balance factor
	int getBalanceFactor(Node* root) {
		if (root == nullptr)
			return 0;
		return height(root->left) - height(root->right);
	}

	//Left rotation
	Node* rotateRight(Node* root) {
		Node* newRoot = root->left;
		Node* temp = newRoot->right;
		newRoot->right = root;
		root->left = temp;
		
		//update height
		root->height = max(height(root->left), height(root->right)) + 1;
		newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

		return newRoot;
	}

	//Right rotation
	Node* rotateLeft(Node* root) {
		Node* newRoot = root->right;
		Node* temp = newRoot->left;
		newRoot->left = root;
		root->right = temp;

		//update height
		root->height = max(height(root->left), height(root->right)) + 1;
		newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

		return newRoot;
	}
	
	//Inserting node
	Node* insertNode(Node* root, int value) {

		//deepest node is reached
		if (root == nullptr)
			return new Node(value);
		
		//if value more than current node then movint to the right node
		if (value > root->data)
			root->right = insertNode(root->right, value);

		//if value less than current node then moving to the left node
		else if (value < root->data)
			root->left = insertNode(root->left, value);

		//in other case value is inserted
		else
		{
			cout << "Element already inserted!!\n"; 
			return root;
		}

		//now update tree height
		root->height = max(height(root->left), height(root->right)) + 1;
		
		//now check balance factor
		int balanceFactor = getBalanceFactor(root);

		//left imbalance
		if (balanceFactor > 1) {
			//LL-rotation
			if (value < root->left->data)
				return rotateRight(root);
			//LR-rotation
			else if (value > root->left->data) {
				root->left = rotateLeft(root->left);
				return rotateRight(root);
			}
		}

		//right imbalance
		if (balanceFactor < -1) {
			//RR-rotation
			if (value > root->right->data)
				return rotateLeft(root);
			else if (value < root->right->data) {
				root->right = rotateRight(root->right);
				return rotateLeft(root);
			}
		}
		
		//returning root again in case balance was not needed
		return root;
	}

	// Node with minimum value
	Node* nodeWithMimumValue(Node* node) {
		Node* current = node;
		while (current->left != nullptr)
			current = current->left;
		return current;
	}

	//preorder traverse
	void printTree(Node* root) {
		if (root != nullptr) {
			cout << root->data << " ";
			printTree(root->left);
			printTree(root->right);
			
		}
	}

	//delete node
	Node* deleteNode(Node* root,int item) {
		//first traverse and find the node to delete
		if (root == nullptr)
			return root;
		if (item < root->data)
			root->left = deleteNode(root->left, item);
		else if (item > root->data)
			root->right = deleteNode(root->right, item);
		else {
			// Node woth only right child
			if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			// Node with only left child
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			// Node with only two child
			else {
				Node* temp = nodeWithMimumValue(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		
		root->height = max(height(root->left), height(root->right)) + 1; //update heigh;

		int bf = getBalanceFactor(root); //get balance factor of the current node

		//LL imbalance
		if (bf == 2 && getBalanceFactor(root->left) >= 0)
			return rotateRight(root); //R-rotation
		//LL imbalance
		else if (bf == 2 && getBalanceFactor(root->left) == -1)
		{
			//LR-rotation
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		//RR imbalance
		else if (bf == -2 && getBalanceFactor(root->right) <= 0)
			return rotateLeft(root); //R-rotation
		//RR imbalance
		else if (bf == -2 && getBalanceFactor(root->right) == 1) {
			//RL-rotation
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}

		return root;

	}

	//search node
	bool _searchNode(Node* root, int val) {
		if (root == nullptr)
			return false;
		else if (val == root->data)
			return true;
		else if (val > root->data)
			_searchNode(root->right, val);
		else if (val < root->data)
			_searchNode(root->left, val);
	}

public:

	//default constructor
	AVL(){
		root = nullptr;
	}
	//insert item
	void insert(int val){
		root = insertNode(root, val);
	}

	//display item
	void display() {
		printTree(root);
	}

	//delete item
	void deleteItem(int val) {
		root = deleteNode(root, val);
	}

	//search item
	bool searchItem(int val) {
		return _searchNode(root, val);
	}
};

int main()
{				
	AVL a1;
	a1.insert(33);
	a1.insert(13);
	a1.insert(53);
	a1.insert(9);
	a1.insert(21);
	a1.insert(61);
	a1.insert(8);
	a1.insert(11);
	a1.display();
	cout << endl;
	cout << boolalpha << a1.searchItem(11) << endl;

	a1.deleteItem(61);
	a1.display();
	cout << endl;
	cout << boolalpha << a1.searchItem(61) << endl;


	return 0;
}
