
#pragma once
#include<iterator>
#include "DinamicArray.h"
template<typename T> class LinkedList
{
private:
    class Node
    {
    public:
        T item;
        Node* pnext;

        Node(T item = T(), Node* pnext = nullptr) {
            this->item = item;
            this->pnext = pnext;
        };
    };
    Node* head;
    int size;

public:

    LinkedList();
    LinkedList(T* arr, int count);
    LinkedList(const LinkedList<T>& list);


    int GetLength() const;
    T GetFirst() const;
    T GetLast() const;
    T Get(int index) const;
    LinkedList<T>* GetSublist(int start, int end) const;



    void Set(int index, T value);
    void Append(T value);
    void Prepend(T value);
    void InsertAt(T value, int index);
    LinkedList<T>* Concat(LinkedList<T>* list);

    ~LinkedList() = default;
};



template<typename T> LinkedList<T>::LinkedList() :size(0) {
    this->size = 0;
    this->head = nullptr;
}

template<typename T>LinkedList<T>::LinkedList(const LinkedList<T>& list) : LinkedList() {
    for (int i=0; i<list.GetLength(); i++) {
        this->Append(list.Get(i));
    }
}

template<typename T> LinkedList<T>::LinkedList(T* arr, int count) : LinkedList() {
    if (count<0) {
        throw length_error("Negative size!");
    }
    for (int i =0; i<count; i++) {
        this->Append(arr[i]);
    }
}



template<typename T> int LinkedList<T>::GetLength() const {
    return this->size;
}

template<typename T> T LinkedList<T>::GetFirst() const {
    if (this->GetLength()==0) {
        throw out_of_range("Index out of range!");
    }
    return Get(0);
}

template<typename T> T LinkedList<T>::GetLast() const {
    if (this->GetLength()==0) {
        throw out_of_range("Index out of range!");
    }
    return Get(this->size-1);
}

template<typename T>
T LinkedList<T>::Get(int index) const {
    if (index <0 || index >= this->size) {
        throw out_of_range("Index out of range!");
    }
    int sch = 0;
    Node* temp;
    temp = this->head;
    while (temp != nullptr) {
        if (sch == index) {
            return temp->item;
        }
        temp = temp ->pnext;
        ++sch;
    }
}

template<typename T> LinkedList<T>* LinkedList<T>::GetSublist(int start, int end) const {
    if (start<0 || start>=this->size || end<0 || end >=this->size || end<start) {
        throw out_of_range("Index out of range!");
    }
    LinkedList<T>* nList = new LinkedList<int>();
    for (int i=start; i<=end; i++) {
        nList->Append(this->Get(i));
    }
    nList->size = end-start+1;
    return nList;
}



template<typename T> void LinkedList<T>::Set(int index, T value) {
    if (index <0 || index > this->size-1) {
        throw out_of_range("Index out of range!");
    }
    Node* temp = this->head;
    for (int i=0; i<index; i++) {
        temp = temp->pnext;
    }
    temp->item = value;
};

template<typename T> void LinkedList<T>::Append(T value) {
    if (head == nullptr)
        head = new Node(value);
    else {
        Node* temp;
        temp = head;
        while (temp->pnext != nullptr) {
            temp = temp->pnext;
        }
        temp->pnext = new Node(value);
    }
    ++size;
}

template<typename T> void LinkedList<T>::Prepend(T value) {
    this->size++;
    this->head = new Node(value, this->head);
}

template<typename T> void LinkedList<T>::InsertAt(T value, int index) {
    if (index <0 || index >= this->size) {
        throw out_of_range("Index out of range!");
    }
    if (index ==0) {
        Prepend(value);
    }
    else  {
        Node* temp = this->head;
        for (int i=0; i<index-1; i++) {
            temp = temp->pnext;
        }
        Node* NewOne = new Node(value, temp->pnext);
        temp->pnext = NewOne;
        this->size++;
    }
}

template<typename T> LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) { //IMPROVED
    LinkedList<T>* result = new LinkedList<T>();
    result->head=this->head;
    Node* temp = this->head;
    for (int i=0; i<this->size-1; i++) {
        temp = temp->pnext;
    }
    result->size=this->size+list->size;
    temp->pnext =list->head;
    return result;
}


