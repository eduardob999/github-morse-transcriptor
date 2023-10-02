//---------------------------------------------------------------------//
//                                                                     //
//                    Transcriptor de Código Morse                     //
//                                                                     //
//---------------------------------------------------------------------//
// Codigo finalizado el día 11/9/23
// Programa desarrollado por Eduardo Bogado
// Universidad Central de Venezuela
// Github user eduardob999
// Prof. Yusneiyi Carballo.

// Librerías

# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <fstream>
# include <vector>

// namespace

using namespace std;

// Firmas de procedimeintos

bool CheckFile( string name );

// Clases

class Menu {

    // Atributos

    protected:

        // Mensajes al usuario y diccionarios

        string prompt;
        string condition;
        string input;
        string dictionary;
        string confirmation;

        // Contadores para la traducción de texto a morse
        
        int cantmsg;
        int palen;
        string cantpal;
        float totpal;
        string procesed;
        string texto;

        // Contadores para la traducción de morse a texto

        int cantmorse;
        string cantpalmor;
        float totpalmor;
        int nerror;
        string morsefinal;
        string converted;
        string aux;

        // Procesamiento de archivos

        string sorted;

    // Métodos

    public:

        // Constructor

        Menu () {

            cantmsg = 0;
            cantmorse = 0;
            totpal = 0;
            totpalmor = 0;
            nerror = 0;
            palen = 0;
            cantpal = "";
            morsefinal = "";
            texto = "";

        }

        // Operaciones
        
        void Input( int min, int max, bool word ) {
            
            // Esta acción maneja todas las entradas de dato tipo string.
            // Se incluye solicitud de datos y validación.
            // Este procedmiento se diseño con la finalidad de ser altamente
            // reutilizable.

            // Declaración de variables.

            int ind, size, flag, i, dummy;

            // Procesamiento: Se comienzo mostrarndo el mensaje de solicitud
            // El mensaje de solicitud se obtiene como parametro.

            cout << prompt << endl;

            do {

                // Este ciclo es un ciclo de validación.
                // Inicialización de contadores.

                flag = 0;
                size = 0;

                // Procesamiento: se comienza solicitando el texto de entrada.

                getline( cin, input );

                if (input.length() >= min && input.length() <= max) {

                    // En este condicional se verifica la longitud de la
                    // cadena, los límites son personalizbles y se valida la entrada

                    for ( i = 0; i < input.length() ; i++) {
                        
                        if (word) {

                            SearchWord( i, ind, size, dummy);

                        } else {
                            
                            Search( i, ind, 1 );

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

                    cout << condition << endl;

                }

            } while (!( flag != -1 ));

        }

        void InputFile( string filename ) {

            // Se lleva a cabo la lectura, codificación y respaldo del archivo filename
            // Declaración e inicialización de variables

            fstream file;
            bool start;
            string dummy;
            start = false;
            input = "";

            // Lectura del archivo entradaT.txt

            file.open( filename, ios::in );
            file.peek();

            do {

                // Se ubica el apuntador en la primera línea a leer.

                getline( file, dummy );
                file.peek();

            } while ( dummy.substr( 0,2 ) == "//" );

            input = input + dummy + "#";

            do {

                // Se almaneca todo el archivo en la variable input

                getline( file, dummy );
                input = input + dummy + "#";
                file.peek();

            } while (!( file.peek() == EOF ));

            file.close();
            
        }

        void SaveFile( string filename, string content ) {

            ofstream file( filename );
            file << content;
            file.close();

        }

        void Search( int j, int& ind, int size ) {
            
            // El buscador identifica la ubicación relativa de una cadena de caracteres en otra
            // y le asigna un índice entero.

            // Declaración e inicialización de contadores

            int k;
            ind = 0; 
            k = 0;

            // Procesamiento y generación del índice.

            do {
                
                // Este ciclo encuentra el valor del índice según las coincidencias dadas.

                if ( dictionary.substr( k , 1 ) == "\t" ) {

                    ind = ind + 1;

                }

                k = k + 1;

                if ( k + size == dictionary.length() ) {

                    ind = -1;

                }

            } while  (!(  "\t" + input.substr( j , size ) + "\t" == dictionary.substr( k - ( 1 ) , size + 2 ) || ind == -1 ));
        
        }

        void SearchWord( int i, int& ind, int& size, int& length ) {

            // Procesamiento

            if ( input.substr( i, 1 ) == " " || input.substr( i, 1 ) == "#" ) {
                            
                if ( input.substr( i, 1 ) == "#" ) {
                    
                    converted = converted + "\n";
                    cantmorse = cantmorse + 1;
                    palen = palen + 1;

                }
                
                size = i - size;
                Search( i - size, ind, size );
                length = size;
                size = i + 1;

            } else if ( i + 1 == input.length() ) {

                size = i - size + 1;
                Search( i - size + 1, ind, size );
                length = size;
                size = i + 1;

            } else {

                ind = 0;

            }

        }

        bool Check() {

            // Función reutlizable empleada para determinar la condición de salida
            // de un ciclo con finalidad de reutilizar una serie de
            // procedimientos.

            // Declaraciónes de variables.

            string cond, temp1, temp2, temp3;
            int sind, nind, flag;

            // Inicialización de variables.
            
            cond = "\nDebe responder con Si o No (sin acentos)"
            "\nIntroduzca su respuesta nuevamente: ";

            temp1 = prompt;
            temp2 = dictionary;
            temp3 = condition;

            // Solicitud de entrada y procesamiento.

            do {

                //Este es un ciclo de validación.

                prompt = confirmation;
                condition = cond;
                dictionary = "\tSI\tSi\tsI\tsi\tNo\tnO\tNO\tno\t";
                Input( 2, 2, true );
                dictionary = "\tSI\tSi\tsI\tsi\t";
                Search( 0, sind, 2 );
                dictionary = "\tNo\tnO\tNO\tno\t";
                Search( 0, nind, 2 );

                if ( sind != -1  ) {

                    // Este condicional verifca el resultado positivo.

                    prompt = temp1;
                    dictionary = temp2;
                    condition = temp3;  
                    return false;

                } else {

                    if ( nind != -1 ) {

                    // Este condicional verifca el resultado negativo.

                    prompt = temp1;
                    dictionary = temp2;
                    condition = temp3;  
                    return true;

                    } else {

                        // En caso no definido se solicitan los datos nuevamente.
                        cout << cond << endl;

                    }

                }

            } while ( sind == -1 && nind == -1);

            return false;

        }

};

class Team : public Menu {

    // Métodos
    
    public:
        
        Team () {
            
            // Opción 1 - Identificación del equipo.
            
            string dummy;

            // Inicialización de mensjaes

            prompt = "\nOpcion 1 - Integrantes del Equipo."
            "\n"
            "\nUniversidad Central de Venezuela"
            "\nFacultad de Ciencias"
            "\nEscuela de Computacion"
            "\nAlgoritmos y Programacion. Sem I-2023."
            "\n"
            "\nEduardo Alfonso Bogado Rojas"
            "\nC.I: v-26.818.715"
            "\n"
            "\nPresione ENTER para volver al menu anterior.";

            cout << prompt << endl;
            getline( cin, dummy );
            
        }

};

class Interpreter : public Menu {

    // Atributos

    protected:

        vector<vector<string>> interpreter;
        int n;
        int m;

    // Métodos

    public:

        // Constructor

        Interpreter() {
            
            // Declaración del archivo e inicialización del diccionario

            fstream file;
            dictionary = "\t";
            
            // Declaración de dimensiones de la matriz (m filas, n columnas)

            n = 2;
            m = 0;

            interpreter.resize(n);

            // Inicilaización de matriz interprete

            file.open( "morse.txt", ios::in );
            file.peek();

            do
            {
                
                // Redimensionar la matriz
                m = m + 1;
                interpreter[0].resize(m);
                interpreter[1].resize(m);

                getline( file,  interpreter[0][m-1], '\t' );
                getline( file, interpreter[1][m-1], '\n' );
                file.peek();

            } while (!( file.peek() == EOF ));

            file.close();
                  
        }

    // Método set

    protected:

        void setDictionary( int row ) {

            // Declaración del contador
            
            int i;

            for ( i = 0; i < m; i++ ) {

                dictionary = dictionary + interpreter[row][i] + "\t";

            }

        }

};

class Encrypter : public Interpreter {

    // Métodos

    public:

        // Constructores

        Encrypter( int& cmsg, string& cpal, float& tpal, string& pro, string& txt) {

            // Contadores

            cantmsg = cmsg;
            cantpal = cpal;
            totpal = tpal;
            procesed = pro;
            texto = txt;
            
            // Inicialización de parámetros

            prompt = "\nOpcion 2 - Transmitir Texto en Codigo Morse"
            "\n"
            "\nEl mensaje no debe incluir mas de 60 caracteres."
            "\nPor favor, introduzca el texto a codificar:";

            condition = "\nEl texto debe tener de 1 a 60 caracteres."
            "\nSe admiten solo caracteres incluidos en la convencion ITU-RM.1677-1"
            "\nLos acentos y tildes no son soportados por esta version del programa"
            "\nPor favor, introduzca nuevamente el texto a codificar:";

            confirmation = "\nDesea transmitir otro mensaje?"
            "\nResponda con Si o No: ";

            setDictionary( 0 );

            do {

                // Este ciclo permite la reutilización del menú
                // sin neecesidad de volver al menú inicial.
                // El procesamiento y traducción de la entrada es llevada a
                // cabo por la acción ConvertText.

                Input( 1, 60, false );
                ConvertText();
                cout << "\nLa Codificacion Morse de \"" << input << "\" es:\n" << procesed << endl;
                texto = texto + input + " - ";

            } while (!( Check() ));

            // Actualización de contadores

            cmsg = cantmsg;
            cpal = cantpal;
            tpal = totpal;
            pro = procesed;
            txt = texto;

        }

        Encrypter( string filename, string out ) {

            // Declaración e inicialización de variables

            string dummy;
            stringstream stream1, stream2, stream3;
            setDictionary( 0 );

            // Procesamiento

            InputFile( filename );
            ConvertText();
            stream1 << ( palen - 1 );
            stream2 << ( cantmsg - 1 );
            stream3 << ( procesed.length() + 6 );

            procesed = "\nDecodificación de Texto a Morse:\n\n" 
                        + procesed +
                        "\n...-.-\n"
                        "\nFinal de la comunicación."
                        "\nSe transmitieron:"
                        "\n- " + stream2.str() + " mensajes"
                        "\n- " + stream1.str() + " palabras"
                        "\n- " + stream3.str() + " caracteres";

            SaveFile( out, procesed );
            cout << "\nLa decodificacion de texto a morse fue guardada satisfactoriamente en el archivo " << out <<
            "\nPresione ENTER para volver al menu anterior." << endl;
            getline( cin, dummy );
        
        }

        // Operaciones

        void ConvertText() {

            // Esta acción procesa las entradas de texto y las convierte en morse.
            // Declaración de variables.

            int i, ind, q; 
            stringstream stream1, stream2;

            // Inicialización de variables.

            procesed = "";

            // Procesamimiento de la cadena de entrada.

            for ( i = 0 ; i < input.length() ; i++ ) {

                // Este ciclo verifica cada letra de la entrada
                // se reutiliza el método search en esta acción

                Search( i, ind, 1 );

                if ( interpreter[1][ind-1] == "/" || i - 1 > input.length() ) {
                    
                    // Este condicional cuenta la cantidad de palabras y las almacena en "palen".

                    palen = palen + 1;

                };

                if ( interpreter[0][ind-1] == "#") {
                    
                    procesed = procesed + "\n";
                    palen = palen + 1;
                    cantmsg = cantmsg + 1;

                } else {
                    
                    procesed = procesed + interpreter[1][ind-1] + " ";

                }
                
            };

            // Procesamiento de datos intermedios.

            stream1 << palen;
            cantmsg = cantmsg + 1;
            stream2 << cantmsg;
            cantpal = cantpal + "- Mensaje " + stream2.str() + ": " + stream1.str() + " palabra(s)\n";
            totpal = totpal + palen;

        }
                
};

class Decrypter : public Interpreter {

    // Métodos

    public:

        // Constructores

        Decrypter( int& cmorse, int& nerr, string& morfin, string& conv, string& cpalmor, float& tpalmor ) {

            // Contadores

            cantmorse = cmorse;
            nerror = nerr;
            morsefinal = morfin;
            converted = conv;
            cantpalmor = cpalmor;
            totpalmor = tpalmor;
            
            // Opción 3 - Decodificación de código Morse a Texto.

            prompt = "\nOpcion 3 - Convertir Codigo Morse en Texto Normal"
            "\n"
            "\nEl mensaje no debe incluir mas de 180 caracteres."
            "\nSe admiten solo caracteres incluidos en la convencion ITU-RM.1677-1"
            "\nPor favor, introduzca la codificacion:";

            condition = "\nEl texto debe tener de 1 a 180 caracteres."
            "\nEl punto o dot viene dado por el caracter \".\"."
            "\nLa linea o dash viene dado por el caracter \"-\"."
            "\nLos acentos y tildes no son soportados por esta version del programa"
            "\nLos caracteres representados deben ir separados por espacios."
            "\nLas palabras vienen separadas por el caracter \"/\"."
            "\nPor favor, introduzca la codificacion nuevamente: ";

            confirmation = "\nDesea convertir otro mensaje?"
            "\nResponda con Si o No:";

            setDictionary( 1 );

            do {

                // Este ciclo permite la reutilización del menú
                // sin neecesidad de volver al menú inicial.
                // El procesamiento y traducción de la entrada es llevada a
                // cabo por la acción ConvertMorse.

                Input( 1, 180, true );
                ConvertMorse();
                cout << "\nEl texto decodificado es:\n" << converted << endl;
                morsefinal = morsefinal + converted + " - ";

            } while (!( Check() ));

            // Actialización de contadores
            
            cmorse = cantmorse;
            nerr = nerror;
            morfin = morsefinal;
            conv = converted;
            cpalmor = cantpalmor;
            tpalmor = totpalmor;

        }

        Decrypter( string filename, string out ) {

            // Declaración e inicialización de variables

            string dummy;
            stringstream stream1, stream2, stream3;
            setDictionary( 1 );

            // Procesamiento

            InputFile( filename );
            ConvertMorse();
            stream1 << ( palen - 1 );
            stream2 << ( cantmorse - 1 );
            stream3 << ( converted.length() + 25 );

            converted = "\nDecodificación de Texto a Morse:\n\n" 
                        + converted +
                        "\nFinal de la comunicacion."
                        "\nSe transmitieron:"
                        "\n- " + stream2.str() + " mensajes"
                        "\n- " + stream1.str() + " palabras"
                        "\n- " + stream3.str() + " caracteres";

            SaveFile( out, converted );
            cout << "\nLa decodificacion de texto a morse fue guardada satisfactoriamente en el archivo " << out <<
            "\nPresione ENTER para volver al menu anterior." << endl;
            getline( cin, dummy );
        
        }

        // Operaciones

        void ConvertMorse() {
            
            // Esta acción procesa las entradas de codigo morse y las convierte en
            // cadenas de caracteres con texto.
            
            // Declaración de variables.

            string prompt, cond, temp;
            stringstream stream1, stream2;
            int i, size, ind, errind, length;

            // Inicialización de contadores indices y datos intermedios:


            converted = "";
            temp = "";
            i = 0;
            size = 0;
            nerror = 0;
            palen = 0;

            // Procesa y muestra la salida.

            for ( i = 0; i < input.length() ; i++) {
                
                // Este ciclo realiza la traducción del código morse al texto.
                
                // Inicialización de flags y datos intermedios.
                // Los datos intermedios son datos que se utilizan para
                // operaciones matemáticas no se muestran al usuario sin ser
                // procesados.

                // Llamada a acciones que identifican las variables se reutiliza
                // el método SearchWord.

                SearchWord( i, ind, size, length );

                // Verificación y corrección de errores.

                if ( interpreter[1][ind-1] == "........" ) {
                    
                    // Aumenta la cantidad de errores

                    nerror = nerror + 1;
                    converted = aux;
                    cout << "\nSe elimino una palabra con error." << endl;

                } else if ( ind != 0 && ind != -1 ) {

                    converted = converted + temp + interpreter[0][ind-1];

                    if ( interpreter[1][ind-1] == "/" || i + 1 == input.length() ) {
                    
                        // Este condicional cuenta la cantidad de palabras y las almacena en "palen".

                        palen = palen + 1;
                        aux = converted + temp + interpreter[0][ind-1];

                    };

                }

            }

            // Actualización de contadores

            if ( !(interpreter[1][ind-1] == "........") ) {
                    
                stream1 << palen;
                cantmorse = cantmorse + 1;
                stream2 << cantmorse;
                cantpalmor = cantpalmor + "- Mensaje " + stream2.str() + ": " + stream1.str() + " palabra(s)\n";
                totpalmor = totpalmor + palen;

            }

        }
                
};

class Special : public Interpreter {

    // Atributos

    private:

        vector<vector<string>> matrix;
        int n;
        int m;
    
    // Métodos

    public:

        // Constructores

        Special( string filename ) {

            // Declaración e inicialización de variables

            int i, sum;
            i = 0;
            sum = 0;

            prompt = "\nCual ciudad desea consultar?";

            condition = "\nLa ciudad ingresada debe coincidir de manera exacta con alguna de las incluidas en el archivo de entrada.";

            // Procesamiento

            cout << "\nOpcion 5.4 - Procesamiento y calculos"
                    "\n"
                    "\nCiudad o ciudades con la menor y la mayor temperatura en grados Celcius:" << endl;

            ReadMatrix( filename );
            Sort( false );

            do {

                cout << "\nMenor:" + matrix[0][i] + ", " + matrix[1][i] << endl;
                i = i + 1;

            } while ( matrix[1][i] == matrix[1][i-1] && i < m );

            i = m;
            
            do {

                cout << "\nMayor:" + matrix[0][i-1] + ", " + matrix[1][i-1] << endl;
                i = i - 1;

            } while ( matrix[1][i-1] == matrix[1][i] && i > 0 );

            for ( i = 0; i < m; i++)
            {
                sum = sum + atoi( matrix[1][i].c_str() );
            }
            
            cout << "\n- Temperatura promedio:\n" <<
                    sum / m << " grados Celcius." << endl;

            dictionary = "\t";

            for ( i = 0; i < m; i++)
            {
                dictionary = dictionary + matrix[0][i] + "\t";
            }

            Input( 1, 10, true );

            i = 0;

            do {

                i = i + 1;

            } while ( !( input == matrix[0][i] ) );

            cout << "La temperatura en " + input + " es: " + matrix[1][i] + " grados." << endl;

            input = "La temperatura en " + matrix[0][i] + " es: " + matrix[1][i] + " grados.";

            dictionary = "\t";
            
            setDictionary( 0 );

            ConvertText();

            cout << procesed;

        }

        Special( string filename, string out ) {

            // Declaración e inicialización de variables

            string dummy, combined;
            combined = "";


            // Procesamiento

            ReadMatrix( filename );
            Sort( true );

            combined = "Listado de ciudades y temperaturas en grados Celsius, ordenados por ciudad:\n\n" 
            + sorted + "\n";

            Sort( false );

            combined = combined + "Listado de ciudades y temperaturas en grados Celsius, ordenados por temperatura:\n\n" 
            + sorted;

            cout << combined << endl;
            SaveFile( out, combined );

            cout << "\nEl resultado del ordenamiento fue guardado satisfactoriamente en el archivo " << out <<
            "\nPresione ENTER para volver al menu anterior." << endl;

            getline( cin, dummy );

        }

        // Operaciones

        void ReadMatrix( string filename ) {

            // Declaración de variables

            fstream file;
            string dummy;
            int i;
            
            // Declaración de dimensiones de la matriz (m filas, n columnas)

            n = 2;
            m = 0;

            matrix.resize(n);

            // Inicilaización de matriz interprete

            file.open( filename, ios::in );
            file.peek();

            for ( i = 0; i < 2; i++)
            {
                
                // Se saltan las líneas de comentarios

                getline( file,  dummy, '\n' );

            }
            
            do {
                
                // Redimensionar la matriz
                m = m + 1;
                matrix[0].resize(m);
                matrix[1].resize(m);

                getline( file,  matrix[0][m-1], ',' );
                getline( file,  dummy, ' ' );
                getline( file, matrix[1][m-1], '\n' );
                file.peek();

            } while (!( file.peek() == EOF ));

            file.close();
                  
        }

        void Sort( bool city ) {

            // Declaración e inicialización de veriables

            int i, j;
            string temp;
            sorted = "";


            if ( city ) {

                for ( i = 0; i < m - 1; i++) {

                    for ( j = 0; j < m - 1; j++) {

                        if ( matrix[0][j] > matrix[0][j+1] ) {

                            temp = matrix[0][j]; matrix[0][j] = matrix[0][j+1]; matrix[0][j+1] = temp;
                            temp = matrix[1][j]; matrix[1][j] = matrix[1][j+1]; matrix[1][j+1] = temp;
                            
                        }
                        
                    }
                
                }

            } else {

                for ( i = 0; i < m - 1; i++) {

                    for ( j = 0; j < m - 1; j++) {

                        if ( atoi( matrix[1][j].c_str() ) > atoi( matrix[1][j+1].c_str() ) ) {

                            temp = matrix[0][j]; matrix[0][j] = matrix[0][j+1]; matrix[0][j+1] = temp;
                            temp = matrix[1][j]; matrix[1][j] = matrix[1][j+1]; matrix[1][j+1] = temp;
                            
                        }
                        
                    }
                
                }

            }

            for ( j = 0; j < m; j++) {

                    sorted = sorted + matrix[0][j] + ", " + matrix[1][j] + "\n";
            
            }
 
        }

        void ConvertText() {

            // Esta acción procesa las entradas de texto y las convierte en morse.
            // Declaración de variables.

            int i, ind, q; 
            stringstream stream1, stream2;

            // Inicialización de variables.

            procesed = "";

            // Procesamimiento de la cadena de entrada.

            for ( i = 0 ; i < input.length() ; i++ ) {

                // Este ciclo verifica cada letra de la entrada
                // se reutiliza el método search en esta acción

                Search( i, ind, 1 );

                if ( interpreter[1][ind-1] == "/" || i - 1 > input.length() ) {
                    
                    // Este condicional cuenta la cantidad de palabras y las almacena en "palen".

                    palen = palen + 1;

                };

                if ( interpreter[0][ind-1] == "#") {
                    
                    procesed = procesed + "\n";
                    palen = palen + 1;
                    cantmsg = cantmsg + 1;

                } else {
                    
                    procesed = procesed + interpreter[1][ind-1] + " ";

                }
                
            };

            // Procesamiento de datos intermedios.

            stream1 << palen;
            cantmsg = cantmsg + 1;
            stream2 << cantmsg;
            cantpal = cantpal + "- Mensaje " + stream2.str() + ": " + stream1.str() + " palabra(s)\n";
            totpal = totpal + palen;

        }
         
};

class Conversion : public Menu {

    // Métodos
    
    public:

        // Constructor
        
        Conversion () {
            
            // Opción 1 - Identificación del equipo.
            
            string dummy;

            // Inicialización de mensjaes

            prompt = "\nOpcion 5 - Conversion de mensajes desde archivos."
            "\n"
            "\nMenu:"
            "\n  1.  Leer mensaje en texto"
            "\n  2.  Leer mensaje en Codigo Morse"
            "\n  3.  Ordenar y listar archivo tempEntrada.txt"
            "\n  4.  Procesamiento y calculos del archivo tempEntrada.txt"
            "\n  5.  Volver al menu principal"
            "\n"
            "\nPor favor, indique su opcion:";

            condition = "\nDebe ingresar un numero entero entre 1 y 5. "
            "\nIngrese su opcion nuevamente:";

            dictionary = "\t1\t2\t3\t4\t5\t";

            // Procesamiento

            do {
        
                // En este ciclo se controla la ejecicón y salida del programa
                // la variable inp se emplea como bandera

                Input( 1, 1, false );

                switch( atoi( input.c_str() )) {

                    case 1: {

                        Encrypter e2( "entradaT.txt", "salidaT.txt" );
                        break;
                    
                    }

                    case 2: {

                        Decrypter d2( "entradaM.txt",  "salidaM.txt" );
                        break;
                    
                    }

                    case 3: {

                        Special s1( "tempEntradaT.txt", "tempSalidaT.txt" );
                        break;
                    
                    }

                    case 4: {

                        Special s2( "tempEntradaT.txt" );
                        break;
                    
                    }

                    case 5: {

                        break;
                    
                    }

                }

            }
            while ( !( input == "5" ) );
            
        }

};

class Proyecto : public Menu {
    
    // Métodos

    public:
    
        // Constructor

        Proyecto() {
            
            // Inicialización de atributos.

            cout << "\nUniversidad Central de Venezuela"
    		"\nFacultad de Ciencias"
            "\nEscuela de Computacion"
            "\nAlgoritmos y Programacion. Sem I-2023."
            "\nProyecto 1. Codigo Morse Internacional." << endl;
            

            prompt = "\nMenu pricnpial:"
            "\n  1.  Integrantes de Equipo"
            "\n  2.  Transmitir Texto en Codigo Morse"
            "\n  3.  Convertir Codigo Morse a Texto"
            "\n  4.  Estadisticas"
            "\n  5.  Conversion de mensajes desde archivos"
            "\n  6.  Salir"
            "\n"
            "\nPor favor, indique su opcion:";

            condition = "\nDebe ingresar un numero entero entre 1 y 6. "
            "\nIngrese su opcion nuevamente:";

            dictionary = "\t1\t2\t3\t4\t5\t6\t";

            //Procesamiento

            do {
        
                // En este ciclo se controla la ejecicón y salida del programa
                // la variable inp se emplea como bandera

                Input( 1, 1, false );
                Select();

            }
            while ( !( input == "6" ) );

        }

        void Select()
        {

            // En este procedimiento se maneja el menúi de selección
            // Declaracion de variables

            string txt, ver, dummy;
            int flag, contm;
            fstream file;

            // Inicialización de los strings correspondientes a los textos y 
            // condiciones de cada menú.

            ver = "\nDesea volver al menu principal?"
                "\nResponda con Sí o No:";
            
            // Selección correspoendiente a las opciones del menú.

            switch( atoi( input.c_str() )) {

                case 1: {

                    Team t1;
                    break;
                
                }

                case 2: {

                    Encrypter e1( cantmsg, cantpal, totpal, procesed, texto );
                    break;
                
                }

                case 3: {

                    Decrypter d1( cantmorse, nerror, morsefinal, converted, cantpalmor, totpalmor);
                    break;
                
                }

                case 4: {
                    
                    // Opción 4 - Estadística.

                    cout << "\nOpcion 4 - Estadisticas" << endl;
                    PrintStats();
                    cout << "\nPresione ENTER para volver al menu princpial" << endl;
                    getline( cin, dummy );

                    break;
                
                }

                case 5: {
                    
                    Conversion c1;
                    break;
                
                }

                case 6: {
                    
                    // Opción 6 - Salida y resumen de actividad.
                    // Se reutiliza la acción OutputStat para mostrar
                    // el resumen de actividad.

                    cout << "\nOpcion 5 - Salir. A continuacion un resumen de su actividad:" << endl;
                    PrintStats();
                    cout << "\nGracias por usar este programa.\n" << endl;
                    input = "6";
                
                }

            };

        };

        void PrintStats()
        {
            
            // Salida de datos estadísticos procesados a partir de datos intermedios.

            cout << "\n4.1 Cantidad de mensajes transmitidos"
            "\nEn texto: " << cantmsg <<
            "\nEn Codigo Morse: " << cantmorse << endl;

            cout << "\n4.2 Cantidad de palabras por mensaje"
            "\nEn texto:\n" << cantpal <<
            "En Morse:\n" << cantpalmor << endl;

            cout << "\n4.3 Promedio de palabras por mensaje: "
            << "\nEn texto: ";

                if ( cantmsg != 0 ) {

                    //Se verifica un deniminador no nulo

                    cout << ( totpal / cantmsg ) << endl;

                } else {

                    // Mensaje por defecto.

                    cout << "No se ha transmitido ningun mensaje."  << endl;

                }

            cout << "En Morse: ";

                if ( cantmorse != 0 ) {

                    //Se verifica un deniminador no nulo

                    cout << ( totpalmor / cantmorse ) << endl;

                } else {

                    // Mensaje por defecto.

                    cout << "No se ha transmitido ningun mensaje."  << endl;

                }


            cout << "\n4.4 Cantidad de errores en la transmision de mensajes en Codigo Morse:\n" << nerror
                << "\n\n4.5 Cadena(s) con el (los) mensaje(s) transmitido(s)"
                << "\nEn texto:\n" << texto
                << "\nEn morse, traducido a texto:\n" << morsefinal
                << "\n\nFinal de las estadisticas." << endl;

        }

};
  
// Acción Principal

int main()
{
    
    // Se verifican y validan los archivos auxiliares

    bool error = false;
    error = !CheckFile( "morse.txt" ) || error;
    error = !CheckFile( "entradaT.txt" ) || error;
    error = !CheckFile( "entradaM.txt" ) || error;
    error = !CheckFile( "tempEntradaT.txt" ) || error;
    if (error) { return 0; }

    // Contrucción de instancia de clase proyecto

    Proyecto p1;

    return 0;

}

// Funciones

bool CheckFile( string name ) {

    fstream file;
    
    // Verificacion de archivos auxiliares
	file.open( name, ios::in );

	if (!file) {

		cout << "\nArchivo " + name + " no encontrado en el directorio actual "
                "por favor agreguelo al directorio actual.\n" << endl;;
        file.close();
        return false;

	} else if ( file.peek() == EOF ) {

        cout << "\nEl archivo " + name + " se encuentra vacío. Por favor "
                "incluya un archivo " + name + " válido al directorio actual.\n" << endl;
        file.close();
		return false;

    } else {

        file.close();
        return true;

    }

}