#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdexcept>


class QuickSort
{
private:
    int l;
    int r;
    void SortPrivate(int array[], int l, int r);
   
public:
    QuickSort() {}
    ~QuickSort() {}
    void Sort(int array[], int size);
};


void QuickSort::Sort(int array[], int size)
{
    SortPrivate(array, 0, size - 1);
}

void QuickSort::SortPrivate(int array[], int l, int r)
{
    
    if (!std::cin)
    {
        throw std::exception("Incorrect data!");
    }
    if (r < 0)
    {
        throw std::exception("Array must not equal NULL or array is empty!");
    }



    int pivot = array[(l + r) / 2];
    int i = l;
    int j = r;



    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;

        }
        while (array[j] > pivot)
        {
            j--;

        }

        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }

    }

    if (l < j)
    {
        SortPrivate(array, l , j);

    }
    if (r > i)
    {
        SortPrivate(array, i, r);
    }


}


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


int main()
{
    int N;
    std::cout << "Plese enter the number of elements in the array:" << " ";
    std::cin >> N;
    int* Array = new int[N];
    
    QuickSort Q;
    try
    {
        
        input(Array, N);
        std::cout << "Before sorting" << std::endl;
        print(Array, N);

        std::cout << std::endl;

        std::cout << "After sorting" << std::endl;
        Q.Sort(Array, N);
        print(Array, N);
        std::cout << std::endl;

    }
    catch (const std::exception &p1)
    {
        std::cout << "Error: " << p1.what() << std::endl;
    }
   
    delete[] Array;
    Q.~QuickSort();

    return 0;
}
