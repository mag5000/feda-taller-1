#include <iostream>
#include <fstream>

using namespace std;



// Función encargada de crear el dataset de matrices dados los parametros establecidos
// en el main. El valor de "mat_num" corresponde al par de matrices que seran multiplicadas, 
// en las que el número de columnas de la primera es igual al número de filas de la segunda.

void createMatrixDataset(int mat_jump, int mat_min_size, int mat_max_size, int mat_max_element){

	ofstream outfile("random_matrix_dataset.txt");
	int col_num_a;
	int row_num_a;
	int col_num_b;
	int row_num_b;
	int element;
	srand(time(NULL));

	for (int i = 1; i < mat_max_size; i+=mat_jump){
	
	  int col_num_a = rand()%(i-mat_min_size)+mat_min_size;
	  int row_num_a = rand()%(i-mat_min_size)+mat_min_size;
	  int col_num_b = rand()%(i-mat_min_size)+mat_min_size;
	  int row_num_b = col_num_a;

	  outfile << row_num_a << " " << col_num_a << endl;
	  for (int k=0; k < row_num_a; k++){
	  	for (int j=0; j < col_num_a; j++){

	  		element = rand()%mat_max_element;
         	outfile << element <<" ";

	  	}
        outfile << endl;
      }
      outfile << row_num_b << " " << col_num_b << endl;
	  for (int k=0; k < row_num_b; k++){
	  	for (int j=0; j < col_num_b; j++){

	  		element = rand()%mat_max_element;
         	outfile << element <<" ";

	  	}
        outfile << endl;
      }

    }

	outfile.close();
	
}

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

 	createMatrixDataset(mat_jump, mat_min_size, mat_max_size, mat_max_element);
 	createSquareMatrixDataset(mat_jump, mat_min_size, mat_max_size, mat_max_element);
// 	createPower2MatrixDataset(mat_max_size, mat_max_element);
	return 0;




}

