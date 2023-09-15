#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int sample_function()
{
    return 1;
}

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

    file.close();

    return 0;
}