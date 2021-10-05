// /*********************************************
//  * Id: kugl5443
//  *
//  * Name: Austin Kugler
//  * Assignment: W04
//  * Uses Gaussian elimination to solve a system of linear equations.
//  *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(float matrix[], int n);
void GE(float matrix[], int n);

// Accepts command line arguments for matrix values.
int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Enter the number of equations followed by their elements.\n");
      return 0;
   }

   int n = atoi(argv[1]);

   float matrix[n * (n + 1)];
   int i;
   for (i = 2; i < argc; i++)
   {
      matrix[i - 2] = atof(argv[i]);
   }

   GE(matrix, n);

   return 0;
}

// Prints an array in matrix form.
void printMatrix(float matrix[], int n)
{
   int i;
   for (i = 0; i < n * (n + 1); i++)
   {
      if (i && i % (n + 1) == 0)
      {
         printf("\n");
      }
      printf("%.2f ", matrix[i]);
   }
   printf("\n");
}

// Performs Gaussian Elimination on a matrix.
void GE(float matrix[], int n)
{
   float A[n][n + 1];
   int row = 0, col = 0, offset = 0;

   while (row < n)
   {
      for (offset = row * (n + 1); offset < row * (n + 1) + (n + 1); offset++)
      {
         col = offset - (row * (n + 1));
         A[row][col] = matrix[offset];
      }
      row++;
   }

   // Print the matrix
   int y, z;
   for (y = 0; y < n; y++)
   {
      for (z = 0; z < n + 1; z++)
      {
         printf("%.2f ", A[y][z]);
      }
      printf("\n");
   }
   printf("\n");

   // Gaussian elimination
   float tempji;

   int i, j, k;
   for (i = 0; i < n - 2; i++)
   {
      for (j = i + 1; j < n - 1; j++)
      {
         tempji = A[j][i];
         for (k = i; k < n; k++)
         {
            A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
         }

         // Print the matrix
         int y, z;
         for (y = 0; y < n; y++)
         {
            for (z = 0; z < n + 1; z++)
            {
               printf("%.2f ", A[y][z]);
            }
            printf("\n");
         }
         printf("\n");
      }
   }
}