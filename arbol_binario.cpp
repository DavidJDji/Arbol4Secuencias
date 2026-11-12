#include <iostream>

using namespace std;


struct Elemento {
    int valor;
    Elemento* izquierdo;
    Elemento* derecho;
};


Elemento* insertarNodo(int val) {
    Elemento* nuevo = new Elemento();
    nuevo->valor = val;
    nuevo->izquierdo = nullptr;
    nuevo->derecho = nullptr;
    return nuevo;
}


void mostrarPreorden(Elemento* nodo) {
    if (nodo != nullptr) {
        cout << nodo->valor << " ";
        mostrarPreorden(nodo->izquierdo);
        mostrarPreorden(nodo->derecho);
    }
}


void mostrarInorden(Elemento* nodo) {
    if (nodo != nullptr) {
        mostrarInorden(nodo->izquierdo);
        cout << nodo->valor << " ";
        mostrarInorden(nodo->derecho);
    }
}


void mostrarPostorden(Elemento* nodo) {
    if (nodo != nullptr) {
        mostrarPostorden(nodo->izquierdo);
        mostrarPostorden(nodo->derecho);
        cout << nodo->valor << " ";
    }
}

int main() {
 
    Elemento* raiz = insertarNodo(50);
    raiz->izquierdo = insertarNodo(25);
    raiz->derecho = insertarNodo(75);
    raiz->izquierdo->izquierdo = insertarNodo(10);
    raiz->izquierdo->derecho = insertarNodo(35);
    raiz->izquierdo->izquierdo->izquierdo = insertarNodo(5);

    
    cout << "=== ARBOL BINARIO DE 4 NIVELES ===" << endl;
    cout << "            (50)            " << endl;
    cout << "           /    \\           " << endl;
    cout << "         (25)   (75)        " << endl;
    cout << "         /  \\               " << endl;
    cout << "       (10) (35)            " << endl;
    cout << "       /                    " << endl;
    cout << "     (5)                    " << endl;
    cout << "----------------------------------" << endl;

   
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
