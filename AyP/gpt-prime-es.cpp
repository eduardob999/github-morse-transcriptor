#include <iostream>
using namespace std;

bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limite;
    
    cout << "Ingresa un número límite: ";
    cin >> limite;
    
    cout << "Números primos hasta " << limite << ": ";
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}
