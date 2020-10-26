#include "cajero.h"


void inicio()
{

    int opc;
    cout << "\n-----------------Menu  Principal-----------------\n";
    cout<<"Preisione:\n1. Para ingresar como administrador.\n2. para ingresar como usuario.\n0.Para salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            if(ClaveAdmin())
                administrador();
            else
                cout << "clave incorrecta." << endl;

        }
            break;
        case 2:{
            usuario();

        }
            break;
        default:
            cout<<"Opcion no valida.\n";
        }
        cout << "\n-----------------Menu  Principal-----------------\n";
        cout<<"Preisione:\n1. Para ingresar como administrador.\n2. para ingresar como usuario.\n0.Para salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }
}


void administrador()
{
    int opc=0;
    cout << "\n---------------Menu  Administrador---------------\n";
    cout<<"Preisione:\n1.Ver informacion de usuarios.\n2.Registrar nuevo usurio.\n3.Eliminar Usuario.\n4.Agregar dinero a un usuario.\n0.Salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            VerInfoUsuarios();
        }
            break;
        case 2:{
            RegistrarUsuario();

        }
            break;
        case 3:{

            EliminarUsuario();
        }
            break;
        case 4:{

        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << "\n---------------Menu  Administrador---------------\n";
        cout<<"Preisione:\n1.Ver informacion de usuarios.\n2.Registrar nuevo usurio.\n3.Eliminar Usuario.\n4.Agregar dinero a un usuario.\n0.Salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }
}

void usuario()
{

    int opc=0,retiro=0;

    cout << "\n---------------Menu  Usuario---------------\n";
    cout<<"Preisione:\n1.Consultar saldo.\n2.Retirar dinero.\n0.Salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while(opc!=0){
        switch (opc) {
        case 1:{

            retiro=0;
            modificarsaldo(retiro);
        }
            break;
        case 2:{

        cout<<"ingrese el dinero a retirar, debe ser multiplo de 1000"<<endl;
        cin>>retiro;
         modificarsaldo(retiro);

        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << "\n---------------Menu  Administrador---------------\n";
        cout<<"Preisione:\n1.Consultar saldo.\n2.Retirar dinero.\n0.Salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }



}



void modificarsaldo(int retiro){
    string ce,cl;
   if ( verificaretiro(retiro)==true) {
    cout<<"ingrese su cedula"<<endl;
    cin>>ce;

    if (SoloNumeros(ce)) {
        if (ComprobarCedula(ce)) {
            cout<<"ingrese su clave"<<endl;
            cin>>cl;
            if (Comprobarclave(cl)) {

                string usuario,modusuario;
                int pos=0;
                usuario=DecodificarInfo("sudo.dat");


                pos = usuario.find('\n');

                modusuario+= usuario.substr(0,pos-1);

                usuario = usuario.substr(pos+1);



                for(int num=1;pos!=-1;num++){
                   string cedula,clave,saldo;
                   pos = usuario.find(':');
                   cedula = usuario.substr(0,pos);
                   pos = usuario.find(':',pos+1);
                   clave = usuario.substr(0,pos);
                   clave = clave.substr(cedula.size()+1);
                   pos = usuario.find('\r');
                   saldo = usuario.substr(0,pos);
                   saldo = saldo.substr(cedula.size()+clave.size()+2);

                   if (ce==cedula and cl==clave){
                            int saldomod = stoi(saldo, nullptr, 10);



                           if(retiro!=0 and (saldomod-1000)-retiro>=0){
                               cout<<"su saldo es de "<<saldo<<" COP"<<endl;

                               cout<<"se ha retirado"<<retiro<< " COP"<<endl;
                                cout<<"la transaccion tendra un costo de 1000 COP"<<endl;
                                saldomod-=1000;
                                saldomod-=retiro;


                                string mod= to_string(saldomod);

                                cout<< "su nuevo saldo es de "<< mod<< " COP"<<endl;


                                modusuario += "\r\n" + cedula + ':' + clave + ':' + mod;
                           }
                           else if(retiro==0 and saldomod-1000>=0) {
                               cout<<"su saldo es de "<<saldo<<" COP"<<endl;

                               cout<<"la consulta tendra un costo de 1000 COP"<<endl;

                               saldomod-=1000;

                               string mod= to_string(saldomod);

                               cout<< "su nuevo saldo es de "<< mod<< " COP"<<endl;


                               modusuario += "\r\n" + cedula + ':' + clave + ':' + mod;

                           }

                           else {
                               cout<<"no es posible realizar la accion, no hay suficiente dinero"<<endl;
                               modusuario += "\r\n" + cedula + ':' + clave + ':' + saldo;

                           }

                   }
                   else {
                       modusuario += "\r\n" + cedula + ':' + clave + ':' + saldo;

                   }




                   pos = usuario.find('\n');
                   usuario = usuario.substr(pos+1);

                }


                CodificarInfo(modusuario);
                cout<<modusuario<<endl;

            }
            else {
                cout<<"clave incorrecta"<<endl;
            }


        }
        else {
         cout << "La cedula no corresponde a ningun usuario"<<endl;
        }

        }

    else {
        cout<<"La cedula son solo digitos"<<endl;

    }


}
   else {
       cout<<"no es posible realizar el retiro, no es divisible entre 1000"<<endl;

   }
}


bool Comprobarclave(string cl)
{
    string info, clave, cedula;
    int pos = 0;
    info = DecodificarInfo("sudo.dat");
    pos = info.find('\n');
    info = info.substr(pos+1);
    while(pos!= -1){
        pos = info.find(":");
        cedula = info.substr(0,pos);
        pos = info.find(':',pos+1);
        clave = info.substr(0,pos);
        clave = clave.substr(cedula.size()+1);

        if(clave == cl)
            return true;
        pos = info.find('\n');
        info = info.substr(pos+1);
    }
    return false;
}



bool verificaretiro( int retiro){
    if (retiro%1000==0 )   return true;

    else {
        return false;
    }
}













void CodificarInfo(string info)
{
    info = Str_to_Binary(info);
    info = codificacion2(info,4);
    info = Binary_to_Str(info);
    EscribirArchivo("sudo.dat",info);

}

string DecodificarInfo(string archivo)
{
    string info;
    info = LeerArchivo(archivo);
    info = Str_to_Binary(info);
    info = decodificacion2(info,4);
    info = Binary_to_Str(info);

    return info;
}

bool ClaveAdmin()
{
    int pos=0;
    string clave,clave_admin;
    cin.ignore(10000,'\n');
    cout << "Ingrese la clave de administrador: ";getline(cin,clave);
    clave_admin = DecodificarInfo("sudo.dat");
    pos = clave_admin.find('\r');
    clave_admin = clave_admin.substr(0,pos);
    if(clave_admin==clave)
        return true;
    else
        return false;
}


void VerInfoUsuarios()
{
    string usuarios;
    int pos = 0;
    usuarios = DecodificarInfo("sudo.dat");
    pos = usuarios.find('\n');
   usuarios = usuarios.substr(pos+1);
   for(int num=1;pos!=-1;num++){
       string cedula,clave,saldo;
       pos = usuarios.find(':');
       cedula = usuarios.substr(0,pos);
       pos = usuarios.find(':',pos+1);
       clave = usuarios.substr(0,pos);
       clave = clave.substr(cedula.size()+1);
       pos = usuarios.find('\r');
       saldo = usuarios.substr(0,pos);
       saldo = saldo.substr(cedula.size()+clave.size()+2);
       cout << "-------Usuario" <<  num <<"-------\n";
       cout << "Cedula: " << cedula << endl;
       cout << "Clave: " << clave << endl;
       cout << "Saldo: " << saldo << "COP\n" << endl;
       pos = usuarios.find('\n');
       usuarios = usuarios.substr(pos+1);
   }
}

void RegistrarUsuario()
{
    string info,cedula,clave,saldo;
    bool salir = true;
    long long dinero = 0;
    info = DecodificarInfo("sudo.dat");
    cin.ignore(10000,'\n');
    cout << "Ingrese la cedula del nuevo usuario: ";getline(cin,cedula);
    if(!ComprobarCedula(cedula)){
        if(SoloNumeros(cedula)){
            cout << "Ingrese la nueva clave del usuario: ";getline(cin, clave);
            while(salir){
                cout << "Ingerese el dinero inicial del usuario, debe ser mayor a 500000 COP y divisible entre 1000.\n";
                cout << "Dinero inicial: ";cin >> dinero;
                if(dinero>=500000 and dinero%1000==0){
                    salir = false;
                    saldo = to_string(dinero);
                    info += "\r\n" + cedula + ':' + clave + ':' + saldo;
                    CodificarInfo(info);
                }
                else{
                    cout << "cantidad de dinero insuficiente.\n";
                    cout << "Presione 1 para agregar dinero o 0 para salir: ";cin>>salir;
                }
            }
        }
        else
            cout << "La cedula son solo digitos.\n";
    }
    else
        cout << "Este numero de cedula ya se encuentra registrado.\n";

    cout << "Usuario registrado con exito!\n";
}

bool ComprobarCedula(string cedula)
{
    string info, cedula_c;
    int pos = 0;
    info = DecodificarInfo("sudo.dat");
    pos = info.find('\n');
    info = info.substr(pos+1);
    while(pos!= -1){
        pos = info.find(":");
        cedula_c = info.substr(0,pos);
        if(cedula_c == cedula)
            return true;
        pos = info.find('\n');
        info = info.substr(pos+1);
    }
    return false;
}

bool SoloNumeros(string str)
{
    for(int i=0;i<int(str.size());i++){
        if((int(str[i])<48) or (int(str[i])>57))
            return false;
    }
    return true;
}

void EliminarUsuario()
{
    string cedula;
    cout << "Para eliminar usuario su saldo debe ser 0 COP.\n";
    cin.ignore(10000,'\n');
    cout << "Cedula del usuario: ";getline(cin,cedula);
    if(ComprobarCedula(cedula)){
        if(ComprobarSaldo0(cedula)){
            string info,info_final,usuario;
            int pos;
            info = DecodificarInfo("sudo.dat");
            pos = info.find('\n');
            info = info.substr(pos+1);
            while(pos!=-1){
                pos = info.find('\r');
                usuario = info.substr(0,pos);
                pos = info.find(':');
                if(cedula == usuario.substr(0,pos))
                   info_final += usuario + "\r\n";

                pos = info.find('\n');
                info = info.substr(pos+1);
            }
        }
        else
            cout << "El saldo del usurio con cc: " << cedula << " no es 0 COP\n";
    }
    else
        cout << "La cedula ingresada no se encuentra registrada.\n";

    cout << "Usuario eliminado.\n";

}

bool ComprobarSaldo0(string cedula)
{
    string info,usuario;
    int pos = 0;
    info = DecodificarInfo("sudo.dat");
    pos = info.find('\n');
    info = info.substr(pos+1);
    while(pos!=-1){
        pos = info.find('\r');
        usuario = info.substr(0,pos);
        pos = usuario.find(':');
        if(cedula == usuario.substr(0,pos)){
            pos = usuario.rfind(':');
            //usuario = usuario.substr(pos);
            if(usuario.substr(pos)[0]=='0')
                return true;
        }
        pos = info.find('\n');
        info = info.substr(pos+1);
    }
    return false;
}
