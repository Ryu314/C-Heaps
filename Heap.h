//
// Created by R Yu on 11/18/2020.
//

#ifndef HOMEWORK_10_HEAP_H
#define HOMEWORK_10_HEAP_H
#include <iostream>
#include <array>
#include <cmath>
using namespace std;

template<class T>
class Heap{
private:
    T *a;
    int len;
    int size;
public:
    explicit Heap(int x){
        len = 0;
        size = x;
        a = new T[size]{0};
    }
    void insert(T x){
        len = len + 1;
        T *arr = a;
        if(len > size){
            size = size * 2;
            a = new T[size]{0};
            for(int i = 0; i < size/2; i++){
                a[i] = arr[i];
            }
        }
        int i = len - 1;
        //cout << "i: " << i << ", floor(i/2): " << int(floor(i/2)) << ", x: " << x << endl;
        //cout << "Before: a[i]: " << a[i] << ", a[floor(i/2): " << a[int(floor(i/2))] <<endl;
        while(i > 0 and a[int(floor((i-1)/2))] > x){
            a[i] = a[int(floor((i-1)/2))];
            i = int(floor((i-1)/2));
        }

        //cout << "After: a[i]: " << a[i] << ", a[floor(i/2): " << a[int(floor(i/2))] << ", i = " << i << endl;
        a[i] = x;
    }
    void insert2(T x){
        a[len] = x;
        len = len + 1;
        T *arr = a;
        if(len > size){
            size = size * 2;
            a = new T[size]{0};
            for(int i = 0; i < size/2; i++){
                a[i] = arr[i];
            }
        }
    }
    void Heapify(int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest;
        if(l <= len-1 and a[l] < a[i]){
            smallest = l;
        }
        else{
            smallest = i;
        }
        if(r <= len-1 and a[r] < a[smallest]){
            smallest = r;
        }
        if(smallest != i){
            int temp = a[i];
            a[i] = a[smallest];
            a[smallest] = temp;
            //cout << "Heapify: (smallest =  " << smallest << "): ";
            //printHeap();
            Heapify(smallest);
        }
    }
    T min(){
        return a[0];
    }
    void deleteMin(){
        if(len == 0){
            return;
        }
        else{
            a[0] = a[len - 1];
            a[len - 1] = 0;
            len = len - 1;
            //cout << "Length: " << len << endl;
            //printHeap();
            Heapify(0);
        }
    }

    void buildHeap(){

        for(int i = int(floor((len - 1) / 2)) - 1; i >= 0; i--){
            //cout << "i: " << i << endl;
            Heapify(i);
        }
    }
    void printHeap(){
        for(int i = 0; i < size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
#endif //HOMEWORK_10_HEAP_H
