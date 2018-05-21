#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;






void f(unique_ptr<int> const& ptr){
  cout << "hello" << endl;
}





int main(){
  vector<unique_ptr<int>> liste1;
  vector<unique_ptr<int>> liste2;

  for (int i(0); i < 6; i++){
    // unique_ptr<int> p_1(new int(1));
    // unique_ptr<int> p_2(new int(2));
    // liste1.push_back(move(p_1));
    // liste2.push_back(move(p_2));
    // liste1.push_back(unique_ptr<int>(1));
  }


  cout << "Liste 1 : ";
  for (size_t i(0); i < liste1.size(); i++){
    cout << *liste1[i] << " ";
  }
  cout << endl;
  cout << "Liste 2 : ";
  for (size_t i(0); i < liste2.size(); i++){
    cout << *liste2[i] << " ";
  }
  cout << endl;












  return 0;
}
