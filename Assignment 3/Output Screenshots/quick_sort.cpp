#include <iostream>
#include <chrono>

int array_access{0}, comparisons{0};

int partition(int * numbers, int p, int r) {
    int x{numbers[r]}, i{p-1}, temp;
    array_access++;
    for (int j = p; j <= r-1; j++) {
        if (++array_access && ++comparisons && numbers[j] <= x) {
            i++;
            temp = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = temp;
            array_access+=4;
        }
    }
    temp = numbers[i+1];
    numbers[i+1] = numbers[r];
    numbers[r] = temp;
    array_access+=4;
    return i+1;
}


void quick_sort(int *numbers, int left, int right) {
    if (left < right) {
        int q = partition(numbers, left, right);
        quick_sort(numbers, left, q-1);
        quick_sort(numbers, q+1, right);
    }
}

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int size, *numbers;

    std::cin >> size;
    numbers = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    auto t1 = high_resolution_clock::now();
        quick_sort(numbers, 0, size-1);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Time taken: " <<  ms_double.count() << "ms";

    std::cout << " | Array accesses: " <<  array_access << " | Comparisons: " << comparisons << "\n";
}
