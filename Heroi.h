#pragma once

#ifndef _HEROI_H_
#define _HEROI_H_
#include "vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Desenhavel.h"


class Heroi : public Desenhavel
{
private:

	unsigned int ChaveOuvinte;

public:

	Heroi(vetor2F pos);
	~Heroi();
	void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& g);
	void tratarEvento(const sf::Event &e);
};

#endif
