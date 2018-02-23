using namespace std;
#include <iostream>
#include <string>

// La surchage d'operateurs permet d'etendre l'utilisation des operateurs usuels
// Exemple : Une classe Complexe qui contient une partie réelle et une partie complexe, la surchage d'operateur permet d'effectuer, sans erreur :
//  - z1 + z2
//  - cout << "z1 : " << z1 << ...
//  ...et bien plus....

// operateurs : arithmetique (+,-,*,/, ... ), logiques (and, or, not), de comparaison ( ==, >=, <=, ...) , d'increments (++) , ...

// Surcharge : meme nom, differents Attributs



class Complexe{
public:
  Complexe(double a = 0, double b = 0)
  :reel(a), complexe(b)
  {}

  double get_reel() const{return reel;};
  double get_complexe() const{return complexe;};

  void print(){cout << "Partie Reel : " << reel << " , Partie Immaginaire : " << complexe << endl;}
  Complexe operator+(Complexe const& z2);                                       // Prototype de la surcharge d'operateur interne // Un seul parametre
  Complexe operator+=(Complexe const& z2);
private:
  double reel;
  double complexe;

};


// Defintition de la surcharge d'operateurs interne

Complexe Complexe::operator+(Complexe const& z2){                               // Bien preciser Complexe::
  Complexe z3(reel + z2.get_reel(), complexe + z2.get_complexe());
  return z3;}
Complexe Complexe::operator+=(Complexe const& z2){
  reel += z2.get_reel();
  complexe += z2.get_complexe();
}

// Surcharge externe, a l'exterieur de la classe
Complexe operator*(Complexe const& z, double scalaire){
  Complexe z3(z.get_reel()*scalaire, z.get_complexe()*scalaire);
  return z3;}
Complexe operator*(double scalaire, Complexe const& z){                               // gere la commutativité
  return z*scalaire;}
ostream& operator<<(ostream& sortie, Complexe const& z){                              // Facon d'afficher des complexes de maniere simple, remplace print
  sortie << "Partie Reel : " << z.get_reel() << " , Partie Immaginaire : " << z.get_complexe();
  return sortie;
}




int main(){
  Complexe z1(1,2); Complexe z2(3,4); Complexe z3(z1.operator+(z2)); Complexe z4(5*z3);
  z1 += z2;
  cout << "z1 : ";
  z1.print();
  cout << "z2 : ";
  z2.print();
  cout << "z3 : " << z3 << endl;
  cout << "z4 : " << z4 << endl;


  cout << endl;
  return 0;
}
