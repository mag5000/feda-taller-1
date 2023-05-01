#include <iostream>
#include <fstream>

using namespace std;

// Función encargada de crear el dataset de matrices cuadradas dados los parametros establecidos
// en el main. 
void createSquareMatrixDataset(int mat_jump, int mat_min_size, int mat_max_size, int mat_max_element){

	ofstream outfile("sq_matrix_dataset.txt");
	int element;
	int size=10;
	srand(time(NULL));

	for (int i = 0; i <= mat_max_size; i+=mat_jump){

	  if(i!=0){
	  	size=i;
	  }
	  outfile << size << " " << size << endl;	 
	  for (int k=0; k < size; k++){
	  	for (int j=0; j < size; j++){
	  		element = rand()%mat_max_element;
         	outfile << element <<" ";
	  	}
        outfile << endl;
      }
      
      outfile << size << " " << size << endl;
	  for (int k=0; k < size; k++){
	  	for (int j=0; j < size; j++){
	  		element = rand()%mat_max_element;
         	outfile << element <<" ";
	  	}
        outfile << endl;
      }
    }
	outfile.close();
	
}

// Función encargada de crear el dataset de matrices potencia de 2, dados los parametros establecidos
// en el main. 
void createPower2MatrixDataset(int mat_max_size, int mat_max_element){

	ofstream outfile("power2_matrix_dataset.txt");
	int element;
	int size=2;
	srand(time(NULL));

	while (size<=mat_max_size){
	  outfile << size << " " << size << endl;	 
	  for (int k=0; k < size; k++){
	  	for (int j=0; j < size; j++){
	  		element = rand()%mat_max_element;
         	outfile << element <<" ";
	  	}
        outfile << endl;
      }
      outfile << size << " " << size << endl;
	  for (int k=0; k < size; k++){
	  	for (int j=0; j < size; j++){
	  		element = rand()%mat_max_element;
         	outfile << element <<" ";
	  	}
        outfile << endl;
      }
      size=size*2;
    }
	outfile.close();
	
}

int main() {
	
	int mat_jump = 100;
	int mat_min_size = 10;
	int mat_max_size = 1000;
	int mat_max_element = 100;

 	createSquareMatrixDataset(mat_jump, mat_min_size, mat_max_size, mat_max_element);
 	createPower2MatrixDataset(mat_max_size, mat_max_element);
	return 0;




}

