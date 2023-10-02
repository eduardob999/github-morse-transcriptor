//-----------------------------------------------------------------------
//
//                    Transcriptor de Código Morse
//
//------------------------------------------------------------------------
// Codigo finalizado el día 18/8/23
// Programa desarrollado por Eduardo Bogado
// Universidad Central de Venezuela
// Github user eduardob999

////// C++ No puede trabajar con acentos, corregir en version final ///////

//Librerías

# include <iostream>
# include <string>
using namespace std;

// Firma de procedimientos

void InputEntero( string prompt , int& in , int min , int max , string con);
void InputString( string prompt , string& t , int min , int max , string con, string d, int size);
void Seleccion( int& in , int& cmt , string& cpal, float& tpal , int& nerr , string& morse, string& msg );
void OutputMorse( string t , string d , int& nm , string& np , float& tp , string& proc);
void Indexador( int j, int& ind, string t , string d , int size );
void Cuantificador( int k , int& q , string t , string d );
bool Verificador( string p );
void OutputTexto( string t , string d , int& ne );
void TokenSize( int j, int& size , string t );
void OutputStats( int n , string cp , float tp , int ne , string m , string t );


// Accíón principal: Traducción del pseudo 

int main()           //////// sustituye input integer por input string, crea nuevos diccionario para las entradas de 2
{                       /// añadir un verificador al menu 1
                    // incluir simbolos y numeros
                    // arreglar outpu con 7 puntos ....... a texto
                    // cambiar n de outpu stat a integer
                    // que no sea necsario que salgan barras dobles al final de la cadena completa
                    // poner bonito el outpu stat
    // Declaración de variables

    int inp, cantmsg, nerror; 
    string menu0, cond0, cantpal, morsefinal, texto;
    float totpal;

    cantmsg = 0;
    cantpal = "";
    totpal = 0;
    nerror = 0;
    morsefinal = "";
    texto = "";

    // Inicialización de variables

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
    
    // Procedimientos

    do {

        InputEntero( menu0 , inp , 1 , 5 , cond0 );

        Seleccion( inp , cantmsg , cantpal , totpal , nerror , morsefinal, texto );

    }
    while ( !( inp == 5 ) );

    return 0;

}

void InputEntero( string prompt , int& in , int min , int max , string con)
{    
    // Procesamiento

    cout << prompt << endl;

    do {

        string n; getline( cin,  n ); in = stoi( n );

        if ( !( in >= min && in <= max ) ) {
            
            cout << con << endl;

        };

    }
    while ( !( in >= min && in <= max ) );

}

void Seleccion( int& in , int& cmt , string& cpal, float& tpal , int& nerr , string& morse, string& msg )
{
    // Declaracion

    string txt, dic, ver, ver2, ver3, menu1, cond1, menu2, cond2, menu3, cond3, proces;
    int flag;

    //inicialización

    dic = "_a_.-_i_.._r_.-._b_-..._j_.---_s_..._c_-.-._k_-.-_t_-_d_-.._l_.-.._"
          "u_..-_e_._m_--_v_...-_è_..-.._n_-._w_.--_f_..-._o_---_x_-..-_g_--._"
          "p_.--._y_-.--_h_...._q_--.-_z_--.._ _/_error_........_";

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
            "\nEl mensaje no debe incluir más de 30 caracteres."
            "\nPor favor, introduzca el texto a codificar:";

    cond2 = "\nEl texto debe tener de 1 a 30 caracteres."
            "\nEvite el uso de acentos ajenos al idioma español."
            "\nSe admiten solo caracteres incluidos en la convención ITU-RM.1677-1"
            "\nPor favor, introduzca nuevamente el texto a codificar:";

    menu3 = "\nOpción 3 - Convertir Código Morse en Texto Normal"
            "\n"
            "\nEl mensaje no debe incluir más de 50 caracteres."
            "\nSe admiten solo caracteres incluidos en la convención ITU-RM.1677-1"
            "\nPor favor, introduzca la codificación:";

    cond3 = "\nEl texto debe tener de 1 a 50 caracteres."
            "\nEl punto, señal corta o dot viene dado por el caracter \".\"."
            "\nLa línea, señal larga o dash viene dado por el caracter \"-\"."
            "\nLas letras deben ir separadas por espacios."
            "\nLas palabras vienen separadas por el caracter \"/\"."
            "\nPor favor, introduzca la codificación nuevamente: ";

    switch(in) {
    case 1:

        InputEntero( menu1 , in , 1 , 1 , cond1 );
        break;

    case 2:

        do {
            InputString( menu2, txt, 1, 30, cond2, dic, 1 );
            OutputMorse( txt, dic, cmt, cpal, tpal, proces );
            msg = msg + txt + "\n";
            morse = morse + proces + " //";
        }
        while (!( Verificador( ver2 ) ));

        break;

    case 3:

        do {
            InputString( menu3 , txt , 1 , 50 , cond3, "_._-_/_ _", 1 ); ///modificarlo para incluir una biblioteca aparte
            OutputTexto( txt , dic , nerr );
        }
        while (!( Verificador( ver3 ) ));
        break;

    case 4:
        
        do {
            cout << "\nOpción 4 - Estadísticas" << endl;
            OutputStats( cmt , cpal , tpal, nerr, morse, msg );
        }
        while (!(!(  Verificador( ver ) )));
        break;

    case 5:

        cout << "\nOpción 5 - Salir. A continuación un resumen de su actividad:" << endl;
        OutputStats( cmt , cpal , tpal, nerr, morse, msg );
        cout << "\nGracias por usar este programa." << endl;
        in = 5;

    }
    
}

void InputString( string prompt , string& t , int min , int max , string con, string d, int size )
{
    // Declaración
    
    int ind, flag, i;

    // Inicialización

    // Procesamiento

        cout << prompt << endl;

    do {

        // Inicialización 
        
        flag = 0; i = 0;

        // Procesamiento

        getline( cin, t );

        do {

            Indexador( i + 1, ind , t , d , size );
            
            if (!( ( t.length() >= min && t.length() <= max ) && ind < d.length() - 1 )) {

                flag = -1;
            
            };

            i = i + size + 1;

        }
        while (!( i >= t.length() ));

        if ( flag == -1 ) {
    
            cout << con << endl;

        };

    }
    while (!( flag != -1 ));

}

void OutputMorse( string t , string d , int& nm , string& np , float& tp , string& proc)
{
    // Declaración

    string selec; int i, ind, q, palen;

    // Inicialización

    proc = "";
    palen = 0;

    // Procesa y muestra la salida

    for ( i = 1 ; i <= t.length() ; i++ ) {

        Indexador( i , ind , t , d , 1 );

        Cuantificador( ind , q , t , d );

        if ( d.substr( ind + 3 - ( 1 ) , q ) == "/" || i + 1 > t.length() ) { //zi
            
            palen = palen + 1;

        };

        proc = proc + d.substr( ind + 3 - ( 1 ) , q ) + " "; //zi

    };

    nm = nm + 1;

    np = np + to_string( palen ) + " ";

    tp = tp + palen;

    // Salida

    cout << "\nLa Codificación Morse de " << t << " es:\n" << proc << endl;

}

void Indexador( int j, int& ind , string t , string d , int size )
{
    // Init

    ind = 0;

    //Procesamiento

    do {

        ind = ind + 1 ;

    }
    while  (!(  "_" + t.substr( j - ( 1 ) , size ) + "_" == d.substr( ind - ( 1 ) , size + 2 ) ||  ind + size > d.length()  ));  //zi

}

void Cuantificador( int ind , int& q , string t , string d )
{
    q = 0;

    do  {
        
        q = q + 1;

    }
    while (!( ind + q + 2 > d.length() || ( d.substr( ind + q + 2 - ( 1 ) , 1 ) != "." && d.substr( ind + q + 2 - ( 1 ) , 1 ) != "-"  && d.substr( ind + q + 2 - ( 1 ) , 1 ) != "/" ) )); ///zi

    q = q - 1;
}
         
bool Verificador( string p )
{
    // Declaración

    string cond, ans, acc, rej; int sind, nind, flag;

    // Init

    acc = "_SI_Si_sI_si_Sí_sÍ_SÍ_sí_";
    rej = "_No_nO_NO_no_";

    cond = "\nDebe responder con Sí o No"
           "\nIntroduzca su respuesta nuevamente: ";

    // Procesamiento

    do {

        InputString( p , ans , 2 , 2 , cond, acc + rej, 2);

        Indexador( 1 , sind , ans , acc , 2);

        Indexador( 1 , nind , ans , rej , 2);

        if ( sind < acc.length() - 1 ) {
                
            return false;

        } else {

            if ( nind < rej.length() - 1 ) {
                
            return true;

            } else {

                cout << cond << endl;

                flag = -1;
            }

        };

    }
    while (!( flag != -1 ));

};

void OutputTexto( string t , string d , int& ne )
{
    // Declaración

    string prompt, cond, selec, proc; int i, size, ind, q, flag, errs, errind;

    // Inicialización
    
    proc = "";

    // Procesa y muestra la salida

    i = 0;

    do {

        flag = 1;
        errs = 0;

        TokenSize( i + 1 , size , t );

        Indexador( i + 1 , ind , t , d , size);

        // Verificación de error
        if ( i + size + 1 < t.length() ) {

            TokenSize( i + size + 2 , errs , t );

            Indexador( i + size + 2 , errind , t , d , errs);

            if ( d.substr( errind - ( 1 ) , 10 ) == "_........_" ) {
                
                flag = -1;
                i = i + errs + 1;
                ne = ne + 1;

            }

        };
        
        if ( flag == 1 ) {

            proc = proc + d.substr( ind - 1 - ( 1 ) , 1 ); //zi

        };
        
        i = i + size + 1;
        
    }
    while (!( i >= t.length() ));

    // Salida

    cout << "\nEl texto decodificado es:\n" << proc << endl;

}

void TokenSize( int j , int& s , string t )
{
    // Inicialización

    s = 0;

    // Procesamiento

    do {

        s = s + 1;

    }
    while (!( t.substr( j + s - ( 1 ) , 1 ) == " " || j + s > t.length() )); ///zi

}

void OutputStats( int n , string cp , float tp , int ne , string m , string t )
{
    //

    cout << "\nCantidad de mensajes transmitidos: " << n
         << "\nCantidad de palabras en cada mensaje (por separado): " + cp
         << "\nPorcentaje de palabras por mensaje: " << endl;

         if ( n != 0 ) {

            cout << ( tp / n ) * 100 << " %" << endl;
         
         } else {

            cout << "\nNo se ha transmitido ningun mensaje."  << endl;

         }
         
    cout << "\nCantidad de errores transmitidos: " << ne
         << "\nCadena(s) con el (los) mensaje(s) transmitido(s) en texto:\n" << t
         << "\nCadena(s) con el (los) mensaje(s) transmitido(s) en morse:\n" << m
         << endl;

}
            