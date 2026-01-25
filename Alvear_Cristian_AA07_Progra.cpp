#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 


/*
CRISTIAN ALVEAR

ACTIVIDAD AUTÓNOMA 07 PROGRAMACIÓN
27 DE ENERO DEL 2025

TAREA Gestión de Biblioteca Escolar
*/
using namespace std;

int leerEntero(string mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor) || valor < 0) {
        cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return valor;
}

void mostrarDisponibles(const vector<string>& nombres, const vector<int>& stock) {
    cout << "\n--- LIBROS DISPONIBLES ---" << endl;
    for (size_t i = 0; i < nombres.size(); i++) {
        if (stock[i] > 0) {
            cout << "ID: " << i << " | Libro: " << nombres[i] << " | Stock: " << stock[i] << endl;
        }
    }
}

// 2. Actualizar stock por préstamo
void realizarPrestamo(vector<int>& stock, vector<int>& prestados, int id) {
    if (id >= 0 && id < stock.size()) {
        if (stock[id] > 0) {
            stock[id]--;     // Reducimos stock
            prestados[id]++; // Aumentamos cantidad prestada
            cout << "Prestamo realizado con exito." << endl;
        } else {
            cout << "No hay stock suficiente." << endl;
        }
    } else {
        cout << "ID de libro no encontrado." << endl;
    }
}

// 3. Calcular préstamos totales (Operación avanzada)
void reporteAvanzado(const vector<string>& nombres, const vector<vector<int>>& matrizPrestamos) {
    int maxPrestamos = -1;
    string libroMasPopular = "";
    
    cout << "\n--- REPORTE DE PRESTAMOS SEMANALES ---" << endl;
    for (size_t i = 0; i < nombres.size(); i++) {
        int sumaFila = 0;
        for (int j = 0; j < 5; j++) { // Lunes a Viernes
            sumaFila += matrizPrestamos[i][j];
        }
        cout << "Libro: " << nombres[i] << " | Total semanal: " << sumaFila << endl;
        
        if (sumaFila > maxPrestamos) {
            maxPrestamos = sumaFila;
            libroMasPopular = nombres[i];
        }
    }
    cout << "\nEl libro mas prestado fue: " << libroMasPopular << " con " << maxPrestamos << " prestamos." << endl;
}

int main() {
    // Usamos vectores para manejar la información 
    // Matriz de Libros: Nombres y Categorías
    vector<string> nombres = {"Don Quijote", "Calculo I"};
    vector<string> categorias = {"Literatura", "Matematicas"};
    
    vector<int> stock = {10, 5};
    vector<int> prestadosActivos = {2, 1};
    
    // Matriz de Préstamos (5 columnas: Lunes a Viernes)
    vector<vector<int>> registroSemanal = {
        {1, 0, 2, 1, 0},
        {0, 2, 1, 0, 3}  
    };

    int opcion;
    do {
        cout << "\n********** MENU BIBLIOTECA **********" << endl;
        cout << "1. Ver libros con stock" << endl;
        cout << "2. Registrar prestamo" << endl;
        cout << "3. Modificar libro" << endl;
        cout << "4. Eliminar libro" << endl;
        cout << "5. Reporte avanzado (Totales)" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                mostrarDisponibles(nombres, stock);
                break;
            case 2:
                int id;
                id = leerEntero("Ingrese ID del libro: ");
                realizarPrestamo(stock, prestadosActivos, id);
                break;
            case 3: // Modificar información 
                id = leerEntero("Ingrese ID a modificar: ");
                if (id >= 0 && id < nombres.size()) {
                    cout << "Nuevo nombre: ";
                    cin.ignore();
                    getline(cin, nombres[id]);
                    stock[id] = leerEntero("Nuevo stock: ");
                }
                break;
            case 4: // Eliminar libro 
                id = leerEntero("Ingrese ID a eliminar: ");
                if (id >= 0 && id < nombres.size()) {
                    nombres.erase(nombres.begin() + id);
                    stock.erase(stock.begin() + id);
                    cout << "Libro eliminado." << endl;
                }
                break;
            case 5:
                reporteAvanzado(nombres, registroSemanal);
                break;
        }
    } while (opcion != 0);

    return 0;
}
