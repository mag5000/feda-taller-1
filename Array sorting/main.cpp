#include <iostream>
#include <fstream>
#include <vector>

#include "t1_sort.h"

using namespace std;

// Función para imprimir los arreglos
// Fuente: Elaboración propia
void printArray(string algName, int arr[], int size)
{
   cout<<algName<<": "<<endl;
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


// Funcion que sirve para leer el dataset de arreglos que seran ordenados
// recibe la ruta definida en el main.
// Fuente: elaboración propia basado en lo enseñado por Vicente Lermanda
vector <vector<int>> readArrayDataset(string route){

  int size = 0;
  vector<vector<int>> arrays;
  ifstream inputfile(route);

  while(inputfile>>size){
    if(size>0){
      vector<int> temp_vector(size);
      for(int i=0; i<size;i++){
        inputfile>>temp_vector[i];
      }   
      arrays.push_back(temp_vector);
      temp_vector.clear();
    }
  }
  return arrays;
}


// Funcion que toma el tiempo de ejecucion de los algoritmos de ordenamiento
// y los guarda en un archivo de texto denominado "array_sorting_time.txt" 
// en la carpeta output
void takeSortingTime(int exp_x_array, vector< vector<int>> arrays){

  int* temp_array;
  int temp_array_size;
  t1_sort *sort = new t1_sort();

  long long int bubble_sort_time = 0;
  long long int merge_sort_time = 0;
  long long int stl_sort_time = 0;
  long long int quick_sort_time = 0;

  long long int avg_bubble_sort_time;
  long long int avg_merge_sort_time;
  long long int avg_stl_sort_time;
  long long int avg_quick_sort_time;

  ofstream outfile("output/results.csv");
  outfile << "size, algorithm, time\n";

  for(int k = 0; k<arrays.size(); k++){ 

    temp_array_size = arrays[k].size();
    temp_array = new int[temp_array_size];

    for(int i = 0; i<temp_array_size; i++){
      temp_array[i] = arrays[k][i];
    }

    for(int i =0;i< exp_x_array;i++){


      bubble_sort_time += sort->bubbleSortTime(temp_array, temp_array_size);
      merge_sort_time += sort->mergeSortTime(temp_array, temp_array_size);
      quick_sort_time += sort->quickSortTime(temp_array, temp_array_size);
      stl_sort_time += sort->stlSortTime(temp_array, temp_array_size);

    }

    avg_bubble_sort_time = bubble_sort_time/exp_x_array;
    avg_merge_sort_time= merge_sort_time/exp_x_array;
    avg_quick_sort_time= quick_sort_time/exp_x_array;
    avg_stl_sort_time=stl_sort_time/exp_x_array;

    outfile << temp_array_size << ",Bubble Sort,"<< avg_bubble_sort_time << endl;
    outfile << temp_array_size << ",Merge Sort,"<< avg_merge_sort_time << endl;
    outfile << temp_array_size << ",Quick Sort,"<< avg_quick_sort_time << endl;
    outfile << temp_array_size << ",STL Sort,"<< avg_stl_sort_time << endl;

  }

  outfile.close(); 

}


int main(){

  vector<vector<int>> arrays = readArrayDataset("datasets/random_array_dataset.txt");
  takeSortingTime(10, arrays);
  return 0;

}