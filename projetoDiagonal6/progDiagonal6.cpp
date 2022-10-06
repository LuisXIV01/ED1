#include <iostream>
#include "classStack.h"
#include "classFicha.h"
using namespace std;
int main(){
    freopen("imput.txt","r",stdin);

    ficha entrada[4][13];
    ficha mapaDoJogo[6][6];
    Stack <ficha> torre[6];
    Queue <ficha> mao[4];
    ficha fichaEntrada;
    int posFicha[4] = {0, 0, 0, 0}, i, j, k, pos, pontJogadores[4] = {0, 0, 0, 0}, vencedores[3] = {0, 0, 0};
    int *venc1, *venc2, *venc3;
    bool torresNaoCheias = true;

    for(i=0; i < 52; i++){
        cin >> fichaEntrada.jogador >> fichaEntrada.cor >> fichaEntrada.numTorre;
        entrada[fichaEntrada.jogador - 49][posFicha[fichaEntrada.jogador - 49]] = fichaEntrada;
        posFicha[fichaEntrada.jogador - 49]++;
    }
    for(i=0; i < 4; i++){
        for(j=0; entrada[i][j].cor == 'P'; j++);
        if(entrada[i][j].cor == 'A'){
            for(k=0; k < 13; k++){
                mao[0].Push(entrada[i][k]);
            }
        }
        else{
            if(entrada[i][j].cor == 'V'){
                for(k=0; k < 13; k++){
                    mao[1].Push(entrada[i][k]);
                }
            }
            else{
                if(entrada[i][j].cor == 'R'){
                    for(k=0; k < 13; k++){
                        mao[2].Push(entrada[i][k]);
                    }
                }
                else{
                    for(k=0; k < 13; k++){
                        mao[3].Push(entrada[i][k]);
                    }
                }
            }
        }
    }
    for(i=0; torresNaoCheias; i=(i+1)%4){
        if(!mao[i].Empty()){
            if(!mao[i].Empty() && mao[i].Front().cor == 'P'){
                if(!torre[mao[i].Front().numTorre -49].Empty()){
                    torre[mao[i].Front().numTorre -49].Pop();
                }
                mao[i].Pop();
            }
            else{
                pos = mao[i].Front().numTorre -49;
                for(k=0 ;k < 6 && torre[pos].Size() == 6; k++){
                    pos = (pos+1)%6;
                }
                if(k < 6){
                    torre[pos].Push(mao[i].Front());
                    mao[i].Pop();
                }
            }
        }
        if(torre[0].Size() == 6 && torre[1].Size() == 6 && torre[2].Size() == 6 && torre[3].Size() == 6 && torre[4].Size() == 6 && torre[5].Size() == 6){
            torresNaoCheias = false;
        }
    }
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            mapaDoJogo[i][j] = torre[j].Pop();
        }
    }

    for(i=0; i<6; i++){
        pontJogadores[mapaDoJogo[i][i].jogador-49]++;
    }
    venc1 = &pontJogadores[0];
    for(i=1; i<4; i++){
        if(pontJogadores[i] > *venc1){
            venc1 = &pontJogadores[i];
            venc2 = venc3 = 0;
            vencedores[0] = i;
            vencedores[1] = vencedores[2] = 0;
        }
        else{
            if(venc2!= 0 && pontJogadores[i] == *venc2){
                venc3 = &pontJogadores[i];
                vencedores[2] = i;
            }
            else{
                if(pontJogadores[i] == *venc1){
                    venc2 = &pontJogadores[i];
                    vencedores[1] = i;
                }
            }
        }
    }
    if(venc2 == 0){
        cout << " Vencedor: Jogador " << vencedores[0] +1 << endl;
    }
    else{
        if(venc3 != 0){
            cout << " Vencedores:";
        for(i=0;i<2;i++){
            cout << " Jogador " << vencedores[i]+1 << ',';
        }
        cout << " e Jogador " << vencedores[i] +1 << endl;
        }
        else{
            cout << " Vencedores: Jogador " << vencedores[0]+1 << " e Jogador " << vencedores[1]+1 << endl;
        }
    }
    cout << endl;
    for(i=0; i<4; i++){
        if(!mao[i].Empty()){
            cout << " Fichas que sobraram na mao do jogador" << mao[i].Front().jogador << " : ";
            while(!mao[i].Empty()){
                cout << mao[i].Front().jogador << mao[i].Front().cor << mao[i].Front().numTorre << ' ';
                mao[i].Pop();
            }
        cout << endl;
        }
    }
    cout << "\n Mapa do jogo\n";
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            cout << ' ' << mapaDoJogo[i][j].jogador << mapaDoJogo[i][j].cor << mapaDoJogo[i][j].numTorre;
        }
        cout << endl;
    }
}
