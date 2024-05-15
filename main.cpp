#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    int roll, age;
    string name;
public:
    Student(int stdRoll, string stdName, int stdAge){
        roll = stdRoll;
        age = stdAge;
        name = stdName;
    }
    void setRoll(int stdRoll) {
        roll = stdRoll;
    }
    int getRoll() {
        return roll;
    }
    void setName(string stdName) {
        name = stdName;
    }
    string getName(){
        return name;
    }
    void setAge(int stdAge) {
        age = stdAge;
    }
    int getAge() {
        return age;
    }
    void displayStudent() {
        cout <<"Roll No: "<<roll<<endl;
        cout <<"Name: "<<name<<endl;
        cout <<"Age: "<<age<<endl;
    }
};

void updateStudent(vector<Student>& students){

    string sname;

    bool found = false;

    int choice;



    cout<<"\t\tEnter Name to Update Record :";

    cin.ignore();

    getline(cin,sname);



    for(int i = 0; i<students.size();i++){

        if(students[i].getName()==sname){

            found = true;



            cout<<"\t\t---Student Found -----"<<endl;

            cout<<"\t\t 1. Update Roll No. "<<endl;

            cout<<"\t\t 2. Update Name "<<endl;

            cout<<"\t\t 3. Update Age "<<endl;

            cout<<"\t\tEnter Your Choice :";

            cin>>choice;



            switch(choice){

                case 1:{

                    int rno;

                    cout<<"\t\tEnter New Roll No. :";

                    cin>>rno;

                    students[i].setRoll(rno);



                    break;

                }

                case 2:{

                    string name;

                    cout<<"\t\tEnter New Name :";

                    cin.ignore();

                    getline(cin,name);

                    students[i].setName(name);

                    break;

                }

                case 3:{

                    int age;

                    cout<<"\t\tEnter New Age :";

                    cin>>age;

                    students[i].setAge(age);

                    break;

                }

                default:

                    cout<<"\t\tInvalid Number"<<endl;



            }

        }

        if(!found){

            cout<<"\t\tRecord Not Found"<<endl;

            return;

        }

    }

}



void SearchStudent(vector<Student>& students){

    int rollNo;

    cout<<"\t\tEnter Roll No. :";

    cin>>rollNo;



    for(int i = 0; i<students.size();i++){

        if(students[i].getRoll() == rollNo){

            cout<<"\t\t--------Student Found ------------"<<endl;

            students[i].displayStudent();

            return;

        }

    }

}



void DisplayAllStudent(vector<Student>& students){

    if(students.empty()){

        cout<<"\t\t No Student Found "<<endl;

        return;

    }

    for(int i = 0; i<students.size();i++){

        students[i].displayStudent();

        cout<<endl;

    }

}


void addNewStudent(vector<Student> &students){

    int rollNo,age;

    string name;

    cout<<"Enter Roll No. :";

    cin>>rollNo;



    //check if student already exit

    for(int i = 0; i<students.size();i++){

        if(students[i].getRoll() == rollNo){

            cout<<"\t\tStudent Already Exit"<<endl;

            return;

        }

    }

    cout<<"Enter Name : ";

    cin>>name;

    cout<<"Enter Age : ";

    cin>>age;



    Student newStudent(rollNo,name,age);

    students.push_back(newStudent);



}




void deleteStudent(vector<Student>& students){

    string name;

    cout<<"Enter Name to Delete :";

    cin.ignore();

    getline(cin,name);



    for(int i = 0; i<students.size();i++){

        if(students[i].getName() == name){

            students.erase((students.begin()+i));

            cout<<"\t\tStudent Remove Successfully"<<endl;

        }

    }

}

int main() {
    vector <Student> students;
    students.push_back(Student(1,"Araf",28));
    char choice;

    do{
        system("cls");
        int op;
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t*** Student Management System ***";
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t 1. Add New Student"<<endl;
        cout<<"\t\t 2. Display All Student "<<endl;
        cout<<"\t\t 3. Search Student"<<endl;
        cout<<"\t\t 4. Update Student"<<endl;
        cout<<"\t\t 5. Delete Student "<<endl;
        cout<<"\t\t 6. Exit"<<endl;
        cout<<"\t\t Enter Your Choice : ";
        cin>>op;
        switch(op){
            case 1:
                addNewStudent(students);
                break;

            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;

            case 4:
                updateStudent(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 6:
                exit(1);

            default:
                cout<<"\t\tInvalid Number "<<endl;
        }

        cout<<"\t\tDo You Want to Continue [Yes/No] ? :";
        cin>>choice;

    }while(choice == 'y'||choice=='Y');
    return 0;
}
