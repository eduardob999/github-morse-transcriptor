# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <array>
#include <fstream>
/// EXCLUSIVO DE WINDOWS ELIMINAR DE OTRAS VERSIONES
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
///

using namespace std;

void Input( string prompt, string& t, int min, int max, string con, string d, bool word);
void Search( int j, int& ind , string t , string d , int size);
void OutputMorse( string t , string d , int& nm , string& np , float& tp , string& proc);

int main()   /////////////////El codigo funciona solo hace falta testearlo
{
    SetConsoleOutputCP( 65001 );
    
    string menu0 = "\nUniversidad Central de Venezuela"
                "\nFacultad de Ciencias"
                "\nEscuela de Computación"
                "\nAlgoritmos y Programación. Sem I-2023."
                "\nProyecto 1. Código Morse Internacional."
                "\n"
                "\nMenú:"
                "\n  1.  Integrantes de Equipo"
                "\n  2.  Transmitir Texto en Código Morse"
                "\n  3.  Convertir Código Morse a Texto"
                "\n  4.  Estadísticas"
                "\n  5.  Salir"
                "\n"
                "\nPor favor, indique su opción:";
    string cond0 = "\nDebe ingresar un número entero entre 1 y 5. "
                "\nIngrese su opción nuevamente:";
    string t;

    string txt, dic, ver, ver2, ver3, menu1, cond1, menu2, cond2, menu3, cond3, proces, dictxt, dicmor;
    string temp1, cpal = "0", temp2;
    int flag, contm, cmt = 0;
    float tpal = 0;
    fstream file;

    // Inicialización de los strings correspondientes a los textos y 
    // condiciones de cada menú.
    dictxt = "\t";
    dicmor = "\t";
    dic = "\t";
    ver = "\n¿Desea volver al menu principal?"
           "\nResponda con Sí o No:";
    ver2 = "\n¿Desea transmitir otro mensaje?"
           "\nResponda con Sí o No: ";
    ver3 = "\n¿Desea convertir otro mensaje?"
           "\nResponda con Sí o No:";
    menu1 = "\nOpción 1 - Integrantes del Equipo."
            "\n"
            "\nUniversidad Central de Venezuela"
    		"\nFacultad de Ciencias"
            "\nEscuela de Computación"
            "\nAlgoritmos y Programación. Sem I-2023."
            "\n"
            "\nEduardo Alfonso Bogado Rojas"
            "\nC.I: v-26.818.715"
            "\n"
            "\nMenú:"
            "\n"
            "\n  1.  Regresar al menú anterior"
            "\n"
            "\nPor favor, indique su opción:";
    cond1 = "\nDebe ingresar al número entero 1. "
            "\nIndique su opción nuevamente:";
    menu2 = "\nOpción 2 - Transmitir Texto en Código Morse"
            "\n"
            "\nEl mensaje no debe incluir más de 60 caracteres."
            "\nPor favor, introduzca el texto a codificar:";
    cond2 = "\nEl texto debe tener de 1 a 60 caracteres."
            "\nEvite el uso de acentos ajenos al idioma español."
            "\nSe admiten solo caracteres incluidos en la convención ITU-RM.1677-1"
            "\nPor favor, introduzca nuevamente el texto a codificar:";
    menu3 = "\nOpción 3 - Convertir Código Morse en Texto Normal"
            "\n"
            "\nEl mensaje no debe incluir más de 180 caracteres."
            "\nSe admiten solo caracteres incluidos en la convención ITU-RM.1677-1"
            "\nPor favor, introduzca la codificación:";
    cond3 = "\nEl texto debe tener de 1 a 180 caracteres."
            "\nEl punto, señal corta o dot viene dado por el caracter \".\"."
            "\nLa línea, señal larga o dash viene dado por el caracter \"-\"."
            "\nEvite el uso de carácteres con acentos ajenos al idioma español."
            "\nLos carácteres representados deben ir separados por espacios."
            "\nLas palabras vienen separadas por el caracter \"/\"."
            "\nPor favor, introduzca la codificación nuevamente: ";

    // Inicilaización de strings traductores
    contm = 0;
    file.open( "morse.txt", ios::in );
    file.peek();
    do
    {

        getline( file, temp1, '\t' );
        getline( file, temp2, '\n' );
        dictxt = dictxt + temp1 + "\t";
        dicmor = dicmor + temp2 + "\t";
        dic = dic + temp1 + "\t" + temp2 + "\t";
        contm = contm + 1;
        file.peek();
    } while (!( file.peek() == EOF ));
    file.close();
    cout << dic << endl; ///////////////////////

    Input( menu0 , t , 1 , 20 , cond0, "\to\t", true );
    OutputMorse( txt, dic, cmt, cpal, tpal, proces );
    return 0;
}

void Input( string prompt, string& t, int min, int max, string con, string d, bool word)
{
    // Esta acción maneja todas las entradas de dato tipo string.
    // Se incluye solicitud de datos y validación.
    // Este procedmiento se diseño con la finalidad de ser altamente
    // reutilizable.

    // Declaración de variables.
    int ind, flag, i, size;

    // Procesamiento: Se comienzo mostrarndo el mensaje de solicitud
    // El mensaje de solicitud se obtiene como parametro.
    cout << prompt << endl;
    do {

        // Este ciclo es un ciclo de validación.
        // Inicialización de contadores.
        flag = 0; 
        size = 0;

        // Procesamiento: se comienza solicitando el texto de entrada.
        getline( cin, t );
        if (t.length() >= min && t.length() <= max) {

            // En este condicional se verifica la longitud de la
            // cadena, los límites son personalizbles y se valida la entrada
            for ( i = 0; i < t.length() ; i++)
            {
                
                if (word)
                {
                    if ( t.substr( i, 1 ) == " " ) {
                    
                        size = i - size;
                        Search( i - size, ind , t , d , size );
                        size = i + 1;
                    } else if ( i + 1 == t.length() ) {

                        size = i - size + 1;
                        Search( i - size + 1, ind , t , d , size );
                        size = i + 1;
                    }
                } else {
                    
                    Search( i, ind, t, d, 1 );
                }
                if ( ind == -1 ) {
                        
                    // Este condicional asigna un valor bandera al caso de error
                    flag = -1;
                }
            }
        } else {

            // Este condicional asigna un valor bandera al caso fuera de límites
            flag = -1;
        }

        if ( flag == -1 ) {
            
            // Este condicional muestra un mensaje de corrección de ser necesario.
            cout << con << endl;
        }
    }
    while (!( flag != -1 ));
}

void Search( int j, int& ind , string t , string d , int size)
{
    // El buscador identifica la ubicación relativa de una cadena de caracteres en otra
    // y le asigna un índice entero.

    // Declaración e inicialización de contadores
    int k;
    ind = 0; 
    k = 0;

    // Procesamiento y generación del índice.
    do {
        
        // Este ciclo encuentra el valor del índice según las coincidencias dadas.
        if ( d.substr( k , 1 ) == "\t" )
        {
            ind = ind + 1;
        }
        k = k + 1;
        if ( k + size == d.length() ) {
            ind = -1;
        }
    }
    while  (!(  "\t" + t.substr( j , size ) + "\t" == d.substr( k - ( 1 ) , size + 2 ) || ind == -1 ));  //zi
}

void OutputMorse( string t , string d , int& nm , string& np , float& tp , string& proc)
{  
    // Esta acción procesa las entradas de texto y las convierte en morse.
    
    // Declaración de variables.
    string selec; int i, ind, q, palen; stringstream stream;

    // Inicialización de variables.
    proc = "";
    palen = 0;

    // Procesamimiento de la caena de entrada "t".
    for ( i = 1 ; i <= t.length() ; i++ ) {

        // Este ciclo verifica cada letra de la entrada
        // se reutiliza el kernel en esta acción
        // el cuantificador determina la cantidad de carcaternes
        // que tendrá cada salida.
        Kernel( i , ind , t , d , 1 );
        Cuantificador( ind , q , t , d );

        if ( d.substr( ind + 3 - ( 1 ) , q ) == "/" || i + 1 > t.length() ) { //zi
            
            // Este ciclo cuenta la cantidad de palabras y las almacena en "palen".
            palen = palen + 1;
        };
        proc = proc + d.substr( ind + 3 - ( 1 ) , q ) + " "; //zi
    };

    // Procesamiento de datos intermedios.
    stream << palen;
    nm = nm + 1;
    np = np + stream.str() + " ";
    tp = tp + palen;

    // Codigo morse codificado:
    cout << "\nLa Codificación Morse de \"" << t << "\" es:\n" << proc << endl;

}