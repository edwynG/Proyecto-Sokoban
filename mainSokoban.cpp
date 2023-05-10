#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct arrF
{
    int a;
    int b;

};
 arrF Puntos[100000000];
 arrF Cajas[100000000];

     int n=0;
     string name;
    int cantidadCaja=0;
    int cantidadPuntos=0;
   
    class Sokoban
{
    private:
    string person = "K";
    string caja = "C";
    string muro = "X";
    string punto = "F";
    bool ispunto=false;

    public:
    void to_upper(string &m);
    void  moverse(string** matriz,int row,int col,char m);
   // void searchElement(string** matriz,int row,int col,string L,int arr[],int &tam,int &cantidadElement);
    string getPerson(){return person;};
    string getCaja(){return caja;};
    string getMuro(){return muro;};
    string getPuntofinal(){return punto;};
    void  moverObjetos(string &a, string &b);
    void set_is_punto(bool op){ispunto = op;}
    bool get_is_punto(){return ispunto;}
    void buscarSokoban(string** matriz,int row,int col,int &a,int &b);
    void EncontrarPuntos(string** matriz,int row,int col,arrF arr[],int &n,string L);
    void typeData(string m);
    void setSokoban(string n){ person=n;}
    void setMuro(string n){ muro=n;}
    void setCaja(string n){ caja=n;}
    void setPuntofinal(string n){ punto=n;}

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
    string** matrizCargada;
    int row=0;
    int col=0;
    bool wins = false;

    public:
    Game(){};

    void juegoEnVivo();
    void juegoCargado();
    void cargarPartida();
    void cargarTablero(string name);
    bool getInitGame(){return initGame;}
    string** getMatriz(){return matriz;}
    void moverSokoban(string &m,bool op);
    int getRow(){return row;}
    int getCol(){return col;}
    bool getWins(){return wins;}
    void setWins(bool n){ wins = n;}
    void isWins(string **matriz,int row,int col);
    void borraMatriz(int tam, string **matriz);
    void  cacheData(string** matriz,int row,int col,string dataArr[],int n);
    void saveTable(string** matriz,int row,int col);
    bool isCorrecMatrix(string** matriz,int row,int col);
    bool isCorrectoLimite(string** m,int row, int column);
    bool isCorrectoMatriz(string A[],int row, int col,int n);
    string** getMatrizCargada(){ return matrizCargada;}
    void restaurarMatriz(string** m){matriz = m;}

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
                     gameOptions.juegoCargado();


            }else{
                cout <<"Debes cargar un tablero"<< endl<<endl;;
                }
            break;
        case '3':

            break;
        case '4':
            cin>>name;
            gameOptions.cargarTablero(name);
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
    Sokoban objeto;
    while (!getWins()){
        view.ImprimirMatriz(getMatriz(),getRow(),getCol());
        cin>>m;
        objeto.to_upper(m);
        if(m == "R"){break;}

        moverSokoban(m,false);
        if(m == "G"){break;}
        isWins(getMatriz(),getRow(),getCol());

        if(getWins()){
            view.ImprimirMatriz(getMatriz(),getRow(),getCol());
            cout<<"Ganaste la partida"<<endl;
           
        }

    }
    setWins(false);
    borraMatriz(getRow(),getMatriz());
    restaurarMatriz(getMatrizCargada());
    
}

 void Game::juegoCargado(){
        string m;
        setMatriz view;
        cin>>m;
    if(m != "r" && m != "R"){ 
        moverSokoban(m,true);
        isWins(getMatriz(),getRow(),getCol());
        if(getWins()){
            view.ImprimirMatriz(getMatriz(),getRow(),getCol());
            cout<<"Ganaste la partida"<<endl;
            setWins(false);
            borraMatriz(getRow(),getMatriz());
            restaurarMatriz(getMatrizCargada());

           
        }else{
            juegoEnVivo();
        }
    }else{
        borraMatriz(getRow(),getMatriz());
        restaurarMatriz(getMatrizCargada());

    }
    }


/*metodo para mover el sokoban que esta implementado en el metodo juegoEnVivo*/
void Game::moverSokoban(string &m,bool op){
        Sokoban objeto;
        objeto.to_upper(m);
        
        for (int i = 0; i < m.size(); i++){ 
            objeto.moverse(getMatriz(),getRow(),getCol(),m[i]);
            if(!op){
                break;
            }
        }

}

void Game::isWins(string **matriz,int row,int col){
    Sokoban obj;
   
    if(cantidadPuntos > cantidadCaja){
        for (int i = 0; i < cantidadCaja; i++)
        {
            if(matriz[Cajas[i].a][Cajas[i].b] !=  matriz[Puntos[i].a][Puntos[i].b]){
                setWins(false);
                break;
            }else{
                setWins(true);
            }
        }
        
        
    }else{
        for (int i = 0; i < cantidadPuntos; i++)
        {
            if( matriz[Puntos[i].a][Puntos[i].b] != obj.getCaja()){
                    setWins(false);
                    break;
            }else{
                    setWins(true);
            }
        }
    }

}


void Sokoban::moverse(string** matriz,int row,int col,char m){
    int f=0;
    int c=0;
   
    EncontrarPuntos(matriz,row,col,Puntos,cantidadPuntos,getPuntofinal());
    EncontrarPuntos(matriz,row,col,Cajas,cantidadCaja,getCaja());

    //busca al socokan
    buscarSokoban(matriz,row,col,f,c);
    switch (m)
                {
                case 'W':
                       if(matriz[f-1][c] != getMuro()){
                           if(matriz[f-1][c]== getPuntofinal()){
                                matriz[f-1][c] = getPerson();
                                matriz[f][c]=".";
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
                            moverObjetos(matriz[f-1][c],matriz[f][c]);

                            
                       }

                    break;
                case 'S':
                        if(matriz[f+1][c] != getMuro()){
                            if(matriz[f+1][c]== getPuntofinal()){
                                matriz[f+1][c] = getPerson();
                                matriz[f][c]=".";
                                break;
                           }
                            if(matriz[f+1][c] == getCaja()){
                                if(matriz[f+2][c] == getPuntofinal()){
                                    matriz[f+2][c]= getCaja();
                                    matriz[f+1][c]=".";
                                    
                                    
                                }else{
                                    if(matriz[f+2][c]== getMuro() || matriz[f+2][c]== getCaja()){
                                        break;
                                    }
                                    moverObjetos(matriz[f+2][c],matriz[f+1][c]);
                                    
                                }
                            }
                            
                            moverObjetos(matriz[f+1][c],matriz[f][c]);

                            
                       }

                    break;
                case 'A':
                        if(matriz[f][c-1] != getMuro()){
                            if(matriz[f][c-1]== getPuntofinal()){
                                matriz[f][c-1] = getPerson();
                                matriz[f][c]=".";
                                break;
                           }
                            if(matriz[f][c-1] == getCaja()){
                                if(matriz[f][c-2] == getPuntofinal()){
                                    matriz[f][c-2]= getCaja();
                                    matriz[f][c-1]=".";
                                   
                                    
                                }else{
                                    if(matriz[f][c-2]== getMuro() || matriz[f][c-2]== getCaja()){
                                        break;
                                    }
                                    moverObjetos(matriz[f][c-2],matriz[f][c-1]);
                                }
                            }
                         moverObjetos(matriz[f][c-1],matriz[f][c]);
                        }

                    break;
                case 'D':
                        if(matriz[f][c+1] != getMuro()){
                            if(matriz[f][c+1]== getPuntofinal()){
                                matriz[f][c+1] = getPerson();
                                matriz[f][c]=".";
                                break;
                           }
                            if(matriz[f][c+1] == getCaja()){
                                if(matriz[f][c+2] == getPuntofinal()){
                                    matriz[f][c+2]= getCaja();
                                    matriz[f][c+1]=".";
                                    
                                }else{
                                    if(matriz[f][c+2]== getMuro() || matriz[f][c+2]== getCaja()){
                                        break;
                                    }
                                    moverObjetos(matriz[f][c+2],matriz[f][c+1]);
                                }
                           
                            }
                            moverObjetos(matriz[f][c+1],matriz[f][c]);
                       }
                        
                    break;

                default:
                    break;
                }
    for (int i = 0; i < cantidadPuntos; i++)
    {
        int a= Puntos[i].a;
        int b= Puntos[i].b;
        if(matriz[a][b] == "."){
            matriz[a][b]=getPuntofinal();
        }
    }
    
    
}


void  Sokoban::moverObjetos(string &a, string &b){
    string t = a;
    a= b;
    b= t;
}

  void Sokoban::EncontrarPuntos(string** matriz,int row,int col,arrF arr[],int &n,string L){
       for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matriz[i][j] == L)
            {
              arr[n].a=i;
              arr[n].b=j;
              n++;
            }
            
        }
        
    }
  }

void Sokoban::buscarSokoban(string** matriz,int row,int col,int &a,int &b){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matriz[i][j] == getPerson())
            {
               a=i;
               b=j;
              
            }
            
        }
        
    }
}


/*metodo para cargar tablero*/
void Game::cargarTablero(string name){
    if(initGame){
        borraMatriz(getRow(),getMatriz());
        initGame =false;
    }
    setMatriz  rellenarMatriz;
    ifstream File(name.c_str());

    if(File.is_open()){
            File >> row;
            File >> col;
            if(row == col){
                restaurarMatriz(getMatrizCargada());
                cout<<"Tablero Invalido"<<endl;
               
            }else{
                string line;
                int tam = 0;
                string* arr = new string[row];
                //array dinamico para guardar las lineas de la matriz
                while (!File.eof())
                {
                    File >> line;
                    arr[tam] = line;
                    tam++;
                    
                }
                    //funcion para generar la matriz con el array
                matriz = rellenarMatriz.generarMatriz(row,col,arr);
                matrizCargada = rellenarMatriz.generarMatriz(row,col,arr);
                bool  isCorrectaMatriz = isCorrectoMatriz(arr,row,col,tam);
                bool isCorrectoCaracter= isCorrecMatrix(getMatriz(),getRow(),getCol());
                bool isLimite = isCorrectoLimite(getMatriz(),getRow(),getCol());
                if(isCorrectoCaracter && isLimite && isCorrectaMatriz){
                    initGame = true;

                }else{
                    delete[]arr;
                    borraMatriz(getRow(),getMatriz());
                     restaurarMatriz(getMatrizCargada());

                    cout <<"Tablero inválido"<<endl;
                    
                }
            }
    
        File.close();

    }else{
        restaurarMatriz(getMatrizCargada());        
        cout <<"Tablero inválido"<<endl;

    }

}

bool Game::isCorrectoMatriz(string A[],int row,int col,int n){
    string a="";
    if( n != row){
        return 0;
    }
    for (int i = 0; i < row; i++)
    {
        a+=A[i];
    }
    if( a.size() != row*col){
        return 0;
    }
    return 1;
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
                //cout<<endl;
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

void Game::borraMatriz(int tam,string **matriz){
    for(int i = 0; i < tam; i++){
        delete[]matriz[i];
    }
    delete[]matriz;
}

bool Game::isCorrecMatrix(string** matriz,int row,int col){
            bool k=false,c=false,f=false,m=false;
            Sokoban objetos;
            int auxi=0;
            string K = objetos.getPerson();
            string C =  objetos.getCaja();
            string F = objetos.getPuntofinal();
            string M = objetos.getMuro();
            for (int i = 0; i < row; i++)
            {
               for (int j = 0; j < col; j++)
               {
                    
                    if( matriz[i][j] == K){
                        k = true;
                        auxi++;
                        if(auxi > 1){
                            return 0;
                        }
                    }
                    if(matriz[i][j]== C){
                        c=true;

                    }
                    if(matriz[i][j] == F){
                        f=true;
                    } 

                    if(matriz[i][j] == M){
                        m = true;
                    }
                    if(matriz[i][j] != M && matriz[i][j] != F && matriz[i][j]!= C && matriz[i][j] != K && matriz[i][j] != "."){
                        return 0;
                    }
               }
               
            }
        if( k & c & f & m){
             return true;
         }
        return 0;
    }

bool Game::isCorrectoLimite(string** m,int row, int column){
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1) { // Primer y última fila
               if( m[i][j] != "X"){
                return 0;
               }
            } else if (j == 0 || j == col-1) { // Primer y última columna
                 if(m[i][j] !="X"){
                    return 0;
                 }
            }
        }
        
    }

    return 1;
};

