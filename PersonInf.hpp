/*
 * PersonInf.h
 *
 *  Created on: Feb 21, 2021
 *      Author: Benjamin Sobota
 */

#ifndef PERSONINF_HPP_
#define PERSONINF_HPP_

#include <stdlib.h>
#include <iostream>
using namespace std;

class PersonInf {
	friend class TNode;
	friend class PersonTreeInfo;
	friend class BST;
	string first;
	string last;
	string age;
	int numstuff = 6;
public:
	PersonInf();
	PersonInf(string sarr[]);
};

#endif /* PERSONINF_HPP_ */
