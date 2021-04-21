#pragma once
#include "SortedIndexedList.h"

// DO NOT CHANGE THIS PART
class ListIterator {
    friend class SortedIndexedList;

  private:
    const SortedIndexedList &list;
    explicit ListIterator(const SortedIndexedList &list);
    SortedIndexedList::SLLNode* current;
    struct SLLPreviousNode {
        SortedIndexedList::SLLNode* node;
        SLLPreviousNode* previous_node;
    };
    SLLPreviousNode* previous_elem;
    void clear_previous_nodes();

  public:
    void first();
    void next();
    void previous();
    bool valid() const;
    TComp getCurrent() const;
    ~ListIterator();
};
