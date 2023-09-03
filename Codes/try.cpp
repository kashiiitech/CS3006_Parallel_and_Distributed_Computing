#include "mpi.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  int rank, numprocs;
  int namelen;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  std::vector<std::string > strings;
  std::vector<char* > cstrings;

  if (rank==0) {
    strings.push_back("fe");
    strings.push_back("fo");
    
    for(int i=0; i<strings.size(); i++){
      string st = strings[i];
      cstrings.push_back(&st[0]);
    }

    for(int i=0; i<cstrings.size(); i++){
      cout << cstrings.data()[i] << endl;
    }
            
    MPI_Send(&cstrings[0], cstrings.size(), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  }
  if (rank==1) {
    cstrings.resize(2);
    MPI_Recv(&cstrings[0], cstrings.size(), MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
    for(int i=0; i<cstrings.size(); i++){
      cout << cstrings.data()[i] << endl;
    }
  }

  MPI_Finalize();
  return 0;
}