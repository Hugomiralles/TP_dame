
#include "Plateau.h"

using namespace std;

Plateau::Plateau(){
	//Remplissage du plateau
	for (int i=0; i<10; i++){
		for (int j=0; i<10; j++){
			if (i<4){
				if (j%2==0){
					tableau[i][j]=0;
				}
				else{
					tableau[i][j]=1; // 1=noir
				}
			}
			else if (i>=4 && i<6)
				tableau[i][j]=0;
			else{
				if (j%2==0){
					tableau[i][j]=0;
				}
				else{
					tableau[i][j]=2; // 2=blanc
				}				
			}
		}
	}
}

void Plateau::afficher (){
	cout << " ";
	for (int i=0; i<10; i++){
		cout<<i+1<<"||";
	}
	cout<<endl;
	for (int i=0; i<10; i++){
		 cout<<i+1;
		 for (int j=0; j<10; j++){
			 if (tableau[i][j]==1){
				cout<<"n||";
			 }
			 else if (tableau[i][j]==2){
				cout<<"b||";
			 }
			 else
				 cout<<" ||";
		 }
		 cout<<endl;
	}
}

void Plateau::jouer(){
	afficher();
	cout << "Joueur 1 (pions noir):" << endl;
	cout << "Quel pion?" << endl;
	bool faux = true;
	int x,y,xn,yn;
	while (faux){
		cin >> x;
		cin >> y;
		if (x > 9 || y>9 || tableau[x][y] != 1)
			cout<<"Mauvais choix"<<endl;
		else 
			faux = false;
	}
	faux = true;

	cout << "Quelle case?" << endl;
	while (faux){
		cin >> xn;
		cin >> yn;
		if (xn > 9 || yn>9 || tableau[xn][yn] == 1 || !(x-1<=xn<=x+1) || !(y-1<=yn<=y+1))
			cout<<"Mauvais choix"<<endl;
		else if (tableau[xn][yn] == 0){
			tableau[xn][yn] = 1;
			tableau[xn][yn] = 0;
			faux = false;
		}
		else {
			if (tableau[2*xn-x][2*yn-y] == 0){
				tableau[xn][yn] = 0;
				tableau[2*xn-x][2*yn-y] = 1;
				faux = false;
			}
			else 
				cout << "Mauvais choix"<<endl;
		}
	}

	afficher();
	cout << "Joueur 2 (pions blancs):" << endl;
	cout << "Quel pion?" << endl;
	bool faux = true;
	int x,y,xn,yn;
	while (faux){
		cin >> x;
		cin >> y;
		if (x > 9 || y>9 || tableau[x][y] != 2)
			cout<<"Mauvais choix"<<endl;
		else 
			faux = false;
	}
	faux = true;

	cout << "Quelle case?" << endl;
	while (faux){
		cin >> xn;
		cin >> yn;
		if (xn > 9 || yn>9 || tableau[xn][yn] == 2 || !(x-1<=xn<=x+1) || !(y-1<=yn<=y+1))
			cout<<"Mauvais choix"<<endl;
		else if (tableau[xn][yn] == 0){
			tableau[xn][yn] = 1;
			tableau[xn][yn] = 0;
			faux = false;
		}
		else {
			if (tableau[2*xn-x][2*yn-y] == 0){
				tableau[xn][yn] = 0;
				tableau[2*xn-x][2*yn-y] = 2;
				faux = false;
			}
			else 
				cout << "Mauvais choix"<<endl;
		}
	}

}


bool Plateau::terminer(){
	bool joueur1 = false;
	bool joueur2 = false;
	for (int i = 0; i<10; i++){
		for (int j = 0; j<10; j++){
			joueur1 = (tableau[i][j] == 1);
			joueur2 = (tableau[i][j] == 2);
		}
	}
	return (joueur1 && joueur2);
}


int Plateau::gagner(){
	int gagnant = 0;
	int i=0;
	int j=0;
	while (gagnant == 0){
		gagnant = tableau[i][j];
		i++;
		j++;
	}
	return gagnant;
}

