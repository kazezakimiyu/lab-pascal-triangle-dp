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

ull scalar(ull coef, int i, int j) {
    if (i == 0 || j == 0)
    {
        return 1;
    }
    return coef * (i-j+1) / j;
}

ull *getPascalTriangle(int n, bool print, int version)
{
    ull coef = 0;
    ull tmp;
    ull * row = malloc((sizeof(ull)) * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {              
            if(version == 2) tmp = pascaldp(i, j);
            else if(version == 1) tmp = pascalr(i, j);
            else {
                coef = scalar(coef, i, j);
                tmp = coef;
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
    printf("\t[Type] is either 3 for dynamic programming version, 2 for recursive version, 1 for iterative version, defaults to 1.\n");
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
