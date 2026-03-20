#include "funciones.h"
#include <iostream>
using namespace std;
//aqui creo las funciones
char *crear_cadena(const int tamaño){
    char *cadena=new char[tamaño];
    for (int i=0;i<tamaño;i++){
        cadena[i]='\0';
    }
    return cadena;
}
void liberarCadena(char*& cadena) {
    delete[] cadena;
    cadena = nullptr;
}
unsigned int aleatorio(unsigned int &semilla){
    semilla=(1103515245*semilla)%2147483648;
    return semilla;
}
void generar_imprimir_letras(char *arreglo, unsigned int &semilla, int tam){
    cout<< "El arreglo generado es:"<<endl;
    for (int i=0; i<tam;i++){
        int num = aleatorio(semilla)%26;
        arreglo[i]='A'+num;
        cout<<arreglo[i];
    }
    cout<<endl<<endl;
}
void contarLetras(char *arreglo, int *contador, int tam) {
    for (int i = 0; i < 26; i++) {
        contador[i] = 0;
    }

    for (int i = 0; i < tam; i++) {
        contador[arreglo[i] - 'A']++;
    }
}
void imprimirFrecuencias(int *contador) {
    cout << "Frecuencia de cada letra:\n";
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ": " << contador[i] << endl;
    }
}

int problema_2(){
    const int tam=200;
    char *arreglo=crear_cadena(tam);
    int contador[26];
    unsigned int semilla=15324;
    generar_imprimir_letras(arreglo, semilla, tam);
    contarLetras(arreglo, contador,tam);
    liberarCadena(arreglo);
    imprimirFrecuencias(contador);
    return 0;

}
int char_a_int(char *cadena){
    int resultado=0;
    for(int i=0; cadena[i] !='\0' ;i++){
        int digito=cadena[i]-48;
        resultado=resultado*10+digito;
    }
    return resultado;
}
int problema_4(){
    char *cadena=crear_cadena(10);
    cout<<"Ingrese un numero: "<<endl;
    cin>>cadena;
    cout<<"El numero convertido es: "<< char_a_int(cadena)<<endl;
    liberarCadena(cadena);
    return 0;
}
int conver_a_mayusculas(char letra){
    int may=0;
    if (letra>=97 && letra<=122){
        may=letra-32;
    }
    else{ may=letra;}
    return may;
}
int Problema_6(){
    char *cadena=crear_cadena(25);
    cout<<"Ingrese la palabra a cambiar: "<<endl;
    cin>>cadena;
    cout<<"Original: "<<cadena<<endl;
    for (int i=0; cadena[i]!='\0'; i++){
        cadena[i]=conver_a_mayusculas(cadena[i]);
    }
    cout<< "En mayusculas: "<<cadena<<endl;
    liberarCadena(cadena);
    return 0;
}

int Problema_8(){
    char *cadena=crear_cadena(20);
    char *numero=crear_cadena(20);
    char *texto=crear_cadena(20);
    cout<<"Ingrese la cadena de caracteres: "<<endl;
    cin>>cadena;
    int k=0;
    int j=0;
    for (int i=0; cadena[i]!='\0';i++){
        if (cadena[i]>=48 && cadena[i]<=57) {
            numero[k]=cadena[i];
            k++;
        }
        else if (cadena[i]>='a' && cadena[i]<='z') {
            texto[j]=cadena[i];
            j++;
        }
        else if (cadena[i]>='A' && cadena[i]<='Z') {
            texto[j]=cadena[i];
            j++;
        }
    }
    cout<<"La cadena de numeros es: "<<numero<<endl<<"La cadena de texto es: "<<texto<<endl;
    liberarCadena(cadena);
    return 0;
}
int dar_valor(char n){
    int num=0;
    if (n==77) num=1000;
    else if(n==68) num=500;
    else if(n==67) num=100;
    else if(n==76) num=50;
    else if(n==88) num=10;
    else if(n==86) num=5;
    else if(n==73) num=1;
    else if(num==0) cout<<"Ingreso un valor incorrecto."<< endl;
    return num;
}
int valor(char* cadena){
    int resultado=0;
    for (int i=0; cadena[i]!='\0';i++){
        if(cadena[1+i]!='\0' && dar_valor(cadena[i])<dar_valor(cadena[i+1])){
            resultado-=dar_valor(cadena[i]);
        }
        else{resultado+=dar_valor(cadena[i]);}
    }
    return resultado;
}
void Problema_10(){
    char *cadena=crear_cadena(20);
    cout<<"Ingrese un valor en numeros romanos: "<<endl;
    cin>>cadena;
    cout<<"El numero ingresado es: "<<cadena;
    cout<<". El valor convertido es: "<<valor(cadena)<<endl;
    liberarCadena(cadena);

}
int **crear_Matriz(int filas, int columnas){
    int** matriz=new int*[filas];
    for (int i=0; i<filas;i++){
        matriz[i]=new int[columnas];
    }
    return matriz;
}

void liberar_matriz(int** &matriz, int filas){
    for (int i=0;i<filas;i++){
        delete [] matriz[i];
    }
    delete [] matriz;
    matriz = nullptr;
}
void leerMatriz(int** matriz, int n) {
    cout << "Ingrese los elementos:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(int** matriz, int n) {
    cout << "Matriz ingresada:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool Cuadrado_magico(int** matriz, int n){
    int sumarefe=0;
    for (int j=0;j<n;j++){
        sumarefe+=matriz[0][j];
    }
    for(int i=0;i<n;i++){
        int suma=0;
        for(int j=0;j<n;j++){
            suma+=matriz[i][j];
        }
        if(suma!=sumarefe)
        {return false;}
    }
    for(int j=0;j<n;j++){
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=matriz[i][j];
        }
        if(suma!=sumarefe)
        {return false;}
    }
    int sumaD1 = 0;
    for (int i = 0; i < n; i++) {
        sumaD1 += matriz[i][i];
    }

    int sumaD2 = 0;
    for (int i = 0; i < n; i++) {
        sumaD2 += matriz[i][n - 1 - i];
    }

    if (sumaD1 != sumarefe || sumaD2 != sumarefe) return false;

    for (int i = 0; i < n * n; i++) {
        int valor = matriz[i / n][i % n];

        for (int j = i + 1; j < n * n; j++) {
            if (valor == matriz[j / n][j % n]) {
                return false;
            }
        }
    }
    return true;
}
int Problema_12(){
    int n;
    cout<<"Ingrese el tamaño de la matriz: "<<endl;
    cin>>n;
    int **matriz=crear_Matriz(n,n);
    leerMatriz(matriz,n);
    imprimirMatriz(matriz,n);
    if (Cuadrado_magico(matriz,n)){
        cout<<"Es un cuadrado magico."<<endl;
    }
    else{cout<<"No es un cuadrado magico."<<endl;}
    liberar_matriz(matriz,n);
    return 0;
}
int menu(){
    int x=0,d=0;

    while (d<=3){

        cout <<"Ingrese el numero del problema que desea ver: "<<endl<<"2) Problema 2."<<endl<<"4) Problema 4."<<endl<<"6) Problema 6."<<endl<<"8) Problema 8."<<endl<<"10) Problema 10."<<endl<<"12) Problema 12."<<endl<<"14) Problema 14."<<endl<<"16) Problema 16."<<endl<<"18) Problema 18."<<endl;
        cout<<"19) Salir."<<endl;
        cin >> x;

        switch(x){
        case 2:
            problema_2();
            break;
        case 4:
            problema_4();
            break;
        case 6:
            Problema_6();
            break;
        case 8:
            Problema_8();
            break;
        case 10:
            Problema_10();
            break;
        case 12:
            Problema_12();
            break;
        case 14:
  //          Problema_14();
            break;
        case 16:
//            Problema_16();
            break;
        case 18:
//            Problema_18();
            break;
        case 19:
            d=5;
            break;
        default:
            break;
        }

        d++;
    }
    return 0;
}
