#include "classNode.h"
template <class Trem>
class Queue
{
public:
    Node<Trem>* Head;
    Node<Trem>* Tail;
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
    Node<Trem>* P = Head;
    while(Head)
    {
        Head = P->next;
        Node<Trem>::desmontaNode(P);
        P = Head;
    }
}
template <class Trem>
bool Queue<Trem>::Push(Trem X)
{
    Node<Trem>* P = Node<Trem>::montaNode(X);
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
        Node<Trem>* P = Head;
        Head = Head->next;
        X = Node<Trem>::desmontaNode(P);
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
    Node<Trem>* P = Head;
    while(Head)
    {
        Head = P->next;
        Node<Trem>::desmontaNode(P);
        P = Head;
    }
    N = 0;
    Tail = 0;
}
