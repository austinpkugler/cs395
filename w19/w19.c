/*********************************************
 * Id: kugl5443
 *
 * Name: Austin Kugler
 * Assignment: W19
 *
 * MaximumBipartiteMatching BFS-based
 *********************************************/

// Before calling MaximumBipartiteMatching(G)
//    printGraph(G)

// //Finds a maximum matching in a bipartite graph by a BFS-like traversal
// //Input: A bipartite graph G = Adjacenty Matrix
// //Output: A maximum-cardinality matching M (array of (V,U) edges in the input graph
// MaximumBipartiteMatching(G)
//    initialize set M of edges with some valid matching (e.g., the empty set)
//    initialize queue Q with all the free vertices in V (in any order)
//    while not Empty(Q) do
//       printQueue(Q)
//       w←Front(Q); Dequeue(Q)
//       if w is an element of V
//          for every vertex u adjacent to w do
//             if u is free
//                //augment
//                M ←M ∪ (w, u)
//                v←w
//                while v is labeled do
//                   u←vertex indicated by v’s label; M ←M − (v, u)
//                   v←vertex indicated by u’s label; M ←M ∪ (v, u)
//                remove all vertex labels
//                reinitialize Q with all free vertices in V
//                break //exit the for loop
//             else //u is matched
//                if (w, u) is not an element of M and u is unlabeled
//                   label u with w
//                   Enqueue(Q, u)
//       else //w is and element of U (and matched)
//          label the mate v of w with w
//          Enqueue(Q, v)
//       printM(M)
//    return M //current matching is maximum

// Note: These are my print functions. Your may vary if you have different data structures.
// // Print the adjacentcy matrix.
// void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies) {
//    int i, j;
//    for(i=0; i<Vverticies; i++)
//    {
//       printf("%d ->", i);
//       j=0;
//       while(G[i][j] != BCEMPTY)
//       {
//          printf(" %d", G[i][j]);
//          j++;
//       }
//       printf("\n");
//    }
// }

// // Print out the current contents of the queue for debugging
// void printQueue(int Queue[], int start, int end) {
//    int i;
//    printf("Queue:");
//    for(i=start; i<end; i++)
//    {
//       printf(" %d", Queue[i]);
//    }
//    printf("\n");
// }

// // Print out the currenlty found matchings
// void printM(int M[][2], int start, int end) {
//    int i;
//    for(i=start; i<end; i++)
//    {
//       printf("\tV%d", M[i][0]);
//    }
//    printf("\n");

//    for(i=start; i<end; i++)
//    {
//       printf("\t|");
//    }
//    printf("\n");

//    for(i=start; i<end; i++)
//    {
//       printf("\tU%d", M[i][1]);
//    }
//    printf("\n");
// }