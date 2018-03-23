#include <string>


// Un objet a caractérisé par un element : cet element est il un attribut, ou une methode  (= peut il etre calculé a base des attributs ?)

// Toujours mettre en private, et ensuite mettre sur public si necessaire

// Eviter les const methode(); pour les types de base

// Hydre combat Dragon peut s'ecrire combat(Dragon& , Hydre&), ou bien encore mieux combat(Creature&, Creature&)

class Rectangle{
public:
  Rectangle(double const& largeur, double const& hauteur)
  :l(largeur), h(hauteur)
  {}

private:
  double l;
  double h;






};


class RectangleColore : public Rectangle{                                       // ou protected ou private
  RectangleColore(double const& largeur, double const& hauteur, string )











};


int main(){






  return 0;
}
