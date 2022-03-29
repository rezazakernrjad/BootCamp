

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
        car_service->printCost(n);

    }
}



int main(){
    Car::CarService* carService;
    carService = new Car::CarService;
    carService->customer_input(carService);
    cout << "number of cars: " << carService->getNumberofCars() << endl;
    
}