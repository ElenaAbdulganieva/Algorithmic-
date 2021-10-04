# include "TXlib.h"

void FillArray  (int data [], int size, int start, int step);
void PrintArray (int data [], int size, const char title []);
void FillArray_11 (int data [], int size);
void FillArray_12 (int data [], int size);
void FillArray_13 (int data [], int size);

int main ()
    {
    int data [100] = {};

    FillArray_13  (data, 20);
    PrintArray (data, 20, "ѕосле заполнени€");

    $d;

    // $(data); макрос распечатки массива
    return 0;
    }

void FillArray (int data [], int size, int start, int step)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i     && i < size);
        //assert (0 <= i - 1 && i - 1 < size);
        data [i] = start + i * step;
        }
    }

void PrintArray (int data [], int size, const char title [])
    {
    $y; printf ("\n%s :", title);
    for (int i = 0; i < size; i++)
        {
        if (i % 5 == 0) printf ("\n");
        $g; printf ("[%2d] = %3d, ", i, data [i]);
        }
    }

void FillArray_11 (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);
        data [i] = 1 + i % 3;
        }
    }

void FillArray_12 (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);
        if (i % 3 == 0) data [i] = 1;
        if (i % 3 == 1) data [i] = 2;
        if (i % 3 == 2) data [i] = 3;
        }
    }

void FillArray_13 (int data [], int size)
    {
    data [0] = 1;
    for (int i = 1; i < size; i++)
        {
        assert (0 <= i     && i     < size);
        assert (0 <= i - 1 && i - 1 < size);

        if (data [i - 1] == 1) data [i] = 2;
        if (data [i - 1] == 2) data [i] = 3;
        if (data [i - 1] == 3) data [i] = 1;
        }
    }
