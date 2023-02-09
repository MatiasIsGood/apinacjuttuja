#include "pch.h"

bool SpaceBarPressed = false;
bool IsPressedTooFast = false;

//sehän olis muistiosotteet
int* ammo = (int*)0x0E0DB40;
int* clip = (int*)0x0E0DD40;
int* health = (int*)0x0C8155C;
int* gravity = (int*)0x0E0DA28; //joku gravity?


void GlideJump() {
	std::cout << "sehän olis spacebar" << '\n';
	Sleep(300);
	*gravity = 100;
	Sleep(200);
	*gravity = 200;
	Sleep(200);
	*gravity = 300;
	Sleep(200);
	*gravity = 400;
	Sleep(200);
	*gravity = 500;
	Sleep(200);
	*gravity = 600;
	Sleep(200);
	*gravity = 700;
	Sleep(200);
	*gravity = 800;
}


void OnKeyPressed(int mode, bool negative, int button) {
	float* z = (float*)0x0E0DA1C;		//ylös
	float* y = (float*)(0x0E0DA1C - 4); //oikeelle
	float* x = (float*)(0x0E0DA1C - 8); //eteenpäi

	if (KeyPressed(button) == false)
		return;

	if (mode == 1) { //muokkaa x
		if (negative == false) {
			*x += 100;
			std::cout << "moved x " << *x << '\n';
		}
		else {
			*x -= 100;
			std::cout << "moved -x " << *x << '\n';
		}
	}

	else if (mode == 2) { //muokkaa y
		if (negative == false) {
			*y += 100;
			std::cout << "moved y " << *y << '\n';
		}
		else {
			*y -= 100;
			std::cout << "moved -y " << *y << '\n';
		}
	}

	else if (mode == 3) { //muokkaa z
		if (negative == false) {
			*z += 100;
			std::cout << "moved z " << *z << '\n';
		}
		else {
			*z -= 100;
			std::cout << "moved -z " << *z << '\n';
		}
	}

	else if (mode == 68) {
		std::cout << "enne: " << *gravity << '\n';
		*gravity = 1;
		std::cout << "jalkee: " << *gravity << '\n';
	}

	else if (mode == 69) {
		GlideJump();
	}
}


void __main() {	

	// tp move
	OnKeyPressed(1, true, VK_NUMPAD8);
	OnKeyPressed(1, false, VK_NUMPAD2);
	OnKeyPressed(2, true, VK_LEFT);
	OnKeyPressed(2, false, VK_RIGHT);
	OnKeyPressed(3, true, VK_DOWN);
	OnKeyPressed(3, false, VK_UP);

	//gravity no fall damage
	OnKeyPressed(68, true, VK_INSERT);

	//random glide movement
	OnKeyPressed(69, true, VK_SPACE);

	Sleep(3);
}