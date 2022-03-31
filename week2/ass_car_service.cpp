/*
A car service shop needs to keep track of the records of services they provide to their customer. Create a system
for them so they could keep ATLEAST the below records:
• Date the customer visited
• Services performed (at least 2 different services)
• Parts changed (at least 2 different parts)
• Payment (method & amount)
*/
/*
TODO:
add exit machanism: ask the client to press "c" to exit the process:
    delete memories borrowed from the heap.
print out a list of bought services per car.
    create a vector of strings including each service name and price of service
*/
#include<iostream>
using namespace std;
#include "ass_car_service.hpp"

void Car::CarService::customer_input(CarService* car_service){
//    Car* car;
//    car = new Car[number_of_cars];
//    cout << "Enter number of cars you what to be taken care of: ";
//    cin >> car_service->number_of_cars;
    do {
        cout << "Enter number of cars you what to be taken care of: ";
        cin >> car_service->number_of_cars;
        if (car_service->number_of_cars <= 0){
            cout << "Number of cars you entered is not correct. try again..." << endl;
        }
    } while (car_service->number_of_cars <= 0 );
    setNumberofCars(car_service->number_of_cars);
    cout << "1- For Engin:Cylinder" << endl;
    cout << "2- For Engin:Pipe" << endl;
    cout << "3- For Engin:Catalysor" << endl;
    cout << "4- For Body:Door" << endl;
    cout << "5- For Body:Mirror" << endl;
    cout << "6- For Body:TurnIndicators" << endl;
    cout << "7- For Body:HeadLamp" << endl;
    cout << "8- For Window:Glass" << endl;
    cout << "9- For Window:Motor" << endl;
    cout << "10- For Window:Plast" << endl;
    cout << "11- For Wheel:Tire" << endl;
    cout << "12- For Wheel:Ring" << endl;
    cout << "13- For Wheel:change" << endl;
    cout <<"******************************************" << endl;
    cout << "* press 0 once you are done with the car " << "*" <<endl;
    cout <<"******************************************" << endl;
    cout << "* Enter -1 to EXIT  " << "*" <<endl;
    cout <<"******************************************" << endl;

}
/*
add  
    string* service_names;  
    service_names = new string;
to save the name of service each car got while user enters what 
services he needs.
*/
bool Car::CarService::calculate_coest(CarService* car_service){
//    int service_per_car[number_of_cars][13]{0}; 
    for (int n =0; n < car_service->number_of_cars; n++){
    bool excont{true};
    int k{0};
    do {
        cout << "For What part of car number "<< n + 1 <<" you need reparation: ";
        cin >> k;
        if ((k > 0) && (k <= 13)){
            if (service_per_car1[n][k-1] == 1){
            cout << "!!!!you have alraedy cosen this servis for car " << n +1 << endl;
        } else {
            switch (k) {
                case 1:
                    car_service->car[n].cost += car_service->car[n].engin.cylinder;
                    break;
                case 2:
                    car_service->car[n].cost += car_service->car[n].engin.pipe;
                    break;
                case 3:
                    car_service->car[n].cost += car_service->car[n].engin.catalysor;
                    break;
                case 4:
                    car_service->car[n].cost += car_service->car[n].body.door;
                    break;
                case 5:
                    car_service->car[n].cost += car_service->car[n].body.mirror;
                    break;
                case 6:
                    car_service->car[n].cost += car_service->car[n].body.blinkers;
                    break;
                case 7:
                    car_service->car[n].cost += car_service->car[n].body.headlamp;
                    break;
                case 8:
                    car_service->car[n].cost += car_service->car[n].window.glass;
                    break;
                case 9:
                    car_service->car[n].cost += car_service->car[n].window.motor;
                    break;
                case 10:
                    car_service->car[n].cost += car_service->car[n].window.plast;
                    break;
                case 11:
                    car_service->car[n].cost += car_service->car[n].wheel.tire;
                    break;
                case 12:
                    car_service->car[n].cost += car_service->car[n].wheel.ring;
                    break;
                case 13:
                    car_service->car[n].cost += car_service->car[n].wheel.change;
                    break;
                default:
                    car_service->car[n].cost += 0;
                }
            }
//              service_per_car[n][k] = 1;
              car_service->service_per_car1[n][k-1] = 1;
              cout << " car "<< n << " part " << k << endl;
            } else if (k == 0){
                cout << "*****exit car " << n + 1 << "****" << endl;
                excont = false;
            } else if (k == -1) {
                car_service->~CarService();
                return false;
            } else {
                    cout << "!!!!!!!!! WROnG NUMBER Enter number again..." << endl;
            }
        } while (excont);
    }
    system("clear");
     return true;
}

int main(){
    Car::CarService* carService;
    carService = new Car::CarService;
    carService->customer_input(carService);
    if (carService->calculate_coest(carService)) {
    carService->printBoughtList();
    carService->printCost();
    }
    
}