#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Constante fija para la semana
const int DIAS_SEMANA = 7;

// Utilidades
int leerEntero(string mensaje, int min, int max);
void mostrarEncabezado();
void pausar();

// Gestión de los 7 días
void mostrarTodos(string d[], int p[], int m[], float c[]);
void ingresarDatosIniciales(string d[], int p[], int m[], float c[]);
void modificarDiaEspecifico(string d[], int p[], int m[], float c[]);
void buscarPorValor(string d[], int p[], int m[], float c[]);
void ordenarSemana(string d[], int p[], int m[], float c[]);
void eliminarDatosDia(string d[], int p[], int m[], float c[]);

int main() {
    // Inicialización de nombres de días
    string dias[DIAS_SEMANA] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    int pasos[DIAS_SEMANA] = {0, 0, 0, 0, 0, 0, 0};
    int minutos[DIAS_SEMANA] = {0, 0, 0, 0, 0, 0, 0};
    float calorias[DIAS_SEMANA] = {0, 0, 0, 0, 0, 0, 0};

    int opcion;

    do {
        mostrarEncabezado();
        cout << "\n=== MONITOREO SEMANAL (7 DIAS) ===\n";
        cout << "1. Ingreso masivo de la semana\n";
        cout << "2. Modificar/Insertar datos de un dia especifico\n";
        cout << "3. Buscar un valor en la semana\n";
        cout << "4. Ordenar registros (Visualizacion temporal)\n";
        cout << "5. Eliminar (Resetear) datos de un dia\n";
        cout << "6. Mostrar reporte completo\n";
        cout << "0. Salir\n";
        
        opcion = leerEntero("Seleccione una opcion: ", 0, 6);

        switch (opcion) {
            case 1: ingresarDatosIniciales(dias, pasos, minutos, calorias); break;
            case 2: modificarDiaEspecifico(dias, pasos, minutos, calorias); break;
            case 3: buscarPorValor(dias, pasos, minutos, calorias); break;
            case 4: ordenarSemana(dias, pasos, minutos, calorias); break;
            case 5: eliminarDatosDia(dias, pasos, minutos, calorias); break;
            case 6: mostrarTodos(dias, pasos, minutos, calorias); break;
        }
        if (opcion != 0) pausar();
    } while (opcion != 0);

    return 0;
}

// --- FUNCIONES ADAPTADAS ---

void ingresarDatosIniciales(string d[], int p[], int m[], float c[]) {
    cout << "\n--- REGISTRO COMPLETO DE LA SEMANA ---\n";
    for (int i = 0; i < DIAS_SEMANA; i++) {
        cout << " Datos para el " << d[i] << ":" << endl;
        p[i] = leerEntero("  Pasos: ", 0, 100000);
        m[i] = leerEntero("  Minutos: ", 0, 1440);
        cout << "  Calorias: "; cin >> c[i];
    }
}

void modificarDiaEspecifico(string d[], int p[], int m[], float c[]) {
    cout << "\nSeleccione el dia (1.Lun, 2.Mar, 3.Mie, 4.Jue, 5.Vie, 6.Sab, 7.Dom): ";
    int seleccion = leerEntero("", 1, 7);
    int i = seleccion - 1; // Ajuste a índice de arreglo

    cout << "Modificando " << d[i] << ":" << endl;
    p[i] = leerEntero("  Nuevos Pasos: ", 0, 100000);
    m[i] = leerEntero("  Nuevos Minutos: ", 0, 1440);
    cout << "  Nuevas Calorias: "; cin >> c[i];
}

void eliminarDatosDia(string d[], int p[], int m[], float c[]) {
    cout << "\nSeleccione dia para resetear a cero (1-7): ";
    int i = leerEntero("", 1, 7) - 1;
    p[i] = 0; m[i] = 0; c[i] = 0;
    cout << "Datos del " << d[i] << " eliminados.\n";
}

void mostrarTodos(string d[], int p[], int m[], float c[]) {
    cout << "\nREPORTE SEMANAL:\n";
    cout << "DIA\t\t| PASOS\t| MIN\t| CAL\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < DIAS_SEMANA; i++) {
        cout << d[i] << (d[i].length() < 8 ? "\t\t| " : "\t| ") 
             << p[i] << "\t| " << m[i] << "\t| " << c[i] << endl;
    }
}

// Búsqueda por valor (Punto 4 de tu requerimiento)
void buscarPorValor(string d[], int p[], int m[], float c[]) {
    int valor = leerEntero("Ingrese cantidad de pasos a buscar: ", 0, 100000);
    bool encontrado = false;
    for (int i = 0; i < DIAS_SEMANA; i++) {
        if (p[i] == valor) {
            cout << "¡Encontrado! Dia: " << d[i] << " | Minutos: " << m[i] << " | Cal: " << c[i] << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No hay registros con esa cantidad de pasos.\n";
}

// Ordenamiento (Punto 5 de tu requerimiento)
void ordenarSemana(string d[], int p[], int m[], float c[]) {
    // Usamos una copia para no perder el orden Lunes-Domingo original
    int p_temp[DIAS_SEMANA], m_temp[DIAS_SEMANA];
    float c_temp[DIAS_SEMANA];
    string d_temp[DIAS_SEMANA];

    for(int i=0; i<7; i++) {
        p_temp[i] = p[i]; m_temp[i] = m[i]; c_temp[i] = c[i]; d_temp[i] = d[i];
    }

    // Burbuja
    for (int i = 0; i < DIAS_SEMANA - 1; i++) {
        for (int j = 0; j < DIAS_SEMANA - i - 1; j++) {
            if (p_temp[j] < p_temp[j+1]) { // Descendente por pasos
                swap(p_temp[j], p_temp[j+1]);
                swap(m_temp[j], m_temp[j+1]);
                swap(c_temp[j], c_temp[j+1]);
                swap(d_temp[j], d_temp[j+1]);
            }
        }
    }
    cout << "\nDias ordenados de mayor a menor actividad (pasos):\n";
    mostrarTodos(d_temp, p_temp, m_temp, c_temp);
}

// --- UTILIDADES ---
int leerEntero(string mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= min && valor <= max) return valor;
        cout << "Entrada invalida. Reintente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void mostrarEncabezado() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}