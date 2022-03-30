

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
        char *serviceName;
    public:
        
        void customer_input(CarService*);
        int getNumberofCars(){
            return number_of_cars;
        }
        void setNumberofCars(int& number_of_cars){
            car = new Car[number_of_cars];
            serviceName = new char[number_of_cars];
        }
/*        void setServiceName(char* servicename, int n){
            serviceName[n] = servicename;
        }
        void printServiceName(int n){
            std::cout << "service name: " << serviceName[n] << endl; 
        }
*/
        void printCost(int& n){
            std::cout << "*****cost for car # "<< n + 1 << ": " << car[n].cost << std::endl;
            car[n].cost = 0;
        }
    };
}