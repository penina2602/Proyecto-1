//El presente codigo representa una simulacion completamente funcional de una entidad financiera que le permite a los usuarios autogestinar creditos. Para lograrlo, el usuario debe ingresar su informacion personal y hacer una solicitud.
//Si el usuario cumple con los requisitos podra obtener el credito asi como visualizar una proyeccion de pagos segun el monto del credito, el interes y el plazo escogidos

//Referencias
//Deitel, P. y Deitel, H. (2017). C++ cómo programar. Pearson Educación.

//Cátedra Tecnología de Sistemas. (15 de octubre de 2021). Estructuras de control [Vídeo]. YouTube. https://www.youtube.com/watch?v=uCC92ivM2Y8
//Cátedra Tecnología de Sistemas. (25 de octubre de 2021). Ciclo for [Vídeo]. YouTube. https://www.youtube.com/watch?v=w-5Qb2N1QhM
//Cátedra Tecnología de Sistemas. (29 de octubre de 2021). Ciclo while [Vídeo]. YouTube. https://www.youtube.com/watch?v=-sgpjhY9Ois
//Cátedra Tecnología de Sistemas. (3 de noviembre de 2021). Sentencia switch [Vídeo]. YouTube. https://www.youtube.com/watch?v=G3Ieej2HFgk
//Cátedra Tecnología de Sistemas. (10 de noviembre de 2021). Estructuras de repetición [Vídeo]. YouTube. https://www.youtube.com/watch?v=jvzrs6ytVcM
//Cátedra Tecnología de Sistemas. (17 de noviembre de 2021). Estructuras de selección [Vídeo]. YouTube. https://www.youtube.com/watch?v=_pNlUnzJ0Y4
//Doji Creates. (28 de diciembre de 2023). Login Simulation with Max Attempts Using C++ | Tagalog Coding Tutorials [Vídeo]. YouTube. https://www.youtube.com/watch?v=lbu2_0KK4SA
//Jake R. Pomperada. (26 de junio de 2017). Three Attempts Login System in C++. Blogspot. https://jakerpomperada.blogspot.com/2017/06/three-attempts-login-system-in-c.html
//LeMaster Tech. (2 de enero de 2023). How to Program a Simple Login Form and User Registration Project Using C++ and MS Visual Studio! [Vídeo]. YouTube. https://www.youtube.com/watch?v=fTdkqOS5_ro
//rranger. (5 de marzo de 2013). Limit Login Attempts in C++ [Post en un foro en línea]. Stack Overflow. https://stackoverflow.com/questions/15234021/limit-login-attempts-in-c
//Thornton, D. F. (6 de febrero de 2014). Re: How do I make a menu that a user can choose from [Comentario en un foro en línea]. Stack Overflow. https://stackoverflow.com/questions/21608624/how-do-i-make-a-menu-that-a-user-can-choose-from
//W3Schools. (s.f.). C++ Date and Time. https://www.w3schools.com/cpp/cpp_date.asp

#include <iostream>
#include <string> //permite al programa usar datos string
#include <fstream> // contiene tipos de procesamiento de flujos de archivos
#include <conio.h> // Necesario para _getch
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std; //cout, cin, cerr son partes del namespace llamado standard library

int main() //comienza la ejecucion del programa. siempre necesaria
{
    string usuario = ""; //variables?/cadena
    string contrasena = "";
    string pass_correcta = "7777";
    string nombre = ""; //variables?/cadena
    string correo = "";
    string direccion = "";
    bool isNotNum = false; // cap 7
    bool ppvacia = true;
    bool pdosvacia = true;
    bool ptresvacia = true;
    bool acceso_concedido = false;
    bool credito = false;
    char respuesta; //datos de caracteres
    char ch;
    double salario = 0.0; //para numeros con deciamles
    double prestamo = 0.0;
    double interes = 0.0;
    double intmen = 0.0;
    double intmenres = 0;
    double cuota = 0.0;
    double cuotaex = 8.33;
    double cuotanue = 0.0;
    double saldo_anterior = cuota;
    double amortizacion = 0.0;
    double saldo_nuevo = saldo_anterior - amortizacion;
    int mesesPlazo = 0;
    int telefono = 0;
    int cedula = 0;
    int intentos = 1; //int valores enteros
    int opcion = 0;
    int opcionpres = 0;
    int secuencia = 0;
    time_t timestamp;

    cout << "----------------------\n"; //n para saltar a la siguiente linea, caracter de escape
    cout << "|  ________________  |\n";
    cout << "| |                | |\n";
    cout << "| |     BANKEST    | |\n";
    cout << "| |________________| |\n";
    cout << "|                    |\n";
    cout << "----------------------\n";
    cout << "=== LOGIN ===\n\n"; //imprimir, tal vez, write?
  
//el operador <<, la cadena "Bienvenido a C++!\n" y el punto y coma (;), se le llama instrucción.
//La mayoría de las instrucciones de C++ terminan con punto y coma, también conocidas como el terminador de instrucciones

    cout << "Usuario:";
    cin >> usuario; //read?

//si el suario es correcto, pide contrasena,

    if (usuario == "admin")
    {
        while (intentos <= 3 && !acceso_concedido) {
            cout << "Contrasena:";
            contrasena = ""; //para borrar el intento anterior
            ch = _getch(); //convierte en asterisco
                while (ch != 13){
                    contrasena.push_back(ch); //para guardar
                    cout<<'*'; //todo esto se necesita para los asteriscos
                    ch = _getch(); //para esperar por el enter otra vez despues de ingresar el pass
                }//https://stackoverflow.com/questions/41652182/how-to-display-asterisk-for-input-password-in-c-using-clion
            if (contrasena == pass_correcta){
                acceso_concedido = true;
                }
            else {
                cout << "\n\nDatos invalidos. Intente de nuevo. Intentos fallidos: " << intentos << "\n";
                intentos++; //la posicion de los ++ no importa?
            }
        }
    }
    else {
        cout <<"\n\nUsuario incorrecto.Acceso Dengado";
        return 0;
    }
    if (acceso_concedido) {
        do {
            do {
            cout << "\n\nBienvenida(o)\n\n";
            cout << "1. Datos del solicitante\n";
            cout << "2. Solicitar prestamo\n";
            cout << "3. Realizar estudio\n";
            cout << "4. Reporte de pagos\n";
            cout << "5. Salir\n";
            cout << "\nEscoja la opcion de su preferencia: ";
            cin >> opcion;
                if (opcion == isNotNum) {
                    cerr << "Opcion invalida. Vuelva a intentarlo.\n";
                    cin.clear();
                    cin.ignore(10000, '\n'); //necesarias para evitar los bucles infintos
                }
                else {
                    isNotNum = false;
                }
            }
            while (isNotNum);
            if (opcion < 1 || opcion > 5) {
                cerr << "Opcion invalida. Vuelva a intentarlo.\n";
                opcion = 0; // Reset option so the menu re-prompts safely
            }
            if (opcion == 5) {
                cout << "\nGracias por utilizar BANKEST. ¡Hasta luego!\n";
                break;
            }
            if (opcion == 1) {
                    opcion == 1;
                    cin.ignore();
                    cout << "\033[2J\033[1H";
                    cout << "----------------------\n"; //n para saltar a la siguiente linea
                    cout << "|  ________________  |\n";
                    cout << "| |                | |\n";
                    cout << "| |     BANKEST    | |\n";
                    cout << "| |________________| |\n";
                    cout << "|                    |\n";
                    cout << "----------------------\n";
                    cout << "DATOS DEL SOLICITANTE\n\n";
                    do {
                        cout << "Numero de identificacion (9 digitos): ";
                        cin >> cedula;
                        isNotNum = true;
                        if (cedula == !isNotNum) {
                            cerr << "Datos invalidos, intente de nuevo.\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        else {
                            isNotNum = false;
                        }
                    }
                    while (isNotNum);
                    do {
                        cin.ignore(10000, '\n');
                        cout << "Nombre completo: ";
                        getline(cin, nombre);
                        //La función miembro getNombre de la clase Cuenta devuelve el nombre de la cuenta almacenado en un Objeto
                        //Cuenta en particular. La línea 13 cout << "El nombre inicial de la cuenta es: " << miCuenta.getNombre();

                        if (nombre.empty()){ // .empty en cap 10 -_-
                            cerr << "Datos invalidos, intente de nuevo.\n" << endl;
                        }
                    }
                    while (nombre.empty());
                    do {

                        cout << "Correo electronico: ";
                        getline(cin, correo);
                        if (correo.empty()){
                            cerr << "Datos invalidos, intente de nuevo.\n" << endl;
                        }
                    }
                    while (correo.empty());
                    do {
                        cout << "Telefono: ";
                        cin >> telefono;
                        isNotNum = true;
                        if (telefono == !isNotNum) {
                            cerr << "Datos invalidos, intente de nuevo.\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        else {
                            isNotNum = false;
                        }
                    }
                    while (isNotNum);
                    do {
                        cin.ignore(10000, '\n');
                        cout << "Direccion de domicilio (incluya el distrito, canton y provincia): ";
                        getline(cin, direccion);
                        if (direccion.empty()){
                            cerr << "Datos invalidos, intente de nuevo.\n" << endl;
                        }
                    }
                    while (direccion.empty());
                    do {
                        cout << "Salario mensual: ";
                        cin >> salario;
                        cout << fixed << setprecision(2); //resultados con dos decimales
                        isNotNum = true;
                        if (salario == !isNotNum) {
                            cout << "Datos invalidos, intente de nuevo.\n";
                            cout << "salario mensual: ";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        else {
                            cout << "\nDatos capturados correctamente.\n";
                            isNotNum = false;
                            ch = _getch();
                        }
                        cin.ignore(10000, '\n');
                    }
                    while (isNotNum);

                // CAMBIO 2: Eliminamos el texto sobrante de advertencia.
                // Ahora, al terminar la opción 1 con éxito, marcamos que ya NO está vacía.
                ppvacia = false;
            }
            else if (opcion == 2 ) {
                if (ppvacia == true) {
                    cout << "\n Debe completar la información del solicitante.\n";
                    cout << "Presione cualquier tecla para volver al menu principal";
                    _getch();
                } else {
                    cout << "\033[2J\033[1H";//clean page
                    cout << "----------------------\n"; //n para saltar a la siguiente linea
                    cout << "|  ________________  |\n";
                    cout << "| |                | |\n";
                    cout << "| |     BANKEST    | |\n";
                    cout << "| |________________| |\n";
                    cout << "|                    |\n";
                    cout << "----------------------\n";
                    cout << "\nREGISTRO DEL SOLICITANTE\n";
                    cout << "Solicitante: " << nombre << "\n";
                    cout << "Identificacion registrada: " << cedula << "\n\n";
                    do {
                        cout << "Monto del prestamo: ";
                        cin >> prestamo;
                        cout << fixed << setprecision(2); // dos decimales
                        isNotNum = true;
                        if (prestamo == !isNotNum || prestamo < 1) {
                            cerr << "Datos invalidos, intente de nuevo.\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                            opcion = 0;
                        }
                        else {
                            isNotNum = false;
                        }
                    }
                    while (isNotNum);
                    do {
                        cout << "Tasa de interes anual en porcentaje (ej. 18.5): ";
                        cin >> interes;
                        cout << fixed << setprecision(2);
                        isNotNum = true;
                        if (interes == !isNotNum || interes < 0 || interes > 100) {
                            cerr << "Datos invalidos, intente de nuevo.\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                            opcion = 0;
                        }
                        else {
                            isNotNum = false;
                        }
                    }
                    while (isNotNum);


                    cout << "Seleccione el prestamo (en meses): \n";
                    cout << "1. 12 meses\n";
                    cout << "2. 24 meses\n";
                    cout << "3. 36 meses\n";
                    cout << "Opcion: ";
                    cin >> opcionpres;
                    if (opcionpres == 1) mesesPlazo = 12;
                    else if (opcionpres == 2) mesesPlazo = 24;
                    else if (opcionpres == 3) mesesPlazo = 36;
                    if (opcionpres < 1 || opcionpres > 3) {
                        cerr << "Opcion invalida. Vuelva a intentarlo.\n";
                        opcionpres = 0; // Reset option so the menu re-prompts safely
                    }
                    else {
                        cerr << "Datos capturados correctamente el ";
                        //tomado de https://www.w3schools.com/
                        time(&timestamp);
                        cout << ctime(&timestamp); //ctime muestra el tiempo en texto plano
                        secuencia++;
                            cout << "ID: ";
                            cout << "BK-" << setfill('0') << setw(4) << secuencia << "-" << (localtime(&timestamp)->tm_year + 1900) << endl; 
                            //El manipulador de f lujos parametrizado setfill (del encabezado <iomanip>) especif ica el carácter de relleno que aparecerá entre el signo y el valor cuando se muestre un número con un ancho de campo de cinco caracteres pero que no tenga cuatro dígitos
                            //setw, libro 169. 
                            //El manipulador de flujo setw(4) especifica que el siguiente valor de salida debe aparecer en un ancho de campo de 4, 
                            // decir, cout << imprime el valor con al menos cuatro posiciones de caracteres. 
                            
                            ch = _getch();
                            cin.ignore(10000, '\n');
                    }
                }
                intmen = interes / (100 * 12);
                pdosvacia = false;
            }
            else if (opcion == 3 ) {
                if (ppvacia == true || pdosvacia == true) {
                    cout << "\nDebe completar la informacion del solicitante y la solicitud de prestamo\n";
                    cout << "Presione cualquier tecla para volver al menu principal";
                    _getch();
                }
                else {
                    cout << "\033[2J\033[1H";
                    cout << "----------------------\n"; //n para saltar a la siguiente linea
                    cout << "|  ________________  |\n";
                    cout << "| |                | |\n";
                    cout << "| |     BANKEST    | |\n";
                    cout << "| |________________| |\n";
                    cout << "|                    |\n";
                    cout << "----------------------\n";
                    cout << "\nREALIZAR ESTUDIO\n";
                    cout << "Solicitante: " << nombre << "\n";
                    cout << "Identificacion registrada: " << cedula << "\n";
                    cout << "Salario mensual: " << salario << "\n\n";
                    if (prestamo > salario){
                        cout << "Prestamo denegado\n" << salario << "\n\n";
                        _getch();
                    }
                    else {

                        cout << "===== Resultado del estudio =====\n";
                        cout << "Monto solicitado:" << prestamo << "\n";
                        cout << "Estado: Aprobado\n";
                        cout << "Plazo del prestamo:" << mesesPlazo << "\n";
                        cout << "Tasa de interes " << interes << " anual\n";
                        if (intmen != 0){
                            cuota = prestamo * (intmen / (1 - pow(1 + intmen, -mesesPlazo)));
                            // ejemplo del libro
                            //C++ no incluye un operador de exponenciación, por lo que usamos la función pow de la Biblio-teca estándar (línea 24) del encabezado <cmath>.
                            //La función pow(x, y) calcula el valor de x elevado a la y­ésima potencia.
                        }
                        else{
                            cuota = prestamo / mesesPlazo;

                        }
                        cout << "Cuota mensual: " << cuota << " \n\n";
                        cout << "Desea aceptar el prestamo? (S/N): ";
                        cin >> respuesta;
                        if (respuesta == 'S' || respuesta == 's') {
                            cout << "Ver reporte y volver al menu.";
                        }
                        else{

                            ch = _getch();
                            cin.ignore(10000, '\n');
                        }
                    }
                }
               ptresvacia = false;
            }

            else if (opcion == 4 ) {
                if (ppvacia == true || pdosvacia == true) {
                    cout << "\nDebe realizar primero el estudio del prestamo\n";
                    cout << "Presione cualquier tecla para volver al menu principal";
                    _getch();
                }
                else {
                    cout << "\033[2J\033[1H";
                    cout << "================= REPORTE DE PAGOS =================\n";
                    cout << "Fecha analisis: ";
                    time(&timestamp);
                    cout << ctime(&timestamp);
                    cout << "\nNombre: " << nombre << "\n";
                    cout << "Identificacion: " << cedula << "\n";
                    cout << "Monto: " << prestamo << "\n";
                    if (opcionpres == 1) {
                        mesesPlazo = 12; cout << "Plazo: 12 meses\n";
                    }
                    if (opcionpres == 2) {
                        mesesPlazo = 24; cout << "Plazo: 24 meses\n";
                    }
                    if (opcionpres == 3) {
                        mesesPlazo = 36; cout << "Plazo: 36 meses\n";
                    }
                    cout << "Tasa anual: " << interes << "\n";
                    cout << "Cuota: " << cuota << "\n\n";
                    cout << "Mes\tCuota\t\tInteres\t\tAmortizacion\tSaldo Nuevo\n";
                    cout << "----------------------------------------------------------------\n\n";
                    saldo_anterior = prestamo;
                        for (int mes = 1; mes <= mesesPlazo; mes++) { //https://www.youtube.com/watch?v=w-5Qb2N1QhM video de la uned explicando el ciclo for

                            intmenres = saldo_anterior * intmen;
                            if (mes == mesesPlazo) {
                                amortizacion = saldo_anterior;
                                cuota = amortizacion + intmenres;
                            }
                            else {
                                amortizacion = cuota - intmenres;
                            }
                            saldo_nuevo = saldo_anterior - amortizacion;
                        if (saldo_nuevo < 0) saldo_nuevo = 0;
                        saldo_anterior = saldo_nuevo;
                        cout << mes << "\t" << fixed << setprecision(2) << cuota << "\t\t" << intmenres << "\t\t" << amortizacion << "\t\t"<< saldo_nuevo << "\n";
                    }
                }
            }
        }
        while (opcion != 5);
    }
    return 0; // indica que el programa finalizó exitosamente
}
