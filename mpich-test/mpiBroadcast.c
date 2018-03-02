#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>


int main(int argc, char *argv[])   {

    int rank;
    int size;

    srand(time(NULL));
    int random;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank == 0){
        random  = (rand() % 101);
    }

    MPI_Bcast(&random, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank !=0) {
        printf("After broadcast, at process %d value = %d \n", rank, random);
    }


    MPI_Finalize();
    return 0;
}
