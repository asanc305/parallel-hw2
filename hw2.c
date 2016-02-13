//#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int add_all(int x, int root);
int	taskid, numtasks;

int main (int argc, char *argv[])
{

  //MPI_Init(&argc,&argv);  
  //MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
  //MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
  //printf ("MPI task %d has started...\n", taskid);
  taskid = 1;
  numtasks = 10;
  int sum = add_all(taskid, 0);
  //if (taskid==0) printf("[0] add_all->%d\n", sum);
}

int add_all(int x, int root)
{
  int i;
  double j, high;

  j = ceil(log(numtasks) / log(2));

  high = numtasks - 1;
  printf("1Value of high: %lf\n", high);
  printf("1Value of log: %lf\n", j);

  for (i=0; i < j; i++)
  {
    if ( taskid < (high / 2))
    {
      printf("Less than: taskid: %i high: %lf i: %i half: %lf\n", taskid, high, i, high/2);
    }
    else if ( taskid > (high / 2))
    {
      //send to high-taskid
      printf("More than: taskid: %i high: %lf i: %i half: %lf\n", taskid, high, i, high/2);
    }

    high = floor(high/2);
  }
  
}
