#include "classCarta.h"
class Node
{
public:
    Carta D;
    Node* next;
public:
	static Node* montaNode(Carta dat);
	static Carta desmontaNode(Node* P);
};

Node* Node::montaNode(Carta dat)
{
	Node* P = new Node;
	if(P)
	{
		P->D = dat;
		P->next = 0;
	}
	return P;
}
Carta Node::desmontaNode(Node* P)
{
	Carta X;
	if(P)
	{
		X = P->D;
		delete P;
	}
	return X;
}
class List
{
public:
	Node* Head;
	int N;
public:
	List();
	~List();
	bool Insert(Carta X);
	bool Search(Carta X, Carta* pX);
	Carta Erase(Carta X);
	Carta pop();
	Carta retorna();
	int Size();
	void Clear();
	bool Empty();
};
List::List()
{
	Head = 0;
	N = 0;
}
List::~List()
{
	Node* P = Head;
	while(Head)
	{
		Head = Head->next;
		Node::desmontaNode(P);
		P = Head;
	}
}
bool List::Search(Carta X, Carta* pX)
{
	Node* Pvalor = Head;
	Node* Pnaipe = Head;
	while(Pnaipe && Pnaipe->D.naipe != X.naipe)
	{
		Pnaipe = Pnaipe->next;
	}
	while(Pvalor && Pvalor->D.valor!= X.valor)
		{
			Pvalor = Pvalor->next;
		}
	if(Pvalor && !Pnaipe){
		*pX = Pvalor->D;
		return true;
	}
	if(!Pvalor && Pnaipe){
		*pX = Pnaipe->D;
		return true;
	}
	if(!Pvalor && !Pnaipe){
		return false;
	}
	if((Pvalor->D).valor > (Pnaipe->D).valor){
		*pX = Pvalor->D;
		return true;
	}
	*pX = Pnaipe->D;
	return true;
}
bool List::Insert(Carta X)
{
	Node* P = Node::montaNode(X);
	if(!P)
		return false;

	Node** aux = &Head;
	while((*aux) && ((((*aux)->D).valor > X.valor) || (((*aux)->D).valor == X.valor) && (((*aux)->D).naipe < X.naipe))){
		aux = &((*aux)->next);
	}
	P->next = (*aux);
	(*aux)= P;
	N++;
	return true;
}
Carta List::Erase(Carta X)
{
	Carta R;
	Node* Aux;
	Node** P = &Head;
	while((*P) && (((*P)->D).valor != X.valor || ((*P)->D).naipe != X.naipe))
	{
		P = &((*P)->next);
	}
	if(*P)
	{
		Aux = *P;
		*P = (Aux->next);
		R = Node::desmontaNode(Aux);
		N--;
	}
	return R;
}
Carta List::pop()
{
	Carta aux;
	if(!Head)
		return aux;
	Node* P = Head;
	Head = Head->next;
	N--;
	return Node::desmontaNode(P);
}
int List::Size()
{
	return N;
}
void List::Clear()
{
	Node* P = Head;
	while(Head)
	{
		Head = Head->next;
		Node::desmontaNode(P);
		P = Head;
	}
	N = 0;
}
bool List::Empty()
{
	return !Head;
}
Carta List::retorna(){
	return Head->D;
}