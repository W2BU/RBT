#include <MyMap.cpp>
#include <vector>

int main() {
    MyMap<int, int> map = {{55, 55}, {40, 40}, {65, 65}, {60, 60}, {75, 75}};
    std::cout << "\nKeys:\n";
    map.printKeys();
    std::cout << "\nValues:\n";
    map.printValues();
    map.insert(57, 57);
    std::cout << "\nKeys after insertion of 57:\n";
    map.printKeys();
    map.remove(40);
    std::cout << "\nKeys after removing of 40:\n";
    map.printKeys();
    std::cout << "\nList of keys:\n";
    std::vector<int> keys = map.get_keys();
    for (auto i: keys) std::cout << i << ' '; 
    std::cout << "\nList of values:\n";
    std::vector<int> values = map.get_values();
    for (auto i: values) std::cout << i << ' ';
    std::cout << "\nAttempted to find key 45:\n";
    try {
        map.find(45);
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << "\n";
    }
    std::cout << "\nValue of node with key 65:\n";
    std::cout << map.find(65) << std::endl;
    system("pause");
}