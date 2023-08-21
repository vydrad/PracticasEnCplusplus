#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void Punto1();
void Punto2();
void Punto3();
void MostrarVector(int *v,int tam);

/*
class Musicos2023{
private:
    int IDdeMusico;
    char Nombre[30];
    int Claustro;

public:
    void setIDMusico(int id){IDdeMusico=id;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setClaustro(int cla){Claustro=cla;}

    int getIDMusico(){return IDdeMusico;}
    const char* getNombre(){return Nombre;}
    int getClaustro(){return Claustro;}

    void Mostrar(){
        cout<<"ID de Musico: "<<IDdeMusico<<endl;
        cout<<"NOMBRE: "<<Nombre<<endl;
        cout<<"CLAUSTRO: "<<Claustro<<endl;
        cout<<" --- --- --- --- --- --- --- --- --- --- "<<endl;
    }

    bool grabarEnDisco(){
    FILE *p;
    p=fopen("musicos2023.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Musicos2023), 1, p);
    fclose(p);
    return escribio;
    }

    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("musicos2023.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Musicos2023), 0);
    bool leyo = fread(this, sizeof (Musicos2023), 1, p);
    fclose(p);
    return leyo;
}

};
*/

//------------------------------------ FUNCIONES PARA RESOLVER LOS PUNTOS DEL EXAMEN ---------------------------------------------------------


void Punto1(){




}

void Punto2(){




}



void Punto3(){



}



#endif // REPORTES_H_INCLUDED
