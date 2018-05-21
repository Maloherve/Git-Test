#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;












int main(){
  vector<unique_ptr<int>> liste;
  vector<int> liste2 = {1,2,3,4,5};


  int const a(1);
  int* p_a(&a);
  cout << *p_a << endl;


  //
  // int b(2);
  // unique_ptr<int> p_b(new int(b));
  // liste.push_back(move(p_b));
  //
  // int c(3);
  // unique_ptr<int> p_c(new int(c));
  // liste.push_back(move(p_c));

  // int d(4);
  // unique_ptr<int> p_d(new int(d));
  // liste.push_back(move(p_d));

  // int d(4);
  // int* p_dd = new int(d);
  // unique_ptr<int> p_d(p_dd);
  // liste.push_back(move(p_d));



  for (size_t i(0); i < liste.size(); i++){
    cout << *liste[i] << endl;
  }

  // for (size_t i(2); i < liste.size()-1; i++){
  //   liste[i].swap(liste[i+1]);
  // }
  // cout << "-----------------------------------" << endl;
  // liste.pop_back();
  //
  // for (size_t i(0); i < liste.size(); i++){
  //   cout << *liste[i] << endl;
  // }





  return 0;
}
