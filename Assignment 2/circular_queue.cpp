#include <iostream>

void enqueue(int &head, int &tail, int &size, int queue[], int &data) {
    if (head == -1) { // initialize head and tail if queue is empty
        head = 0; tail = 0;
        queue[tail] = data;
    } else if (!((head == 0 && tail == size-1)||(tail == head-1))) {
            tail = (tail+1)%size; // increment tail and use % for making it cyclic
            queue[tail] = data;
    } else std::cerr << "Overflow!!\n"; // give error message
}

int dequeue(int &head, int &tail, int size, int queue[]) {
    if (head != -1) { // check if queue is not empty
        int return_value{queue[head]};
        if (head == tail) {
            tail = -1; head = -1; // if one element it queue, resets head and tail
        } else {
            head = (head+1)%size; // increment head, use % for making it cyclic
        }
        return return_value;
    } else std::cerr << "Underflow, returning garbage value!\n"; // throw error
}

void display_queue(int &head, int &tail, int &size, int queue[]) {
    if (head != -1) {
       std::cout << "--------------Queue--------------\n Head -> ";
       int i = head; // start at head of queue
       while (true) {
            if (i == tail) {
                std::cout << queue[i];
                break; // if tail is reached, break
            } else {
                std::cout << queue[i] << " "; // print element
            }
           i = (i + 1)%size; // increment i cyclically
       }
        std::cout << " <- Tail\n---------------------------------\n";
    } else {
        std::cerr << "empty queue!\n"; // throw error
    }
}

int main() {
    int size, choice, head{-1}, tail{-1};
    std::cout << "Enter size of queue: ";
    std::cin >> size;
    int queue[size]; // initialize queue
    while (true) {
        std::cout << "1. Display 2. Enqueue 3. Dequeue 0. Exit\n";
        std::cin >> choice;
        switch (choice) { // handle user choice
        case 0:
            return 0; // exit program
        case 1:
            display_queue(head, tail, size, queue);
            continue;
        case 2:
            std::cout << "Data: ";
            std::cin >> choice; // get user input
            enqueue(head, tail, size, queue, choice);
            continue;
        case 3:
            std::cout << dequeue(head, tail, size, queue) << " dequeued\n";
        default:
            continue;
        }
    }
    return 0;
}
