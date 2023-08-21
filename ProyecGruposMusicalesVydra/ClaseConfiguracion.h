#ifndef CLASECONFIGURACION_H_INCLUDED
#define CLASECONFIGURACION_H_INCLUDED


int DatosInicio(){

    Genero obj;
    FILE *p,*pNuevo;
    p=fopen("GeneroINICIAL.dat","rb");
    pNuevo=fopen("Genero.dat", "wb");
    if(p==NULL){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- NO ABRIERON LOS DATOS DE GENEROS INICIALES ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        return 0;}
    if(pNuevo==NULL){
        cout<<"--- --- --- --- --- --- --- --- --- --- "<<endl;
        cout<<"--- NO ABRIO EL ARCHIVO DE GENEROS ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- "<<endl;
        return 0;}
    while(fread(&obj,sizeof obj,1,p)==1){///COPIA EN EL OBJETO EL CONTENIDO .DAT DE INICIO
        if(obj.getEstado()==true){
            fwrite(&obj, sizeof obj,1, pNuevo);///LOS ESCRIBE EN EL .dat DE DESTINO DE LA CLASE
        }
    }
    fclose(p);
    fclose(pNuevo);


    Musico reg;
    FILE *q,*pNuevo1;
    q=fopen("MusicoINICIAL.dat","rb");
    pNuevo1=fopen("Musico.dat", "wb");
    if(q==NULL){
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- NO ABRIERON LOS DATOS DE MUSICOS INICIALES ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        return 0;}
    if(pNuevo1==NULL){
        cout<<"--- --- --- --- --- --- --- --- --- ---"<<endl;
        cout<<"--- NO ABRIERON LOS DATOS DE MUSICOS ---"<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- ---"<<endl;
        return 0;}

    while(fread(&reg,sizeof reg,1,q)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg,1, pNuevo1);
        }
    }

    fclose(q);
    fclose(pNuevo1);

    return 1;
}


#endif // CLASECONFIGURACION_H_INCLUDED
