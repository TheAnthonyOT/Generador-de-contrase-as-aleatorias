#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void generarContrasena(int longitud, bool incluirMayusculas, bool incluirMinusculas, bool incluirSimbolos);
void MenudeGeneracion();
int main() {
MenudeGeneracion();

    return 0;
}

void MenudeGeneracion(){
    bool generarOtra = true;

    while (generarOtra) {
        // Solicitar la longitud de la contrase�a al usuario
        int longitud;

        do {
            cout << "Ingrese la longitud de la contrasena (maximo 15 caracteres): ";
            cin >> longitud;

            // Verificar que la longitud sea v�lida
            if (longitud <= 0 || longitud > 15) {
                cout << "La longitud de la contrasena debe ser mayor que 0 y no debe exceder los 15 caracteres." << endl;
            }

        } while (longitud <= 0 || longitud > 15);

        // Permitir al usuario elegir los tipos de caracteres
        bool incluirMayusculas, incluirMinusculas, incluirSimbolos;

        cout << "�Incluir mayusculas? (1: Si, 0: No): ";
        cin >> incluirMayusculas;

        cout << "�Incluir minusculas? (1: Si, 0: No): ";
        cin >> incluirMinusculas;

        cout << "�Incluir simbolos? (1: Si, 0: No): ";
        cin >> incluirSimbolos;

        // Llamar a la funci�n para generar la contrase�a
        generarContrasena(longitud, incluirMayusculas, incluirMinusculas, incluirSimbolos);

        // Preguntar al usuario si desea generar otra contrase�a
        char respuesta;
        cout << "�Generar otra contrasena? (S/N): ";
        cin >> respuesta;

        generarOtra = (respuesta == 'S' || respuesta == 's');
    }

    cout << "�Gracias por usar el generador de contrasenas!" << endl;
}
// Definici�n de la funci�n para generar la contrase�a
void generarContrasena(int longitud, bool incluirMayusculas, bool incluirMinusculas, bool incluirSimbolos) {
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string simbolos = "!@#$%^&*()_-+=<>?";
    string caracteresPermitidos;

    // Construir la cadena de caracteres permitidos seg�n las preferencias del usuario
    if (incluirMayusculas) {
        caracteresPermitidos += mayusculas;
    }
    if (incluirMinusculas) {
        caracteresPermitidos += minusculas;
    }
    if (incluirSimbolos) {
        caracteresPermitidos += simbolos;
    }

    // Verificar si se ha seleccionado al menos un tipo de caracter
    if (caracteresPermitidos.empty()) {
        cout << "Error: Debes seleccionar al menos un tipo de caracter para generar la contrasena." << endl;
        return;
    }

    const int numCaracteres = caracteresPermitidos.length();

    // Inicializar la semilla para la generaci�n de n�meros aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Generar la contrase�a
    string contrasena;
    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % numCaracteres;
        contrasena.push_back(caracteresPermitidos[indice]);
    }

    // Mostrar la contrase�a generada
    cout << "Contrasena generada: " << contrasena << endl;
}
