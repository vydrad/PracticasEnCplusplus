#ifndef CLASES_P2_H_INCLUDED
#define CLASES_P2_H_INCLUDED

class Pais{
    private:
        int id;
        char nombre[30];
        char continente[30];
        bool estado;
    public:

        int getId(){return id;}
        const char *getNombre(){return nombre;}
        const char *getContinente(){return continente;}
        bool getEstado(){return estado;}

        void setId(int i){id=i;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setContinente(const char *c){strcpy(continente, c);}
        void setEstado(bool e){estado=e;}

        void Cargar(int i){
            id=i;
            cargarCadena(nombre,29);
            cargarCadena(continente, 29);
            estado=true;
        }
        void grabarEnDisco(){
            FILE *p;
            p=fopen("paises.dat","ab");
            if(p==NULL) return;
            fwrite(this, sizeof *this, 1, p);
            fclose(p);
        }
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("paises.dat","rb");
            if(p==NULL) return false;
            fseek(p,sizeof *this * pos, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
        void Mostrar(){
            if(estado){
                cout<<"ID: "<<id<<endl;
                cout<<"NOMBRE: "<<nombre<<endl;
                cout<<"CONTINENTE: "<<continente<<endl;
            }
        }
};

class TipoInterprete{
    private:
        int id;
        char nombre[40];
        bool estado;
    public:

        int getId(){return id;}
        const char *getNombre(){return nombre;};
        bool getEstado(){return estado;}

        void setId(int i){id=i;}
        void setNombre(const char *n){strcpy(nombre,n);};
        void setEstado(bool e){estado=e;}

        void Cargar(int i){
            id=i;
            cargarCadena(nombre,39);
            estado=true;
        }
        void grabarEnDisco(){
            FILE *p;
            p=fopen("tipos.dat","ab");
            if(p==NULL) return;
            fwrite(this, sizeof *this, 1, p);
            fclose(p);
        }
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("tipos.dat","rb");
            if(p==NULL) return false;
            fseek(p,sizeof *this * pos, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
        void Mostrar(){
            if(estado){
                cout<<"ID: "<<id<<endl;
                cout<<"NOMBRE: "<<nombre<<endl;
            }
        }
};

#endif // CLASES_P2_H_INCLUDED
