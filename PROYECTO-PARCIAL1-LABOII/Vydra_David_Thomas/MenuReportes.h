#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED


void MenuReportes(){

bool a=false;
int opc;
do{
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------> MENU REPORTES <----------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--- 1. LISTAR LOS MUSICOS QUE TOCAN LA GUITARRA (INSTRUMENTO 1) --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
    cout<<"--- SE DEBEN MOSTRAR 'SOLO' LAS SIGUIENTE PROPIEDADES DE CADA REGISTRO: DNI, NOMBRE, APELLIDO Y TELEFONO. --- --- ---"<<endl;
    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
    cout<<"--- 2. INFORMAR EL INSTRUMENTO PRINCIPAL CON MAS MUSICOS DEL CLAUSTRO 'DOCENTE'(CLAUSTRO 1). --- --- --- --- --- ---"<<endl;
    cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
    cout<<"--- 3. GENERAR UN ARCHIVO DE NOMBRE 'instrumentos.dat' CON LOS MUSICOS QUE >NO< TOCAN EL PIANO (INSTRUMENTO 3) ---"<<endl;
    cout<<"--- CADA REGISTRO DEBE TENER EL SIGUIENTE FORMATO: DNI, NOMBRE, APELLIDO Y TIPO DE MUSICA. --- --- --- --- --- --- "<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<" --- --- --- --- --- --- --- --- --- --- 0. VOLVER AL MENU PRINCIPAL --- --- --- --- --- --- --- --- --- --- --- --"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                 --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"---> ";cin>>opc;
    system("cls");
    switch (opc){
        case 1:
            Punto1();
            break;
        case 2:
            Punto2();
            break;
        case 3:
            Punto3();
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


#endif // MENUREPORTES_H_INCLUDED
