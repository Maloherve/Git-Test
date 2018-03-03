using namespace std;
#include <iostream>

void print();

// ici, on essaye de modifier Rectangle pour avoir une variable "globale" compteur, commune a tout le programme qui compte le nombre de rectangles ouvert
class Rectangle{
public:
  Rectangle(double h = 1.0, double l = 1.0)
  :hauteur(h), largeur(l)
  {++compteur;}
  ~Rectangle(){
    --compteur;
  }
  static int compteur;                                                          // Ici, static indique que la variable est commune a toutes les instances de la classe // Privé ou publique

private:
  double hauteur;
  double largeur;
};


int Rectangle::compteur(0);                                                     // On doit initialiser l'attribut en dehors de la classe


void print(){cout << "Compteur = " << Rectangle::compteur << endl;}             // Rectangle::compteur indique qu'on accede a l'attribut de classe compteur de la classe rectangle

int main(){
  print();
  if (true == true){
    Rectangle rect1;
    print();
    cout << "Destroying Rectangle." << endl;
  }
  print();
  return 0;
}
