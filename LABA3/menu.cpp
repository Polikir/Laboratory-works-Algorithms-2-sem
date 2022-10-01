
#include "Menu.h"



void PrintMenuTree()
{
	cout << "----Tree Menu----" << endl;
	cout << "1. Add Element." << endl;
	cout << "2. Print Tree." << endl;
	cout << "3. Map. (+1)" << endl;
	cout << "4. Where. (>0)" << endl;
	cout << "5. Sub tree." << endl;
	cout << "6. Search Element." << endl;
	cout << "7. Search SubTree." << endl;
	cout << "8. Delete Element."<<endl;
	cout << "9. Exit." << endl;

}

void PrintMenuHeap()
{
	cout << "----Menu Heap----" << endl;
	cout << "1. Add Element." << endl;
    cout << "2. Delete Element."<<endl;
	cout << "3. Print Heap." << endl;
	cout << "4. Find Element" << endl;
	cout << "5. Sub SubHeap." << endl;
    cout << "6. Exit." << endl;
}


void menuFloatTree()
{
	int choice = 0;
	BinaryTree<float>* tree = new BinaryTree<float>();
	BinaryTree<float>* tree2 = new BinaryTree<float>();
	BinaryTree<float>* tree3 = new BinaryTree<float>();
	BinaryTree<float>* tree4 = new BinaryTree<float>();
	BinaryTree<float>* tree5 = new BinaryTree<float>();
	BinaryTree<float>* tree6 = new BinaryTree<float>();
	float *f = new float;
	float* f1 = new float;
	float * f2 = new float;
	float *f3 = new float;
    float *f4 = new float;
	while (choice != 9) {

		PrintMenuTree();
		cin >> choice;
		int i = 1;
		int j = 1;

		switch (choice)
		{
		case 1:
			while (i == 1)
			{
				f = new float;
				cout << "Enter a number" << endl;
				cin >> *f;
				tree->Add(f);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> i;
			}
			break;
		case 2:
			tree->PrintTree(tree);
			break;
		case 3:
			tree2 = tree->Map(plusOne);
			tree2->PrintTree(tree2);
			break;
		case 4:
			tree3 = tree->Where(BigZero);
			tree3->PrintTree(tree3);
			break;
		case 5:
			cout << "Enter the slice element:" << endl;
			cin >> *f1;
			tree4 = tree->Sub(tree, f1);
			tree4->PrintTree(tree4);
			break;
		case 6:
			cout << "Enter a number to search for:" << endl;
			cin >> *f2;
			if (tree->SearchItem(tree->GetRoot(), f2))
				cout << "Number found." << endl;
			else
				cout << "Number not found." << endl;
			break;
		case 7:
            tree5 = new BinaryTree<float>();
			while (j == 1) {
				f3 = new float;
				cout << "Enter a number." << endl;
				cin >> *f3;
				tree5->Add(f3);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> j;
			}

			if (tree->SearchTree(tree, tree5))
				cout << "Subtree found." << endl;
			else
				cout << "Subtree not found." << endl;
			break;
        case 8:
            //
            cout<<"Enter a number to delete"<<endl;
            cin>>*f4;
            tree->DeleteFromTree(tree,f4);
            break;
		case 9:
			break;
		default:
			cout << "Oooops!" << endl;
			break;
		}
	}
}

void menuComplexTree()
{
	int choice = 0;
	BinaryTree<complex>* tree = new BinaryTree<complex>();
	BinaryTree<complex>* tree2 = new BinaryTree<complex>();
	BinaryTree<complex>* tree3 = new BinaryTree<complex>();
	BinaryTree<complex>* tree4 = new BinaryTree<complex>();
	BinaryTree<complex>* tree5 = new BinaryTree<complex>();
	complex *f1 = new complex(0, 0);
	complex *f2 = new complex(0, 0);
	complex *f3 = new complex(0, 0);
	complex *f4 = new complex(0, 0);
	complex *f = new complex(0, 0);

	while (choice != 9) {

		PrintMenuTree();
		cin >> choice;
		int k = 1;
		int j = 1;

		double r = 0, i = 0;
		double r1 = 0, i1 = 0;
		double r2 = 0, i2 = 0;
		double r3 = 0, i3 = 0;
		double r4 = 0, i4 = 0;

		switch (choice)
		{
		case 1:
			while (k == 1) {
				f = new complex(0, 0);
				cout << "Enter a complex number." << endl;
				cout << "Enter a real part: ";
				cin >> r;
				cout << "Enter am imagine part: ";
				cin >> i;
				f->cin(r, i);
				tree->Add(f);
				cout << "Add another complex number\n1. Yes.\n0. No." << endl;
				cin >> k;
			}
			break;
		case 2:
			tree->PrintTree(tree);
			break;
		case 3:

			tree2 = tree->Map(plusOne);
			tree2->PrintTree(tree2);
			break;
		case 4:

			tree3 = tree->Where(BigZero);
			tree3->PrintTree(tree3);
			break;
		case 5:

			cout << "Enter a complex slice number:" << endl;
			cout << "Enter a real part: ";
			cin >> r1;
			cout << "Enter an imagine part: ";
			cin >> i1;
			f1->cin(r1, i1);
			tree4 = tree->Sub(tree, f1);
			tree4->PrintTree(tree4);
			break;
		case 6:
			cout << "Enter a number to search for:" << endl;
			cout << "Enter a real part: ";
			cin >> r2;
			cout << "Enter an imagine part: ";
			cin >> i2;
			f2->cin(r2, i2);
			if ((tree->SearchItem(tree->GetRoot(), f2)))
				cout << "Number found." << endl;
			else
				cout << "Number not found." << endl;
			break;
		case 7:
            tree5 = new BinaryTree<complex>();
			while (j == 1) {
                cout << "Enter a complex number." << endl;
                cout << "Enter a real part: ";
                cin >> r3;
                cout << "Enter an imagine part: ";
                cin >> i3;
				f3->cin(r3, i3);
				tree5->Add(f3);
				cout << " Add another number\n1. Yes.\n0. No." << endl;
				cin >> j;
			}
			if ((tree->SearchTree(tree, tree5))){
				cout << "Subtree found." << endl;
			}
			else
				cout << "Subtree not found." << endl;
			break;
        case 8:
            cout<<"Enter a number to delete"<<endl;
            cout << "Enter a real part: ";
            cin >> r4;
            cout << "Enter an imagine part: ";
            cin >> i4;
            f4->cin(r4, i4);
            tree->DeleteFromTree(tree,f4);
            break;
		case 9:
			break;
		default:
			cout << "Ooops" << endl;
			break;
		}
	}
}

void menuIntTree()
{
	int choice = 0;
	BinaryTree<int>* tree = new BinaryTree<int>();
	BinaryTree<int>* tree2 = new BinaryTree<int>();
	BinaryTree<int>* tree3 = new BinaryTree<int>();
	BinaryTree<int>* tree4 = new BinaryTree<int>();
	BinaryTree<int>* tree5 = new BinaryTree<int>();
	BinaryTree<int>* tree6 = new BinaryTree<int>();
	int *f = new int;
	int * f1 = new int;
    int * f2 = new int;
    int *f3 = new int;
    int *f4 = new int;
	while (choice != 9) {

		PrintMenuTree();
		cin >> choice;
		int i = 1;
		int j = 1;

		switch (choice)
		{
		case 1:
			while (i == 1)
			{
				f = new int;
				cout << "Enter a number" << endl;
				cin >> *f;
				tree->Add(f);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> i;
			}
			break;
		case 2:
			tree->PrintTree(tree);
			break;
		case 3:
			tree2 = tree->Map(plusOne);
			tree2->PrintTree(tree2);
			break;
		case 4:
			tree3 = tree->Where(BigZero);
			tree3->PrintTree(tree3);
			break;
		case 5:
			cout << "Enter the slice element:" << endl;
			cin >> *f1;
			tree4 = tree->Sub(tree, f1);
			tree4->PrintTree(tree4);
			break;
		case 6:
			cout << "Enter a number to search for:" << endl;
			cin >> *f2;
			if (tree->SearchItem(tree->GetRoot(), f2))
				cout << "Number found." << endl;
			else
				cout << "Number not found." << endl;
			break;
		case 7:
        tree5 = new BinaryTree<int>();
			while (j == 1) {
				f3 = new int;
				cout << "Enter a number." << endl;
				cin >> *f3;
				tree5->Add(f3);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> j;
			}

			if (tree->SearchTree(tree, tree5))
				cout << "Subtree found." << endl;
			else
				cout << "Subtree not found." << endl;
			break;
        case 8:
            //
            cout<<"Enter a number to delete"<<endl;
            cin>>*f4;
            tree->DeleteFromTree(tree,f4);
            break;
		case 9:
			break;
		default:
			cout << "Ooops!" << endl;
			break;
		}
	}
}


void menuFloatHeap()
{
    int choice = 0;
	auto* heap = new BinaryHeap<float>();
	auto* heap1 = new BinaryHeap<float>();
	float *fh = new float;
    float *fh1 = new float;
    float *fh2 = new float;
    float *fh3 = new float;
	while (choice != 6) {

		PrintMenuHeap();
		cin >> choice;
		int i = 1;
		int j = 1;

		switch (choice)
		{
		case 1:
			while (i == 1)
			{
				cout << "Enter a number" << endl;
				cin >> *fh;
				heap->add(fh);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> i;
			}
			break;
        case 2:
            cout<<"Enter a number"<<endl;
			cin>>*fh1;
			heap->DeleteItem(fh1);
			break;
        case 3:
            heap->PrintHeap();
            cout<<""<<endl;
            break;

		case 4:
            cout << "Enter a number" << endl;
            cin >> *fh2;
		    if (heap->Find(fh2))
            {
                cout<<"Number found"<<endl;
            }
            else
            {
                cout<<"Number not found"<<endl;
            }
            break;
        case 5:
            cout << "Enter a number" << endl;
            cin >> *fh3;
            heap1 = heap->SubHeap(fh3);
            heap1->PrintHeap();
            break;
			}}
}


void menuComplexHeap()
{
    int choice = 0;
	auto* heap = new BinaryHeap<complex>();
	auto* heap1 = new BinaryHeap<complex>();
	complex *fh1 = new complex(0, 0);
	complex *fh2 = new complex(0, 0);
    complex *fh3 = new complex(0, 0);
	complex *fh = new complex(0, 0);
	while (choice != 6) {

		PrintMenuHeap();
		cin >> choice;
		int i = 1;
		int j = 1;
        double r0 = 0, i0 = 0;
		double r1 = 0, i1 = 0;
		double r2 = 0, i2 = 0;
		double r3 = 0, i3 = 0;
		switch (choice)
		{
		case 1:
			while (i == 1)
			{   cout << "Enter a complex number." << endl;
				cout << "Enter a real part: ";
				cin >> r0;
				cout << "Enter am imagine part: ";
				cin >> i0;
				fh->cin(r0, i0);
				heap->add(fh);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> i;
			}
			break;
        case 2:
            cout << "Enter a complex number." << endl;
            cout << "Enter a real part: ";
            cin >> r1;
            cout << "Enter am imagine part: ";
            cin >> i1;
            fh1->cin(r1, i1);
			heap->DeleteItem(fh1);
			break;
        case 3:
            heap->PrintHeap();
            cout<<""<<endl;
            break;

		case 4:
            cout << "Enter a complex number." << endl;
            cout << "Enter a real part: ";
            cin >> r2;
            cout << "Enter am imagine part: ";
            cin >> i2;
            fh2->cin(r2, i2);
		    if (heap->Find(fh2))
            {
                cout<<"Number found"<<endl;
            }
            else
            {
                cout<<"Number not found"<<endl;
            }
            break;
        case 5:
            cout << "Enter a complex number." << endl;
            cout << "Enter a real part: ";
            cin >> r3;
            cout << "Enter am imagine part: ";
            cin >> i3;
            fh2->cin(r3, i3);
            heap1 = heap->SubHeap(fh3);
            heap1->PrintHeap();
            break;
			}}
}

void menuIntHeap()
{
    int choice = 0;
	auto* heap = new BinaryHeap<int>();
	auto* heap1 = new BinaryHeap<int>();
	//BinaryTree<int>* tree2 = new BinaryTree<int>();
	//BinaryTree<int>* tree3 = new BinaryTree<int>();
	//BinaryTree<int>* tree4 = new BinaryTree<int>();
	//BinaryTree<int>* tree5 = new BinaryTree<int>();
	//BinaryTree<int>* tree6 = new BinaryTree<int>();
	//int f =  int;
	int *fh = new int;
    int *fh1 = new int;
    int *fh2 = new int;
    int *fh3 = new int;
//    int *f3 = new int;
//    int *f4 = new int;
	while (choice != 6) {

		PrintMenuHeap();
		cin >> choice;
		int i = 1;
		int j = 1;

		switch (choice)
		{
		case 1:
			while (i == 1)
			{
				cout << "Enter a number" << endl;
				cin >> *fh;
				heap->add(fh);
				cout << "Add another number \n1. Yes.\n0. No." << endl;
				cin >> i;
			}
			break;
        case 2:
            cout<<"Enter a number"<<endl;
			cin>>*fh1;
			heap->DeleteItem(fh1);
			break;
        case 3:
            heap->PrintHeap();
            cout<<""<<endl;
            break;

		case 4:
            cout << "Enter a number" << endl;
            cin >> *fh2;
		    if (heap->Find(fh2))
            {
                cout<<"Number found"<<endl;
            }
            else
            {
                cout<<"Number not found"<<endl;
            }
            break;
        case 5:
            cout << "Enter a number" << endl;
            cin >> *fh3;
            heap1 = heap->SubHeap(fh3);
            heap1->PrintHeap();
            break;
			}}
}

void menuTree()
{   int choice = 0 ;
    cout << "Select a type:" << endl;
    cout << "1. Float\n2. Complex\n3. Integer" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		menuFloatTree();
		break;
	case 2:
		menuComplexTree();
		break;
	case 3:
		menuIntTree();
		break;
	default:
		cout << "Ooops!" << endl;

}}

void menuHeap()
{   int choice = 0 ;
    cout << "Select a type:" << endl;
    cout << "1. Float\n2. Complex\n3. Integer" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		menuFloatHeap();
		break;
	case 2:
		menuComplexHeap();
		break;
	case 3:
		menuIntHeap();
		break;
	default:
		cout << "Ooops!" << endl;
}}


void menu()
{
	int choice = 0 ;
	cout << "-Menu-" << endl;
	cout << "Select a type:" << endl;
    cout<<"1.Binary Tree\n2.Binary Heap."<<endl;
    cin >> choice;
    switch (choice)
	{
	case 1:
		menuTree();
		break;
	case 2:
		menuHeap();
		break;
	default:
		cout << "Ooops!" << endl;
		break;
	}

}


