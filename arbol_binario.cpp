#include <iostream>

using namespace std;

// Definicion de la estructura para cada elemento del arbol
struct Elemento {
    int valor;
    Elemento* izquierdo;
    Elemento* derecho;
};

// Crea e inicializa un nuevo elemento con el valor indicado
Elemento* insertarNodo(int val) {
    Elemento* nuevo = new Elemento();
    nuevo->valor = val;
    nuevo->izquierdo = nullptr;
    nuevo->derecho = nullptr;
    return nuevo;
}

// Imprime los elementos siguiendo el orden: Raiz -> Izquierda -> Derecha
void mostrarPreorden(Elemento* nodo) {
    if (nodo != nullptr) {
        cout << nodo->valor << " ";
        mostrarPreorden(nodo->izquierdo);
        mostrarPreorden(nodo->derecho);
    }
}

// Imprime los elementos siguiendo el orden: Izquierda -> Raiz -> Derecha
void mostrarInorden(Elemento* nodo) {
    if (nodo != nullptr) {
        mostrarInorden(nodo->izquierdo);
        cout << nodo->valor << " ";
        mostrarInorden(nodo->derecho);
    }
}

// Imprime los elementos siguiendo el orden: Izquierda -> Derecha -> Raiz
void mostrarPostorden(Elemento* nodo) {
    if (nodo != nullptr) {
        mostrarPostorden(nodo->izquierdo);
        mostrarPostorden(nodo->derecho);
        cout << nodo->valor << " ";
    }
}

int main() {
    // Armado del arbol binario respetando los 4 niveles de profundidad
    Elemento* raiz = insertarNodo(50);
    raiz->izquierdo = insertarNodo(25);
    raiz->derecho = insertarNodo(75);
    raiz->izquierdo->izquierdo = insertarNodo(10);
    raiz->izquierdo->derecho = insertarNodo(35);
    raiz->izquierdo->izquierdo->izquierdo = insertarNodo(5);

    // Dibujo de la estructura del arbol para mostrarlo en pantalla
    cout << "=== ARBOL BINARIO DE 4 NIVELES ===" << endl;
    cout << "            (50)            " << endl;
    cout << "           /    \\           " << endl;
    cout << "         (25)   (75)        " << endl;
    cout << "         /  \\               " << endl;
    cout << "       (10) (35)            " << endl;
    cout << "       /                    " << endl;
    cout << "     (5)                    " << endl;
    cout << "----------------------------------" << endl;

    // Llamada a las funciones para mostrar los tres recorridos
    cout << "Secuencia PreOrden  : ";
    mostrarPreorden(raiz);
    cout << endl;

    cout << "Secuencia InOrden   : ";
    mostrarInorden(raiz);
    cout << endl;

    cout << "Secuencia PostOrden : ";
    mostrarPostorden(raiz);
    cout << endl;

    return 0;
}
