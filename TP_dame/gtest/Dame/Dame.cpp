// Dame.cpp�: d�finit le point d'entr�e pour l'application console.
//
#include "Plateau.h"

using namespace std;

int main(){
	Plateau dame;
	while (dame.terminer()){
		dame.jouer;
	}
	cout << "Joueur gagnant:" << dame.gagner() << endl;
	return 0;
}
