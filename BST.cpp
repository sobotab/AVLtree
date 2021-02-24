#include "BST.hpp"


BST::BST() {
	root = NULL;
}
BST::BST(string sarr[]) {
	root = new TNode(sarr);
}

bool BST::insert(string sarr[]) {
	TNode *newNode=new TNode(sarr);
	if (root == NULL) {
		root=newNode;
		return true;
	}
	TNode *currentNode=root;
	while (currentNode != NULL) {
		if (newNode->person->last < currentNode->person->last) {
			if (currentNode->left == NULL) {
				currentNode->left = newNode;
				newNode->parent=currentNode;
				setHeight(newNode);
				return true;
			} else {
				currentNode=currentNode->left;
			}
		} else if(newNode->person->last > currentNode->person->last) {
			if (currentNode->right == NULL) {
				currentNode->right=newNode;
				newNode->parent=currentNode;
				setHeight(newNode);
				return true;
			} else {
				currentNode=currentNode->right;
			}
		} else {
			return false;
		}
	}
	return false;
}

TNode *BST::find(string l, string f) {
	TNode *currentNode=root;
	while(currentNode != NULL) {
		if (l < currentNode->person->last) {
			if (currentNode->left == NULL) {
				return NULL;
			} else {
				currentNode=currentNode->left;
			}
		} else if (l > currentNode->person->last) {
			if (currentNode->right == NULL) {
				return NULL;
			} else {
				currentNode=currentNode->right;
			}
		} else {
			if (f == currentNode->person->first) {
				return currentNode;
			}
		}
	}
	return NULL;
}

void BST::printTreeIO(TNode *n) {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else if (n != NULL){
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreeIO() { // Just the start – you must write the recursive version
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void BST::printTreePre(TNode *n) {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else if (n != NULL){
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreePost(TNode *n) {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	} else if (n != NULL){
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

TNode *BST::remove(string s, string l) {
	TNode *searchNode=find(s, l);
	if (searchNode->left and searchNode->right) {
		TNode *currentNode=searchNode->left;
		if (searchNode == root) {
			if (currentNode->right) {
				while(currentNode->right != NULL) {
						currentNode=currentNode->right;
					}
					currentNode->left=searchNode->left;
					currentNode->parent->right=NULL;
					setHeight(currentNode->parent);
			} else {
				setHeight(currentNode->left);
			}
			currentNode->parent=NULL;
			currentNode->right=searchNode->right;
			root=currentNode;
			setHeight(currentNode);
			return searchNode;
		} else {
			if (currentNode->right) {
				while(currentNode->right != NULL) {
					currentNode=currentNode->right;
				}
				currentNode->left=searchNode->left;
				currentNode->parent->right=NULL;
				setHeight(currentNode->parent);
			} else {
				setHeight(currentNode->left);
			}
			currentNode->parent=searchNode->parent;
			currentNode->right=searchNode->right;
			if (searchNode->parent->right == searchNode) {
				searchNode->parent->right=currentNode;
			} else {
				searchNode->parent->left=currentNode;
			}
			setHeight(currentNode);
			return searchNode;
		}
	} else if (searchNode->left) {
		return removeOneKid(searchNode, true);
	} else if (searchNode->right) {
		return removeOneKid(searchNode, false);
	} else {
		return removeNoKids(searchNode);
	}
	return NULL;
}

TNode *BST::removeNoKids(TNode *tmp) {
	if (tmp == root) {
		root = NULL;
		return tmp;
	}
	if(tmp->parent->right == tmp) {
		tmp->parent->right = NULL;
	} else {
		tmp->parent->left = NULL;
	}
	setHeight(tmp->parent);
	return tmp;
}

TNode *BST::removeOneKid(TNode *tmp, bool leftFlag) {
	if (tmp == root) {
		if (leftFlag) {
			tmp->left->parent=NULL;
			root=tmp->left;
			setHeight(tmp->parent);
			return tmp;
		} else {
			tmp->right->parent=NULL;
			root=tmp->right;
			setHeight(tmp->parent);
			return tmp;
		}
	}
	if (tmp->parent->right == tmp) {
		if (leftFlag) {
			tmp->parent->right = tmp->left;
			tmp->left->parent=tmp->parent;
			setHeight(tmp->parent);
			return tmp;
		} else {
			tmp->parent->right = tmp->right;
			tmp->right->parent=tmp->parent;
			setHeight(tmp->parent);
			return tmp;
		}
	} else {
		if (leftFlag) {
			tmp->parent->left = tmp->left;
			tmp->left->parent=tmp->parent;
			setHeight(tmp->parent);
			return tmp;
		} else {
			tmp->parent->left = tmp->right;
			tmp->right->parent=tmp->parent;
			setHeight(tmp->parent);
			return tmp;
		}
	}
	return NULL;
}

void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

void BST::setHeight(TNode *n) {
	if (getBalance(n) >= 2) {
		if (getBalance(n->left) >= 1) {
			rotateRight(n);
		} else if (getBalance(n->left) <= -1){
			rotateLeft(n->left);
			rotateRight(n);
		}
	} else if (getBalance(n) <= -2) {
		if (getBalance(n->right) <= -1) {
			rotateLeft(n);
		} else if (getBalance(n->right) >= 1) {
			rotateRight(n->right);
			rotateLeft(n);
		}
	}
	if (n != NULL) {
		n->height=height(n);
		setHeight(n->parent);
	}
}

int BST::height(TNode *n) {
	if (n != NULL) {
		return max(height(n->left), height(n->right))+1;
	}
	return 0;
}

int BST::getBalance(TNode *tmp) {
	if (tmp != NULL) {
		return height(tmp->left) - height(tmp->right);
	}
	return 0;
}

TNode *BST::rotateLeft(TNode *tmp) {
	TNode *oRight=tmp->right;
	TNode *oRightLeft=tmp->right->left;

	if (tmp==root) {
		root=oRight;
	} else if (tmp->parent->right == tmp) {
		tmp->parent->right = oRight;
	} else if (tmp->parent->left == tmp) {
		tmp->parent->left= oRight;
	}

	oRight->left=tmp;
	oRight->parent=tmp->parent;
	tmp->parent=oRight;
	tmp->right=oRightLeft;

	if (oRightLeft) {
		oRightLeft->parent=tmp;
	}

	oRight->height=tmp->height-1;
	tmp->height=height(tmp);

	return oRight;
}

TNode *BST::rotateRight(TNode *tmp) {
	TNode *oLeft=tmp->left;
	TNode *oLeftRight=tmp->left->right;
	TNode *parent=tmp->parent;

	if (tmp == root) {
		root=oLeft;
	} else if (parent->left == tmp) {
		parent->left=oLeft;
	} else if (parent->right == tmp) {
		parent->right=oLeft;
	}

	oLeft->right=tmp;
	oLeft->parent=parent;
	tmp->parent=oLeft;
	tmp->left=oLeftRight;

	if (oLeftRight) {
		oLeftRight->parent=tmp;
	}

	tmp->height=height(tmp);
	oLeft->height=height(oLeft);

	return oLeft;
}


