#ifndef HOMEWORK4_HOMEWORK4_BINARY_SEARCH_TREE_H_
#define HOMEWORK4_HOMEWORK4_BINARY_SEARCH_TREE_H_
#include <iostream>
#include "student.h"
using namespace std;



struct TreeNode {
	Student data;
	TreeNode *left;
	TreeNode *right;
};


class BinarySearchTree {
private:
	TreeNode *root;
	void deleteTree(TreeNode * &) const;
	void copy(TreeNode * &, TreeNode * const &) const;
	void copyTree(BinarySearchTree const &);
	unsigned long long findMax() const;
	void traverseFromNode(const TreeNode *,unsigned long long) const;
	void addNode(TreeNode * &, Student const &) const;
    TreeNode* findFromNode(TreeNode*,unsigned long long) const;
    bool deleteNode(TreeNode * &, unsigned long long);

public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(BinarySearchTree const &);
	BinarySearchTree& operator=(BinarySearchTree const &);
	Student getRootData() const;
	TreeNode* getRootPtr() const;
	bool empty() const;

	void traverseInorder() const;
	void addStudent(Student const &);
	void findStudent(unsigned long long) const;
	void deleteStudent(unsigned long long);
};



#endif