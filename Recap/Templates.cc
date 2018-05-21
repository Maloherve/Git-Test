#include <iostream>
#include <string>

using namespace std;


// Template de fonctions
// Cette procedure est utile pour tout operation qui peut etre faite sur un grand nombre de Types (comprends les classes)
// Cette ecriture ne prends aucune place mais decrit une multitude de fonctions pouvant etre créées.
template<typename Type>
void echange(Type& i, Type& j){                                                 // Cette fonction marchera donc pour tout type ayant le constructeur de copie Type(Type const&) et l'operateur de copie =.
  int temp(i);
  i = j;
  j = temp;
}

// Template de classes = Modeles de classe
// Ici on fait une classe qui represente juste une paire de 2 types differents.
template<typename Type1, typename Type2 = int>
class Paire{
  public:
  Paire(Type1 const& un, Type2 const& deux);

  Type1 get_premier() const {return premier;}
  Type2 get_second() const {return second;}
  void set_premier(Type1 const& un){premier = un;}
  void set_second(Type2 const& deux){second = deux;}


  private:
    Type1 premier;
    Type2 second;
};

template<typename Type1, typename Type2>
Paire<Type1, Type2>::Paire(Type1 const& un, Type2 const& deux)                  // Il est imperatif de préciser les types
:premier(un), second(deux)
{}

template<typename Type1, typename Type2>
ostream& operator<<(ostream& sortie, Paire<Type1, Type2> const& paire){
  sortie << "Premier = " << paire.get_premier() << endl
         << "Second = "  << paire.get_second()  << endl;
  return sortie;
}




// Surcharge de Modeles

template<typename Type>
void affiche(Type const& i){
  cout << "J'affiche : " << i << endl;
}

template<typename Type>
void affiche(Type* const i){
  cout << "J'affiche : " << *i << endl;
}

// Specialisation de fonction

template<> void affiche<int>(int* const i){
  cout << "J'affiche le contenu d'un entier : " << *i << endl;
}

// Specialisation de classe

template<> class Paire<string, int>{
public:
  Paire(string const& un, int const& deux);

  string get_premier() const {return premier;}
  int get_second() const {return second;}
  void set_premier(string const& un){premier = un;}
  void set_second(int const& deux){second = deux;}

  // une methode de plus
  void add(int const& i){second += i;}

private:
  string premier;
  int second;

};

Paire<string, int>::Paire(string const& un, int const& deux)                  // Il est imperatif de préciser les types
:premier(un), second(deux)
{}




template <int N, int M>
class IntRange
{
public:
int low() const { return min(N,M); }
int high() const { return max(N,M); }
bool contains(int x) const {
return (x >= low()) and (x < high());
}
};







int main(){
  // ------Instanciation-------
  // Fonction echange
  double i(1);
  double j(2);
  cout << "i = " << i << endl
       << "j = " << j << endl;

  echange<double>(i,j);

  cout << "i = " << i << endl
  << "j = " << j << endl;


  // Class Paire

  Paire<double> paire(1,2);                                                     // 1 est considéré comme un double, 2 comme un int (valeur par defaut)
  cout << paire << endl;

  // Surcharge affiche

  double nb(5);
  double* p_nb(&nb);

  affiche(nb);
  affiche(p_nb);

  // Specialisation

  int nb2(10);
  int* p_nb2(&nb2);

  affiche(nb2);
  affiche(p_nb2);



  IntRange<1,5> ran;
  cout << "Min = " << ran.low() << endl
       << "Max = " << ran.high() << endl
       << "Constains 3 : " << ran.contains() << endl;
       ;


  return 0;
}
