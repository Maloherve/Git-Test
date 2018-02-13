using namespace std;
#include <iostream>

void print();

long compteur(0); // Mauvais de délarer comme ca mais bon pour l'instant on s'en contente

class Rectangle{
public:
  Rectangle(double h = 1.0, double l = 1.0)
  :hauteur(h), largeur(l)
  {++compteur;}
  ~Rectangle(){
    --compteur;
  }
private:
  double hauteur;
  double largeur;
};


void print(){cout << "Compteur = " << compteur << endl;}

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
