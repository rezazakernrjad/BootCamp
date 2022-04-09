

#include<iostream>
using namespace std;
int main(){
uint16_t inp = 0XBA5B;
cout << "input: " << inp << endl;
uint16_t seat_belt = inp & 0xF800;
cout << "seat belt: " << (seat_belt>>11) << endl;
uint16_t windows = inp & 0x0780;
cout << "windows: " << (windows>>7) << endl;
uint16_t doors = inp & 0x0078;
cout << "doors: " << (doors>>3) << endl;
uint16_t lights = inp & 0x0007;
cout << "lights: " << lights << endl;
return 0;
}