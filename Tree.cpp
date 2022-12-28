
#include <iostream>
#include <stdlib.h>

#include "Tree.h"
#include "Node.h"
#include<stdlib.h>

/*
Modifications:
 12/1: similar to the other files, loading everything in and tuned up anything that needed help
 12/6: Wrote the deleteall method to safely make a recursive Tree DTOR
 */


// ======================================================================
Tree::Tree()								//CTOR
//..........................................
//POST: new tree is created with a root
{
	this->root = new Node;
	
	// NOTE:  we must use the functions in the Node class to change things!
	root->AppendLeft( 0 );
	root->AppendRight( 0 );

}//CTOR


// ======================================================================
Tree::Tree(string questionText, string leftObject, string rightObject)
//..........................................
//POST: new tree is created with a root with known question and left/right objects
{
    // new node with given question text is dynamically created and then this->root points there
	this->root = new Node(questionText);
	
	// NOTE:  we must use the functions in the Node class to change things!
	root->AppendLeft( new Node(leftObject) );
	root->AppendRight( new Node(rightObject) );

}//CTOR


/* ======================================================================
This recursively calls a deletion method that deletes leaf nodes first
 and works its way back up the tree to the root
 */
Tree::~Tree()								//DTOR
{
	deleteall(this->root);
	
} //DTOR


/*
 This method is saying if the left mode node pointer is not pointing to a zero (aka not a leaf)
 call this method again with that nodes left child. Continue until you reach a leaf, then call
 delete all with that nodes RChild, if that is a 0, delete the node. This is a clean alg that
 cleans up the tree (imagine a wildlife clip of a flower blooming but in reverse.
 */
void Tree::deleteall(Node* pNode){

    if (pNode != 0) {
        // delete all left children
        deleteall(pNode->LChild());

        // delete all right children
        deleteall(pNode->RChild());

        // delete pNode
        deleteall(pNode);
    }
}

/*
The same as the parameterized constructor but this one sets the values in main since
the tree T is previously defined and a constructor cannot be called twice on the same object.
this->Tree is getting its private data being set equal to the input parameters.
 */
void Tree::setTree(string questionText, string leftObject, string rightObject){
    // new node with given question text is dynamically created and then this->root points there
    this->root = new Node(questionText);

    // NOTE:  we must use the functions in the Node class to change things!
    root->AppendLeft( new Node(leftObject) );
    root->AppendRight( new Node(rightObject) );
}
	
// ======================================================================
bool Tree::IsEmpty(void) const
//..........................................
//POST: RETURN == whether or not the root node has children
{
    if (root->RChild() == 0  &&  root->LChild() == 0 )
        return true;
	else
        return false;
}// IsEmpty


// ======================================================================
Node* Tree::GetRoot(void) const
//..........................................
//POST: RETURN == address of root node
{
	return this->root;
}// GetRoot


// put this in Tree.cpp
// ======================================================================
void Tree::SaveTreeToFile(string outputFileName)
//..........................................
//POST: entire tree saved to a file
{
    this->FOUT.clear();                         // reset the stream just in case
    this->FOUT.open( outputFileName.c_str() );	// attempt to OPEN output FILE

    // TRAP
    if (FOUT.fail() )			// but did open fail?
    {
        cout << "ERROR: output file called " << outputFileName
             << " didn't open " << endl << "Program terminating ..." << endl;
        // system("PAUSE");
        exit(-1);
    } // if

    // call recursive (private) method to do all the work
    this->RecursiveNodeSAVEtoFile( this->root );

    this->FOUT.close();

} // SaveTreeToFile


// ======================================================================
void Tree::RecursiveNodeSAVEtoFile(Node* pNode)
//..........................................
// PRE:  outstream is open and ready
//       Assigned(pNode) (any node in tree)
// POST: pNode and children written to file
{

    this->FOUT << pNode->GetText() << endl;

    if ( pNode->LChild() != 0 )
    {
        this->FOUT << 1 << endl;
        RecursiveNodeSAVEtoFile( pNode->LChild() );
    }
    else
        this->FOUT << 0 << endl;


    if ( pNode->RChild() != 0 )
    {
        this->FOUT << 1 << endl;
        RecursiveNodeSAVEtoFile( pNode->RChild() );
    }
    else
        this->FOUT << 0 << endl;

} // RecursiveNodeSAVEtoFile


// ======================================================================
void Tree::ReadTreeFromFile(string inputFileName)
//..........................................
//POST: entire tree loaded from a file
{
    this->FIN.clear();					// reset the stream just in case
    this->FIN.open( inputFileName.c_str() );		// attempt to OPEN output FILE

    // TRAP
    if (FIN.fail() )			// but did open fail?
    {
        cout << "ERROR: input file called " << inputFileName
             << " didn't open " << endl << "Program terminating ..." << endl;
        // system("PAUSE");
        exit(-1);
    } // if

    // call recursive (private) method to do all the work
    this->root = this->RecursiveNodeREADfromFile( );

    this->FIN.close();

} // ReadTreeFromFile



Node* Tree::RecursiveNodeREADfromFile( )
//..........................................
// PRE:  ifstream is open and ready
//       Assigned(pNode) (any node in tree)
// POST: pNode and children read from file and saved in Tree

{
    short marker;
    string theText;
    string flushRestOfLine;

    getline(this->FIN, theText );
    Node* pNode = new Node(theText);

    this->FIN >> marker;   getline(this->FIN, flushRestOfLine );
    if (marker == 1 )
        pNode->AppendLeft( RecursiveNodeREADfromFile() );
    else
        pNode->AppendLeft(0);

    this->FIN >> marker;   getline(this->FIN, flushRestOfLine );

    if (marker == 1 )
        pNode->AppendRight( RecursiveNodeREADfromFile() );
    else
        pNode->AppendRight(0);


    return pNode;

} // RecursiveNodeREADfromFile
		
	
