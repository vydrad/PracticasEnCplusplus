#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void Punto1();
void Punto2();
void Punto3();
void Punto4();
void CopiarInter(interprete *vi, int cant);
void mostrarinter(interprete *vi, int cant);
int ContarArchivodeInterpretes();
int ContartiposdeInterpretes(int tipoI);
void submenureportes(){

    int opc6;

 cout<<"----MENU REPORTES----"<<endl;
 cout<<"-RECUPERO EL PRIMERO-"<<endl;
 cout<<"---------------------"<<endl;

 cout<<"1) Generar un archivo con la cantidad de interpretes del genero musical 1 por cada tipo de interprete (cada tipo del archivo de tipos de interpretes). Cada registro debe tener el siguiente formato:"<<endl;
 cout<<"2) Informar el/los genero/s con 2 interpretes como minimo."<<endl;
 cout<<"3)Dado un anioo que se ingresa por teclado, informar cantidad de canciones estrenadas ese año."<<endl;
 cout<< "4)Cargar y mostrar el archivo de Interpretes usando un vector dinamico"<<endl;
 cout<<"--------------------------------"<<endl;
 cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
 cout<<"************************************"<<endl;
 cout<<"OPCION:";

 cin>>opc6;

 switch(opc6){

    case 1:

        Punto1();

        break;

    case 2:
        Punto2();

        break;

    case 3:
        Punto3();
        break;

    case 4: Punto4();
        break;
    case 0: return;
        break;
 }
}



class Interpretetipo1{
private:
    int IDinterprete;
    char Nombreinterpret[40];
    int CantInterpretes;

public:

    void setIDinterprete(int i){IDinterprete=i;}
    void setNombreInterpreteEsp(const char *n) {strcpy(Nombreinterpret,n);}
    void setCantInterpretes(int c){CantInterpretes=c;}


    void Mostrar(){
    cout<<"EL ID INTERPRETE ES: "<<IDinterprete<<endl;
    cout<<"EL NOMBRE DE INTERPRETE ES: "<<Nombreinterpret<<endl;
    cout<<"LA CANTIDAD DE INTERPRETES ES: "<<CantInterpretes<<endl;
    cout<<endl<<endl;

    }

    bool grabarEnDisco4(){
    FILE *p;
    p=fopen("Interpretestipo1.txt", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (Interpretetipo1), 1, p);
    fclose(p);
    return escribio;}

    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("Interpretestipo1.txt", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Interpretetipo1), 0);
    bool leyo=fread(this, sizeof (Interpretetipo1), 1, p);
    fclose(p);
    return leyo;
}


};


void Punto1(){
interprete obj;
Interpretetipo1 obj2;
int pos=0,pos2=0;
int cant;
while(obj.leerDeDisco2(pos++)){

    if(obj.getGeneromusical2()==1&&obj.getEstado2()==true){

        cant=ContartiposdeInterpretes(obj.getTipointerprete());


        obj2.setIDinterprete(obj.getIDinterprete2());
        obj2.setNombreInterpreteEsp(obj.getNombrebanda());
        obj2.setCantInterpretes(cant);
        obj2.grabarEnDisco4();
    }
}

while(obj2.leerDeDisco(pos2++)){
    obj2.Mostrar();

}

system("pause");
}

int ContartiposdeInterpretes(int tipoI){
    interprete obj;
 int pos=0, cant=0;
    while(obj.leerDeDisco2(pos++)){
        if(obj.getGeneromusical2()==1&&obj.getTipointerprete()==tipoI&& obj.getEstado2()==true){
        cant++;
        }

}
 return cant;
}



void Punto2(){
interprete obj;
int pos=0;
int cont=0;
///for(int i=0;i<10;i++){
while(obj.leerDeDisco2(pos++)){

       for(int i=0;i<10;i++){
    if (obj.getGeneromusical2()==i+1){
        cont++;

    }

    }
    cout<<"Cont :"<<cont<<endl;
    ///if(cont>=2){
    cout<<"EL GENERO: "<<obj.getGeneromusical2()<<" POSEE 2 O MAS REGISTROS"<<endl;
    ///}
    cont=0;
    ///pos=0;
}

    system("pause");
}




void Punto3(){
 Canciones obj;

 int pos=0,anio;
 int contadorcan=0;
cout<<"POR FAVOR INGRESE UN AÑO DE ESTRENO:"<<endl;
cin>>anio;

while(obj.leerDeDisco(pos++)){
    if(obj.getFechaestreno().getAnio()==anio){
        contadorcan++;
    }
}

cout<<"PARA EL ANIO: "<<anio<<" SE CONTARON "<<contadorcan<<" CANCIONES"<<endl;

system("pause");
}

void Punto4(){
interprete obj;
int pos=0, cant=0;
interprete *VecInter;

    cant=ContarArchivodeInterpretes();
    VecInter=new interprete[cant];
    if(VecInter==NULL)return;
    CopiarInter(VecInter,cant);
    mostrarinter(VecInter,cant);

    delete[]VecInter;///falta destructor
    system("pause");
}

int ContarArchivodeInterpretes(){
    interprete obj;
 int pos=0, cant=0;
    while(obj.leerDeDisco2(pos++)){

        cant++;


}
 return cant;
}

void CopiarInter(interprete *vi, int cant)
{
    interprete aux;
    for(int i=0;i<cant;i++)
    {
        aux.leerDeDisco2(i);
            vi[i]=aux;
    }
    }


void mostrarinter(interprete *vi, int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        vi[i].Mostrar();
        cout<<endl;
    }
}


#endif // REPORTES_H_INCLUDED
