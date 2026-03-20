#ifndef FUNCIONES_H
#define FUNCIONES_H
//aqui se declaran las funciones
int menu();
char *cadena(const int tamaño);
void liberarCadena(char*& cadena);
int **crear_Matriz(int ancho, int alto);
void liberar_matriz(int** &matriz, int filas);
unsigned int aleatorio(unsigned int &semilla);
void generar_imprimir_letras(char *arreglo, unsigned int &semilla, int tam);
void contarLetras(char *letras, int *contador);
void imprimirFrecuencias(int *contador);
int problema_2();
int char_a_int(char *cadena);
int problema_4();
int conver_a_mayusculas(char letra);
int Problema_6();
int Problema_8();
void Problema_10();
int dar_valor(char n);
int valor(char* cadena);
int Problema_12();
bool Cuadrado_magico(int** matriz, int n);
void imprimirMatriz(int** matriz, int n);
void leerMatriz(int** matriz, int n);
int Problema_14();
int Problema_16();
int Problema_18();

#endif // FUNCIONES_H
