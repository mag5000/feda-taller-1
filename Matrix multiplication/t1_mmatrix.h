using namespace std;

class t1_mmatrix{

  private:

    vector<vector<int>> addMatrix(vector<vector<int>> matrix_a, vector<vector<int> > matrix_b, int split_index, int multiplier=1);
    
  public:
    t1_mmatrix();
    ~t1_mmatrix();
    vector<vector<int>> strassenMultiplication(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b);
    vector<vector<int>> standartMultiplication(vector<vector<int> >  matrix_a, vector<vector<int> >  matrix_b);
    vector<vector<int>> transposedMultiplication(vector<vector<int> >  matrix_a, vector<vector<int> >  matrix_b);
    long long strassenMultiplicationTime(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b);
    long long standartMultiplicationTime(vector<vector<int> >  matrix_a, vector<vector<int> >  matrix_b);
    long long transposedMultiplicationTime(vector<vector<int> >  matrix_a, vector<vector<int> >  matrix_b);

};
