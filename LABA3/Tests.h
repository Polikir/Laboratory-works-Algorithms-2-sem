#include "Complex.h"
#include "Function.h"
#include "BinaryHeap.h"
#include "BinaryTree.h"
#include <iostream>
#include <cassert>
#pragma once
using namespace std;

int arr[] = {0,1,2,3,-3,-2,-1};
int *pointer = arr;

int arr_h[] = {0,1,2,3,-3,-2,-1};
int *pointerh = arr_h;
void Test()
{   int i;
    BinaryTree<int>* tree = new BinaryTree<int>();
    assert(tree->GetRoot() == nullptr);
    for(i=0;i<7;i++)
    {
        tree->Add(&arr[i]);
    }
    assert(*(tree->GetRoot()->Value) == arr[0]);
    assert(*(tree->GetRoot()->Right->Right->Right->Value) == arr[3]);
    assert(*(tree->GetRoot()->Left->Value) == arr[4]);

    assert(*(tree->GetRoot()->Value)==arr[0]);
    tree->DeleteFromTree(tree,&arr[0]);
    assert(*(tree->GetRoot()->Value)==arr[6]);

    tree = new BinaryTree<int>();
    for(i=0;i<7;i++)
    {
        tree->Add(&arr[i]);
    }

    assert(tree->SearchItem(tree->GetRoot(),&arr[4]));

    BinaryTree<int>* tree1 = new BinaryTree<int>();
    tree1->Add(&arr[0]);
    tree1->Add(&arr[1]);
    tree1->Add(&arr[4]);

    assert(tree->SearchTree(tree,tree1));


    tree1 = tree->Map(plusOne);
    assert(*(tree1->GetRoot()->Value) == 1);
    assert(*(tree1->GetRoot()->Right->Right->Right->Value) == 4);

    tree1 = tree->Where(BigZero);
    assert(tree1->GetRoot()->Left == nullptr);
    assert(*(tree1->GetRoot()->Right->Value) == arr[2]);

    tree1 = tree->Sub(tree,&arr[0]);
    assert(*(tree1->GetRoot()->Value) == arr[0]);
    assert(*(tree1->GetRoot()->Right->Value) == arr[1]);

    tree1 = tree->Sub(tree,&arr[1]);
    assert(*(tree1->GetRoot()->Value) == arr[1]);
    assert(*(tree1->GetRoot()->Right->Value) == arr[2]);



    complex c0 = complex(0,0);
    complex c1 = complex(1,2);
    complex c2 = complex(0,1);
    complex c3 = complex(3,3);
    complex c4 = complex(-2,0);
    complex c5 = complex(-1,1);
    complex c6 = complex(7,7);
    complex arr_com[] = {c0,c1,c2,c3,c4,c5};
    complex *com_pointer = arr_com;

    BinaryTree<complex>* treec = new BinaryTree<complex>();
    for(i=0;i<6;i++)
    {
       treec->Add(&arr_com[i]);
    }

    assert(*(treec->GetRoot()->Value) == c0);
    assert(*(treec->GetRoot()->Right->Left->Value) == c2);
    assert(treec->GetRoot()->Right->Value->real == 1);
    assert(treec->GetRoot()->Right->Value->image == 2);


    treec->DeleteFromTree(treec,&arr_com[0]);
    assert(*(treec->GetRoot()->Value)==arr_com[5]);
    assert(treec->GetRoot()->Left->Right == nullptr);

    treec = new BinaryTree<complex>();
    assert(treec->GetRoot() == nullptr);
    for(i=0;i<6;i++)
    {
        treec->Add(&arr_com[i]);
    }

    assert(treec->SearchItem(treec->GetRoot(), &c1));
    assert(treec->SearchItem(treec->GetRoot(),&c6) == false);

    BinaryTree<complex>* treec1 = new BinaryTree<complex>();
    treec1->Add(&c1);
    treec1->Add(&c2);
    treec1->Add(&c3);
    assert(treec->SearchTree(treec,treec1));

    treec1 = new BinaryTree<complex>();
    treec1->Add(&c4);
    treec1->Add(&c1);
    assert(!(treec->SearchTree(treec,treec1)));

    treec1 = treec->Map(plusOne);
    assert(*(treec1->GetRoot()->Value) == complex(1,0));
    assert(*(treec1->GetRoot()->Left->Value) == complex(-1,0));

    treec1 = treec->Where(BigZero);
    assert(*(treec1->GetRoot()->Value)==c1);
    assert(*(treec1->GetRoot()->Right->Value) == c3);

    treec1 = treec->Sub(treec,&c1);
    assert(*(treec1->GetRoot()->Value) == c1);
    assert(*(treec1->GetRoot()->Right->Value) == c3);

    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for (i=0;i<7;i++)
    {
        heap->add(&arr_h[i]);
    }

    assert(heap->GetSize() == 7);
    assert(*(heap->GetItem(0)) == 3);


    heap->DeleteItem(heap->GetItem(4));
    assert(heap->GetSize() == 6);

    BinaryHeap<int>* heap1 = new BinaryHeap<int>();
    heap1 = heap->SubHeap(&arr_h[2]);
    assert(heap1->GetSize());

    assert(heap->Find(heap->GetItem(0)));

    BinaryHeap<complex>* heapc = new BinaryHeap<complex>();
    for(i=0;i<6;i++)
    {
       heapc->add(&arr_com[i]);
    }

    assert(heapc->GetSize() == 6);
    assert(*(heapc->GetItem(0)) == c3);


    heapc->DeleteItem(heapc->GetItem(4));
    assert(heapc->GetSize() == 5);
    assert(heapc->Find(&c1));
    assert(!(heapc->Find(&c6)));
    cout<<"Tests completed"<<endl;
}
