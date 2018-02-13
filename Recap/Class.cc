using namespace std;
#include <iostream>
#include <string>


class Rectangle{
public:
  // Constructeur 1                                                             Appelé par défaut,initialise les attribut
  Rectangle(double h, double l)                                                 //Meme nom que la class, invoqué automatiquement a la création. Il peut y en avoir plusieurs pour une seule classe
  :hauteur(h), largeur(l)                                                       //Meme chose que hauteur = h; largeur = l;
  {}
  //Constructeur par défaut                                                     //Si aucune valeur n'est donnée lors de l'initialisation, alors ce constructeur peut etre appelé
  Rectangle()
  :hauteur(1.0), largeur(4.0)
  {}                                                                            //Des la programmation d'un constructeur, le constructeur par defaut par defaut est désactivé
  //Rectangle() = default;                                                      //Réactive le constructeur par defaut par defaut (meme si inutile ici)
  //Rectangle() = delete;                                                       //Supprime le constructeur par defaut par defaut
  // Rectangle(Rectangle const&) = delete;                                      //Supprime le constructeur de copie par defaut, la classe n'est donc pas copiable

  // Prototypes de methode
  double surface() const;

  double get_hauteur() const{return hauteur;};                                  //Accesseurs
  double get_largeur() const{return largeur;};
  void set_hauteur(double h){hauteur = h;};                                     //Manipulateurs
  void set_largeur(double largeur){this->largeur = largeur;};                   //A éviter : Cas Particulier : on differentie les 2 "largeur" en indiquant this-> pour l'attribut
private:
  // Attributs   // Important qu'ils soient privés
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



class RectanglePointeur{
public:
  RectanglePointeur()
  :hauteur(new double(2.0)), largeur(new double(4.0))
  {}
  //Destructeur                                                                 // Appelé en fin de vie, il s'occupe de fermer/detruire les ressources allouées
  ~RectanglePointeur()
  {
    delete hauteur;
    delete largeur;
  }

private:
  double* hauteur;
  double* largeur;
};









int main(){

  Rectangle rect1;                                                              // Initialise avec constructeur par défaut
  Rectangle rect2(3.0,4.0);                                                     // Initialise avec constructeur 1
  Rectangle rect3(rect2);                                                       // Initialisation par constructeur de copie
  cout << "Hauteur = " << rect1.get_hauteur() << endl << "Largeur = " << rect1.get_largeur() << endl << "Surface = "<< rect1.surface() << endl;
  cout << "Hauteur = " << rect2.get_hauteur() << endl << "Largeur = " << rect2.get_largeur() << endl << "Surface = "<< rect2.surface() << endl;
  cout << "Hauteur = " << rect3.get_hauteur() << endl << "Largeur = " << rect3.get_largeur() << endl << "Surface = "<< rect3.surface() << endl;
   {}
  return 0;
}
