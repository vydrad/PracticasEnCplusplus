#ifndef FUNCIONESPARCHIVOS_H_INCLUDED
#define FUNCIONESPARCHIVOS_H_INCLUDED
void cargarCadena(char *pal, int tam);
bool buscarEstado(int id);
bool checkearinterpretes(int aux);

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

 /// UN HEADER PARA CADA CLASE
class Fecha{
    private:
    int dia,mes,anio;
    public:
        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void Cargar(){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;};

        void Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}

};


class Canciones {
    private:
    int IDcancion;
    char NombreCancion[30];
    char NombreAutor[30];
    int IDinterprete;
    Fecha Fechaestreno;
    bool Estado=false;
    float Duracion;
    int GeneroMusical;

public:
    void setNombreCancion(const char *n){strcpy(NombreCancion,n);}
    void setNombreAutor(const char *n){strcpy (NombreAutor,n);}
    void setIDinterprete(int i){IDinterprete=i;}/// EL ID DE INTERPRETE DEBE EXISTIR EN EL ARCHIVO DE INTERPRETES
    void setIDcancion(int c){IDcancion=c;}/// EL ID NO DEBE REPETIRSE
    void setFechaestreno(Fecha aux){Fechaestreno= aux;}/// DEBE SER UNA FECHA VALIDA ANTERIOR O IGUAL A LA FECHA ACTUAL
    void setEstado(bool e){Estado=e;} /// EL ESTADO DEBE SER VERDADERO PARA QUE EL SISTEMA PUEDA UTILIZAR EL REGISTRO
    void setDuracion(float d){Duracion=d;}/// LA DURACION DEBE SER UN VALOR POSITIVO
    void setGenero(int g){GeneroMusical=g;}/// EL GENERO DEBE SER NUMERO ENTERO DEL 1 AL 10
    void setdia(int d){Fechaestreno.setDia(d);}
    void setmes(int m){Fechaestreno.setMes(m);}
    void setanio(int a){Fechaestreno.setAnio(a);}

    const char *getNombreCancion(){return NombreCancion;}
    const char *getNombreAutor(){return NombreAutor;}
    int getIDcancion(){return IDcancion;}
    int getIDinterprete(){return IDinterprete;}
    Fecha getFechaestreno(){return Fechaestreno;}
    bool getEstado(){return Estado;}
    int getDia(){return getDia();}
    int getMes(){return getMes();}
    int getAnio(){return getAnio();}


    void Cargar();
    void Mostrar();

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("canciones.txt", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Canciones), 0);
    bool leyo=fread(this, sizeof (Canciones), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("canciones.txt", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return escribio;
}

bool modificarEnDisco(int pos){
    FILE *p;
    p=fopen("canciones.txt", "rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Canciones), 0);
    bool modifico=fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return modifico;}

};

int buscarNumeroIDcancion(int id){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getIDcancion()==id){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool buscarEstado(int id){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getIDcancion()==id){
            return obj.getEstado();
        }
        pos++;
    }
    return false;
}


bool CorroborarFecha(Fecha FechaEstreno){

  time_t tiempo;
  struct tm *tmPtr;
  Fecha Actual;

  tiempo = time(NULL);

  tmPtr = localtime(&tiempo);

  Actual.setDia(tmPtr->tm_mday);
  Actual.setMes(tmPtr->tm_mon+1);
  Actual.setAnio(1900+tmPtr->tm_year);

    ///cout<<"LA FECHA ACTUAL ES: "<<Actual.getDia()<<" /"<<Actual.getMes()<<" /"<<Actual.getAnio()<<endl;
   /// system("pause");

    bool aniovalido=false,mesvalido=false,diavalido=false;
  if(FechaEstreno.getAnio()<Actual.getAnio()){
        aniovalido=true;}

    else if(FechaEstreno.getAnio()==Actual.getAnio()){

    if(FechaEstreno.getMes()<Actual.getMes()&&FechaEstreno.getMes()<=12){
    mesvalido=true;}

    else if(FechaEstreno.getMes()==Actual.getMes()&&FechaEstreno.getMes()<=12){

        if(FechaEstreno.getDia()<=Actual.getDia()&&FechaEstreno.getDia()<=31){
            diavalido=true;
        }}}


  if(aniovalido==true||mesvalido==true||diavalido==true){
        return true;
  }

  else{
    return false;
  }
}



    void Canciones::Cargar(){
    cout<<"CARGAR ID DE CANCIONES: "<<endl;
    int aux,pos,pos2;
    cin>> aux;

    pos=buscarNumeroIDcancion(aux);
    bool est=buscarEstado(aux);
    if (est==true){
    while(pos>=0){

        cout<<"EL ID DE LA CANCION INGRESADO YA EXISTE"<<endl;
        cout<<" POR FAVOR INGRESE OTRO ID: "<<endl;
        cin>>aux;
        pos=buscarNumeroIDcancion(aux);

    }}
        setIDcancion(aux);

    cout<<" CARGAR NOMBRE DE CANCION:"<<endl;
    cargarCadena(NombreCancion,30);

    cout<<" CARGAR NOMBRE DEL AUTOR: "<<endl;
    cargarCadena(NombreAutor,30);

    ///***************************************
    cout<<" CARGAR ID DEL INTERPRETE: " <<endl;
    cin>>aux;
   /* bool encontro=checkearinterpretes(aux);

      while(encontro==true){
            cout<<" EL REGISTRO ID INTERPRETE NO EXISTE EN EL ARCHIVO INTERPRETE"<<endl;
             cout<<" POR FAVOR INGRESE OTRO ID:"<<endl;
            cin>>aux;
            encontro=checkearinterpretes(aux);


        }
*/        setIDinterprete(aux);
    ///***************************************
    bool FechaValida=false;
    while(FechaValida==false){
    cout<<"CARGAR FECHA DE ESTRENO: " <<endl;
        int dia,mes,anio;

    cout<<" DIA:";
    cin>> dia;
    Fechaestreno.setDia(dia);

    cout<<" MES:";
    cin>>mes;
    Fechaestreno.setMes(mes);

    cout<<" ANIO:";
    cin>>anio;
    Fechaestreno.setAnio(anio);


    FechaValida=CorroborarFecha(Fechaestreno);

    if(FechaValida==false){
        cout<<"FECHA INVALIDA!"<<endl;
    }
    }

    float aux2;
    cout<<" DURACION DE LA CANCION:"<<endl;

    cin>>aux2;

        while(aux2<=0){
        cout<<"LA DURACION TIENE QUE SER UN VALOR POSITIVO."<<endl;
        cout<<" DURACION DE LA CANCION:"<<endl;
        cin>>aux2;
    }

    setDuracion(aux2);

    cout<<" GENERO MUSICAL:"<<endl;
    cin>>aux;

    while(aux<1||aux>10){
        cout<<"El genero musical debe ser un valor entero entre 1 y 10."<<endl;
        cout<<" GENERO MUSICAL:"<<endl;
        cin>>aux;
    }
    setGenero(aux);

    setEstado(true);
    cout<<endl;
    }



    void Canciones::Mostrar(){
        if(Estado==true){
    cout<<"ID DE CANCION: "<<endl;
    cout<< IDcancion<<endl;
    cout<<"NOMBRE DE CANCION:"<<endl;
    cout<<NombreCancion<<endl;
    cout<<" NOMBRE DEL AUTOR: "<<endl;
    cout<<NombreAutor<<endl;
    cout<<"ID DEL INTERPRETE: " <<endl;/// ESTE SE REPITE
    cout<< IDinterprete<<endl;
    cout<<" FECHA DE ESTRENO " <<endl;
    cout<< Fechaestreno.getDia()<<"/"<<Fechaestreno.getMes()<<"/"<<Fechaestreno.getAnio()<<endl;
    cout<<" DURACION DE LA CANCION:"<<endl;
    cout<<Duracion<<endl;
    cout<<"GENERO MUSICAL"<<endl;/// ESTE SE REPITE
    cout<<GeneroMusical<<endl;
    ///Estado=true;
    cout<<endl;
    }}


bool Agregarcancion(){///ME AGREGA DE A 1
    FILE *p;
    Canciones can;
    int escribio, i;
    p=fopen("canciones.txt","ab");
    if(p==NULL){ cout<<"Error de archivo";
    return false;}

    for (i=0;i<1;i++){
    can.Cargar();
    escribio=fwrite(&can, sizeof(Canciones),1,p);

    if (escribio==0){
        cout<< "NO SE ESCRIBIO NADA"<<endl;
        fclose(p);
        system("pause");
        return false;}
    }
    fclose(p);
    return true;
    }


bool Mostrarcancion(){
    FILE *p;
    Canciones can;
    p=fopen("canciones.txt","rb");
    if(p==NULL){ cout<<"Error de archivo";
    system("pause");
    return false;}

    while(fread(&can, sizeof(Canciones),1,p)==1){
    can.Mostrar();
    cout<<endl;
    }

    fclose(p);
    system("pause");
    return true;
    }


void buscarYlistariDCanciones(){
Canciones obj;
FILE *p;

p=fopen("canciones.txt","rb");
if(p==NULL){
    cout<<"Error de archivo, (no encontrado)"<<endl;}
int aux,pos;
cout<<"INGRESE EL ID DE CANCION QUE QUIERE VER:"<<endl;
cin>>aux;
pos=buscarNumeroIDcancion(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDcancion(aux);
}
fseek(p,pos*sizeof(Canciones),0);
fread(&obj,sizeof (Canciones),1,p);
obj.Mostrar();

system("pause");
fclose(p);
}


bool ModificarFechaEstreno(){
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR CATEGORIA DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
Canciones obj;
int aux,pos;

cout<<"INGRESE EL ID DE CANCION QUE QUIERE EDITAR:"<<endl;
cin>>aux;
pos=buscarNumeroIDcancion(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDcancion(aux);
}
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
        return false;}


cout<<"INGRESE LA NUEVA FECHA DE ESTRENO"<<endl;
int a,b,c;
cout<<"INGRESE DIA:"<<endl;
cin>>a;
obj.setdia(a);
cout<<"INGRESE MES:"<<endl;
cin>>b;
obj.setmes(b);
cout<<"INGRESE ANIO:"<<endl;
cin>>c;
obj.setanio(c);

obj.Mostrar();
obj.modificarEnDisco(pos);
system("pause");

}


bool EliminarCancion(){
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR ESTADO DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
    Canciones obj;
    int id, pos;
    cout<<"INGRESE NUMERO DE ID de CANCION A ELIMINAR: "<<endl;
    cin>>id;
    pos=buscarNumeroIDcancion(id);
    if(pos==-1){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        system("pause");
        return false;

    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
        system("pause");
        return false;}

    obj.setEstado(false);
    cout<<"AHORA EL ESTADO ACTUAL DEL ARCHIVO ES:"<<obj.getEstado()<<endl;
     system("pause");
    return obj.modificarEnDisco(pos);

}



#endif // FUNCIONESPARCHIVOS_H_INCLUDED
