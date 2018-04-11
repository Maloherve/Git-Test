#include <iostream>
using namespace std;

//Le polymotrphisme est le fait que les instances d'une sous classe, lequelles sont substituables aux instances des classes parentes,
//gardent leurs proppriete propres.

// resolution statique des liens : Le fait qu'une instance d'une sous classe, lorsque passée comme argument et identifié comme sa classe mere, fasse appele au methodes de la classe mere. Solution : Resolution dynamique des liens

// Resolution dynamique des lien : 2 ingredients essentiel : mot clé "virtual" et passage par reference des argument de la methode.


// Mot Clés :
// Override : à utilisier lors d'une substitution d'une fonction, le compilateur va verifier que la fonction a bel et bien ete definie auparavant. Ne marche que pour les virtuals
// Final : Empeche la substitution de cette fonction dans les sous classes.


// Methodes virtuelles Pures (= Abstraites) :
// Une methode virtuelle d'une classe mere est definie comme "pure" pour obliger les classes filles a posseder une substitution de cette methode.
// On ajoute =0 a la fin du prototype : virtual void afficher() const = 0;
// /!\ On ne peut pas creer d'instance d'une classe contenant une methode virtuelle pure 

class Personnage{
public:
  Personnage(int pv = 100 , int energie = 50, string name = "Default pnj")
  :pv(pv), energie(energie), name(name)
  {}

  int get_pv() const{return pv;};
  int get_energie() const{return energie;};
  string get_name() const{return name;};

  virtual void rencontrer(Personnage& p) const{
    cout << "Rencontrer de Personnage" << endl;}
  void print(){cout << "Statistiques de " << name << " : " << endl << "Points de vie : " << pv << endl << "Energie : " << energie << endl;}

protected:                                                                      //permet l'acces aux attributs par la descendance de cette super classe
  int pv;
  int energie;
  string name;
};



ostream& operator<<(ostream& sortie, Personnage const& p){                              // Facon d'afficher des complexes de maniere simple, remplace print
sortie << "Statistiques de " << p.get_name() << " : " << endl << "Points de vie : " << p.get_pv() << endl << "Energie : " << p.get_energie() << endl;
return sortie;}

// void Personnage::rencontrer(Personnage const& autre){
//   // cout << "Bonjour " << autre.get_name() << " !! Je m'appel " << name << "." << endl;
//   cout << "Rencontrer de Personnage"  << endl;
// }







class Guerrier : public Personnage{
public:
  Guerrier(int pv = 100 , int energie = 50, string name = "Default pnj",string arme = "Poing")
  :Personnage(pv, energie, name), arme(arme)
  {}

  void print(){
    Personnage::print();
    cout << "Moi , Je suis un guerrier et je cogne avec : " << arme << endl;
  }


  void rencontrer(Personnage& p) const override{
    cout << "Rencontrer de Guerrier" << endl;}

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

    void rencontrer(Personnage& p) const override{
      cout << "Rencontrer de Mage" << endl;}
private:
  string baton;
};

void faire_rencontrer(Personnage& un, Personnage& autre){
 cout << un.get_name() << " rencontre " << autre.get_name() << " : " <<  endl;
 un.rencontrer(autre);
 autre.rencontrer(un);

}


int main(){

  Personnage pnj;
  Mage hero(2000, 1500, "Natsu", "Bite");                                       // Definition methode 2
  Guerrier garde(200, 50, "Robert le garde", "Epee");
  // Personnage gardebis(garde);                                                 //definition methode 1
  // Mage default_mage;
  // hero.print();
  // cout << endl;
  // garde.print();
  // cout << endl;
  // gardebis.print();

  faire_rencontrer(garde, hero);
  // garde.rencontrer(hero);
  // gardebis.rencontrer(hero);







  return 0;
}
