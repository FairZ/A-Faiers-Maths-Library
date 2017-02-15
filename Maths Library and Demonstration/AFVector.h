#ifndef AFVECTOR_H
#define AFVECTOR_H

#include <math.h>						//included to allow later use of trigonometric and other maths functions later in the program


class Vector
{
private:
	float m_a;
	float m_b;
	float m_c;
	float m_w;
public:
	Vector(float _W, float _X, float _Y, float _Z);
	Vector();
	float getA();
	float getB();
	float getC();
	float getW();
	void setA(float _val);
	void setB(float _val);
	void setC(float _val);
	void setW(float _val);
};







#endif