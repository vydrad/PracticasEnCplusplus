#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED


/*La opción AGREGAR deberá permitir ingresar de a un registro por vez.
La opción LISTAR POR ID deberá solicitar el ID y listar todos los campos del registro si éste existe, o informar si no existe.
La opción LISTAR TODOS deberá listar todos los registros.
La opción MODIFICAR AÑO DE ORIGEN deberá pedir un ID y un AÑO y cambiar el año de origen del género con ese ID.
La opción ELIMINAR deberá solicitar el ID y realizar la baja lógica.
*/
void MenuGeneros()
{

Genero obj;
bool a=false;
int opc;
 do{
 cout<<"---------------------------------------------------------------- "<<endl;
 cout<<"-----------------------> MENU GENEROS <------------------------- "<<endl;
 cout<<"---------------------------------------------------------------- "<<endl;
 cout<<" --- --- --- 1. AGREGAR GENERO --- --- --- --- --- --- --- "<<endl;
 cout<<" --- --- --- 2. LISTAR GENERO POR ID --- --- --- --- ---"<<endl;
 cout<<" --- --- --- 3. LISTAR TODO--- --- --- --- "<<endl;
 cout<<" --- --- --- 4. MODIFICAR ANIO DE ORIGEN--- --- --- "<<endl;
 cout<<" --- --- --- 5. ELIMINAR REGISTRO --- --- --- --- "<<endl;
 cout<<"--------------------------------------------------------------- "<<endl;
 cout<<" --- --- --- 0. VOLVER AL MENU PRINCIPAL--- --- --- --- --- --- "<<endl;
 cout<<"--------------------------------------------------------------- "<<endl;
 cout<<"           --- --- --- ELIJA UNA OPCION --- --- ---"<<endl;
 cout<<"--------------------------------------------------------------- "<<endl;
 cout<<"---> ";cin>>opc;
system("cls");
 switch (opc){
    case 1:
        obj.CargarArchivosGeneros();
        break;
    case 2:
        obj.ListarSoloID();
        break;
    case 3:
        obj.MostrarArchivosGeneros();
        break;
    case 4:
        obj.ModificarFechaConIDgenero();
        break;
    case 5:
        obj.EliminarRegistroLogicoG();
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

#endif // MENUGENEROS_H_INCLUDED
