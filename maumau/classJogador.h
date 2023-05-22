#include "classList.h"
class Jogador
{
public:
    int NumJog;
    List mao;
    int pont;
public:
    Jogador();
    void somarPontos();
    void clearPontos();
};
Jogador::Jogador(){
    NumJog = 0;
    pont = 0;
}
void Jogador::somarPontos(){
    while(mao.Size() != 0){
        pont = pont + (mao.pop()).valor -64;
    }
}
void Jogador::clearPontos(){
    pont = 0;
}