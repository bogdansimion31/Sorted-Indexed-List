#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList &list) : list(list) {
    current = list.head;
    previous_elem = nullptr;
}

void ListIterator::first() {
    current = list.head;
    clear_previous_nodes();
}

void ListIterator::next() {
    if (!valid())
        throw std::exception();
    auto elem = new SLLPreviousNode();
    elem->node = current;
    elem->previous_node = previous_elem;
    current = current->next;
}

bool ListIterator::valid() const { return current != nullptr; }

TComp ListIterator::getCurrent() const {
    if (!valid())
        throw std::exception();
    return current->element;
}
void ListIterator::previous() {
    if (!valid())
        throw std::exception();
    if (current == list.head) {
        current = nullptr;
        return;
    }
    current = previous_elem->node;
    auto current_elem = previous_elem;
    previous_elem = previous_elem->previous_node;
    delete current_elem;
}
void ListIterator::clear_previous_nodes() {
    auto current_elem = previous_elem;
    while (current_elem != nullptr) {
        auto to_destroy = current_elem;
        current_elem = current_elem->previous_node;
        delete to_destroy;
    }
    previous_elem = nullptr;
}
ListIterator::~ListIterator() {
    clear_previous_nodes();
}
