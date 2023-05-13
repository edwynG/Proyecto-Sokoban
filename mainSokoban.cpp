#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct arrF
{
    int a;
    int b;

};
 arrF Puntos[10000];
 arrF Cajas[10000];

     int n=0;
     string name;
    int cantidadCaja=0;
    int cantidadPuntos=0;
   void restCantidad(){cantidadPuntos = 0; cantidadCaja=0;}
    class Sokoban
{
    private:
    string person = "K";
    string caja = "C";
    string muro = "X";
    string punto = "F";
    bool ispunto=false;

    public:
    Sokoban(){};
    void to_upper(string &m);
    void  moverse(string** matriz,int row,int col,char m);
    string getPerson(){return person;};
    string getCaja(){return caja;};
    string getMuro(){return muro;};
    string getPuntofinal(){return punto;};
    void  moverObjetos(string &a, string &b);
    void set_is_punto(bool op){ispunto = op;}
    bool get_is_punto(){return ispunto;}
    void buscarSokoban(string** matriz,int row,int col,int &a,int &b);
    void EncontrarPuntos(string** matriz,int row,int col,arrF arr[],int &n,string L,bool op);
    void setSokoban(string n){ person=n;}
    void setMuro(string n){ muro=n;}
    void setCaja(string n){ caja=n;}
    void setPuntofinal(string n){ punto=n;}

};


class setMatriz{

    public:
    setMatriz(){};
     void ImprimirMatriz(string** matriz,int row,int column);
    
};

class Game{

    bool initGame = false;
    string estadoCargado="";
    string** matriz;
    string matrizCargada="";
    int rowG = 0;
    int colG = 0;
    int row=0;
    int col=0;
    bool wins = false;
    string arregloEstado[10000];
    int tamanoEstados=0;
    bool isCargado=false;
    public:
    Game(){};
    ~Game(){
        borraMatriz(getRow(),getMatriz());
    }
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
    void isWins(string **matriz);
    void borraMatriz(int tam, string **matriz);
    
    bool isCorrecMatrix(string** matriz,int row,int col);
    bool isCorrectoLimite(string** m,int row, int column);
    bool isCorrectoMatriz(string A,int row, int col,int n);
    string getMatrizCargada(){ return matrizCargada;}
    void restaurarMatriz(string** m){matriz = m;}
    void setRowG(int a){rowG=a;}
    void setColG(int a){colG=a;}
    int getRowG(){return rowG;}
    int getColG(){return colG;}
    void transformador(string** tablero, int row, int column,string arr[]);
    void Escritura(string ArreglodeTableros[],int Cantidad_Tableros,int row, int column);
    void resetEstados(){tamanoEstados=0;}
    void setEstadoCargado(string a){estadoCargado=a;}
    string getEstadoCargado(){return estadoCargado;}
    string** cargar(string m,int row,int col);
    void restaurarDatos(int a, int b){ row=a;col =b;}
    bool ValidCaracteres(string str,int n);
    void generarEstado(string m,int row,int col);


};

void menu(){
    setMatriz a;

    Game gameOptions;
    string op = "";
    bool exit = false;
 

    while (!exit){

        cout <<"1. Juego en vivo."<<endl;
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
                cout <<"Debes cargar un tablero"<< endl<< endl;
              
                }
            break;
        case '3':
                gameOptions.cargarPartida();
            break;
        case '4':
            cin>>name;
            gameOptions.cargarTablero(name);
            break;
        case '5':
            exit = true;
            break;

        default:

            cout <<"Opción inválida"<<endl;
            cout<<endl;
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
    objeto.EncontrarPuntos(getMatriz(),getRow(),getCol(),Puntos,cantidadPuntos,objeto.getPuntofinal(),false);
    
    while (!getWins()){
        view.ImprimirMatriz(getMatriz(),getRow(),getCol());
        cin>>m;
        objeto.to_upper(m);
        if(m == "R"){break;}

        moverSokoban(m,false);
        if(m == "G"){break;}
        isWins(getMatriz());

        if(getWins()){
            view.ImprimirMatriz(getMatriz(),getRow(),getCol());
            cout<<"Ganaste la partida"<<endl;
           
        }

    }
   setWins(false);
    borraMatriz(getRow(),getMatriz());
   if(isCargado){
     restaurarDatos(getRowG(),getColG());
     isCargado=false;
   }
    restCantidad();
    resetEstados();
    restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
    
}

 void Game::juegoCargado(){

        string m;
        setMatriz view;
        Sokoban objeto;
        restaurarDatos(getRow(),getCol());
        objeto.EncontrarPuntos(getMatriz(),getRow(),getCol(),Puntos,cantidadPuntos,objeto.getPuntofinal(),false);
       
        cin>>m;
    if(m != "r" && m != "R"){ 
        moverSokoban(m,true);
        if(m != "g" &&  m != "G"){
            isWins(getMatriz());
            if(getWins()){
                view.ImprimirMatriz(getMatriz(),getRow(),getCol());
                cout<<"Ganaste la partida"<<endl;
                setWins(false);
                borraMatriz(getRow(),getMatriz());
                restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
                resetEstados();
                restCantidad();

            
            }else{
                juegoEnVivo();
            }
        }
    }else{
       borraMatriz(getRow(),getMatriz());
       restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
        resetEstados();
        restCantidad();

    }
   
   
    }



void Game::cargarPartida(){
    string name="currentGame.txt";
    ifstream File(name.c_str());
    string data;
    string data2;
    string  acumulador;
    string arr[10000];
    int tam=0;
    string estado="";
    bool a=false;
    int row=0;
    setMatriz b;

    if(File.is_open()){
            File>>data;
        if(!File.eof()){
            acumulador = data;
            row++;
            while (!File.eof())
            {
            do{
                File>>data2;
                acumulador+=data2;
                if(!a){row++;};
            } while( data != data2);
                if(!a){estado=acumulador;}
                File>> data2;
                arr[tam]=acumulador;
                acumulador=data2;
                tam++;
                a=true;
            }
            setRowG(row);
            setColG(data.size());
            setEstadoCargado(arr[tam-1]);
            File.close();
            borraMatriz(getRow(),getMatriz());
            restaurarMatriz(cargar(getEstadoCargado(),getRowG(),getColG()));
            setRowG(getRow());
            setColG(getCol());
            restaurarDatos(row,data.size());
            restCantidad();
            generarEstado(estado,row,data.size());
            isCargado=true;
            juegoEnVivo();

        }else{
             cout<<"No hay partida guardada"<<endl<<endl;
        }
    }else{
        cout<<"No hay partida guardada"<<endl<<endl;
    }
}


/*metodo para cargar tablero*/
void Game::cargarTablero(string name){
    if(initGame){
        borraMatriz(getRow(),getMatriz());
    }
    setMatriz  rellenarMatriz;
    ifstream File(name.c_str());

    if(File.is_open()){
            File >> row;
            File >> col;
                string line="";
                string acumulador= "";
                int tam=0;
                //array dinamico para guardar las lineas de la matriz
                while (true){
                    File >> line;
                    if(File.eof()){
                        break;
                    }
                    acumulador+=line;
                    tam++;
                    
                };
                bool  correcta = isCorrectoMatriz(acumulador,getRow(),getCol(),tam);
                bool caracteres = ValidCaracteres(acumulador,tam);
            if( correcta && caracteres){
                    //funcion para generar la matriz con el array
                matriz = cargar(acumulador,getRow(),getCol());
                matrizCargada = acumulador;
                bool isCorrectoCaracter= isCorrecMatrix(getMatriz(),getRow(),getCol());
                bool isLimite = isCorrectoLimite(getMatriz(),getRow(),getCol());
                if(isCorrectoCaracter && isLimite){
                    initGame = true;
                    restCantidad();

                }else{
                    borraMatriz(getRow(),getMatriz());
                    restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
                    cout <<"Tablero inválido"<<endl<<endl;
                    
                }
               
            }else{
                restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
                cout<<"Tablero Invalido"<<endl<<endl;
            }
    
        File.close();

    }else{
        restaurarMatriz(cargar(getMatrizCargada(),getRow(),getCol()));
            
        cout <<"Tablero inválido"<<endl<< endl;

    }
}

void Game::generarEstado(string m,int row,int col){
        Sokoban a;
        setMatriz b;
        string **M=cargar(m,row,col);
        a.EncontrarPuntos(M,row,col,Puntos,cantidadPuntos,a.getPuntofinal(),false);
        borraMatriz(row,M);
}

/*metodo para mover el sokoban que esta implementado en el metodo juegoEnVivo*/
void Game::moverSokoban(string &m,bool op){
        Sokoban objeto;
        objeto.to_upper(m);
        int n =m.size();
        if(op){n++;}
        for (int i = 0; i < n; i++){ 
          //  objeto.EncontrarPuntos(getMatriz(),getRow(),getCol(),Puntos,cantidadPuntos,objeto.getPuntofinal());
            transformador(getMatriz(),getRow(),getCol(),arregloEstado);
            tamanoEstados++;
            if(m == "G" || op){
                Escritura(arregloEstado,tamanoEstados,getRow(),getCol());
                if(i == n-1){
                    break;
                }
                if(!op){
                break;

                }
            }
            objeto.moverse(getMatriz(),getRow(),getCol(),m[i]);
            if(!op){
                break;
            }
        }

}

void Game::isWins(string **matriz){
    Sokoban obj;
    int n=0;
    if(cantidadPuntos > cantidadCaja){
        for (int i = 0; i < cantidadPuntos; i++)
        {
            if( matriz[Puntos[i].a][Puntos[i].b] == obj.getCaja()){
                n++;
            }
        }
         n == cantidadCaja? setWins(true):setWins(false);
        
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
    EncontrarPuntos(matriz,row,col,Puntos,cantidadPuntos,getPuntofinal(),false);
    EncontrarPuntos(matriz,row,col,Cajas,cantidadCaja,getCaja(),true);

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

bool itsHere(arrF arr[],int tam,int x,int y){
    for (int i = 0; i < tam; i++)
    {
        if(arr[i].a == y && arr[i].b== x){
            return 1;
        }
    }
    return 0;
}

  void Sokoban::EncontrarPuntos(string** matriz,int row,int col,arrF arr[],int &n,string L,bool op){
    if(op){n=0;}
       for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(!itsHere(arr,n,j,i))
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

bool Game::ValidCaracteres(string str,int n){
    Sokoban obj;
    string x ="";
    for (int i = 0; i < n; i++)
    {
        x= str[i];
        if(x != obj.getPerson() && x!= obj.getCaja() &&  x != obj.getMuro() && x!=obj.getPuntofinal() && x!="."){
            return false;
        }
    }
    return true;
}
bool Game::isCorrectoMatriz(string A,int row,int col,int n){
   int tam=A.size();
   int cantidad=row*col;
    if( n != row){
        return 0;
    }

    if( tam != cantidad){
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
        
    };

};

/*metodo covierte en mayusculas un string*/
void Sokoban:: to_upper(string &m){
        int n= m.size();
        for (int i = 0; i < n; i++)
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
        if( k && c && f && m){
             return true;
         }
        return 0;
    }

bool Game::isCorrectoLimite(string** m,int row, int col){
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

void Game::Escritura(string ArreglodeTableros[],int Cantidad_Tableros,int row, int column) {
    int contador = 0; //Cuenta hasta la cantidad de columnas del tablero

    ofstream Archivo("currentGame.txt", ios::out);

    if (Archivo.is_open()) {
        for (int j = 0; j < Cantidad_Tableros; j++) {
            for (int i = 0; i < column * row; i++) {

                Archivo << ArreglodeTableros[j][i];

                contador++;
                if (contador == column) {
                    Archivo << "\n";
                    contador = 0;
                }
            }
            Archivo << "\n";
        }
    }

    Archivo.close();
}

void Game::transformador(string** tablero, int row, int column,string arr[]) { // Parametros: (Tablero sin transformar, Filas, Columnas)
 
    string res = "X";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 && j == 0) {
                res = tablero[i][j];
            }
            else {
                res = res + tablero[i][j];
            }
           
        }
    }
   
   arr[tamanoEstados]=res;
}

string** Game::cargar(string m,int row,int col){
    setMatriz view;
        int n=0;
     string** ma = new string*[row];
        for (int i = 0; i < row; i++){
            ma[i]= new string[col];
            for (int j = 0; j < col; j++){
                ma[i][j] = m[n];
                n++;
            }
           
           
        }
       // view.ImprimirMatriz(ma,row,col);
         return ma;
     
}


