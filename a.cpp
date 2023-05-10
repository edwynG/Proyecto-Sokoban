#include <iostream>
#include <fstream>

using namespace std;
// void cargarTablero(string name){
//     setMatriz  rellenarMatriz;
//     ifstream File(name.c_str());

//     if(File.is_open()){
//         while (true)
//         {
//             File >> row;
//             File >> col;
//             if(row == col){
//                 cout<<"Tablero Invalido"<<endl;
//                 break;
//             }
//             string line;
//             int tam = 0;
//             string* arr = new string[row];
//             //array dinamico para guardar las lineas de la matriz
//             while (tam!= row)
//             {
//                 File >> line;
//                 arr[tam] = line;
//                 tam++;
//             }
//             //funcion para generar la matriz con el array
//             matriz = rellenarMatriz.generarMatriz(row,col,arr);
//             delete[]arr;
//             initGame = true;
//             break;
//         }
//         File.close();

//     }else{
//         cout <<"Tablero inválido"<<endl;

//     }

// }

// void ImprimirMatriz(string** matriz,int row,int column){
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//            cout<<matriz[i][j];
//             if(j == column-1){
//                 cout<<endl;
//             }
//         }
//         if(i == row-1){
//                 //cout<<endl;
//         }
//     };

// };

// /*metodo para generar la matriz con los elementos del archivo*/
// string** generarMatriz(int row,int column, string arr[]){
//         string** matriz = new string*[row];
//         for (int i = 0; i < row; i++){
//             matriz[i]= new string[column];
//             for (int j = 0; j < column; j++){
//                 matriz[i][j] = arr[i][j];
//             }
//         }
//         return matriz;
// };

void dataArr(string m[6][7],int row,int col,string arr[]){
    string a="",b="",c;
    for (int i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            a+= m[i][j];
            
        }
        cout<<a<<endl;
        //a+="\n";
        arr[i]= a;
        a="";
    }
    
}

void isCorrectoLimite(string matriz[][7],int row, int col){
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1) { // Primer y última fila
                matriz[i][j]="X";
            } else if (j == 0 || j == col-1) { // Primer y última columna
                 matriz[i][j] ="X";
            }
        }
        
    }

    
};

void ImprimirMatriz(string matriz[][7],int row,int column){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
           cout<<matriz[i][j];
            if(j == column-1){
                cout<<endl;
            }
        }
        if(i == row-1){
                //cout<<endl;
        }
    };

};

bool isCorrectoMatriz(string A[],int row,int col,int n){
    string a="";
    if( n != row){
        return 0;
    }
    cout<< row*col<<endl;
    for (int i = 0; i < row; i++)
    {
        a+=A[i];
    }
    cout<< a.size()<<endl;

    if( a.size() != row*col){
        return 0;
    }
    return 1;
}

int main(){
    
    string m[6][7]={{"a","b","c","d","e","h","i"},
                    {"j","k","l","n","m","o","p"},
                    {"q","r","s","t","u","v","w"},
                    {"x","y","z","1","2","3","4"},
                    {"5","6","7","8","9","1","1"},
                    {"1","1","1","1","1","1","1"},
                    };
    string arr[10000];
    // ImprimirMatriz(m,6,7);
    // cout<<endl;
    // isCorrectoLimite(m,6,7);
    // ImprimirMatriz(m,6,7);

    dataArr(m,6,7,arr);
  isCorrectoMatriz(arr,6,7,6);
    // for (size_t i = 0; i < 6; i++)
    // {
        
        
    //         cout<<arr[i];
       
        
    // }
    

    return 0;
}



