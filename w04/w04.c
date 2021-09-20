// /*********************************************
//  * Id: kugl5443
//  *
//  * Name: Austin Kugler
//  * Assignment: W04
//  * Uses Gaussian elimination to solve a system of linear equations.
//  *********************************************/
#include <stdio.h>
#include <stdlib.h>

float A[3][4] = {
    {1.00, 2.00, 3.00, 4.00},
    {5.00, 6.00, 7.00, 8.00},
    {9.00, 10.00, 11.00, 12.00}};

void printMatrix();

int main(int argc, char *argv[])
{
   int n = 3;

   printMatrix(n);
   printf("\n");

   int i, j, k;
   for (i = 0; i < n - 2; i++)
   {
      for (j = i + 1; j < n - 1; j++)
      {
         float tempji = A[j][i];
         for (k = i; k < n; k++)
         {
            A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
         }
      }
      printMatrix(n);
      printf("\n");
   }
}

void printMatrix(int n)
{
   int i, j;
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n + 1; j++)
      {
         printf("%.2f ", A[i][j]);
      }
      printf("\n");
   }
}

// #include <stdio.h>
// #include <stdlib.h>

// // int GE(int n, float A[][]);
// // void printMatrix(int n, float A[n][n + 1]);

// int main(int argc, char *argv[])
// {
//    int n = atoi(argv[1]);
//    float A[n + 1][n];

//    int row = 0, column = 0;
//    int i;
//    for (i = 2; i < argc; i++)
//    {
//       if (column > 0 && column % (n + 1) == 0)
//       {
//          row++;
//          column = 0;
//       }

//       A[row][column] = atof(argv[i]);
//       column++;
//    }

//    int j, k;
//    for (i = 0; i < n; i++)
//    {
//       for (j = 0; j < n + 1; j++)
//       {
//          printf("%.2f ", A[i][j]);
//       }
//       printf("\n");
//    }
//    printf("\n");

//    for (i = 0; i < n - 2; i++)
//    {
//       for (j = i + 1; j < n - 1; j++)
//       {
//          float tempji = A[j][i];
//          for (k = i; k < n; k++)
//          {
//             A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
//          }
//       }
//    }

//    for (i = 0; i < n; i++)
//    {
//       for (j = 0; j < n + 1; j++)
//       {
//          printf("%.2f ", A[i][j]);
//       }
//       printf("\n");
//    }
//    printf("\n");

//    return 0;
// }

// // int GE(int n, float A[][])
// // {
// //    // int i, j;
// //    // for (int i = 0; i < n - 2; ++i)
// //    // {
// //    //    for (int j = i + 1; j < n - 1; ++j)
// //    //    {
// //    //    }
// //    // }
// // }

// // void printMatrix(int, float[][])
// // {
// //    int i, j;
// //    for (i = 0; i < n; i++)
// //    {
// //       for (j = 0; j < n + 1; j++)
// //       {
// //          printf("%.2f ", A[i][j]);
// //       }
// //       printf("\n");
// //    }
// // }