Ethan Perry

Summary: This program allows the user to either load a file tree or build one themselves to then save it.
         It is a classic 20 questions style game where the user thinks of an object and the computer
         magically guesses it. Through this program, I understand the algorithm of this guessing and have come
         to realize it's beauty and simplicity.

Files Included:

    Node.h: The contains the prototype definitions of the node class including its methods and private data
    Node.cpp: This is where the prototypical definitions are written and are manipulating the actual data
    testNode.cpp: Where the affor-created node class was tested (CTOR's and methods)

    Tree.h: Writing tree class prototypes for the methods and defining the private data
    Tree.cpp: Filling in the methods to manipulate the data and use the tree class methods
    testTree.cpp: Tested the CTOR's, various methods, and ensured the recursive DTOR worked

    main.cpp: Here is the variety of functions needed to actually run the game such as load/save file,
              isAnswerYes, and myGuess. The code to get the tree to self update and run is there to
              create a new saved tree. The default way is to hard code a starting tree to then build out
              a game but there is also a file loader. You will need to uncomment certain lines to get
              the correct game sequence.

    WorldCup.txt:   This is a loaded game I created to guess one of the 32 WC teams. I also tested using a question
                    that doesn't split the data exactly in half to get an assymetric tree.
    NFLdivisions.txt: All the NFL teams guessing by division.


status: works well except for that printing bug I showed you. As I know of now, Q3 typically has it and the
        output for when I guess right. Other than that, works well!