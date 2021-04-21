#include <iostream>
#include <chrono>

int comparisons{0}, array_access{0};

void bubble_sort(int *numbers, int size) {
    int temp, key;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size -1; j++) {
            comparisons++;
            array_access +=2;
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                array_access += 4;
            }
        }
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
        bubble_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Time taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}
