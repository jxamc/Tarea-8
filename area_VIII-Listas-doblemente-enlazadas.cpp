#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo*& head, int valor) {

    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head != NULL) {
        head->anterior = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo*& head, int valor) {

    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (head == NULL) {
        nuevo->anterior = NULL;
        head = nuevo;
        return;
    }

    Nodo* temp = head;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void mostrarAdelante(Nodo* head) {

    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = head;

    cout << "\nLista hacia adelante:\n";

    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->siguiente;
    }

    cout << "NULL\n";
}

void mostrarAtras(Nodo* head) {

    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = head;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    cout << "\nLista hacia atras:\n";

    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->anterior;
    }

    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {

    Nodo* temp = head;

    while (temp != NULL) {

        if (temp->dato == valor) {
            return true;
        }

        temp = temp->siguiente;
    }

    return false;
}

void eliminar(Nodo*& head, int valor) {

    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Dato no encontrado\n";
        return;
    }

    if (actual == head) {

        head = actual->siguiente;

        if (head != NULL)
            head->anterior = NULL;

        delete actual;

        cout << "Nodo eliminado correctamente\n";
        return;
    }

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;

    delete actual;

    cout << "Nodo eliminado correctamente\n";
}

int contarNodos(Nodo* head) {

    int contador = 0;

    Nodo* temp = head;

    while (temp != NULL) {

        contador++;

        temp = temp->siguiente;
    }

    return contador;
}

void liberarLista(Nodo*& head) {

    Nodo* temp = head;

    while (temp != NULL) {

        Nodo* aux = temp;

        temp = temp->siguiente;

        delete aux;
    }

    head = NULL;
}

int main() {

    Nodo* head = NULL;

    int opcion, valor;

    cout << "Estudiante: JULIO CESAR XAM CHIVALAN\n";

    do {

        cout << "\n===== MENU =====\n";

        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar hacia adelante\n";
        cout << "4. Mostrar hacia atras\n";
        cout << "5. Buscar dato\n";
        cout << "6. Eliminar dato\n";
        cout << "7. Contar nodos\n";
        cout << "8. Salir\n";

        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                cout << "Ingrese valor: ";
                cin >> valor;

                insertarInicio(head, valor);

                break;

            case 2:

                cout << "Ingrese valor: ";
                cin >> valor;

                insertarFinal(head, valor);

                break;

            case 3:

                mostrarAdelante(head);

                break;

            case 4:

                mostrarAtras(head);

                break;

            case 5:

                cout << "Ingrese valor: ";
                cin >> valor;

                if (buscar(head, valor))
                    cout << "El valor SI existe\n";
                else
                    cout << "El valor NO existe\n";

                break;

            case 6:

                cout << "Ingrese valor: ";
                cin >> valor;

                eliminar(head, valor);

                break;

            case 7:

                cout << "Total nodos: "
                     << contarNodos(head)
                     << endl;

                break;

            case 8:

                cout << "Saliendo...\n";

                break;

            default:

                cout << "Opcion invalida\n";
        }

    } while (opcion != 8);

    liberarLista(head);

    return 0;
}