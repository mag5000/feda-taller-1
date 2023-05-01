#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Función encargada de crear el dataset de arreglos desordenados dados los parametros establecidos en el main.
void createRandomArrayDataset(int arr_jump, int arr_min_size, int arr_max_size, int arr_max_element){

	ofstream outfile("random_array_dataset.txt");
	int size;
	int element;
	srand(time(NULL));

	for (int i = arr_min_size; i <= arr_max_size; i+=arr_jump){
	  outfile << i <<endl;
	  for (int k=0; k < i; k++){
        element = rand()%arr_max_element;
        outfile << element <<" ";
      
      }
      outfile << endl;
    }
	outfile.close();
}

// Función encargada de crear el dataset de arreglos ordenados dados los parametros establecidos en el main.
void createOrderedArrayDataset(int arr_jump, int arr_min_size, int arr_max_size, int arr_max_element){

	ofstream outfile("ordered_array_dataset.txt");
	int size;
	int element;
	srand(time(NULL));
	vector<int> temp_array;

	for (int i = arr_min_size; i <= arr_max_size; i+=arr_jump){
	  outfile << i <<endl;
	
	  for (int k=0; k < i; k++){
        element = rand()%arr_max_element;
        temp_array.push_back(element);
      }

      sort(temp_array.begin(), temp_array.end());

      for (int k=0; k < i; k++){
        outfile << temp_array[k] <<" ";
      
      }

      outfile << endl;
      temp_array.clear();
    }
	outfile.close();
}

// Función encargada de crear el dataset de arreglos ordenados de forma inversa dados los 
// parametros establecidos en el main.
void createReverseOrderedArrayDataset(int arr_jump, int arr_min_size, int arr_max_size, int arr_max_element){

	ofstream outfile("reverse_ordered_array_dataset.txt");
	int size;
	int element;
	srand(time(NULL));
	vector<int> temp_array;

	for (int i = arr_min_size; i <= arr_max_size; i+=arr_jump){
	  outfile << i <<endl;
	
	  for (int k=0; k < i; k++){
        element = rand()%arr_max_element;
        temp_array.push_back(element);
      }

      sort(temp_array.rbegin(), temp_array.rend());

      for (int k=0; k < i; k++){
        outfile << temp_array[k] <<" ";
      
      }

      outfile << endl;
      temp_array.clear();
    }
	outfile.close();
}

// Función encargada de crear el dataset de arreglos parcialmente ordenados dados los 
// parametros establecidos en el main. Para ello primero crea un arreglo aleatorio y luego 
// ordena la mitad del arreglo desde una posición al azar (entre el inicio y la mitad).
void createSemiOrderedArrayDataset(int arr_jump, int arr_min_size, int arr_max_size, int arr_max_element){

	ofstream outfile("semi_ordered_array_dataset.txt");
	int size;
	int element;
	int ord_start;
	vector<int> temp_array;

	srand(time(NULL));

	for (int i = arr_min_size; i <= arr_max_size; i+=arr_jump){
	  outfile << i <<endl;

	  for (int k=0; k < i; k++){
	  	element = rand()%arr_max_element;
        temp_array.push_back(element);
      }

	  ord_start = rand()%(i/2);
      sort(temp_array.begin()+ord_start, temp_array.begin()+ord_start+(i/2));

      for (int k=0; k < i; k++){
        outfile << temp_array[k] <<" ";
      
      }

      outfile << endl;
      temp_array.clear();
    }
	outfile.close();
}


int main() {

	int arr_jump = 20;
	int arr_min_size = 20;
	int arr_max_size = 1000;
	int arr_max_element = 10000;

	createRandomArrayDataset(arr_jump, arr_min_size, arr_max_size, arr_max_element);	
	createOrderedArrayDataset(arr_jump, arr_min_size, arr_max_size, arr_max_element);
	createReverseOrderedArrayDataset(arr_jump, arr_min_size, arr_max_size, arr_max_element);	
	createSemiOrderedArrayDataset(arr_jump, arr_min_size, arr_max_size, arr_max_element);
	return 0;

}

