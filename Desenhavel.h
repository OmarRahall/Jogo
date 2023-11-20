#pragma once

#ifndef _DESENHAVEL_H_
#define _DESENHAVEL_H_
#include "vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

class Desenhavel
{
protected:

	vetor2F posicao;
	vetor2F v;
	const char* caminho;

public:

	Desenhavel(vetor2F pos, vetor2F vel, const char* caminhoTextura = nullptr);
	virtual ~Desenhavel();
	virtual void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge);
	virtual void atualizar(float t);
	virtual void desenhar(GerenciadorGrafico &g);

};

#endif
