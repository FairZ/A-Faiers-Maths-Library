#include "Demonstration.h"



int main()								//main function is run first
{
	if (AllegroInit()==0)		//if the allegro initialization works then run the menu
	{
		int MenuControl = 3;	//value initialized to one that will allow the while loop to runand cause no problems

		while (MenuControl != 2)	//repeat unless the user wishes to quit
		{
			if (MenuControl == 0)		//if the user chose option 1 in the menu run the rectangle demo
			{
				RectangleDemo();
			}
			else if(MenuControl == 1)	//if the user chose the second option run the calculator demo
			{
				Calculator();
			}
			MenuControl = Menu();	//run the menu function and assign its return value to MenuControl
		}
	}
	AllegroDeInit();		//deinitialize allegro at the game exit
	return 0;				//exit with a default value
}
END_OF_MAIN()

int Menu()	//function giving the user a menu and allowing them to pick an option
{
	int returnValue;				//creation of initial variables
	bool exitMenu = false;

	clear_to_color(screen,0);	//make sure the screen is clear
	textout_centre(screen,font,"Press ESC to exit",SCREEN_W/2,20,makecol(255,255,255));																						//write the options on the screen
	textout_centre(screen,font,"Press 1 for 2D vector and matrix manipulation",SCREEN_W/2,SCREEN_H/2 - 30,makecol(255,255,255));
	textout_centre(screen,font,"Press 2 for vector and matrix calculator",SCREEN_W/2,SCREEN_H/2 + 20,makecol(255,255,255));

	_sleep(500);		//wait to ensure that a previous button press does not effect this choice

	while(exitMenu == false) //thile the user has yet to make a choice loop
	{
		
		if (key[KEY_1])				//if the player presses 1 exit the loop and return the value 0 
		{
			exitMenu = true;
			returnValue = 0;
		}
		if (key[KEY_2])				//if the player presses 2 exit the loop and return the value 1
		{
			exitMenu = true;
			returnValue = 1;
		}
		if (key[KEY_ESC])			//if the player presses Esc exit the loop and return the value 2
		{
			exitMenu = true;
			returnValue = 2;
		}

	}
	return returnValue;
}

void RectangleDemo()				//function using vectors and matrices to draw and transform polygons
{
	float angleClockwise = 0.261799f;														//initialize all neccessary variables with appropriate values
	float angleClockwiseSmall = 0.0174533f;											//angles in radians for use in math.h's sin and cos
	float angleAnticlockwise = -0.261799f;
	float angleAnticlockwiseSmall = -0.0174533f;
	BITMAP* buffer = create_bitmap(SCREEN_H,SCREEN_W);
	BITMAP* background = load_bitmap("Axis.bmp",0);
	Cube s_cube;
	Matrix right(1,0,0,SCREEN_W/20,0,1,0,0,0,0,1,0,0,0,0,1);	//all transformation matrices are initialized here
	Matrix rightSmall(1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1);
	Matrix left(1,0,0,-SCREEN_W/20,0,1,0,0,0,0,1,0,0,0,0,1);
	Matrix leftSmall(1,0,0,-1,0,1,0,0,0,0,1,0,0,0,0,1);
	Matrix up(1,0,0,0,0,1,0,-SCREEN_W/20,0,0,1,0,0,0,0,1);
	Matrix upSmall(1,0,0,0,0,1,0,-1,0,0,1,0,0,0,0,1);
	Matrix down(1,0,0,0,0,1,0,SCREEN_W/20,0,0,1,0,0,0,0,1);
	Matrix downSmall(1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1);
	Matrix scaleUpXY(2,0,0,0,0,2,0,0,0,0,1,0,0,0,0,1);
	Matrix scaleDownXY(0.5,0,0,0,0,0.5,0,0,0,0,1,0,0,0,0,1);
	Matrix rotateClockwise(cos(angleClockwise),-sin(angleClockwise),0,0,sin(angleClockwise),cos(angleClockwise),0,0,0,0,1,0,0,0,0,1);
	Matrix rotateClockwiseSmall(cos(angleClockwiseSmall),-sin(angleClockwiseSmall),0,0,sin(angleClockwiseSmall),cos(angleClockwiseSmall),0,0,0,0,1,0,0,0,0,1);
	Matrix rotateAnticlockwise(cos(angleAnticlockwise),-sin(angleAnticlockwise),0,0,sin(angleAnticlockwise),cos(angleAnticlockwise),0,0,0,0,1,0,0,0,0,1);
	Matrix rotateAnticlockwiseSmall(cos(angleAnticlockwiseSmall),-sin(angleAnticlockwiseSmall),0,0,sin(angleAnticlockwiseSmall),cos(angleAnticlockwiseSmall),0,0,0,0,1,0,0,0,0,1);
	int moving = 0;

	while(!key[KEY_ESC]) //loop until the user wants to exit
	{
		blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);		//copy updated information to the screen
		clear_to_color(buffer,0);													//clear the old information from the buffer
		line(buffer,0,0,s_cube.GetPosDX(),s_cube.GetPosDY(),makecol(0,255,255));	//draw lines to the corners of the rectangle to better show transformations
		line(buffer,0,0,s_cube.GetPosCX(),s_cube.GetPosCY(),makecol(0,170,255));
		line(buffer,0,0,s_cube.GetPosBX(),s_cube.GetPosBY(),makecol(0,85,255));
		line(buffer,0,0,s_cube.GetPosAX(),s_cube.GetPosAY(),makecol(0,0,255));
		s_cube.DrawCube(buffer);													//draw the cube to the buffer
		rectfill(buffer,s_cube.GetPosAX()-2,s_cube.GetPosAY()-2,s_cube.GetPosAX()+2,s_cube.GetPosAY()+2,makecol(0,0,255));	//draw cubes and letters on the corners of the cube to better show the positions
		textout_ex(buffer,font,"A",s_cube.GetPosAX()+2,s_cube.GetPosAY()+2,makecol(0,0,255),-1);
		rectfill(buffer,s_cube.GetPosBX()-2,s_cube.GetPosBY()-2,s_cube.GetPosBX()+2,s_cube.GetPosBY()+2,makecol(0,85,255));
		textout_ex(buffer,font,"B",s_cube.GetPosBX()+2,s_cube.GetPosBY()+2,makecol(0,85,255),-1);
		rectfill(buffer,s_cube.GetPosCX()-2,s_cube.GetPosCY()-2,s_cube.GetPosCX()+2,s_cube.GetPosCY()+2,makecol(0,170,255));
		textout_ex(buffer,font,"C",s_cube.GetPosCX()+2,s_cube.GetPosCY()+2,makecol(0,170,255),-1);
		rectfill(buffer,s_cube.GetPosDX()-2,s_cube.GetPosDY()-2,s_cube.GetPosDX()+2,s_cube.GetPosDY()+2,makecol(0,255,255));
		textout_ex(buffer,font,"D",s_cube.GetPosDX()+2,s_cube.GetPosDY()+2,makecol(0,255,255),-1);

		masked_stretch_blit(background,buffer,0,0,500,500,0,0,SCREEN_W,SCREEN_H);		//draw the axis and instructions onto the screen

		textprintf_right_ex(buffer,font,660,400,makecol(255,255,255),-1,"Vector A [ %3.0f , ",s_cube.GetPosAX());	//write the values of the position vectors to the screen
		textprintf_right_ex(buffer,font,700,400,makecol(255,255,255),-1,"%3.0f ]",s_cube.GetPosAY());
		textprintf_right_ex(buffer,font,660,420,makecol(255,255,255),-1,"Vector B [ %3.0f , ",s_cube.GetPosBX());
		textprintf_right_ex(buffer,font,700,420,makecol(255,255,255),-1,"%3.0f ]",s_cube.GetPosBY());
		textprintf_right_ex(buffer,font,660,440,makecol(255,255,255),-1,"Vector C [ %3.0f , ",s_cube.GetPosCX());
		textprintf_right_ex(buffer,font,700,440,makecol(255,255,255),-1,"%3.0f ]",s_cube.GetPosCY());
		textprintf_right_ex(buffer,font,660,460,makecol(255,255,255),-1,"Vector D [ %3.0f , ",s_cube.GetPosDX());
		textprintf_right_ex(buffer,font,700,460,makecol(255,255,255),-1,"%3.0f ]",s_cube.GetPosDY());

		//for each transformation a timer is set to slow down transformation speed

		if(key[KEY_RIGHT] && key[KEY_LSHIFT] && moving == 0)	//if user is holding shift and right do a small translate
		{
			s_cube.Translate(rightSmall);
			moving = 50;
		}
		else if(key[KEY_RIGHT] && moving == 0)		//if user is holding right translate the rectangle
		{
			s_cube.Translate(right);
			moving = 150;
		}

		if(key[KEY_LEFT] && key[KEY_LSHIFT] && moving == 0)		//if user is holding shift and left do a small translate
		{
			s_cube.Translate(leftSmall);
			moving = 50;
		}
		else if(key[KEY_LEFT] && moving == 0)		//if user is holding right translate the rectangle
		{
			s_cube.Translate(left);
			moving = 150;
		}

		if(key[KEY_UP] && key[KEY_LSHIFT] && moving == 0)		//if user is holding shift and up do a small translate
		{
			s_cube.Translate(upSmall);
			moving = 50;
		}
		else if(key[KEY_UP] && moving == 0)		//if user is holding right translate the rectangle
		{
			s_cube.Translate(up);
			moving = 150;
		}

		if(key[KEY_DOWN] && key[KEY_LSHIFT] && moving == 0)		//if user is holding shift and down do a small translate
		{
			s_cube.Translate(downSmall);
			moving = 50;
		}
		else if(key[KEY_DOWN] && moving == 0)		//if user is holding right translate the rectangle
		{
			s_cube.Translate(down);
			moving = 150;
		}

		if(key[KEY_X] && moving == 0)			//if the user is pressing X scale up the rectangle
		{
			s_cube.Scale(scaleUpXY);
			moving = 150;
		}

		if(key[KEY_Z] && moving == 0)		//if the user is pressing Z scale down the rectangle
		{
			s_cube.Scale(scaleDownXY);
			moving = 150;
		}

		if(key[KEY_Q] && key[KEY_LSHIFT] && moving == 0)		//if the user is holding shift and Q do a small rotate
		{
			s_cube.Rotate(rotateClockwiseSmall);
			moving = 50;
		}
		else if(key[KEY_Q] && moving == 0)		//if the user is pressing Q rotate clockwise
		{
			s_cube.Rotate(rotateClockwise);
			moving = 150;
		}

		if(key[KEY_E] && key[KEY_LSHIFT] && moving == 0)		//if the user is holding shift and E do a small rotate
		{
			s_cube.Rotate(rotateAnticlockwiseSmall);
			moving = 50;
		}
		if(key[KEY_E] && moving == 0)				//if the user is pressing E rotate anticlockwise
		{
			s_cube.Rotate(rotateAnticlockwise);
			moving = 150;
		}

		if(key[KEY_SPACE] && moving == 0)		//if the user is pressing space reset the rectangle
		{
			s_cube.SetPosAX(0);
			s_cube.SetPosAY(0);
			s_cube.SetPosAZ(0);
			s_cube.SetPosBX(SCREEN_W/20 *3);
			s_cube.SetPosBY(0);
			s_cube.SetPosBZ(0);
			s_cube.SetPosCX(0);
			s_cube.SetPosCY(SCREEN_H/20 *2);
			s_cube.SetPosCZ(0);
			s_cube.SetPosDX(SCREEN_W/20 *3);
			s_cube.SetPosDY(SCREEN_H/20 *2);
			s_cube.SetPosDZ(0);
			moving = 150;
		}

		if (moving > 0)		//if it isn't already at zero count down the timer
		{
			moving--;
		}

	}
	destroy_bitmap(buffer);				//free the memory used for the bitmaps
	destroy_bitmap(background);
}

void Calculator()						//function using the whole maths library to do calculations
{
	srand(time(NULL)); //set the random seed to the current time
	BITMAP *buffer = create_bitmap(SCREEN_W,SCREEN_H);				//create the buffer
	Vector s_Vec1(rand()%10,rand()%10,rand()%10,rand()%10);		//randomize all the initial values of the initial vectors and matrices
	Vector s_Vec2(rand()%10,rand()%10,rand()%10,rand()%10);	
	Matrix s_Mat1(rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10);
	Matrix s_Mat2(rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10);

	float scalar = 3.5f;		//initialize scalar value

	Vector s_VecVecAddition;				//create empty vectors and matrices ready to recieve answers to calculations
	Vector s_VecVecSubtraction;
	Vector s_VecScalMultiplication;
	Vector s_VecScalDivision;
	Vector s_VecVecCrossProduct;
	float s_VecVecDotProduct = 0;

	Matrix s_MatScalMultiplication;
	Matrix s_MatScalDivision;
	Vector s_MatVecMultiplication;
	Matrix s_MatMatAddition;
	Matrix s_MatMatSubtraction;
	Matrix s_MatMatMultiplication;

	s_VecVecAddition = VecVecAddition(s_Vec1,s_Vec2);									//assign the answers to all calculations to the empty variables
	s_VecVecSubtraction = VecVecSubtraction(s_Vec1,s_Vec2);
	s_VecScalMultiplication = VecScalMultiplication(s_Vec1,scalar);
	s_VecScalDivision = VecScalDivision(s_Vec1,scalar);
	s_VecVecCrossProduct = VecVecCrossProduct(s_Vec1,s_Vec2);
	s_VecVecDotProduct = VecVecDotProduct(s_Vec1,s_Vec2);

	s_MatScalMultiplication = MatScalMultiplication(s_Mat1,scalar);
	s_MatScalDivision = MatScalDivision(s_Mat1,scalar);
	s_MatVecMultiplication = MatVecMultiplication(s_Mat1, s_Vec1);
	s_MatMatAddition = MatMatAddition(s_Mat1,s_Mat2);
	s_MatMatSubtraction = MatMatSubtraction(s_Mat1,s_Mat2);
	s_MatMatMultiplication = MatMatMultiplication(s_Mat1,s_Mat2);

	clear_to_color(buffer,0); // give buffer a black background

	//the whole of the next section draws the UI to the screen including the values calculated by the previous calculations

	textout_centre(buffer,font,"Press ESC to exit",SCREEN_W/6,20,makecol(255,255,255)); 

	textout_centre(buffer,font,"VECTOR MATHS",SCREEN_W/2,40,makecol(255,255,255));
	line(buffer,SCREEN_W/3,50,SCREEN_W/3 *2,50,makecol(255,255,255));

	textout_right(buffer,font,"Vector 1:",180,70,makecol(255,255,255));
	textprintf(buffer,font,200,70,makecol(255,255,255),"X = %4.2f",s_Vec1.getA());			//%x.yf is used to draw the value of variables to specific accuracy
	textprintf(buffer,font,200,80,makecol(255,255,255),"Y = %4.2f",s_Vec1.getB());
	textprintf(buffer,font,200,90,makecol(255,255,255),"Z = %4.2f",s_Vec1.getC());
	textprintf(buffer,font,200,100,makecol(255,255,255),"W = %4.2f",s_Vec1.getW());

	textout_right(buffer,font,"Vector 2:",430,70,makecol(255,255,255));
	textprintf(buffer,font,450,70,makecol(255,255,255),"X = %4.2f",s_Vec2.getA());
	textprintf(buffer,font,450,80,makecol(255,255,255),"Y = %4.2f",s_Vec2.getB());
	textprintf(buffer,font,450,90,makecol(255,255,255),"Z = %4.2f",s_Vec2.getC());
	textprintf(buffer,font,450,100,makecol(255,255,255),"W = %4.2f",s_Vec2.getW());

	textout_right(buffer,font, "Vec1 + Vec2:",180,120,makecol(255,255,255));
	textprintf(buffer,font,200,120,makecol(255,255,255),"X = %4.2f",s_VecVecAddition.getA());
	textprintf(buffer,font,200,130,makecol(255,255,255),"Y = %4.2f",s_VecVecAddition.getB());
	textprintf(buffer,font,200,140,makecol(255,255,255),"Z = %4.2f",s_VecVecAddition.getC());
	textprintf(buffer,font,200,150,makecol(255,255,255),"W = %4.2f",s_VecVecAddition.getW());

	textout_right(buffer,font, "Vec1 - Vec2:",430,120,makecol(255,255,255));
	textprintf(buffer,font,450,120,makecol(255,255,255),"X = %4.2f",s_VecVecSubtraction.getA());
	textprintf(buffer,font,450,130,makecol(255,255,255),"Y = %4.2f",s_VecVecSubtraction.getB());
	textprintf(buffer,font,450,140,makecol(255,255,255),"Z = %4.2f",s_VecVecSubtraction.getC());
	textprintf(buffer,font,450,150,makecol(255,255,255),"W = %4.2f",s_VecVecSubtraction.getW());

	textout_right(buffer,font, "Vec1 * 3.5:",180,170,makecol(255,255,255));
	textprintf(buffer,font,200,170,makecol(255,255,255),"X = %4.2f",s_VecScalMultiplication.getA());
	textprintf(buffer,font,200,180,makecol(255,255,255),"Y = %4.2f",s_VecScalMultiplication.getB());
	textprintf(buffer,font,200,190,makecol(255,255,255),"Z = %4.2f",s_VecScalMultiplication.getC());
	textprintf(buffer,font,200,200,makecol(255,255,255),"W = %4.2f",s_VecScalMultiplication.getW());

	textout_right(buffer,font, "Vec1 / 3.5:",430,170,makecol(255,255,255));
	textprintf(buffer,font,450,170,makecol(255,255,255),"X = %4.2f",s_VecScalDivision.getA());
	textprintf(buffer,font,450,180,makecol(255,255,255),"Y = %4.2f",s_VecScalDivision.getB());
	textprintf(buffer,font,450,190,makecol(255,255,255),"Z = %4.2f",s_VecScalDivision.getC());
	textprintf(buffer,font,450,200,makecol(255,255,255),"W = %4.2f",s_VecScalDivision.getW());

	textout_right(buffer,font, "Vec1 X Vec2:",180,220,makecol(255,255,255));
	textprintf(buffer,font,200,220,makecol(255,255,255),"X = %4.2f",s_VecVecCrossProduct.getA());
	textprintf(buffer,font,200,230,makecol(255,255,255),"Y = %4.2f",s_VecVecCrossProduct.getB());
	textprintf(buffer,font,200,240,makecol(255,255,255),"Z = %4.2f",s_VecVecCrossProduct.getC());

	textout_right(buffer,font, "Vec1 . Vec2:",430,220,makecol(255,255,255));
	textprintf(buffer,font,450,220,makecol(255,255,255),"    %4.2f",s_VecVecDotProduct);
			
	textout_centre(buffer,font,"MATRIX MATHS",SCREEN_W/2,270,makecol(255,255,255));
	line(buffer,SCREEN_W/3,280,SCREEN_W/3 *2,280,makecol(255,255,255));

	textout_right(buffer,font, "Mat1:",100,300,makecol(255,255,255));
	textprintf(buffer,font,110,300,makecol(255,255,255),"%3.1f,",s_Mat1.getMatrixR1C1());
	textprintf(buffer,font,150,300,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR1C2());
	textprintf(buffer,font,200,300,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR1C3());
	textprintf(buffer,font,250,300,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR1C4());
	textprintf(buffer,font,110,310,makecol(255,255,255),"%3.1f,",s_Mat1.getMatrixR2C1());
	textprintf(buffer,font,150,310,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR2C2());
	textprintf(buffer,font,200,310,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR2C3());
	textprintf(buffer,font,250,310,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR2C4());
	textprintf(buffer,font,110,320,makecol(255,255,255),"%3.1f,",s_Mat1.getMatrixR3C1());
	textprintf(buffer,font,150,320,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR3C2());
	textprintf(buffer,font,200,320,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR3C3());
	textprintf(buffer,font,250,320,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR3C4());
	textprintf(buffer,font,110,330,makecol(255,255,255),"%3.1f,",s_Mat1.getMatrixR4C1());
	textprintf(buffer,font,150,330,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR4C2());
	textprintf(buffer,font,200,330,makecol(255,255,255)," %3.1f,",s_Mat1.getMatrixR4C3());
	textprintf(buffer,font,250,330,makecol(255,255,255)," %3.1f",s_Mat1.getMatrixR4C4());

	textout_right(buffer,font, "Mat2:",430,300,makecol(255,255,255));
	textprintf(buffer,font,450,300,makecol(255,255,255),"%3.1f,",s_Mat2.getMatrixR1C1());
	textprintf(buffer,font,490,300,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR1C2());
	textprintf(buffer,font,540,300,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR1C3());
	textprintf(buffer,font,590,300,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR1C4());
	textprintf(buffer,font,450,310,makecol(255,255,255),"%3.1f,",s_Mat2.getMatrixR2C1());
	textprintf(buffer,font,490,310,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR2C2());
	textprintf(buffer,font,540,310,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR2C3());
	textprintf(buffer,font,590,310,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR2C4());
	textprintf(buffer,font,450,320,makecol(255,255,255),"%3.1f,",s_Mat2.getMatrixR3C1());
	textprintf(buffer,font,490,320,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR3C2());
	textprintf(buffer,font,540,320,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR3C3());
	textprintf(buffer,font,590,320,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR3C4());
	textprintf(buffer,font,450,330,makecol(255,255,255),"%3.1f,",s_Mat2.getMatrixR4C1());
	textprintf(buffer,font,490,330,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR4C2());
	textprintf(buffer,font,540,330,makecol(255,255,255)," %3.1f,",s_Mat2.getMatrixR4C3());
	textprintf(buffer,font,590,330,makecol(255,255,255)," %3.1f",s_Mat2.getMatrixR4C4());

	textout_right(buffer,font, "Mat1 * 3.5:",100,350,makecol(255,255,255));
	textprintf(buffer,font,110,350,makecol(255,255,255),"%3.1f,",s_MatScalMultiplication.getMatrixR1C1());
	textprintf(buffer,font,150,350,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR1C2());
	textprintf(buffer,font,200,350,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR1C3());
	textprintf(buffer,font,250,350,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR1C4());
	textprintf(buffer,font,110,360,makecol(255,255,255),"%3.1f,",s_MatScalMultiplication.getMatrixR2C1());
	textprintf(buffer,font,150,360,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR2C2());
	textprintf(buffer,font,200,360,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR2C3());
	textprintf(buffer,font,250,360,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR2C4());
	textprintf(buffer,font,110,370,makecol(255,255,255),"%3.1f,",s_MatScalMultiplication.getMatrixR3C1());
	textprintf(buffer,font,150,370,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR3C2());
	textprintf(buffer,font,200,370,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR3C3());
	textprintf(buffer,font,250,370,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR3C4());
	textprintf(buffer,font,110,380,makecol(255,255,255),"%3.1f,",s_MatScalMultiplication.getMatrixR4C1());
	textprintf(buffer,font,150,380,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR4C2());
	textprintf(buffer,font,200,380,makecol(255,255,255)," %3.1f,",s_MatScalMultiplication.getMatrixR4C3());
	textprintf(buffer,font,250,380,makecol(255,255,255)," %3.1f",s_MatScalMultiplication.getMatrixR4C4());

	textout_right(buffer,font, "Mat1 / 3.5:",430,350,makecol(255,255,255));
	textprintf(buffer,font,450,350,makecol(255,255,255),"%3.1f,",s_MatScalDivision.getMatrixR1C1());
	textprintf(buffer,font,490,350,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR1C2());
	textprintf(buffer,font,540,350,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR1C3());
	textprintf(buffer,font,590,350,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR1C4());
	textprintf(buffer,font,450,360,makecol(255,255,255),"%3.1f,",s_MatScalDivision.getMatrixR2C1());
	textprintf(buffer,font,490,360,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR2C2());
	textprintf(buffer,font,540,360,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR2C3());
	textprintf(buffer,font,590,360,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR2C4());
	textprintf(buffer,font,450,370,makecol(255,255,255),"%3.1f,",s_MatScalDivision.getMatrixR3C1());
	textprintf(buffer,font,490,370,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR3C2());
	textprintf(buffer,font,540,370,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR3C3());
	textprintf(buffer,font,590,370,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR3C4());
	textprintf(buffer,font,450,380,makecol(255,255,255),"%3.1f,",s_MatScalDivision.getMatrixR4C1());
	textprintf(buffer,font,490,380,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR4C2());
	textprintf(buffer,font,540,380,makecol(255,255,255)," %3.1f,",s_MatScalDivision.getMatrixR4C3());
	textprintf(buffer,font,590,380,makecol(255,255,255)," %3.1f",s_MatScalDivision.getMatrixR4C4());

	textout_right(buffer,font, "Mat1 * Vec1:",180,400,makecol(255,255,255));
	textprintf(buffer,font,200,400,makecol(255,255,255),"X = %4.2f",s_MatVecMultiplication.getA());
	textprintf(buffer,font,200,410,makecol(255,255,255),"Y = %4.2f",s_MatVecMultiplication.getB());
	textprintf(buffer,font,200,420,makecol(255,255,255),"Z = %4.2f",s_MatVecMultiplication.getC());
	textprintf(buffer,font,200,430,makecol(255,255,255),"W = %4.2f",s_MatVecMultiplication.getW());

	textout_right(buffer,font, "Mat1 + Mat2:",430,400,makecol(255,255,255));
	textprintf(buffer,font,450,400,makecol(255,255,255),"%3.1f,",s_MatMatAddition.getMatrixR1C1());
	textprintf(buffer,font,490,400,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR1C2());
	textprintf(buffer,font,540,400,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR1C3());
	textprintf(buffer,font,590,400,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR1C4());
	textprintf(buffer,font,450,410,makecol(255,255,255),"%3.1f,",s_MatMatAddition.getMatrixR2C1());
	textprintf(buffer,font,490,410,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR2C2());
	textprintf(buffer,font,540,410,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR2C3());
	textprintf(buffer,font,590,410,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR2C4());
	textprintf(buffer,font,450,420,makecol(255,255,255),"%3.1f,",s_MatMatAddition.getMatrixR3C1());
	textprintf(buffer,font,490,420,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR3C2());
	textprintf(buffer,font,540,420,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR3C3());
	textprintf(buffer,font,590,420,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR3C4());
	textprintf(buffer,font,450,430,makecol(255,255,255),"%3.1f,",s_MatMatAddition.getMatrixR4C1());
	textprintf(buffer,font,490,430,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR4C2());
	textprintf(buffer,font,540,430,makecol(255,255,255)," %3.1f,",s_MatMatAddition.getMatrixR4C3());
	textprintf(buffer,font,590,430,makecol(255,255,255)," %3.1f",s_MatMatAddition.getMatrixR4C4());

	textout_right(buffer,font, "Mat1 - Mat2:",100,450,makecol(255,255,255));
	textprintf(buffer,font,110,450,makecol(255,255,255),"%3.1f,",s_MatMatSubtraction.getMatrixR1C1());
	textprintf(buffer,font,150,450,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR1C2());
	textprintf(buffer,font,200,450,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR1C3());
	textprintf(buffer,font,250,450,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR1C4());
	textprintf(buffer,font,110,460,makecol(255,255,255),"%3.1f,",s_MatMatSubtraction.getMatrixR2C1());
	textprintf(buffer,font,150,460,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR2C2());
	textprintf(buffer,font,200,460,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR2C3());
	textprintf(buffer,font,250,460,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR2C4());
	textprintf(buffer,font,110,470,makecol(255,255,255),"%3.1f,",s_MatMatSubtraction.getMatrixR3C1());
	textprintf(buffer,font,150,470,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR3C2());
	textprintf(buffer,font,200,470,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR3C3());
	textprintf(buffer,font,250,470,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR3C4());
	textprintf(buffer,font,110,480,makecol(255,255,255),"%3.1f,",s_MatMatSubtraction.getMatrixR4C1());
	textprintf(buffer,font,150,480,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR4C2());
	textprintf(buffer,font,200,480,makecol(255,255,255)," %3.1f,",s_MatMatSubtraction.getMatrixR4C3());
	textprintf(buffer,font,250,480,makecol(255,255,255)," %3.1f",s_MatMatSubtraction.getMatrixR4C4());

	textout_right(buffer,font, "Mat1 * Mat2:",430,450,makecol(255,255,255));
	textprintf_ex(buffer,font,450,450,makecol(255,255,255),-1,"%3.1f,",s_MatMatMultiplication.getMatrixR1C1());
	textprintf_ex(buffer,font,490,450,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR1C2());
	textprintf_ex(buffer,font,540,450,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR1C3());
	textprintf_ex(buffer,font,590,450,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR1C4());
	textprintf_ex(buffer,font,450,460,makecol(255,255,255),-1,"%3.1f,",s_MatMatMultiplication.getMatrixR2C1());
	textprintf_ex(buffer,font,490,460,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR2C2());
	textprintf_ex(buffer,font,540,460,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR2C3());
	textprintf_ex(buffer,font,590,460,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR2C4());
	textprintf_ex(buffer,font,450,470,makecol(255,255,255),-1,"%3.1f,",s_MatMatMultiplication.getMatrixR3C1());
	textprintf_ex(buffer,font,490,470,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR3C2());
	textprintf_ex(buffer,font,540,470,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR3C3());
	textprintf_ex(buffer,font,590,470,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR3C4());
	textprintf_ex(buffer,font,450,480,makecol(255,255,255),-1,"%3.1f,",s_MatMatMultiplication.getMatrixR4C1());
	textprintf_ex(buffer,font,490,480,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR4C2());
	textprintf_ex(buffer,font,540,480,makecol(255,255,255),-1," %3.1f,",s_MatMatMultiplication.getMatrixR4C3());
	textprintf_ex(buffer,font,590,480,makecol(255,255,255),-1," %3.1f",s_MatMatMultiplication.getMatrixR4C4());

	textout_centre(buffer,font,"Values for Vec1, Vec2, Mat1, and Mat2 are random",SCREEN_W/2,630,makecol(255,255,255));
	textout_centre(buffer,font,"return to menu and come back to this screen to randomize",SCREEN_W/2,640,makecol(255,255,255));

	blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H); //copy the buffer to the screen

	while(!key[KEY_ESC]){} //wait for the user to exit the page

	destroy_bitmap(buffer); //free the memory used by the buffer
}
