#ifndef CLASEMUSICOS_H_INCLUDED
#define CLASEMUSICOS_H_INCLUDED

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

class Musico{
    private:
        int DNI;
        char Nombre[30];
        char Apellido[30];
        char Email[30];
        char Telefono[30];
        int Claustro; ///Claustro (1: docente; 2 alumno; 3 no docente; 4 graduado)
        int Instrumento; ///Instrumento principal (número entre 1 y 15)
        int TipodeMusica;///Tipo de música (número entre 1 y 10)
        Fecha Fechainscripcion; /// DEBE SER UNA ANTERIOR O IGUAL A LA ACTUAL
        float Matricula; /// LA MATRICULA DEBE aceptar 0 o numeros positivos
        bool Estado;

    public:
        void setDNI(int i){DNI=i;}
        void setNombre(const char* n){strcpy(Nombre,n);}
        void setApellido(const char* n){strcpy(Apellido,n);}
        void setEmail(const char* n){strcpy(Email,n);}
        void setTelefono(const char* n){strcpy(Telefono,n);}
        void setClaustro(int i){Claustro=i;}
        void setInstrumento(int i){Instrumento=i;}
        void setTipodeMusica(int i){TipodeMusica=i;}
        void setFechaInscripcion(Fecha fe){Fechainscripcion=fe;}
        void setMatricula(float m){Matricula=m;}
        void setEstado(bool e){Estado=e;}

        int getDNI(){return DNI;}
        const char *getNombre(){return Nombre;}
        const char *getApellido(){return Apellido;}
        const char *getEmail(){return Email;}
        const char *getTelefono(){return Telefono;}
        int getClaustro(){return Claustro;}
        int getInstrumento(){return Instrumento;}
        int getTipodeMusica(){return TipodeMusica;}
        Fecha getFechaInscripcion(){return Fechainscripcion;}
        float getMatricula(){return Matricula;}
        bool getEstado(){return Estado;}

        void Cargar();
        void Mostrar();

        void CargarArchivosMusicos();
        int BuscarDNIMusicos(int dni);
        void MostrarArchivosMusicos();
        int buscarPosicionMusico(int d);
        Musico DevolverMusicoLeido(int p);
        void ListarSoloDNI();
        void ModificarFechaConDNI();
        bool modificarRegistroMusico(Musico obj, int pos);
        void EliminarRegistroLogicoM();
        Fecha VerificarFechaAnteriorActual(Fecha Ingresada);

        int leerEnDisco(int pos);
        bool recuMusico();
        int LeerDeDiscobkp(int pos);
        bool backupMusico();
};

void Musico::Mostrar(){

    if(Estado==true){
        cout<<"--- DNI: "<<DNI<<endl;
        cout<<"--- NOMBRE: "<<Nombre<<endl;
        cout<<"--- APELLIDO: "<<Apellido<<endl;
        cout<<"--- EMAIL: "<<Email<<endl;
        cout<<"--- TELEFONO: "<<Telefono<<endl;
        cout<<"--- CLAUSTRO: "<<Claustro<<endl;
        cout<<"--- INSTRUMENTO: "<<Instrumento<<endl;
        cout<<"--- TIPO DE MUSICA: "<<TipodeMusica<<endl;
        cout<<"--- FECHA DE INSCRIPCION: ";
        Fechainscripcion.Mostrar();
        cout<<"--- MATRICULA: "<<Matricula<<endl;
        cout<<"--- ESTADO : "<<Estado<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- "<<endl;
    }
    else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<" --- EL REGISTRO DE MUSICO SE ENCUENTRA DADO DE BAJA, NO SE PUEDE MOSTRAR --- "<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
    }

}

void Musico::Cargar(){

    cout<<" INGRESE EL NOMBRE: "<<endl;
    cargarCadena(Nombre,30);
    cout<<" INGRESE EL APELLIDO:"<<endl;
    cargarCadena(Apellido,30);
    cout<<"INGRESE EL EMAIL: "<<endl;
    cargarCadena(Email,30);
    cout<<"INGRESE EL TELEFONO"<<endl;
    cargarCadena(Telefono,30);

    /*AGREGANDO LOS RANGOS PEDIDOS EN CADA PARAMETRO*/
    cout<<"INGRESE EL NRO CLAUSTRO(RANGO: 1 - 4):"<<endl;
    cin>>Claustro;/// 1,2,3,4
    while(Claustro>4||Claustro<=0){
        cout<<"--- HA INGRESADO UN NRO DE CLAUSTRO INVALIDO ---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL NRO DE CLAUSTRO(ENTRE 1 Y 4): ---"<<endl;
        cin>>Claustro;
    }
    cout<<" INGRESE EL INSTRUMENTO(RANGO: 1 - 15):"<<endl;
    cin>>Instrumento;///Entre 1 - 15
    while(Instrumento>15||Instrumento<=0){
        cout<<"--- HA INGRESADO UN NRO DE INSTRUMENTO INVALIDO ---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL NRO DE INSTRUMENTO(ENTRE 1 Y 15): ---"<<endl;
        cin>>Instrumento;
    }
    cout<<"INGRESE EL TIPO DE MUSICA(RANGO 1 - 10):"<<endl;
    cin>>TipodeMusica;///Entre 1 - 10
    while(TipodeMusica>10||TipodeMusica<=0){
        cout<<"--- HA INGRESADO UN NRO DE TIPO DE MUSICA INVALIDO ---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL NRO DE NURO DE MUSICA (ENTRE 1 Y 10): ---"<<endl;
        cin>>TipodeMusica;
    }

    cout<<"INGRESE UNA FECHA(anterior o igual a la actual):"<<endl;
    Fechainscripcion.Cargar();

    cout<<"INGRESE VALOR DE LA MATRICULA:"<<endl;
    cin>>Matricula;
    while(Matricula<0){
        cout<<"--- POR FAVOR INGRESE VALOR DE LA MATRICULA CON VALORES POSITIVOS: ---"<<endl;
        cin>>Matricula;
    }

    Estado=true;

}

void Musico::CargarArchivosMusicos(){
    int DNI;
    Musico Musi;
    FILE *pMu;
    pMu=fopen("Musico.dat", "ab");/// lo abro en modo agregar

    if(pMu==NULL){
    cout<<"NO PUDO ABRIR/CREAR EL ARCHIVOS"<<endl;
    fclose(pMu);
    return;
    }
    cout<<"--- INGRESE EL NRO DE DNI QUE QUIERE AGREGAR --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>DNI;

    int auxi;
    auxi=BuscarDNIMusicos(DNI); /// -2 SI NO ENCONTRO EL ARCHIVO Y -1 SI ENCONTRO EL DNI   2 Si se puede agregar
    while(auxi<0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- --- EL NUMERO DE DNI INGRESADO, YA SE ENCUENTRA EN LOS REGISTROS --- ---"<<endl;
        cout<<"--- --- POR FAVOR INGRESE EL DNI NUEVAMENTE O 0(cero) PARA SALIR --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>DNI;
        auxi=BuscarDNIMusicos(DNI);///ESTO ES SOLO PARA CHECKEAR SI EXISTE O NO
    }
    if(auxi>0){
        Musi.setDNI(DNI);
        Musi.Cargar();
        int escribio=fwrite(&Musi,sizeof (Musico),1,pMu);

        if(escribio==0){
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<"--- ---EL ARCHIVO NO SE ESCRIBIO CORRECTAMENTE  --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            fclose(pMu);
            return;
        }
    }
fclose(pMu);
return;
}

int Musico::BuscarDNIMusicos(int dni){
    if(dni>0){      ///SOLO HACE LA BUSCACION SI EL DNI ES UN NUMERO POSITIVO
        Musico musicoo;
        FILE *pmusic;
        pmusic=fopen("Musico.dat","rb");
        if(pmusic==NULL){
            cout<<"--- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- NO SE ENCONTRO EL ARCHIVO ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- ---"<<endl;
            return -2;
        }
        while(fread(&musicoo,sizeof musicoo,1,pmusic)==1){
            if(musicoo.getDNI()==dni){///cout<<"DNI ENCONTRADO"<<endl;
            fclose(pmusic);
            return -1;
            }
        }
        fclose(pmusic);
    }
    else if(dni==0){cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- HA INGRESADO 0, USTED ESTA SALIENDO --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            return 0;}
          else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<" --- --- EL NUMERO ES NEGATIVO, NO EXISTEN DNIS NEGATIVOS, USTED ESTA SALIENDO AUTOMATICAMENTE --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            return 0;}

return 2;
}

void Musico::MostrarArchivosMusicos(){
    Musico Musi;
    FILE *pmu;
    pmu=fopen("Musico.dat","rb");/// lo abro en lectura porque solo quiero mostrar
    if(pmu==NULL){
        cout<<"NO PUDO ABRIR/CREAR EL ARCHIVOS"<<endl;
        fclose(pmu);
        return;
    }
    while(fread(&Musi,sizeof (Musico),1,pmu)==1){///Muestra si encuentra el contenido.
      Musi.Mostrar();
    }

    fclose(pmu);
    return ;
}

int Musico::buscarPosicionMusico(int d){
    Musico obj;
    int pos=0;
    FILE *pMusic;
    pMusic=fopen("Musico.dat", "rb");
    if(pMusic==NULL){
        return -2; /// -2 sino leyó nada
    }
    while(fread(&obj, sizeof obj, 1, pMusic)==1){
        if(obj.getDNI() == d){
            fclose(pMusic);
            return pos; /// devuelve la pos
        }
        pos++;
	}
	fclose(pMusic);
	return -1;  /// -1 sino encontro nada
}

Musico Musico::DevolverMusicoLeido(int p){

    Musico obj;

    if(p<0){
        obj.setDNI(-3);/// Significa que el DNI no existe  -3
        return obj;
    }
    FILE *pMusic;
    pMusic=fopen("Musico.dat", "rb");
    if(pMusic==NULL){
        obj.setDNI(-2);/// Sino existe el archivo -2
        return obj;
    }
    fseek(pMusic, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pMusic);
    fclose(pMusic);
    if(aux==0){ /// No pudo leerlo  -1
        obj.setDNI(-1);
    }
    ///obj.Mostrar();
    return obj;
}

void Musico::ListarSoloDNI(){
    Musico obj;
    int DNI;
    cout<<"--- INGRESE EL NRO DE DNI A LISTAR --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>DNI;
    if(DNI>0){
    int pos=buscarPosicionMusico(DNI);
    obj=DevolverMusicoLeido(pos);
    if(obj.getDNI()>0){
        obj.Mostrar();
    }
    else if(obj.getDNI()==-3 || obj.getDNI()==-1){
            cout<<"--- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<"--- EL DNI NO EXISTE EN EL ARCHIVO ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- "<<endl;
          }
        else{
            cout<<"--- --- --- --- --- --- ---"<<endl;
            cout<<"--- ERROR DE ARCHIVO ---"<<endl;
            cout<<"--- --- --- --- --- --- ---"<<endl;
        }
    }
    else if(DNI==0){ cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- HA INGRESADO 0, USTED ESTA SALIENDO --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
        else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<" --- --- EL NUMERO ES NEGATIVO, NO EXISTEN DNIS NEGATIVOS, USTED ESTA SALIENDO AUTOMATICAMENTE --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
}

void Musico::ModificarFechaConDNI(){
    Musico obj;
    Fecha Aux;
    int DNI;
    cout<<"--- INGRESE EL NRO DE DNI A BUSCAR PARA MODIFICAR LA FECHA DE INSCRIPCION --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>DNI;

    int auxi;
    auxi=BuscarDNIMusicos(DNI); /// -2 SI NO ENCONTRO EL ARCHIVO Y -1 SI ENCONTRO EL DNI   2 Si se puede agregar
    while(auxi>0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- --- EL NUMERO DE DNI INGRESADO,NO SE ENCUENTRA EN LOS REGISTROS --- ---"<<endl;
        cout<<"--- --- POR FAVOR INGRESE EL DNI NUEVAMENTE O 0(cero) PARA SALIR --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>DNI;
        auxi=BuscarDNIMusicos(DNI);///ESTO ES SOLO PARA CHECKEAR SI EXISTE O NO
    }

    if(auxi==-1){   ///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE
        int pos=buscarPosicionMusico(DNI);

        FILE *pMusic;
        pMusic = fopen("Musico.dat", "rb+");
        fseek(pMusic, sizeof obj * pos, 0);
        fread(&obj,sizeof (Musico),1,pMusic);
        bool esta2=obj.getEstado();
        fclose(pMusic);

        if(esta2){ /// si el estado es true entonces cargamos fecha nueva, SINO  ESTA DADO DE BAJA Y NO TE DEJA
            Fecha FechaNueva;
            cout<<"--- INGRESE LA FECHA NUEVA"<<endl;
            FechaNueva.Cargar();
            Aux=VerificarFechaAnteriorActual(FechaNueva);///VERIFICO QUE LA NUEVA FECHA SEA ANTERIOR O IGUAL A LA ACTUAL
         //   int pos=buscarPosicionMusico(DNI);  ///BUSCO LA POSICION A TRAVES DEL DNI
         //   obj=DevolverMusicoLeido(pos);   /// LO LEO Y LO TRAIGO
            obj.setFechaInscripcion(Aux);   /// LE MODIFICO LA FECHA

            bool escribio=modificarRegistroMusico(obj,pos);

            if(escribio){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- ---EL ARCHIVO SE SOBRE ESCRIBIO CORRECTAMENTE --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                return;
            }
            else{ cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- HUBO UN ERROR EN LA MODIFICACION DEL ARCHIVO--- ---"<<endl;
            cout<<"--- --- --- INTENTE NUEVAMENTE MAS TARDE--- --- --- --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            return;
            }
        }///IF ESTADO
        else {cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- EL REGISTRO SE ENCUENTRA DADO DE BAJA, NO ES POSIBLE MODIFICARLO --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        }
    }///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE

}

bool Musico::modificarRegistroMusico(Musico obj, int pos){
    FILE *pMusic;
    pMusic = fopen("Musico.dat", "rb+");
    fseek(pMusic, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pMusic);
    fclose(pMusic);
    return aux;
}

void Musico::EliminarRegistroLogicoM(){
    Musico obj;
    int DNI;
    cout<<"--- INGRESE EL NRO DE DNI A BUSCAR PARA ELIMINAR --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>DNI;
    int auxi;
    auxi=BuscarDNIMusicos(DNI); /// -2 SI NO ENCONTRO EL ARCHIVO Y -1 SI ENCONTRO EL DNI   2 Si se puede agregar
    while(auxi>0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- --- EL NUMERO DE DNI INGRESADO,NO SE ENCUENTRA EN LOS REGISTROS --- ---"<<endl;
        cout<<"--- --- POR FAVOR INGRESE EL DNI NUEVAMENTE O 0(cero) PARA SALIR --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>DNI;
        auxi=BuscarDNIMusicos(DNI);///ESTO ES SOLO PARA CHECKEAR SI EXISTE O NO
    }

    if(auxi==-1){   ///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE
        int pos=buscarPosicionMusico(DNI);

        FILE *pMusic;
        pMusic = fopen("Musico.dat", "rb+");
        fseek(pMusic, sizeof obj * pos, 0);
        fread(&obj,sizeof (Musico),1,pMusic);
        bool esta2=obj.getEstado();
        fclose(pMusic);

        if(esta2){ /// si el estado es true entonces cargamos fecha nueva, SINO  ESTA DADO DE BAJA Y NO TE DEJA
           // int pos=buscarPosicionMusico(DNI);  ///BUSCO LA POSICION A TRAVES DEL DNI
          //  obj=DevolverMusicoLeido(pos);   /// LO LEO Y LO TRAIGO
            obj.setEstado(false); /// LE MODIFICO LA FECHA

            bool escribio=modificarRegistroMusico(obj,pos);

            if(escribio){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- ---EL ARCHIVO SE DIO DE BAJA CORRECTAMENTE --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                return;}
            else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- --- HUBO UN ERROR EN LA ELIMINACION LOGICA DEL ARCHIVO --- ---"<<endl;
                cout<<"--- --- --- --- INTENTE NUEVAMENTE MAS TARDE --- --- --- --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            return;}
        }
        else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- EL REGISTRO YA SE ENCUENTRA DADO DE BAJA --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;} ///ELSE ESTADO
    }///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE

}

Fecha Musico::VerificarFechaAnteriorActual(Fecha Ingresada){
    Fecha Actual;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    Actual.setAnio(1900+tmPtr->tm_year);
    Actual.setMes(tmPtr->tm_mon+1);
    Actual.setDia(tmPtr->tm_mday);

    bool a =false;
    int b,c,d;
    do{
        if(Ingresada.getAnio()<Actual.getAnio()){
            a=true; ///Es menor
        }
        else if(Ingresada.getAnio()==Actual.getAnio()){
                if(Ingresada.getMes()<Actual.getMes()){
                    a=true;
                }

            else if(Ingresada.getMes()==Actual.getMes()){
                    if(Ingresada.getDia()<=Actual.getDia()){
                        a=true;
                    }
                 }
        }
                if (a==false){
                    cout<<"HA INGRESADO UNA FECHA INCORRECTA, POR FAVOR INGRESE UNA FECHA ANTERIOR O IGUAL A LA ACTUAL"<<endl;
                    cout<<"DIA: ";
                    cin>>b;
                    cout<<"MES:";
                    cin>>c;
                    cout<<"ANIO:";
                    cin>>d;
                    Ingresada.setDia(b);
                    Ingresada.setMes(c);
                    Ingresada.setAnio(d);
                }

    }while(a==false);


    return Ingresada;
}

int Musico::leerEnDisco(int pos){
    FILE *p;
    p=fopen("Musico.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(Musico)*pos,0);
    int leyo=fread(this,sizeof(Musico),1,p);
    fclose(p);
    return leyo;
}

bool Musico::recuMusico(){
    int pos=0;
    FILE *br;
    br=fopen("Musico.dat","wb");
    if(br==NULL){
        return false;}

    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(Musico),1,br);
        pos++;}

    fclose(br);
    if(pos==0){
        return false;}

    return true;
}

int Musico::LeerDeDiscobkp(int pos){
    FILE *A;
    A=fopen("Musico.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;}

    fseek(A,sizeof(Musico)*pos,0);
    int leyo=fread(this,sizeof(Musico),1,A);
    fclose(A);

    return leyo;
}

bool Musico::backupMusico(){
    int pos=0;
    FILE *b;
    b=fopen("Musico.bkp","wb");
    if(b==NULL){
        return false;}

    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(Musico),1,b);
        pos++;}

    fclose(b);
    if(pos==0){
        return false;}

    return true;
}




#endif // CLASEMUSICOS_H_INCLUDED
