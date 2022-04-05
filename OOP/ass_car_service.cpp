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
    for (int n =0; n < car_service->number_of_cars; n++){
        car_service->car[n].cost += car_service->car[n].body.door;
        car_service->car[n].cost += car_service->car[n].body.blinkers;
        car_service->car[n].cost += car_service->car[n].engin.catalysor;
        car_service->setServiceName("OP", n);
        car_service->printServiceName(n);
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