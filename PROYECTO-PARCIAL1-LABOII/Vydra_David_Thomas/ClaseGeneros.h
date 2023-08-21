#ifndef CLASEGENEROS_H_INCLUDED
#define CLASEGENEROS_H_INCLUDED

class Genero{
private:
    int IDgenero; ///Autonumerico, NO debe repetirse
    char Nombre[30]; ///
    int paisOrigen; /// 1 a 100
    int anioOrigen; /// 1500 al actual
    bool Estado;

public:
    void setIDgenero(int id){IDgenero=id;}
    void setNombre(const char* nom){strcpy(Nombre,nom);}
    void setpaisOrigen(int pais){paisOrigen=pais;}
    void setanioOrigen(int anio){anioOrigen=anio;}
    void setEstado(bool a){Estado=a;}

    int getIDgenero(){return IDgenero;}
    const char* getNombre(){return Nombre;}
    int getpaisOrigen(){return paisOrigen;}
    int getanioOrigen(){return anioOrigen;}
    int getEstado(){return Estado;}


    int VerificarAnio(int anio);
    void Cargar(int aux);
    void CargarArchivosGeneros();
    int BuscarIDgenero(int id);

    int autonumericoIDgenero();
    int leerEnDisco(int pos);

    void Mostrar();
    void MostrarArchivosGeneros();

    void ListarSoloID();
    int buscarPosicionGenero(int d);
    Genero DevolverGeneroLeido(int p);

    void ModificarFechaConIDgenero();

    void EliminarRegistroLogicoG();

    bool modificarRegistroGenero(Genero obj, int pos);


        bool recuGenero();
        int LeerDeDiscobkp(int pos);
        bool backupGenero();
};

void Genero::Mostrar(){
    if(Estado==true){
        cout<<"--- ID DE GENERO: "<<IDgenero<<endl;
        cout<<"--- NOMBRE: "<<Nombre<<endl;
        cout<<"--- PAIS DE ORIGEN: "<<paisOrigen<<endl;
        cout<<"--- ANIO DE ORIGEN: "<<anioOrigen<<endl;
        cout<<"--- ESTADO: "<<Estado<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- "<<endl;
    }
    else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        cout<<" --- EL REGISTRO DE GENERO ENCUENTRA DADO DE BAJA, NO SE PUEDE MOSTRAR --- "<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
    }

void Genero::MostrarArchivosGeneros(){
    Genero Gene;
    FILE *pGENE;
    pGENE=fopen("Genero.dat","rb");/// lo abro en lectura porque solo quiero mostrar
    if(pGENE==NULL){
        cout<<"NO PUDO ABRIR/CREAR EL ARCHIVOS"<<endl;
        fclose(pGENE);
        return;
    }
    while(fread(&Gene,sizeof (Genero),1,pGENE)==1){///Muestra si encuentra el contenido.
        Gene.Mostrar();
    }
    fclose(pGENE);
    return ;

}

void Genero::Cargar(int aux){

    IDgenero=autonumericoIDgenero();

    cout<<"--- INGRESE EL NOMBRE: "<<endl;
    cargarCadena(Nombre,30);

    paisOrigen=aux;
  /*  cout<<"INGRESE EL NRO DE PAIS DE ORIGEN"<<endl;
    cin>>paisOrigen;///
    while(paisOrigen>100||paisOrigen<=0){
        cout<<"HA INGRESADO UN NRO DE PAIS DE ORIGEN INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL NRO DE PAIS DE ORIGEN(1 - 100)"<<endl;
        cin>>paisOrigen;
    }*/

    int anio;
    cout<<"--- INGRESE EL INSTRUMENTO ANIO DE ORIGEN: "<<endl;
    cin>>anio;///
    anioOrigen=VerificarAnio(anio);

    Estado=true;

}

void Genero::CargarArchivosGeneros(){

    Genero Gene;
    FILE *pGENE;
    pGENE=fopen("Genero.dat", "ab");/// lo abro en modo agregar

    if(pGENE==NULL){
        cout<<"NO PUDO ABRIR/CREAR EL ARCHIVOS"<<endl;
        fclose(pGENE);
        return;}

    int aux;
    cout<<"--- INGRESE EL NRO DE PAIS DE ORIGEN PARA CARGAR --- O 0(Cero) PARA SALIR AL MENU ANTERIOR:"<<endl;
    cout<<"--- ";cin>>aux;
    if(aux>0){
    while(aux>100||aux<=0){
        cout<<"HA INGRESADO UN NRO DE PAIS DE ORIGEN INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL NRO DE PAIS DE ORIGEN(1 - 100)"<<endl;
        cin>>aux;
    }

    Gene.Cargar(aux);
    int escribio=fwrite(&Gene,sizeof (Genero),1,pGENE);

    if(escribio==0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- ---EL ARCHIVO NO SE ESCRIBIO CORRECTAMENTE --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        fclose(pGENE);
        return;}

    fclose(pGENE);
    return;
    }
        else if(aux==0){cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- HA INGRESADO 0, USTED ESTA SALIENDO --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            }
        else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- EL NUMERO ES NEGATIVO, NO EXISTEN NRO DE GENEROS NEGATIVOS, USTED ESTA SALIENDO AUTOMATICAMENTE --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            }

}

int Genero::BuscarIDgenero(int id){
    if(id>0){
        Genero Gene;
        FILE *pGENE;
        pGENE=fopen("Genero.dat","rb");
        if(pGENE==NULL){
            cout<<"--- NO SE ENCONTRO EL ARCHIVO ---"<<endl;
            return -2;}

        while(fread(&Gene,sizeof (Genero),1,pGENE)==1){
            if(Gene.getIDgenero()==id){
            fclose(pGENE);
            return -1;}
        }

        fclose(pGENE);
    }
    else if(id==0){cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- HA INGRESADO 0, USTED ESTA SALIENDO --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            return 0;}
        else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<" --- --- EL NUMERO ES NEGATIVO, NO EXISTEN NRO DE GENEROS NEGATIVOS, USTED ESTA SALIENDO AUTOMATICAMENTE --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            return 0;}

return 2;
}

void Genero::ListarSoloID(){
    Genero obj;
    int ID;
    cout<<"--- INGRESE EL NRO DE ID DE GENERO A LISTAR --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>ID;
    if(ID>0){
    int pos=buscarPosicionGenero(ID);
    obj=DevolverGeneroLeido(pos);
    ///cout<<"IDGENERO:"<<obj.getIDgenero()<<endl;
    if(obj.getIDgenero()>0){
        obj.Mostrar();}
    else if(obj.getIDgenero()==-3 || obj.getIDgenero()==-1){
            cout<<"--- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- EL ID DE GENERO NO EXISTE EN EL ARCHIVO ---"<<endl;
             cout<<"--- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
          }
        else{
            cout<<"--- --- --- --- --- --- ---"<<endl;
            cout<<"--- ERROR DE ARCHIVO ---"<<endl;
            cout<<"--- --- --- --- --- --- ---"<<endl;
        }
    }
    else if(ID==0){ cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<" --- --- HA INGRESADO 0, USTED ESTA SALIENDO --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
        else{cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<" --- --- EL NUMERO ES NEGATIVO, NO EXISTEN DNIS NEGATIVOS, USTED ESTA SALIENDO AUTOMATICAMENTE --- ---"<<endl;
            cout<<" --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
}

int Genero::buscarPosicionGenero(int d){
    Genero obj;
    int pos=0;
    FILE *pGENE;
    pGENE=fopen("Genero.dat", "rb");
    if(pGENE==NULL){
        return -2; /// -2 sino leyó nada
    }
    while(fread(&obj, sizeof obj, 1, pGENE)==1){
        if(obj.getIDgenero() == d){
            fclose(pGENE);
            return pos; /// devuelve la pos
        }
        pos++;
	}
	fclose(pGENE);
	return -1;  /// -1 sino encontro nada
}

Genero Genero::DevolverGeneroLeido(int p){
    Genero obj;

    if(p<0){///LA POSICION NO EXISTE
        obj.setIDgenero(-3);/// Significa que el DNI no existe  -3
        return obj;
    }
    FILE *pGENE;
    pGENE=fopen("Genero.dat", "rb");
    if(pGENE==NULL){
        obj.setIDgenero(-2);/// Sino existe el archivo -2
        return obj;
    }
    fseek(pGENE, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pGENE);
    fclose(pGENE);
    if(aux==0){ /// No pudo leerlo  -1
        obj.setIDgenero(-1);
    }
    ///obj.Mostrar();
    return obj;
}

void Genero::ModificarFechaConIDgenero(){

    Genero obj;
    int ID;

    cout<<"--- INGRESE EL NRO DE ID DE GENERO QUE BUSCA PARA MODIFICAR ANIO DE ORIGEN --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>ID;

    int auxi;
    auxi=BuscarIDgenero(ID); /// -2 SI NO ENCONTRO EL ARCHIVO Y -1 SI ENCONTRO EL DNI   2 Si se puede agregar
    while(auxi>0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- --- EL NUMERO DE ID DE GENERO INGRESADO,NO SE ENCUENTRA EN LOS REGISTROS --- ---"<<endl;
        cout<<"--- --- --- POR FAVOR INGRESE EL DNI NUEVAMENTE O 0(cero) PARA SALIR --- --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>ID;
        auxi=BuscarIDgenero(ID);///ESTO ES SOLO PARA CHECKEAR SI EXISTE O NO
    }

    if(auxi==-1){   ///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE
        int pos=buscarPosicionGenero(ID);

        FILE *pGENE;
        pGENE = fopen("Genero.dat", "rb+");
        fseek(pGENE, sizeof obj * pos, 0);
        fread(&obj,sizeof (Genero),1,pGENE);
        bool esta2=obj.getEstado();
        fclose(pGENE);

        if(esta2){ /// si el estado es true entonces cargamos fecha nueva, SINO  ESTA DADO DE BAJA Y NO TE DEJA
            int anio, anioaux;
            cout<<"--- INGRESE EL NUEVO ANIO DE ORIGEN"<<endl;
            cin>>anio;
            anioaux=VerificarAnio(anio);
            //VERIFICO QUE LA NUEVA FECHA DEL 1500 EN ADELANTE HASTA EL AÑO ACTUAL
         //   int pos=buscarPosicionGenero(ID);  ///BUSCO LA POSICION A TRAVES DEL ID
         //   obj=DevolverGeneroLeido(pos);   /// LO LEO Y LO TRAIGO
            obj.setanioOrigen(anioaux);   /// LE MODIFICO LA FECHA

            bool escribio=modificarRegistroGenero(obj,pos);

            if(escribio){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- ---EL ARCHIVO SE SOBRE ESCRIBIO CORRECTAMENTE --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                return;}
            else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- --- HUBO UN ERROR EN LA MODIFICACION DEL ARCHIVO--- ---"<<endl;
                cout<<"--- --- --- INTENTE NUEVAMENTE MAS TARDE--- --- --- --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                return;}
        } ///IF ESTADO
        else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- EL REGISTRO SE ENCUENTRA DADO DE BAJA, NO ES POSIBLE MODIFICARLO --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}
    }///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE

}

void Genero::EliminarRegistroLogicoG(){
    Genero obj;
    int ID;
    cout<<"--- INGRESE EL NRO DE ID DE GENERO A BUSCAR PARA ELIMINAR --- O 0 (Cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
    cout<<"--- ";cin>>ID;

    int auxi;
    auxi=BuscarIDgenero(ID); /// -2 SI NO ENCONTRO EL ARCHIVO Y -1 SI ENCONTRO EL DNI   2 Si se puede agregar
    while(auxi>0){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- --- EL NUMERO DE ID DE GENERO INGRESADO,NO SE ENCUENTRA EN LOS REGISTROS --- ---"<<endl;
        cout<<"--- --- POR FAVOR INGRESE EL DNI NUEVAMENTE O 0(cero) PARA SALIR --- ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>ID;
        auxi=BuscarIDgenero(ID);///ESTO ES SOLO PARA CHECKEAR SI EXISTE O NO
    }

    if(auxi==-1){   ///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE

        int pos=buscarPosicionGenero(ID);


        FILE *pGENE;
        pGENE = fopen("Genero.dat", "rb+");
        fseek(pGENE, sizeof obj * pos, 0);
        fread(&obj,sizeof (Genero),1,pGENE);
        fclose(pGENE);

        bool esta2=obj.getEstado();
        if(esta2){ /// si el estado es true entonces cargamos fecha nueva, SINO  ESTA DADO DE BAJA Y NO TE DEJA
         //   int pos=buscarPosicionGenero(ID);  ///BUSCO LA POSICION A TRAVES DEL DNI --- POS DE MAS!!
         //   obj=DevolverGeneroLeido(pos);   /// LO LEO Y LO TRAIGO
            obj.setEstado(false); /// LE MODIFICO LA FECHA

            bool escribio=modificarRegistroGenero(obj,pos);

            if(escribio){cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- ---EL ARCHIVO SE DIO DE BAJA CORRECTAMENTE --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                return;}
            else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- --- HUBO UN ERROR EN LA ELIMINACION LOGICA DEL ARCHIVO --- ---"<<endl;
                cout<<"--- --- --- --- INTENTE NUEVAMENTE MAS TARDE --- --- --- --- ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            return;}
        }/// IF ESTADO
        else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            cout<<"--- --- EL REGISTRO YA SE ENCUENTRA DADO DE BAJA --- ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}
    }///IF AUXI  -1 ARCHIVO EXISTE   -2 ERROR    2 EL ARCHIVO NO EXISTE

}

bool Genero::modificarRegistroGenero(Genero obj, int pos){
    FILE *pGENE;
    pGENE = fopen("Genero.dat", "rb+");
    fseek(pGENE, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pGENE);
    fclose(pGENE);
    return aux;
}

int Genero::VerificarAnio(int anio){
    Fecha Actual;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    Actual.setAnio(1900+tmPtr->tm_year);
  ///  cout<<"ANIOACTUAL:"<<Actual.getAnio()<<endl;
   /// system("pause");
    while(anio>Actual.getAnio()|| anio<1500){
        cout<<"--- HA INGRESADO UN NRO DE ANIO DE ORIGEN INVALIDO ---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL NRO DE ANIO DE ORIGEN(1500 - "<<Actual.getAnio()<<") ---"<<endl;
        cin>>anio;
    }
    return anio;
}

int Genero::autonumericoIDgenero(){
    Genero obj;
    int pos=0;
    int c=0;
    while(obj.leerEnDisco(pos++)==1){
            c++;
        if (pos>100){
            cout <<"SE HA ALCANZADO EL LIMITE DE REGISTROS(100)"<<endl;
            return 0;}
    }
    return c+1;
}


int Genero::leerEnDisco(int pos){
    FILE *p;
    p=fopen("Genero.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(Genero)*pos,0);
    int leyo=fread(this,sizeof(Genero),1,p);
    fclose(p);
    return leyo;

}

bool Genero::recuGenero(){
    int pos=0;
    FILE *br;
    br=fopen("Genero.dat","wb");
    if(br==NULL){
        return false;}

    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(Genero),1,br);
        pos++;}

    fclose(br);
    if(pos==0){
        return false;}

    return true;
}

int Genero::LeerDeDiscobkp(int pos){
    FILE *A;
    A=fopen("Genero.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;}

    fseek(A,sizeof(Genero)*pos,0);
    int leyo=fread(this,sizeof(Genero),1,A);
    fclose(A);

    return leyo;
}

bool Genero::backupGenero(){
    int pos=0;
    FILE *b;
    b=fopen("Genero.bkp","wb");
    if(b==NULL){
        return false;}

    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(Genero),1,b);
        pos++;}

    fclose(b);
    if(pos==0){
        return false;}

    return true;
}

#endif // CLASEGENEROS_H_INCLUDED
