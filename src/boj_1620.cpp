#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

int input_count, output_count;
std::map<std::string, int> string_int_map;
std::vector<std::string> string_vector;

bool is_numeric(char input) {
    if (input >= '0' && input <= '9')
        return true;
    else
        return false;
}

int main(void) {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> input_count >> output_count;

    std::string name;
    for (int i = 0; i < input_count; i++) {
        std::cin >> name;
        string_int_map.insert(std::make_pair(name, i + 1));
        string_vector.push_back(name);
    }

    std::string key;
    std::string::iterator itor;
    std::map<std::string, int>::iterator string_int_itor;
    std::vector<std::string>::iterator string_vector_itor;
    for (int i = 0; i < output_count; i++) {
        std::cin >> key;
        itor = key.begin();
        if (is_numeric(*itor)) {
            string_vector_itor = string_vector.begin();
            int key_num = std::stoi(key);
            std::advance(string_vector_itor, key_num - 1);
            std::cout << *string_vector_itor << std::endl;
        } else {
            string_int_itor = string_int_map.find(key);
            std::cout << string_int_itor->second << std::endl;
        }
    }

    return 0;
}
