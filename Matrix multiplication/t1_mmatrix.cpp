#include <algorithm>
#include "t1_mmatrix.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor y Destructor
t1_mmatrix::t1_mmatrix(){}
t1_mmatrix::~t1_mmatrix(){}

// Strassens Multiplication: Este algoritmo utiliza la recurrencia para la multiplicación de matrices, al 
// llamar a este mismo algoritmo para resolver la multiplicación de las submatrices. Se diferencia del 
// algoritmo standart de multiplicación recursivo al reducir el número de multiplicaciones (o llamadas
// recursivas) de 8 a 7.
// Fuente: https://www.codingninjas.com
vector<vector<int>> t1_mmatrix::strassenMultiplication(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b)
{
    int cols_a = matrix_a[0].size();
    int rows_a = matrix_a.size();
    int cols_b = matrix_b[0].size();


    vector<int> result_matrix_rows(cols_b, 0);
    vector<vector<int> > result_matrix(rows_a, result_matrix_rows);
 
    //caso base
    if (cols_a == 1){
        result_matrix[0][0] = matrix_a[0][0] * matrix_b[0][0];
    }else {

	  // se crean las submatrices
        int split_index = cols_a / 2;
        vector<int> row_vector(split_index, 0);
        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);
 
        for (int i = 0; i < split_index; i++){
            for (int j = 0; j < split_index; j++) {
                a00[i][j] = matrix_a[i][j];
                a01[i][j] = matrix_a[i][j + split_index];
                a10[i][j] = matrix_a[split_index + i][j];
                a11[i][j] = matrix_a[i + split_index][j + split_index];
                b00[i][j] = matrix_b[i][j];
                b01[i][j] = matrix_b[i][j + split_index];
                b10[i][j] = matrix_b[split_index + i][j];
                b11[i][j] = matrix_b[i + split_index][j + split_index];
            }
 		}

	  //llamadas recursivas
        vector<vector<int>> p(strassenMultiplication(a00, addMatrix(b01, b11, split_index, -1)));
        vector<vector<int>> q(strassenMultiplication(addMatrix(a00, a01, split_index), b11));
        vector<vector<int>> r(strassenMultiplication(addMatrix(a10, a11, split_index), b00));
        vector<vector<int>> s(strassenMultiplication(a11, addMatrix(b10, b00, split_index, -1)));
        vector<vector<int>> t(strassenMultiplication(addMatrix(a00, a11, split_index),addMatrix(b00, b11, split_index)));
        vector<vector<int>> u(strassenMultiplication(addMatrix(a01, a11, split_index, -1),addMatrix(b10, b11, split_index)));
        vector<vector<int>> v(strassenMultiplication(addMatrix(a00, a10, split_index, -1),addMatrix(b00, b01, split_index)));
 
        vector<vector<int>> result_matrix_00(addMatrix(addMatrix(addMatrix(t, s, split_index), u, split_index), q, split_index, -1));
        vector<vector<int>> result_matrix_01(addMatrix(p, q, split_index));
        vector<vector<int>> result_matrix_10(addMatrix(r, s, split_index));
        vector<vector<int>> result_matrix_11(addMatrix(addMatrix(addMatrix(t, p, split_index), r,split_index, -1),v, split_index, -1));
 
        for (int i = 0; i < split_index; i++){
            for (int j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
        }
 
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
        p.clear();
        q.clear();
        r.clear();
        s.clear();
        t.clear();
        u.clear();
        v.clear();
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
    }
    return result_matrix;
}

// Este algoritmo suma o resta matrices. Es llamado por el algoritmo de multiplicacion Strassen.
// Fuente: https://www.codingninjas.com
vector<vector<int>> t1_mmatrix::addMatrix(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b, int split_index, int multiplier){

    for (int i = 0; i < split_index; i++){
        for (int j = 0; j < split_index; j++){
            matrix_a[i][j] = matrix_a[i][j] + (multiplier * matrix_b[i][j]);
        }
    }
    return matrix_a;

}

// Función encargada de tomar el tiempo de ejecución de Strassen Multiplication
long long t1_mmatrix::strassenMultiplicationTime(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b){

    auto start_time = chrono::steady_clock::now();
    vector<vector<int> > result = strassenMultiplication(matrix_a, matrix_b);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    result.clear();
    return duration;

}


// Standart Multiplication: Esta funcion corresponde a la multiplicación standart de matrices, en el que se recorre toda 
// la matriz para su multiplicación
// Fuente: Entregado por Vicente Lermanda
vector<vector<int> > t1_mmatrix::standartMultiplication(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b) {
  int rows_a = matrix_a.size();
  int cols_a = matrix_a[0].size();
  int cols_b = matrix_b[0].size();

  vector<vector<int> > result_matrix(rows_a, vector<int>(cols_b, 0));

  for(int i = 0; i < rows_a; i++){ 
    for(int j = 0; j < cols_b; j++){ 
      for(int k = 0; k < cols_a; k++){ 
        result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }
  return result_matrix;
}

// Funcion encargada de tomar el tiempo de ejecución de la multiplicación standart
long long t1_mmatrix::standartMultiplicationTime(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b){

  auto start_time = chrono::steady_clock::now();
  vector<vector<int> > result = standartMultiplication(matrix_a, matrix_b);
  auto end_time = chrono::steady_clock::now();
  long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
  result.clear();
  return duration;
      
}

// Esta función corresponde a la multiplicación de matrices en la que la segunda matriz se encuentra transpuesta. Su 
// ventaja esta en la localidad de los datos.
// Fuente: Entregado por Vicente Lermanda
vector<vector<int> > t1_mmatrix::transposedMultiplication(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b) {
  
  int rows_a = matrix_a[0].size();
  int cols_b = matrix_b[0].size();
  int rows_b = matrix_b.size();
  int temp_element = 0;

 
  vector<vector<int> > matrix_b_transposed(cols_b, vector<int>(rows_b, 0));

  for(int i = 0; i < rows_b; i++){ 
    for(int j = 0; j < cols_b; j++){  
      matrix_b_transposed[j][i] = matrix_b[i][j];
    }
  }

  vector<vector<int> > result_matrix(rows_a, vector<int>(cols_b, 0));

  for(int i = 0; i < rows_a; i++){
    for(int j = 0; j < cols_b; j++){
      temp_element = 0;
      for(int k = 0; k < rows_b; k++){
        result_matrix[i][j] += matrix_a[i][k] * matrix_b_transposed[j][k];
      }
    }
  }

  return result_matrix;
} 

// Función encargada de tomar el tiempo de ejecución de la multiplicación con la transpuestade la segunda matriz.
long long t1_mmatrix::transposedMultiplicationTime(vector<vector<int> > matrix_a, vector<vector<int> > matrix_b){

    auto start_time = chrono::steady_clock::now();
    vector<vector<int> > result = transposedMultiplication(matrix_a, matrix_b);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    result.clear();
    return duration;

}



