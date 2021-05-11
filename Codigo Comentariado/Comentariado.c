#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<ctype.h>

//REALIZAMOS EL PROTOTIPADO DE LAS FUNCIONES A USAR.
void Validar_nombre(char a[],int t);
void Validar_identificacion(char b[], int c);
float Porcentajes(float numero1, float acumulador);

int main()
{
//DECLARAMOS VARIABLES A USAR DE MANERA REPETITIVA.
int opc;
int cantidad;
int i;

//VARIABLES PARA EL PORCENTAJE Y CANTIDAD DE ESTUDIANTES.
float contador_primaria =0,contador_media =0,contador_superior =0, acumulador=0;
float porc_primaria, porc_media, porc_superior;

//DECLARAMOS ARREGLOS PARA GUARDAR DATOS DE LOS DIFERENTES ESTUDIANTES.
//ARRAY PARA GUARDAR NOMBRES
typedef char nombre[50];
nombre arrayNombres[50];

//ARRAY PARA GUARDAR NIVELES ACADEMICO.
typedef int nivel[20];
nivel arrayNivel[20];

//RRAY PARA GUARDAR  IDENTIFICACION.
typedef int identificacion[20];
identificacion arrayidenti[20];

//INICIALIZAMOS UN CLICO PARA MOSTRAR EL MENU.
do{

    //MOSTRAMOS LAS OPCIONES DE MENU
    printf("\n*******************************************");
    printf("\n*                                         *");
    printf("\n*   \t    COLEGIO UBUNTU            \t  *");
    printf("\n*                                         *");
    printf("\n*\t1. Registro de estudiantes        *");
    printf("\n*\t2. Lista de estudiantes           *");
    printf("\n*\t3. Promedio de estudiantes        *");
    printf("\n*\t4. Salir                          *");
    printf("\n*                                         *");
    printf("\n*******************************************");
    printf("\n Opcion: ");
    scanf("%d", &opc);

    switch(opc){
        //EL CASO 1 NOS LLEVARA A DECIR CUANTOS ESTUDIANTES VAMOS A EVALUAR.
        case 1:
            printf("\n-Digite la cantidad de alumnos: ");
            scanf("%i", &cantidad);
            system("cls");
            arrayNombres[cantidad];
            arrayNivel[cantidad];
            arrayidenti[cantidad];
        //INICIALIZAMOS UN CICLO FOR PARA PEDIR LOS DATOS RESPECTIVOS A LA CANTIDAD DE ESTUDIANTES INGRESADOS ANTERIORMENTE.

            for (i=0; i<cantidad; i++)
                {
                    //PROPIEDAD PARA LIMPIAR EL ESPACIO DE MEMORIA EN CADA CICLO.
                    fflush(stdin);

                    //PEDIMOS EL NOMBRE DEL ESTUDIANTE Y LO GUARDAMOS EN UN ARRAY.
                    printf("\n\tAlumno[%i] - Digite su nombre: Ej.Santiago Mendez Arellano \n\nNombre: " , i+1);
                    gets(arrayNombres[i]);

                    //HACEMOS LLAMADA DE LA FUNCION Validar_nombre PARA QUE VERIFIQUE QUE SON SOLO LETRAS.
                    Validar_nombre(arrayNombres[i],i);

                    //PEDIMOS EL GRADO ACADEMICO INGRESANDO EL NUMERO 1, 2 O 3. Y LO GUARDAMOS EN UN ARRAY.
                    printf("\n\tAlumno[%i] - Digite su Grado Academico: Ej.1\n" , i+1);
                    printf("\n 1 -- Primaria\n 2 -- Basica Media \n 3 -- Basica Superior: \n\nNivel: ");
                    gets(arrayNivel[i]);

                    //PEDIMOS LA IDENTIFICACION DEL ESTUDIANTE Y LA GUARDAMOS EN UN ARRAY.
                    printf("\n\tAlumno[%i] - Digite su identificacion: Ej.1000395742\n\n Identificacion: ", i+1);
                    gets(arrayidenti[i]);

                    //HACEMOS LLAMADA DE LA FUNCION Validar_identificacion PARA QUE VERIFIQUE QUE SON SOLO NUMEROS.
                    Validar_identificacion(arrayidenti,i);

                    //PROPIEDAD PARA LIMPIAR LA CONSOLA.
                    system("cls");
                }
         break;

        case 2:
            //PROPIEDAD PARA LIMPIAR LA CONSOLA.
            system("cls");
            //EN EL CASO 2 MOSTRAMOS UNA LISTA DE LOS ESTUDIANTES REGISTRADOS.
            printf("\n\t\t\tLISTA DE ALUMNOS\t\t\n\n");
            printf("Numero          Nombres                          Grado Academico        Identificacion\n");
            /*INICIALIZAMOS UN CICLO FOR PARA RECORRER LOS 3 ARRAYS
            DONDE TEMOS GUARDADA LA INFORMACION DE LOS ESTUDIANTES Y IMPRIMIRLA EN PANTALLA*/
            int i;
            for (i=0; i<cantidad; i++){

                fflush(stdin);

                //CREAMOS 3 VARIABLES PARA DETERMINAR EL GRADO ACADEMICO DEL ESTUDIANTES
                char *comparar ="1",*comparar2 ="2",*comparar3 ="3";

                //LA PROPIEDAD strcmp NOS PERMITE COMPARAR 2 CHARS Y SABER SI SON IGUALES
                //EN ESTE PRIMER IF DETERMINAMOS SI PERTENECA AL GRADE DE PRIMARIA
                if(strcmp(comparar,arrayNivel[i])==0){

                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i+1, arrayNombres[i]," Primaria ",arrayidenti[i]);
                    //LLEVAMOS UN CONTADOR PARA SABER LA CANTIDAD TOTAL DE ESTUDIANTES EN PRIMARIA
                    contador_primaria++;
                    //USAMOS UN ACUMULADOR PARA SABER LA CANTIDAD DE ESTUDIANTES EN TOTAL
                    acumulador+= 1;
                }
                //DE IGUAL MANERA HACEMOS LO ANTERIOR PERO CON BASICA MEDIA
                else if(strcmp(comparar2,arrayNivel[i])==0){
                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i+1, arrayNombres[i]," Basica Media ",arrayidenti[i]);
                    contador_media++;
                    acumulador+= 1;
                }
                //DE IGUAL MANERA HACEMOS LO ANTERIOR PERO CON BASICA SUPERIOR
                else if(strcmp(comparar3,arrayNivel[i])==0){
                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i+1, arrayNombres[i]," Basica Superior ",arrayidenti[i]);
                    contador_superior++;
                    acumulador+= 1;
                }
                //EN CASO DE NO HABER INGRESADO ALGUNO DE LOS VALORES 1,2 P 3, ESTE MARCARA DATOS INCORRECTOS EN LA TABLA DE ESTUDIANTES
                else{
                    printf("\n Grado Academico Invalido, este debe ser 1,2 o 3.");
                };
            };
                        printf("\n\n\n");
        break;

        //EN EL CASO NUMERO 3 HACEMOS CONTEO DE LOS ESTUDIANTES EN TOTAL Y LOS IMPRIMIMO JUNTO A SUS PORCENTAJES
        case 3:
            //INICILIZAMOS LOS CONTADORES DE ESTUDIANTES PARA CONTARLOS Y PREVENIR ERRORES
            contador_primaria = 0;
            contador_media =0;
            contador_superior =0;
            acumulador=0;
            //RECORREMOS UN FOR PARA SABER EL GRADO ACADEMICO DE LOS ESTUDIANTES
            for (i=0; i<cantidad; i++){
                fflush(stdin);
                char *comparar ="1",*comparar2 ="2",*comparar3 ="3";
                if(strcmp(comparar,arrayNivel[i])==0){
                    contador_primaria++;
                    acumulador+= 1;
                }
                else if(strcmp(comparar2,arrayNivel[i])==0){
                    contador_media++;
                    acumulador+= 1;
                }
                else if(strcmp(comparar3,arrayNivel[i])==0){
                    contador_superior++;
                    acumulador+= 1;
                }
                else{
                    printf("\n Grado Academico Invalido, este debe ser 1,2 o 3.");
                };
            };
            printf("\n\n\n");

            //PROPIEDAD PARA LIMPIAR LA CONSOLA.
            system("cls");
            //HACEMOS 3 LLAMADAS A LA FUNCION PORCENTAJES, PARA SABER EL PORCENTAJE DE CADA NIVEL ACADEMICO
            porc_primaria = Porcentajes(contador_primaria,acumulador);
            porc_media = Porcentajes(contador_media, acumulador);
            porc_superior = Porcentajes(contador_superior, acumulador);

            //HACEMOS LA IMPRICECION DE LA CANTUDAD TOTAL DE ESTUDIANTES JUSTO CON SUS PROCENTAJES REFERENTES AL TOTAL
            printf("\n\t-------NUMERO DE ESTUDIANTES-------\n");
            printf("\n.Total estudiantes: %.0f% \n.Primaria: %.0f% \n.Basica Media: %.0f% \n.Basica Superior: %0.f%\n",acumulador,contador_primaria,contador_media,contador_superior);
            printf("\n\t-------PORCENTAJE DE ESTUDIANTES-------\n");
            printf("\n.Primaria: %.0f%% \n.Basica Media %.0f%% \n.Basica Superior: %0.f%%",porc_primaria,porc_media,porc_superior);
            printf("\n\n\n");

        break;

        //DE NO HABER ENTRADO A NINGUN CASO MENCIONADO DARA ERROR Y VOLVERA A MOSTRAR EL MENI
        default:
            printf("\n\t Opcion Erronea\n\n");
        break;
    }

//SI ESCOJE LA OPCION 4 ESTE SE SALDRA DEL PROGRAMA
}while(opc !=4 );
    return 0;
}

/*DEFINICIOMOS LA INSTRUCCIONES DE LA FUNCION VALIDAR NOMBRE,
DONDE SOLO SE ACEPTAN CARACTERES ALFABETICOS GRACIAS A AL ATRIBUTO isalpha*/
void Validar_nombre(char a[],int t){
  if(!(isalpha(a[t]))){
    printf("\n El nombre ha sido ingresado con valores incorrectos, recuerda que solo se aceptan LETRAS.");
    exit(-1);
    };
};

/*DEFINICIOMOS LA INSTRUCCIONES DE LA FUNCION VALIDAR IDENTIFICACION,
DONDE SOLO SE ACEPTAN CARACTERES NUMERICOS GRACIAS A AL ATRIBUTO isdigit*/
void Validar_identificacion(char b[], int c){
  if(!(isdigit(b[c]))){
    printf("\n La identificacion ha sida ingresada erroneamente, solo se aceptan numeros.");
    exit(-1);
    };
}

/*DEIFINIMOS LA FUNCION RECURSIVA, DONDE NOS AYUDARA A SACAR EL PORCENTAJE
  DE LOS ESTUDIANTES DEPENDIENDO SU VALOR ACADEMICO*/
float Porcentajes(float numero1, float acumulador){
    float porcentaje=0;
    porcentaje = (numero1/acumulador)*100;
    return porcentaje;
}
