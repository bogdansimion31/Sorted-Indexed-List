#include "SortedIndexedList.h"
#include "ListIterator.h"
#include <iostream>
using namespace std;
#include <exception>

void SortedIndexedList::filter(Condition cond) { //complexity worst case = best case = average case = O(n) - n = number of elements
    while (!cond(head->element)) {
        auto node = head;
        auto elem = head->element;
        head = head->next;
        delete node;
        dim--;
    }
    auto current = head;
    while (current->next) {
        if (!cond(current->next->element)) {
            auto to_destroy = current->next;
            current->next = to_destroy->next;
            delete to_destroy;
            dim--;
        } else {
            current = current->next;
        }
    }
}

SortedIndexedList::SortedIndexedList(Relation r) {
    dim = 0;
    head = nullptr;
    relation = r;
}

int SortedIndexedList::size() const {
    return dim;
}

bool SortedIndexedList::isEmpty() const {
    return dim == 0;
}

TComp SortedIndexedList::getElement(int i) const {
    if(dim <= i){
        throw std::exception();
    }
    int index = 0;
    auto current = head;
    while(index < i){
        current = current->next;
        index++;
    }
    return current->element;
}

TComp SortedIndexedList::remove(int i) {
    if(dim <= i || i < 0){
        throw std::exception();
    }
    if(i==0){
        auto node = head;
        auto elem = head->element;
        head = head->next;
        delete node;
        dim--;
        return elem;

    }
    int index = 0;
    auto current = head;
    while(index < i-1){
        current = current->next;
        index++;

    }
    auto to_destroy = current->next;
    current->next = to_destroy->next;
    auto elem = to_destroy->element;
    delete to_destroy;
    dim--;
    return elem;
}

int SortedIndexedList::search(TComp e) const {
    auto current = head;
    int index = 0;
    while(current != nullptr){
        if(current->element == e){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void SortedIndexedList::add(TComp e) {
    if(dim == 0 ){
        auto node = new SLLNode();
        node->element = e;
        node->next = nullptr;
        head = node;
        dim++;
        return;
    }
    auto previous = head;
    auto current = head;
    while(relation(current->element, e)){
        if(current->next != nullptr){
            previous = current;
            current = current->next;
        }else{
            auto node = new SLLNode();
            node->element = e;
            node->next = nullptr;
            current->next = node;
            dim++;
            return;
        }
    }
    if(previous == current){
        auto node = new SLLNode();
        node->element = e;
        node->next = current;
        head = node;
        dim++;
        return;
    }
    auto node = new SLLNode();
    node->element = e;
    node->next = current;
    previous->next = node;
    dim++;
}

ListIterator SortedIndexedList::iterator() { return ListIterator(*this); }

// destructor
SortedIndexedList::~SortedIndexedList() {
    auto current = head;
    while(current != nullptr){
        auto to_destroy = current;
        current = current->next;
        delete to_destroy;
    }
}
