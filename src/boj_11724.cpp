#include <iostream>
#include <map>

enum node_state {
    UNLINKED,
    LINKED,
};

std::map<int, bool> remain_vertex;
int **node_map;
int vertex_count, edge_count, link_count;

void init_node_map() {
    std::cin >> vertex_count >> edge_count;

    node_map = new int *[vertex_count + 1];
    for (int i = 0; i < vertex_count + 1; i++) {
        node_map[i] = new int[vertex_count + 1];
    }

    for (int i = 0; i < vertex_count + 1; i++) {
        for (int j = 0; j < vertex_count + 1; j++) {
            std::cout << node_map[i][j];
        }
        std::cout << std::endl;
    }
}

void init_edge() {
    int vertex_a, vertex_b;

    std::cin >> vertex_a >> vertex_b;
    node_map[vertex_a][vertex_b] = LINKED;
    node_map[vertex_b][vertex_a] = LINKED;
}

void init_remain_vertex() {
    for (int i = 1; i <= vertex_count; i++) {
        remain_vertex.insert(std::make_pair(i, true));
    }
}

void count_link() {
    while (remain_vertex.size() != 0) {
        std::map<int,bool>::iterator iter = remain_vertex.begin();
        std::pair<int, bool> current_vertex = *iter;
        remain_vertex.erase(iter);

        flood_fill();
        link_count++;
    }
}

int main(void) {
    init_node_map();
    init_edge();
    init_remain_vertex();
    count_link();

    return 0;
}