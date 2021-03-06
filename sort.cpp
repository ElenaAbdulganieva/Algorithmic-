# include "TXlib.h"
# include "stdio.h"
# include "config.h"

struct ComExc
    {
    int comparison;
    int exchange;
    };

void FillRandomArray (int data [], int size, int minimum, int maximum);
void PrintArray      (int data [], int size, const char title []);
void Counting   ();
void DrawCharts ();

int MinMaxArray (int data [], int size, boolean maximum, int start, int end, ComExc* comexc);

ComExc DrawChart (int x, int y, const char namefile[]);
ComExc SortSelectionArray (int data [], int size, int start, int end);
ComExc BubbleSortArray    (int data [], int size, int start, int end);

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (WINDOW_WIDTH, WINDOW_HEIGHT);
    Counting ();
    DrawCharts ();
    return 0;
    }

//-----------------------------------------------------------------------------
void Counting ()
    {
    int i = 0;
    int data [100] = {};
    FillRandomArray (data, 100, 0, 10);

    for (int i = 0; i < 101; i +=5)
        {
        SortSelectionArray (data, 100, 0, i);
        BubbleSortArray    (data, 100, 0, i);
        }
    }

//-----------------------------------------------------------------------------
void FillRandomArray (int data [], int size, int minimum, int maximum)
    {
    for (int i = 0; i <= size; i ++)
        {
        assert (0 <= i && i <= size);
        data [i] = rand () % (maximum + 1) - rand () % (minimum + 1);
        }
    }

//-----------------------------------------------------------------------------
void PrintArray (int data [], int size, const char title [])
    {
    $y; printf ("\n%s:", title);
    printf ("\n");
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);
        $b; printf ("[%2d ]=%3d  ", i, data [i]);
        }
    printf ("\n");
    }

//-----------------------------------------------------------------------------
int MinMaxArray (int data [], int size, boolean maximum, int start, int end, ComExc* comexc)
    {
    int max = data [start];
    int min = data [start];
    int number_min = start;
    int number_max = start;

    for (int i = start + 1; i < end; i ++)
        {
        assert (0 <= i && i < size);

        if (max < data [i])
            {
            number_max = i;
            max = data [i];
            comexc -> exchange += 2;
            }

        if (min > data [i])
            {
            number_min = i;
            min = data [i];
            comexc -> exchange += 2;
            }
        comexc -> comparison += 2;
        }

    if (maximum == 1) return number_max;
                 else return number_min;
    }

//-----------------------------------------------------------------------------
ComExc SortSelectionArray (int data [], int size, int start, int end)
    {
    ComExc comexc;
    comexc.comparison = 0;
    comexc.exchange = 0;

    FILE *res = fopen ("results/results_SortSelect.csv", "a");

    int begin = start;

    for (begin = start; begin < end; begin ++)
        {
        assert (0 <= begin && begin < size);
        int glass = data [begin];
        int number = MinMaxArray (data, size, 0, begin, end, &comexc);
        data [begin] = data [number];
        data [number] = glass;
        comexc.exchange += 4;
        }

    fprintf (res, "%d; %d\n", comexc.exchange, comexc.comparison);
    fclose (res);
    }

//-----------------------------------------------------------------------------
ComExc BubbleSortArray (int data [], int size, int start, int end)
    {
    ComExc comexc;
    comexc.comparison = 0;
    comexc.exchange = 0;
    int glass = 0;

    FILE *res = fopen ("results/results_bubbleSort.csv", "a");

    for (int sort = 1; sort < end - start - 1; sort ++)
        {
        for (int i = start; i < end; i ++)
            {
            assert (0 <= i && i < size);
            comexc.comparison ++;
            if (data [i] > data [i + 1])
                {
                glass = data [i];
                data [i] =data [i + 1];
                data [i + 1] = glass;
                comexc.exchange +=3;
                }
            }
        }

    fprintf (res, "%d; %d\n", comexc.exchange, comexc.comparison);
    fclose (res);
    }

//-----------------------------------------------------------------------------
void DrawCharts ()
    {
    HDC fon = txLoadImage ("image/fon.bmp");
    txBitBlt (txDC (), 0, 0, 0, 0, fon, 0, 0);
    int t = 1;

    DrawChart (100, 550, "results/results_bubbleSort.csv");
    DrawChart (800, 550, "results/results_SortSelect.csv");

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSleep (1);
        t ++;
        }

    txDeleteDC (fon);
    }

//-----------------------------------------------------------------------------
ComExc DrawChart (int x, int y, const char namefile[])
    {
    ComExc comexc;
    comexc.comparison = 0;
    comexc.exchange   = 0;

    txSetColor (RGB (122, 84, 33), 3);
    txLine     (x, y, x + 350, y      );
    txLine     (x, y, x,       y - 500);

    FILE *res = fopen (namefile, "a");

    fclose (res);
    }
