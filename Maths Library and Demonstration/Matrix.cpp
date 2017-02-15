#include "AFMaths.h"

Matrix::Matrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(float _a,float _b, float _c, float _d
							,float _e,float _f, float _g, float _h
							,float _i,float _j, float _k, float _l
							,float _m,float _n, float _o, float _p)
{
	m_matrix[0][0] = _a;
	m_matrix[0][1] = _b;
	m_matrix[0][2] = _c;
	m_matrix[0][3] = _d;
	m_matrix[1][0] = _e;
	m_matrix[1][1] = _f;
	m_matrix[1][2] = _g;
	m_matrix[1][3] = _h;
	m_matrix[2][0] = _i;
	m_matrix[2][1] = _j;
	m_matrix[2][2] = _k;
	m_matrix[2][3] = _l;
	m_matrix[3][0] = _m;
	m_matrix[3][1] = _n;
	m_matrix[3][2] = _o;
	m_matrix[3][3] = _p;
}

float Matrix::getMatrixR1C1()
{
	return m_matrix[0][0];
}

float Matrix::getMatrixR1C2()
{
	return m_matrix[0][1];
}

float Matrix::getMatrixR1C3()
{
	return m_matrix[0][2];
}

float Matrix::getMatrixR1C4()
{
	return m_matrix[0][3];
}

float Matrix::getMatrixR2C1()
{
	return m_matrix[1][0];
}

float Matrix::getMatrixR2C2()
{
	return m_matrix[1][1];
}

float Matrix::getMatrixR2C3()
{
	return m_matrix[1][2];
}

float Matrix::getMatrixR2C4()
{
	return m_matrix[1][3];
}

float Matrix::getMatrixR3C1()
{
	return m_matrix[2][0];
}

float Matrix::getMatrixR3C2()
{
	return m_matrix[2][1];
}

float Matrix::getMatrixR3C3()
{
	return m_matrix[2][2];
}

float Matrix::getMatrixR3C4()
{
	return m_matrix[2][3];
}

float Matrix::getMatrixR4C1()
{
	return m_matrix[3][0];
}

float Matrix::getMatrixR4C2()
{
	return m_matrix[3][1];
}

float Matrix::getMatrixR4C3()
{
	return m_matrix[3][2];
}

float Matrix::getMatrixR4C4()
{
	return m_matrix[3][3];
}

void Matrix::setMatrixR1(float _a,float _b, float _c, float _d)
{
	m_matrix[0][0] = _a;
	m_matrix[0][1] = _b;
	m_matrix[0][2] = _c;
	m_matrix[0][3] = _d;
}

void Matrix::setMatrixR2(float _a,float _b, float _c, float _d)
{
	m_matrix[1][0] = _a;
	m_matrix[1][1] = _b;
	m_matrix[1][2] = _c;
	m_matrix[1][3] = _d;
}

void Matrix::setMatrixR3(float _a,float _b, float _c, float _d)
{
	m_matrix[2][0] = _a;
	m_matrix[2][1] = _b;
	m_matrix[2][2] = _c;
	m_matrix[2][3] = _d;
}

void Matrix::setMatrixR4(float _a,float _b, float _c, float _d)
{
	m_matrix[3][0] = _a;
	m_matrix[3][1] = _b;
	m_matrix[3][2] = _c;
	m_matrix[3][3] = _d;
}

Matrix MatScalMultiplication(Matrix _X, float _Y)
{
	Matrix temp;
	temp.setMatrixR1(_X.getMatrixR1C1()*_Y, _X.getMatrixR1C2()*_Y, _X.getMatrixR1C3()*_Y, _X.getMatrixR1C4()*_Y);
	temp.setMatrixR2(_X.getMatrixR2C1()*_Y, _X.getMatrixR2C2()*_Y, _X.getMatrixR2C3()*_Y, _X.getMatrixR2C4()*_Y);
	temp.setMatrixR3(_X.getMatrixR3C1()*_Y, _X.getMatrixR3C2()*_Y, _X.getMatrixR3C3()*_Y, _X.getMatrixR3C4()*_Y);
	temp.setMatrixR4(_X.getMatrixR4C1()*_Y, _X.getMatrixR4C2()*_Y, _X.getMatrixR4C3()*_Y, _X.getMatrixR4C4()*_Y);
	return temp;
}

Matrix MatScalDivision(Matrix _X, float _Y)
{
	Matrix temp;
	temp.setMatrixR1(_X.getMatrixR1C1()/_Y, _X.getMatrixR1C2()/_Y, _X.getMatrixR1C3()/_Y, _X.getMatrixR1C4()/_Y);
	temp.setMatrixR2(_X.getMatrixR2C1()/_Y, _X.getMatrixR2C2()/_Y, _X.getMatrixR2C3()/_Y, _X.getMatrixR2C4()/_Y);
	temp.setMatrixR3(_X.getMatrixR3C1()/_Y, _X.getMatrixR3C2()/_Y, _X.getMatrixR3C3()/_Y, _X.getMatrixR3C4()/_Y);
	temp.setMatrixR4(_X.getMatrixR4C1()/_Y, _X.getMatrixR4C2()/_Y, _X.getMatrixR4C3()/_Y, _X.getMatrixR4C4()/_Y);
	return temp;
}

Vector MatVecMultiplication(Matrix _X, Vector _Y)
{
	Vector temp;
	temp.setA((_X.getMatrixR1C1()*_Y.getA())+(_X.getMatrixR1C2()*_Y.getB())+(_X.getMatrixR1C3()*_Y.getC())+(_X.getMatrixR1C4()*_Y.getW()));
	temp.setB((_X.getMatrixR2C1()*_Y.getA())+(_X.getMatrixR2C2()*_Y.getB())+(_X.getMatrixR2C3()*_Y.getC())+(_X.getMatrixR2C4()*_Y.getW()));
	temp.setC((_X.getMatrixR3C1()*_Y.getA())+(_X.getMatrixR3C2()*_Y.getB())+(_X.getMatrixR3C3()*_Y.getC())+(_X.getMatrixR3C4()*_Y.getW()));
	temp.setW((_X.getMatrixR4C1()*_Y.getA())+(_X.getMatrixR4C2()*_Y.getB())+(_X.getMatrixR4C3()*_Y.getC())+(_X.getMatrixR4C4()*_Y.getW()));
	return temp;
}

Matrix MatMatAddition(Matrix _X, Matrix _Y)
{
	Matrix temp;
	temp.setMatrixR1((_X.getMatrixR1C1()+_Y.getMatrixR1C1()),(_X.getMatrixR1C2()+_Y.getMatrixR1C2()),(_X.getMatrixR1C3()+_Y.getMatrixR1C3()),(_X.getMatrixR1C4()+_Y.getMatrixR1C4()));
	temp.setMatrixR2((_X.getMatrixR2C1()+_Y.getMatrixR2C1()),(_X.getMatrixR2C2()+_Y.getMatrixR2C2()),(_X.getMatrixR2C3()+_Y.getMatrixR2C3()),(_X.getMatrixR2C4()+_Y.getMatrixR2C4()));
	temp.setMatrixR3((_X.getMatrixR3C1()+_Y.getMatrixR3C1()),(_X.getMatrixR3C2()+_Y.getMatrixR3C2()),(_X.getMatrixR3C3()+_Y.getMatrixR3C3()),(_X.getMatrixR3C4()+_Y.getMatrixR3C4()));
	temp.setMatrixR4((_X.getMatrixR4C1()+_Y.getMatrixR4C1()),(_X.getMatrixR4C2()+_Y.getMatrixR4C2()),(_X.getMatrixR4C3()+_Y.getMatrixR4C3()),(_X.getMatrixR4C4()+_Y.getMatrixR4C4()));
	return temp;
}

Matrix MatMatSubtraction(Matrix _X, Matrix _Y)
{
	Matrix temp;
	temp.setMatrixR1((_X.getMatrixR1C1()-_Y.getMatrixR1C1()),(_X.getMatrixR1C2()-_Y.getMatrixR1C2()),(_X.getMatrixR1C3()-_Y.getMatrixR1C3()),(_X.getMatrixR1C4()-_Y.getMatrixR1C4()));
	temp.setMatrixR2((_X.getMatrixR2C1()-_Y.getMatrixR2C1()),(_X.getMatrixR2C2()-_Y.getMatrixR2C2()),(_X.getMatrixR2C3()-_Y.getMatrixR2C3()),(_X.getMatrixR2C4()-_Y.getMatrixR2C4()));
	temp.setMatrixR3((_X.getMatrixR3C1()-_Y.getMatrixR3C1()),(_X.getMatrixR3C2()-_Y.getMatrixR3C2()),(_X.getMatrixR3C3()-_Y.getMatrixR3C3()),(_X.getMatrixR3C4()-_Y.getMatrixR3C4()));
	temp.setMatrixR4((_X.getMatrixR4C1()-_Y.getMatrixR4C1()),(_X.getMatrixR4C2()-_Y.getMatrixR4C2()),(_X.getMatrixR4C3()-_Y.getMatrixR4C3()),(_X.getMatrixR4C4()-_Y.getMatrixR4C4()));
	return temp;
}

Matrix MatMatMultiplication(Matrix _X, Matrix _Y)
{
	Matrix temp;
	float R1[4];
	float R2[4];
	float R3[4];
	float R4[4];

	R1[0] = ((_X.getMatrixR1C1()*_Y.getMatrixR1C1())+(_X.getMatrixR1C2()*_Y.getMatrixR2C1())+(_X.getMatrixR1C3()*_Y.getMatrixR3C1())+(_X.getMatrixR1C4()*_Y.getMatrixR4C1()));
	R1[1] = ((_X.getMatrixR1C1()*_Y.getMatrixR1C2())+(_X.getMatrixR1C2()*_Y.getMatrixR2C2())+(_X.getMatrixR1C3()*_Y.getMatrixR3C2())+(_X.getMatrixR1C4()*_Y.getMatrixR4C2()));
	R1[2] = ((_X.getMatrixR1C1()*_Y.getMatrixR1C3())+(_X.getMatrixR1C2()*_Y.getMatrixR2C3())+(_X.getMatrixR1C3()*_Y.getMatrixR3C3())+(_X.getMatrixR1C4()*_Y.getMatrixR4C3()));
	R1[3] = ((_X.getMatrixR1C1()*_Y.getMatrixR1C4())+(_X.getMatrixR1C2()*_Y.getMatrixR2C4())+(_X.getMatrixR1C3()*_Y.getMatrixR3C4())+(_X.getMatrixR1C4()*_Y.getMatrixR4C4()));

	R2[0] = ((_X.getMatrixR2C1()*_Y.getMatrixR1C1())+(_X.getMatrixR2C2()*_Y.getMatrixR2C1())+(_X.getMatrixR2C3()*_Y.getMatrixR3C1())+(_X.getMatrixR2C4()*_Y.getMatrixR4C1()));
	R2[1] = ((_X.getMatrixR2C1()*_Y.getMatrixR1C2())+(_X.getMatrixR2C2()*_Y.getMatrixR2C2())+(_X.getMatrixR2C3()*_Y.getMatrixR3C2())+(_X.getMatrixR2C4()*_Y.getMatrixR4C2()));
	R2[2] = ((_X.getMatrixR2C1()*_Y.getMatrixR1C3())+(_X.getMatrixR2C2()*_Y.getMatrixR2C3())+(_X.getMatrixR2C3()*_Y.getMatrixR3C3())+(_X.getMatrixR2C4()*_Y.getMatrixR4C3()));
	R2[3] = ((_X.getMatrixR2C1()*_Y.getMatrixR1C4())+(_X.getMatrixR2C2()*_Y.getMatrixR2C4())+(_X.getMatrixR2C3()*_Y.getMatrixR3C4())+(_X.getMatrixR2C4()*_Y.getMatrixR4C4()));

	R3[0] = ((_X.getMatrixR3C1()*_Y.getMatrixR1C1())+(_X.getMatrixR3C2()*_Y.getMatrixR2C1())+(_X.getMatrixR3C3()*_Y.getMatrixR3C1())+(_X.getMatrixR3C4()*_Y.getMatrixR4C1()));
	R3[1] = ((_X.getMatrixR3C1()*_Y.getMatrixR1C2())+(_X.getMatrixR3C2()*_Y.getMatrixR2C2())+(_X.getMatrixR3C3()*_Y.getMatrixR3C2())+(_X.getMatrixR3C4()*_Y.getMatrixR4C2()));
	R3[2] = ((_X.getMatrixR3C1()*_Y.getMatrixR1C3())+(_X.getMatrixR3C2()*_Y.getMatrixR2C3())+(_X.getMatrixR3C3()*_Y.getMatrixR3C3())+(_X.getMatrixR3C4()*_Y.getMatrixR4C3()));
	R3[3] = ((_X.getMatrixR3C1()*_Y.getMatrixR1C4())+(_X.getMatrixR3C2()*_Y.getMatrixR2C4())+(_X.getMatrixR3C3()*_Y.getMatrixR3C4())+(_X.getMatrixR3C4()*_Y.getMatrixR4C4()));

	R4[0] = ((_X.getMatrixR4C1()*_Y.getMatrixR1C1())+(_X.getMatrixR4C2()*_Y.getMatrixR2C1())+(_X.getMatrixR4C3()*_Y.getMatrixR3C1())+(_X.getMatrixR4C4()*_Y.getMatrixR4C1()));
	R4[1] = ((_X.getMatrixR4C1()*_Y.getMatrixR1C2())+(_X.getMatrixR4C2()*_Y.getMatrixR2C2())+(_X.getMatrixR4C3()*_Y.getMatrixR3C2())+(_X.getMatrixR4C4()*_Y.getMatrixR4C2()));
	R4[2] = ((_X.getMatrixR4C1()*_Y.getMatrixR1C3())+(_X.getMatrixR4C2()*_Y.getMatrixR2C3())+(_X.getMatrixR4C3()*_Y.getMatrixR3C3())+(_X.getMatrixR4C4()*_Y.getMatrixR4C3()));
	R4[3] = ((_X.getMatrixR4C1()*_Y.getMatrixR1C4())+(_X.getMatrixR4C2()*_Y.getMatrixR2C4())+(_X.getMatrixR4C3()*_Y.getMatrixR3C4())+(_X.getMatrixR4C4()*_Y.getMatrixR4C4()));

	temp.setMatrixR1(R1[0], R1[1], R1[2], R1[3]);
	temp.setMatrixR2(R2[0], R2[1], R2[2], R2[3]);
	temp.setMatrixR3(R3[0], R3[1], R3[2], R3[3]);
	temp.setMatrixR4(R4[0], R4[1], R4[2], R4[3]);

	return temp;
}
