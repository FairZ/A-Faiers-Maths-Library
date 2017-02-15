#ifndef _CUBE_H_
#define _CUBE_H_

#include "AFMaths.h"					//included to allow use of vector and matrix maths
#include "AllegroInit.h"			//included to allow use of allegro

class Cube										//Cube class conatins 4 position vectors (one for each corner), a default contructor to create a rectangle, functions to get and set the position vector values
{															//and functions to perform transformations on and draw the rectangle. It is named cube as it was originally designed to be 3D but later simplified to 2D
private:
	Vector m_PosA;
	Vector m_PosB;
	Vector m_PosC;
	Vector m_PosD;
public:
	Cube();
	float GetPosAX();
	float GetPosAY();
	float GetPosAZ();
	float GetPosAW();
	float GetPosBX();
	float GetPosBY();
	float GetPosBZ();
	float GetPosBW();
	float GetPosCX();
	float GetPosCY();
	float GetPosCZ();
	float GetPosCW();
	float GetPosDX();
	float GetPosDY();
	float GetPosDZ();
	float GetPosDW();
	void SetPosAX(float _X);
	void SetPosAY(float _Y);
	void SetPosAZ(float _Z);
	void SetPosBX(float _X);
	void SetPosBY(float _Y);
	void SetPosBZ(float _Z);
	void SetPosCX(float _X);
	void SetPosCY(float _Y);
	void SetPosCZ(float _Z);
	void SetPosDX(float _X);
	void SetPosDY(float _Y);
	void SetPosDZ(float _Z);
	void Rotate(Matrix _rotation);
	void RotateCentre(Matrix _rotation);
	void Translate(Matrix _translation);
	void Scale(Matrix _scaling);
	void DrawCube(BITMAP *_buffer);
};


#endif