// Notas de desarrollador


// Haz la tarea antes del lunes
// Se eliminó la función input entero y se lenó con la generalización InputString
// este programa emplea caracteres unicode

////// C++ No puede trabajar con acentos, corregir en version final ///////

// sustituye input integer por input string, crea nuevos diccionario para las entradas de 2 (?)
// añadir un verificador al menu 1 (poco necesario)
// arreglar outpu con 7 puntos ....... a texto
// cambiar n de outpu stat a integer (poco necesario)
// que no sea necsario que salgan barras dobles al final de la cadena completa (poco necesario)
// complementar el outpustat (poco necesario)
// añadir simbolos faltantes (en caso de ser necesario)
// regresar al amenu inicial en stats (poco necesario)
// se debe borrar la función ImputEntero
// eliminar el desea volver al menu principal de la opcion 4

//-----------------------------------------------------------------------
//
//                    Transcriptor de Código Morse
//
//------------------------------------------------------------------------
// Codigo finalizado el día 18/8/23
// Programa desarrollado por Eduardo Bogado
// Universidad Central de Venezuela
// Github user eduardob999

//Librerías

# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <array>
# include <fstream>
/// EXCLUSIVO DE WINDOWS ELIMINAR DE OTRAS VERSIONES
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
///

using namespace std;

// Firma de procedimientos

void Input( string prompt, string& t, int min, int max, string con, string d, bool word);
void Search( int j, int& ind , string t , string d , int size);
void Seleccion( string& in, int& cmt, string& cpal, float& tpal, int& nerr, string& morse, string& msg );
void OutputMorse( string t, string d, int& nm, string& np, float& tp, string& proc);
void Kernel( int j, int& ind, string t, string d, int size );
void Cuantificador( int k, int& q, string t, string d );
bool Verificador( string p );
void OutputTexto( string t, string d, int& ne );
void TokenSize( int j, int& size, string t );
void OutputStats( int n, string cp, float tp, int ne, string m, string t );
/// FUNCIONES RESIDUALES ///
void InputEntero( string prompt, int& in, int min, int max, string con);
void InputString( string prompt, string& t, int min, int max, string con, string d, int size);
// Procedimientos

int main()           
{
    // Acá se manejan la iniciación y finalización del programa,
    // así como también, se declaran e inicializan las variables
    // compartidas entre procedimientos.

    /// EXCLUSIVO DE WINDOWS ELIMINAR DE OTRAS VERSIONES
    // Texto Unicode windows
    SetConsoleOutputCP( 65001 );
    ///

    // Declaración de variables
    int cantmsg, nerror;
    string inp, menu0, cond0, cantpal, morsefinal, texto, aux;
    float totpal;
    fstream morse;

    // Inicialización de variables
    cantmsg = 0;
    totpal = 0;
    nerror = 0;
    cantpal = "";
    morsefinal = "";
    texto = "";
    menu0 = "\nUniversidad Central de Venezuela"
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
    cond0 = "\nDebe ingresar un número entero entre 1 y 5. "
            "\nIngrese su opción nuevamente:";

    // Verificacion de archivos auxiliares y conteo de líneas
	morse.open( "morse.txt", ios::in );
	if (!morse) {

		cout << "\nArchivo morse.txt no encontrado en el directorio actual "
                "por favor añadalo.\n" << endl;;
        morse.close();
        return 0;
	} else if ( morse.peek() == EOF ) {

        cout << "\nEl archivo morse.txt se encuentra vacío. Por favor "
                "incluya un archivo morse.tsv válido al directorio actual.\n" << endl;
        morse.close();
		return 0;
    }
    morse.close();

    // Menú principal
    do {
        
        // En este ciclo se controla la ejecicón y salida del programa
        // la variable inp se emplea como bandera
        Input( menu0 , inp , 1 , 1 , cond0, "\t1\t2\t3\t4\t5\t", false );
        Seleccion( inp , cantmsg , cantpal , totpal , nerror , morsefinal, texto );
    }
    while ( !( inp == "5" ) );
    return 0;
};

void Seleccion( string& in, int& cmt, string& cpal, float& tpal, int& nerr, string& morse, string& msg )
{
    // En este procedimiento se maneja el menúi de selección
    // Declaracion de variables
    string txt, dic, ver, ver2, ver3, menu1, cond1, menu2, cond2, menu3, cond3, proces, dictxt, dicmor;
    string temp1, temp2;
    int flag, contm;
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
    // Selección correspoendiente a las opciones del menú.
    switch( atoi( in.c_str() )) {
    case 1:

        // Opción 1 - Identificación del equipo.
        Input( menu1 , in , 1 , 1 , cond1, "\t1\t", false );
        break;
    case 2:

        // Opción 2 - Codificación de texto a código morse.
        do {

            // Este ciclo permite la reutilización del menú
            // sin neecesidad de volver al menú inicial.
            // El procesamiento y traducción de la entrada es llevada a
            // cabo por la fucnión OutputMorse.
            Input( menu2, txt, 1, 60, cond2, dictxt, false );
            OutputMorse( txt, dic, cmt, cpal, tpal, proces );
            msg = msg + txt + "\n";
            morse = morse + proces + "//";
        }
        while (!( Verificador( ver2 ) ));
        break;
    case 3:

        // Opción 3 - Decodificación de código Morse a Texto.
        do {

            // Este ciclo permite la reutilización del menú
            // sin neecesidad de volver al menú inicial.
            // El procesamiento y traducción de la entrada es llevada a
            // cabo por la acción OutputTexto.
            Input( menu3, txt, 1, 180, cond3, dicmor, true );
            OutputTexto( txt , dic , nerr );
        }
        while (!( Verificador( ver3 ) ));
        break;
    case 4:
        
        // Opción 4 - Estadística.
        do {

            // Este ciclo permite la reutilización del menú
            // sin neecesidad de volver al menú inicial.
            // El procesamiento y traducción de la entrada es llevada a
            // cabo por la acción OutputStat.
            cout << "\nOpción 4 - Estadísticas" << endl;
            OutputStats( cmt , cpal , tpal, nerr, morse, msg );
        }
        while (!(!(  Verificador( ver ) )));
        break;
    case 5:
        
        // Opción 5 - Salida y resumen de actividad.
        // Se reutiliza la acción OutputStat para mostrar
        // el resumen de actividad.
        cout << "\nOpción 5 - Salir. A continuación un resumen de su actividad:" << endl;
        OutputStats( cmt , cpal , tpal, nerr, morse, msg );
        cout << "\nGracias por usar este programa.\n" << endl;
        in = "5";
    };
};

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

void Kernel( int j, int& ind , string t , string d , int size )
{
    // El kernel identifica la ubicaciñon relativa de una cadena de caracteres en otra
    // y le asigna un índice entero.

    // Inicialización del contador principal.
    ind = 0;

    // Procesamiento y generación del índice.
    do {
        
        // Este ciclo encuentra el valor del índice según las coincidencias dadas.
        ind = ind + 1 ;
    }
    while  (!(  "\t" + t.substr( j - ( 1 ) , size ) + "\t" == d.substr( ind - ( 1 ) , size + 2 ) ||  ind + size > d.length()  ));  //zi
}

void Cuantificador( int ind , int& q , string t , string d )
{
    // Esta acción mide el tamaño de una subcadena en un string
    // este procedimiento es específcio de la acción OutputMorse.

    // Inicialición del contador principal.
    q = 0;
    do  {
        
        // Este ciclo encuentra el valor del tamaño de la subcadena según las especificaciones.
        q = q + 1;
    }
    while (!( ind + q + 2 > d.length() || ( d.substr( ind + q + 2 - ( 1 ) , 1 ) != "." && d.substr( ind + q + 2 - ( 1 ) , 1 ) != "-"  && d.substr( ind + q + 2 - ( 1 ) , 1 ) != "/" ) )); ///zi
    q = q - 1;
};
         
bool Verificador( string p )
{
    // Función reutlizable empleada para determinar la condición de salida
    // de un ciclo con finalidad de reutilizar una serie de
    // procedimeintos.

    // Declaraciónes de variables.
    string cond, ans, acc, rej; int sind, nind, flag;

    // Inicialización de variables.
    acc = "\tSI\tSi\tsI\tsi\tSí\tsÍ\tSÍ\tsí\t";
    rej = "\tNo\tnO\tNO\tno\t";
    cond = "\nDebe responder con Sí o No"
           "\nIntroduzca su respuesta nuevamente: ";

    // Solicitud de entrada y procesamiento.
    do {

        //Este es un ciclo de validación.
        InputString( p , ans , 2 , 2 , cond, acc + rej, 2);
        Kernel( 1 , sind , ans , acc , 2);
        Kernel( 1 , nind , ans , rej , 2);
        if ( sind < acc.length() - 1 ) {

            // Este condicional verifca el resultado positivo.  
            return false;
        } else {
            if ( nind < rej.length() - 1 ) {

            // Este condicional verifca el resultado negativo.
            return true;
            } else {

                // En caso no definido se solicitan los datos nuevamente.
                cout << cond << endl;
                flag = -1;
            }
        }
    }
    while (!( flag != -1 ));
    return false;
}

void OutputTexto( string t , string d , int& ne )
{
    // Esta acción procesa las entradas de codigo morse y las convierte en
    // cadenas de caracteres con texto.
    
    // Declaración de variables.
    string prompt, cond, selec, proc; int i, size, ind, q, flag, errs, errind;

    // Inicialización de contadores indices y datos intermedios:
    proc = "";
    i = 0;

    // Procesa y muestra la salida.
    do {
        
        // Este ciclo realiza la traducción del código morse al texto.
        
        // Inicialización de flags y datos intermedios.
        // Los datos intermedios son datos que se utilizan para
        // operaciones matemáticas no se muestran al usuario sin ser
        // procesados.
        flag = 1;
        errs = 0;

        // Llamada a acciones que identifican las variables
        // TokenSize es una acción muy similar al cuantificador.
        TokenSize( i + 1 , size , t );
        Kernel( i + 1 , ind , t , d , size);

        // Verificación y corrección de errores.
        if ( i + size + 1 < t.length() ) {

            // Este ciclo verifica la existencia de errores y mediante el uso de
            // flags omite a la entrada errada
            TokenSize( i + size + 2 , errs , t );
            Kernel( i + size + 2 , errind , t , d , errs);
            if ( d.substr( errind - ( 1 ) , 10 ) == "\t........\t" ) {
                
                // Flags que permiten la eliminación y conteo de errores
                // este condicional viene dado por el carcater "error"
                flag = -1;
                i = i + errs + 1;
                ne = ne + 1;
            }
        };
        if ( flag == 1 ) {
            
            // Se porudce la salida si no hubo ningún error
            proc = proc + d.substr( ind - 1 - ( 1 ) , 1 ); //zi
        };
        i = i + size + 1;  
    }
    while (!( i >= t.length() ));

    // Salida del texto decodificado
    cout << "\nEl texto decodificado es:\n" << proc << endl;
}

void TokenSize( int j , int& s , string t )
{
    // Esta acción mide el tamaño de una subcadena en un string
    // su función es muy similar a la del cuantificador.

    // Inicialición del contador principal.
    s = 0;
    do {
        
        // Incremento del contador según las longitudes de las subacaenas
        // y los carcateres especificados.
        s = s + 1;
    }
    while (!( t.substr( j + s - ( 1 ) , 1 ) == " " || j + s > t.length() )); ///zi
}

void OutputStats( int n , string cp , float tp , int ne , string m , string t )
{
    // Salida de datos estadísticos procesados a partir de datos intermedios.
    cout << "\nCantidad de mensajes transmitidos: " << n
         << "\nCantidad de palabras en cada mensaje (por separado): " + cp
         << "\nPorcentaje de palabras por mensaje: " << endl;

         if ( n != 0 ) {

            //Se verifica un deniminador no nulo
            cout << ( tp / n ) * 100 << " %" << endl;
         } else {

            // Mensaje por defecto.
            cout << "\nNo se ha transmitido ningun mensaje."  << endl;
         }
    cout << "\nCantidad de errores transmitidos: " << ne
         << "\nCadena(s) con el (los) mensaje(s) transmitido(s) en texto:\n" << t
         << "\nCadena(s) con el (los) mensaje(s) transmitido(s) en morse:\n" << m
         << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                             CODIGO RESIDUAL                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void InputEntero( string prompt , int& in , int min , int max , string con)
{    
    // Esta acción maneja las entradas de datos enteros incluyendo la
    // solicitud de datos y la validadción en base a una serie de
    // parámetros entre los que se incluyen los valores máximos y mínimos.
    cout << prompt << endl;
    do {
        
        // Ciclo de validación basada en valores máximos y mínimos
        // Solicitud de datos
        string n; getline( cin,  n ); in = atoi( n.c_str() );
        if ( !( in >= min && in <= max ) ) {

            // Solicitud de correción personalizable.
            cout << con << endl;
        };
    }
    while (!( in >= min && in <= max ));
}

void WordLenght( int j, int& s, string t )
{
    // Esta acción mide el tamaño de una subcadena en un string
    // su función es muy similar a la del cuantificador.

    // Inicialición del contador principal.
    s = 0;
    do {
        
        // Incremento del contador según las longitudes de las subacaenas
        // y los carcateres especificados.
        if ( t.substr( j - ( 1 ) , 1 ) == " " || t.substr( j - ( 1 ) , 1 ) == "\t" )
        {
            s = s + 1;
        }        
    }
    while (!( t.substr( j + s - ( 1 ) , 1 ) == " " || j + s > t.length() )); ///zi
}

void InputString( string prompt , string& t , int min , int max , string con, string d, int size )
{
    // Esta acción maneja todas las entradas de dato tipo string.
    // Se incluye solicitud de datos y validación.
    // Este procedmiento se diseño con la finalidad de ser altamente
    // reutilizable.

    // Declaración de variables.
    int ind, flag, i;

    // Procesamiento: Se comienzo mostrarndo el mensaje de solicitud
    // El mensaje de solicitud se obtiene como parametro.
    cout << prompt << endl;
    do {

        // Este ciclo es un ciclo de validación.
        // Inicialización de contadores.
        flag = 0; i = 0;

        // Procesamiento: se comienza solicitando el texto de entrada.
        getline( cin, t );
        do {

            // Este ciclo verifica cada letra de la entrada
            // el kernel es una acción que permite identificar la
            // posición relativa de un caracter en una cadena.
            Kernel( i + 1, ind , t , d , size );
            if (!( ( t.length() >= min && t.length() <= max ) && ind < d.length() - 1 )) {

                // En este condicional se verifica la longitud de la
                // cadena, los límites son personalizbles
                flag = -1;
            };
            i = i + size + 1;
        }
        while (!( i >= t.length() ));

        if ( flag == -1 ) {
            
            // Este condicional muestra un mensaje de corrección de ser necesario.
            cout << con << endl;
        };
    }
    while (!( flag != -1 ));
}