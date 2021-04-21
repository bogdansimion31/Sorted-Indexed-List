#include <cassert>

#include "ListIterator.h"
#include "SortedIndexedList.h"

using namespace std;

bool relation1(TComp e1, TComp e2) { return e1 <= e2; }
bool condition1(TComp e) { return e % 2; }

void testAll() {
    SortedIndexedList list = SortedIndexedList(relation1);
    assert(list.size() == 0);
    assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());

    list.add(1);
    list.add(4);
    list.add(5);
    list.add(2);
    list.add(7);
    list.filter(condition1);
    assert(list.size() == 3);

}
