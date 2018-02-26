using namespace std;
#include <iostream>
#include <string>


class Erreur{
public:
  Erreur(int code = 0, string message = "Erreur ! ")
  :code(code), message(message)
  {}
  int get_code(){return code;};
  string get_message(){return message;};
  int code;
  string message;
};


ostream& operator<<(ostream& sortie, Erreur faute){                              // Facon d'afficher des complexes de maniere simple, remplace print
  sortie << "Erreur code " << faute.get_code() << " : " << faute.get_message();
  return sortie;
}




void test_div(int const& n){
  if (n == 0){
    Erreur div_par_0(1, "Division par 0 ! ");
    throw div_par_0;
  }else{
    cout << "La division vaut : 1/" << n << endl;
  }
}





int main(){



  try{
    int n;
    cout << "On test 1/n" << endl << "Entrez n : "; cin >> n;
    cout << "On effectue la division ... " << endl;
    test_div(n);
    cout << "La division a ete effectuee" << endl;
  }catch(Erreur erreur){
    cout << erreur << endl;
  }

  return 0;
}
