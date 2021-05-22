#include<iostream>
using namespace std;
class Student {
    public:
    int rollNumber;
    private:
    int age;
    public:
    void display(){
      cout<<age<<" "<<rollNumber<<endl;
    }
    int getAge(){
      return age;
    }
    void setAge(int a,int password){
      if(password!=123){
        return;
      }
      if(a<0){
        return;
      }
      age=a;
    }
};
int main(){
    Student s1;
    Student s2;
    Student s3,s4,s5;
    s1.rollNumber=101;
    cout<<"S1 Age: "<<s1.getAge()<<endl;
    cout<<"S1 Roll Number: "<<s1.rollNumber<<endl;
    s1.display();
    s2.display();
    Student *s6=new Student;
    (*s6).rollNumber=104;
    (*s6).display();
    cout<<"S6 age: "<<s6->getAge()<<endl;
    s6->rollNumber=104;
    s6->display();
}
