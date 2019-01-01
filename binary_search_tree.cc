#include "binary_search_tree.h"


BinarySearchTree::BinarySearchTree() {
	root = NULL;
}


BinarySearchTree::~BinarySearchTree() {
	deleteTree(root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree const &tree) {
	copyTree(tree);
}


BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree const &tree) {
	if (this != &tree) {
		deleteTree(root);
		copyTree(tree);
	}
	return *this;
}


void BinarySearchTree::deleteTree(TreeNode* &treeRoot) const {
	if (!treeRoot) {
		return;
	}
	deleteTree(treeRoot->left);
	deleteTree(treeRoot->right);
	delete treeRoot;
	treeRoot = NULL;
}


void BinarySearchTree::copyTree(BinarySearchTree const & tree) {
	copy(root, tree.root);
}

unsigned long long BinarySearchTree::findMax() const
{
	TreeNode* temp = root;
	while (temp->right) { temp = temp->right; }
	return temp->data.getFacNum();
}


void BinarySearchTree::copy(TreeNode* &dest, TreeNode * const &src) const {
	dest = NULL;
	if (src) {
		dest = new TreeNode;
		dest->data = src->data;
		copy(dest->left, src->left);
		copy(dest->right, src->right);
	}
}


bool BinarySearchTree::empty() const {
	return root == NULL;
}

Student BinarySearchTree::getRootData() const {
	return root->data;
}

TreeNode* BinarySearchTree::getRootPtr() const {
	return root;
}

void BinarySearchTree::traverseFromNode(const TreeNode *treeNode,unsigned long long max) const {
	if (!treeNode) {
		return;
	}
	traverseFromNode(treeNode->left,max);
	unsigned long long fn = treeNode->data.getFacNum();
	cout << fn;
	if (fn != max) { cout << ", "; }
	traverseFromNode(treeNode->right,max);
}

void BinarySearchTree::addNode(TreeNode * &treeNode, Student const &x) const {
	if (!treeNode) {
		treeNode = new TreeNode;
		treeNode->data = x;
		treeNode->left = NULL;
		treeNode->right = NULL;
		return;
	}
	if (x == treeNode->data) {
		treeNode->data = x;
	}
	if (x < treeNode->data) {
		addNode(treeNode->left, x);
	}
	else {
		addNode(treeNode->right, x);
	}
}

TreeNode* BinarySearchTree::findFromNode(TreeNode * treeNode, unsigned long long fn) const {
	if (!treeNode) {
		return treeNode;
	}

	if (treeNode->data.getFacNum() == fn) {
		return treeNode;
	}
	if (fn < treeNode->data.getFacNum()) {
		return findFromNode(treeNode->left,fn);
	}
	else {
		return findFromNode(treeNode->right,fn);
	}
}

bool BinarySearchTree::deleteNode(TreeNode * &root, unsigned long long fn) {
	bool found = false;
	if (!root) {
		return found;
	}
	if (fn < root->data.getFacNum()) {
		deleteNode(root->left, fn);
	}
	else if (fn > root->data.getFacNum()) {
		deleteNode(root->right, fn);
	}
	else {
		found = true;
		TreeNode *tempPtr;
		if (!(root->left)) {
			tempPtr = root;
			root = root->right;
			delete tempPtr;
		}
		else if (!(root->right)) {
			tempPtr = root;
			root = root->left;
			delete tempPtr;
		}
		else {
			tempPtr = root->right;
			while (tempPtr->left) {
				tempPtr = tempPtr->left;
			}
			root->data = tempPtr->data;
			deleteNode(root->right, tempPtr->data.getFacNum());

		}
	}

}

void BinarySearchTree::traverseInorder() const {
	unsigned long long max = findMax();
	traverseFromNode(root, max);
}

void BinarySearchTree::addStudent(Student const &x) {
	addNode(root, x);
}

void BinarySearchTree::findStudent(unsigned long long fn) const {
	TreeNode* temp = findFromNode(root,fn);
	if (!temp) { cout << "Record not found!\n"; }
	else { cout << temp->data; }
}

void BinarySearchTree::deleteStudent(unsigned long long fn) {
	if (deleteNode(root, fn)) { cout << "Record deleted!\n"; }
	else { cout << "Record not found!\n"; }
}