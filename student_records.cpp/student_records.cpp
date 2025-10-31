#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>  // for transform (uppercase conversion)
using namespace std;

// ----------------------------
//  ENUM for Grade Levels
// ----------------------------
enum GradeLevel {
    FRESHMAN = 1,
    SOPHOMORE,
    JUNIOR,
    SENIOR
};

// ----------------------------
//  TYPEDEF / USING EXAMPLES
// ----------------------------
using GPA = double;           // alias for double (GPA type)
typedef string StudentName;   // typedef example

// ----------------------------
//  NAMESPACE for Student Utilities
// ----------------------------
namespace StudentUtils {

    // Convert a student's name to uppercase
    void formatName(string &name) {
        transform(name.begin(), name.end(), name.begin(), ::toupper);
    }

    // Convert enum to readable text
    string gradeToString(GradeLevel grade) {
        switch (grade) {
            case FRESHMAN:  return "Freshman";
            case SOPHOMORE: return "Sophomore";
            case JUNIOR:    return "Junior";
            case SENIOR:    return "Senior";
            default:        return "Unknown";
        }
    }

    // Display formatted student info
    void displayStudentInfo(const StudentName &name, GradeLevel grade, GPA gpa) {
        cout << "\n-----------------------------\n";
        cout << "Student Record:\n";
        cout << "Name: " << name << endl;
        cout << "Grade Level: " << gradeToString(grade) << endl;

        // Format GPA to two decimal places
        cout << fixed << setprecision(2);
        cout << "GPA: " << gpa << endl;
        cout << "-----------------------------\n";
    }
}

// ----------------------------
//  MAIN PROGRAM
// ----------------------------
int main() {
    StudentName name;
    int gradeInput;
    GPA gpa;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
    cin >> gradeInput;

    cout << "Enter GPA: ";
    cin >> gpa;

    // Convert name to uppercase using namespace function
    StudentUtils::formatName(name);

    // Display formatted record
    StudentUtils::displayStudentInfo(name, static_cast<GradeLevel>(gradeInput), gpa);

    return 0;
}
