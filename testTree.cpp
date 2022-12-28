/*
12/1: Used to test the written node class and objects and saw it was working.
      Tested the two means of creating a Tree and accesing it's two methods.
12/6: The testing was simple enough, I just added a DTOR message to see that in action.
      I took it out for the final submission but you can imagine it's utility.
 */

#include <iostream>
using namespace std;

#include<stdlib.h>

#include "Tree.h"
#include "Node.h"

int main(){

    // creating default tree
    Tree T;

    // param ctor
    Tree TP("Did they make the knockout stage?", "Brazil", "Canada");


    // testing IsEmpty method
    cout << T.IsEmpty() << endl;
    cout << TP.IsEmpty() << endl;

    // set tree
    T.setTree("root", "left answer", "right answer");

    // get root
    cout << *T.GetRoot() << endl;
    cout << *TP.GetRoot() << endl;

    return 0;
}



















