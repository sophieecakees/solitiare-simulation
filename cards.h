#include "deckManger.h"
//Redraw and getHand are used for drawing cards from the deck and puting them back into the deck
void getInfo(string card, int &number, string &suit)//send card[location], number variable and suit variable.This seperates them so you can use either independitly
{
		if (card == "") {}//this makes sure getInfo is not getting an empty string so stoi will not crash
		else {
			suit = card[0];
			card.erase(0, 2);
			number = stoi(card);
	}
}void getNum(string card, int &number)//send card[location], number variable and suit variable.This seperates them so you can use either independitly
{
		card.erase(0, 2);
		number = stoi(card);
}
void GetHand(string card[], int size, int &head, int &tail, int &counter, string hand[], int handSize, int &HandHead, int &HandTail, int &HandCounter)//this 
{
	string topCard="";
	for (int i = HandHead; i < handSize; i++)//loop 5 times to give the player his/her hand.
	{
		topCard = "";
		if (hand[i] != "")
		{
			push(card, size, head, tail, hand[i], counter);
			hand[i] = "";
		}
		pop(hand, HandHead, HandTail, handSize, HandCounter, topCard);
	}
	for (int i = 0; i < handSize; i++)//loop 5 times to give the player his hand.
	{
		topCard = "";
		pop(card, head, tail, size, counter, topCard);
		push(hand, handSize, HandHead, HandTail, topCard, HandCounter);
	}
}
void reDraw(string card[], int size, int &head, int &tail, int &counter, string hand[], int handSize, int &HandHead, int &HandTail, int &HandCounter)//this 
{
	string topCard;
	for (int i = HandHead; i < handSize; i++)//starts from index head to end
	{
		topCard = "";
		if (hand[i] != "")//if not empty pops from the hand then enters it into the deck
		{
			pop(hand, HandHead, HandTail, handSize, HandCounter, topCard);
			push(card, size, head, tail, topCard, counter);
		}
		else {
			pop(hand, HandHead, HandTail, handSize, HandCounter, topCard);//if is empty justs pops from hand

		}
	}
	for (int i = 0; i <= HandTail; i++)//does same thing as above but just from index 0 to tail
	{
		topCard = "";//resets topcard so we dont get duplicates entered into the deck
		if (hand[i] != "")
		{
			pop(hand, HandHead, HandTail, handSize, HandCounter, topCard);
			push(card, size, head, tail, topCard, counter);
		}
		else {
			pop(hand, HandHead, HandTail, handSize, HandCounter, topCard);
		}
	}

}
