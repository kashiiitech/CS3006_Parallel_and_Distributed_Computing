
#include <mpi.h>
#include <stdio.h>
// #include <cstring>



int main(int argc, char** argv) {
        int cp;
        int sum = 0;
        int data[5];
        int arr[5] = {1, 2, 3, 4, 5};
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &cp);

        if(cp == 0) {
                int i = 0;
                for(i=0;i<5;i++) {
                        data[i] = arr[i];
                }
        }
        MPI_Bcast(&data, 5, MPI_INT, 0, MPI_COMM_WORLD);
        // printf("\nbefore bcast data in Process %d : %d",cp,data);
                int i = 0;
                printf("\nAfter bcast data in Process %d:",cp);
                for(i=4;i>=0;i--) {
                        printf("%d",data[i]);
                        sum += data[i];
                }
                printf("\nsum is %d: ", (sum-2));

        

        MPI_Finalize();
        return 0;
}
