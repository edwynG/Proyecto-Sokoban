#include <iostream>


using namespace std;



struct Sokoban
{
    string person = "K";
    string caja = "C";
    string muro = "X";
};


class setMatriz{
    int b;
    public:
    setMatriz(){};
    string** BorderMatriz(string** Matriz, int row,int column);
     void ImprimirMatriz(string** matriz,int row,int column);
    void borraMatriz(string** matriz,int fila);
};

class Game{
    int a;

    public:
    Game(){};
    
    string** generarMatriz(int row,int column);
    
};

int main(){
        
        Game a;
        setMatriz p;
        //setMatriz a;
       string** m = a.generarMatriz(6,7);
       p.ImprimirMatriz(m,6,7);
        
        
    return 0;
};





string** setMatriz::BorderMatriz(string** matriz,int row, int column){
    int i = 0;
    int j = 0;
    for (; i < row; i++)
    {
        for (; j < column; j++)
        {
            matriz[i][j]= "X";
        }
        if(i >= 1){ 
        matriz[i][j-1]= "X";
        }
       
    }
    i = row-1;  

    j = j-2;
    for (; i > 0; i--)
    {
        for (; j >= 0; j--){
            matriz[i][j]="X";
        }
        matriz[i-1][j+1]="X";
    }

    return matriz;
};

void setMatriz::ImprimirMatriz(string** matriz,int row,int column){
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
                cout<<endl;
        }
    };

};

void setMatriz::borraMatriz(string** matriz,int fila){
    for(int i = 0; i < fila; i++){
        delete[]matriz[i];
    }
    delete[]matriz;
    
};




string** Game:: generarMatriz(int row,int column){
        setMatriz bordes;
        string** matriz= new string*[row];
        for (int i = 0; i < row; i++){
            matriz[i]= new string[column];

            for (int j = 0; j < column; j++){

                matriz[i][j] = ".";

            }
            
        }
        bordes.BorderMatriz(matriz,row,column);

        return matriz;
        
};
