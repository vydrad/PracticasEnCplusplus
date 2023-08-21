#ifndef FUNCIONESGENEROS_H_INCLUDED
#define FUNCIONESGENEROS_H_INCLUDED


int buscarNumeroIDgenero(int id);
bool buscarEstado3(int id);

class genero {
private:
int IDgenero;
char Nombregenero[40];
int Nacionalidadgenero; ///entre 1 y 100
int Tipoinstrumentacion;///entre 1 y 5
bool Estado3=false;

public:
    void setIDgenero(int i){IDgenero=i;} /// EL INTERPRETE SE REPITE EN LA PRIMERA CLASE

    void setNombregenero(const char *n){strcpy(Nombregenero,n);}
    void setNacionalidadgenero(int g){Nacionalidadgenero=g;}
    void setTipoinstrumentacion(int i){Tipoinstrumentacion=i;}
    void setEstado3(bool e){Estado3=e;} /// EL ESTADO DEBE SER VERDADERO PARA QUE EL SISTEMA PUEDA UTILIZAR EL REGISTRO



    int getIDgenero(){return IDgenero;}
    const char *getNombregenero(){return Nombregenero;}
    int getNacionalidadgenero(){return Nacionalidadgenero;}
    int getTipoinstrumentacion(){return Tipoinstrumentacion;}
    bool getEstado3(){return Estado3;}

    void Cargar();
    void Mostrar();


bool leerDeDisco3(int pos){
    FILE *p;
    p=fopen("genero.txt", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (genero), 0);
    bool leyo=fread(this, sizeof (genero), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco3(){
    FILE *p;
    p=fopen("genero.txt", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (genero), 1, p);
    fclose(p);
    return escribio;
}

bool modificarEnDisco3(int pos){
    FILE *p;
    p=fopen("genero.txt", "rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (genero), 0);
    bool modifico=fwrite(this, sizeof (genero), 1, p);
    fclose(p);
    return modifico;}



};



    void genero::Cargar(){
 int aux,pos=0;




    cout<<" CARGAR ID DEL GENERO: " <<endl;
    cin>> aux;

        pos=buscarNumeroIDgenero(aux);

       bool est3=buscarEstado3(aux);
    if(est3==true){
    while(pos>=0){

        cout<<"EL ID DE GENERO INGRESADO YA EXISTE"<<endl;
        cout<<" POR FAVOR INGRESE OTRO ID: "<<endl;
        cin>>aux;
        pos=buscarNumeroIDgenero(aux);

        }}
        setIDgenero(aux);

    cout<<" CARGAR NOMBRE DEL GENERO:"<<endl;
    cargarCadena(Nombregenero,40);

    cout<<"CARGAR NACIONALIDAD: (1 a 100):"<<endl;

      cin>>aux;

        while(aux<1||aux>100){
        cout<<"INGRESE EL PAIS DE ORIGEN, DEL 1 y 100."<<endl;
        cout<<"CARGAR NACIONALIDAD: (1 a 100):"<<endl;
        cin>>aux;}

    setNacionalidadgenero(aux);

    cout<<" CARGAR TIPO DE INSTRUMENTACION: (1 a 5)"<<endl;

    cin>>aux;

        while(aux<1||aux>5){
        cout<<"HA INGRESO UN TIPO DE INSTRUMENTACION INVALIDO, INGRESE  NUEVAMENTE:"<<endl;

        cout<<"CARGAR TIPO DE INSTRUMENTACION: (1 a 5):"<<endl;
        cin>>aux;
    }

    setTipoinstrumentacion(aux);




    setEstado3(true);
    cout<<Estado3<<endl;
    system("pause");
    }


    void genero::Mostrar(){
        if (Estado3==true){
    cout<<"ID DE GENERO: " ;
    cout<< IDgenero<<endl;
    cout<<"NOMBRE:";
    cout<< Nombregenero<<endl;
    cout<<"PAIS DE ORIGEN : ";
    cout<< Nacionalidadgenero<<endl;
    cout<<"TIPO DE INSTRUMENTACION: ";
    cout<<Tipoinstrumentacion<<endl;
        }
    }

bool Agregargenero(){
    FILE *f;
    genero gen;
    int escribio, i;
    f=fopen("genero.txt","ab");
    if(f==NULL){ cout<<"Error de archivo";
    return false;}

    for (i=0;i<1;i++){
    gen.Cargar();
    escribio=fwrite(&gen, sizeof(genero),1,f);

    if (escribio==0){
        cout<< "NO SE ESCRIBIO NADA"<<endl;
        fclose(f);
        system("pause");
        return false;}
    }
    fclose(f);
    return true;
    }

int buscarNumeroIDgenero(int id){
    genero obj;
    int pos=0;
    while(obj.leerDeDisco3(pos)){
        if(obj.getIDgenero()==id){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool buscarEstado3(int id){
    genero obj;
    int pos=0;
    while(obj.leerDeDisco3(pos)){
        if(obj.getIDgenero()==id){
            return obj.getEstado3();
        }
        pos++;
    }
    return false;
}



/// Me va a leer la cantidad de registros existentes
bool Mostrargenero(){

    FILE *p;
    genero gen;
    p=fopen("genero.txt","rb");
    if(p==NULL){ cout<<"Error de archivo";
    system("pause");
    return false;}

    while(fread(&gen, sizeof(genero),1,p)==1){
    gen.Mostrar();
    cout<<endl;
    }

    fclose(p);
    system("pause");
    return true;
    }




void buscarYlistariDgenero(){
genero obj;
FILE *p;

p=fopen("genero.txt","rb");
if(p==NULL){
    cout<<"Error de archivo, (no encontrado)"<<endl;}
int aux,pos;
cout<<"INGRESE EL ID DE GENERO QUE QUIERE VER:"<<endl;
cin>>aux;
pos=buscarNumeroIDgenero(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDgenero(aux);
}
fseek(p,pos*sizeof(genero),0);
fread(&obj,sizeof (genero),1,p);
obj.Mostrar();

system("pause");
fclose(p);
}


bool ModificarIDinstrumentacion(){
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR CATEGORIA DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
genero obj;
int aux,pos;

cout<<"INGRESE EL ID DE INSTRUMENTACION QUE QUIERE EDITAR:"<<endl;
cin>>aux;
pos=buscarNumeroIDgenero(aux);
while(pos==-1){
cout<<"EL ID INGRESADO NO EXISTE"<<endl;
cout<<"POR FAVOR INGRESE  EL ID NUEVAMENTE"<<endl;
cin>>aux;
pos=buscarNumeroIDgenero(aux);
}
    obj.leerDeDisco3(pos);
    if(obj.getEstado3()==false){
        cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
        return false;}


cout<<"INGRESE EL NUEVO TIPO DE INSTRUMENTACION (1 a 5):"<<endl;
cin>>aux;

while(aux<1||aux>5){
    cout<<"HA INGRESADO UN NUMERO INVALIDO!! INGRESE NUEVAMENTE EL TIPO DE INSTRUMENTACION (1 a 5):"<<endl;
    cin>>aux;

}

obj.setTipoinstrumentacion(aux);

obj.Mostrar();
obj.modificarEnDisco3(pos);
system("pause");

}


#endif // FUNCIONESGENEROS_H_INCLUDED
