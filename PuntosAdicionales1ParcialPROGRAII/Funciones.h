#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void MostrarVector(int *v,int tam);
void MostrarVector2(int *v,int tam);
void MostrarVector3(int *v,int tam);
void MostrarVector4(int *v,int tam);
void Punto1();
void Punto2();
void Punto3();
void Punto4();
void Punto5();
void Poneren0(int *v,int cant2);
void Punto6();

//a1) Para cada material la cantidad de compras que se hayan realizado entre todas las compras.
/// abri un archivo para resolverlo
void Punto1(){
ArchivoCompra archiCompra("compras.dat");
Compra comprita;

int pos=0;
int aux;
aux=archiCompra.contarRegistros();
int VecCODIGOmaterialesCompras[30]={0};
for(int i=0;i<aux;i++){
comprita=archiCompra.leerRegistro(i);
VecCODIGOmaterialesCompras[comprita.getCodigoMaterial()-1]+=comprita.getCantidad();
comprita.Mostrar();
}

MostrarVector(VecCODIGOmaterialesCompras,30);
}
void MostrarVector(int *v,int tam){
for(int i=0;i<tam;i++){
    if(v[i]!=0){
    cout<<"EL MATERIAL NRO "<<(i+1)<<" TIENE "<<v[i]<<" CANTIDAD DE COMPRAS"<<endl;
    }
}

}

//a2) El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron.
/// en este nomas abri 2 archivos para resolverlo
void Punto2(){
ArchivoCompra archiCompra("compras.dat");
Compra comprita;
int cant;
cant=archiCompra.contarRegistros();
float importemax, aux;
int posmax;
for(int i=0;i<cant;i++){
    comprita=archiCompra.leerRegistro(i);
    if(i==0){importemax=comprita.getImporte();
                posmax=i;}

    aux=comprita.getImporte();
    if(aux>importemax){
        importemax=aux;
        posmax=i;
    }
  ///  cout<<"--------------"<<endl;
   ///     cout<<"IMPORTE:"<<importemax<<endl;

}

///cout<<"--------------"<<endl;
 comprita=archiCompra.leerRegistro(posmax);
cout<<"LA COMPRA MAS CARA LA HIZO EL PROVEEDOR "<<comprita.getNumeroproveedor()<<endl;

int numprov=comprita.getNumeroproveedor();
ArchivoProveedor archiProvee("proveedores.dat");
Proveedor provee;
///int cant;
cant=archiProvee.contarRegistros();

for(int a=0;a<cant;a++){
    provee=archiProvee.leerRegistro(a);
    ///provee.Mostrar();
    if(provee.getNumeroProveedor()==numprov){
        cout<<"EL NOMBRE DEL PROVEEDOR ES: "<<provee.getNombre()<<endl;
    }

}

}

//a3) Los numero de los proveedores a los que no se les compro nada el año pasado."
//abri un archivo para resolverlo
void Punto3(){
ArchivoCompra archiCompra("compras.dat");
Compra compraa;

int cant2=archiCompra.contarRegistros();
int VecProveedores[6]={0}; /// ACTUALMENTE HAY 6 PROVEEDORES EN EL ARCHIVO
for(int a=0;a<cant2; a++){
    compraa=archiCompra.leerRegistro(a);
    ///cout<<"COMPRAAAAS"<<endl;
    compraa.Mostrar();
    if(compraa.getFechaCompra().getAnio()==2022){
    VecProveedores[compraa.getNumeroproveedor()-1]++; ///cuento si compro x vez
    }
}

MostrarVector2(VecProveedores,6);

}

void MostrarVector2(int *v, int tam){

for(int i=0;i<tam;i++){
    if(v[i]==0){
    cout<<"EL PROVEEDOR:"<<(i+1)<<" TUVO:"<<v[i]<<" (CERO) COMPRAS EN EL ANIO 2022"<<endl;

    }
}

}

//a4) El gasto en obra gruesa para cada uno de las obras.
//(analizar bien. Es el punto mas complejo porque requiere del uso de 3 archivos)
void Punto4(){


ArchivoObras archiObra("obras.dat");
Obra obrita;
int cant2=archiObra.contarRegistros();
int *VecImporteObragruesaxObras;
VecImporteObragruesaxObras=new int[cant2]; ///CON VECTOR DINAMICO XDXDJAJA
if(VecImporteObragruesaxObras==NULL){
 cout<<"Error de asignación de memoria"<<endl;
 system("pause");
 return;
}
Poneren0(VecImporteObragruesaxObras,cant2);
for(int e=0;e<cant2;e++){
    obrita=archiObra.leerRegistro(e);
    ///cout<<"---"<<endl;
    ///obrita.Mostrar();
    obrita.getCodigoObra();///OBTENGO EL CODIGO DE LA OBRA PARA COMPARAR CON EL ARCHIVO COMPRAS

    ArchivoCompra archiCompra("compras.dat");
    Compra comprita;

    int cant=archiCompra.contarRegistros();
  ///  int VecCodMaterial[6]={0};
    for(int i=0;i<cant;i++){
        comprita=archiCompra.leerRegistro(i);

        if(strcmp(comprita.getCodigoObra(),obrita.getCodigoObra())==0 ){
            comprita.getCodigoMaterial(); ///OBTENGO EL MATERIAL desde cOMPRAS


            ArchivoMaterial archimate("materiales.dat");
            Material mate;

            int cant1=archimate.contarRegistros();
            int CodigoMat;
            for(int a=0;a<cant1;a++){
                    mate=archimate.leerRegistro(a);
                if(comprita.getCodigoMaterial()==mate.getCodigoMaterial()&& mate.getTipo()==1){

                   int gasto=comprita.getImporte();
                    ///    cout<<"COMPRAAAAS"<<endl;
                   /// comprita.Mostrar();
                   VecImporteObragruesaxObras[e]+=gasto;
                   }
            }


        } /// TENGO EL CODIGO DE MATERIAL PERO TENGO QUE CHECKEAR QUE SEA DEL TIPO 1 == OBRA GRUESA

}

    //obrita.Mostrar();

}

MostrarVector4(VecImporteObragruesaxObras,cant2);
/*
//----------PARA VER LOS REGISTROS DE COMPRAS --------------------------
ArchivoCompra archiCompra("compras.dat");
Compra comprita;

int cant=archiCompra.contarRegistros();
int VecCodMaterial[]={0};
for(int i=0;i<cant;i++){
comprita=archiCompra.leerRegistro(i);
comprita.Mostrar();

}
//----------PARA VER LOS REGISTROS DE MATERIALES---------------------
ArchivoMaterial archimate("materiales.dat");
Material mate;

int cant1=archimate.contarRegistros();
int CodigoMat;
for(int a=0;a<cant1;a++){
  mate=archimate.leerRegistro(a);
  cout<<"MATERIAAAAAAAAAAAAALES"<<endl;
    mate.Mostrar();
}
*/

delete VecImporteObragruesaxObras;

}

void Poneren0(int *v, int cant2){
    for(int i=0;i<cant2;i++){
    v[i]=0;}
    ///MostrarVector4(v,cant2);
}

void MostrarVector4(int *v, int tam){
    ArchivoObras archiobraa("obras.dat");
    Obra obrita;
for(int i=0;i<tam;i++){
    obrita=archiobraa.leerRegistro(i);
    cout<<"LA OBRA CODIGO: "<<obrita.getCodigoObra()<<" pos i:"<<i<<" IMPORTE TOTAL: "<<v[i]<<endl;

}
}
//5. a5) La/s provincia/s con mas de 22 proveedores

void Punto5(){
ArchivoProveedor archiProvee("proveedores.dat");
Proveedor provee;

int cant=archiProvee.contarRegistros();
int VecProv[24]={0};
for(int i=0;i<cant;i++){

  provee=archiProvee.leerRegistro(i);
    provee.Mostrar();
  VecProv[provee.getProvincia()-1]++;

}
MostrarVector3(VecProv,24);

}

void MostrarVector3(int *v,int tam){
int cont=0;
for(int i=0;i<tam;i++){

    if(v[i]>22){
    cout<<"LA PROVINCIA"<<(i+1)<<" TIENE MAS DE 22 PROVEEDORES"<< v[i]<<endl;
    cont++;}
    ///else{cout<<"LA PROVINCIA"<<(i+1)<<" TIENE MENOS DE 22 PROVEEDORES"<< v[i]<<endl;}
}

if(cont==0){
    cout<<"NO SE ENCONTRARON PROVINCIAS CON MAS DE 22 PROVEEDORES"<<endl;
}

}

void Punto6(){
ArchivoCompra archiCompra("compras.dat");
Compra comprita;

int cant=archiCompra.contarRegistros();
int import=0;
int nroprov=0;
for(int i=0;i<cant;i++){
    comprita=archiCompra.leerRegistro(i);
    ///comprita.getImporte();
    if(import<comprita.getImporte()){
    nroprov=comprita.getNumeroproveedor();
    import=comprita.getImporte();
    }

}

}
/*ArchivoCompra archiCompra("compras.dat");
Compra comprita;

int cant=archiCompra.contarRegistros();
for(int i=0;i<cant;i++){
  comprita=archiCompra.leerRegistro(i);

}*/


#endif // FUNCIONES_H_INCLUDED
