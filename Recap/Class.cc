using namespace std;
#include <iostream>
#include <string>


class Rectangle{
public:
  // Constructeurs                                                              Appelé par défaut,initialise les attribut
  Rectangle(double h, double l)                                                 //Meme nom que la class, invoqué automatiquement a la création. Il peut y en avoir plusieurs pour une seule classe
  :hauteur(h), largeur(l)                                                       //Meme chose que hauteur = h; largeur = l;
  {}

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

class RectangleColore{
public:
  RectangleColore(double h, double l, string c)
    :rectangle(h,l), couleur(c)                                                 // type de constructeur. Initialise un rectangle sans en créer un séparé du rectangle coloré créé.
  {}   //Autres methodes

private:
  Rectangle rectangle;
  string couleur;
};


int main(){

  Rectangle rect2(3.0,4.0);                                                     // Initialise avec constructeur

  // cout << "Hauteur = " << rect1.get_hauteur() << endl << "Largeur = " << rect1.get_largeur() << endl << "Surface = "<< rect1.surface() << endl;
  cout << "Hauteur = " << rect2.get_hauteur() << endl << "Largeur = " << rect2.get_largeur() << endl << "Surface = "<< rect2.surface() << endl;
  return 0;
}
