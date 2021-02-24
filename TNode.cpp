/*
 * TNode.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string sarr[]) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	person = new PersonInf(sarr);
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	person = new PersonInf(sarr); // updated
}
TNode::~TNode(){
	cout <<"Deleting "<<person->first<<","<<person->last<<endl;
}
void TNode::printNode() {
	cout << "Height of node: " << height << endl;
	cout << "Name: ";
	cout << person->first << " "<<person->last << endl;
}
