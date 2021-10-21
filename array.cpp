# include "TXlib.h"

void FillArray  (int data [], int size, int start, int step);
void PrintArray (int data [], int size, const char title []);
void FillArray_11 (int data [], int size);
void FillArray_12 (int data [], int size);
void FillArray_13 (int data [], int size);
void FillArray_21 (int data [], int size);
void FillArray_22 (int data [], int size);
void FillArray_31 (int data [], int size);
void FillArray_41 (int data [], int size);
void FillArray_42 (int data [], int size);
void FillArray_51 (int data [], int size, int step);
void FillRandomArray (int data [], int size, int minimum, int maximum);
void MinMaxArray     (int data [], int size, boolean maximum);
void ExchangeArray   (int data [], int size);
void ShiftArray      (int data [], int size, boolean shiftright);

int main ()
    {
    int data [20] = {};

    FillRandomArray (data, 20, -100, 100);
    PrintArray   (data, 20, "Array");
    ShiftArray (data, 20, 0);
    PrintArray   (data, 20, "Array");

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
        printf ("\n");
        $g; printf ("[%2d] = %3d", i, data [i]);
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

void FillArray_21 (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i     && i     < size);

        if ((i % 6 == 0) || (i % 6 == 5)) data [i] = 1;
        if ((i % 6 == 1) || (i % 6 == 4)) data [i] = 2;
        if ((i % 6 == 2) || (i % 6 == 3)) data [i] = 3;
        }
    }

void FillArray_22 (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);

        if (i % 6 < 3) data [i] = i % 6 + 1;
                  else data [i] = 6 - i % 6;
        }
    }

void FillArray_31 (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);

        if  (i % 4 == 2) data [i] = 3;
        if  (i % 4 == 0) data [i] = 1;
        if ((i % 4 == 1) || (i % 4 == 3)) data [i] = 2;
        }
    }

void FillArray_41 (int data [], int size)
    {
    int score = 1;
    for (int i = 0; i <= size / 2; i++)
        {
        assert (0 <= i && i < size);

        data [i] = score;
        score++;
        if (data [size - i] == 0) data [size - i] = score;
        score++;
        }
    }

void FillArray_42 (int data [], int size)
    {
    int even = 2;
    int  odd = 1;

    for (int i = 0; i <= size / 2; i++)
        {
        assert (0 <= i && i < size);

        data [i] = odd;
        odd = odd + 2;
        }

    for (int i = 0; i <= size / 2; i++)
        {
        assert (0 <= i && i < size);

        if (data [size - i] == 0) data [size - i] = even;
        even = even + 2;
        }
    }

void FillArray_51 (int data [], int size, int step)
    {
    int score = 1;
    for (int i = 0; i < size / 2; i = i + step)
        {
        assert (0 <= i && i < size);

        if (data [i]     == 0) data [i]     = score;
        if (data [i + 1] == 0) data [i + 1] = score + 1;
        if (data [i + 2] == 0) data [i + 2] = score + 2;

        if (data [size - i]       == 0) data [size - i]       = score + 3;
        if (data [size - (i + 1)] == 0) data [size - (i + 1)] = score + 4;
        if (data [size - (i + 2)] == 0) data [size - (i + 2)] = score + 5;

        score = score + 6;
        }
    }

void FillRandomArray (int data [], int size, int minimum, int maximum)
    {
    for (int i = 0; i <= size; i ++)
        {
        assert (0 <= i && i <= size);
        data [i] = rand () % (maximum + 1) - rand () % (minimum + 1);
        }
    }

void MinMaxArray (int data [], int size, boolean maximum)
    {
    int max = data [0];
    int min = data [0];
    int number_min = 0;
    int number_max = 0;

    for (int i = 1; i < size; i ++)
        {
        assert (0 <= i && i < size);
        if (max < data [i])
            {
            number_max = i;
            max = data [i];
            }
        if (min > data [i])
            {
            number_min = i;
            min = data [i];
            }
        }

    if (maximum == 1) printf ("number_max = %d", number_max);
                 else printf ("number_min = %d", number_min);
    }

void ExchangeArray (int data [], int size)
    {
    int glass = 0;

    for (int i = 0; i < size; i += 2)
        {
        assert (0 <= i && i < size);
        glass = data [i];
        data [i] = data [i + 1];
        data [i + 1] = glass;
        }
    }

void ShiftArray (int data [], int size, boolean shiftright)
    {
    if (shiftright == 1)
        {
        int glass = data [size - 1];

        for (int i = size - 1; i >= 0; i = i - 1)
            {
            assert (0 <= i && i < size);
            data [i] = data [i - 1];
            }

        data [0] = glass;
        }

    if (shiftright == 0)
        {
        int glass = data [0];

        for (int i = 0; i < size - 2; i++)
            {
            assert (0 <= i && i < size);
            data [i] = data [i + 1];
            }

        data [size - 1] = glass;
        }
    }
