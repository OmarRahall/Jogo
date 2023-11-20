#include "Desenhavel.h"

Desenhavel::Desenhavel(vetor2F pos, vetor2F vel, const char* caminhoTextura) : posicao{ pos }, v{ vel }, caminho{ caminhoTextura } {


}

Desenhavel::~Desenhavel(){
	

}

void Desenhavel::inicializar(GerenciadorGrafico &gf, GerenciadorEventos &ge) {

	gf.carregarTexturas(caminho);
}

void Desenhavel::atualizar(float t){


	posicao += v*t;


	//corpo.move(v * t);
}

void Desenhavel::desenhar(GerenciadorGrafico &gf){


	gf.desenhar(caminho, posicao);
}
