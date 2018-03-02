#include <stdio.h>
#include "mpi.h"
int main( int argc, char *argv[] )
{

int rank;
double start , end, ttaken;

MPI_Init (&argc , &argv);
MPI_Comm_rank(MPI_COMM_WORLD , &rank);

start = MPI_Wtime ();
//LocalComputation (); /* some local computations here */
//MPI, time_Barrier(MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);

end = MPI_Wtime (); /* measure the worst -case time of a process */
MPI_Finalize ();

ttaken = end -start;
printf("%f\n",start );
printf("%f\n",end );
if (rank == 0) /* use time on master node */
      printf("Time taken - %f", ttaken);



return 0;

   }
