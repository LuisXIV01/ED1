template<class trem> 
class dNode{
public:
	trem D;
	dNode<trem>* next;
	dNode<trem>* prev;
	static dNode* montaNode(trem dat);
	static trem desmontaNode(dNode* P);
};

template<class trem>
dNode<trem>* dNode<trem>::montaNode(trem dat){
	dNode<trem>* P=new dNode;
	if(P){
		P->D=dat;
		P->next=0;
		P->prev=0;
	}
	return P;
}

template<class trem>
trem dNode<trem>::desmontaNode(dNode<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}

template<class trem>
class cListDE
{
public:
	dNode<trem>* Head;
	dNode<trem>* It;
	int N;
	
	cListDE();
	~cListDE();
	bool insert(trem X);
	trem erase();
	void ItMM();
	void ITmm();
	void Itbegin();
	trem RtIt();
	bool empty();
	int size();
	void clear();
};

template<class trem>
cListDE<trem>::cListDE(){
	Head = It =0;
	N =0;
}

template<class trem>
cListDE<trem>::~cListDE(){
	dNode<trem>* P = Head;
	while(N > 0)
	{
		Head = Head->next;
		dNode<trem>::desmontaNode(P);
		P = Head;
		N--;
	}
}
template<class trem>
bool cListDE<trem>::insert(trem X){
	dNode<trem>* P= dNode<trem>::montaNode(X);
	if(!P)
		return false;
	if(!Head)
	{
		Head = It = P->next = P->prev = P;
	}
	else{
		P->prev = It;
		P->next = It->next;
		It->next = P;
		It = P;
		Head->prev = P;
	}
	N++;
	return true;
}
template<class trem>
trem cListDE<trem>::erase(){
	trem X;
	if(!Head)
		return X;
	dNode<trem>* Aux = It;
	if(It->next != It){
		(It->next)->prev = It->prev;
		(It->prev)->next = It->next;
	}
	else
	{
		Head = 0;
	}
	if(Head == It){
		Head = It = It->next;
	}
	else{
		It = It->next;
	}
	N--;
	X = dNode<trem>::desmontaNode(Aux);
	return X;
}
template<class trem>
void cListDE<trem>::clear(){
	dNode<trem>* P = Head;
	while(N > 0)
	{
		Head = Head->next;
		dNode<trem>::desmontaNode(P);
		P = Head;
		N--;
	}
	Head = 0;
	It = 0;
}
template<class trem>
void cListDE<trem>::ItMM(){
	if(It)
		It = It->next;
}
template<class trem>
void cListDE<trem>::ITmm(){
	if(It)
		It = It->prev;
}
template<class trem>
void cListDE<trem>::Itbegin(){
	It = Head;
}
template<class trem>
trem cListDE<trem>::RtIt(){
	trem X;
	if(!It){
		return X;
	}
	X = It->D;
	return X;
}
template<class trem>
bool cListDE<trem>::empty(){
	return !Head;
}
template<class trem>
int cListDE<trem>::size(){
	return N;
}