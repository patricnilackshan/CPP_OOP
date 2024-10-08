#include <iostream>

using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0; 
    /*
    Abstract class is a class that has atleast one pure virtual function
    Pure virtual function is a function that has no implementation
    Class which implements Abstract class must implement all the pure virtual functions

    Use virtual void AskForPromotion() = 0; when you want to enforce that all derived classes
    implement a specific function, creating a contract for them.

    Use virtual void AskForPromotion() {} when you want to provide a default behavior that 
    derived classes can choose to override.
    */ 
};

class Employee:AbstractEmployee{
    private:
        string Name;
        string Company;
        int Age;
    public:
        Employee(string Name,string Company,int Age){
            this->Name = Name;
            this->Company = Company;
            this->Age = Age;
        }
        void IntroduceYourself(){
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }

        void AskForPromotion(){
            if(Age>30){
                cout << Name << " got promoted!" << endl;
            }else{
                cout << Name << " sorry no promotion for you!" << endl;
            }
        }

        string getName(){
            return Name;
        }
        string getCompany(){
            return Company;
        }
        int getAge(){
            return Age;
        }
        void setName(string Name){
            this->Name = Name;
        }
        void setCompany(string Company){
            this->Company = Company;
        }
        void setAge(int Age){
            this->Age = Age;
        }
};

class Developer: public Employee{
    /*
    If you don't specify the access specifier, it will default to private.
    So you can't access the Developer class methods derviced from Employee Class from outside.
    */
    public:
        string FavProgrammingLanguage;
        Developer(string Name,string Company,int Age,string FavProgrammingLanguage):Employee(Name,Company,Age){
            this->FavProgrammingLanguage = FavProgrammingLanguage;
        }   
};

int main(){
    Employee employee1 = Employee("Saldina","Google",23);
    Developer d = Developer("Saldina","Amazon",23,"JavaScript");
    employee1.IntroduceYourself();
    cout<<employee1.getName()<<endl;
    employee1.AskForPromotion();
}
