/* Node.cpp */
/*
12/1: I updated and wrote the methods within this file that needed to still be written.
      The bulk of the testing work was done in the testNode file
*/


#include<iostream>
#include<stdlib.h>

#include "Node.h"

// ======================================================================
Node::Node()					// Default CTOR
{		
	this->Qthing = DEFAULT_TEXT;
		
	this->left  = 0;			//make left and right point to NULL
	this->right = 0;
	
}// CTOR

// ======================================================================
Node::Node(const string text)	// CTOR when text is known
{
	this->Qthing = text;		
	this->left  = 0;			// make left and right point to NULL
	this->right = 0;
	
}// CTOR

// ======================================================================
Node::Node(const Node& old)		// COPY CTOR 
{
	this->Qthing = old.Qthing;
		
	this->left  = old.left;		// new copy still points to the same children!
	this->right = old.right;
	
}// COPY CTOR

// ======================================================================
Node::~Node()	// DTOR
{
	// Tree DTOR does the work ...
	
}


// ======================================================================
// ---------- SETTERS ------------------------

void Node::StoreText(const string /*in*/ newText)
{
	this->Qthing = newText;
														
}// StoreText

// ======================================================================
void Node::AppendRight(Node* /*in*/ newNode)
{
    this->right = newNode;

}// AppendRight


// ======================================================================
void Node::AppendLeft(Node* /*in*/ newNode)
{
    this->left = newNode;

}// AppendLeft


// ======================================================================
// ---------- GETTERS ------------------------

string Node::GetText() const
{
	return this->Qthing;		// return the text of current node

}// GetText


// ======================================================================
Node* Node::LChild() const
{

    return this->left;
	
}// LChild


// ======================================================================
Node* Node::RChild() const
{
	
    return this->right;
	
}// RChild


// ======================================================================
bool Node::IsLeaf() const
{
	if (this->left == 0 and this->right == 0)
        return true;
    else
        return false;

}// IsLeaf

// ======================================================================
// OUTPUT a Node object (show children, if any)
ostream& operator<< ( ostream& OUT, const Node& aNode ) {

    OUT << "----------------------------" << endl;
    OUT << "  " << aNode.GetText() << endl;
    if (aNode.LChild() != 0) {
        cout << "   /         \\" << endl;
        cout << aNode.LChild()->GetText();
    }
    if (aNode.RChild() != 0) {
        cout << "           " << aNode.RChild()->GetText() << endl;
    }
    OUT << "-----------------------------" << endl;
    return OUT;
}