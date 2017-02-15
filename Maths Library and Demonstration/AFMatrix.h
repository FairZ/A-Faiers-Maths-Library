#ifndef AFMATRIX_H
#define AFMATRIX_H

#include "AFVector.h"


class Matrix
{
private:
	float m_matrix[4][4];
public:
	Matrix();
	Matrix(float _a,float _b, float _c, float _d
				,float _e,float _f, float _g, float _h
				,float _i,float _j, float _k, float _l
				,float _m,float _n, float _o, float _p);
	float getMatrixR1C1();
	float getMatrixR1C2();
	float getMatrixR1C3();
	float getMatrixR1C4();
	float getMatrixR2C1();
	float getMatrixR2C2();
	float getMatrixR2C3();
	float getMatrixR2C4();
	float getMatrixR3C1();
	float getMatrixR3C2();
	float getMatrixR3C3();
	float getMatrixR3C4();
	float getMatrixR4C1();
	float getMatrixR4C2();
	float getMatrixR4C3();
	float getMatrixR4C4();
	void setMatrixR1(float _a,float _b, float _c, float _d);
	void setMatrixR2(float _a,float _b, float _c, float _d);
	void setMatrixR3(float _a,float _b, float _c, float _d);
	void setMatrixR4(float _a,float _b, float _c, float _d);
};






#endif