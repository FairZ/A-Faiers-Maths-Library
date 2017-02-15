#include "AFMaths.h"

Vector :: Vector(float _W, float _X,float _Y,float _Z)
{
	m_a = _W;
	m_b = _X;
	m_c = _Y;
	m_w = _Z;
}

Vector :: Vector()
{
	m_a = 0;
	m_b = 0;
	m_c = 0;
	m_w = 0;
}

float Vector::getA()
{
	return m_a;
}

float Vector::getB()
{
	return m_b;
}

float Vector::getC()
{
	return m_c;
}

float Vector::getW()
{
	return m_w;
}

void Vector::setA(float _val)
{
	m_a = _val;
}

void Vector::setB(float _val)
{
	m_b = _val;
}

void Vector::setC(float _val)
{
	m_c = _val;
}

void Vector::setW(float _val)
{
	m_w = _val;
}

Vector VecVecAddition(Vector _X, Vector _Y)
{
	Vector temp;

	temp.setA(_X.getA()+_Y.getA());
	temp.setB(_X.getB()+_Y.getB());
	temp.setC(_X.getC()+_Y.getC());
	temp.setW(_X.getW()+_Y.getW());

	return temp;
}

Vector VecVecSubtraction(Vector _X, Vector _Y)
{
	Vector temp;

	temp.setA(_X.getA()-_Y.getA());
	temp.setB(_X.getB()-_Y.getB());
	temp.setC(_X.getC()-_Y.getC());
	temp.setW(_X.getW()-_Y.getW());

	return temp;
}

Vector VecScalMultiplication(Vector _X, float _Y)
{
	Vector temp;

	temp.setA(_X.getA()*_Y);
	temp.setB(_X.getB()*_Y);
	temp.setC(_X.getC()*_Y);
	temp.setW(_X.getW()*_Y);

	return temp;
}

Vector VecScalDivision(Vector _X, float _Y)
{
	Vector temp;

	temp.setA(_X.getA()/_Y);
	temp.setB(_X.getB()/_Y);
	temp.setC(_X.getC()/_Y);
	temp.setW(_X.getW()/_Y);

	return temp;
}

Vector VecVecCrossProduct(Vector _X,Vector _Y)
{
	Vector temp;

	temp.setA( (_X.getB() * _Y.getC()) - (_X.getC() * _Y.getB()) );
	temp.setB( (_X.getC() * _Y.getA()) - (_X.getA() * _Y.getC()) );
	temp.setC( (_X.getA() * _Y.getB()) - (_X.getB() * _Y.getA()) );

	return temp;
}

float VecVecDotProduct(Vector _X, Vector _Y)
{
	float temp;

	temp = ( (_X.getA() * _Y.getA()) + (_X.getB() * _Y.getB()) + (_X.getC() * _Y.getC()) );


	return temp;
}
