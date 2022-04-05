
#include <iostream>
#include<string>

using namespace std;

void print_string(string* name, int x){
    for (int k=0; k< 4; k++){
        if (k == 2){
            name[k] = "modi fied";
        }
        cout << "entered name: " << name[k] << endl;
        cout << "entered digit: " << x << endl;
    }
    
}

int main(){
    string name[4];
    int x{0};
    for (int n = 0 ; n < 4; n++){
        cout << "enter name " << n<< ": ";
        getline(cin, name[n]);
        cout << "enter digit: " << n <<": ";
        cin >> x;
    }
    print_string(name, x);
    return 0;
}

