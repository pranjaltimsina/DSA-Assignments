// Exp 3A: Binary search student details
// Author: Pranjal Timsina; 20BDS0392
#include <iostream>
#include <string>

class Student {
public:
  //initialize student attributes
  int reg_no;
  std::string first_name;
  std::string last_name;
  std::string phone_number;
  float CGPA;

  // constructor for Student
  Student(int r_no, std::string f_name, std::string l_name, std::string ph_no, float cgpa) {
    reg_no = r_no;
    first_name = f_name;
    last_name = l_name;
    phone_number = ph_no;
    CGPA = cgpa;
  }
  // empty constructor for Student
  // used when initializing empty array
  Student() {}
};

int binary_search(Student* students, int target, int high, int low) {
  // base case for recursion
  if (low > high) {
    std::cout << "Not found!\n\n";
    return -1;
  }
  // get index of middle element
  int mid = (high + low) / 2;
  // if found print the student details
  if (students[mid].reg_no == target) {
    std::cout << "Found at " << mid << "\n";
    std::cout << "Registration No: "  << students[mid].reg_no <<
        " | Name: " << students[mid].first_name <<
        " " << students[mid].last_name << " | Phone no: " <<
        students[mid].phone_number << " | CGPA: " <<
        students[mid].CGPA << "\n\n";
    return mid;
  } else if (students[mid].reg_no < target) {
    // check the right sub array
    return binary_search(students, target, high, mid+1);
  } else if (students[mid].reg_no > target) {
    // check the let sub array
    return binary_search(students, target, mid-1, low);
  }
}
// use merge sort for efficient sorting of student data
void merge(Student* students, int l, int mid, int r) {
  // compute the lengths of the right and the left subarray
  int len_1 = mid - l + 1;
  int len_2 = r - mid;

  // Create temp arrays
  Student L[len_1], R[len_2];

  // initialize and copy data to the right and left subarray
  // from the main array
  for (int i = 0; i < len_1; i++)
    L[i] = students[l + i];
  for (int j = 0; j < len_2; j++)
    R[j] = students[mid + 1 + j];

  /* i is the index for left subarray
  * j is the index for right subarray
  * k is the index of the main array
  */
  int i{0}, j{0}, k{l};

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

  while (i < len_1) {
    students[k] = L[i]; i++; k++;
  }
  while (j < len_2) {
    students[k] = R[j]; j++; k++;
  }
}
// main merge sort function
void merge_sort(Student* students, int left, int right) {
  if (left >= right ) return;
  int mid = (right + left) / 2;
  merge_sort(students, left, mid);
  merge_sort(students, mid+1, right);
  merge(students, left, mid, right);
}

int main() {
  int n; // initialize and input number of students
  std::cout << "Enter number of students: ";
  std::cin >> n;
  // initalize an array with n students
  Student* students = new Student[n];
  // initialize temporary variables for storing inputs
  std::string temp_f_name, temp_l_name, temp_ph_no;
  int temp_r_no;
  float temp_gpa;

  // input details of n students
  for (int i = 0; i < n; i++) {
    std::cout << "Enter first name, last name, phone number, " <<
                  "registration number and the CGPA:\n";
    std::cin >> temp_f_name >> temp_l_name >> temp_ph_no >>
                temp_r_no >> temp_gpa;
    Student new_student(temp_r_no, temp_f_name,
                     temp_l_name, temp_ph_no,temp_gpa);
    students[i] = new_student;
  }
  // sort the students array
  merge_sort(students, 0, n-1);

  int query; // initialize variable for input query
  std::cout << "Enter a query: (0 to break)\n";

  while (std::cin >> query) {
    if (!query) return 0;
    std::cout << "Query: " << query << " | ";
    // search for the queried student reg no
    binary_search(students, query, n, 0);
  }
}
