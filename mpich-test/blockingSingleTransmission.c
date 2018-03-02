//CPSC 479 Homework 2
//Resham Jhangiani CWID 893336362
//Problem 1
//Calculating time taken for Single transmission  using blocking 
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
int number;
start_time = MPI_Wtime();
  if (rank == 0) {
                    number = -1;
                    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
                    printf("Process 0 sent number %d to process 1\n", number);
                  }
   else if (rank == 1){
                          MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                          printf("Process 1 received number %d from process 0\n", number);
                        }
end_time = MPI_Wtime();
printf("Time taken for Single transmission using blocking : %f\n", end_time - start_time);
MPI_Finalize();
return 0;
}
