#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>

using namespace std;

struct STUDENT_DATA
{
    string lastName1;
    string firstName1;
};

#ifdef PRE_RELEASE 
struct STUDENT_DATA_PRE_RELEASE
{
    string lastName;
    string firstName;
    string EmailAddress;
};

using STD = STUDENT_DATA_PRE_RELEASE;
#else
using STD = STUDENT_DATA;
#endif // PRE_RELEASE

int main()
{
#ifdef PRE_RELEASE
    cout << "THIS IS THE PRE-RELEASE SOURCE CODE" << endl;
    fstream file;
    file.open("StudentData_Emails.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }

    vector<STD> students;

    STD student;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        
        if (getline(ss, student.lastName, ',') && getline(ss, student.firstName, ',') && getline(ss, student.EmailAddress))
        {
            students.push_back(student);
        }

    }

    for (const STD& student : students)
    {
        cout << "First Name: " << student.firstName << endl
            << "Last Name: " << student.lastName << endl
            << "Email Address: " << student.EmailAddress << endl<<endl;
    }


    file.close();

    return 0;
#else
    cout << "THIS IS THE STANDARD SOURCE CODE" << endl;
    fstream file;
    file.open("StudentData.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }

    vector<STD> students;

    STD student;

    while (file >> student.lastName1 >> student.firstName1)
    {
        students.push_back(student);
    }

    for (const STD& student : students)
    {
        cout << "First Name: " << student.firstName1 << " Last Name: " << student.lastName1 << endl;
    }

    file.close();

    return 0;
#endif // PRE_RELEASE
}
