//CPSC 479 Homework 2
//Resham Jhangiani CWID 893336362
//Problem 1
//Calculating time taken for Single transmission  using non blocking 
#include <stdio.h>
#include "mpi.h"
int main( int argc, char *argv[] )
{
int rank, size;
MPI_Init( &argc, &argv );
MPI_Comm_rank( MPI_COMM_WORLD, &rank );
MPI_Comm_size( MPI_COMM_WORLD, &size );
double start_time = 0;
double end_time = 0;
MPI_Request ireq;
MPI_Status istatus;
int number;
start_time = MPI_Wtime();
if (rank == 0) {
           number = -1;
           MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &ireq);
           printf("Process 0 sent number %d to process 0\n", number);
           //MPI_Wait(&ireq, &istatus);
     } else if (rank == 1) {

          MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &ireq);
          //MPI_Wait(&ireq, &istatus);
          printf("Process 1 received number %d from process 0\n", number);
     }
 end_time = MPI_Wtime();
 printf("Time taken for single transmissionwith non blocking communication  %f\n", end_time - start_time );
 MPI_Finalize();
 return 0;
 }
