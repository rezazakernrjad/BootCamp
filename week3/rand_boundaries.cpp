
/*
Scalable lower / upper bound finder. give a number to max_rando...

We want to generate 1024 random integers, then given a new random number; find two integers which are the
closest to the given number (smaller, and bigger) with less than twelve lookups.

*/
#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <chrono>
#include <thread>

#define max_rando 1024
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

#if 1
void test (int uper, int lower, set<int> s_, int urando)
{
    cout << "rand_given: " << urando << endl;
    cout << "reff: Lower Band: " << *(--s_.lower_bound(urando))<< " / lower_b: " << lower << endl;
    cout << "reff: Upper Band: " << *s_.upper_bound(urando)<< " / upper band: "<< uper << endl;
    if ((uper == *s_.upper_bound(urando))  && (lower == *(--s_.lower_bound(urando))))
    {cout << "PASSED..." << endl;}

}
#endif

#if 1
int main(){//int find_bound(int urando)
    set<int> rando;
    int lp{0};
    srand(time(NULL));
    for (int k = 0; k < max_rando; k++)
    {
        rando.insert(rand() % max_rando);
    }
    int ziz{0};
    ziz = rando.size();
    int arando[ziz];
    int uppr{0};
    int lwr{0};
    int i{0};
    for (set<int>::iterator it = rando.begin(); it != rando.end(); ++it)
    {
        arando[i++] = *it;
    }
    int divt{0};
    vector<int> divisor{};
    for (int i=2; i<max_rando && (ziz / i) > 1 ;i*=2){
      divisor.push_back(ziz / i);
    }
    int urando{0};
    cout << "Enter a number between 0 and 1024: ";
    cin >> urando;
    int d_1 = divisor[0];
    for (lp = 0; lp < divisor.size(); lp++){
      if (urando == *(arando + d_1)){
        cout << "at d_1: "<< d_1 << " / urando = " << *(arando + d_1) << endl;
        break; 
      }else if (urando < *(arando + d_1)){
        if (lp == divisor.size() -1){ 
          d_1 = d_1 - divisor[lp];}
        else {
          d_1 = d_1 - divisor[lp+1];}
      } else { 
        if (lp == divisor.size() -1){
           d_1 = d_1 + divisor[lp];}
        else {
          d_1 = d_1 + divisor[lp+1];}
      }
    }
    cout << "D_1: "<< d_1 << endl;
  if(urando > *(--rando.end()) || urando < *(rando.begin())){
    cout << "Entered number is out of range..." << endl;
    return 0;
  }else {
    if (urando == *(arando + d_1)){lp++;
      uppr = *(arando + d_1+1); lwr =  *(arando + d_1-1);
    } else if (urando == *(arando + d_1-1)){lp++;
      uppr = *(arando + d_1); lwr =  *(arando + d_1-2);
    } else if (urando == *(arando + d_1+1)){lp++;
      uppr = *(arando + d_1+2); lwr =  *(arando + d_1);
    } else if (urando == *(arando + d_1+2)){lp++;
      uppr = *(arando + d_1+3); lwr =  *(arando + d_1+1);
    } else if (urando == *(arando + d_1-2)){lp++;
      uppr = *(arando + d_1-1); lwr =  *(arando + d_1-3);
    } 
    else{
      if ((urando < *(arando + d_1))){ lp++;
        if (urando < *(arando + d_1-1)){ lp++;
          uppr = *(arando + d_1-1); lwr =  *(arando + d_1-2);
        }else {
          uppr = *(arando + d_1); lwr=*(arando + d_1-1);}
      } else if ((urando > *(arando + d_1+1))){ lp++;
        uppr = *(arando + d_1+2); lwr = *(arando + d_1);
      uppr = *(arando + d_1+1); *(arando + d_1);}
      
    }
      cout << "number of look ups: " << lp << endl;
      test(uppr, lwr, rando, urando);
      return 0;
  }
}
 
#endif

// int main (){
// int r{0}; 
// int ra[20]{0, -234, 246, 784, 341 ,333, 777, 813,12, 16,673,431,1,0,666,43,2,33,45};
// srand(time(NULL));
// for (int itt =0; itt < 20 ; itt++){
  
//   cout << "main sent random: " << ra[itt] << endl;
//   find_bound(ra[itt]);
// }
// return 0;
// }