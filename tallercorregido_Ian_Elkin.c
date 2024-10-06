/*Instrucciones para el Desarrollo del Programa:
El número de estudiantes será 5 y de asignaturas 3.
El programa debe ser capaz de realizar las siguientes tareas:
Calcular el promedio de calificaciones para cada estudiante. /
Calcular el promedio por asignatura.
Encontrar la calificación más alta y baja por estudiante/ y por asignatura.
Determinar cuántos estudiantes aprobaron o reprobaron cada asignatura. (Nota aprobatoria ≥ 6).
*/

#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) { 
    float promedio = 0;
    float calif[5][3]; 
    float maximo, minimo;
    int aprobados, reprobados;
    
    char estudiantes[5][30];
    char asignaturas[3][30];

    // Entrada de nombres de los estudiantes
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i]);
    }

    // Entrada de nombres de las asignaturas
    for (int j = 0; j < 3; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        scanf("%s", asignaturas[j]);
    }

    // Entrada de notas por estudiante y asignatura
    for (int i = 0; i < 5; i++) {
        printf("\nIngrese las notas del estudiante %s \n", estudiantes[i]);
        printf("---------------------------------------\n");

        for (int j = 0; j < 3; j++) {
            printf("Ingrese la nota de %s: ", asignaturas[j]);
            scanf("%f", &calif[i][j]);
            
            if (calif[i][j] > 10 || calif[i][j] < 0) {
                printf("La nota ingresada no es valida, vuelva a ingresarla \n");
                j--;
            }  
        }
    }

    // Cálculo de promedios por estudiante
    printf("\n");
    for (int i = 0; i < 5; i++) {
        promedio = 0;
        for (int j = 0; j < 3; j++) {
            promedio += calif[i][j];

            if (j == 0) {
                maximo = calif[i][j];
                minimo = calif[i][j];
            } else {
                if (calif[i][j] > maximo) {
                    maximo = calif[i][j];
                }
                if (calif[i][j] < minimo) {
                    minimo = calif[i][j];
                }
            }
        }
   
        promedio /= 3;
        printf("El promedio de %s es %.2f \n", estudiantes[i], promedio);
        printf("Nota maxima de %s es: %.2f \n", estudiantes[i], maximo);
        printf("Nota minima de %s es: %.2f \n\n", estudiantes[i], minimo);
    }

    // Cálculo de promedios por asignatura
    for (int j = 0; j < 3; j++) {   
        promedio = 0;
        aprobados = 0;
        reprobados = 0;

        for (int i = 0; i < 5; i++) {
            promedio += calif[i][j];

            if (i == 0) {
                maximo = calif[i][j];
                minimo = calif[i][j];
            } else {
                if (calif[i][j] > maximo) {
                    maximo = calif[i][j];
                }
                if (calif[i][j] < minimo) {
                    minimo = calif[i][j];
                }
            }

            if (calif[i][j] >= 6) {
                aprobados++;
            } else {
                reprobados++;
            }
        }

        promedio /= 5;
        printf("El promedio de %s es %.2f \n", asignaturas[j], promedio);
        printf("Nota maxima de %s es: %.2f \n", asignaturas[j], maximo);
        printf("Nota minima de %s es: %.2f \n", asignaturas[j], minimo);
        printf("Aprobados en %s: %d \n", asignaturas[j], aprobados);
        printf("Reprobados en %s: %d \n\n", asignaturas[j], reprobados);
    }

    return 0;
}
