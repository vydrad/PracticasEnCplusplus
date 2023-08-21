///Ejercicio: Parcial 1 de Programaci�n II
///Autor:DEK
///Fecha:
///Comentario:

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Proyecto{
private:
    char codigoProyecto[5];
    char nombre[30];
    int ubicacion;
    char direccion[40];
    float presupuesto;
    int estadoDesarrollo;
    Fecha inicio;
    bool activo;
public:
    void Cargar(){
        cout<<"codproyecto5cad"<<endl;
        cargarCadena(codigoProyecto,4);
        cout<<"nombre"<<endl;
        cargarCadena(nombre,29);
        cout<<"direccion"<<endl;
        cargarCadena(direccion,39);
        cout<<"ubicacion"<<endl;
        cin>>ubicacion;
        cout<<"presu ff"<<endl;
        cin>>presupuesto;
        cout<<"estado desarrollo 1-5"<<endl;
        cin>>estadoDesarrollo;
        cout<<"fecha"<<endl;
        inicio.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<codigoProyecto<<endl;
        cout<<nombre<<endl;
        cout<<direccion<<endl;
        cout<<ubicacion<<endl;
        cout<<presupuesto<<endl;
        cout<<estadoDesarrollo<<endl;
        inicio.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }

    const char* getCodigoProyecto(){return codigoProyecto;}
    const char* getNombre(){return nombre;}
    const char* getDireccion(){return direccion;}
    int getUbicacion(){return ubicacion;}
    int getEstadoDesarrollo(){return estadoDesarrollo;}
    float getPresupuesto(){return presupuesto;}
    bool getActivo(){return activo;}
    Fecha getFechaInicio(){return inicio;}

    void setCodigoProyecto(const char *c){strcpy(codigoProyecto,c);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setEstadoDesarrollo(int e){estadoDesarrollo=e;}
    void setPresupuesto(float p){presupuesto = p;}
    void setActivo(bool a){activo=a;}
    void setFechaInicio(Fecha f){inicio=f;}
    void setUbicacion(int u){ubicacion=u;}


    bool grabarEnDisco(){
    FILE *p;
    p=fopen("proyectos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Proyecto), 1, p);
    fclose(p);
    return escribio;
    }

};

class ArchivoProyecto{
private:
    char nombre[30];
public:
    ArchivoProyecto(const char *n){
        strcpy(nombre, n);
    }
    Proyecto leerRegistro(int pos){
        Proyecto reg;
        reg.setUbicacion(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Proyecto)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Proyecto);
    }


};




class Componente{
private:
    int codigo;
    char nombre[30];
    char marca[30];
    int tipo;
    int origen;
    float pu;
    Fecha fechaUltimaCompra;
    bool activo;
public:
    void Cargar(){
        cin>>codigo;
        cargarCadena(nombre,29);
        cargarCadena(marca,29);
        cin>>tipo;
        cin>>origen;
        cin>>pu;
        fechaUltimaCompra.Cargar();
        activo=true;
    }
    void Mostrar(){
        cout<<codigo<<endl;
        cout<<nombre<<endl;
        cout<<marca<<endl;
        cout<<tipo<<endl;
        cout<<origen;
        cout<<pu<<endl;
        fechaUltimaCompra.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }
    int getCodigo(){return codigo;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    int getOrigen(){return origen;}
    float getPU(){return pu;}
    Fecha getFecha(){return fechaUltimaCompra;}

    bool getActivo(){return activo;}

    void setCodigo(int cm){codigo=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setOrigen(int o){origen=o;}
    void setFechaUltimaCompra(Fecha f){fechaUltimaCompra = f;}
    void setActivo(bool a){activo=a;}
};


class ArchivoComponente{
private:
    char nombre[30];
public:
    ArchivoComponente(const char *n){
        strcpy(nombre, n);
    }
    Componente leerRegistro(int pos){
        Componente reg;
        reg.setCodigo(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Componente);
    }
};


class Tarea{
private:
    int codigo, numeroEmpleado, codigoComponente;
    char nombre[30];
    char codigoProyecto[5];
    int categoria, tiempo;
    Fecha fechaTarea;
    int lugarRealizacion;
    bool activo;
public:
    void Cargar(){

        cout<<"int codigo"<<endl;
        cin>>codigo;
        cout<<"int nro Empleado"<<endl;
        cin>>numeroEmpleado;
        cout<<"int codigo Componente"<<endl;
        cin>>codigoComponente;
        cout<<"cad nombre"<<endl;
        cargarCadena(nombre,29);
        cout<<"int codigoproyecto"<<endl;
        cin>>codigoProyecto;
        cout<<"int categoria"<<endl;
        cin>>categoria;
        cout<<"int tiempo"<<endl;
        cin>>tiempo;
        cout<<"fecha"<<endl;
        fechaTarea.Cargar();
        cout<<"int lugar realizacion"<<endl;
        cin>>lugarRealizacion;
        activo=true;
    }

    void Mostrar(){
        cout<<codigo<<endl;
        cout<<numeroEmpleado<<endl;
        cout<<codigoComponente<<endl;
        cout<<nombre<<endl;
        cout<<codigoProyecto<<endl;
        cout<<categoria<<endl;
        cout<<tiempo<<endl;
        fechaTarea.Mostrar();
        cout<<lugarRealizacion;
        cout<<endl;
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }
    int getCodigo(){return codigo;}
    int getNumeroEmpleado(){return numeroEmpleado;}
    int getCodigoComponente(){return codigoComponente;}
    const char *getNombre(){return nombre;}
    const char *getCodigoProyecto(){return codigoProyecto;}
    int getCategoria(){return categoria;}
    int getTiempo(){return tiempo;}
    Fecha getFechaTarea(){return fechaTarea;}
    bool getActivo(){return activo;}
    int getLugarRealizacion(){return lugarRealizacion;}

    void setCodigo(int c){codigo=c;}
    void setNumeroEmpleado(int n){ numeroEmpleado=n;}
    void setCodigoComponente(int c){codigoComponente=c;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setCodigoProyecto(const char *c){ strcpy(codigoProyecto, c);}
    void setCategoria(int c){categoria = c;}
    void setTiempo(int t){tiempo = t;}
    void setFechaTarea(Fecha f){fechaTarea = f;}
    void setActivo(bool a){activo = a;}
    void setLugarRealizacion(int l){lugarRealizacion = l;}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("tareas.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Tarea), 1, p);
    fclose(p);
    return escribio;
    }


};


class ArchivoTarea{
private:
    char nombre[30];
public:
    ArchivoTarea(const char *n){
        strcpy(nombre, n);
    }
    Tarea leerRegistro(int pos){
        Tarea reg;
        reg.setCodigoComponente(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Tarea);
    }
};

class Empleado{
private:
    int numero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    int cargo;
    bool activo;
public:
    void Cargar(){
        cin>>numero;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cin>>provincia;
        cin>>cargo;
        activo=true;
    }
    void Mostrar(){
        cout<<numero<<endl;
        cout<<nombre<<endl;
        cout<<telefono<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
        cout<<cargo;
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }

    int getNumero(){return numero;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    int getcargo(){return cargo;}
    bool getActivo(){return activo;}

    void setNumero(int n){numero=n;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}
    void setCargo(int c){cargo=c;}
};

class ArchivoEmpleado{
private:
    char nombre[30];
public:
    ArchivoEmpleado(const char *n){
        strcpy(nombre, n);
    }
    Empleado leerRegistro(int pos){
        Empleado reg;
        reg.setNumero(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Empleado);
    }
};
