#include<iostream>
using namespace std;
#include<string>
class aditya{
    private:
        int salary;
    public:
        aditya(){
            cout<<"Member Created\n";
            dept="Computer Science";
        }
        string name;
        string surname;
        string dept;
        
};
int main(){
    aditya A;
    A.name="Animesh";
    A.surname= "Singh";
    cout<<A.name<<" "<<A.surname<<"\n"<<A.dept;



}