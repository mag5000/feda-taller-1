#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "t1_mmatrix.h"

using namespace std;




// En caso de ser necesario se implementa un algoritmo para la impresión de matrices


void print(string display, vector<vector<int> > matrix){

    int cols = matrix[0].size();
    int rows = matrix.size();

    cout << endl << display << ": " << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          cout <<" "<< matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}
 




// Algoritmo encargado de leer el archivo del dataset de matrices que seran multiplicadas
vector<vector<vector<int>>> readMatrixDataset(string route){


  int rows = 0;
  int cols = 0;

  vector<vector<int>> temp_matrix;
  vector<vector<vector<int>>> matrix_array;
  

  ifstream inputfile(route);

  while(inputfile>>rows){

    inputfile>>cols;

    if(cols>0 && rows>0){
      vector<int> temp_row(cols);

      for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){ 
          inputfile>>temp_row[j];

        }

        temp_matrix.push_back(temp_row);
        
      } 
      temp_row.clear();
      matrix_array.push_back(temp_matrix);
      temp_matrix.clear();
    }


  }
  return matrix_array;
}

// Funcion encargada de recibir un array de matrices y crear un archivo con los tiempos de ejecucion
// de los distintos algoritmos de multiplicacion de matrices implementados. También recibe como parametro el
// número de veces que se ejecutara cada multiplicacion de matrices.
void takeMultiplicationTime(int exp_x_matrix, vector<vector<vector<int>>>matrix_array){

  int rows_a;
  int cols_a;
  int rows_b;
  int cols_b;
  vector<vector<int> > matrix_a;
  vector<vector<int> > matrix_b;

  long long strassen_multiplication_time = 0;
  long long standart_multiplication_time = 0;
  long long transposed_multiplication_time = 0;

  long long avg_strassen_multiplication_time = 0;
  long long avg_standart_multiplication_time = 0;
  long long avg_transposed_multiplication_time = 0;

  t1_mmatrix *mmatrix = new t1_mmatrix();

  ofstream outfile("output/results.csv");
  outfile << "rows_a,cols_a,rows_b,cols_b,algorithm,time\n";
  

  
  for(int i =0;i<matrix_array.size();i+=2){


    matrix_a = matrix_array[i];
    matrix_b = matrix_array[i+1];

    rows_a = matrix_a.size();
    cols_a = matrix_a[0].size();
    rows_b = matrix_b.size();
    cols_b = matrix_b[0].size();


    for(int j=0; j<exp_x_matrix; j++){

      // solo se ejecuta en caso de que sea una matriz cuadrada con n potencia de 2
      if (ceil(log2(rows_a)) == floor(log2(rows_a)) && rows_a==cols_a && rows_a==cols_b && rows_b== cols_b){ 
        strassen_multiplication_time += mmatrix->strassenMultiplicationTime(matrix_a, matrix_b);
      } 
      standart_multiplication_time += mmatrix->standartMultiplicationTime(matrix_a, matrix_b);
      transposed_multiplication_time += mmatrix->transposedMultiplicationTime(matrix_a, matrix_b);

    }

    avg_strassen_multiplication_time = strassen_multiplication_time/exp_x_matrix;
    avg_standart_multiplication_time = standart_multiplication_time/exp_x_matrix;
    avg_transposed_multiplication_time = transposed_multiplication_time/exp_x_matrix;

    outfile << rows_a<< ","<< cols_a<<","<<rows_b<<","<<cols_b<<",Strassen Multiplication,"<<avg_strassen_multiplication_time<<endl;
    outfile << rows_a<< ","<< cols_a<<","<<rows_b<<","<<cols_b<<",Standart Multiplication,"<<avg_standart_multiplication_time<<endl;
    outfile << rows_a<< ","<< cols_a<<","<<rows_b<<","<<cols_b<<",Transposed Multiplication,"<<avg_transposed_multiplication_time<<endl;

    cout<<""<<rows_a<<"X"<<cols_a<<"*"<<rows_b<<"x"<<cols_b<<"    OK!"<<endl; //Para ir viendo el avance por pantalla

    matrix_array[i].clear();
    matrix_array[i+1].clear();


  }

  outfile.close();


}



//=============================================  main para las pruebas ====================================================================

int main(){

  vector<vector<vector<int>>> matrix_array = readMatrixDataset("dataset/sq_matrix_dataset.txt");
  takeMultiplicationTime(1, matrix_array);

return 0;
}