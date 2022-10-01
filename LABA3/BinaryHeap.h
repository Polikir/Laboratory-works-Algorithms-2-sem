#include <iostream>
#include <list>
#include <cmath>
#pragma once

using namespace std;
template<typename T> class BinaryHeap
{
private:
    T* list;
    int size;



public:
    void add(T* value);
    int GetSize(){
        return size;
    }
    void Heapify(int i);
    void PrintHeap();
    T* GetItem(int ind);
    bool Find(T* value);
    void DeleteItem(T* value);
    BinaryHeap<T>* SubHeap(T* value);
    int Height(int hsize);
    int NodeHeight(int index);
    BinaryHeap<T>() {
        list = new T[0];
        size = 0;
    }
};



template<typename T> T* BinaryHeap<T> :: GetItem(int ind)
{
    return &list[ind];
}

template<typename T> void BinaryHeap<T> :: add(T* value) {
    int i, parent;
    i = size;
    list[i] = *value;
    parent = (i-1)/2;
    while(parent >= 0 && i > 0)  {
        if(list[i] > list[parent]) {
            T temp = list[i];
            list[i] = list[parent];
            list[parent] = temp;
        }
        i = parent;
        parent = (i-1)/2;
    }
    size++;
}

template<typename T> void BinaryHeap<T>:: Heapify(int i) {
    int left, right;
    T* temp;
    left = 2*i+1;
    right = 2*i+2;
    if(left < size) {
        if(list[i] < list[left]) {
            *temp = list[i];
            list[i] = list[left];
            list[left] = *temp;
            Heapify(left);
        }
    }
    if(right < size) {
        if(list[i] < list[right]) {
            *temp = list[i];
            list[i] = list[right];
            list[right] = *temp;
            Heapify(right);
        }
    }
}


template<typename T> bool BinaryHeap<T>::Find(T* value) {
    bool l = false;
    for(int i=0; i<size; i++){
        if(list[i] == *value){
            l = true;
        }
    }
    return l;
}

template<typename T> void BinaryHeap<T>::DeleteItem(T* value) {
    int i=0;
    while(list[i]!=*value){
        i++;
    }
    list[i] = list[size - 1];
    size--;
    Heapify(i);
}

template<typename T> int BinaryHeap<T>::Height(int hsize){
    int k = 0;
    int l = pow(2, k);
    while (l < hsize){
        k++;
        l+= pow(2, k);
    }
    k++;
    return k;
}

template<typename T> int BinaryHeap<T>::NodeHeight(int index){
    int k = Height(size)-Height(index++)+1;
    return k;
}

template<typename T> BinaryHeap<T>* BinaryHeap<T>::SubHeap(T* value) {
    BinaryHeap<T>* heap = new BinaryHeap<T>();
    int i = 0;
    int height = 1;
    while (list[i]!= *value)
        i++;
    heap->add(&list[i]);
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int point = l;
    int k = NodeHeight(i);
    while(height < k) {
        while((l <= r) && (l < size) ) {
            heap->add(&list[l]);
            l++;
        }
        height++;
        l = 2 * point + 1;
        r = 2 * r + 2;
    }
    return heap;
}


template<typename T> void BinaryHeap<T>::PrintHeap() {
    int i = 0;
    int k = 1;
    cout<<""<<endl;
    while(i < size) {
        while((i < k) && (i < size)) {
            cout<<ToStrings(list[i]);
            if (i!=0)
            {
                cout<<"(";
                cout<<ToStrings(list[(i-1)/2]);
                cout<<")";
            }
            cout << " ";
            i++;
        }
        cout <<" ! ";
        k = k * 2 + 1;
    cout<<""<<endl;
    }
}


















