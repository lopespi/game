#include <iostream>

using namespace std;
const int iMAX=10;
const int iTAM=5;

void FuncTablero(char cTablero[iMAX][iMAX]){
  cout<<"\t";
  for(int iX=0; iX<iTAM; iX++){
    cout<<iX<<"\t";
  }
  cout<<endl;
  for(int iX=0; iX<iTAM; iX++){
    cout<<iX<<"\t";
    for(int iY=0; iY<iTAM; iY++){
      cout<<cTablero[iX][iY]<<"\t";
    }
    cout<<endl;
  }
}

void FuncTurno(int &iTurno, char &cObjeto, int iC){
  if(iC%2==0){
    iTurno=1;
    cObjeto='X';
  }
  else{
    iTurno=2;
    cObjeto='O';
  }
}

void FuncPosicion(int &iX, int &iY, int iTurno, char cObjeto, char cValidar, char cTablero[iMAX][iMAX]){
  do{
    cValidar='s';
    cout<<"Jugador "<<iTurno<<" "<<cObjeto<<endl<<"Renglon #";
    cin>>iX;
    cout<<endl<<"Columna #";
    cin>>iY;
    if(iX>=0 && iX<iTAM && iY>=0 &&iY<iTAM){
      cValidar='e';
    }
    else{
      cValidar='s';
    }
  }while(tolower(cValidar)=='s');
}

void FuncMover (char cTablero[iMAX][iMAX], int &iX, int &iY, char cObjeto, char cClave, int iCheck){
    cout << "a = izquierda  x = abajo  w = arriba  d = derecha" << endl<< "q = arriba a la izquierda   e = arriba a la derecha" << endl<< "z = abajo a la izquierda    c = abajo a la derecha" << endl;
    do{
        iCheck=0;
        do{
            cout << "Respuesta: ";
            cin >> cClave;
            cClave = tolower(cClave);
        } while (cClave!='a' && cClave!='w' && cClave!='d' && cClave!='x' && cClave!='q' && cClave!='e' && cClave!='z' && cClave!='c');
        switch (cClave){
            case 'a': if (iY-1>=0 && iY-1<iTAM){
                            if (cTablero[iX][iY-1]=='-'){
                                cTablero[iX][iY-1]=cObjeto;
                                iY-=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'w': if (iX-1>=0 && iX-1<iTAM){
                            if (cTablero[iX-1][iY]=='-'){
                                cTablero[iX-1][iY]=cObjeto;
                                iX-=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                              }
                       }
                       break;
            case 'd': if (iY+1>=0 && iY+1<iTAM){
                            if (cTablero[iX][iY+1]=='-'){
                                cTablero[iX][iY + 1]=cObjeto;
                                iY+=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'x': if (iX+1>=0 && iX+1<iTAM){
                            if (cTablero[iX+1][iY]=='-'){
                                cTablero[iX+1][iY]=cObjeto;
                                iX+=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'q': if (iX-1>=0 && iX-1<iTAM && iY-1>=0 && iY-1<iTAM){
                            if (cTablero[iX-1][iY-1]=='-'){
                                cTablero[iX-1][iY-1]=cObjeto;
                                iX-=1;
                                iY-=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'e': if (iX-1>=0 && iX-1<iTAM && iY+1>=0 && iY+1<iTAM){
                            if (cTablero[iX-1][iY+1]=='-'){
                                cTablero[iX-1][iY+1]=cObjeto;
                                iX-=1;
                                iY+=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'z': if (iX+1>=0 && iX+1<iTAM && iY-1>=0 && iY-1<iTAM){
                            if (cTablero[iX+1][iY-1]=='-'){
                                cTablero[iX+1][iY-1]=cObjeto;
                                iX+=1;
                                iY-=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
            case 'c': if (iX+1>=0 && iX+1<iTAM && iY+1>=0 && iY+1<iTAM){
                            if (cTablero[iX+1][iY+1]=='-'){
                                cTablero[iX+1][iY+1]=cObjeto;
                                iX+=1;
                                iY+=1;
                            }else{
                                cout << "Error, Ingrese valores validos" << endl;
                                iCheck=1;
                            }
                       }
                       break;
        }
    }while (iCheck == 1);
}


void FuncionCambiar(char cTablero[iMAX][iMAX], int iX, int iY, char cObjeto){
    for (int iCon=iX-1; iCon<=iX+1; iCon++){
        for (int iCon2=iY-1; iCon2<=iY+1; iCon2++){
            if (iCon>=0 && iCon<iTAM && iCon2>=0 && iCon2<iTAM){
                if (cTablero[iCon][iCon2]!='-' && cTablero[iCon][iCon2]!=cObjeto){
                    cTablero[iCon][iCon2]=cObjeto;
                  }
              }
        }
    }
}

int main(){
  int iC=0;
  int iTurno, iX, iY, iCheck;
  char cObjeto, cFinal='s';
  char cValidar, cClave;
  char cTablero[iMAX][iMAX]={{'X', '-', '-', '-', 'X'},{'-', '-', '-', '-', '-'},{'-', '-', '-', '-', '-'},{'-', '-', '-', '-', '-'},{'O', '-', '-', '-', 'O'}};

  do {
    FuncTablero(cTablero);//mostrar tablero en terminal
    FuncTurno(iTurno, cObjeto, iC);//Validar el tueno de el jugador
    FuncPosicion(iX, iY, iTurno, cObjeto, cValidar, cTablero);//verificar la posicion del objeto
    FuncMover (cTablero, iX, iY, cObjeto, cClave, iCheck);//Mover el objeto a una posicion
    FuncionCambiar (cTablero, iX, iY, cObjeto);//Cambiar el objeto
    cout<<"¿desea seguir jugando? "<<endl;
    cin>>cFinal;
    iC++;
  } while(tolower(cFinal)=='s');

}
