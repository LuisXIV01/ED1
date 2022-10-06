template <class Trem>
class Node
{
public:
    Trem D;
    Node <Trem>* next;
public:
	static Node<Trem>* montaNode(Trem dat);
	static Trem desmontaNode(Node<Trem>* P);
};

template <class Trem>
Node<Trem>* Node<Trem>::montaNode(Trem dat)
{
	Node<Trem>* P = new Node<Trem>;
	if(P)
	{
		P->D = dat;
		P->next = 0;
	}
	return P;
}
template <class Trem>
Trem Node<Trem>::desmontaNode(Node<Trem>* P)
{
	Trem X;
	if(P)
	{
		X = P->D;
		delete P;
	}
	return X;
}
