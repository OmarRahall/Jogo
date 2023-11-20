#include "Principal.h"
#include "Heroi.h"
#include "Vilao.h"

Principal::Principal() : terminar{ false }, IDjanelaFechada{ gerenciarEventos.adicionarOuvinteOutros([this](const sf::Event& e) {janelaFechada(e); }) } {

	listaAmigos.inserir(new Heroi(vetor2F(0.0f, 0.0f)));
	listaAmigos.inserir(new Vilao(vetor2F(400.0f, 300.0f), vetor2F(10, 0)));
	listaAmigos.inserir(new Vilao(vetor2F(200.0f, 200.0f), vetor2F(0, 5)));
	listaAmigos.inserir(new Vilao(vetor2F(100.0f, 100.0f), vetor2F(0, 10)));
	listaAmigos.inserir(new Vilao(vetor2F(500.0f, 500.0f), vetor2F(0, 0)));

	listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciarEventos);

	gerenciarEventos.setJanela(gerenciadorGrafico.getJanela());
}

Principal::~Principal()
{

	listaAmigos.destruirDesenhaveis();
}

int Principal::executar()
{

	relogio.restart();

	while (!terminar) {

		sf::Time t = relogio.getElapsedTime();
		relogio.restart();

		gerenciarEventos.tratarEventos();

		gerenciadorGrafico.limpar();
		listaAmigos.atualizarDesenhaveis(t.asSeconds());
		listaAmigos.desenharDesenhaveis(gerenciadorGrafico);
		gerenciadorGrafico.mostrar();

		
	}
	return 0;

}

void Principal::janelaFechada(const sf::Event& e) {

	if (e.type == sf::Event::Closed) terminar = true;

}
