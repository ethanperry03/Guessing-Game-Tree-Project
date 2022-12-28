#include <iostream>
using namespace std;

#include "Node.h"

/*
Modifications:
 12/1: created and tested the node class to ensure they were outputting and being created correctly
 12/7: I went back through and made sure the documentation and comments were more clear for the tester.
       the conditions are nice checking of the various aspects of the node class on top of the original testing.
 */


int main() {

    // ---------------- default ------------------
    cout << "Default CTOR(0)" << endl;
    Node A;
    cout << "node A: " << endl << A << endl;

    // ------------ parameterized -----------------
    cout << "Param CTOR with string 'poobar' (1)" << endl;
    Node B("poobar");
    cout << "node B:" << endl << B << endl;

    // ------------ creating object from methods ---------------
    cout << 'creating object from methods(2)' << endl;
    Node C;
    C.StoreText("Is it childish?");
    Node *LC = new Node("poo");
    Node *RC = new Node("bar");
    C.AppendLeft(LC);
    C.AppendRight(RC);

    cout << "node C: " << endl << "The question is: " << C.GetText() << endl << C << endl;

    // ----------- copy CTOR (3) -------------------
    cout << "Copy CTOR (3) " << endl;
    Node D(C);
    cout << "node D: " << endl << D << endl;


// ================== left over testing from original file ===================
    // (0) get a default Node object
    Node N;
    string aQorThing;

    // (1) check default node's wording
    aQorThing = N.GetText();
    cout << "The question or thing is: " << aQorThing << endl;

    // (2) set a new question at this node
    N.StoreText("Is it alive?");
    cout << "The question or thing is: " << N.GetText() << endl;

    // (3) make two new Nodes, connect two objects for answers
    //      YES (left) ... (umm, you need to write, then use AppendLeft() )
    //      NO  (right) ...(umm, you need to write, then use AppendRight() )
    //          ... then you should write the "getters": LChild(), RChild() methods

    Node *L = new Node("dog");
    Node *R = new Node("rock");
    N.AppendLeft(L);
    N.AppendRight(R);

    // after you write AppendLeft(), AppendRight(), LChild(), and RChild() methods,
    // you can then:  cout Node objects (see the friend overloaded operator<<() method)
    cout << N << endl;

    cout << "Done." << endl;
    return 0;
}
