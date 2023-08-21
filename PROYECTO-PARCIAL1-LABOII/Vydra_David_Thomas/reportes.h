#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void Punto1();
void Punto2();
void Punto3();
void MostrarVector(int *v,int tam);

/*
    Alumno: David Thomas Vydra
    Legajo: 26191
*/
//------------------------------------ FUNCIONES PARA RESOLVER LOS PUNTOS DEL EXAMEN ---------------------------------------------------------

//                                          PUNTO 1:
//Listar los músicos que tocan guitarra (instrumento principal 1).
//Se deben mostrar las siguientes propiedades de cada registro:
//DNI, nombre, apellido y teléfono
void Punto1(){
Musico musicos;

int pos=0;
    cout<<"LOS MUSICOS QUE TOCAN LA GUITARRA SON: "<<endl;
    cout<<"--- --- --- --- --- --- ---"<<endl;
while(musicos.leerEnDisco(pos++)==1){
    if(musicos.getInstrumento()==1){
    cout<<"DNI: "<<musicos.getDNI()<<endl;
    cout<<"NOMBRE: "<<musicos.getNombre()<<endl;
    cout<<"APELLIDO: "<<musicos.getApellido()<<endl;
    cout<<"TELEFONO: "<<musicos.getTelefono()<<endl;
    cout<<"--- --- --- --- --- --- ---"<<endl;
    }

}

}

//                                          PUNTO 2:
//Informar el instrumento principal con más músicos del claustro de docentes
void Punto2(){
int VecInstrumento[15]={0};
Musico musicos;
int pos=0;
while(musicos.leerEnDisco(pos++)==1){
    if(musicos.getClaustro()==1){
        VecInstrumento[musicos.getInstrumento()-1]++;
    }

}
MostrarVector(VecInstrumento,15);
}

void MostrarVector(int *v, int tam){
int valormax=0, posmax=0;
valormax=v[0];
for(int i=1;i<tam;i++){
    if(v[i]>valormax){
        valormax=v[i];
        posmax=i;
    }
}
cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
cout<<"--- EL INSTRUMENTO CON MAS MUSICOS DEL CLAUSTRO DOCENTE ES EL INSTRUMENTO: "<<(posmax+1)<<" Y TIENE: "<<valormax<<" MUSICOS ---"<<endl;
cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
}


//                                          PUNTO 3:
class Instrumento{
private:
    int DNI;
    char Nombre[30];
    char Apellido[30];
    int TipodeMusica;

public:
    void setDNI(int id){DNI=id;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setApellido(const char *a){strcpy(Apellido,a);}
    void setTipodeMusica(int t){TipodeMusica=t;}

    int getDNI(){return DNI;}
    const char* getNombre(){return Nombre;}
     const char* getApellido(){return Apellido;}
    int getTipodeMusica(){return TipodeMusica;}

    void Mostrar(){
        cout<<"DNI: "<<DNI<<endl;
        cout<<"NOMBRE: "<<Nombre<<endl;
        cout<<"APELLIDO: "<<Apellido<<endl;
        cout<<"TIPO DE MUSICA: "<<TipodeMusica<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- "<<endl;
    }

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("instrumentos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Instrumento), 1, p);
    fclose(p);
    return escribio;
    }

    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("instrumentos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Instrumento), 0);
    bool leyo = fread(this, sizeof (Instrumento), 1, p);
    fclose(p);
    return leyo;
}

};

//Generar un archivo de nombre instrumentos.dat con los músicos que no tocan piano (instrumento principal 3).
//Cada registro debe tener el siguiente formato:
//DNI, nombre, apellido y tipo de música
void Punto3(){
Instrumento instru;
Musico musicos;
int pos=0,pos1=0;
bool grabo=false;
while(musicos.leerEnDisco(pos++)==1){
    if(musicos.getInstrumento()!=3){
        instru.setDNI(musicos.getDNI());
        instru.setNombre(musicos.getNombre());
        instru.setApellido(musicos.getApellido());
        instru.setTipodeMusica(musicos.getTipodeMusica());
        grabo=instru.grabarEnDisco();

    }

}
        if(grabo){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- SE HAN GENERADO LOS REGISTROS EXITOSAMENTE ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}
        else{  cout<<"--- --- --- --- --- --- ---  --- --- --- --- --- ---"<<endl;
                cout<<"--- ERROR, NO SE HAN PODIDO GENERAR LOS REGISTROS ---"<<endl;
                cout<<"--- --- --- --- --- --- ---  --- --- --- --- --- ---"<<endl;}
 /*  // Mostrar Registros
    while(instru.leerDeDisco(pos1++)==1){
        instru.Mostrar();
    }
*/

}



#endif // REPORTES_H_INCLUDED
