#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;//functions in this file are used to manage the ring queue arrays.
void push(string a[], int size, int head, int &tail, string &input, int &counter)//pushes input into the ring array
{
	if (counter == (size))
	{
		cout << "Deck is Full " << size << " " << head << " " << tail << endl;
		return;
	}
	else if (tail == size && head >= 0)
	{
		tail = 0;
		a[tail] = input;
		tail++;
		counter++;
		return;
	}
	a[tail] = input;
	tail++;
	counter++;
}


void pop(string a[], int &head, int &tail, int size, int &counter, string &topOfDeck)//pops the top card of the deck, when counter is 0, resets tail and head to 0
{
	if (counter == 0)
	{
		//cout << "the Deck is empty" << endl;
		return;
	}
	else if (head == size)
	{
		head = 0;
	}
	topOfDeck = a[head];
	a[head] = "";
	head++;
	counter--;
	if (counter == 0)
	{
		head = 0;
		tail = 0;
	}
}
void printDeck(string a[], int head, int tail, int counter, int size)//this is used to print the array in order.
{
	int deckCount;
	deckCount = 0;
	if (head == tail) {
	}
	else
		int i;
	if (head <= tail)
	{
		for (int i = head; i < tail; i++)
		{
			if (a[i] == "") {}
			else { cout << " [" << a[i] << "] ";
			deckCount++;
			}
		}
	}
	else
	{
		int i = head;
		while (i < size)
		{
			if (a[i] == "") {}
			else { cout << " [" << a[i] << "] ";
			deckCount++;
			}
			i++;
		}
		i = 0;
		while (i <= tail - 1)
		{
			if (a[i] == "") {}
			else { cout << " [" << a[i] << "] "; 
			deckCount++;
			}
			i++;
			
		}
	}
	cout << "\nNumber of cards left:";
}
