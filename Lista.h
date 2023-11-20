#pragma once
#ifndef _LISTA_H_
#define _LISTA_H_


template <typename TF>
class Lista {


private:

	template <typename TE>
	class ElementoLista {

	private:
		TE info;
		ElementoLista* ant;
		ElementoLista* prox;


	public:
		ElementoLista(TE Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
		~ElementoLista();

		TE getInfo();
		void setInfo(TE Info);

		ElementoLista* getAnt();
		void setAnt(ElementoLista* Ant);

		ElementoLista* getProx();
		void setProx(ElementoLista* Prox);

	};

	ElementoLista<TF>* inicio;
	ElementoLista<TF>* fim;
	ElementoLista<TF>* atual;

public:
	Lista();
	~Lista();

	void inserir(TF info);
	void esvaziar();
	TF voltarInicio();
	TF irProximo();


};

#include "ListaImplementacao.h"

#endif
