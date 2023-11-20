#pragma once
#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_




template <typename T>

class vetor2D {

public:
	
	T x, y;

	vetor2D(T X = 0.0, T Y = 0.0);
	~vetor2D();
	vetor2D operator  +(vetor2D v);
	vetor2D operator  -(vetor2D v);
	vetor2D operator  *(int i);
	vetor2D operator  *(float f);
	vetor2D operator  *(double d);

	void operator  +=(vetor2D v);
	//void operator  -=(vetor2D v);
	//void operator  *=(int i);
	//void operator  *=(float f);
	//void operator  *=(double d);

	T operator *(vetor2D v);
	T modulo();
	vetor2D versor();
	vetor2D projOrtogonal(vetor2D v);


};

typedef vetor2D<float> vetor2F;
typedef vetor2D<unsigned>vetor2U;

#include "vetor2DImplementacao.h"

#endif
