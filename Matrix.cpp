#include <iostream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
using namespace std;

template<class T>
class Node{
public:
    T value;
    Node<T> *nextInRow;
    Node<T> *nextInColumn;
    Node() : nextInRow(nullptr), nextInColumn(nullptr) {} 
    Node(T &v) : value(v), nextInRow(nullptr), nextInColumn(nullptr) {}
    ~Node(){
        delete nextInRow;
        delete nextInColumn;
    }
};

template<class T>
class Matrix{ // M * N Matrix
private:
    int M;
    int N;
    Node<T> *start;
public:
    // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    struct Iterator{
        // Iterator tags
        using iterator_category = std::forward_iterator_tag;
        // using difference_type   = std::count(Iterator(start), Iterator(start->nextInRow));
        using difference_type = std::ptrdiff_t;
        using value_type        = Node<T>;
        using pointer           = Node<T>*;
        using reference         = Node<T>&;

        // Constructor
        Iterator(pointer ptr) : m_ptr(ptr), col_start(ptr) {}
        // Destructor
        ~Iterator(){
            delete curr_ptr;
            delete col_start;
        }

        reference operator*() const { return *curr_ptr; }
        pointer operator->() { return curr_ptr; }

        // Prefix increment
        Iterator& operator++() { 
            if(curr_ptr->nextInRow)
                curr_ptr = curr_ptr->nextInRow; 
            else{
                col_start = col_start->nextInColumn;
                curr_ptr = col_start;
            }
            return *this; 
        }  
        // Postfix increment
        Iterator operator++(int) { 
            Iterator_R tmp = *this; 
            ++(*this); 
            return tmp; 
        }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.curr_ptr == b.curr_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.curr_ptr != b.curr_ptr; }; 

        private:
            pointer curr_ptr;
            pointer col_start;
    };
    Iterator beginR(){
        return Iterator(start); 
    }
    Iterator endR(){
        Node<T> *end = start;
        for(int i=1; i<M; i++)
            end = end->nextInColumn;
        for(int i=1; i<N; i++)
            end = end->nextInRow;
        return Iterator(end->nextInRow);
    }

    Node<T>* getStart() { return start; }
    Matrix() : M(0), N(0), start(nullptr) {}
    ~Matrix(){
        Node<T> *iterR = start;
        Node<T> *iterC = iterR->nextInColumn;
        Node<T> *tmp = iterR;
        for(int i=0; i<M; i++){
            while(iterR != nullptr){
                tmp = iterR;
                iterR = iterR->nextInRow;
                free(tmp);
            }
            iterR = iterC;
            iterC = iterC->nextInColumn;
        }
    }
    Matrix(T **arr, int m, int n) : M(m), N(n){
        start = new Node<T>(arr[0][0]);
        Node<T> *prevRow = start; // previous row's iter
        Node<T> *curr = start; // current row's iter
        // Link 1st row
        for(int i=0; i<n-1; i++){
            curr->nextInRow = new Node<T>(arr[0][i+1]);
            curr = curr->nextInRow;
        }
        // Link 1st column
        curr = start;
        for(int i=1; i<m; i++){
            curr->nextInColumn = new Node<T>(arr[i][0]);
            curr = curr->nextInColumn;
        }
        
        Node<T> *currHead = start->nextInColumn; // current row's head
        for(int i=1; i<m; i++){
            curr = currHead;
            for(int j=1; j<n; j++){
                prevRow = prevRow->nextInRow;
                Node<T> *tmp = new Node<T>(arr[i][j]);
                prevRow->nextInColumn = tmp;
                curr->nextInRow = tmp;
                curr = curr->nextInRow;
            }
            prevRow = currHead;
            currHead = currHead->nextInColumn;
        }
    }
    Matrix(const Matrix<T>& mat){
        M = mat.M;
        N = mat.N;

        start = new Node<T>(mat.start->value); // (*start).value EQ start->value

        Node<T> *currStart = mat.start; // Points to mat
        Node<T> *cS = start; // Points to calling object
        for(int i=0; i<M; i++){
            Node<T> *curr = currStart; // Points to mat
            Node<T> *c = cS; // Points to calling object
            for(int j=0; j<N; j++){
                if(j < N - 1)
                    c->nextInRow = new Node<T>(curr->nextInRow->value);
                if(i < M - 1)
                    c->nextInColumn = new Node<T>(curr->nextInColumn->value);
                curr = curr->nextInRow;
                c = c->nextInRow;
            }
            currStart = currStart->nextInColumn;
            cS = cS->nextInColumn;
        }
    }
    Matrix<T>& operator= (const Matrix<T> &mat){
        if(this == &mat) // Point to the same memory location
            return *this;
        if(start != nullptr){ // Clean up previous memory
            Node<T> *iterR = start; // The iter for current row
            Node<T> *iterC = iterR->nextInColumn;
            Node<T> *tmp = iterR;
            for(int i=0; i<M; i++){
                while(iterR != nullptr){
                    tmp = iterR;
                    iterR = iterR->nextInRow;
                    free(tmp);
                }
                iterR = iterC;
                iterC = iterC->nextInColumn;
            }
        }
        M = mat.M;
        N = mat.N;
        start = mat.start;
        return *this;
    }
    Matrix<T>* getRow(int row){
        // Finding the starting Node for the column that we want.
        Node<T> *rowHead = start;
        for(int i=1; i<row; i++)
            rowHead = rowHead->nextInColumn;

        // Construct the 2D array
        T **arr = new T*[1];
        arr[0] = new T[N];
        
        for(int i=0; i<N; i++){
            arr[0][i] = rowHead->value;
            rowHead = rowHead->nextInRow;
        }
        // Using the parameterized constructor to get the 1 * N Matrix
        return new Matrix<T>(arr, 1, N);
    }
    Matrix<T>* getColumn(int col){
        Node<T> *colHead = start;
        for(int i=1; i<col; i++)
            colHead = colHead->nextInRow;
        
        // Construct the 2D Array
        T **arr = new T*[M];
        for(int i=0; i<M; i++)
            arr[i] = new T[1];

        for(int i=0; i<M; i++){
            arr[i][0] = colHead->value;
            colHead = colHead->nextInColumn;
        }

        return new Matrix<T>(arr, M, 1);
    }
    T getElement(int r, int c){
        Node<T> *iter = start;
        for(int i=1; i<r; i++)
            iter = iter->nextInColumn;
        for(int i=1; i<c; i++)
            iter = iter->nextInRow;
        return iter->value;
    }
    Matrix<T>& operator + (const Matrix<T> &mat){
        Node<T> *cS = start;
        Node<T> *cS_ = mat.start;
        Node<T> *curr;
        Node<T> *curr_;
        for(int i=0; i<M; i++){
            curr = cS;
            curr_ = cS_;
            for(int j=0; j<N; j++){
                curr->value += curr_->value;
                curr = curr->nextInRow;
                curr_ = curr_->nextInRow;
            }
            cS = cS->nextInColumn;
            cS_ = cS_->nextInColumn;
        }
        return *this;
    }
    Matrix<T>& operator * (const Matrix<T> &mat){
        Node<T> *cS = start;
        Node<T> *cS_ = mat.start;
        Node<T> *curr;
        Node<T> *curr_;
        for(int i=0; i<M; i++){
            curr = cS;
            curr_ = cS_;
            for(int j=0; j<N; j++){
                curr->value *= curr_->value;
                curr = curr->nextInRow;
                curr_ = curr_->nextInRow;
            }
            cS = cS->nextInColumn;
            cS_ = cS_->nextInColumn;
        }
        return *this;
    }
    void print(){
        Node<T> *currStart = start;
        for(int i=0; i<M; i++){
            Node<T> *curr = currStart;
            cout<<"[";
            for(int j=0; j<N; j++){
                cout<<curr->value<<" ";
                curr = curr->nextInRow;
            }
            cout<<"]\n";
            currStart = currStart->nextInColumn;
        }
    }
    friend ostream& operator << (ostream &out, const Matrix<T> &mat){
        Node<T> *currStart = mat.start;
        Node<T> *curr = currStart;
        out<<"[";
        for(int i=0; i<mat.M-1; i++){
            curr = currStart;
            out<<"[";
            for(int j=0; j<mat.N-1; j++){
                out<<curr->value<<", ";
                curr = curr->nextInRow;
            }
            out<<curr->value<<"]\n";
            currStart = currStart->nextInColumn;
        }
        curr = currStart;
        out<<"[";
        for(int j=0; j<mat.N-1; j++){
            out<<curr->value<<", ";
            curr = curr->nextInRow;
        }
        out<<curr->value<<"]]\n";

        return out;
    }
    friend istream& operator>> (istream &in, Matrix<T> &mat){
        cout<<"Enter number of rows: \n";
        in >> mat.M;
        cout<<"Enter number of columns: \n";
        in >> mat.N;

        T **arr = new T*[mat.M];
        for(int i=0; i<mat.M; i++)
            arr[i] = new T[mat.N];
        
        cout<<"Enter values: \n";
        for(int i=0; i<mat.M; i++){
            for(int j=0; j<mat.N; j++)
                in >> arr[i][j];            
        }
        Matrix<T> *tmp = new Matrix<T>(arr, mat.M, mat.N);
        mat = *tmp;
        return in;
    }
};

int main(){
    // Initialize 2D Array
    int M = 3, N = 4;
    int **arr = new int*[M];
    int **arr2 = new int*[M];
    for(int i=0; i<M; i++){
        arr[i] = new int[N];
        arr2[i] = new int[N];
    }
    
    // Assigning Values for 2D Array
    int val = 1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = val;
            arr2[i][j] = 2 * val;
            val++;
        }
    }

    // Matrix Creation
    Matrix<int> mat(arr, M, N);
    Matrix<int> mat1(arr2, M, N);

    // Copy constructor (Either one of the following line)
    Matrix<int> mat2(mat); 
    // Matrix<int> mat2 = mat;

    // Assignment Operator
    Matrix<int> mat3;
    mat3 = mat1;

    // Matrix Printing
    cout<<"mat:\n";
    mat.print();
    // cout<<"mat1:\n";
    // mat1.print();
    // cout<<"mat2:\n";
    // mat2.print();
    // cout<<"mat3:\n";
    // mat3.print();

    // int row = 2;
    // cout<<"The "<<row<<" th row is: \n";
    // mat.getRow(row)->print();

    // cout<<"------------\n";

    // int col = 4;
    // cout<<"The "<<col<<" th column is: \n";
    // mat.getColumn(col)->print();

    // cout<<"Matrix["<<row<<", "<<col<<"]: "<<mat.getElement(row, col)<<endl;

    // cout<<"mat + mat1: "<<endl;
    // (mat + mat1).print();
    // cout<<"mat2 * mat1: "<<endl;
    // (mat2 * mat1).print();

    // cout<<"mat3:\n"<<mat3<<endl;

    // Matrix<int> mat4;
    // cout<<"Create Matrix:\n";
    // cin >> mat4;

    // cout<<"mat4:\n"<<mat4<<endl;

    Matrix<int> *mat_p = new Matrix<int>(arr, M, N);
    
    cout<<"Iterator for mat_p:\n";
    for(Matrix<int>::Iterator it = mat_p->begin(); it != mat_p->end(); ++it)
        cout<<it->value<<" ";

    // Free Memory Spaces
    for(int i=0; i<M; i++){
        delete[] arr[i];
        delete[] arr2[i];
    }
    delete[] arr;
    delete[] arr2;

    return 0;
}
