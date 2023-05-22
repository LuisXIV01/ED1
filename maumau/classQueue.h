template <class Trem>
class nodeQueue
{
public:
    Trem D;
    nodeQueue <Trem>* next;
public:
	static nodeQueue<Trem>* montaNode(Trem dat);
	static Trem desmontaNode(nodeQueue<Trem>* P);
};

template <class Trem>
nodeQueue<Trem>* nodeQueue<Trem>::montaNode(Trem dat)
{
	nodeQueue<Trem>* P = new nodeQueue<Trem>;
	if(P)
	{
		P->D = dat;
		P->next = 0;
	}
	return P;
}
template <class Trem>
Trem nodeQueue<Trem>::desmontaNode(nodeQueue<Trem>* P)
{
	Trem X;
	if(P)
	{
		X = P->D;
		delete P;
	}
	return X;
}

template <class Trem>
class Queue
{
public:
    nodeQueue<Trem>* Head;
    nodeQueue<Trem>* Tail;
    int N;

public:
    Queue();
    ~Queue();
    bool Push(Trem X);
    Trem Front();
    Trem Pop();
    int Size();
    bool Empty();
    void Clear();
};

template <class Trem>
Queue<Trem>::Queue()
    
{
    Head =0;
    Tail =0;
    N =0;
}
template <class Trem>
Queue<Trem>::~Queue()
{
    nodeQueue<Trem>* P = Head;
    while(Head)
    {
        Head = P->next;
        nodeQueue<Trem>::desmontaNode(P);
        P = Head;
    }
}
template <class Trem>
bool Queue<Trem>::Push(Trem X)
{
    nodeQueue<Trem>* P = nodeQueue<Trem>::montaNode(X);
    if(!P)
        return false;
    if(Head)
        Tail->next = P;
    else
        Head = P;
    Tail = P;
    Tail->next = 0;
    N++;
    return true;
}
template <class Trem>
Trem Queue<Trem>::Front()
{
    Trem X;
    if(Head)
        X = Head->D;
    return X;
}
template <class Trem>
Trem Queue<Trem>::Pop()
{
    Trem X;
    if(Head)
    {
        nodeQueue<Trem>* P = Head;
        Head = Head->next;
        X = nodeQueue<Trem>::desmontaNode(P);
        if(!Head)
            Tail = 0;
        N--;
    }
    return X;
}
template <class Trem>
int Queue<Trem>::Size()
{
    return N;
}
template <class Trem>
bool Queue<Trem>::Empty()
{
    return !Head;
}
template <class Trem>
void Queue<Trem>::Clear()
{
    nodeQueue<Trem>* P = Head;
    while(Head)
    {
        Head = P->next;
        nodeQueue<Trem>::desmontaNode(P);
        P = Head;
    }
    N = 0;
    Tail = 0;
}
