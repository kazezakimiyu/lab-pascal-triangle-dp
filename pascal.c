#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 50000

typedef unsigned long long ull;

// don't forget to allocate space for your table (multi-demi arrayof MAX x MAX)

ull pascaldp(int n, int i)
{
 // todo by student

 return 0; // just here to compile, delete
}

ull pascalr(int n, int i)
{
    if (n == i || i == 0)
    {
        return 1;
    }
    else
    {
        return pascalr(n - 1, i) + pascalr(n - 1, i - 1);
    }
}


ull *getPascalTriangle(int n, bool print, int version)
{

    ull tmp = 1;
    ull * row = malloc((sizeof(ull)) * n);
    ull arr[n][n]; // for iterative version. n^2 space + n^2 time

    /*if(version == 1) {
        printf("Running recursive version\n");
    }*/
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            if(version == 2) tmp = pascaldp(i, j);
            else if(version == 1) {
                tmp = pascalr(i, j);
            }
            else {
                if(i == j || j == 0)  {
                    arr[i][j] = 1;
                    tmp = 1;
                }
                else {
                    arr[i][j] = arr[i - 1][j-1] + arr[i-1][j];
                    tmp = arr[i][j];
                }

            }
            if(i+1 == n) row[j] = tmp;
            if (print) printf("%llu ", tmp);

        }
        if(print) printf("\n");
    }
    return row;
}

void printSingleRow(ull* row, int size) {
    for(int i = 0; i < size; i++) {
        printf("%llu ", row[i]);
        //else printf(" ");
    }
    printf("\n");


}

void help() {
    printf("./pascal.out N [Type] [Print Level]\n");
    printf("\tN is the number of rows in the pascal triangle, required.\n");
    printf("\t[Type] is either 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 0.\n");
    printf("\t[Print Level] is 0 for no print/speed compare only, 1 for print final row only, 2 for print all rows, defaults to 0.\n");

}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("at least two arguments needed!\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]);
    int type = 0;
    int print = 0;
    if (argc > 2) {
        type = atoi(argv[2]);
    }
    if(argc > 3) {
        print = atoi(argv[3]);
    }

    bool print_it = false;
    if (print > 1) {
        print_it = true;
    }
    ull *row_at_n = getPascalTriangle(n, print_it, type);
    if (print == 1) printSingleRow(row_at_n, n);
    return 0;
}
