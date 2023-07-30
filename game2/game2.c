#include <stdio.h>

// Función para acreditar los créditos según el valor del billete ingresado
int acreditarCreditos(int valorBillete, int creditosAcumulados) {
    // Arreglo que contiene los valores de billetes aceptados
    int billetesAceptados[] = {10, 20, 50, 100};
    
    // Arreglo que contiene la cantidad de créditos a acreditar para cada billete
    int creditosPorBillete[] = {1000, 2000, 5000, 10000};

    // Variable para indicar si el billete ingresado es válido
    int billeteValido = 0;
    
    // Verificar si el billete ingresado es válido
    for (int i = 0; i < sizeof(billetesAceptados) / sizeof(billetesAceptados[0]); i++) {
        if (valorBillete == billetesAceptados[i]) {
            creditosAcumulados += creditosPorBillete[i];
            billeteValido = 1;
            break;
        }
    }
    
    // Si el billete no es válido, mostrar un mensaje de error
    if (!billeteValido) {
        printf("El billete ingresado no es válido.\n");
    }
    
    return creditosAcumulados;
}

int main() {
    int creditos = 0;
    int billeteIngresado = 20;
    
    creditos = acreditarCreditos(billeteIngresado, creditos);
    printf("Créditos totales: %d\n", creditos);

    return 0;
}
