#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED


void MenuReportes(){

bool a=false;
int opc;
do{
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------> MENU REPORTES <-------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"--- --- --- 1.  --- --- ---"<<endl;
    cout<<"--- --- --- 2.  --- --- ---"<<endl;
    cout<<"--- --- --- 3.  --- --- ---"<<endl;
    cout<<"--- --- ---    --- --- --- "<<endl;
    cout<<"--- --- --- --- --- --- --- ---"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<" --- --- --- 0. VOLVER AL MENU PRINCIPAL--- --- --- --- ---  ---"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"           --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
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
