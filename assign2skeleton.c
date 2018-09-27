// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

// PROG8130 assignment #2 skeleton
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// structure defining a binary tree node.  Lower sorted values will go the the left, higher to the right.
struct nodeData {
	char name[30];				// character string of the data being stored in the node
	struct nodeData *left;		// pointer to the next node in the tree that is less than current node OR NULL if empty
	struct nodeData *right;		// pointer to the next node in the tree that is greater than current node OR NULL if empty
};


// data to be stored in tree.  In this case there is just a character string but this could have contained more

// replace inputData used for test put it in here and is created from Prog8130AssignDataCreator.exe 
// Used the following data in your assignment #1
char *inputData[12] = {
	{ "nwomo" },
	{ "ddouu" },
	{ "vcyfi" },
	{ "wsaeh" },
	{ "axykd" },
	{ "sgqsm" },
	{ "pdchj" },
	{ "uujlp" },
	{ "mxqnc" },
	{ "keoij" },
	{ "blome" },
	{ "ileci" }
};

// FUNCTION      : addToBinaryTree
//
// DESCRIPTION   :
//   This function will store the data in newNode into a binary tree according to alphabetical order
//
// PARAMETERS    :
//   newString - the string that is to be stored in the binary tree in alphabetica order
//	 *head - the root pointer to allow for recursions and traversing the binary tree.
// RETURNS       :
//   Nothing
void addToBinaryTree(struct nodeData *head, char *newString) {
	// add code to put items into binary tree in alphabetical order here
	// consider using strcmp library function to decide if a name is greater or less than
	struct nodeData *newPtr;

	newPtr = (struct nodeData *)malloc(sizeof(struct nodeData));

	strcpy(newPtr->name,newString);
	if (head == NULL)
	{
		head=newPtr;
		newPtr->left = newPtr->right = NULL;
	}
	else if (strcmp(newString, *head->name)<0) {
		addToBinaryTree(newPtr->left, newString);
	}
	else {
		addToBinaryTree(newPtr->right,newString);
	}
}

// FUNCTION      : printBinaryTree
//
// DESCRIPTION   :
//   This function will print the entire binary tree out.  You can choose to print
//   it using recursion but more marks will be awarded if you do it non recursively.
//
// PARAMETERS    :
//   *head - the pointer to allow recursions and traversing the binary tree.
//
// RETURNS       :
//   Nothing
void printBinaryTree(struct nodeData *head) {
	// add code to print data in order starting at the "head" pointer
	struct nodeData *tmpryPtr;
	tmpryPtr = head;
	while (tmpryPtr != NULL) {
		if (tmpryPtr != NULL) {
			if (tmpryPtr->left != NULL) {
				printBinaryTree(tmpryPtr->left);
			}
			else if (tmpryPtr->right != NULL) {
				printBinaryTree(tmpryPtr->right);
			}
			else {
				printf("\n%s", tmpryPtr->name);
			}
		}
	}
}



void main() {
	int i;

	struct nodeData *head = NULL;	// head of the binary tree
	
	// put all the data into the binary tree
	for (i = 0; i < 12; i++)
		addToBinaryTree(head,inputData[i]);

	// print the entire tree.  It should come out in alphabetical order because of the way it was stored in the tree
	printBinaryTree(head);
}
