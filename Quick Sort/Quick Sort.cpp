#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdexcept>


class Sorting
{
private:
    int l;
    int r;
    void quicksort(int A[], int l, int r);
    
public:
    Sorting(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
    ~Sorting() {}

    void QuickSort(int A[]);
};



void input(int* m, int& n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i];
    }

}


void print(int* m, int& n)
{
    for (int i = 0; i < n; i++)
    {
    
        std::cout << m[i] << " ";
    }
}

void Sorting::QuickSort(int A[])
{
    quicksort(A, l, r);
}


void Sorting::quicksort(int A[], int l, int r)
{
    if (!std::cin)
    {
        throw std::exception("Incorrect data!");
    }
    if (r < 0)
    {
        throw std::exception("Array must not equal NULL or array is empty!");
    }



    this->l = l;
    this->l = r;


    int pivot = A[(l + r) / 2];
    int i = l;
    int j = r;



    while (i <= j)
    {
        while (A[i] < pivot)
        {
            i++;

        }
        while (A[j] > pivot)
        {
            j--;

        }

        if (i <= j)
        {
            std::swap(A[i], A[j]);
            i++;
            j--;
        }

    }

    if (l < j)
    {
        quicksort(A, l, j);

    }
    if (r > i)
    {
        quicksort(A, i, r);
    }

}



int main()
{
    int N;
    std::cout << "Plese enter the number of elements in the array:" << " ";
    std::cin >> N;
    int* Array = new int[N];
    
    Sorting Q(0, N - 1);
    try
    {
        
        input(Array, N);
        std::cout << "Before sorting" << std::endl;
        print(Array, N);

        std::cout << std::endl;

        std::cout << "After sorting" << std::endl;
        Q.QuickSort(Array);
        print(Array, N);
        std::cout << std::endl;

    }
    catch (const std::exception &p1)
    {
        std::cout << "Error: " << p1.what() << std::endl;
    }
    
    delete[] Array;
    Q.~Sorting();

    return 0;
}
