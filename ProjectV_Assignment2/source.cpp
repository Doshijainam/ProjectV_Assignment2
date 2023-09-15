#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



struct STUDENT_DATA
{
    string lastName;
    string firstName;
};

int main()
{
    fstream file;
    file.open("StudentData.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }

    vector<STUDENT_DATA> students;

    STUDENT_DATA student;

    while (file >> student.lastName >> student.firstName)
    {
        students.push_back(student);
    }

    for (STUDENT_DATA& student : students)
    {
        cout << "First Name: " << student.firstName << " Last Name: " << student.lastName << endl;
    }

    file.close();

    return 0;
}