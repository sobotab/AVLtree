/*
 * MainPhrase.cpp
 *
 *  Created on: Apr 19, 2020
 *      Author: 13027
 */

#include <iostream>
#include "PersonTreeInfo.hpp"
using namespace std;

int main() {
	PersonTreeInfo *personTree = new PersonTreeInfo("people.txt");
	personTree->Interface();
	return 0;
}


