#ifndef CODIFICAR_H
#define CODIFICAR_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <math.h>
#include <exception>

using namespace std;
//menu ejercicio de codificación
void principal();
void Metodo1Char();
void Metodo2str();
void Metodo1str();

//binario a caracteres y catacteres a binarios
string Str_to_Binary(string);
string Binary_to_Str(string);
// leer y escribir archivos de texto
string LeerArchivo(string);
void EscribirArchivo(string,string);

// metodo2 de codificacion
string codificacion2(string, int);
string Cambiar_pos(string);
//metodo2 de decodificacion
string decodificacion2(string, int);
string cambiar_decof(string);

//metodo1 de codificacion string
string metodo(int n, string);
//metodo1 de decodificacion string
string metododecodificacion(int n, string bin);

//binario a caracteres y caracteres a binario
void Char_to_Binary(char *,char *,long long int);
void Binary_to_Char(char *,char *,long long int);
//longitud del archivo
long long int Longitud_Archivo(char *);

//Leer y excibir archivo
void LeerArchivoChar(char *, char*);
void EscribirArchivoChar(char *, char *,long long);

//metodo1 de codificacion char
void codificacion1(int, char *,long long int);
//metodo1 de decodificacion char
void decodificacion1(int, char *,long long int);

#endif // CODIFICAR_H
