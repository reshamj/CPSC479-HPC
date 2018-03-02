//CPSC 479 Homework 2
//Resham Jhangiani CWID 893336362
//Problem 1
//Calculating time taken for Two transmissions (round trip) using non blocking communication i.e. MPI_Isend and MPI_Irecv
#include <stdio.h>
#include "mpi.h"
int main( int argc, char *argv[] )
{
int rank, size;
MPI_Init( &argc, &argv );
MPI_Comm_rank( MPI_COMM_WORLD, &rank );
MPI_Comm_size( MPI_COMM_WORLD, &size );
double start_time, end_time;
MPI_Request ireq;
MPI_Status istatus;
int number;
start_time = MPI_Wtime();
if (rank == 0) {
           number = -1;
           MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &ireq);
           printf("Process 0 sent number %d to process 0\n", number);
           //MPI_Wait(&ireq, &istatus);
           MPI_Irecv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &ireq);
           printf("Process 0 received number %d from process 1\n", number);
     } else if (rank == 1) {
          MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &ireq);
          //MPI_Wait(&ireq, &istatus);
          printf("Process 1 received number %d from process 0\n", number);
          MPI_Isend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &ireq);
           printf("Process 1 sent number %d to process 0\n", number);
     }
 end_time = MPI_Wtime();
 MPI_Finalize();

 printf("Time taken for two transmissions (round trip) using non blocking communication %f\n", end_time-start_time );
 return 0;
 }
