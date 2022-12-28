
#ifndef TREE
#define TREE
#include <fstream>
#include "Node.h"

/*
Modifications:
 12/1: Loaded this file and wrote anything that needed updating for the Tree.cpp file
 12/6: Updated the Tree DTOR with a deletion all method to make sure the deletion was safe.
 */

class Tree
{
	public:
	
		Tree();													// Default CTOR
		//..........................................
		//POST: new tree is created with a root
		
		Tree(string questionText, string leftObject, string rightObject);	// CTOR when root info is known
		//..........................................
		//POST: new tree is created with a root with text questionText, plus two children:
		//		right child has text of rightObject, and left child has text of leftObject

		
		~Tree();												// DTOR
		//..........................................
		//POST: entire tree is deleted/freed and all dynamic memory cleared

        void deleteall(Node* pNode);
		
		
		bool IsEmpty(void) const;
		//..........................................
		//POST: RETURN T/F whether or not the root node of the Tree has children


		Node* GetRoot(void) const;
		//..........................................
		//POST: RETURN == address of root node

        void setTree(string questionText, string leftObject, string rightObject);


        void SaveTreeToFile(string outputFileName);
        void ReadTreeFromFile(string inputFileName);


	private:
		Node* root;    // pointer to root node of tree

        ofstream FOUT;
        ifstream FIN;

        // private methods
        void  RecursiveNodeSAVEtoFile(Node* root);
        Node* RecursiveNodeREADfromFile( );

};// class Tree

#endif

