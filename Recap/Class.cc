using namespace std;
#include <iostream>




class Rectangle{

public:
  //Prototypes de methode
  double surface() const;

  double get_hauteur() const{return hauteur;};                                  //Accesseurs
  double get_largeur() const{return largeur;};
  void set_hauteur(double h){hauteur = h;};                                     //Manipulateurs
  void set_largeur(double largeur){this->largeur = largeur;};                   //A éviter : Cas Particulier : on differentie les 2 "largeur" en indiquant this-> pour l'attribut
private:
  // attributs   // Important qu'ils soient privés
  double hauteur;
  double largeur;

};

// Methodes
// On peut sortir (meilleurs lisibilité) les definitions des methodes des classes tout en y laissant un prototype
double Rectangle::surface() const{             //Pas besoin de passer les attributs d'une classe dans ses methodes // On utilise Rectangle:: pour indiquer la classe // const indique que c'est un "predicat", il ne modifie pas les attributs
  return hauteur*largeur;
}




int main(){
  Rectangle rect1;
  rect1.set_hauteur(3.0);
  rect1.set_largeur(4.0);

  cout << "Hauteur = " << rect1.get_hauteur() << endl << "Largeur = " << rect1.get_largeur() << endl << "Surface = "<< rect1.surface() << endl;

  return 0;
}
