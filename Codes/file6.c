// #include <mpi.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// // size of array
// #define n 10

// int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// // Temporary array for slave process
// int a2[1000];

// int main(int argc, char* argv[])
// {

// 	int pid, np,
// 		elements_per_process,
// 		n_elements_recieved;
// 	// np -> no. of processes
// 	// pid -> process id

// 	MPI_Status status;

// 	// Creation of parallel processes
// 	MPI_Init(&argc, &argv);

// 	// find out process ID,
// 	// and how many processes were started
// 	MPI_Comm_cp(MPI_COMM_WORLD, &pid);
// 	MPI_Comm_size(MPI_COMM_WORLD, &np);

// 	// master process
// 	if (pid == 0) {
// 		int index, i;
// 		elements_per_process = n / np;

// 		// check if more than 1 processes are run
// 		if (np > 1) {
// 			// distributes the portion of array
// 			// to child processes to calculate
// 			// their partial sums
// 			for (i = 1; i < np - 1; i++) {
// 				index = i * elements_per_process;

// 				MPI_Send(&elements_per_process,
// 						1, MPI_INT, i, 0,
// 						MPI_COMM_WORLD);
// 				MPI_Send(&a[index],
// 						elements_per_process,
// 						MPI_INT, i, 0,
// 						MPI_COMM_WORLD);
// 			}

// 			// last process adds remaining elements
// 			index = i * elements_per_process;
// 			int elements_left = n - index;

// 			MPI_Send(&elements_left,
// 					1, MPI_INT,
// 					i, 0,
// 					MPI_COMM_WORLD);
// 			MPI_Send(&a[index],
// 					elements_left,
// 					MPI_INT, i, 0,
// 					MPI_COMM_WORLD);
// 		}

// 		// master process add its own sub array
// 		int sum = 0;
// 		for (i = 0; i < elements_per_process; i++)
// 			sum += a[i];

// 		// collects partial sums from other processes
// 		int tmp;
// 		for (i = 1; i < np; i++) {
// 			MPI_Recv(&tmp, 1, MPI_INT,
// 					MPI_ANY_SOURCE, 0,
// 					MPI_COMM_WORLD,
// 					&status);
// 			int sender = status.MPI_SOURCE;

// 			sum += tmp;
// 		}

// 		// prints the final sum of array
// 		printf("Sum of array is : %d\n", sum);
// 	}
// 	// slave processes
// 	else {
// 		MPI_Recv(&n_elements_recieved,
// 				1, MPI_INT, 0, 0,
// 				MPI_COMM_WORLD,
// 				&status);

// 		// stores the received array segment
// 		// in local array a2
// 		MPI_Recv(&a2, n_elements_recieved,
// 				MPI_INT, 0, 0,
// 				MPI_COMM_WORLD,
// 				&status);

// 		// calculates its partial sum
// 		int partial_sum = 0;
// 		for (int i = 0; i < n_elements_recieved; i++)
// 			partial_sum += a2[i];

// 		// sends the partial sum to the root process
// 		MPI_Send(&partial_sum, 1, MPI_INT,
// 				0, 0, MPI_COMM_WORLD);
// 	}

// 	// cleans up all MPI state before exit of process
// 	MPI_Finalize();

// 	return 0;
// }



















//////////////////////////////////////////////////////////////////////////







// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Ping pong example with MPI_Send and MPI_Recv. Two processes ping pong a
// number back and forth, incrementing it until it reaches a given value.
//
// #include <mpi.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char** argv) {
//   const int PING_PONG_LIMIT = 2;

//   // Initialize the MPI environment
//   MPI_Init(NULL, NULL);
//   // Find out cp, size
//   int current_process;
//   MPI_Comm_cp(MPI_COMM_WORLD, &current_process);
//   int total_no_of_processes;
//   MPI_Comm_size(MPI_COMM_WORLD, &total_no_of_processes);

//   // We are assuming 2 processes for this task
//   if (total_no_of_processes != 2) {
//     fprintf(stderr, "World size must be two for %s\n", argv[0]);
//     MPI_Abort(MPI_COMM_WORLD, 1);
//   }

//   int ping_pong_count = 0;
//   int partner_cp = (current_process + 1) % 2;
//   while (ping_pong_count < PING_PONG_LIMIT) {
//     if (current_process == ping_pong_count % 2) {
//       // Increment the ping pong count before you send it
//       ping_pong_count++;
//       MPI_Send(&ping_pong_count, 1, MPI_INT, partner_cp, 0, MPI_COMM_WORLD);
//       printf("%d sent and incremented ping_pong_count %d to %d\n",
//              current_process, ping_pong_count, partner_cp);
//     } else {
//       MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_cp, 0, MPI_COMM_WORLD,
//                MPI_STATUS_IGNORE);
//       printf("%d received ping_pong_count %d from %d\n",
//              current_process, ping_pong_count, partner_cp);
//     }
//   }
//   MPI_Finalize();
// }

















//////////////////////////////////////////////////



// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Example using MPI_Send and MPI_Recv to pass a message around in a ring.
//
// #include <mpi.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char** argv) {
//   // Initialize the MPI environment
//   MPI_Status status;
//   MPI_Init(NULL, NULL);
//   // Find out cp, size
//   int cp;
//   MPI_Comm_cp(MPI_COMM_WORLD, &cp);
//   int np;
//   MPI_Comm_size(MPI_COMM_WORLD, &np);

//   int num;

//   if(cp==0) {
//     num = 5;
// //     MPI_Bcast(void *data, int count, MPI_Datatype datatype,
// // int source, MPI_Comm comm)

//     MPI_Bcast(&num, 1, MPI_INT,0,MPI_COMM_WORLD);

//   }

//   else {
//     MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//                 printf("Current process %d receiving received %d\n", cp, num);

//   }

//   MPI_Finalize();
// }






#include <mpi.h>
#include <stdio.h>
// #include <cstring>



int main(int argc, char** argv) {
        int cp;
        char data[5];
        char arr[5] = {'h', 'e', 'l', 'l', 'o'};
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &cp);

        if(cp == 0) {
                int i = 0;
                for(i=0;i<5;i++) {
                        data[i] = arr[i];
                }
        }
        MPI_Bcast(&data, 5, MPI_CHAR, 0, MPI_COMM_WORLD);
        // printf("\nbefore bcast data in Process %d : %d",cp,data);
                int i = 0;
                printf("\nAfter bcast data in Process %d: ",cp);
                for(i=0;i<5;i++) {
                        printf("%c",data[i]);
                }

        

        MPI_Finalize();
        return 0;
}
