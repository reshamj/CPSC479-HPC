#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int i, p,Neven, Nodd, members[8], ierr;
  MPI_Comm comm_world;
  MPI_Group group_world;
  comm_world = MPI_COMM_WORLD;
  MPI_Comm_group(comm_world, &group_world);

   //printf("\n WORLD:%d  GROUP:%d", comm_world, group_world);
   p = world_rank;
   Neven = (p+1)/2;
   //printf("Neven %d\n", Neven);
   Nodd = p -Neven;
   //printf("Nodd %d\n", Nodd);
   for (i=0; i<Neven ; i++)
   {
     members[i] = 2*i;
     printf("%d\n",members[i] );
   }



  MPI_Finalize();
  return 0;
  }
