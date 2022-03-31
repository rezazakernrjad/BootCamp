

namespace Car {
    struct Engine {
        const int cylinder{200};
        const int pipe{150};
        const int catalysor{300};
    };
    struct Body {
        const int door{300};
        const int mirror{100};
        const int blinkers{200};
        const int headlamp{350};
    };
    struct Window{
        const int glass{280};
        const int motor{380};
        const int plast{30};
    };
    struct Wheel{
        const int tire{400};
        const int ring{300};
        const int change{100};
    };
    struct Car {
        Engine engin;
        Body body;
        Window window;
        Wheel wheel;
        int cost{0};
    };

    enum class Payment{
        cache,
        debit,
        visa,
        klarna,    
    };

    class CarService {
        Car* car;
        int date;
        Payment payment;
        int number_of_cars{0};
        int** service_per_car1;
        string service_name[13] ={"Engin-Cylinder: 200", "Engin-pipe: 150", "Engin-catalysor: 300",
                                    "Body-door: 300", "Body-Mirror: 100", "Body-dooTurnindicator: 200", "Body-Headlamps: 350",
                                    "Window-Glass: 280", "Window-Motor: 380", "Window-Plast: 30",
                                    "Wheel-Tire: 400", "Wheel-Ring: 300", "Wheel-change: 100"};
    public:
        void customer_input(CarService*);
        bool calculate_coest(CarService*);
        int getNumberofCars(){
            return number_of_cars;
        }
        void setNumberofCars(int& number_of_cars){
            car = new Car[number_of_cars];
            service_per_car1 = new int*[number_of_cars];
            for (int ar =0; ar < number_of_cars; ar++){
                // 13 number of total services the workshop offers. sum of # of structs
                service_per_car1[ar] = new int[13];
            }
        }
        void printBoughtList(){
            for (int n = 0; n < number_of_cars; n++){
                std::cout << "Bought Services for car number: "<< n +1 << std::endl;
                for (int m = 0; m < 13; m++){
                    if (service_per_car1[n][m] == 1)
                        {std::cout << "--" <<service_name[m] << std::endl;}
                }
            } 
        }
        void printCost(){
            for (int k = 0; k < number_of_cars; k++){
                std::cout << "*****cost for car # "<< k + 1 << ": " << car[k].cost << std::endl;
            }
        }
        ~CarService(){
            std::cout << "Exit Program run deconstructor" << endl;
            std::cout<< "delete service_per_car1"  << endl;
            delete [] service_per_car1;
            std::cout << "delete car" << std::endl;
            delete [] car;
        }
    };//class
} // namespace