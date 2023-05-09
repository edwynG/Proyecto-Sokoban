#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Sokoban
{
    private:
    string person = "K";
    string caja = "C";
    string muro = "X";
    string punto = "F";

    public:
    void to_upper(string &m);
    void  moverse(string** matriz,int row,int col,char m);
    void searchElement(string** matriz,int row,int col,string L,int arr[],int &tam,int &cantidadElement);
    string getPerson(){return person;};
    string getCaja(){return caja;};
    string getMuro(){return muro;};
    string getPuntofinal(){return punto;};
    void  moverObjetos(string &a, string &b);
};


class setMatriz{

    public:
    setMatriz(){};
    //string** BorderMatriz(string** Matriz, int row,int column);
     void ImprimirMatriz(string** matriz,int row,int column);
    //void borraMatriz(string** matriz,int fila);
    string** generarMatriz(int row,int column, string arr[]);
};

class Game{

    bool initGame = false;
    string** matriz;
    int row=0;
    int col=0;
    bool wins = false;

    public:
    Game(){};

    void juegoEnVivo();
    void juegoCargado();
    void cargarPartida();
    void cargarTablero();
    bool getInitGame(){return initGame;}
    string** getMatriz(){return matriz;}
    void moverSokoban(string &m);
    int getRow(){return row;}
    int getCol(){return col;}
    bool getWins(){return wins;}
    void setWins(bool n){ wins = n;}


};

void menu(){
        setMatriz a;

    Game gameOptions;
    string op = "";
    bool exit = false;

    while (!exit){

        cout <<"1. Juego en vivo"<<endl;
        cout <<"2. Juego cargado."<<endl;
        cout <<"3. Cargar partida." <<endl;
        cout <<"4. Cargar tablero."<<endl;
        cout <<"5. Salir."<<endl;
        cin >> op;

        if(op.size() > 1){
            op[0]=0;
        }

        switch (op[0]){

        case '1':
            if (gameOptions.getInitGame()){

                gameOptions.juegoEnVivo();

            }else{
                cout <<"Debes cargar un tablero"<< endl<<endl;
                }

            break;
        case '2':
            if (gameOptions.getInitGame()){
                void juegoEnVivo();

            }else{
                cout <<"Debes cargar un tablero"<< endl<<endl;;
                }
            break;
        case '3':

            break;
        case '4':
            gameOptions.cargarTablero();
            break;
        case '5':
            exit = true;
            break;

        default:

            cout <<"Opción inválida"<<endl<<endl;
            break;
        }


    }

};

int main(){
        menu();
    return 0;
};

/*juego en vivo*/
void Game::juegoEnVivo(){
    setMatriz view;
    string m = "";
    while ((m != "G" && m != "R") && (getWins() != true)){
        view.ImprimirMatriz(getMatriz(),getRow(),getCol());
        cin>>m;
        moverSokoban(m);

        if(getWins() == true){
            cout<<"Ganaste la partida"<<endl;
        }

    }

}
/*metodo para mover el sokoban que esta implementado en el metodo juegoEnVivo*/
void Game::moverSokoban(string &m){
        Sokoban objeto;
        objeto.to_upper(m);

        for (int i = 0; i < m.size(); i++)
        {
            objeto.moverse(getMatriz(),getRow(),getCol(),m[i]);
        
        }

}

void x(string** m,int n,int x,int y){
    Sokoban a;
    if( m[x+n][y] != "X"){
        string t = m[x][y];
        m[x][y]= m[x+n][y];
        m[x+n][y]=t;
    }
}

void y(string** m,int n,int x,int y){
    Sokoban a;
    if( m[x][y+n] != "X"){
        string t = m[x][y];
        m[x][y]= m[x][y+n];
        m[x][y+n]=t;
    }
}

void a(string** m,int n,int x,int y){
   
}

void Sokoban::moverse(string** matriz,int row,int col,char m){
    int f=0;
    int c=0;
    bool punto=false;
    //busca al socokan
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matriz[i][j] == getPerson())
            {
               f=i;
               c=j;
               break;
            }
            
        }
        
    }
    
    switch (m)
                {
                case 'W':
                       if(matriz[f-1][c] != getMuro()){
                            if(matriz[f-1][c] == getPuntofinal()){
                                matriz[f-1][c] = getPerson();
                                matriz[f][c] = ".";
                                punto=true;
                                break;
                            }
                            if(matriz[f-1][c] == getCaja()){
                                if(matriz[f-2][c] == getPuntofinal()){
                                    matriz[f-2][c]= getCaja();
                                    matriz[f-1][c]=".";
                                    
                                }else{
                                    if(matriz[f-2][c]== getMuro() || matriz[f-2][c]== getCaja()){
                                        break;
                                    }
                                
                                     moverObjetos(matriz[f-2][c],matriz[f-1][c]);
                                }
                                

                            }
                            if(punto){
                                moverObjetos(matriz[f-1][c],matriz[f][c]);
                            matriz[f][c]=getPuntofinal();
                                
                            }else{
                                moverObjetos(matriz[f-1][c],matriz[f][c]);

                            }
                       }

                    break;
                case 'S':
                        if(matriz[f+1][c] != getMuro()){
                            if(matriz[f+1][c] == getCaja()){
                                if(matriz[f+2][c]== getMuro() || matriz[f+2][c]== getCaja()){
                                    break;
                                }
                            moverObjetos(matriz[f+2][c],matriz[f+1][c]);

                            }
                            moverObjetos(matriz[f+1][c],matriz[f][c]);
                       }

                    break;
                case 'A':
                        if(matriz[f][c-1] != getMuro()){
                            if(matriz[f][c-1] == getCaja()){
                                if(matriz[f][c-2]== getMuro() || matriz[f][c-2]== getCaja()){
                                    break;
                                }
                            moverObjetos(matriz[f][c-2],matriz[f][c-1]);

                            }
                            moverObjetos(matriz[f][c-1],matriz[f][c]);
                        }

                    break;
                case 'D':
                        if(matriz[f][c+1] != getMuro()){
                            if(matriz[f][c+1] == getCaja()){
                                if(matriz[f][c+2]== getMuro() || matriz[f][c+2]== getCaja()){
                                    break;
                                }
                            moverObjetos(matriz[f][c+2],matriz[f][c+1]);
                            }
                            moverObjetos(matriz[f][c+1],matriz[f][c]);
                       }
                        
                    break;

                default:
                    break;
                }
    

    // Game tablero;
    // string** terreno = tablero.getMatriz();
    // int caja=0,person =0 ,puntoFinal=0;
    // int i = 0;
    // int* arrPocisiones;
    // searchElement(terreno,tablero.getRow(),tablero.getCol(),getPerson(),arrPocisiones,i,person);
    // searchElement(terreno,tablero.getRow(),tablero.getCol(),getCaja(),arrPocisiones,i,caja);
    // searchElement(terreno,tablero.getRow(),tablero.getCol(),getPuntofinal(),arrPocisiones,i,puntoFinal);
    // arrPocisiones = new int[i];
}

void  Sokoban::moverObjetos(string &a, string &b){
    string t = a;
    a =b;
    b=t;
}

/*metodo para bscar elementos en una matriz y guarda en un array la pocision row y la pocision col, ocupando dos espacios en memoria por cada elemento*/
void Sokoban::searchElement(string** matriz,int row,int col,string L,int arr[],int &tam,int &cantidadElement){

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(matriz[i][j] == L){
                   arr[tam]=i;
                   arr[tam+1]=j;
                   tam+=2;
                   cantidadElement++;
                }
            }

        }

}

/*metodo para cargar tablero*/
void Game::cargarTablero(){
    setMatriz  rellenarMatriz;
    string nameFile;
    cin >> nameFile;
    ifstream File(nameFile.c_str());

    if(File.is_open()){
        while (true)
        {
            File >> row;
            File >> col;
            if(row == col){
                cout<<"Tablero Invalido"<<endl;
                break;
            }
            string line;
            int tam = 0;
            string* arr = new string[row];
            //array dinamico para guardar las lineas de la matriz
            while (tam!= row)
            {
                File >> line;
                arr[tam] = line;
                tam++;
            }
            //funcion para generar la matriz con el array
            matriz = rellenarMatriz.generarMatriz(row,col,arr);
            delete[]arr;
            initGame = true;
            break;
        }
        File.close();

    }else{
        cout <<"Tablero inválido"<<endl;

    }

}

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

/*metodo para generar la matriz con los elementos del archivo*/
string** setMatriz:: generarMatriz(int row,int column, string arr[]){
        string** matriz = new string*[row];
        for (int i = 0; i < row; i++){
            matriz[i]= new string[column];
            for (int j = 0; j < column; j++){
                matriz[i][j] = arr[i][j];
            }
        }
        return matriz;
};

/*metodo covierte en mayusculas un string*/
void Sokoban:: to_upper(string &m){
        for (int i = 0; i < m.size(); i++)
        {
           m[i] = toupper(m[i]);
        }

}
















































// string** setMatriz::BorderMatriz(string** matriz,int row, int column){
//     int i = 0;
//     int j = 0;
//     for (; i < row; i++)
//     {
//         for (; j < column; j++)
//         {
//             matriz[i][j]= "X";
//         }
//         if(i >= 1){
//         matriz[i][j-1]= "X";
//         }

//     }
//     i = row-1;

//     j = j-2;
//     for (; i > 0; i--)
//     {
//         for (; j >= 0; j--){
//             matriz[i][j]="X";
//         }
//         matriz[i-1][j+1]="X";
//     }

//     return matriz;
// };


// void setMatriz::borraMatriz(string** matriz,int fila){
//     for(int i = 0; i < fila; i++){
//         delete[]matriz[i];
//     }
//     delete[]matriz;

// };





