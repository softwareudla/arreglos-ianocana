/*Instrucciones para el Desarrollo del Programa:
El número de estudiantes será 5 y de asignaturas 3.
El programa debe ser capaz de realizar las siguientes tareas:
Calcular el promedio de calificaciones para cada estudiante. /
Calcular el promedio por asignatura.
Encontrar la calificación más alta y baja por estudiante/ y por asignatura.
Determinar cuántos estudiantes aprobaron o reprobaron cada asignatura. (Nota aprobatoria ≥ 6).
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
    float promedio=0;
    float calif[5][3];
    float maximo, minimo;
    int aprobados, reprobados;
    for (int i = 0; i < 5; i++)
    {
        printf ("\nIngrese las notas del estudiante %d \n", i+1);
        printf("---------------------------------------\n");

        for (int j = 0; j < 3; j++)
        {
            printf ("Ingrese la nota de la asignatura %d: ", j+1);
            scanf("%f", &calif[i][j]);
            if (calif[i][j]>10 || calif[i][j]<0)
            {
                printf ("La nota ingresada no es valida, vuelva a ingrasarla \n");
                j--;
            }  
        }
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {   promedio=0;
        for (int j = 0; j < 3; j++)
        {
            promedio= promedio + calif[i][j];
           
            if (j==0)
            {
                maximo=calif[i][j];
                minimo=calif[i][j];
                
            }
            else
            {
                 
                if (calif[i][j]>maximo){
                maximo=calif[i][j];
                }
                if (calif[i][j]<minimo){
                minimo=calif[i][j];
                } 
            }
            
        }
    
        promedio= promedio/3;
        printf ("El promedio del estudiante %d es %.2f \n", i+1, promedio);
        printf ("Nota maxima del es: %.2f \n", maximo);
        printf ("Nota minima del es: %.2f \n \n", minimo);

    }
    maximo = 0;
    minimo = 0;
    for (int j = 0; j < 3; j++)
    {   promedio=0;
        aprobados=0;
        reprobados=0;
        for (int i = 0; i < 5; i++)
        {
            promedio= promedio + calif[i][j];
           
            if (i==0)
            {
                maximo=calif[i][j];
                minimo=calif[i][j];
                
            }
            else
            {
                 
                if (calif[i][j]>maximo){
                maximo=calif[i][j];
                }
                if (calif[i][j]<minimo){
                minimo=calif[i][j];
                } 
            }

            if (calif[i][j]>=6)
            {
                aprobados=aprobados+1;
            }
            else 
            {
                reprobados=reprobados+1;
            }
            
        }
        promedio= promedio/5;
        printf ("El promedio de la asignatura %d es %.2f \n", j+1, promedio);
        printf ("Nota maxima de la asignatura es: %.2f \n", maximo);
        printf ("Nota minima de la asignatura es: %.2f \n", minimo);
        printf ("Aprobados de la asignatura: %d \n", aprobados);
        printf ("Reprobados de la asignatura: %d \n \n", reprobados);
    }
    return 0;
}