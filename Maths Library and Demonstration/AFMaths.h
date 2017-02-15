#ifndef AFMATHS_H
#define AFMATHS_H

#include "AFMatrix.h"

Vector VecVecAddition(Vector _X, Vector _Y);
Vector VecVecSubtraction(Vector _X, Vector _Y);
Vector VecScalMultiplication(Vector _X, float _Y);
Vector VecScalDivision(Vector _X, float _Y);
Vector VecVecCrossProduct(Vector _X,Vector _Y);
float VecVecDotProduct(Vector _X, Vector _Y);

Matrix MatScalMultiplication(Matrix _X, float _Y);
Matrix MatScalDivision(Matrix _X, float _Y);
Vector MatVecMultiplication(Matrix _X, Vector _Y);
Matrix MatMatAddition(Matrix _X, Matrix _Y);
Matrix MatMatSubtraction(Matrix _X, Matrix _Y);
Matrix MatMatMultiplication(Matrix _X, Matrix _Y);





#endif