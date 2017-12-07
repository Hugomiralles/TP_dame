
#include <string>
#include <iostream>


using namespace std;

class Plateau {
private:
	int tableau[10][10];
	void afficher();
public:
	Plateau();
	void jouer();
	bool terminer();
	int gagner();
}