/*2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en
funcionamiento. Para ello, se utiliza un sistema de log que almacena los eventos
relevantes. Cada evento recibe una etiqueta que indica su nivel de importancia o
gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y
CRITICAL.


a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un
archivo mediante el llamado a una función logMessage definida en pseudo código de
la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente
mencionadas. El formato esperado en una línea del archivo de log es el siguiente:2
[ERROR] <Mensaje>
[INFO] <Mensaje>
etc.
Verifique su funcionamiento con al menos una entrada de cada tipo.
*/

void logMessage(string mensaje, int NivelSeveridad){

    if(NivelSeveridad >= 1 && NivelSeveridad <= 5){
        vector<string> mensajes_posibles = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
        
        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open()){
            logFile << "[" << mensajes_posibles[NivelSeveridad - 1] << "]" << mensaje << endl; 
            logFile.close();
            return;
        }
    }
    else{return;}
}

/*b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad.
Para el caso del código del ejercicio 2.a, se requiere tener la habilidad de agregar
mensajes personalizados para registrar otro tipo de eventos. Los requisitos son los
siguientes:
i. Todos los nuevos mensajes deben ser invocados con logMessage.
ii. Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el
archivo y la línea de código donde sucedió este error, es decir:
logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código)
iii. Se requiere la posibilidad de registrar un mensaje de “Acceso de Usuario” a la
aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma
debe ser ingresada de la siguiente manera:
logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario)
Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc.
iv. Se requiere un código que pruebe que el sistema verifica la funcionalidad
requerida y que además demuestre que puede capturar un error en runtime,
crear una entrada en el log y después detener la ejecución del programa y salir
del mismo con un código de error (return 1)*/

//nuevos mensajes personalizados con logmessage, registrar errores indicando: 
//logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código)
//aplicacion: [security] logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario)
//mensajes de acesso:  Access Granted, Access Denied, etc.

void logMessage(string mensaje, int NivelSeveridad, string mensajePersonalizado = ""){

    if(NivelSeveridad >= 1 && NivelSeveridad <= 5){
        vector<string> mensajes_posibles = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
        
        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open()){
            logFile << "[" << mensajes_posibles[NivelSeveridad - 1] << "]" << mensaje << endl; 
            if(!mensajePersonalizado.empty()){
                logFile << ";" << mensajePersonalizado << endl;
            }
            
            logFile.close();
            return;
        }
    }
    else{return;}
}

void logMessage(string mensaje, string archivo = "", int linea_codigo = 0){
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()){
        if(!mensaje.empty()){
            logFile << "[ERROR] " << mensaje << endl;
        }
        if(!archivo.empty()){
            logFile << ";" << archivo << endl;
        }
        if(linea_codigo != NULL){
            logFile << ";" << linea_codigo << endl;
        }
        logFile.close();
        return; }
    else{return;}
}   

void logMessage(string mensaje_de_acceso, string nombre_de_usuario){
    
    ofstream logFile("log.txt", ios::app);
    if(logFile.is_open()){
        logFile << "[SECURITY] " << mensaje_de_acceso << "; usuario: " << nombre_de_usuario << endl;
    }

}

main(){
    //funcion parte 1:
    logMessage("Debugging ", 1);
    logMessage("Info ", 2);
    logMessage("Warning ", 3);
    logMessage("Error ", 4);
    logMessage("Critical ", 5);
    //funcion parte 2 con mensaje personalizado:
    logMessage("Debugging ", 1, "Mensaje personalizado");
    //Parte 3 con mensaje, archivo y linea
    logMessage("Hubo un error", "archivo.txt", 98)
    //Parte 4: 
    logMessage("Este es un mensaje de error", "usuario1340");
}