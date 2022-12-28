using namespace std;
#include <iostream>
#include "Tree.h"
#include "Node.h"
#include<stdlib.h>
#include<cstring>

/*
 Date modified:
 12/2: started to try to build the trees to get the game working
 12/3: played the whole game and created two trees that were pretty cool and thoroughly enjoyed that process.
 12/7: Worked on the flow for user and the outputting being well formatted.
       Also added a feature where for all intents and purposes, the user can start a new game or load a saved one.
 12/8: Finished up documentation and submitted
 */

/*
This is used to prompt the user if they would like to play again after the current game ends
It is just called without input and the user is prompted yes or no, a bool answer is returned in the
if statement to continue the game or not.
 */
bool playAgain(){
    string userInput;
    cout << "Want to play again? (Y or N): ";
    getline(cin, userInput);

    if (userInput == "Y" or userInput == "y")
        return true;
    else
        return false;
}

/*
This is called each time to get the answer to the question at each node.
It is called and the answer is returned in bool to be used in an if statement.
 */
bool answerYes(){

    string answer;
    getline(cin, answer);

    if (answer == "Y" or answer == "y")
        return true;
    else
        return false;
}

/*
Output method for when the guess is correct. The leaf node (which is the left side for yes)
which holds the answer is passed into the function and the proper gettext() gets the text
corresponding to the yes answer.
 */
void iWon(const Node* p){
    cout << "-------------------------------------" << endl;
    cout << "It was " << p->GetText() << "!" << endl;
    cout << "I knew it. Better luck next time." << endl;
    cout << "-------------------------------------" << endl;
}

/*
This function guesses the left text of a pre-leaf node which askes the second to last question.
The pointer to the leaf of yes is passed and that text is outputted as a guess.
This is an output method that will be followed by isYes method to get the answer.
 */
void myGuess(const Node* p){
    cout << "Is it " << p->GetText() << "?" << " (Y/N)";
}

/*
When the guess is wrong, a new question is added so that the model can updated and grow its answer capabilties.
The p node is passed and allowed to be changed
Post: The previous getText is pushed down to the left as the Y answer and what the model failed to guess is at
 the no side. This prompts the user to answer an appriate answer so that this new node can add a layer of guessing
 ability to teach this model more answers.
 */
void addNewQ(Node* p){
    string answer;
    cout << "What was it?" << endl;
    getline(cin, answer);

    string newQ;
    cout << "Enter a question that is 'YES' for " << p->GetText() << " and 'NO' for " << answer << ": " << endl;
    getline(cin, newQ);

    Node *left = new Node(p->GetText());
    Node *right = new Node(answer);

    p->AppendLeft(left);
    p->AppendRight(right);
    p->StoreText(newQ);

}

/*
When called, this function asks the user for the tree file they wish to load and returns it as a string
 */
string loadFile() {

    string file;
    cout << "enter file name you wish to load:" << endl;
    getline(cin, file);

    return file;
}

int main(){

    // WC root I used
    //Tree T("Did they make the knockout stage?", "Netherlands", "Canada");

    // NFL division root
    //Tree T("Is the team in the AFC?", "Ravens", "Rams");

    // Or to test
    // Tree Test("foobar", "foo", "bar");

    Tree T;                  // this creates the default tree when a file is being read in oppose to building a game
    Node *p;                 // new node that is used to move around the tree
    Node *leftyes;           // node to point to the left of wherever p is at
    Node *rightno;           // node to point to the right of wherever p is at

    // string game;          // didn't use this either but it goes with play game method provided
    bool iWantToPlayAgain;   // bool that will hold response to play again method
    short counter = 1;       // counter for question numbering

    cout << "Do you wish to load a file game?(y/n)" << endl;

    if(answerYes()){
        string infile = loadFile();                   // saves the string returned by this function
        T.ReadTreeFromFile(infile);
    }
    else{
        string rootQ, aLeft, aRight;                // these strings hold the new root and answers when a game is started

        cout << "Enter root question" << endl;
        getline(cin, rootQ);

        cout << "Enter answer on the left(yes)" << endl;
        getline(cin, aLeft);

        cout << "Enter answer on the right(no)" << endl;
        getline(cin, aRight);

        T.setTree(rootQ, aLeft, aRight);
    }

    do {
        p = T.GetRoot();                // p starts at the root

        while(!(p->IsLeaf())){          // while it is not the end of the tree (a leaf node)

            cout << "Q#" << counter << " | " << p->GetText() << ": (Y/N)";
            cout.flush();
            leftyes = p->LChild();      // pre-sets leftyes as the pointer to the Left child (node method)
            rightno = p->RChild();      // pre-sets rightno as the pointer to the right child (node method)

            if(answerYes())             // asks the user to input answer to the question posed (Y/N)
                p = leftyes;            // if answer is yes, then the pointer goes to left node
            else
                p = rightno;            // if answer is not yes, pointer goes to the right side

            counter++;                  // counter increments
        }

        myGuess(p);                     // this is where the script makes its guess

        if (answerYes())                // asks user if the guess what right
            iWon(p);                    // if yes, a winning message is outputted.
        else
            addNewQ(p);                 // else, add new Q to grow the tree

        p = T.GetRoot();                // reset (left in from original code but not explicitly needed)
        counter = 1;                    // reset counter for a new game

        iWantToPlayAgain = playAgain(); // prompts to play again

    } while (iWantToPlayAgain);         // while user still want to play

    cout << "Input file: " << endl;
    string file;
    getline(cin, file);            // where do they want to save the game to

    T.SaveTreeToFile(file);  // save file inputted to save the game

    return 0;
}

/*
I actually didn't end up using this but left it in
 */
void playGame(Node* currP, Tree &T){
    currP = T.GetRoot();
    while(!currP->IsLeaf()){
        cout << currP->GetText() << endl;
        if(answerYes())
            currP = currP->LChild();
        else
            currP = currP->RChild();
    }
}