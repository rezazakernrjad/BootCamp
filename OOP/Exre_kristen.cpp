
/*
Kristen is a contender for valedictorian of her high school. She wants to know how many students (if any) have 
scored higher than her in the exams given during this semester.
Create a class named with the following specifications:
•An instance variable named to hold a student's exam scores.
•A void input() function that reads integers and saves them to .
•An int calculateTotalScore() function that returns the sum of the student's scores.
*/
#include <iostream>
using namespace std;
class Student{
    public:
    Student() {}
    double getScore(){
        return sum_;
    }
    void student_input(){
        double tmp{0};
        for (int j= 0; j < 5; j++){
            cout << "  Enter scor " << j << ": ";
            cin >> tmp;
            sum_ += tmp;
        }
    }
    private:
    double sum_;
};

int main(){
    int number_of_students{0};
    cout << "Enter number of Students: ";
    cin >> number_of_students;
    Student* student_vec;
    student_vec = new Student[number_of_students];
    int smarter{0};
    for (int i = 0; i < number_of_students; i++){

        if (i ==0){cout << "For Kristina: " << endl;}
        else {cout << "For Student: " << i << endl;} 
        student_vec[i].student_input();
        if (student_vec[i].getScore() > student_vec[0].getScore()){
            smarter++;
        }
        cout << "student( "<<i<<"] sum: " << student_vec[i].getScore()<< endl;
        }
        cout << "number of students with score highrt than Kristina: "<< smarter<< endl;
    return 0;
}