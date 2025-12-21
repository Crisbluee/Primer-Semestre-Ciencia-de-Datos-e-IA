#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

// Constantes globales
const int DIAS = 5; // Definimos el tamaño para 5 días de producción
const float UMBRAL_HORAS = 8.5; // Valor X para sobrecarga de horas
const float UMBRAL_TEMP = 75.0; // Umbral para sobrecalentamiento

// --- Prototipos de Funciones ---
void ingresarDatos(int prod[], float horas[], float energia[], float temp[]);
void analizarProduccion(int prod[]);
void analizarHoras(float horas[]);
void analizarEnergia(float energia[]);
void analizarTemperatura(float temp[]);
float validarFlotante(string mensaje);
int validarEntero(string mensaje);

int main() {
    // 1. Estructura del Sistema (4 arreglos unidimensionales)
    int produccion[DIAS];
    float horasOperacion[DIAS];
    float consumoEnergia[DIAS];
    float temperaturaMaquinas[DIAS]; // Arreglo personalizado

    int opcion;

    cout << "=== SISTEMA DE MONITOREO INDUSTRIAL ===" << endl;
    ingresarDatos(produccion, horasOperacion, consumoEnergia, temperaturaMaquinas);

    do {
        cout << "\n--- MENU DE ANALISIS ---" << endl;
        cout << "1. Analisis de Produccion Diaria" << endl;
        cout << "2. Analisis de Horas de Operacion" << endl;
        cout << "3. Analisis de Consumo de Energia" << endl;
        cout << "4. Analisis de Temperatura (Personalizado)" << endl;
        cout << "5. Salir" << endl;
        opcion = validarEntero("Seleccione una opcion: ");

        switch (opcion) {
        case 1: analizarProduccion(produccion); break;
        case 2: analizarHoras(horasOperacion); break;
        case 3: analizarEnergia(consumoEnergia); break;
        case 4: analizarTemperatura(temperaturaMaquinas); break;
        case 5: cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 5);

    return 0;
}

// --- Implementacion de Funciones ---

// Funcion para validar que la entrada sea un numero flotante positivo
float validarFlotante(string mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= 0) return valor;
        cout << "Error: Ingrese un valor numerico positivo." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Funcion para validar que la entrada sea un numero entero positivo
int validarEntero(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= 0) return valor;
        cout << "Error: Ingrese un numero entero positivo." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void ingresarDatos(int prod[], float horas[], float energia[], float temp[]) {
    cout << "\n--- Ingreso de Datos (Registro de " << DIAS << " dias) ---" << endl;
    for (int i = 0; i < DIAS; i++) {
        cout << "\nDia " << i + 1 << ":" << endl;
        prod[i] = validarEntero("  Unidades producidas: ");
        horas[i] = validarFlotante("  Horas operadas: ");
        energia[i] = validarFlotante("  Consumo energia (kWh): ");
        temp[i] = validarFlotante("  Temperatura promedio maq. (C): ");
    }
}

void analizarProduccion(int prod[]) {
    int total = 0, mayor = prod[0], menor = prod[0];
    int diaMayor = 1, diaMenor = 1;

    for (int i = 0; i < DIAS; i++) {
        total += prod[i];
        if (prod[i] > mayor) { mayor = prod[i]; diaMayor = i + 1; }
        if (prod[i] < menor) { menor = prod[i]; diaMenor = i + 1; }
    }

    cout << fixed << setprecision(2);
    cout << "\n--- RESULTADOS PRODUCCION ---" << endl;
    cout << "Total producido: " << total << " unidades" << endl;
    cout << "Promedio diario: " << (float)total / DIAS << " unidades" << endl;
    cout << "Mayor produccion: " << mayor << " (Dia " << diaMayor << ")" << endl;
    cout << "Menor produccion: " << menor << " (Dia " << diaMenor << ")" << endl;
}

void analizarHoras(float horas[]) {
    float suma = 0, menor = horas[0];
    int diaMenor = 1;

    cout << "\n--- RESULTADOS HORAS DE OPERACION ---" << endl;
    cout << "Dias con sobrecarga (Horas > " << UMBRAL_HORAS << "): ";
    bool haySobrecarga = false;

    for (int i = 0; i < DIAS; i++) {
        suma += horas[i];
        if (horas[i] < menor) { menor = horas[i]; diaMenor = i + 1; }
        if (horas[i] > UMBRAL_HORAS) {
            cout << "Dia " << i + 1 << " ";
            haySobrecarga = true;
        }
    }
    if (!haySobrecarga) cout << "Ninguno";

    cout << "\nPromedio de horas: " << suma / DIAS << " hrs" << endl;
    cout << "Dia con menos trabajo: Dia " << diaMenor << " (" << menor << " hrs)" << endl;
}

void analizarEnergia(float energia[]) {
    float total = 0;
    for (int i = 0; i < DIAS; i++) total += energia[i];
    float promedio = total / DIAS;

    // Encontrar el dia con consumo mas cercano al promedio
    float diferenciaMinima = abs(energia[0] - promedio);
    int diaCercano = 1;

    for (int i = 1; i < DIAS; i++) {
        float dif = abs(energia[i] - promedio);
        if (dif < diferenciaMinima) {
            diferenciaMinima = dif;
            diaCercano = i + 1;
        }
    }

    cout << "\n--- RESULTADOS CONSUMO ENERGIA ---" << endl;
    cout << "Consumo total: " << total << " kWh" << endl;
    cout << "Consumo promedio: " << promedio << " kWh" << endl;
    cout << "Dia con consumo mas cercano al promedio: Dia " << diaCercano << " (" << energia[diaCercano - 1] << " kWh)" << endl;
}

// Funcion Personalizada: Analisis de Temperatura
void analizarTemperatura(float temp[]) {
    cout << "\n--- ALERTA DE TEMPERATURA (PERSONALIZADO) ---" << endl;
    cout << "Umbral critico definido: " << UMBRAL_TEMP << " C" << endl;
    bool alerta = false;

    for (int i = 0; i < DIAS; i++) {
        if (temp[i] > UMBRAL_TEMP) {
            cout << "[!] ALERTA: Sobrecalentamiento detectado el Dia " << i + 1 << " (" << temp[i] << " C)" << endl;
            alerta = true;
        }
    }

    if (!alerta) {
        cout << "Estado del sistema: Normal. No se detectaron anomalias termicas." << endl;
    }
}