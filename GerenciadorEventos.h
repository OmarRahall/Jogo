#pragma once
#ifndef _GERENCIADOREVENTOS_H_
#define _GERENCIADOREVENTOS_H_
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>


class GerenciadorEventos
{
private:

	static unsigned int proximoID;
	sf::RenderWindow* janela;
	std::map<unsigned int, std::function<void(const sf::Event&)>> ouvinteMouse;
	std::map<unsigned int, std::function<void(const sf::Event&)>> ouvinteTeclado;
	std::map<unsigned int, std::function<void(const sf::Event&)>> ouvinteOutros;
	sf::Event evento;

public:
	GerenciadorEventos();
	~GerenciadorEventos();
	void tratarEventos();
	void setJanela(sf::RenderWindow* j);

	unsigned int adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada);
	int removerOuvinteMouse(int id);

	unsigned int adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada);
	int removerOuvinteTeclado(int id);

	unsigned int adicionarOuvinteOutros(std::function<void(const sf::Event&)> chamada);
	int removerOuvinteOutros(int id);
};

#endif
