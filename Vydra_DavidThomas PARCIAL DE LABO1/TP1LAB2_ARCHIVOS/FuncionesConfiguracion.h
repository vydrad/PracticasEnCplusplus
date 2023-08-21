#ifndef FUNCIONESCONFIGURACION_H_INCLUDED
#define FUNCIONESCONFIGURACION_H_INCLUDED


bool CopiarCanciones(){

    FILE *txt,*bkp;
    Canciones obj;
    int pos=0;

    txt=fopen("canciones.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    fclose(txt);

    bkp=fopen("canciones.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    pos=0;

    while(obj.leerDeDisco(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}

bool CopiarInterpretes(){

    FILE *txt,*bkp;
    interprete obj;
    int pos=0;

    txt=fopen("interpretes.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco2(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    fclose(txt);

    bkp=fopen("interpretes.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco2(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    pos=0;

    while(obj.leerDeDisco2(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}


bool CopiarGeneros(){

    FILE *txt,*bkp;
    genero obj;
    int pos=0;

    txt=fopen("genero.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco3(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    fclose(txt);

    bkp=fopen("genero.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco3(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    pos=0;

    while(obj.leerDeDisco3(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}

bool RestaurarCanciones(){

    FILE *bkp,*txt;
    Canciones obj;
    int pos=0;

    bkp=fopen("canciones.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    pos=0;

    txt=fopen("canciones.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    fclose(txt);

    while(obj.leerDeDisco(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}

bool RestaurarInterpretes(){

    FILE *bkp,*txt;
    interprete obj;
    int pos=0;

    bkp=fopen("interpretes.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco2(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    pos=0;

    txt=fopen("interpretes.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco2(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    fclose(txt);

    while(obj.leerDeDisco2(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}


bool RestaurarGeneros(){

    FILE *bkp,*txt;
    genero obj;
    int pos=0;

    bkp=fopen("genero.bkp","w");

    if(bkp==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco3(pos++)){

    fread(&obj, sizeof obj, 1, txt);

    }

    pos=0;

    txt=fopen("genero.txt","r");

    if(txt==NULL){

        cout<<"Error de archivo";

        system("pause");

    return false;
    }

    while(obj.leerDeDisco3(pos++)){

    fwrite(&obj, sizeof obj, 1, bkp);

    }

    fclose(txt);

    while(obj.leerDeDisco3(pos++)){

        obj.Mostrar();
    }

    system("pause");

    return true;
}


bool DatosInicio(){

    FILE *xlsx,*c,*i,*g;
    Canciones can;
    interprete inter;
    genero gen;
    int pos=0;
    string id="id";

        xlsx=fopen("Datos iniciales 2C 2022.xlsx","r");

    if(xlsx==NULL){

            cout<<"Error de archivo Planilla!";

            system("pause");

        return false;
        }

        //canciones

        while(fread(&can, sizeof can, 1, xlsx)==1){

        fread(&can, sizeof can, 1, xlsx);

        }

        pos=0;

        c=fopen("canciones.txt","ab");

        if(c==NULL){

            cout<<"Error de archivo";

            system("pause");

        return false;
        }

        while(can.leerDeDisco(pos++)){

        fwrite(&can, sizeof can, 1, c);

        }

        fclose(c);

        //interpretes

        while(fread(&inter, sizeof inter, 1, xlsx)==1){

        fread(&inter, sizeof inter, 1, xlsx);

        }

        pos=0;

        i=fopen("interpretes.txt","ab");

        if(i==NULL){

            cout<<"Error de archivo";

            system("pause");

        return false;
        }

        while(inter.leerDeDisco2(pos++)){

        fwrite(&inter, sizeof inter, 1, i);

        }

        fclose(i);

        //generos

        while(fread(&gen, sizeof gen, 1, xlsx)==1){

        fread(&gen, sizeof gen, 1, xlsx);

        }

        pos=0;

        g=fopen("genero.txt","ab");

        if(g==NULL){

            cout<<"Error de archivo";

            system("pause");

        return false;
        }

        while(gen.leerDeDisco3(pos++)){

        fwrite(&gen, sizeof gen, 1, g);

        }

        fclose(g);


        while(can.leerDeDisco(pos++)){

            can.Mostrar();
        }

        while(inter.leerDeDisco2(pos++)){

            inter.Mostrar();
        }

        while(gen.leerDeDisco3(pos++)){

            gen.Mostrar();
        }

        system("pause");

        return true;
}

#endif // FUNCIONESCONFIGURACION_H_INCLUDED
