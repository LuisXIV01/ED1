#include <iostream>
#include "classQueue.h"
#include "cListDE.h"
#include "classJogador.h" // Class Jogador. Representa cada jogador - É formado por numero do jogador e sua mão de carta
using namespace std;
int main(){
    //freopen("imput.txt","r",stdin);
    cListDE <Jogador*> Jogo; // Ordem do jogo (pode mudar conforme o andamento das rodadas)
    Carta cartAux; // Carta auxiliar para facilitar
    Queue <Carta> monte;
    Carta Lixo;
    Carta aux;
    Jogador jogQueSai;
    Jogador Vencedor;
    int N, i, nJ, nCartas, nJogadas;
    bool ok, Invert;
    
    cin >> N;
    for(int v=0; v < N; v++){
		Jogo.clear();
		cin >> nJ;
		nJogadas = nJ -1;
		Jogador jog[nJ];
		for(int j=0; j<nJ; j++){
			jog[j].NumJog = j+1;
			Jogo.insert(&(jog[j]));
		}
		
		for(i=0; i<nJogadas; i++){
			Jogo.Itbegin();
			for(int j=0; j<nJ; j++){
				for(int k=0; k<5; k++){
					cin >> cartAux.valor >> cartAux.naipe;
					(*Jogo.RtIt()).mao.Insert(cartAux);
				}
				Jogo.ItMM();
			}
			
			nCartas =  104 - (nJ*5);
			for(int j=0; j < nCartas; j++){
				cin >> cartAux.valor >> cartAux.naipe;
				monte.Push(cartAux); // Montando o monte com as cartas que sobraram
			}
			Lixo.valor = Lixo.naipe = 'Z'; 
			Jogo.Itbegin();
			ok = true;
			Invert = false;
			for(int j =0;ok; j++){
				if(Lixo.valor == 'Z'){ // A primeira jogada, Sem nenhuma carta, jogador joga a de maior valor
					Lixo = (*Jogo.RtIt()).mao.retorna(); // Carta descartada vai para o topo do lixo
					(*Jogo.RtIt()).mao.Erase(Lixo); // Descarta a carta da mão do jogador
					if(Lixo.valor == 'K'){ // Verifica se a carta descartada é a carta de Rotação (K)
						Invert = true; // inverte a rotação do jogo
					}
					else{
						if(Lixo.valor == 'A'){ // Verifica se a carta descartada é a carta de pular o jogador (A)
							Jogo.ItMM();
						}
						else{
							if(Lixo.valor == 'G'){ // Verifica se a carta descartada é a carta de o próximo jogador compra 2 (G)
								Jogo.ItMM();
								cartAux = monte.Pop();
								(*Jogo.RtIt()).mao.Insert(cartAux);

								cartAux = monte.Pop();
								(*Jogo.RtIt()).mao.Insert(cartAux);
								Jogo.ITmm();
							}
							else{
								if(Lixo.valor == 'I'){ // Verifica se a carta descartada é a carta de o jogador anterior comprar 3 (I)
									Jogo.ITmm();
									cartAux = monte.Pop();
									(*Jogo.RtIt()).mao.Insert(cartAux);

									cartAux = monte.Pop();
									(*Jogo.RtIt()).mao.Insert(cartAux);

									cartAux = monte.Pop();
									(*Jogo.RtIt()).mao.Insert(cartAux);
									Jogo.ItMM();
								}
							}
						}
					}
				}
				else{
					if(!Invert){ // caso a rotação do jogo esteja em sentido horário
						//cout << monte.Front().valor << monte.Front().naipe << " carta do fronte do monte\n";
						if(!((*Jogo.RtIt()).mao.Search(Lixo, &aux))){ // Verifica se o jogador não tem nenhuma carta possível pra descartar
							//cout << "Nao tem carta\n";
							cartAux = monte.Pop(); // O jogador compra uma do monte
							(*Jogo.RtIt()).mao.Insert(cartAux);
						}
						if((*Jogo.RtIt()).mao.Search(Lixo, &aux)){ // Verifica se o jogador tem carta possível pra desartar
							monte.Push(Lixo);
							//cout << aux.valor << aux.naipe << " carta aux jogada pelo jogador" << (*Jogo.RtIt()).NumJog << endl;
							Lixo = (*Jogo.RtIt()).mao.Erase(aux);
							if((*Jogo.RtIt()).mao.Size() == 0){
								ok = false;
							}
							if(Lixo.valor == 'K'){
								Invert = true; // inverte a rotação do jogo
							}
							else{
								if(Lixo.valor == 'A'){
									Jogo.ItMM();
								}
								else{
									if(Lixo.valor == 'G'){
										Jogo.ItMM();
										cartAux = monte.Pop();
										(*Jogo.RtIt()).mao.Insert(cartAux);
										
										cartAux = monte.Pop();
										(*Jogo.RtIt()).mao.Insert(cartAux);
										Jogo.ITmm();
									}
									else{
										if(Lixo.valor == 'I'){
											Jogo.ITmm();
											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);

											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);

											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);
											Jogo.ItMM();
										}
									}
								}
							}
						}
					}
					else{
						if(!((*Jogo.RtIt()).mao.Search(Lixo, &aux))){
							cartAux = monte.Pop(); // O jogador compra uma do monte
							(*Jogo.RtIt()).mao.Insert(cartAux);
						}
						if((*Jogo.RtIt()).mao.Search(Lixo, &aux)){
							monte.Push(Lixo);
							Lixo = (*Jogo.RtIt()).mao.Erase(aux);
							if((*Jogo.RtIt()).mao.Size() == 0){
								ok = false;
							}
							if(Lixo.valor == 'K'){
								Invert = false; // inverte a rotação do jogo
								
							}
							else{
								if(Lixo.valor == 'A'){
									Jogo.ITmm();
								}
								else{
									if(Lixo.valor == 'G'){
										Jogo.ITmm();
										cartAux = monte.Pop();
										(*Jogo.RtIt()).mao.Insert(cartAux);
										
										cartAux = monte.Pop();
										(*Jogo.RtIt()).mao.Insert(cartAux);
										Jogo.ItMM();
									}
									else{
										if(Lixo.valor == 'I'){
											Jogo.ItMM();
											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);

											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);

											cartAux = monte.Pop();
											(*Jogo.RtIt()).mao.Insert(cartAux);
											Jogo.ITmm();
											
										}
									}
									
								}
								
							}
						}
						//cout << "segunda rodada\n";
					}
				}
				if(Invert){
					Jogo.ITmm();
				}
				else{
					Jogo.ItMM();
				}
			}
			
			for(int j=0; j<nJ; j++){
				(*Jogo.RtIt()).somarPontos();
				Jogo.ItMM();
			}
			jogQueSai = *Jogo.RtIt();
			Jogo.ItMM();
			for(int j=1; j<nJ; j++){
				if(jogQueSai.pont < (*Jogo.RtIt()).pont){
					jogQueSai = *Jogo.RtIt();
				}
				Jogo.ItMM();
			}
			for(int j=0; j<nJ && jogQueSai.pont != (*Jogo.RtIt()).pont; j++){
				Jogo.ItMM();
			}
			Jogo.erase();
			nJ--;
			Vencedor = (*Jogo.RtIt());
			Jogo.ItMM();
			for(int j=1; j<nJ; j++){
				if((*Jogo.RtIt()).pont < Vencedor.pont){
					Vencedor = (*Jogo.RtIt());
				}
				Jogo.ItMM();
			}
			cout << "\nVencedor da partida " << i+1 << " Jogador " << Vencedor.NumJog << endl;
			for(int j=0; j<nJ; j++){
				(*Jogo.RtIt()).clearPontos();
				Jogo.ItMM();
			}
			monte.Clear();
		}
	}
}
