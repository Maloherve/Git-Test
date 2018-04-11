using namespace std;

#include <memory>
#include <iostream>
// Pointeur Intelligent : Pas besoin de delete (il s'en occupent )
// unique_ptr : verifie qu'a tout moment, un seul pointeur pointe vers une instance. Doivent pointer vers des instances dynamiquement allouée.











int main(){



  int element(25);

  // unique_ptr<int> p_element(new int(65));
  // cout << *p_element << endl;


  unique_ptr<int> p_element2(nullptr);
  // p_element2 = new int(56);

  int a(71);

  unique_ptr<int> p_a(&a);
  cout << *p_a << endl;
  cout << a << endl;

  *p_a += 9;
  cout << *p_a << endl;
  cout << a << endl;


  // unique_ptr<int> p_a(nullptr);
  // p_a = &a;
  // cout << "Test" << endl;
  // cout << *p_a << endl;
  // cout << a << endl;
  //
  // *p_a += 9;
  // cout << *p_a << endl;
  // cout << a << endl;


  // int* p_a(nullptr);
  // p_a = &a;
  // cout << *p_a << endl;
  // cout << a << endl;
  //
  // *p_a += 9;
  // cout << *p_a << endl;
  // cout << a << endl;

  return 0;
}
