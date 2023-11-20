#include "GerenciadorEventos.h"


unsigned int GerenciadorEventos::proximoID{ 0 };

GerenciadorEventos::GerenciadorEventos() {

	}

GerenciadorEventos::~GerenciadorEventos() {

	}

void GerenciadorEventos::tratarEventos() {

	while (janela->pollEvent(evento))
		if (evento.type == sf::Event::MouseWheelScrolled || evento.type == sf::Event::MouseButtonPressed || evento.type == sf::Event::MouseButtonReleased
			|| evento.type == sf::Event::MouseMoved) {

			for (auto it : ouvinteMouse) {
				it.second(evento);
			}
	}
		else {
			 if (evento.type == sf::Event::KeyPressed || evento.type == sf::Event::KeyReleased) {

			for (auto it : ouvinteTeclado) {
				it.second(evento);
			}

		}
			else {

				for (auto it : ouvinteOutros) {
					it.second(evento);
				}

			}

		}

	}

void GerenciadorEventos::setJanela(sf::RenderWindow* j) {

	janela = j;

	janela->setKeyRepeatEnabled(false);
	}

unsigned int GerenciadorEventos::adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada) {

	ouvinteMouse.emplace(proximoID, chamada);

	return proximoID++;

	}

int GerenciadorEventos::removerOuvinteMouse(int id) {

	ouvinteMouse.erase(id);

	}

unsigned int GerenciadorEventos::adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada) {

	ouvinteTeclado.emplace(proximoID, chamada);

	return proximoID++;

	}

int GerenciadorEventos::removerOuvinteTeclado(int id) {

	ouvinteTeclado.erase(id);

	}

unsigned int GerenciadorEventos::adicionarOuvinteOutros(std::function<void(const sf::Event&)> chamada) {

	ouvinteOutros.emplace(proximoID, chamada);

	return proximoID++;

	}

int GerenciadorEventos::removerOuvinteOutros(int id) {

	ouvinteOutros.erase(id);

	}
