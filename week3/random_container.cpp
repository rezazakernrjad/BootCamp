#include <stdlib.h>     /* srand, rand */
#include <iostream> 
#include <vector>
#include<set>
#include<unordered_map>
using namespace std;
int main ()
{
    // a set of integers 0-33
    set<int> s_;
    for (int i=0; i<34;i++){
        s_.insert(i);
    }
    srand (time(NULL));
    // a vector of 10000 random number between 0-33
    vector<int> v_;
    for (int i = 0; i < 9999; i++){
        v_.push_back(rand() % 34 );
    }
    //array of integeres all 0 a cnt for each figure is found in vector.
    int ar_cnt[34]{0};
    // unordered_map, maps s_ and ar_cnt.
    //each number of v_ will increase one element of ar_cnt sits in  index eg. if(v_[x]= 25) then ar_cnt[25]++
    //since s_ is a set of 0-33 it's members matches with ar_cnt's index
     unordered_map<int, int> rand_map{};
     for (int x=0; x<10000; x++){
         rand_map[*s_.find(v_[x])] = ar_cnt[v_[x]]++;
     }
     for (int r=0; r<34; r++){
         cout << r << " :  Repeated: " << rand_map[r] << " times" << endl;
     }
    return 0;
}