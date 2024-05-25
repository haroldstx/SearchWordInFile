#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string keyword;

    cout << "Ingrese la palabra a buscar en el archivo: ";
    cin >> keyword;

    ifstream file("Archivo.txt");

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo Archivo.txt" << endl;
        return 1;
    }

    int line_number = 0, total_occurrences = 0;
    string line;

    while (getline(file, line)) {
        line_number++;
        size_t pos = 0;
        while ((pos = line.find(keyword, pos)) != string::npos) {
            cout << "Se encontro la cadena en la linea: " << line_number << " en la posicion: " << pos << endl;
            pos += keyword.length();
            total_occurrences++;
        }
    }

    if (total_occurrences == 0) {
        cout << "No se encontraron ocurrencias de la cadena: " << keyword << endl;
    }
    else {
        cout << "Se encontraron: " << total_occurrences << " ocurrencias de la cadena: " << keyword << endl;
    }

    file.close();

    return 0;
}

