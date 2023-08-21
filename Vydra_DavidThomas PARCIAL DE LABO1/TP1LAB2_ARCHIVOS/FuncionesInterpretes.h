#ifndef FUNCIONESINTERPRETES_H_INCLUDED
#define FUNCIONESINTERPRETES_H_INCLUDED

int buscarNumeroIDinterprete(int id);
bool buscarEstado2(int id);


class interprete{
protected:
int IDinterprete;
char Nombrebanda[40];
int Nacionalidad; ///entre 1 y 100
int Tipointerprete;/// entre 1 y 5
int Generomusical2;///entre 1 y 10
Fecha FechaInicioact;///
bool Estado2=false;

public:
    void setIDinterprete2(int i){IDinterprete=i;} /// EL INTERPRETE SE REPITE EN LA PRIMERA CLASE

    void setNombrebanda(const char *n){strcpy(Nombrebanda,n);}
    void setNacionalidad(int g){Nacionalidad=g;}

    void setFechainicioact(Fecha aux){FechaInicioact= aux;}/// DEBE SER UNA FECHA VALIDA ANTERIOR O IGUAL A LA FECHA ACTUAL
    void setEstado(bool e){Estado2=e;} /// EL ESTADO DEBE SER VERDADERO PARA QUE EL SISTEMA PUEDA UTILIZAR EL REGISTRO
    void setTipointerprete(int i){Tipointerprete=i;}
    void setGenero(int g){Generomusical2=g;} /// EL SE REPITE EN LA PRIMERA CLASE
    void setdia(int d){FechaInicioact.setDia(d);}
    void setmes(int m){FechaInicioact.setMes(m);}
    void setanio(int a){FechaInicioact.setAnio(a);}

    int getIDinterprete2(){return IDinterprete;}
    const char *getNombrebanda(){return Nombrebanda;}
    int getNacionalidad(){return Nacionalidad;}
    int getTipointerprete(){return Tipointerprete;}
    Fecha getFechaestreno(){return FechaInicioact;}
    int getGeneromusical2(){return Generomusical2;}
    bool getEstado2(){return Estado2;}

    int getDia(){return getDia();}
    int getMes(){return getMes();}
    int getAnio(){return getAnio();}

    void Cargar();
    void Mostrar();


bool leerDeDisco2(int pos){
    FILE *p;
    p=fopen("interpretes.txt", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (interprete), 0);
    bool leyo=fread(this, sizeof (interprete), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco2(){
    FILE *p;
    p=fopen("interpretes.txt", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (interprete), 1, p);
    fclose(p);
    return escribio;
}

bool modificarEnDisco2(int pos){
    FILE *p;
    p=fopen("interpretes.txt", "rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (interprete), 0);
    bool modifico=fwrite(this, sizeof (interprete), 1, p);
    fclose(p);
    return modifico;}



};



    void interprete::Cargar(){
 int aux,pos=0;
    cout<<" CARGAR ID DEL INTERPRETE: " <<endl;
    cin>> aux;

        pos=buscarNumeroIDinterprete(aux);
        bool est2=buscarEstado2(aux);
        if(est2==true){
    while(pos>=0){

        cout<<"EL ID DE INTERPRETE INGRESADO YA EXISTE"<<endl;
        cout<<" POR FAVOR INGRESE OTRO ID: "<<endl;
        cin>>aux;
        pos=buscarNumeroIDinterprete(aux);

        }}
        setIDinterprete2(aux);

    cout<<" CARGAR NOMBRE DE LA BANDA:"<<endl;
    cargarCadena(Nombrebanda,40);

    cout<<"CARGAR NACIONALIDAD: (1 a 100):"<<endl;

      cin>>aux;

        while(aux<1||aux>100){
        cout<<"La nacionalidad del interprete solo debe aceptar valores enteros entre 1 y 100."<<endl;
        cout<<"CARGAR NACIONALIDAD: (1 a 100):"<<endl;
        cin>>aux;}

    setNacionalidad(aux);

    cout<<" CARGAR TIPO DE INSTRUMENTACION: (1 a 5)"<<endl;

    cin>>aux;

        while(aux<1||aux>5){
        cout<<"Tipo de interprete representa si es solista, grupo, orquesta, etc. Solo debe aceptar valores enteros entre 1 y 5."<<endl;

        cout<<"CARGAR TIPO DE INTERPRETE: (1 a 5):"<<endl;
        cin>>aux;
    }

    setTipointerprete(aux);

    cout<<"GENERO MUSICAL PRINCIPAL: (1 a 10):"<<endl;

    cin>>aux;

        while(aux<1||aux>10){
        cout<<"El genero musical debe ser un valor entero entre 1 y 10."<<endl;
        cout<<" GENERO MUSICAL:"<<endl;
        cin>>aux;
    }

    setGenero(aux);
    bool FechaValida=false;
    while(FechaValida==false){
    cout<<" CARGAR FECHA DE INICIO DE ACTIVIDAD: " <<endl;

    cout<<" DIA:"<<endl;
    int a,b,c;
    cin>> a ;
     FechaInicioact.setDia(a);
    cout<<" MES:"<<endl;
    cin>>b;
    FechaInicioact.setMes(b);
    cout<<" ANIO:"<<endl;
    cin>>c;
    FechaInicioact.setAnio(c);

    FechaValida=CorroborarFecha(FechaInicioact);

    if(FechaValida==false){
        cout<<"FECHA INVALIDA!"<<endl;
    }
    }


    setEstado(true);
    }


    void interprete::Mostrar(){
        if (Estado2==true){
    cout<<"ID DEL INTERPRETE: " ;
    cout<< IDinterprete<<endl;
    cout<<"NOMBRE DE LA BANDA:";
    cout<< Nombrebanda<<endl;
    cout<<"NACIONALIDAD: ";
    cout<< Nacionalidad<<endl;
    cout<<"TIPO DE INTERPRETE: ";
    cout<<Tipointerprete<<endl;
    cout<<"GENERO MUSICAL PRINCIPAL: ";
    cout<<Generomusical2<<endl;
    cout<<"FECHA DE INICIO DE ACTIVIDAD: " ;
    cout<< FechaInicioact.getDia() <<"/"<<FechaInicioact.getMes()<<"/"<<FechaInicioact.getAnio()<<endl;
        }
    }

bool Agregarinterprete(){
    FILE *f;
    interprete inter;
    int escribio, i;
    f=fopen("interpretes.txt","ab");
    if(f==NULL){ cout<<"Error de archivo";
    return false;}

    for (i=0;i<1;i++){
     inter.Cargar();
    escribio=fwrite(&inter, sizeof(interprete),1,f);

    if (escribio==0){
        cout<< "NO SE ESCRIBIO NADA"<<endl;
        fclose(f);
        system("pause");
        return false;}
    }
    fclose(f);
    return true;
    }

int buscarNumeroIDinterprete(int id){
    interprete obj;
    int pos=0;
    while(obj.leerDeDisco2(pos)){
        if(obj.getIDinterprete2()==id){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool buscarEstado2(int id){
    interprete obj;
    int pos=0;
    while(obj.leerDeDisco2(pos)){
        if(obj.getIDinterprete2()==id){
            return obj.getEstado2();
        }
        pos++;
    }
    return false;
}




/// Me va a leer la cantidad de registros existentes
bool Mostrarinterprete(){

    FILE *p;
    interprete inter;
    p=fopen("interpretes.txt","rb");
    if(p==NULL){ cout<<"Error de archivo";
    system("pause");
    return false;}

    while(fread(&inter, sizeof(interprete),1,p)==1){
    inter.Mostrar();
    cout<<endl;
    }

    fclose(p);
    system("pause");
    return true;
    }




void buscarYlistariDinterprete(){
interprete obj;
FILE *p;

p=fopen("interpretes.txt","rb");
if(p==NULL){
    cout<<"Error de archivo, (no encontrado)"<<endl;}
int aux,pos;
cout<<"INGRESE EL ID DE INTERPRETE QUE QUIERE VER:"<<endl;
cin>>aux;
pos=buscarNumeroIDinterprete(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDinterprete(aux);
}
fseek(p,pos*sizeof(interprete),0);
fread(&obj,sizeof (interprete),1,p);
obj.Mostrar();

system("pause");
fclose(p);
}


bool ModificarGeneroMusical(){
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR CATEGORIA DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
interprete obj;
int aux,pos;

cout<<"INGRESE EL ID DE INTERPRETE QUE QUIERE EDITAR:"<<endl;
cin>>aux;
pos=buscarNumeroIDinterprete(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDinterprete(aux);
}
    obj.leerDeDisco2(pos);
    if(obj.getEstado2()==false){
        cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
        return false;}


cout<<"INGRESE EL NUEVO GENERO MUSICAL (1 a 10):"<<endl;
cin>>aux;

while(aux<1||aux>10){
    cout<<"HA INGRESAO UN NUEMRO INVALIDO!! INGRESE NUEVAMENTE (1 a 10):"<<endl;
    cin>>aux;

}

obj.setGenero(aux);

obj.Mostrar();
obj.modificarEnDisco2(pos);
system("pause");

}


bool Eliminarinterprete(){
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR ESTADO DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
    interprete obj;
    int id, pos;
    cout<<"INGRESE NUMERO DE ID de CANCION A ELIMINAR: "<<endl;
    cin>>id;
    pos=buscarNumeroIDinterprete(id);
    if(pos==-1){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        system("pause");
        return false;

    }
    obj.leerDeDisco2(pos);
    if(obj.getEstado2()==false){
        cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
        system("pause");
        return false;}

    obj.setEstado(false);
    cout<<"AHORA EL ESTADO ACTUAL DEL ARCHIVO ES:"<<obj.getEstado2()<<endl;
     system("pause");
    return obj.modificarEnDisco2(pos);

}
/*
bool checkearinterpretes(int aux){

interprete obj2;
int pos=0;
pos=buscarNumeroIDinterprete(aux);
if (pos <0){
bool leyo=obj2.leerDeDisco2(pos);

return leyo;
}
else return false;

}
*/

#endif // FUNCIONESINTERPRETES_H_INCLUDED
