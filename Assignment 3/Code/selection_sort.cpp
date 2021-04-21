#include <iostream>
#include <chrono>

int comparisons{0}, array_access{0};

void selection_sort(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        int key = i;
        for (int j = i+1; j < size; j++) {
            if (++comparisons&& ++++array_access && numbers[j] < numbers[key]) {
                key = j;
            }
        }
        int temp = numbers[key];
        numbers[key] = numbers[i];
        numbers[i] = temp;
        array_access += 3;
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
    selection_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Time taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}
