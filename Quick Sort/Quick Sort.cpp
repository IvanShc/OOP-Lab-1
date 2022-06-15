#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdexcept>

class Sorting
{
public:
    Sorting()
    {
        std::cout << "Constructor" << std::endl;
    }
    ~Sorting() 
    {
        std::cout << "Garbage cleaning" << std::endl;
    }
    int quicksort(int A[], int l, int r);
};

void Input_Array(int* A, int &N)
{
    for (int i = 0; i < N ; i++)
    {
        std::cin >> A[i];
    }
}

void Output_Array(int* A, int &N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << A[i] << " ";
    }
}


int Sorting::quicksort(int A[], int l, int r)
{
    if (!std::cin)
    {
        throw std::exception("Incorrect data!");
    }
    if  (r < 0)
    {
        throw std::exception("Array must not equal NULL or array is empty!");
    }
    
  
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
            return quicksort(A, l, j);
        }

        if (r > i)
        {
            return quicksort(A, i, r);
        }
}




int main()
{
    int N;
    std::cout << "Plese enter the number of elements in the array:" << " ";
    std::cin >> N;
    int* Array = new int[N];
    Sorting Q;
    try
    {
        
        Input_Array(Array, N);
        std::cout << "Before sorting" << std::endl;
        Output_Array(Array, N);

        std::cout << std::endl;

        std::cout << "After sorting" << std::endl;
        Q.quicksort(Array, 0, N - 1);
        Output_Array(Array, N);
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
