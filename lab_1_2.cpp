#include <iostream>
#include "lab_1_1.h"


void init(list_double_t& list) {
    list.head = nullptr;
    list.tail = nullptr;
    list.length = 0;
}
void clear(list_double_t& list) {
    list_node_double_t* now = list.head;
    while (now != nullptr) {
        list_node_double_t* next_node = now->next;
        delete now;
        now = next_node;
    }
    list.head = nullptr;
    list.tail = nullptr;
    list.length = 0;
}
list_double_t clone(list_double_t& list) {
    list_double_t new_list;
    init(new_list);
    list_node_double_t* now = list.head;
    list_node_double_t* prev_node = nullptr; // Исправлено здесь
    while (now != nullptr){
        if (prev_node == nullptr) {
            new_list.head = new list_node_double_t{now->data};
            prev_node = new_list.head;
        } 
        else {
            prev_node->next = new list_node_double_t{now->data};
            prev_node = prev_node->next;
        }
        now = now->next;
        ++new_list.length; // Увеличение длины нового списка
    }
    new_list.tail = prev_node;
    return new_list;
}

void append(list_double_t& list_1, list_double_t& list_2) {
    list_double_t temp = clone(list_2);
    if (list_2.head == nullptr) 
        return;

    if (list_1.head == nullptr) {
        list_1.head = temp.head;
    } 
    else {
        list_node_double_t* tail = temp.head;
        while (tail->next !=nullptr){
            tail = tail->next;
        }
        tail->next = list_2.head;
    }
    list_1.tail = temp.tail;
    list_1.length += temp.length;

}
void append(list_double_t& list, double value) {
    list_node_double_t* new_node = new list_node_double_t;
    new_node->data = value;
    if (list.head == nullptr) {
        list.head = new_node;
    } else {
        list.tail->next = new_node;
    }
    list.tail = new_node;
    list.length++;
}
int size(const list_double_t& list){
    list_node_double_t* now = list.head;
    int count = 0;
    while (now != nullptr){
        count += 1;
        now = now -> next;
    }
    return count;
}
void print(const list_double_t& list) {
    list_node_double_t* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void copy(list_double_t& list_1, list_double_t& list_2){
    clear(list_2);
    list_2 = clone(list_1);
}