#include <iostream>
#include <chrono>

int comparisons{0}, array_access{0};

void insertion_sort(int *numbers, int size) {
    int key;

    for (int i = 1; i < size; i++) {
        key = numbers[i];
        array_access++;
        int j = i-1;
        while (j >= 0 && ++comparisons && ++array_access && numbers[j] > key) {
            numbers[j+1] = numbers[j];
            array_access +=2;
            j--;
        }
        numbers[j+1] = key;
        array_access+=1;
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
        insertion_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Time taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}

