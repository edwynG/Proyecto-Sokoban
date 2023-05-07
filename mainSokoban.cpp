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
    void leerArchivo();
    string** generarMatriz(int row,int column);
    
};

void menu(){
    int op = 0;
    bool exit = false;

    while (!exit){

    cout <<"1. Juego en vivo"<<endl;
    cout <<"2. Juego cargado."<<endl;
    cout <<"3. Cargar partida." <<endl;
    cout <<"4. Cargar tablero."<<endl;
    cout <<"5. Salir."<<endl;
    cin >> op;

    switch (op){ 
    
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        exit = true;
        break;
    
    default:
    
        cout <<"Opción inválida"<<endl;
        break;
    }
       
    
    }
    
};

int main(){
        menu();  
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
