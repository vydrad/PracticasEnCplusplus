#ifndef MENUMUSICOS_H_INCLUDED
#define MENUMUSICOS_H_INCLUDED


/*La opción AGREGAR deberá permitir ingresar de a un registro por vez.
La opción LISTAR POR DNI deberá solicitar el DNI y listar todos los campos del registro si éste existe, o informar si no existe.
La opción LISTAR TODOS LOS MUSICOS deberá listar todos los registros.
La opción MODIFICAR FECHA deberá pedir un DNI de músico y una fecha y cambiar la fecha de inscripción del músico con ese DNI.
La opción ELIMINAR deberá solicitar el DNI y realizar la baja lógica.*/

void MenuMusicos()
{

Musico obj;
bool a=false;
int opc;
do{
    cout<<"---------------------------------------------------------------- "<<endl;
    cout<<"-----------------------> MENU MUSICOS <------------------------- "<<endl;
    cout<<"---------------------------------------------------------------- "<<endl;
    cout<<" --- --- --- 1. AGREGAR MUSICOS --- --- --- --- --- --- --- "<<endl;
    cout<<" --- --- --- 2. LISTAR MUSICO POR DNI --- --- --- --- ---"<<endl;
    cout<<" --- --- --- 3. LISTAR TODOS LOS MUSICOS --- --- --- --- "<<endl;
    cout<<" --- --- --- 4. MODIFICAR FECHA DE INSCRIPCION --- --- --- "<<endl;
    cout<<" --- --- --- 5. ELIMINAR REGISTRO DE MUSICO --- --- --- --- "<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
    cout<<" --- --- --- 0. VOLVER AL MENU PRINCIPAL--- --- --- --- --- --- "<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
    cout<<"           --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
    cout<<"--------------------------------------------------------------- "<<endl;
    cout<<"---> ";cin>>opc;
    system("cls");
    switch (opc){
        case 1:
            obj.CargarArchivosMusicos();
            break;
        case 2:
            obj.ListarSoloDNI();
            break;
        case 3:
            obj.MostrarArchivosMusicos();
            break;
        case 4:
            obj.ModificarFechaConDNI();
            break;
        case 5:
            obj.EliminarRegistroLogicoM();
            break;
        case 0:
            return;
            break;
        default:cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
                cout<<"--- USTED HA INGRESADO UNA OPCION INVALIDA, VUELVA A INTENTARLO ---"<<endl;
                cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
            break;

    }

    system("pause");
 system("cls");
 }while(a==false);


}


#endif // MENUMUSICOS_H_INCLUDED
