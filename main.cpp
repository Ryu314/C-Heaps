#include <iostream>
#include "Heap.h"
#include <cmath>
using namespace std;
int main() {
    Heap<int> h = Heap<int>(10);
    /*h.insert(10);
    h.insert(1);
    h.insert(5);
    h.insert(4);
    h.insert(2);
    h.insert(7);
    h.insert(8);
    h.insert(30);
    h.insert(6);
    h.insert(9);
    h.insert(15);
    cout << h.min() << endl;
    h.printHeap();
    h.deleteMin();
    h.printHeap();
    h.printHeap();*/
    h.insert2(2);
    h.insert2(8);
    h.insert2(6);
    h.insert2(1);
    h.insert2(18);
    h.insert2(15);
    h.insert2(3);
    h.insert2(12);
    h.insert2(11);
    h.insert2(17);
    h.insert(9);
    h.buildHeap();
    h.printHeap();
    return 0;
}
