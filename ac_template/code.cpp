#include "pch.h"


void __main() {

	//sehän olis muistiosotteet
	int* ammo = (int*)0x0E0DB40;
	int* clip = (int*)0x0E0DD40;
	int* health = (int*)0x0C8155C;
	float* gravity = (float*)0x01340234; //joku gravity?

	float* z = (float*)0x0E0DA1C;		//ylös
	float* y = (float*)(0x0E0DA1C - 4); //oikeelle
	float* x = (float*)(0x0E0DA1C - 8); //eteenpäi

	float* w_pitch = (float*)(0x086872C - 4);
	float* r_pitch = (float*)(0x074D60C - 4);

	float* read_yaw = (float*)0x0E0DAE0;

	bool* IsGrounded = (bool*)0x0815F08;



	Sleep(3);
}