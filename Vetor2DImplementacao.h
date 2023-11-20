#pragma once
#include <cmath>
#include "vetor2D.h"


template <typename T>  
class vetor2D;

template <typename T>
vetor2D<T>::vetor2D(T X, T Y) : x { X }, y{ Y }{

}
template <typename T>
vetor2D<T>::~vetor2D() {

}

template <typename T>
vetor2D<T> vetor2D<T>::operator  +(vetor2D<T> v){

	return vetor2D<T>(x + v.x, y + v.y);
	}

template <typename T>
vetor2D<T> vetor2D<T>::operator  -(vetor2D<T> v) {

	return vetor2D<T>(x - v.x, y - v.y);
	}

template <typename T>
vetor2D<T> vetor2D<T>::operator  *(int i) {

	return vetor2D<T>(x*i, y*i);
	}

template <typename T>
vetor2D<T> vetor2D<T>::operator  *(float f) {

	return vetor2D<T>(x*f, y*f);
	}

template <typename T>
vetor2D<T> vetor2D<T>::operator  *(double d) {

	return vetor2D<T>(x*d, y*d);
	}

template <typename T>
void vetor2D<T>::operator  +=(vetor2D<T> v) {

	x += v.x;
	y += v.y;
}

template <typename T>
T vetor2D<T>::operator *(vetor2D<T> v) {

	return x * v.x + y * v.y;
	}

template <typename T>
T vetor2D<T>::modulo() {

	return sqrt(pow(x. 2) + pow(y.2));
	}

template <typename T>
vetor2D<T> vetor2D<T>::versor() {

	return this->operator *(1.0f/modulo());
	}

template <typename T>
vetor2D<T> vetor2D<T>::projOrtogonal(vetor2D<T> v) {

	return v * (this->operator*(v) / pow(v.modulo().2));
	}

