/***********AUTOR: NATALIA ISAZA SERRANO
      FUNCION DEL PROGRAMA: CALCULADORA DE MATRICES
            FECHA DE INICIO:11/10/2016***********/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#define d 4
#define largo 100
#define MAX 5

using namespace std;

//Mostrar menu
int menu();

void llenarMatriz(int[MAX][MAX], int orden);
void mostrarMatriz(int[MAX][MAX], int orden);
void transpuestaM(int [MAX][MAX], int [][MAX],int orden);
void mostrarT(int [MAX][MAX],int orden);
int determinante(int matriz[MAX][MAX],int orden );
int cofactor(int matriz[MAX][MAX], int orden, int fila, int columna);
int menudematriz (int matriz[MAX][MAX], int orden);
void verMatriz (int matriz[MAX][MAX], int orden);
void Producto (int Escalar, int matriz [MAX], int orden);
void sumarMatriz(int, int [MAX][MAX], int [MAX][MAX],int [MAX][MAX]);
void restarMatriz(int, int [MAX][MAX], int [MAX][MAX],int [MAX][MAX]);
void MultMatriz(int orden, int [MAX][MAX],int [MAX][MAX], int [MAX][MAX]);
void burbuja();
void insercion();
void seleccion();
void shell();
void quicksort(int A[],int izq, int der );
void leeCadena(int cant,int n[]);
void muestraCadena(int cant,int n[]);
void Pausa ();
void limpiarPantalla ();
//Funcion principal
int main ()

{

    system ("color f0");//Funcion para cambiarle el color al programa
    //Crear matriz
    int opcion = menu();
    return 0;
}
int menu(){
    //definir
    int matriz [MAX][MAX];
    int T[MAX][MAX];
    int opcion;
    int orden;
    int Escalar;
    int A[MAX][MAX];
    int B[MAX][MAX];
    int R[MAX][MAX];
    int M[MAX][MAX];

   //preguntaremos al usuario de que cantidad de filas y columnas quiere la matriz con un maximo de 5
   cout << "***Ingresa la cantidad de filas-columnas de la matriz (Maximo " << MAX << "): "<<endl;
   cin >> orden;

   //el siguiente while servira por si el usuario ingresa un numero superios a 5
   while (orden < 0 || orden > MAX) {
      cout << "\nEl orden de la matriz no puede ser mayor que " << MAX << endl;
      cout << "Ingrese nuevamente el orden de la matriz: ";
      cin >> orden;
      }
    //ciclo principal del menu calculadora de matrices
    do{
        cout << "******CALCULADORA DE MATRICES*****" << endl;
        cout << "***MARQUE UNA OPCION DEL PENU***" << endl<<endl;
        cout << "1.Llenar matriz" << endl;
        cout << "2.Mostrar matriz" << endl;
        cout << "3.Traspuesta de una Matriz" << endl;
        cout << "4.Determinante matriz" << endl;
        cout << "5.Multiplicar matriz escalar" << endl;
        cout << "6.potencia de matriz" << endl;
        cout << "7.matriz A + matriz B" << endl;
        cout << "8.matriz A - matriz B" << endl;
        cout << "9.matriz A * matriz B" << endl;
        cout << "10.metodos de ordenamiento" << endl;
        cout << "11.Limpieza" << endl;
        cout << "0.Salir" << endl;
        cout<<endl;
        cout<<"ELIGE UNA OPCION:";
        cin>>opcion;

     }
        while(opcion>11 || opcion<0);//while para mostrar el maximo y la minima opcion
            switch(opcion){//toma de decision de la calculadora, y mostrar el proceso
                case 0: cout << "Programa finalizar" << endl;
                exit(0);
                case 1: cout << "Llenar matriz" << endl;
                    llenarMatriz(matriz,orden);//muestra matriz
                    Pausa ();
                    menu ();//volver a mostrar menu principal
                break;
                case 2: cout << "Mostrar matriz" << endl;
                    llenarMatriz(matriz,orden);//mostrara la matriz
                    mostrarMatriz(matriz,orden);// volvera a mostrar la matriz un poco mas ordenada
                    Pausa ();
                    menu ();
                break;
                case 3: llenarMatriz(matriz,orden);
                        transpuestaM(matriz, T,orden);//mostrara la matriz
                        cout<<"***Matriz Original***"<<endl;
                        mostrarMatriz(matriz,orden);
                        cout<<"***Matriz Transpuesta***"<<endl;
                        mostrarT(T,orden);//mostrara la transpuesta de la matriz
                        Pausa ();
                        menu();
                break;
                case 4: cout << "***Determinante matriz***" << endl;
                        llenarMatriz(matriz,orden);
                        mostrarMatriz(matriz,orden);
                        cout << "La determinante es = "<< determinante(matriz,orden) << endl;//mostrara la determinante de la matriz
                        Pausa ();
                        menu();

                break;
                case 5: cout << " escalar de una matriz"<< endl;
                        llenarMatriz(matriz,orden);
                        cout << "Cual es la escarla de la matriz" << endl;
                        cin >> Escalar;
                        Producto (Escalar,(int*) matriz, orden);
                        verMatriz (matriz, orden);

                        Pausa ();
                        menu();

                break;
                case 6:

                break;
                case 7:
                        cout << "****Sumar Matrices****" << endl;
                        sumarMatriz(orden,A,B,R);//mostrara la dos matrices sumadas y la matriz resultado
                        Pausa ();
                        menu();
                break;
                case 8:
                        cout << "****Restar Matrices****" << endl;
                        restarMatriz(orden,A,B,R);//Mostrara dos matrices restadas y la matriz resultados
                        Pausa ();
                        menu();

                break;
                case 9:
                    cout << "****multiplicacion de mtrices****" << endl;
                    MultMatriz(orden, A, B, M);//Mostrara dos matrices multiplicadas y la matriz resultado
                    Pausa ();
                        menu();
                break;
                case 10:
                    int opcionn;
                    cout<<"*****MENU METODOS DE ORDENAMIENTO*****";//menu para invocar las obciones de metodo de ordenamiento
                    cout<<endl;
                    cout<<endl;
                    cout<<"1.Metodo Burbuja";
                    cout<<endl;
                    cout<<"2.Metodo Insercion";
                    cout<<endl;
                    cout<<"3.Metodo Seleccion";
                    cout<<endl;
                    cout<<"4.Metodo Shell";
                    cout << endl;
                    cout << "5.Metodo QuickSort";
                    cout<<endl;
                    cout<<endl;
                    cout<<"ELIGE UNA OPCION:";
                    cin>>opcionn;
                    cout<<endl;
                    cout<<endl;
                        switch (opcionn){
                            case 1:burbuja();
                            break;
                            case 2:insercion();
                            break;
                            case 3:seleccion();
                            break;
                            case 4:shell();
                            break;
                            case 5:
                                int A[largo],n;
                                    do{
                                        cout<<"Cantidad de numeros a ingresar: ";
                                    cin>>n;
                                        if(n<=0||n>largo)
                                            cout<<"Debe ingresar un valor > a 0 y < a "<<largo<<endl;
                                        }
                                        while(n<=0||n>largo);
                                            leeCadena(n,A);
                                            quicksort(A,0,n-1);
                                            muestraCadena(n,A);
                        break;
                        default: cout<<"ERROR EN LA SECCION";
                        }
                Pausa();
                menu();
                break;
                case 11:
                    cout << "Limpiar" << endl;//opcion para que el programa quede limpio sin necesidad de cerrarse
                     limpiarPantalla () ;
                     menu ();
                break;
                default: cout << "OPCION NO VALIDA " << endl;

    }
    return opcion;


}
//el proceso a continuacion es para llenar la matriz principal usando dos for
void llenarMatriz(int matriz[MAX][MAX],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i]=rand ()%100;

               cout << matriz [j][i]<< "\t";// matriz lista

    }
    cout << endl <<endl;
    }
    cout << endl << "Matriz llenada con exito" << endl << endl;
}
void mostrarMatriz(int matriz[MAX][MAX],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
              cout << matriz [j][i]<< "\t";

    }
    cout << endl << endl;
    }
}

void transpuestaM(int matriz[MAX][MAX], int T[MAX][MAX], int orden){//la transpuesta-llenamos la matriz y la asignamos a la transpuesta
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
           T[j][i] = matriz[i][j];
        }
    }
    cout << endl<<endl;
}

void mostrarT(int T[MAX][MAX], int orden){
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
            cout<<T[j][i]<< "\t";//mostrara la traspuesta
        }
        cout<<endl<<endl;
    }
}
int determinante(int matriz[MAX][MAX], int orden)
{
   int det = 0.0;

   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }

   return det;
}


int cofactor(int matriz[MAX][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = orden - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }

   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}

int menudematriz (int matriz[MAX][MAX], int orden)
{
        int Escalar;
            for (int  j=0;j<orden;j++) {
                for (int i=0;i<orden;i++) {
                matriz [j][i]=rand ()%100;
            }
            }
            cout << "Matriz" << endl;
           // verMatriz (matriz, orden);
            cout << endl;
            cout << "Cual es la escarla de la matriz" << endl;
            cin >> Escalar;
            //cout << "Matriz * 2" << endl;
            Producto (Escalar, (int *) matriz, orden);
            //verMatriz ( matriz, orden);
            cout << endl;
            Pausa ();
}
void verMatriz (int matriz[MAX][MAX], int orden)
{
        for (int i = 0; i < orden; ++i){
        for (int j = 0; j < orden; ++j)
        cout << matriz [orden * i + j] << "\t";
        cout << endl;
        }
}

void Producto (int Escalar, int matriz [MAX], int orden)
{
        int Total = orden * orden;
        for (int i = 0; i < Total; ++i)
         matriz [i] *= Escalar;
}
/* Aqui explicare solo la suma porque el mismo mecanismo es para la resta y  la
multiplicacion, solamente se le cambiara los signos */
void sumarMatriz(int orden, int A[MAX][MAX],int B[MAX][MAX], int R[MAX][MAX])
{
   cout<<"llenar matriz A"<<endl;//Formando matriz A
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;//La variable valor va tomar un valor aleatorio %10 y este se le asigna a la matriz A
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";//Mostrara matriz A
        }
        cout << endl<<endl;
    }



    cout<<"llenar matriz B"<<endl;//Formando matriz B
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;//La variable valor va tomar un valor aleatorio %30 Diferente a la matriz A y este se le asigna a la matriz B
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";//Mostrara matriz B
        }
        cout << endl<<endl;
    }
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            R[i][j]=A[i][j]+B[i][j];//Sumando matriz A y matriz B dando la matriz resultado "R"
        }
    }
    cout<<"el resultado de suma es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<R[i][j]<<" \t";//Mostrando matriz R
        }
        cout<<endl<<endl;
    }

}
void restarMatriz(int orden, int A[MAX][MAX],int B[MAX][MAX], int R[MAX][MAX])
{
    cout<<"llenar matriz A"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";
        }
        cout << endl<<endl;
    }



    cout<<"llenar matriz B"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";
        }
        cout << endl;
    }
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            R[i][j]=A[i][j]-B[i][j];
        }
    }
    cout<<"el resultado de la resta es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<R[i][j]<<" \t";//Mostrando matriz R
        }
        cout<<endl<<endl;
    }
}

void MultMatriz(int orden, int A[MAX][MAX],int B[MAX][MAX], int M[MAX][MAX])
{
    cout<<"llenar matriz A"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           A[i][j]=rand ()%10;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

          cout << A[i][j] << "\t";
        }
        cout << endl<<endl;
    }



    cout<<"llenar matriz B"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

             B[i][j]=rand ()%30;
        }
    }
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){

           cout <<B[i][j] << "\t";
        }
        cout << endl<<endl;
    }
    for( int i=0;i<orden;i++){
        int N=0;
        for(int j=0;j<orden;j++){
            M[i][j]=(A[i][j]*B[j][N]+
                    A[i][j]*B[j][N]+
                    A[i][j]*B[j][N]);
                N+=1;
        }
    }
    cout<<"el resultado de multiplicacion es"<<endl;
    for( int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            cout<<M[i][j]<<" \t";
        }
        cout<<endl<<endl;
    }
}
//los siguientes son los metoso de ordenamiento
void burbuja()
{
    char salir;
    int N,Aux,J,opcion;
    int V[10];
    int I;


    cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
    cin>>N;
    for(I=0; I<N; I++)
    {
        cout<<"Ingrese dato "<<I+1<<":";
        cin>>V[I];
    }
    for (I=0; I<N-1; I++)
    for (J=0; J<(N-1)-I; J++)
    if (V[J]>V[J+1])
    {
        Aux=V[J];
        V[J]=V[J+1];
        V[J+1]=Aux ;
    }

    cout<<"Los numeros de forma ordenada son:";
    for(I=0; I<N; I++)
    cout<<endl<<V[I];
    getch();



}




    void insercion()
{
    int N,Aux,J,SW;
    int V[10];
    int I;


    cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
    cin>>N;
    for(I=0; I<N; I++)
    {
        cout<<"Ingrese dato "<<I+1<<":";
        cin>>V[I];
    }
    for (I=1; I<N;I++)
    {
        Aux=V[I];
        J=I-1;
        SW=1;
        while (SW&&J>=0)
        {
            if (Aux<V[J])
            {
                V[J+1]=V[J];
                J--;
            }
            else
            SW=0;
        }
            V[J+1]=Aux;
    }



    cout<<"Los numeros de forma ordenada son:";
    for(I=0; I<N; I++)
    cout<<endl<<V[I];

    getch();
}
void seleccion()
{
    int J,I,N,K;
    int V[10];
    int Sw;
    int Aux;

    cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
    cin>>N;
    for(I=0; I<N; I++)
    {
        cout<<"Ingrese dato "<<I+1<<":";
        cin>>V[I];
    }

    for(I=0; I<N-1; I++)
    {
        K=I;
        for (J=I+1; J<N; J++)
        if (V[J]<V[K])
        K=J;

        Aux=V[I];
        V[I]=V[K];
        V[K]=Aux;
    }


    cout<<"Los numeros de forma decrecciente son:";
    for(I=N-1; I>=0; I--)
    cout<<endl<<V[I];
    getch();
}
void shell()
{
    int J,I,N,K,INC,TMP;
    int V[10];
    int Sw;
    int Aux;

    cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
    cin>>N;
    for(I=0; I<N; I++)
    {
        cout<<"Ingrese dato "<<I+1<<":";
        cin>>V[I];
    }

    INC=N/2;
    do {
        for(I=INC; I<N; I++)
        {
            TMP=V[I];
            J=I-INC;
            while ((J>=0)&&(TMP<V[J]))
            {
                V[J+INC]=V[J];
                J-=INC;
            }
            V[J+INC]=TMP;
        }
        INC/=2;
    }
    while(INC!=0);


    cout<<"Los numeros de forma decrecciente son:";
    for(I=0; I<N; I++)
    cout<<endl<<V[I];
    getch();
}
void quicksort(int A[],int izq, int der )
{
    int i, j, x , aux;
    i = izq;
    j = der;
    x = A[ (izq + der) /2 ];
    do{
        while( (A[i] < x) && (j <= der) )
        {
            i++;
        }

        while( (x < A[j]) && (j > izq) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = A[i]; A[i] = A[j]; A[j] = aux;
            i++;  j--;
        }

    }while( i <= j );

    if( izq < j )
        quicksort( A, izq, j );
    if( i < der )
        quicksort( A, i, der );
}
void leeCadena(int cant,int n[])
{
    int i;for(i=0;i<cant;i++)
    {
        cout<<"Ingresa numero "<<i+1<<": ";
        cin>>n[i];
    }
}
void muestraCadena(int cant,int n[])
{
    int i;for(i=0;i<cant;i++)
    {
    cout<<n[i]<<endl;
    }
}
void Pausa ()
{
cout << "Pulse una tecla para continuar...";
if (!getch ())
getch ();
cout << endl;
}
void limpiarPantalla () {
    system ("cls");
}

