#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstring>
#include "t1_sort.h"
using namespace std;

// Constructor y destructor de la clase t1_sort
t1_sort::t1_sort(){}
t1_sort::~t1_sort(){}


// Funcion que sirve para intercambiar elementos de un array, es llamada por las funciones
// de ordenamiento de Bubble Sort, Selection Sort, 
// Fuente: obtenida de https://www.geeksforgeeks.org
void t1_sort::swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort: funcion de ordenamiento que recorre todo el algoritmo comparando los elementos
// adyacentes e intercambiando aquellos que se encuentran en el orden incorrecto. En esta versión
// optimizada el arreglo es recorrido hasta que ya no se intercambian elementos. 
// Fuente: https://www.geeksforgeeks.org 
void t1_sort::bubbleSort(int array[] , int size){
  
   bool swapped;
   for (int i = 0; i < size-1; i++){
     swapped = false;
     for (int j = 0; j < size-i-1; j++){
        if (array[j] > array[j+1]){
           swap(&array[j], &array[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}

// Funcion que toma el tiempor de ejecución de Bubble Sort
long long t1_sort::bubbleSortTime(int array[], int size){

    int array_copy[size]; 
    memcpy(array_copy, array, sizeof(int)*size);
    auto start_time = chrono::steady_clock::now();
    bubbleSort(array_copy, size);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

//    imprimir(array_copy, size);

    return duration;

}


// Merge Sort: Algoritmo de ordenamiento que se basa en la combinación y ordenamiento de 2 
// subarreglos ordenados. Su funcionamiento se basa en el paradigma de dividir para conquistar, 
// dividiendo el arreglo que debe ser ordenado en subarreglos cada vez mas pequeños para finalmente
// combinarlos de manera ordenada recursivamente.
// Fuente: https://www.geeksforgeeks.org
void t1_sort::mergeSort(int arr[], int begin, int end){

    if (begin >= end){
        return;
    }
 
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

// Función encargada de tomar el tiempo de ejecución de Merge Sort 
long long t1_sort::mergeSortTime(int array[] , int size){

    int array_copy[size]; 
    memcpy(array_copy, array, sizeof(int)*size);

    auto start_time = chrono::steady_clock::now();
    mergeSort(array_copy, 0, size-1);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

//    imprimir(array_copy, size);

    return duration;

}

// Función encargada de combinar los 2 subarreglos en un arreglo ordenado
void t1_sort::merge(int array[], int left, int mid, int right){

    int sub_array_one_size = mid - left + 1;
    int sub_array_two_size = right - mid;
    int* left_array = new int[sub_array_one_size];
    int* right_array = new int[sub_array_two_size];
 
    for (int i = 0; i < sub_array_one_size; i++){
        left_array[i] = array[left + i];
    }

    for (int i = 0; i < sub_array_two_size; i++){
        right_array[i] = array[mid + 1 + i];
    }
 
    int sub_one_index = 0;
    int sub_two_index = 0;
    int merged_index = left;
 
    // combina los 2 subarreglos en un uno
    while (sub_one_index < sub_array_one_size && sub_two_index < sub_array_two_size){
        if (left_array[sub_one_index] <= right_array[sub_two_index]){
            array[merged_index] = left_array[sub_one_index];
            sub_one_index++;
        }
        else {
            array[merged_index] = right_array[sub_two_index];
            sub_two_index++;
        }
        merged_index++;
    }
    // Copia los elementos del arreglo de la izquierda si es que quedan
    while (sub_one_index < sub_array_one_size){
        array[merged_index] = left_array[sub_one_index];
        sub_one_index++;
        merged_index++;
    }
    // Copia los elementos del arreglo de la derecha si es que quedan
    while (sub_two_index < sub_array_two_size){
        array[merged_index] = right_array[sub_two_index];
        sub_two_index++;
        merged_index++;
    }
    delete[] left_array;
    delete[] right_array;
}


// Quick Sort: Esta funcion toma un elemento del arreglo como pivote y deja
// a la izquierda todos los elementos que deberian ir antes y a la derecha los 
// que deberían ir despues (en nuestro caso más pequeños a la izquierda y más grandes
// a la derecha), dejando al pivote en su posisción correcta. 
// En este caso el pivote es seleccionado al azar.
// Fuente: https://www.geeksforgeeks.org
void t1_sort::quickSort(int array[], int low, int high){

  if (low < high){

    // particiona el arreglo y deja al pivote en la posicion correcta
    int partition_index = partition(array, low, high);

    // se llama recursivamente con las partes no ordenadas del arreglo
    quickSort(array, low, partition_index - 1);
    quickSort(array, partition_index + 1, high);
  }
}

// Funcion que se encarga de encontrar un elemento pivote y dejar a la izquierda
// los elementos de menor tamaño que el pivote y a la derecha los más grandes.
// Retorna la posición del pivote.
int t1_sort::partition(int array[], int low, int high){
 
  // creación del pivote e intercambio con la posición final 
  int pivot_index = rand()%(high+1-low)+low;
  int pivot = array[pivot_index];
  swap(&array[pivot_index], &array[high]);

  int temp_index = (low - 1);

  for (int i = low; i < high ; i++){

      if (array[i] <= pivot) {
          temp_index++;
          swap(&array[temp_index], &array[i]);
      }
  }

  swap(&array[temp_index + 1], &array[high]);
  
  return (temp_index + 1);

}

// Funcion que toma el tiempo de ejecución de Quick Sort
long long t1_sort::quickSortTime(int array[], int size){

    int array_copy[size]; 
    memcpy(array_copy, array, sizeof(int)*size);
    auto start_time = chrono::steady_clock::now();
    quickSort(array_copy, 0, size-1);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();


//    imprimir(array_copy, size);

    return duration;

}

    
// Ordenamiento de la libreria estandart (STL): Este Algoritmo de ordenamiento es un algoritmo
// combinado que utiliza Quicksort, Heapsort e Insertionsort, en caso de que el arreglo a ordenar 
// sea pequeño utiliza insertion sort, ahora, en otros casos utiliza por defecto usa Quick Sort y
// cambia a heapsort al llegar a cierta profundidad.
// Fuente: https://www.geeksforgeeks.org

void t1_sort::stlSort(int array[], int n){

   sort(array,array + n);

}

long long t1_sort::stlSortTime(int array[], int size){

    int array_copy[size]; 
    memcpy(array_copy, array, sizeof(int)*size);
    auto start_time = chrono::steady_clock::now();
    stlSort(array_copy, size);
    auto end_time = chrono::steady_clock::now();
    long long duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

//    imprimir(array_copy, size);

    return duration;

}



// Funcion para imprimir los arreglos ordenados (para revision)
void t1_sort::imprimir(int array[], int size){

   for(int i =0;i<size;i++){
        cout<<array[i]<<" ";
   }
   cout<<endl;

}