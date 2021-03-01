/*
 * PersonTreeInfo.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: 13027
 */

#include "PersonTreeInfo.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


PersonTreeInfo::PersonTreeInfo(string name) {
	fn = name;
	tree = new BST();
	readFile();
}


void PersonTreeInfo::Interface() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"****************************************************"<<endl;
		cout <<"Choose Option:\n  a\tGet Student\n  b\tadd a person\n  c\tremove a person\n  d\tprint tree\n  q\tquit"<< endl;
		cin >> c;
		switch (c) {
		case 'a': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			TNode *t = tree->find(l,f);
			if (t == NULL) {
				cout << f << " " << l <<" not found in database.  " << endl;
			}
			else {
				TNode *s = tree->find(l,f);
				s->printNode();
			}
			break;
		}
		case 'b':{
			string studarr[6];
			cout << "Enter Last: "<<endl;
			cin >> studarr[0];
			cout << "Enter First: " << endl;
			cin >> studarr[3];
			cout << "Enter Age: " << endl;

			if (tree->insert(studarr)) {
				cout << endl <<studarr[3] << "\t" << studarr[0]<< " inserted successfully "<<endl;
			}
			else {
				TNode *t = tree->find(studarr[0],studarr[3]);
				t->printNode();
				cout << "... already in tree with " << endl;
			}
			break;
		}
		case 'c': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			TNode *t = tree->remove(l,f);
			if (t == NULL) {
				cout << endl << f << " " << l << " not in tree " << endl;
			}
			else {
				t->printNode();
				cout << " ...has been removed. "<<endl;
			}
			break;
		}
		case 'd': {
			cout << "Choose a for pre, b for in, or c for post-order\t";
			char k;
			cin >> k;
			cout << endl;
			cout << "************************************************"<<endl;
			if (k == 'a') {
				cout << "*********** Printing Tree Pre Order ************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePre();
			}
			else if (k == 'b') {
				cout << "*********** Printing Tree In Order *************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreeIO();
			}
			if (k == 'c') {
				cout << "*********** Printing Tree Post Order ***********"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePost();
			}

			break;
		}
		}
	}
}

string PersonTreeInfo::strip(string s, string sarr[]) {
	const char* WhiteSpace = " \t\v\r\n";
	const char* EndChar = ":\t\n";
	for (int i = 0; i < 6; i++) {
		size_t start = s.find_first_not_of(WhiteSpace);
		int len = s.length();
		s = s.substr(start,len-start+1);
		size_t end = s.find_first_of(EndChar);
		if (end > 0){
			sarr[i] = s.substr(0,end);
			s = s.substr(end+1, len-end);
		}
	}
	return sarr[5];

}
void PersonTreeInfo::readFile() {
	ifstream file(fn.c_str());
	string word;
	string phrase;
	string sarr[6];
	file >> word;
	while (!file.eof()) {
		file >> word;
		getline(file,phrase);
		phrase = strip(phrase, sarr);
			tree->insert(sarr);
		file >> word;
	}
	tree->printTreeIO();
	return;
}



