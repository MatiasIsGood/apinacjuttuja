#include "pch.h"

//en voi olla sit koko aja paikalla
//asiakkaita  
//juu

bool ChangeGravity = false;

//täällekö
/*
works
mikä on console clear

öööö ssi vrm -45 ja -135
yes
system("cls");
*/
int apina(float read_apina) {
	system("cls");

	std::cout << "nyt testaan anglea: " << read_apina << '\n'; //pinkki
	if (read_apina >= 45 && read_apina < 135) { 
		std::cout << "sehan on 45 ja 135 valilla kai??? " << '\n';
		return 1;
	}
	else if (read_apina <= 45 && read_apina > -45) { //oranssi
		std::cout << "sehan on 45 ja -45 valis kai??? " << '\n';
		return 2;
	}
	else if (read_apina <= -45 && read_apina > -135) { //sinine
		std::cout << "sehän on -45 ja -135 valis kai???" << '\n';
		return 3;
	}
	else if (read_apina >= 135 || read_apina < -135) { //vihree
		std::cout << "sehän on 135 ja -135 valis kai???" << '\n';
		return 4;
	}
	 
	std::cout << "ei ole alueella\n"; //voit vaa tehä näi for debugging
	return 0; //hyvä

	//tän koodin ei pitäs ikinä suorittaa, mut laita tänne joku return arvo mistä tiedät et tää kusi
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


	float* read_yaw = (float*)0x0E0DAE0;
	
	if (KeyPressed(VK_INSERT)) {
		int value = apina(*read_yaw); //anna vielä valuelle oikee datatyyppi

		std::cout << value << '\n'; //toimiiii
		//noni nyt 10 sijasta liiku tasan 0.125
		//ja sit juokse seinää vaste ja testaa tätä
		//jooo toimii jep oota sekka 
		//epic games
		//nyt tää broject on tehty

		if (value == 1) { //vasen
			*y += 0.125f; // huomio F lopussa <-- float 
		}
		else if (value == 2) { //ylös = x 
			*x += 0.125f;
		}
		else if (value == 3) { //oikee eli = -y
			*y -= 0.125f;
		}
		else if (value == 4) { // taakse eli = -x
			*x -= 0.125f;
		}

	}
	
	
	Sleep(3);
}