#pragma once
#ifndef _LISTADESENHAVEIS_H_
#define _LISTADESENHAVEIS_H_
#include "Desenhavel.h"
#include "Lista.h"

class GerenciadorGrafico;
class GerenciadorEventos;
class ListaDesenhaveis{

private:

	Lista<Desenhavel*> lista;

public:
	ListaDesenhaveis();
	~ListaDesenhaveis();
	void inserir(Desenhavel* info);

	Desenhavel* voltarInicio();
	Desenhavel* irProximo();

	void inicializarDesenhaveis(GerenciadorGrafico &gf, GerenciadorEventos &ge);
	void atualizarDesenhaveis(float t);
	void desenharDesenhaveis(GerenciadorGrafico &g);
	void destruirDesenhaveis();



};

#endif
