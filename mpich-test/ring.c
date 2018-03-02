//CPSC 479 - Resham Jhangiani
//HOMEWORK 2 Problem 2
//MPI RING EXAMPLE WITH TIME CALCULATION
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {

  // Initialize the MPI environment

  MPI_Init(NULL, NULL);

  // Find out rank, size

  int world_rank;

  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  int world_size;

  MPI_Comm_size(MPI_COMM_WORLD, &world_size);


  int token;
  //Variables to calculate start time exection and end time.
  double start_time = 0;
  double end_time = 0;
  //Begin Timer
  start_time = MPI_Wtime();
  // Receive from the lower process and send to the higher process. Take care

  // of the special case when you are the first process to prevent deadlock.

  if (world_rank != 0) {

    MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD,

             MPI_STATUS_IGNORE);

    printf("Process %d received token %d from process %d\n", world_rank, token,

           world_rank - 1);

  } else {

    // Set the token's value if you are process 0

    token = -1;

  }

  MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0,

           MPI_COMM_WORLD);

  // Now process 0 can receive from the last process. This makes sure that at

  // least one MPI_Send is initialized before all MPI_Recvs (again, to prevent

  // deadlock)

  if (world_rank == 0) {

    MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD,

             MPI_STATUS_IGNORE);

    printf("Process %d received token %d from process %d\n", world_rank, token,

           world_size - 1);

           //Execution in the ring completed end timer
           end_time = MPI_Wtime();
           printf("Time taken to pass the token in the ring is :%f\n", end_time-start_time);

  }

  MPI_Finalize();


return 0;
}
