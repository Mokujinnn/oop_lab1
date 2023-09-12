#include <iostream>
#include <cstdlib>

int * genRandArray(int size, int maxValue)
{
    int * arr = new int[size+1];

    if (!arr)
    {
        return nullptr;
    }

    arr[0] = size;
    for (int i = 1; i < size + 1; i++)
    {
        arr[i] = rand() % maxValue;
    }
    
    return arr;
}

int ** genRandMatrix(int size, int maxValue)
{
    int ** arr = new int*[size];

    if (!arr)
    {
        return nullptr;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = genRandArray(rand()%10, maxValue);
    }

    return arr;
}

void print(int * arr)
{
    int size = arr[0];
    std::cout << size << ": ";
    for (int i = 1; i < size + 1; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void printMatrix(int ** arr, int size)
{
    std::cout << "size matrix: " << size << '\n';
    for(int i = 0; i < size; i++)
    {
        print(arr[i]);
    }
    std::cout << '\n';
}

int main()
{
    srand(time(NULL));

    int size = rand()%10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete [] arr;

    std::cout << "---------------\n";

    size=rand()%10;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}