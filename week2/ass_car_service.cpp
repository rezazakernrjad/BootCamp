/*
A car service shop needs to keep track of the records of services they provide to their customer. Create a system
for them so they could keep ATLEAST the below records:
• Date the customer visited
• Services performed (at least 2 different services)
• Parts changed (at least 2 different parts)
• Payment (method & amount)
*/

#include<iostream>
using namespace std;
#include "ass_car_service.hpp"

void Car::CarService::customer_input(CarService* car_service){
    Car* car;
    car = new Car[number_of_cars];
    cout << "Enter number of cars you what to be taken care of: ";
    cin >> car_service->number_of_cars;
    setNumberofCars(car_service->number_of_cars);
    int cost[car_service->number_of_cars]{0};
    int service_per_car[number_of_cars][13]{0}; 
    // 13 number of total services the workshop offers. sum of # of structs
    int k{0};
    
    for (int n =0; n < car_service->number_of_cars; n++){
        bool excont{true};
        do {
            
            cout << "For Engin:Cylinder enter       1" << endl;
            cout << "For Engin:Pipe enter           2" << endl;
            cout << "For Engin:Catalysor enter      3" << endl;
            cout << "For Body:Door enter            4" << endl;
            cout << "For Body:Mirror enter          5" << endl;
            cout << "For Body:TurnIndicators enter  6" << endl;
            cout << "For Body:HeadLamp enter        7" << endl;
            cout << "For Window:Glass enter         8" << endl;
            cout << "For Window:Motor enter         9" << endl;
            cout << "For Window:Plast enter         10" << endl;
            cout << "For Wheel:Tire enter           11" << endl;
            cout << "For Wheel:Ring enter           12" << endl;
            cout << "For Wheel:change enter         13" << endl;
            cout << "press 0 once you are done with car number " << n +1 << endl;
            cout << "For What part of car number "<< n + 1 <<" you need reparation: ";
            cin >> k;
            if ((k > 0) && (k <= 13)){
              service_per_car[n][k] = 1;  
              cout << " car "<< n << " part " << k << endl;
            } else if (k == 0){
                cout << "exit car " << n << endl;
                excont = false;
            } else {
                cout << " Enter number again..." << endl;
            }
        

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
        } while (excont);
        car_service->printCost(n);
    }
}
/*
add  
    string* service_names;  
    service_names = new string;
to save the name of service each car got while user enters what 
services he needs.
*/


int main(){
    Car::CarService* carService;
    carService = new Car::CarService;
    carService->customer_input(carService);
    cout << "number of cars: " << carService->getNumberofCars() << endl;
    
}