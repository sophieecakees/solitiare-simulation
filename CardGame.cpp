#include "pch.h"
#include <fstream>
#include "cards.h"
#include "SophiaFinalStackFunc.h"
int main()
{
	const int N = 30; //Deck limit
	const int HandS = 5;//hand size
	string card[N]; string hand[HandS];
	string CurSuit;	string temp;
	int CurNum; int head = 0; int tail = 0; int counter = 0;
	int HandHead = 0; int HandTail = 0; int HandCounter = 0;
	string filename = "deck.txt"; ifstream inFile;//used for getting elements from a file
	inFile.open(filename);
	if (inFile.fail())//failcheck for infile closes program if not found.
	{
		cerr << "error opening file"; exit(1);
	}
	inFile >> CurSuit;  inFile >> CurNum;//skips first two since they are only amount of suits and numbers.
	for (int i = 0; i < N; i++)//goes until end of text file
	{
		inFile >> CurSuit; inFile >> CurNum;//gets suit, then gets the number
		temp = CurSuit + " " + to_string(CurNum);//combines both string and int into a string
		push(card, N, head, tail, temp, counter);//pushes the temp into the deck
	}
	inFile.close();
	GetHand(card, N, head, tail, counter, hand, HandS, HandHead, HandTail, HandCounter);//gets 5 cards from deck into hand
	Node* aStack = NULL;Node* bStack = NULL;Node* cStack = NULL;
	bool pikaCountA = false;bool pikaCountB = false;bool pikaCountC = false;
	int answer = 0;
	Node* stack1 = NULL;Node* stack2 = NULL;
	Node* stack3 = NULL;Node* stack4 = NULL;Node* stack5 = NULL;
	while (answer != 5)
	{
		system("CLS");//clears the screen(seems to not work on geany though) but will let the program continue
		if (pikaCountA == true && pikaCountB == true && pikaCountC == true)//If you win you get to enjoy this little treat :D
		{
			cout << "##################################################" << endl;
			cout << "##################################################" << endl;
			cout << "######################CONGRATULATION##############" << endl;
			cout << "######N###########################################" << endl;
			cout << "#########::#######################################" << endl;
			cout << "#########:::::/#################################//" << endl;
			cout << "##########:::::::##########################/::::::" << endl;
			cout << "###########/::::::::###################/::::::::::" << endl;
			cout << "#############:::::::::::::::::::::::::::::::::::/#" << endl;
			cout << "###############:::::::::::::::::::::::::::::::####" << endl;
			cout << "#################::::::::::::::::::::::::://######" << endl;
			cout << "################::::::::::::::::::::::::::/#######" << endl;
			cout << "###############:::/####::::::::::/####:::::/######" << endl;
			cout << "###############:::/####::::::::::/####::::::######" << endl;
			cout << "##############/::::::::::###/:::::::::::::::/#####" << endl;
			cout << "#################/:::::::::::::::::::/#####::#####" << endl;
			cout << "##################::::::/#####/::::::######::/####" << endl;
			cout << "################/:::::::#######/::::::####/:::####" << endl;
			cout << "##############:::::::::::######::::::::::::::::###" << endl;
			cout << "###############::::::::::::::::::::::::::::::::###" << endl;
			cout << "###############/:::::::::::::::::::::::::::::::/##" << endl;
		}
		else {
			cout << "Final Stack: " << endl;
			dispTop(temp, aStack);//displays top of stack A
			cout << "Suit A: " << temp << endl;
			if (temp == "A 10") { pikaCountA = true; }//used to check for completness
			dispTop(temp, bStack);//displays top of stack B
			cout << "Suit B: " << temp << endl;
			if (temp == "B 10") { pikaCountB = true; }
			dispTop(temp, cStack);//displays top of stack C
			if (temp == "C 10") { pikaCountC = true; }
			cout << "Suit C: " << temp << endl;		
			cout << "Sorting Stack: " << endl;
			dispTop(temp, stack1);//displays top of stack
			cout << "Stack 1: " << temp << endl;
			dispTop(temp, stack2);
			cout << "Stack 2: " << temp << endl;
			dispTop(temp, stack3);
			cout << "Stack 3: " << temp << endl;
			dispTop(temp, stack4);
			cout << "Stack 4: " << temp << endl;
			dispTop(temp, stack5);
			cout << "Stack 5: " << temp << endl;
			cout << "\n\nHand:" << endl;
			printDeck(hand, HandHead, HandTail, HandCounter, HandS);//prints the hand (ignore the function name)
			cout << endl;
		}
		while (!(cin >> answer)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		switch (answer)
		{
		case 1:
			pushFinalStack(hand, HandS, aStack, "A");//pushes all possible A values onto final stack
			pushFinalStack(hand, HandS, bStack, "B");//pushes all possible B values onto final stack
			pushFinalStack(hand, HandS, cStack, "C");//pushes all possible C values onto final stack
			SortToFinal(stack1, aStack, bStack, cStack);//pops/pushes from stack1 to a b or c if possible
			SortToFinal(stack2, aStack, bStack, cStack);//				   stack2
			SortToFinal(stack3, aStack, bStack, cStack);//                 stack3 
			SortToFinal(stack4, aStack, bStack, cStack);//                 stack4
			SortToFinal(stack5, aStack, bStack, cStack);//                 stack5
			pushFinalStack(hand, HandS, aStack, "A");//rechecks hand if there is any values the can go onto final stack
			pushFinalStack(hand, HandS, bStack, "B");//rechecks hand if there is any values the can go onto final stack
			pushFinalStack(hand, HandS, cStack, "C");//rechecks hand if there is any values the can go onto final stack
			pushSortStack(hand, HandS, stack1);//attempts to push all unsorted cards onto stack1
			pushSortStack(hand, HandS, stack2);//attempts to push all unsorted cards onto stack2
			pushSortStack(hand, HandS, stack3);//attempts to push all unsorted cards onto stack3
			pushSortStack(hand, HandS, stack4);//attempts to push all unsorted cards onto stack4
			pushSortStack(hand, HandS, stack5);//attempts to push all unsorted cards onto stack5
			reDraw(card, N, head, tail, counter, hand, HandS, HandHead, HandTail, HandCounter);//puts all current cards back into deck;
			GetHand(card, N, head, tail, counter, hand, HandS, HandHead, HandTail, HandCounter);//draws 5 cards from deck to users hand
			break;
		case 5:
			exit;
			break;
		default:
			break;
		}
	}
}
