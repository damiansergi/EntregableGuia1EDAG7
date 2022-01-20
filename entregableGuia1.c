
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef int (*pCallback) (char *, char*, void *);

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData);

int parseCallback(char *key, char *value, void *userData);  //Funcion callback que llama parseCmdLine

int main (int argc, char * argv []){

    int cantidadeAnalizados;

    cantidadeAnalizados = parseCmdLine(argc, argv, parseCallback, NULL);

    if (cantidadeAnalizados == -1){

        printf("Hubo errores en la lectura de opciones y parametros\n");
    }
    else{

        printf("Se analizo una combinacion de %d opciones y parametros\n", cantidadeAnalizados);
    }

    return 0;

}

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData){

    int salida;
    int error = 0;
    int conteo = 0;
    int i = 1;

    while (i<argc && error == 0){

        if (argv[i][0] == '-'){

            if ( (i + 1) >= argc){

                error = 1; //En este caso estarias poniendo una clave sin valor
            }
            else{

                if ( p(argv[i], argv[i+1], NULL) == 0 ){

                    error = 1;
                }
                else{
                    i++;
                    conteo++;
                }
            }
        }
        else{

            if ( p(NULL, argv[i], NULL) == 0){

                error = 1;
            }
            else{

                ++conteo;
            }
        }

        i++;
    }

    if (error == 0){

        salida = conteo;
    }
    else{

        salida = -1;
    }

    return salida;
}

int parseCallback(char *key, char *value, void *userData){

    int esCorrecto = 1;

    if (key == NULL){

        if (!strcmp(value, "-d")){

            //Algo con userdata
        }
        else if (!strcmp(value, "-g")) {

            //Algo con userdata
        }
        else{

            //Algo con userdata
        }
    }
    else {
        if (!strcmp(key, "-max_clients")) {

            if (!strcmp(value, "3")) {

                //Algo con userdata
            } else if (!strcmp(value, "4")) {

                //Algo con userdata
            } else if (!strcmp(value, "5")) {

                //Algo con userdata
            } else {

                esCorrecto = 0;
            }
        } else if (!strcmp(key, "-hand")) {

            if (!strcmp(value, "right")) {

                //Algo con userdata
            } else if (!strcmp(value, "left")) {

                //Algo con userdata
            } else {

                esCorrecto = 0;
            }
        } else if (!strcmp(key, "-o")) {
            if (!strcmp(value, "damian")) {

                //Algo con userdata
            } else {

                //Algo con userdata
            }
        } else {

            esCorrecto = 0;
        }
    }

    return esCorrecto;
}
