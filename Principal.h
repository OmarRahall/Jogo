#pragma once

#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include "GerenciadorGrafico.h"
#include "Desenhavel.h"
#include "ListaDesenhaveis.h"


class Principal
{
private:

	bool terminar;
	GerenciadorGrafico gerenciadorGrafico;
	GerenciadorEventos gerenciarEventos;
	sf::Clock relogio;
	ListaDesenhaveis listaAmigos;
	unsigned int IDjanelaFechada;

public: 
	Principal();
	~Principal();
	int executar();
	void janelaFechada(const sf::Event& e);
};

#endif
