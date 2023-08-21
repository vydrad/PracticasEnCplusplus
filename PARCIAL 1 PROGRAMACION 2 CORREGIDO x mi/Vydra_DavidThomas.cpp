
# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

#include "clasesp1.h"
void PuntoA();
void PuntoB();
int buscarMinimo(int *v, int tam);
void MostrarVector(int *v,int tam);
int buscarMinimoMenos0(int *v, int tam);
///void PuntoA(int tam);///para pasarle tam
int main(){
    int tam=8;
    Multa obj;
    Infraccion obj1;
    Inspector obj2;
    int pos1=0,pos2=0;
  ///  cout<<"------------------------"<<endl;

  /* while(obj1.leerDeDisco(pos2++)==1){
        obj1.Mostrar();
    }*/
    cout<<"------------------------"<<endl;
   /// PuntoA();

	cout<<endl;
/*	    while(obj.leerDeDisco(pos1++)==1){
        obj.Mostrar();
    }*/

    PuntoB();

     while(obj2.leerDeDiscoGRO(pos1++)==1){
        obj2.Mostrar();
    }


	return 0;
}

///Calcular e informar la categoría con menos multas (códigos.
/// de multa no infracciones), sin tener en cuenta las categorías que no tienen multas

void PuntoA(){
Infraccion infrac;

int tam=8;/// 8 CATEGORIAS DE MULTAS     Para sacar LOS Codigos de las INFRACCIONES Y A QUE CATEGORIA PERTENECEN
int pos=0;
int vCodMul[8]={0};

Multa multa;
int vCatMulta[8]={0};
int pos1=0;

///INFRACCIONES INDIVIDUALES
/// CONTAR CANTIDAD DE INFRACCIONES DEPENDIENDO EL CODIGO DE MULTA Y GUARDARLAS EN VECTOR
while(infrac.leerDeDisco(pos++)){  ///GUARDO TODOS LOS VALORES EN EL VECTOR --- ESTO SE TENIA QUE HACER CON CLASE INFRACCIONES
    vCodMul[infrac.getCodigoMulta()-1]++;/// ES DECIR comparar el CodigoDeMulta DE la clase Infracciones
                                    /// Y VER A QUE CATEGORIA PERTENECEN ESOS CODIGOS DE MULTA EN LA CLASE MULTA
}
MostrarVector(vCodMul,tam);

///INFRACCIONES A CATEGORIAS DE MULTAS
/// GUARDAR LA CANTIDAD TOTAL DE CODIGOS DE MULTAS, QUE PERTENECEN A SU CATEGORIA = posicion dentro del vector
int i=0;
while (multa.leerDeDisco(pos1++)==1){
    if (vCodMul[i]!=0){
          ///  cout<<"vcodmult["<<i<<"]"<<" "<<vCodMul[i]<<endl;
        ///cout<<multa.getCategoria()<<endl;
        vCatMulta[multa.getCategoria()-1]+=vCodMul[i];///EN UN VECTOR  FILTRADO POR CATEGORIA, GUARDAMOS CUANTAS INFRACCIONES Q TUVO CADA CATEGORIA
    }
    i++;
}
cout<<"----------------"<<endl;
MostrarVector(vCatMulta,tam);

int posminima=buscarMinimoMenos0(vCatMulta,tam); ///Sin contar las posiciones = 0

cout<<"LA CATEGORIA CON MENOS MULTAS ES :"<<posminima+1<<" CON :"<<vCatMulta[posminima]<<endl;
multa.leerDeDisco(posminima);
multa.Mostrar();

cout<<"FIN PUNTO A"<<endl;
system("pause");

}


/// BUSCA EL VALOR MINIMO EN UN VECTOR INT Y TAM  IGNORANDO LOS VALORES EN 0
///PARA ESTO PRIMERO LEEMOS EL ARCHIVO Y SACAMOS LOS VALORES EN UN VEC DEL MISMO TAMAÑO
int buscarMinimoMenos0(int *v, int tam){
    	int primervalor=-1;
    for (int e=0;e<tam;e++){
		if (primervalor==-1){
            if(v[e]!=0){
			primervalor=e;/// EL PRIMER VALOR SE ENCUENTRA EN LA POSICION "e"
			///cout<<"PRIMERVALOR:"<<primervalor<<endl;
            }
		}
	}
	///cout<<"PRIMERVALOR:"<<primervalor<<endl;
    int posmin=0;
	for (int i=0;i<tam;i++){
		if(v[i]!=0){
            if(v[i]<v[primervalor]){
			posmin=i;
			cout<<"posmin:"<<posmin<<endl;
            }
		}
	}
	return posmin;
}



/*
int buscarMinimo(int *v, int tam){
	int posmin=0;
	for (int i=1;i<tam;i++)
	{
		if(v[i]<v[posmin])
		{
			posmin=i;
		}
	}
	return posmin;
}*/

void MostrarVector(int *v,int tam){

for(int i=0;i<tam;i++){
            cout<<"EL VECTOR EN LA POSICION I+1="<<(i+1)<<" VALE: "<<v[i]<<endl;

}

}


///Crear un archivo con las infracciones realizadas por el inspector
///Ismael Groh en el año 2021. El archivo debe tener el mismo formato que el archivo de infracciones.
void PuntoB(){

int pos=0,pos1=0;
    Inspector inspec;
    Infraccion infracc;

    char Nom[30]= "Ismael";
    char Ape[30]= "GROH";
    strlwr(Nom);
    strlwr(Ape);
    char Nom2[30];
    char Ape2[30];

    while(inspec.leerDeDisco(pos++)==1){
        strcpy(Nom2,inspec.getNombre());
        strcpy(Ape2,inspec.getApellido());
        strlwr(Nom2);
        strlwr(Ape2);
        if (strcmp(Nom,Nom2)==0 && strcmp(Ape,Ape2)==0){
            if(inspec.getFechaIngreso().getAnio()==2021){

            ///inspec.Mostrar();
            inspec.grabarEnDiscoGRO();


            }
           /// else {cout<<" EL INSPECTOR NO TIENE REGISTROS DE ESE ANIO"<<endl;}
        }
     ///  else {cout<<"NO SE ENCONTRARON REGISTROS DE ESE INSPECTOR"<<endl;}
    }



 system("pause");
}
