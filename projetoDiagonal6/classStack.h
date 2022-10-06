#include "classQueue.h"
template <class Trem>
class Stack
{
public:
	Node<Trem>* top;
	int N;
public:
	Stack();
	~Stack();
	bool Push(Trem dat);
	Trem Pop();
	Trem Top();
	bool Empty();
	int Size();
};
template <class Trem>
Stack<Trem>::Stack(){
	top = 0;
	N = 0;
}
template <class Trem>
bool Stack<Trem>::Push(Trem x){
	Node<Trem>* P = Node<Trem>::montaNode(x);
	if(!P)
		return false;
	P->next = top;
	top = P;
	N++;
	return true;
}
template <class Trem>
Trem Stack<Trem>::Top(){
	Trem X;
	if(top)
		X = top->D;
	return X;
}
template <class Trem>
int Stack<Trem>::Size(){
	return N;
}
template <class Trem>
bool Stack<Trem>::Empty(){
	return !top;
}
template <class Trem>
Trem Stack<Trem>::Pop(){
	Trem X;
	if(top){
		Node<Trem>* P = top;
		top = top->next;
		X= Node<Trem>::desmontaNode(P);
		N--;
	}
	return X;
}
template <class Trem>
Stack<Trem>::~Stack(){
	Node<Trem>* P;
	while(top){
		P = top;
		top = top->next;
		Node<Trem>::desmontaNode(P);
	}
}
