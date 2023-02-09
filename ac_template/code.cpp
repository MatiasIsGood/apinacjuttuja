#include "pch.h"

struct vector3
{
	float x;
	float y;
	float z;
};

//todo teleport eteenpäin

#define PITCH 0 //X
#define YAW 1 //Y
#define ROLL 2 //Z

bool ChangeGravity = false;


void guessNumber(int guess) {
    
	std::cout << guess  <<" : ";
	if (guess == 555) {
		std::cout << "Correct. You guessed it!\n";
	}
	else if (guess < 555) {
		std::cout << "Your guess is too low.\n";
	}
	else if (guess > 555) {
		std::cout << "Your guess is too high.\n";
	}

}

void __main() {	

	//sehän olis muistiosotteet
	int* ammo = (int*)0x0E0DB40;
	int* clip = (int*)0x0E0DD40;
	int* health = (int*)0x0C8155C;
	float* gravity = (float*)0x01340234; //joku gravity?

	float* z = (float*)0x0E0DA1C;		//ylös
	float* y = (float*)(0x0E0DA1C - 4); //oikeelle
	float* x = (float*)(0x0E0DA1C - 8); //eteenpäi

	float* w_pitch = (float*)(0x086872C-4); 

	float* r_pitch = (float*)(0x074D60C-4);


	if (KeyPressed(VK_INSERT)) {
		
		    guessNumber(500);
			guessNumber(600);
			guessNumber(555);

	}


	Sleep(3);
}