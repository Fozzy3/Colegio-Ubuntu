#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<ctype.h>

void Validar_nombre(char a[],int t);
void Validar_identificacion(char b[], int c);
float Porcentajes(float numero1, float acumulador);

int main()
{
int opc;
int cantidad;
int i;
float contador_primaria =0,contador_media =0,contador_superior =0, acumulador=0;
float porc_primaria, porc_media, porc_superior;
typedef char nombre[50];
nombre arrayNombres[50];
typedef int nivel[20];
nivel arrayNivel[20];
typedef int identificacion[20];
identificacion arrayidenti[20];

do{
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
        case 1:
            printf("\n-Digite la cantidad de alumnos: ");
            scanf("%i", &cantidad);
            system("cls");
            arrayNombres[cantidad];
            arrayNivel[cantidad];
            arrayidenti[cantidad];
            for (i=0; i<cantidad; i++){
                    fflush(stdin);
                    printf("\n\tAlumno[%i] - Digite su nombre: Ej.Santiago Mendez Arellano \n\nNombre: " , i+1);
                    gets(arrayNombres[i]);
                    Validar_nombre(arrayNombres[i],i);
                    printf("\n\tAlumno[%i] - Digite su Grado Academico: Ej.1\n" , i+1);
                    printf("\n 1 -- Primaria\n 2 -- Basica Media \n 3 -- Basica Superior: \n\nNivel: ");
                    gets(arrayNivel[i]);
                    printf("\n\tAlumno[%i] - Digite su identificacion: Ej.1000395742\n\n Identificacion: ", i+1);
                    gets(arrayidenti[i]);
                    Validar_identificacion(arrayidenti,i);
                    system("cls");}
        break;

        case 2:
            system("cls");
            printf("\n\t\t\tLISTA DE ALUMNOS\t\t\n\n");
            printf("Numero          Nombres                          Grado Academico        Identificacion\n");
            int i;
            for (i=0; i<cantidad; i++){
                fflush(stdin);
                char *comparar ="1",*comparar2 ="2",*comparar3 ="3";
                if(strcmp(comparar,arrayNivel[i])==0){
                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i, arrayNombres[i]," Primaria ",arrayidenti[i]);
                    contador_primaria++;
                    acumulador+= 1;
                }
                else if(strcmp(comparar2,arrayNivel[i])==0){
                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i, arrayNombres[i]," Basica Media ",arrayidenti[i]);
                    contador_media++;
                    acumulador+= 1;
                }
                else if(strcmp(comparar3,arrayNivel[i])==0){
                    printf("\n %-7d \t%-30s \t%-17s \t%-11s",i, arrayNombres[i]," Basica Superior ",arrayidenti[i]);
                    contador_superior++;
                    acumulador+= 1;
                }
                else{
                    printf("\n Grado Academico Invalido, este debe ser 1,2 o 3.");
                };
            };
                        printf("\n\n\n");
        break;

        case 3:
            contador_primaria = 0;
            contador_media =0;
            contador_superior =0;
            acumulador=0;
            for (i=0; i<cantidad; i++){
                fflush(stdin);
                char *comparar ="1",*comparar2 ="2",*comparar3 ="3";
                if(strcmp(comparar,arrayNivel[i])==0){
                    contador_primaria++;
                    acumulador+= 1;}
                else if(strcmp(comparar2,arrayNivel[i])==0){
                    contador_media++;
                    acumulador+= 1;}
                else if(strcmp(comparar3,arrayNivel[i])==0){
                    contador_superior++;
                    acumulador+= 1;}
                else{
                    printf("\n Grado Academico Invalido, este debe ser 1,2 o 3.");};  };
            printf("\n\n\n");
            system("cls");
            porc_primaria = Porcentajes(contador_primaria,acumulador);
            porc_media = Porcentajes(contador_media, acumulador);
            porc_superior = Porcentajes(contador_superior, acumulador);
            printf("\n\t-------NUMERO DE ESTUDIANTES-------\n");
            printf("\n.Total estudiantes: %.0f% \n.Primaria: %.0f% \n.Basica Media: %.0f% \n.Basica Superior: %0.f%\n",acumulador,contador_primaria,contador_media,contador_superior);
            printf("\n\t-------PORCENTAJE DE ESTUDIANTES-------\n");
            printf("\n.Primaria: %.0f%% \n.Basica Media %.0f%% \n.Basica Superior: %0.f%%",porc_primaria,porc_media,porc_superior);
            printf("\n\n\n");
        break;

        default:
            system("cls");
            printf("\n\t Opcion Erronea\n\n");
        break; };

 }while(opc !=4 );
    return 0; }

void Validar_nombre(char a[],int t){
  if(!(isalpha(a[t]))){
    printf("\n El nombre ha sido ingresado con valores incorrectos, recuerda que solo se aceptan LETRAS.");
    exit(-1); };
};

void Validar_identificacion(char b[], int c){
  if(!(isdigit(b[c]))){
    printf("\n La identificacion ha sida ingresada erroneamente, solo se aceptan numeros.");
    exit(-1); };
}

float Porcentajes(float numero1, float acumulador){
    float porcentaje=0;
    porcentaje = (numero1/acumulador)*100;
    return porcentaje;
}
