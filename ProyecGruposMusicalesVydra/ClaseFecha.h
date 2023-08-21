#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
    private:///sólo permite que sean accesibles dentro de la propia clase. Desde fuera no se van a poder manipular.
        int dia, mes, anio;///propiedades, atributos o variables de la clase
    public:///comportamiento. Se establece mediante el desarrollo de los métodos, que son las funciones de la clase
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar(){

            setDia2();
            setMes2();
            setAnio2();
        }
        void Mostrar();
        ///set: para asignar valores a cada propiedad
        void setDia(int x){
        dia=x;
        }
        void setDia2(){
            int x;
        cout<<"INGRESE EL DIA:"<<endl;
        cin>>x;
        while(x>31||x<=0){
        cout<<"HA INGRESADO UN NRO DE DIA INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL NRO DE DIA NUEVAMENTE(1-31)"<<endl;
        cin>>x;
        }
        dia=x;
        }

        void setMes(int x){
        mes=x;
        }

        void setMes2(){
            int x;
        cout<<"INGRESE EL MES:"<<endl;
        cin>>x;
        while(x>12||x<=0){
        cout<<"HA INGRESADO UN NRO DE MES INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL NRO DE MES NUEVAMENTE(ENTRE 1 Y 12)"<<endl;
        cin>>x;
        }
        mes=x;
        }

        void setAnio(int x){
        anio=x;
        }

        void setAnio2(){
        Fecha Actual;
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        Actual.setAnio(1900+tmPtr->tm_year);
            int anio2;
        cout<<"INGRESE EL ANIO:"<<endl;
        cin>>anio2;
        while(anio2>Actual.getAnio()|| anio2<1500){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- HA INGRESADO UN NRO DE ANIO DE ORIGEN INVALIDO ---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL NRO DE ANIO DE ORIGEN(1500 - "<<Actual.getAnio()<<") ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cin>>anio2;
        }
        anio=anio2;

        }
        ///get: para que el exterior se entere de los valores de cada propiedad
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
    /*    ~Fecha(){
            cout<<"SE MURIO EL OBJETO :-("<<endl;
        }*/


};


void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}



#endif // CLASEFECHA_H_INCLUDED
