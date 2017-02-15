#include "Cube.h"								//included to be able to define the functions used in cube.h


Cube::Cube()										//default constructor creates 4 vectors and assigns them to the position vectors in order to create the intial rectangle
{
	Vector initialA(0,0,0,1);
	Vector initialB(SCREEN_W/20 * 3,0,0,1);
	Vector initialC(0,SCREEN_H/20 * 2,0,1);
	Vector initialD(SCREEN_W/20 *3,SCREEN_H/20 *2,0,1);

	m_PosA = initialA;
	m_PosB = initialB;
	m_PosC = initialC;
	m_PosD = initialD;
}

float Cube::GetPosAX()					//all get functions simply return the appropiate value
{
	return m_PosA.getA();
}

float Cube::GetPosAY()
{
	return m_PosA.getB();
}

float Cube::GetPosAZ()
{
	return m_PosA.getC();
}

float Cube::GetPosAW()
{
	return m_PosA.getW();
}

float Cube::GetPosBX()
{
	return m_PosB.getA();
}

float Cube::GetPosBY()
{
	return m_PosB.getB();
}

float Cube::GetPosBZ()
{
	return m_PosB.getC();
}

float Cube::GetPosBW()
{
	return m_PosB.getW();
}

float Cube::GetPosCX()
{
	return m_PosC.getA();
}

float Cube::GetPosCY()
{
	return m_PosC.getB();
}

float Cube::GetPosCZ()
{
	return m_PosC.getC();
}

float Cube::GetPosCW()
{
	return m_PosC.getW();
}

float Cube::GetPosDX()
{
	return m_PosD.getA();
}

float Cube::GetPosDY()
{
	return m_PosD.getB();
}

float Cube::GetPosDZ()
{
	return m_PosD.getC();
}

float Cube::GetPosDW()
{
	return m_PosD.getW();
}

void Cube::SetPosAX(float _X)					//all the set functions simply set the appropriate value
{
	m_PosA.setA(_X);
}

void Cube::SetPosAY(float _Y)
{
	m_PosA.setB(_Y);
}

void Cube::SetPosAZ(float _Z)
{
	m_PosA.setC(_Z);
}

void Cube::SetPosBX(float _X)
{
	m_PosB.setA(_X);
}

void Cube::SetPosBY(float _Y)
{
	m_PosB.setB(_Y);
}

void Cube::SetPosBZ(float _Z)
{
	m_PosB.setC(_Z);
}

void Cube::SetPosCX(float _X)
{
	m_PosC.setA(_X);
}

void Cube::SetPosCY(float _Y)
{
	m_PosC.setB(_Y);
}

void Cube::SetPosCZ(float _Z)
{
	m_PosC.setC(_Z);
}

void Cube::SetPosDX(float _X)
{
	m_PosD.setA(_X);
}

void Cube::SetPosDY(float _Y)
{
	m_PosD.setB(_Y);
}

void Cube::SetPosDZ(float _Z)
{
	m_PosD.setC(_Z);
}

void Cube::Rotate(Matrix _rotation)										//multiplies the position vectors by a rotation matrix defined in the demonstration
{
	m_PosA = MatVecMultiplication(_rotation, m_PosA);
	m_PosB = MatVecMultiplication(_rotation, m_PosB);
	m_PosC = MatVecMultiplication(_rotation, m_PosC);
	m_PosD = MatVecMultiplication(_rotation, m_PosD);
}

void Cube::Translate(Matrix _translation)								//multiplies the position vectors by a translation matrix defined in the demonstration
{
	m_PosA = MatVecMultiplication(_translation, m_PosA);
	m_PosB = MatVecMultiplication(_translation, m_PosB);
	m_PosC = MatVecMultiplication(_translation, m_PosC);
	m_PosD = MatVecMultiplication(_translation, m_PosD);
}

void Cube::Scale(Matrix _scaling)											//multiplies the position vectors by a scaling matrix defined in the demonstration
{
	m_PosA = MatVecMultiplication(_scaling, m_PosA);
	m_PosB = MatVecMultiplication(_scaling, m_PosB);
	m_PosC = MatVecMultiplication(_scaling, m_PosC);
	m_PosD = MatVecMultiplication(_scaling, m_PosD);

}
	
void Cube::DrawCube(BITMAP *_buffer)									//draws triangles between the position vectors in order to draw a rectangle then outlines the rectangle with 4 lines
{
	triangle(_buffer,m_PosA.getA(),m_PosA.getB(),m_PosB.getA(),m_PosB.getB(),m_PosC.getA(),m_PosC.getB(),makecol(0,255,0));
	triangle(_buffer,m_PosB.getA(),m_PosB.getB(),m_PosC.getA(),m_PosC.getB(),m_PosD.getA(),m_PosD.getB(),makecol(0,255,0));
	line(_buffer,m_PosA.getA(),m_PosA.getB(),m_PosB.getA(),m_PosB.getB(),makecol(255,0,0));
	line(_buffer,m_PosA.getA(),m_PosA.getB(),m_PosC.getA(),m_PosC.getB(),makecol(255,0,0));
	line(_buffer,m_PosC.getA(),m_PosC.getB(),m_PosD.getA(),m_PosD.getB(),makecol(255,0,0));
	line(_buffer,m_PosD.getA(),m_PosD.getB(),m_PosB.getA(),m_PosB.getB(),makecol(255,0,0));
}
