
#include<iostream>
using namespace std;
uint16_t devshift(int val, uint16_t r, int s){
    uint16_t val_1 = val/150;
    val_1 = val_1 << s;
    return r | val_1;
}
int main(){
    uint16_t reg = 0x0000;
    cout << "Note: Speed ove 300km/h will limited to 300, Distances over 1050mm will limeted to 1050" << endl;
    cout << "Enter speed max 300km/h: ";
    int speed{0};
    cin >> speed;
    if (speed > 300){speed = 300;}
    uint16_t speed1;
    speed1 = speed / 20;
    reg = speed1 << 12;

    cout << "Enter Front distance max 1050 mm: ";
    int front{0};
    cin >> front;
    if (front > 1050){front = 1050;}
    reg  = devshift(front, reg, 9);

    cout << "Enter Rear distance max 1050 mm: ";
    int rear{0};
    cin >> rear;
    if (rear > 1050){rear = 1050;}
    reg  = devshift(rear, reg, 6);
   
    cout << "Enter Right distance max 1050 mm: ";
    int right{0};
    cin >> right;
    if (right > 1050){right = 1050;}
    reg  = devshift(right, reg, 3);

    cout << "Enter Left distance max 1050 mm: ";
    int left{0};
    cin >> left;
    if (left > 1050){left = 1050;}
    reg  = devshift(left, reg, 0);
    printf("Register valuein hex = 0x%X \n\n", reg);
    return 0;
}