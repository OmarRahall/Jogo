#pragma once
#ifndef _GERENCIADORGRAFICO_H_
#define _GERENCIADORGRADFICO_H
#include <SFML/Graphics.hpp>
#include <map>
#include "vetor2D.h"
#include <string>


class GerenciadorGrafico{

private:

	sf::RenderWindow* janela;
	sf::View camera;
	std::map<const std::string, sf::Texture*> texturas;

public:

	GerenciadorGrafico();
	~GerenciadorGrafico();
	void mostrar() const;
	void limpar(int r = 0, int g = 0, int b = 0);
	void desenhar(const std::string& caminho, const vetor2F posicao);
	bool carregarTexturas(const std::string& caminho);
	void centralizar(const vetor2F centro);
	sf::RenderWindow* getJanela() const;

};

#endif
