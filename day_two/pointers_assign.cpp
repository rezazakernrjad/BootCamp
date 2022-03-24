#include <iostream>

using namespace std;


void RemoveDuplicates(int* old_arr, int& old_size, int* new_arr, int* new_size){
    for (int i = 0; i < old_size; i++){
        int j{0};
        if (i ==0){new_arr[0] = old_arr[0];
        } else { 
            for (j = 0; j <  i; j++){
                if (old_arr[i] == old_arr[j]){
                j = i;
                } 
            }--j;
             if (i != j){
                new_arr[++(*new_size)] = old_arr[i];
                j=i;
            }
        }
    }
}

int main(){

    int old_size;
    int* nya_size;
    int ny_size{0};
    nya_size = &ny_size;
    int* new_arr = new int[*nya_size];
    cout << "Enter the size of the array: ";
    cin >> old_size;
    if (old_size != 0){
        int old_arr[old_size];
        for (int i = 0; i < old_size; i++){
            cout << "enter element["<< i <<"]: ";
            cin >> old_arr[i]; 
        }
        RemoveDuplicates(old_arr, old_size, new_arr, nya_size);
        cout << "new size: " << *nya_size +1<<endl;
        for (int i = 0; i < *nya_size+1; i++){
            cout << "new_arr["<<i<<"]= " << new_arr[i] << endl;
        }
    } else {
        cout << "ERROR"<< endl;
    }
    return 0;
}