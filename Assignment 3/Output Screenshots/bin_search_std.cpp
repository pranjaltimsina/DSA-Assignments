#include <iostream>
#include <string>

/*
 * 1. Binary Search: Implement a program to search and find student details in an efficient matter.
 * Reduce the number of comparisions as much as possible. Use student's reg no as the key (int).
 * Store student name, reg no, CGPA in the list of student's details
*/

class Student {
    public:
        int reg_no;
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        float CGPA;
        Student(int r_no, std::string f_name, std::string l_name, std::string ph_no, float cgpa) {
            reg_no = r_no;
            first_name = f_name;
            last_name = l_name;
            phone_number = ph_no;
            CGPA = cgpa;
        }
        Student() {}
};


int binary_search(Student* students, int target, int high, int low) {
    // if (target > Student::get_max() || target < Student::get_min()) return -1;
    if (low > high) {
        std::cout << "Not found!\n";
        return -1;
    }
    int mid = (high + low) / 2;
    // std::cout << "Mid is " << mid << " value: " << students[mid].reg_no << " target is "<< target;
    if (students[mid].reg_no == target) {
        std::cout << "Found at " << mid << "\n";
        return mid;
    } else if (students[mid].reg_no < target) {
        // std::cout << " | Greater \n";
        binary_search(students, target, high, mid+1);
    } else if (students[mid].reg_no > target) {
        // std::cout << " | Lesser \n";
        binary_search(students, target, mid-1, low);
    }
}

void merge(Student* students, int l, int mid, int r) {
    int len_1 = mid - l + 1;
    int len_2 = r - mid;

    // Create temp arrays
    Student L[len_1], R[len_2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < len_1; i++)
        L[i] = students[l + i];
    for (int j = 0; j < len_2; j++)
        R[j] = students[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < len_1 && j < len_2) {
        if (L[i].reg_no <= R[j].reg_no) {
            students[k] = L[i];
            i++;
        }
        else {
            students[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < len_1) {
        students[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < len_2) {
        students[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(Student* students, int l, int r) {
    if (l >=r ) return;
    int mid = l + (r-l) /2;
    merge_sort(students, l, mid);
    merge_sort(students, mid+1, r);
    merge(students, l, mid, r);
}

int main() {
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;

    Student* students = new Student[n];

    std::string temp_f_name, temp_l_name, temp_ph_no;
    int temp_r_no;
    float temp_gpa;
    for (int i = 0; i < n; i++) {
        // std::cout << "Enter first name, last name, phone number, registration number and the CGPA:\n";

        std::cin >> temp_f_name >> temp_l_name >> temp_ph_no >>
                    temp_r_no >> temp_gpa;
        Student new_student(temp_r_no, temp_f_name, temp_l_name, temp_ph_no,temp_gpa);
        students[i] = new_student;
    }

    merge_sort(students, 0, n-1);


    std::cout << "Students: \n\n";
    for (int i = 0; i < n; i++) {
        std::cout << students[i].reg_no << " ";
    }
    std::cout << "\n\n";

    int query;
    // std::cout << "Enter a query: (0 to break)\n";

    while (std::cin >> query) {
        if (!query) return 0;
        std::cout << "Query: " << query << " | ";
        binary_search(students, query, n, 0);
    }

}
