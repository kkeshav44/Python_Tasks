// KESHAV THAKUR  
#include <iostream> 
using namespace std; 
 
// This function turns a grade letter into a number. 
int getGradePoint(char grade){ 
    switch (grade){ 
        case 'A': 
        case 'a': return 10; 
        case 'B': 
        case 'b': return 8; 
        case 'C': 
        case 'c': return 6; 
        case 'D': 
        case 'd': return 4; 
        case 'F': 
        case 'f': return 0; 
        default: return -1;  
    } 
} 
 
int main() { 
    int numCourses; 
 
    cout << "No of course taken ?  "; 
    cin >> numCourses; 
     
    char grades[100];         // To store letter grades (A, B, C, etc.) 
    float credits[100];       // To store the credit hours for each course 
    float gradePoints[100];   // To store the calculated grade points for each course 
 
    float totalCredits = 0;      // Sum of all credit hours 
    float totalGradePoints = 0;  // Sum of all grade × credit 
 
    for (int i = 0; i < numCourses; i++) { 
        cout << "\nCourse " << i + 1 << ":\n"; 
 
        char grade; 
        int point; 
        do { 
            cout << "Enter your grade (A, B, C, D, F): "; 
            cin >> grade; 
            point = getGradePoint(grade); 
 
            if (point == -1) 
                cout << " that's not a valid grade. Please enter again.\n"; 
 
        } while (point == -1); // Keep asking until a valid grade is entered 
 
        grades[i] = grade; // Store the grade 
        cout << "Enter credit hours for this course: "; 
        cin >> credits[i]; 
        // Calculate grade points (grade × credit) and store it 
        gradePoints[i] = point * credits[i]; 
 
        totalCredits += credits[i]; 
        totalGradePoints += gradePoints[i]; 
    } 
 
    // Now let's show a summary of all the courses 
    cout << "\n--- Here's What You Entered ---\n"; 
    for (int i = 0; i < numCourses; i++) { 
        cout << "Course " << i + 1 << ": Grade = " << grades[i] 
             << ", Credits = " << credits[i] 
             << ", Grade Points = " << gradePoints[i] << "\n"; 
    } 
 
    // Final cgpa 
    if (totalCredits == 0) { 
        cout << "\nOops! You didn't enter any valid credit hours.\n"; 
    } else { 
        float cgpa = totalGradePoints / totalCredits; 
        cout << "\n Your CGPA is: " << cgpa << "\n"; 
    } 
 
    return 0; 
} 