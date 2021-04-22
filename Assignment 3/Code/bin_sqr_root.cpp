#include <iostream>

int get_square_root (int low, int high, int number) {
    // variable for storing the answer
    int ans_sqrt = number;

    // condition for exiting the loop
    while (low <= high) {
        int mid = (high + low) / 2;

        if (mid*mid == number) {
            return mid;
        } else if (mid*mid > number) {
            // if the product is greater than then number
            // reduce the set of possible numbers
            high = mid - 1;
        } else {
            // the answer will be the mid in this case
            ans_sqrt = mid;
            low = mid + 1;
        }
    }
    return ans_sqrt;
}
int main() {
    int number; // intialize and input the number
    std::cout << "Enter a number: ";
    std::cin >> number;
    // calculate the square_root and print it
    float square_root = get_square_root(1, number, number);
    std::cout << "The square root is " << square_root;
}
