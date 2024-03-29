#pragma once
#include "lab_1_1.h"
//
struct list_node_double_t {
    double data;
    list_node_double_t* next = nullptr;
};

struct list_double_t {
    list_node_double_t* head;
    list_node_double_t* tail;
    int length;
};

void init(list_double_t& list);
void clear(list_double_t& list);
list_double_t clone(list_double_t& list);
void append(list_double_t& list_1, list_double_t& list_2);
void append(list_double_t& list, double value);
int size(const list_double_t& list);
void print(const list_double_t& list);
void copy(list_double_t& list_1, list_double_t& list_2);
 //lобавит сюда все загаловки функций, создать еще один cpp, в него вписать все функции
//пусть он также будет include к этому заголовку
//в клоне сделать так, чтобы при создани нового списка создавался также ньвый узел
//при написании своего контейнера или класса, случай самокопирования - довольно странный 