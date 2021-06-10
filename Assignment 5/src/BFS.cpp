#include <iostream>
#include <vector>
#include <queue>

int** get_matrix(int points) {

    int** matrix = 0;
    matrix = new int*[points];

    int value;

    for (int i = 0; i < points; i++) {
        std::cout << "Enter the row " << i << ": ";
        matrix[i] = new int[points];
        for (int j = 0; j < points; j++) {
            std::cin >> value;
            matrix[i][j] = value;
        }
    }
    return matrix;
}

int** get_empty_tree(int points) {
    int** matrix = 0;
    matrix = new int*[points];


    for (int i = 0; i < points; i++) {
        matrix[i] = new int[points];
        for (int j = 0; j < points; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}


int** BFS(int**matrix, int points) {
    int** tree = get_empty_tree(points);
    std::vector<bool> explored_points(points, false);
    std::queue<int> frontier;

    frontier.push(0);
    explored_points[0] = true;

    int current;

    while (!frontier.empty()) {
        current = frontier.front();
        std::cout << current << " from frontier\n";
        frontier.pop();
        explored_points[current] = true;

        for (int i = 0; i < points; i++) {
            int flag = 1;
            if (matrix[current][i] == 1 && !explored_points[i]) {
                frontier.push(i);
                explored_points[i] = true;
            }
        }
    }

    return tree;

}

int main() {
    int points;
    std::cout << "Enter the number of points in the graph: ";
    std::cin >> points;

    int** adjacency_matrix = get_matrix(points);
    int** tree = BFS(adjacency_matrix, points);

    for (int i = 0; i < points; i++) {
        for (int j = 0; j < points; j++) {
            std::cout << tree[i][j] << " ";
        }
        std::cout << "\n";
    }
}
