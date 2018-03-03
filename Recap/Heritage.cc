using namespace std;
#include <iostream>
#include <string>

// L'heritage permet de regrouper au maximum les parties communes (attributs et methodes) dans des classes, appelées super classes
// L'heritage represente la relation "est un"    ex : le sorcier est un personnage

// Personnage p;
// Guerrier g;
// p = g             possible



// Copie Profonde : Sers quand une classe utilise des pointeurs. Si on initialise une instance en copiant une autre, on va copier la VALEURE pointée par l'attribut de la classe et non pas le Pointeur, le 'fl" en lui meme .'





class Personnage{
public:
  Personnage(int pv = 100 , int energie = 50, string name = "Default pnj")
  :pv(pv), energie(energie), name(name)
  {}

  int get_pv() const{return pv;};
  int get_energie() const{return energie;};
  string get_name() const{return name;};

  void rencontrer(Personnage& autre);
  void print(){cout << "Statistiques de " << name << " : " << endl << "Points de vie : " << pv << endl << "Energie : " << energie << endl;}

protected:                                                                      //permet l'acces aux attributs par la descendance de cette super classe
  int pv;
  int energie;
  string name;
};

ostream& operator<<(ostream& sortie, Personnage const& p){                              // Facon d'afficher des complexes de maniere simple, remplace print
sortie << "Statistiques de " << p.get_name() << " : " << endl << "Points de vie : " << p.get_pv() << endl << "Energie : " << p.get_energie() << endl;
return sortie;}

void Personnage::rencontrer(Personnage& autre){
  cout << "Bonjour " << autre.get_name() << " !! Je m'appel " << name << "." << endl;

}







class Guerrier : public Personnage{
public:
  Guerrier(int pv = 100 , int energie = 50, string name = "Default pnj",string arme = "Poing")
  :Personnage(pv, energie, name), arme(arme)
  {}

  void print(){
    Personnage::print();
    cout << "Moi , Je suis un guerrier et je cogne avec : " << arme << endl;}
  void rencontrer(Personnage& autre){                                                           // Masquage : On masque la focion rencontrer définie pour un personnage de base (définie dans la super classe ) par une nouvelle fonction adaptée a la sous-classe
    Personnage::rencontrer(autre);                                                              // Il est cependant possible d'acceder la methode pas defaut

    cout << "GRRRRRR je suis un guerrier j'aime pas me presenter !!!!" << endl;


  }
private:
  string arme;
};


class Mage : public Personnage{
public:
  Mage(int pv = 100, int energie = 100, string name = "Mage par default", string baton = "Brindille")
  :Personnage(pv, energie, name), baton(baton)
  {}
    void print(){
      Personnage::print();
      cout << "Je suis un noble mage qui lance mes sors avec ma " << baton << endl;}

private:
  string baton;
};








int main(){
 Personnage pnj;
 Mage hero(2000, 1500, "Natsu", "Baton Magique de la Mort");
 Guerrier guarde(200, 50, "Robert le Guarde", "Epee");
 Guerrier guarde2(200, 50, "Bobby le Guarde");
 Mage default_mage;
 hero.print();
 cout << endl;
 guarde.print();
 cout << endl;
 guarde2.print();
 cout << endl;
 default_mage.print();
 cout << endl;




 // guarde.rencontrer(hero);
 // hero.rencontrer(guarde);

  return 0;
}
