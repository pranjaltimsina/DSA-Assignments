#include <iostream>
#include <vector>
#include <queue>

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
    return adjacency_matrix;

}

std::vector<std::vector<int>> get_empty_tree(int points) {
     std::vector<std::vector<int>> tree;
     std::vector<int> temp;

    for (int i = 0; i < points; i++) {
        for (int j = 0; j < points; j++) {
            temp.push_back(0);
        }
        tree.push_back(temp);
    }
    return tree;
}


std::vector<std::vector<int>> BFS(std::vector<std::vector<int>> matrix, int points) {
    std::vector<std::vector<int>> tree = get_empty_tree(points);
    std::vector<int> explored_points;
    std::queue<int> frontier;

    frontier.push(0);

    int current;

    while (!frontier.empty()) {
        current = frontier.front();
        frontier.pop();
        explored_points.push_back(current);
        std::vector<int> connected = matrix.at(current);
        for (int i = 0; i < points; i++) {
            if (connected.at(i) == 1 && i != current) {
                frontier.push(i);
            }
        }
    }


}

int main() {
    int points;
    std::cout << "Enter the number of points in the graph: ";
    std::cin >> points;

    std::vector<std::vector<int>> adjacency_matrix = get_matrix(points);
    std::vector<std::vector<int>> tree = BFS(adjacency_matrix, points);


}
