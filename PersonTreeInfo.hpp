/*
 * PersonTreeInfo.hpp
 *
 *  Created on: Feb 23, 2021
 *      Author: Benjamin Sobota
 */

#ifndef PERSONTREEINFO_HPP_
#define PERSONTREEINFO_HPP_

#include <iostream>
#include <stdlib.h>
#include "BST.hpp"
using namespace std;

class PersonTreeInfo {
	string fn;
public:
	BST *tree;
	PersonTreeInfo(string filename);
	void readFile();
	string strip(string s, string sarr[]);

	void Interface();

};

#endif /* PERSONTREEINFO_HPP_ */
