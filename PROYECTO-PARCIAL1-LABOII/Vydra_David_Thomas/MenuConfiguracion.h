#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED



void MenuConfiguracion(){
Genero gen;
Musico music;
bool a=false;
int opc;
do{
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"-----------------------> MENU CONFIGURACION <---------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<" --- --- --- 1. COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS --- --- "<<endl;
    cout<<" --- --- --- 2. COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS --- --- "<<endl;
    cout<<" --- --- --- 3. RESTAURAR EL ARCHIVO DE MUSICOS --- --- --- --- "<<endl;
    cout<<" --- --- --- 4. RESTAURAR EL ARCHIVO DE GENEROS --- --- --- --- "<<endl;
    cout<<" --- --- --- 5. ESTABLECER DATOS DE INICIO --- --- --- --- ---"<<endl;
    cout<<"------------------------------------------------------------------ "<<endl;
    cout<<" --- --- --- 0. VOLVER AL MENU PRINCIPAL --- --- --- --- --- --- "<<endl;
    cout<<"------------------------------------------------------------------ "<<endl;
    cout<<"             --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
    cout<<"------------------------------------------------------------------ "<<endl;
    cout<<"---> ";cin>>opc;

    system("cls");
    switch (opc){
        case 1:if(music.backupMusico()){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- LA COPIA DE SEGURIDAD DE MUSICOS HA SIDO REALIZADA ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                }
                else{
                    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
                    cout<<"--- LA COPIA DE SEGURIDAD DE MUSICOS HA FALLADO, INTENTE NUEVAMENTE ---"<<endl;
                    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
                    }


            break;
        case 2:if(gen.backupGenero()){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- LA COPIA DE SEGURIDAD DE GENEROS HA SIDO REALIZADA EXITOSAMENTE---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                }
                else{   cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                        cout<<"--- LA COPIA DE SEGURIDAD DE GENEROS HA FALLADO, INTENTE NUEVAMENTE ---"<<endl;
                        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}

            break;
        case 3:if(music.recuMusico()){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- RESTAURAR LOS DATOS DESDE LA COPIA DE SEGURIDAD DE MUSICOS FINALIZO EXITOSAMENTE ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                }
                else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                    cout<<"--- RESTAURAR LOS DATOS DESDE LA COPIA DE SEGURIDAD DE MUSICOS FALLO, INTENTE NUEVAMENTE ---"<<endl;
                   cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}

            break;
        case 4:if(gen.recuGenero()){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- RESTAURAR LOS DATOS DESDE LA ULTIMA LA COPIA DE SEGURIDAD DE GENEROS FINALIZO EXITOSAMENTE ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                }
                else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                    cout<<"--- RESTAURAR LOS DATOS DESDE LA ULTIMA LA COPIA DE SEGURIDAD DE GENEROS FINALIZO EXITOSAMENTE ---"<<endl;
                    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}
            break;
        case 5:if(DatosInicio()){
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- LA RESTAURACION DE ARCHIVOS CON DATOS INICIALES DE MUSICOS Y GENEROS FINALIZO EXITOSAMENTE ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                }
                else{cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                   cout<<"--- LA RESTAURACION DE ARCHIVOS CON DATOS INICIALES DE MUSICOS Y GENEROS FALLO, INTENTE NUEVAMENTE ---"<<endl;
                    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;}

            break;
        case 0:
            return;
            break;
        default: cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- USTED HA INGRESADO UNA OPCION INVALIDA, VUELVA A INTENTARLO ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            break;
 }
 system("pause");
 system("cls");
 }while(a==false);


}

#endif // MENUCONFIGURACION_H_INCLUDED
