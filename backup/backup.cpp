// Acción 2

        q = 0;

        do  {
            
            q = q + 1;

        }
        while (!( ind + q + 1 > d.length() || d.substr( ind + q , 1 ) != "." || d.substr( ind + q , 1 ) != "-"  || d.substr( ind + q , 1 ) != "/" ) );

        proc = proc + d.substr( ind + 1 , q ) + " ";
        
        q = 0;




    proc = proc + "/";

    cout << "\nLa Codificación Morse de " << t << " es:\n" << proc << endl;

    // Indexador
            
            ind = 0;

            do {

                ind = ind + 1 ;
            
            }
            while  (!(  t.substr( i - ( 1 ) , 1 ) == d.substr( ind - ( 1 ) , 1 ) ||  ind + 1 > d.length()  ));  //zi


/quant

q = 0;

        do  {
            
            q = q + 1;

        }
        while (!( ind + q + 2 > d.length() || ( d.substr( ind + q + 1 - ( 1 ) , 1 ) != "." && d.substr( ind + q + 1 - ( 1 ) , 1 ) != "-"  && d.substr( ind + q + 1 - ( 1 ) , 1 ) != "/" ) )); ///zi

        q = q - 1;

// Decripter backup

for ( i = 1 ; i <= t.length() ; i++ ) {
        
        TokenSize( i , size , t );
        
        cout << size << endl; ///erase

        Indexador( i , ind , t , d , size);

        cout << ind << endl; ///erase

        cout << d.substr( ind - 1 - ( 1 ) , 1 ) << endl; ///erase

        proc = proc + d.substr( ind - 1 - ( 1 ) , 1 ); //zi

    };

// Decripter

i = 0;

do {

    TokenSize( i , size , t );
    
    cout << size << endl; ///erase

    Indexador( i , ind , t , d , size);

    cout << ind << endl; ///erase

    cout << d.substr( ind - 1 - ( 1 ) , 1 ) << endl; ///erase

    proc = proc + d.substr( ind - 1 - ( 1 ) , 1 ); //zi

    i = i + size;
}
while (!( i = t.length() ));


void Verificador( int& f ) //backup
{
    // Declaración

    string prompt, cond, ans, afirm, negat; int i, si, no;

    // Init

    i = 0; si = 0; no = 0;
    afirm = " SI Si sI si Sí sÍ SÍ sí";
    negat = " No nO NO no";

    prompt = "\n¿Desea transmitir otro mensaje?"
             "\nResponda con Sí o No: ";

    cond = "\nDebe responder con Sí o No"
           "\nIntroduzca su respuesta nuevamente: ";

    // Procesamiento

    cout << prompt << endl;

    do {

        getline( cin, ans );

        for ( i = 1 ; i <= 2 ; i = i + 2 ) {

            Indexador( i , si , ans , afirm , 2);


        };

        i = 0;

        for ( i = 1 ; i <= 2 ; i = i + 2 ) {

            Indexador( i , no , ans , negat , 2);

            cout << no << endl; /// arreglar

        };

        if ( si < afirm.length() - (1) && no == negat.length() - (1) ) { //zi
                
            f = 1;

        } else {

            if ( si == afirm.length() - (1) && no < negat.length() - (1) ) { //zi
                
            f = 0;

            } else {

                cout << cond << endl;

                f = -1;
            }

        };

    }
    while (!( f != -1 ));

}

bool Verificador()
{
    // Declaración

    string prompt, cond, ans; int flag;

    // Init

    flag = -1;

    prompt = "\n¿Desea transmitir otro mensaje?"
             "\nResponda con Sí o No: ";

    cond = "\nDebe responder con Sí o No"
           "\nIntroduzca su respuesta nuevamente: ";

    // Procesamiento

    cout << prompt << endl;

    do {

        InputString( prompt , txt , 1 , 2 , cond );

        switch(ans) {

            case Si:
                return false
            break;
            case sI:
                return false
            break;
            case SI:
                return false
            break;
            case si:
                return false
            break;

            case Sí:
                return false
            break;
            case sÍ:
                return false
            break;
            case SÍ:
                return false
            break;
            case sí:
                return false
            break;

            case No:
                return true
            break;
            case nO:
                return true
            break;
            case NO:
                return true
            break;
            case no:
                return true
            break;

                f

        }

    }
    while (!( flag != -1 ));

}
    
    

