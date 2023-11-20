#include "GerenciadorGrafico.h"
#include <iostream>

GerenciadorGrafico::GerenciadorGrafico() : 

	janela { new sf::RenderWindow(sf::VideoMode(800, 800), "trabalho") },
	camera{sf::Vector2f(400, 400), sf::Vector2f(800, 800)}
{

	janela->setView(camera);
}

GerenciadorGrafico::~GerenciadorGrafico() {

	delete janela;

	/*for (auto i = texturas.begin(); i != texturas.end(); ++i) {
		delete i->second;
	}
	*/
	for (auto i : texturas) {
		delete i.second;
	}
}

void GerenciadorGrafico::mostrar() const{

	janela->display();
}

void GerenciadorGrafico::limpar(int r, int g, int b) {
	
	janela->clear(sf::Color(r, g, b));
}

void GerenciadorGrafico::desenhar(const std::string& caminho, const vetor2F posicao) {

	if (texturas.count(caminho) == 0) {

		std::cout << "atencao! imagem em " << caminho << "nao carregada!" << std::endl;
		exit(119);
	}

	sf::Texture* text = texturas[caminho];

	sf::Sprite sprite;

	sprite.setTexture(*text);

	sprite.setPosition(posicao.x, posicao.y);

	janela->draw(sprite);

}

bool GerenciadorGrafico::carregarTexturas(const std::string& caminho) {

	if (texturas.count(caminho) == 1) return true;
	else {
		sf::Texture* text = new sf::Texture();
		if (text->loadFromFile(caminho)) {
			std::cout << "Atenção! imagem em " << caminho << "nao encontrada!" << std::endl;
				exit(120);
 		}

		//texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
		texturas.emplace(caminho, text);

		return true;
	}
}

void GerenciadorGrafico::centralizar(const vetor2F centro) {

	camera.setCenter(sf::Vector2f(centro.x, centro.y));
}

sf::RenderWindow* GerenciadorGrafico::getJanela() const {
	return janela;
}
