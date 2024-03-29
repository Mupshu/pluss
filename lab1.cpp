#include <iostream>
#include "lab_1_1.h"
#include "lab_1_2.cpp"


int main() {
    list_double_t list1;
    list_double_t list2;
    init(list1);
    init(list2);
    append(list1, 20);
    append(list2, 15);
    append(list1, list2);
    copy(list1, list2);
    std::cout << "the list1" << std::endl;
    print(list1);
    std::cout <<"the list2" << std::endl;
    print(list2);
    std::cout << "The size of list1 is:" << std::endl;
    std::cout << size(list1) << std::endl;
    clear(list1);
    clear(list2);
    return 0;
}

