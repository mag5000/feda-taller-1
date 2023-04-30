using namespace std;

class t1_sort{

  private:
    void merge(int arr[], int left, int mid,int right);
    int partition(int arr[], int low, int high);
    void swap(int *xp, int *yp);
    void imprimir(int array_copy[], int size);
  public:
    t1_sort();
    ~t1_sort();  

    void bubbleSort(int array[], int size);
    void mergeSort(int array[], int begin, int end);
    void quickSort(int array[], int low, int high);
    void stlSort(int array[], int n);

    long long bubbleSortTime(int array[], int size);
    long long mergeSortTime(int array[], int size);
    long long quickSortTime(int array[], int size);
    long long stlSortTime(int array[], int size);


};
