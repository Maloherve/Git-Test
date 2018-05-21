using namespace std;

#include <memory>
#include <iostream>
#include <vector>
// Pointeur Intelligent : Pas besoin de delete (il s'en occupent )
// unique_ptr : verifie qu'a tout moment, un seul pointeur pointe vers une instance. Doivent pointer vers des instances dynamiquement allouée.

// delete pointeur : supprime la valeur pointée pour un pointeur ALLOUE DYNAMIQUEMENT









int main(){



  int element(25);

  unique_ptr<int> p_element(new int(element));


  vector<int*> liste;


  int a(71);
  int* p_a(&a);
  liste.push_back(p_a);



  cout << *liste[0] << endl;
  cout << *p_a << endl;
  cout << a << endl << endl;

  p_a = nullptr;
  p_a.clear();

  cout << *liste[0] << endl;
  cout << *p_a << endl;
  cout << a << endl << endl;




  return 0;
}
