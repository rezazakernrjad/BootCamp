#include <iostream>
using namespace std;

class Animal {
    public:
    void eat(){
        cout << "Eating Animal:" << endl;
    }
    int wight;
};

class Dog: public virtual Animal{
public:
    Dog() = default;
    void woof(){
        cout << "woofing" << endl;
    }

};

class Cat: public virtual Animal {
public:
    Cat() = default;
    void Meow(){
        cout << "Meawing" << endl;
    }
    void eat(){
        cout << "Eating CATS:" << endl;
    }
};

class CatDog: public Cat, public Dog {
public:
    CatDog() = default;
    void eat(){
        cout << "Eating CATS&DOGS" << endl;
    }
};

int main(){
    CatDog cat_dog;
    Cat cat;
    Dog dog;
    cat_dog.Meow();
    cat_dog.woof();
    cat_dog.wight = 4;
    cout << "cat_dog.eat(): "; cat_dog.eat();
    cout << "cat_dog.eat(): "; cat_dog.eat();
    cout << "cat.eat(): ";  cat.eat();
    cout << "dog.eat(): "; dog.eat();
    return 0;
}