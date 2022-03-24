#include <iostream>
#include <climits>
using namespace std;
void BubbleSort(int* arr, int size ){
    int tmp{0} , i{0}; 
    for (int j = 0; j < size  ; j++){
        for (i = 0; i < size ; i++){
            if (arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
}

void SelectionSort(int* arr, int size){
    int min{INT_MAX} , i{0};
    for (int j= 0; j < size; j++){
        for (i = j; i < size; i++){
            if (arr[i] < min){
                min = arr[i];
            }
        }
    arr[j] = min;
    min = INT_MAX;
    }
}

void BoundaryDescending(int* arr,  int& lwr, int& upr){
    int size = upr - lwr -1;
    int desc_arr[size];
    cout <<"size: " << size << endl;
    if (lwr < upr){
        int size = upr - lwr -1;
        for (int i = 0; i < size; i++){
            desc_arr[i] = --upr;
            cout << "desc["<<i<<"]: " << desc_arr[i]<<endl; 
        }
        arr = desc_arr;
    } else {
        cout << "lwr is gt or eq upr" << endl;
        int desc_e_arr[2]{0xFF, 0xFF};
        arr = desc_e_arr;
        cout << "arr[0]: " << arr[0] << "\narr[1]: "<< arr[1]<< endl; 
    }
}

int main(){
    int size{0};
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    for (int i = 0 ; i < size ; i++){
        cout << "enter element " << i << " off array: ";
        cin >>  arr[i];
    }
    int* b_arr = arr;
    int* s_arr = arr;
    BubbleSort(b_arr, size);
    for (int k = 0; k < size; k++){
        cout << "Bubbles_sorted["<<k<<"]" << b_arr[k] << endl;
    }
    SelectionSort(s_arr, size);
    for (int k = 0; k < size; k++){
        cout << "Selestion_sorted["<<k<<"]" << s_arr[k] << endl;
    }
    int lwr, upr;
    cout << "Enter lower bound of array: ";
    cin >> lwr;
    cout << "Enter upper bound of array: ";
    cin >> upr;
    int* d_arr =  new int;
    BoundaryDescending(d_arr, lwr, upr);
    if (lwr < upr){
        for (int k = 0; k < upr - lwr - 1; k++){
            cout << "Boundary_Desc_sorted["<<k<<"]" << d_arr[k] << endl;
        }
    }
    delete d_arr;
    return 0;
}