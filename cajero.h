#ifndef CAJERO_H
#define CAJERO_H
#include "codificar.h"

//menu del cajero
void inicio();
void administrador();
void usuario();

//como administrador
bool ClaveAdmin();
void NuevoUsuario();
void VerInfoUsuarios();
void RegistrarUsuario();
void EliminarUsuario();
void AgregarDinero();


//como usuario
void modificarsaldo(int retiro);
bool Comprobarclave(string cl);
bool verificaretiro( int retiro);
// funciones de ayuda
void CodificarInfo(string);
string DecodificarInfo(string);
bool ComprobarCedula(string);
bool SoloNumeros(string);
bool ComprobarSaldo0(string);


#endif // CAJERO_H
