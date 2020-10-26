#include "codificar.h"

//menu ejercicio de codificar
void principal()
{
    int opc=0;
    cout<<"\n---------------Seleccion de metodo---------------\n";
    cout << "Ingrese:\n1.Usar metodo1 (char).\n2.Usar metodo2 (string).\n3.USar metodo1 (string).\n0.Salir.\n";
    cout << "Eliga una opcion -> ";cin >> opc;
    while (opc != 0){
        switch (opc) {
        case 1:{
            Metodo1Char();
        }
            break;
        case 2:{
            Metodo2str();
        }
            break;
        case 3:{
            Metodo1str();
        }
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
        cout<<"\n---------------Seleccion de metodo---------------\n";
        cout << "Ingrese:\n1.Usar metodo1 (char).\n2.Usar metodo2 (string).\n3.USar metodo1 (string).\n0.Salir.\n";
        cout << "Eliga una opcion -> ";cin >> opc;
    }

}

void Metodo1Char() //metodo1 char
{
    int opc=0,semilla=0,l_titulo=0;
    unsigned long long int longitud;
    char *archivo=NULL,*texto=NULL,*binario=NULL;
    cout << "\n-----------------metodo1  (char)-----------------\n";
    cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc){
        case 1:{
            cout << "Ingrese el numero de caractres del archivo.txt -> ";cin >> l_titulo;
            archivo = new char[l_titulo+1];
            fflush(stdin);
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";gets(archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            archivo[l_titulo] = '\0';
            //longitud del archivo
            longitud = Longitud_Archivo(archivo);
            //inicio de las variables
            texto = new char[longitud+1];
            binario = new char[longitud*8+1];
            binario[longitud*8] = '\0';
            //guarda en texto lo que se encuntra en el archivo
            LeerArchivoChar(archivo,texto);
            texto[longitud] = '\0';
            //pasa de caracteres a binario
            Char_to_Binary(texto,binario,longitud);
            binario[longitud*8] = '\0';
            //codifica binario
            codificacion1(semilla,binario,longitud);
            binario[longitud*8] = '\0';
            //pasa de binario a caracteres
            Binary_to_Char(binario,texto,longitud);
            texto[longitud] = '\0';

            delete [] archivo;
            cout << "Ingrese el numero de caractres donde guardar el archivo codificado .dat -> ";cin >> l_titulo;
            archivo = new char[l_titulo+1];
            fflush(stdin);
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo codificado ej(codificado.dat)" << endl;
            cout << "Nombre: ";gets(archivo);
            archivo[l_titulo] = '\0';
            //guarda en el .dat lo que hay en texto
            EscribirArchivoChar(archivo,texto,longitud);

            delete [] texto;
            delete [] binario;
            delete [] archivo;
        }
            break;
        case 2:{
            cout << "Ingrese el numero de caractres del archivo .dat a decodificar -> ";cin >> l_titulo;
            archivo = new char[l_titulo+1];
            fflush(stdin);
            cout << "Ingrese el nombre del archivo a decodificar (el archivo debe existir y ser .dat ej codificado.dat)\n";
            cout << "Nombre: ";gets(archivo);
            cout << "Ingrese la semilla de decodificacion -> ";cin >> semilla;
            archivo[l_titulo] = '\0';
            //longitud del archivo
            longitud = Longitud_Archivo(archivo);
            //inicio de las variables
            texto = new char[longitud+1];
            binario = new char[longitud*8+1];
            binario[longitud*8] = '\0';
            //guarda en texto lo que se encuntra en el archivo
            LeerArchivoChar(archivo,texto);
            texto[longitud] = '\0';
            //pasa de caracteres a binario
            Char_to_Binary(texto,binario,longitud);
            binario[longitud*8] = '\0';
            //decodifica binario
            decodificacion1(semilla,binario,longitud);
            binario[longitud*8] = '\0';
            //pasa de binario a caracteres
            Binary_to_Char(binario,texto,longitud);
            texto[longitud] = '\0';

            delete [] archivo;
            cout << "Ingrese el numero de caractres del archivo .txt donde guardar el archivo decodificado -> ";cin >> l_titulo;
            archivo = new char[l_titulo+1];
            fflush(stdin);
            cout << "Ingrese nombre del archivo .txt donde guardar el archivo decodificado ej(prueba.txt)" << endl;
            cout << "Nombre: ";gets(archivo);
            archivo[l_titulo] = '\0';
            //guarda en el .dat lo que hay en texto
            EscribirArchivoChar(archivo,texto,longitud);

            delete [] binario;
            delete [] texto;
            delete [] archivo;
        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << "\n-----------------metodo1  (char)-----------------\n";
        cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
        cout <<"Seleccione -> ";cin>>opc;
    }
}

void Metodo2str() //metodo 2 string
{
    int opc = 0,semilla=0;
    string archivo,texto;
    cout << "\n----------------metodo2  (string)----------------\n";
    cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc){

        case 1:{
            //codificar
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            texto = LeerArchivo(archivo);
            texto = Str_to_Binary(texto);
            texto = codificacion2(texto,semilla);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo codificado ej(codificado.dat)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo(archivo,texto);
        }
            break;
        case 2:{
            //decodificar
            cin.ignore(10000,'\n');
            cout << "Ingrese el nombre del archivo a decodificar (el archivo debe existir y ser .dat ej codificado.dat)\n";
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de decodificacion -> ";cin >> semilla;
            texto = LeerArchivo(archivo);
            texto = Str_to_Binary(texto);
            texto = decodificacion2(texto,semilla);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo donde guardar el archivo decodificado ej(prueba.txt)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo(archivo,texto);
        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << endl;
        cout << "\n----------------metodo2  (string)----------------\n";
        cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
        cout <<"Seleccione -> ";cin>>opc;
    }
}


void Metodo1str() //metodo1 string
{
    int opc = 0,semilla=0;
    string archivo,texto;
    cout << "\n----------------metodo1  (string)----------------\n";
    cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc){

        case 1:{
            //codificar
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            texto = LeerArchivo(archivo);
            texto = Str_to_Binary(texto);
            texto = metodo(semilla,texto);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo codificado ej(codificado.dat)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo(archivo,texto);
        }
            break;
        case 2:{
            //decodificar
            cin.ignore(10000,'\n');
            cout << "Ingrese el nombre del archivo a decodificar (el archivo debe existir y ser .dat ej codificado.dat)\n";
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de decodificacion -> ";cin >> semilla;
            texto = LeerArchivo(archivo);
            texto = Str_to_Binary(texto);
            texto = metododecodificacion(semilla,texto);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo donde guardar el archivo decodificado ej(prueba.txt)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo(archivo,texto);
        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << "\n----------------metodo1  (string)----------------\n";
        cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
        cout <<"Seleccione -> ";cin>>opc;
    }
}

string Str_to_Binary(string texto)
{
    // caracteres a binario
    string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string Binary_to_Str(string binario)
{
    //binario a caracteres
    string caracter,texto;
    for(int i=0; i<int(binario.length());i+=8){
        caracter = binario.substr(i,8);
        caracter = stoi(caracter, nullptr, 2);
        texto.append(caracter);
    }
    return texto;
}

string LeerArchivo(string archivo)
{
    string texto="",linea="";
    fstream lectura;
    lectura.open(archivo,fstream::in|fstream::binary);
    if(lectura.fail()){
        cout<<"No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(lectura.good()){
        linea=lectura.get();
        texto.append(linea);
    }
    lectura.close();
    texto.pop_back();
    return texto;

}

void EscribirArchivo(string archivo, string texto)
{
    fstream archivobinario;
    archivobinario.open(archivo,fstream::out|fstream::binary);

    if(archivobinario.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    archivobinario<<texto;
    archivobinario.close();
}

void Char_to_Binary(char *texto, char *binario,long long longitud)
{
    long long int pos = 0;
    for(long long int i=0; i<longitud; i++){
        for(int j=0;j<8;j++){
            binario[pos]=((((texto[i]<<j)&(0x80))/128)+48);
            pos ++;
        }
    }
}

void Binary_to_Char(char *binario, char *texto,long long longitud)
{
    int exp=0, num=0;
    for(long long i=0; i<longitud; i++){
        for(int j=7;j>=0;j--){
            num+=(int(binario[j+8*i])-48)*pow(2,exp);
            exp++;
        }
        texto[i]=num;
        num=0;
        exp=0;
    }

}

long long Longitud_Archivo(char *archivo)
{
    long long int longitud=0;
    fstream lectura;
    lectura.open(archivo, fstream::in|fstream::binary);
    if(lectura.fail()){
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(lectura.good()){
        lectura.get();
        longitud ++;
    }
    lectura.close();
    longitud --;
    return longitud;
}

void LeerArchivoChar(char *archivo, char *texto)
{
    int pos=0;
    fstream lectura;
    lectura.open(archivo,fstream::in|fstream::binary);
    if(lectura.fail()){
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(lectura.good()){
        texto[pos] =lectura.get();
        pos ++;
    }
    lectura.close();
}

void EscribirArchivoChar(char *archivo, char *texto,long long longitud)
{
    fstream escribir;
    escribir.open(archivo,fstream::out|fstream::binary);
    if(escribir.fail()){
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    for(long long i=0; i<longitud; i++){
        escribir << texto[i];
    }

    escribir.close();
}

string codificacion2(string texto, int semilla)
{
    //metodo de codificacion 2
    string parte,codificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            codificado.append(Cambiar_pos(parte));
            parte.clear();
        }
    }
    else
        codificado.append(Cambiar_pos(texto));
    return codificado;
}

string Cambiar_pos(string binario)
{
    string binarioCodif;
    binarioCodif += binario[binario.length()-1];
    for(int i=0; i<int(binario.length())-1; i++){
        binarioCodif += binario[i];
    }
    return binarioCodif;
}

string decodificacion2(string texto, int semilla)
{
    //metodo de decodificacion 2
    string parte,decodificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            decodificado.append(cambiar_decof(parte));

            parte.clear();
        }
    }
    else
        decodificado.append(cambiar_decof(texto));

    return decodificado;
}

string cambiar_decof(string binario)
{
    string binario_decof;
    binario_decof += binario[1];
    for(int i=2; i<int(binario.length()); i++){
        binario_decof += binario[i];
    }
    binario_decof += binario[0];
    return binario_decof;
}

void codificacion1(int semilla, char *bin,long long int longitud)
{
    char *bincod;
    bincod = new char[longitud*8+1];
    bincod[longitud*8] = '\0';

    long long int pos=0;

    for(int i=0; i<semilla;i++){
        if(pos==longitud*8) break;

        if(bin[i]==49){
            bincod[pos] = '0';
            pos ++;
        }

        else{
            bincod[pos]='1';
            pos ++;
        }
    }

    long long int j=0;
    int cont0=0,cont1=0;

    while (j+semilla<longitud*8){
        int con=0;

        for(int k=0;k<semilla;k++,j++){
            if(bin[j]==48) cont0++;
            if(bin[j]==49) cont1++;
        }

        if(cont0>cont1){
            for(int num=0;num<semilla;j++,num++){

                if(pos==longitud*8) break;
                if(con==1){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con=con+1;
                }
            }
            j=j-semilla;
        }

        else if(cont0<cont1){
            for(int num=0;num<semilla ;j++,num++){
                if(pos==longitud*8) break;

                if(con==2){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con=con+1;
                }
            }
            j = j-semilla;
        }

        else{
            for (int num=0;num<semilla ;j++,num++ ){
                if(pos==longitud*8) break;
                if(bin[j]==49){
                    bincod[pos] = '0';
                    pos ++;
                }
                else{
                    bincod[pos] = '1';
                    pos ++;
                }
            }
            j = j-semilla;
        }
        cont0 = 0;
        cont1 = 0;
    }
    bincod[longitud*8] = '\0';
    strcpy(bin,bincod);

    delete [] bincod;
}

void decodificacion1(int semilla, char *bin,long long longitud)
{
    char *bincod;
    bincod = new char[longitud*8+1];
    bincod[longitud*8] = '\0';

    long long int pos=0;

    for(int i=0; i<semilla;i++){
        if(pos==longitud*8) break;

        if(bin[i]==49){
            bincod[pos] = '0';
            pos ++;
        }
        else{
            bincod[pos]='1';
            pos ++;
        }
    }

    long long int j=0;
    int cont0=0,cont1=0;

    while (j+semilla<longitud*8){
        int con=0;

        for(int k=0;k<semilla;k++,j++){
            if(bincod[j]==48) cont0++;
            else if(bincod[j]==49) cont1++;
        }
        if(cont0==cont1){

            for (int num=0;num<semilla ;j++,num++ ){
                if(pos==longitud*8) break;

                if(bin[j]==49){
                    bincod[pos] = '0';
                    pos ++;
                }
                else{
                    bincod[pos] = '1';
                    pos ++;
                }
            }
            j = j-semilla;
        }
        else if(cont0>cont1){
            for(int num=0;num<semilla;j++,num++){

                if(pos==longitud*8) break;
                if(con==1){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con=con+1;
                }
            }
            j=j-semilla;
        }
        else if(cont0<cont1){
            for(int num=0;num<semilla ;j++,num++){
                if(pos==longitud*8) break;

                if(con==2){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con = con+1;
                }
            }
            j = j-semilla;
        }

        cont0=0;
        cont1=0;
    }
    bincod[longitud*8] = '\0';
    strcpy(bin,bincod);

    delete [] bincod;
}

string metodo(int n, string bin){                 //codifica el texto
    string bincod;

    for (int i=0;i<n ;i++ ) {
        if (bin.size()==bincod.size()) break;

        if(bin[i]==49) bincod=bincod + '0';
        else {
            bincod=bincod + '1';
        }
    }

    float j=0;
    int cont0=0,cont1=0;

    while (j+n<bin.size()) {
        int con=0;


        for (int  k=0;k<n ;k++,j++ ) {
            if(bin[j]==48) cont0+=1;
            if(bin[j]==49) cont1+=1;

        }




        if(cont0>cont1){
            for (int num=0;num<n ;j++,num++ ) {



                if (bin.size()==bincod.size()) break;
                if (con==1) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;}
            }
            j=j-n;
        }
        if(cont0<cont1){
            for (int num=0;num<n ;j++,num++ ) {
                if (bin.size()==bincod.size()) break;


                if (con==2) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;
                }
            }
            j=j-n;
        }
        if(cont0==cont1){
            for (int num=0;num<n ;j++,num++ ) {

                if (bin.size()==bincod.size()) break;

                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
            }
            j=j-n;
        }
        cont0=0;
        cont1=0;

    }

    return bincod;

}

string metododecodificacion(int n, string bin){
    string bincod;
    for (int i=0;i<n ;i++ ) {
        if (bin.size()==bincod.size()) break;

        if(bin[i]==49) bincod=bincod + '0';
        else {
            bincod=bincod + '1';
        }
    }

    float j=0;
    int cont0=0,cont1=0;

    while (j+n<bin.size()) {
        int con=0;


        for (int  k=0;k<n ;k++,j++ ) {
            if(bincod[j]==48) cont0+=1;
            if(bincod[j]==49) cont1+=1;

        }
        if(cont0==cont1){
            for (int num=0;num<n ;j++,num++ ) {

                if (bin.size()==bincod.size()) break;

                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
            }
            j=j-n;
        }
        if(cont0>cont1){
            for (int num=0;num<n ;j++,num++ ) {



                if (bin.size()==bincod.size()) break;
                if (con==1) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;}
            }
            j=j-n;
        }
        if(cont0<cont1){
            for (int num=0;num<n ;j++,num++ ) {
                if (bin.size()==bincod.size()) break;

                if (con==2) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;
                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;
                }
            }
            j=j-n;
        }

        cont0=0;
        cont1=0;

    }

    return bincod;

}
