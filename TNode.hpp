/*
 * TNode.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#ifndef TNODE_HPP_
#define TNODE_HPP_
#include <iostream>
#include "PersonInf.hpp"
using namespace std;

class TNode{
	friend class BST;
	TNode *left;
	TNode *right;
	TNode *parent;
	PersonInf *person;
	int height;
public:
	TNode(string sarr[]);
	TNode();
	~TNode();
	void printNode();
};



#endif /* TNODE_HPP_ */
