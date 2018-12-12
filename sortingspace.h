using namespace std;
//this file holds all functions used by the stacks in the final and sorting stack
struct Node
{
	string data;
	Node* next;
};
void pushS(string &input, Node* &top)//push function pushes input[i] onto top of stack
{
	Node *ptr = new Node();
	ptr->data = input;
	ptr->next = top;
	top = ptr;
	input = "";
}
void dispTop(string &y, Node* &top)//gets top of stack
{
	if (top == NULL)
	{
		y = "x 0";//if empty gives this string
	}
	else
	{
		y = top->data;//if not empty gives top of data
	}
}
void popST(string &x, Node* &top)//pops top of deck and stores string into variable being passed in(this is the top)
{
	x = top->data;
	Node *ptr = top;
	top = top->next;
	delete(ptr);
}
