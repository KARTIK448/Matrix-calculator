#include <iostream>
#include<fstream>
using namespace std;
class Matrix {
public:
    int rows, cols;
    int** data;

      void inputMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() 
    {
        {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
        }
    }
};
class func : public Matrix
{
    public:
    func(int rows,int cols) {
        this->rows = rows;
        this->cols = cols;

       
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }
  
    public :
    func operator +(const func mat2){
        func temp(rows,cols);
        for(int i=0;i<rows;i++)
        {for (int j=0;j<rows;j++){
        temp.data[i][j]=data[i][j]+mat2.data[i][j];
        }
     }
     return temp;
     }
     public :
     func operator -(const func mat2){
        func temp(rows,cols);
        for(int i=0;i<rows;i++)
        {for (int j=0;j<rows;j++){
        temp.data[i][j]=data[i][j]-mat2.data[i][j];
        }}
     return temp;
     }
     public :
      func operator *(func mat2){
        func temp(rows,cols);
        for(int i=0;i<rows;i++)
        {for (int j=0;j<rows;j++){
         temp.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    temp.data[i][j] += data[i][k] * mat2.data[k][j];
        }}
        }
     return temp;
     
      }

    ~func() {
        
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int rows, cols,n,x;
    cout<<".........WELCOME TO MATRIX CALCULATOR.................\n";

    cout << "Enter dimensions of matrices:" << endl;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;
    cout<<"enter the number of matrices you want to add(2 or 3):";
    cin>>n;

    func matrix1(rows, cols);
    func matrix2(rows, cols);
    func matrix3(rows,cols);
    if (n==2){
    cout<<"enter the first matrix:\n ";
    matrix1.inputMatrix();
    cout<<"enter the second matrix:\n ";
    matrix2.inputMatrix();
    cout << "Matrix 1:" << endl;
    matrix1.displayMatrix();
    cout << "Matrix 2:" << endl;
    matrix2.displayMatrix();
    }
    else if(n==3){
        cout<<"enter the first matrix:\n ";
    matrix1.inputMatrix();
    cout<<"enter the second matrix:\n ";
    matrix2.inputMatrix();
    
    cout<<"enter the third matrix:\n ";
    matrix3.inputMatrix();
     cout << "Matrix 1:" << endl;
    matrix1.displayMatrix();
    cout << "Matrix 2:" << endl;
    matrix2.displayMatrix();
     cout << "Matrix 3:" << endl;
    matrix3.displayMatrix();

    }
    else{
        cout<<"invalid input";
        exit(1);
    }
    cout<<"enter the operation you want to perform on these matrices\n";
    cout<<"1.addition\n2.subtraction\n3.Multiplication\n4.Exit\n";
    cin>>n;
    switch(n){

    case 1:{
        if(n==2){
    func sum = matrix1+matrix2;
    cout << "Sum:" << endl;
    sum.displayMatrix();
    break;}
        else{
            func sum=(matrix1+matrix2)+matrix3;
            cout<<"sum:"<<endl;
            sum.displayMatrix();
            break;
        }
    }

    case 2:{
         if(n==2){
    func difference = matrix1-matrix2;
    cout << "Difference:" << endl;
    difference.displayMatrix();
    break;}
          else{
            func sum=(matrix1-matrix2)-matrix3;
            cout<<"sum:"<<endl;
            sum.displayMatrix();
            break;
          }

    case 3:{
        if(n==2){

    if (matrix1.cols == matrix2.rows) {
        func product = matrix1*matrix2;
        cout << "Product:" << endl;
        product.displayMatrix();
    } else {
        cout << "Matrices cannot be multiplied due to incompatible dimensions." << endl;
    }
    break;
    }
      else{
        if (matrix1.cols == matrix2.rows&& matrix2.rows==matrix3.cols) {
        func product = matrix1*matrix2*matrix3;
        cout << "Product:" << endl;
        product.displayMatrix();
    } else {
        cout << "Matrices cannot be multiplied due to incompatible dimensions." << endl;
    }
     break;
      }
    }
    case 4:{
        cout<<"thanks for using matrix calculator";
        break;
    }
    }

    return 0;

}
}