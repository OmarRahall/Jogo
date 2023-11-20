#include "Heroi.h"


Heroi::Heroi(vetor2F pos) : Desenhavel(pos, vetor2F()){

}

Heroi::~Heroi() {

}

void Heroi::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge) {
	gf.carregarTexturas(caminho);

	ChaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });
}

void Heroi::atualizar(float t) {

	posicao += v * t;
}

void Heroi::desenhar(GerenciadorGrafico &g) {

	g.centralizar(posicao);
	g.desenhar(caminho, posicao);
}

void Heroi::tratarEvento(const sf::Event& e){

	if (e.type == sf::Event::KeyPressed) {

		switch (e.key.code) {

		case sf::Keyboard::Key::Right:
			v.x += 10;
				break;
		case sf::Keyboard::Key::Left:
			v.x -= 10;
			break;
		case sf::Keyboard::Key::Up:
			v.y -= 10;
			break;
		case sf::Keyboard::Key::Down:
			v.y += 10;
			break;
		default:
			break;
		}
	}
	else if (e.type == sf::Event::KeyReleased) {

		switch (e.key.code) {

		case sf::Keyboard::Key::Right:
			v.x -= 10;
			break;
		case sf::Keyboard::Key::Left:
			v.x += 10;
			break;
		case sf::Keyboard::Key::Up:
			v.y += 10;
			break;
		case sf::Keyboard::Key::Down:
			v.y -= 10;
			break;
		default:
			break;
		}

	}
}
