#pragma once
#include "sortingspace.h"
using namespace std;
//sorting stack and final stack funciton
void pushFinalStack(string hand[], int size, Node* &stackptr, string suit)//send in hand, handsize, where its going and the final stack(ex "A")
{
	int nextNum; int preNum;//used to compare these two, top(preNum) and incoming(nextNum)
	string nextSuit = ""; string preSuit;//same things as above just for the suits
	string preNode;//holds top of stack
	for (int i = 0; i < size; i++)
	{
		if (hand[i] == "") {}
		else {
			getInfo(hand[i], nextNum, nextSuit);
			dispTop(preNode, stackptr);//gets top of deck from the list
			getInfo(preNode, preNum, preSuit);//gets the info from the top of the deck
			if (nextSuit == suit && preNum + 1 == nextNum)//checks to see if the number and suit are a match
			{											  //then adds them to the stack
				pushS(hand[i], stackptr);
				i = -1;//resets the loop to check if previous cards can be put on the stack
			}
		}
	}
}
void pushSortStack(string hand[], int size, Node* &stackptr)//pushes from hand to sorting stack
{
	int nextNum; int preNum;
	string preNode=""; 
	for (int i = 0; i < size; i++)
	{
		if (hand[i] == "") {}
		else {
			getNum(hand[i], nextNum);//gets the number from hand
			dispTop(preNode, stackptr);//checks top of stack
			getNum(preNode, preNum);//gets number of the stack
			if (preNode == "x 0")//checks to see if null then pushes onto the the stack
			{
				pushS(hand[i], stackptr);//pushes hand to sorting stack
				i = -1;//resets hand
			}
			else if(preNum - 1 == nextNum)//checks to see if next number is one less then top of stack
			{
				pushS(hand[i], stackptr);//same thing as above
				i = -1;//resets hand
			}
		}
	}
}
void SortToFinal(Node* &sort, Node* &A, Node* &B, Node* &C)//sorts from sorting stack to final stack
{
	string finalNode=""; string sortNode="";//sets all variables to empty or 0
	string sortSuit=""; string finalSuit="";//
	int sortNum=0; int finalNum=0;//resets numbers
	for (int i=0; i<10;i++) {
			dispTop(sortNode, sort);//this gets the currents node top	
			dispTop(finalNode, A);//this gets the currents node top
			if (sortNode != ""&&finalNode != "") 
			{
				getInfo(finalNode, finalNum, finalSuit);//gets number and suit, from top of final
				dispTop(finalNode, A);//sets final node to top of stack A
				getInfo(sortNode, sortNum, sortSuit);//gets info for top of sort node
				if (sortNum - 1 == finalNum && sortSuit == "A")//pushes if suit is A and number is top of final+1
				{
					popST(sortNode, sort);
					pushS(sortNode, A);
				}
				sortNum = 0; finalNum = 0;//resets numbers
				dispTop(sortNode, sort);//this gets the currents node top	
				dispTop(finalNode, B);//this gets the currents node top
				getInfo(finalNode, finalNum, finalSuit);
				getInfo(sortNode, sortNum, sortSuit);
				if (sortNum - 1 == finalNum && sortSuit == "B")//pushes if suit is B and number is top of final+1
				{
					popST(sortNode, sort);
					pushS(sortNode, B);
				}	
				sortNum = 0; finalNum = 0;
				dispTop(sortNode, sort);//this gets the currents node top(sorting)	
				dispTop(finalNode, C);//this gets the currents node top(final stack)
				getInfo(finalNode, finalNum, finalSuit);//gets info of top of final stack
				getInfo(sortNode, sortNum, sortSuit);//gets info of top of sorting stack
				if (sortNum - 1 == finalNum && sortSuit == "C")//pushes if suit is C and number is top of final+1
				{
					popST(sortNode, sort);
					pushS(sortNode, C);
				}
				sortNum = 0; finalNum = 0;//resets numbers
		}
	}
}
