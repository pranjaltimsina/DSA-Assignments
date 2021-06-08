#include <iostream>
#include <vector>

std::vector<std::vector<int>> get_matrix(int points) {
    std::vector<std::vector<int>> adjacency_matrix;

    int value;
    std::vector<int> temp;

    for (int i = 0; i < points; i++) {
        std::cout << "Enter the row " << i << " :";
        temp.clear();
        for (int j = 0; j < points; j++) {
            std::cin >> value;
            temp.push_back(value);
        }
        adjacency_matrix.push_back(temp);
    }
    retirm adjacency_matrix;

}

int main() {
    int points;
    std::cout << "Enter the number of points in the graph: ";
    std::cin >> points;

    std::vector<std::vector<int>> adjacency_matrix = get_matrix(points);

}
