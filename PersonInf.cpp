/*
 * PersonInf.cpp
 *
 *  Created on: Feb 21, 2021
 *      Author: Benjamin Sobota
 */

#include "PersonInf.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

PersonInf::PersonInf() {
	first="Ben";
	last="Sobota";
	age=20;
}

PersonInf::PersonInf(string sarr[]) {
	first=sarr[0];
	last=sarr[1];
	age=sarr[2];
}

