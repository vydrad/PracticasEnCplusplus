

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
        cout<<"DIA ";cin>>dia;
        cout<<"MES ";cin>>mes;
        cout<<"ANIO ";cin>>anio;
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





class Multa{
    private:
        int codigo;
        int categoria;
        char descripcion[40];
        float importe;
        bool estado;
    public:
        int getCodigo(){return codigo;}
        int getCategoria(){return categoria;}
        const char *getDescripcion(){return descripcion;}
        float getImporte(){return importe;}
        bool getEstado(){return estado;}

        void Cargar(){
            cout<<"CODIGO: ";cin>>codigo;
            cout<<"CATEGORIA: ";cin>>categoria;
            cout<<"DESCRIPCION: ";cargarCadena(descripcion,39);
            cout<<"IMPORTE: ";cin>>importe;
            estado=true;
        }
        void Mostrar(){
            cout<<"CODIGO: "<<codigo<<endl;
            cout<<"CATEGORIA: "<<categoria<<endl;
            cout<<"DESCRIPCION: "<<descripcion<<endl;
            cout<<"IMPORTE: "<<importe<<endl;
            cout<<endl;
        }

        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("multas.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
        }


    int grabarEnDisco(){
        FILE *p;
        p=fopen("multas.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }
};

class Infraccion{
    private:
        int numero;
        int legajoInspector;
        int codigoMulta;
        int localidad;
        Fecha fechaMulta;
        bool estado;
    public:
        int getNumero(){return numero;}
        int getLegajoInspector(){return legajoInspector;}
        int getCodigoMulta(){return codigoMulta;}
        int getLocalidad(){return localidad;}
        Fecha getFechaMulta(){return fechaMulta;}

        void setLegajoInspector(int a){legajoInspector=a;}

        void Cargar(){
            cout<<"NUMERO: ";cin>>numero;
            cout<<"LEGAJO: ";cin>>legajoInspector;
            cout<<"CODIGO: ";cin>>codigoMulta;
            cout<<"LOCALIDAD: ";cin>>localidad;
            cout<<"FECHA: "<<endl;fechaMulta.Cargar();
        }
        void Mostrar(){
            cout<<"NUMERO: "<<numero<<endl;
            cout<<"LEGAJO: "<<legajoInspector<<endl;
            cout<<"CODIGO: "<<codigoMulta<<endl;
            cout<<"LOCALIDAD: "<<localidad<<endl;
            fechaMulta.Mostrar();
            cout<<"--------------"<<endl;
        }


        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("infracciones.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
        }

        int grabarEnDisco(){
            FILE *p;
            p=fopen("infracciones.dat", "ab");
            if(p==NULL) return -1;
            int grabo=fwrite(this, sizeof *this,1, p);
            fclose(p);
            return grabo;
        }
};



class Inspector{
private:
        int legajo;
        char nombre[30];
        char apellido[30];
        char email[40];
        char telefono[20];
        Fecha fechaIngreso;
        int cargo;
        bool activo;
public:
    void Cargar(){
        cout<<"LEGAJO ";cin>>legajo;
        cout<<"NOMBRE ";cargarCadena(nombre,29);
        cout<<"APELLIDO ";cargarCadena(apellido,29);
        cout<<"EMAIL ";cargarCadena(email,29);
        cout<<"TELEFONO ";cargarCadena(telefono,29);
        fechaIngreso.Cargar();
        cout<<"CARGO ";cin>>cargo;
        activo=true;
    }
    void Mostrar(){
        cout<<"LEGAJO: "<<legajo<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"EMAIL: "<<email<<endl;
        cout<<"TELEFONO: "<<telefono<<endl;
        fechaIngreso.Mostrar();
        cout<<"CARGO: "<<cargo<<endl;
        cout<<"-----------------"<<endl;
    }

    int getLegajo(){return legajo;}
    int getCargo(){return cargo;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    bool getActivo(){return activo;}
    Fecha getFechaIngreso(){return fechaIngreso;}

    void setlegajo(int np){legajo=np;}

    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("inspectores.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("inspectores.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

        int grabarEnDiscoGRO(){
        FILE *p;
        p=fopen("inspectorGRO.dat", "wb");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

        int leerDeDiscoGRO(int pos){
        FILE *p;
        p=fopen("inspectorGRO.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

};





