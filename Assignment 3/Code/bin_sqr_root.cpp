#include <iostream>

typedef unsigned long long ULL;
int SquareRootFloor (ULL beg, ULL end, ULL n) {

    int ans_sqrt = n;

    while (beg <= end) {

        ULL mid = beg + (end-beg)/2;
        std::cout << "beg : " << beg << " end : " << end << " mid : " << mid << std::endl;

        if (mid*mid == n) {
            return mid;
        } else if (mid*mid > n) {
            end = mid - 1;
        } else {
            /* If mid*mid < n, it does not certainly mean that mid is the floor(square_root(n)), it may / may not be.
               Example n = 15, when mid becomes 2. mid*mid < 15 so 2 could well be the floor(square_root(15)) so store it
               as the answer and continue the search for a bigger number that could also be the floor(square_root(15))*/
            std::cout << "Store square root as mid (" << mid << ")" << std::endl;
            ans_sqrt = mid;
            beg = mid + 1;
        }
    }
    return ans_sqrt;
}
int main() {
    float number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    number = (float) number;
    float square_root = SquareRootFloor(1, number, number);
    std::cout << "The square root is " << square_root;
}
