/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W04
 * Uses Gaussian elimination to solve a system of linear equations.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GE(float elements[], int n);

// Accepts command line arguments for matrix values.
int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Enter the number of equations followed by their elements.\n");
      return 0;
   }

   int n = atoi(argv[1]);

   float elements[n * (n + 1)];
   int i;
   for (i = 2; i < argc; i++)
   {
      elements[i - 2] = atof(argv[i]);
   }

   GE(elements, n);

   return 0;
}

// Performs Gaussian Elimination on a matrix.
void GE(float elements[], int n)
{
   // Move the elements into a 2D array to represent the matrix.
   float A[n][n + 1];
   int row = 0, col = 0, offset = 0;

   while (row < n)
   {
      for (offset = row * (n + 1); offset < row * (n + 1) + (n + 1); offset++)
      {
         col = offset - (row * (n + 1));
         A[row][col] = elements[offset];
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

   // Start Gaussian elimination
   float tempji;

   int i, j, k;
   for (i = 0; i < n - 1; i++)
   {
      for (j = i + 1; j < n; j++)
      {
         tempji = A[j][i];
         for (k = i; k < n + 1; k++)
         {
            A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
         }

         // Print the matrix
         int y, z;
      }
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