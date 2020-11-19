/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Cargar biblioteca de Wi-Fi
#include <WiFi.h>


// Credenciales de la red
const char* ssid = "GUSTAVOMC";
const char* password = "Gustavo2020";

// Establecer el número de puerto del servidor web en 80
WiFiServer server(80);

// Variable para almacenar la solicitud HTTP
String header;

// Variables auxiliares para almacenar el estado de salida actual

///Led RGB 1
String ledRGB1Rstate = "off";
String ledRGB1Astate = "off";
String ledRGB1Vstate = "off";

String ledRGB2Rstate = "off";
String ledRGB2Astate = "off";
String ledRGB2Vstate = "off";

String ledRGB3Rstate = "off";
String ledRGB3Astate = "off";
String ledRGB3Vstate = "off";

String ledAzul1state = "off";
String ledAzul2state = "off";
String ledAzul3state = "off";

String ledRojo1state = "off";
String ledRojo2state = "off";
String ledRojo3state = "off";

String ledVerde1state = "off";
String ledVerde2state = "off";
String ledVerde3state = "off";

String ledAmarillo1state = "off";
String ledAmarillo2state = "off";
String ledAmarillo3state = "off";

// Asignar variables de salida a pines GPIO
const int ledRGB1R = 33;
const int ledRGB1A = 26;
const int ledRGB1V = 27;

const int ledRGB2R = 32;
const int ledRGB2A = 25;
const int ledRGB2V = 14;

const int ledRGB3R = 12;
const int ledRGB3A = 13;
const int ledRGB3V = 3;

const int ledAzul1 = 22;
const int ledAzul2 = 21;
const int ledAzul3 = 19;

const int ledRojo1 = 23;
const int ledRojo2 = 18;
const int ledRojo3 = 5;

const int ledVerde1 = 17;
const int ledVerde2 = 16;
const int ledVerde3 = 4;

const int ledAmarillo1 = 0;
const int ledAmarillo2 = 2;
const int ledAmarillo3 = 15;

// Tiempo actual
unsigned long currentTime = millis();
// Tiempo anterior
unsigned long previousTime = 0; 
// Se define el tiempo de espera en milisegundos 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Inicializar las variables de salida como salidas
  pinMode(ledRGB1R, OUTPUT);
  pinMode(ledRGB1A, OUTPUT);
  pinMode(ledRGB1V, OUTPUT);

  pinMode(ledRGB2R, OUTPUT);
  pinMode(ledRGB2A, OUTPUT);
  pinMode(ledRGB2V, OUTPUT);

  pinMode(ledRGB3R, OUTPUT);
  pinMode(ledRGB3A, OUTPUT);
  pinMode(ledRGB3V, OUTPUT);

  pinMode(ledAzul1, OUTPUT);
  pinMode(ledAzul2, OUTPUT);
  pinMode(ledAzul3, OUTPUT);

  pinMode(ledRojo1, OUTPUT);
  pinMode(ledRojo2, OUTPUT);
  pinMode(ledRojo3, OUTPUT);

  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledVerde3, OUTPUT);

  pinMode(ledAmarillo1, OUTPUT);
  pinMode(ledAmarillo2, OUTPUT);
  pinMode(ledAmarillo3, OUTPUT);
  
  //Establecer salidas en BAJO(Apagado)
  digitalWrite(ledRGB1R, LOW);
  digitalWrite(ledRGB1A, LOW);
  digitalWrite(ledRGB1V, LOW);

  digitalWrite(ledRGB2R, LOW);
  digitalWrite(ledRGB2A, LOW);
  digitalWrite(ledRGB2V, LOW);

  digitalWrite(ledRGB3R, LOW);
  digitalWrite(ledRGB3A, LOW);
  digitalWrite(ledRGB3V, LOW);

  digitalWrite(ledAzul1, LOW);
  digitalWrite(ledAzul2, LOW);
  digitalWrite(ledAzul3, LOW);

  digitalWrite(ledRojo1, LOW);
  digitalWrite(ledRojo2, LOW);
  digitalWrite(ledRojo3, LOW);

  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVerde2, LOW);
  digitalWrite(ledVerde3, LOW);

  digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledAmarillo2, LOW);
  digitalWrite(ledAmarillo3, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Escuche a los clientes entrantes

  if (client) {                             // Si un nuevo cliente se conecta,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // imprimir un mensaje en el puerto serie
    String currentLine = "";                // cree una cadena para contener los datos entrantes del cliente
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // Bucle mientras el cliente está conectado
      currentTime = millis();
      if (client.available()) {             // Si hay bytes para leer del cliente,
        char c = client.read();             // leer un byte, luego
        Serial.write(c);                    // imprimirlo en el monitor de serie
        header += c;
        if (c == '\n') {                    // si el byte es un carácter de nueva línea
          // si la línea actual está en blanco, tiene dos caracteres de nueva línea seguidos
          // ese es el final de la solicitud HTTP del cliente, así que envíe una respuesta:
          if (currentLine.length() == 0) {
            // Los encabezados HTTP siempre comienzan con un código de respuesta (por ejemplo, HTTP / 1.1 200 OK)
            // y un tipo de contenido para que el cliente sepa lo que viene, luego una línea en blanco:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // enciende y apaga los GPIO (Leds)
            if (header.indexOf("GET /33/on") >= 0 || header.indexOf("GET /26/on") >= 0 || header.indexOf("GET /27/on") >= 0) {
              Serial.println("LED RGB 1 Encendido");
              ledRGB1Rstate = "on";
              ledRGB1Astate = "on";
              ledRGB1Vstate = "on";
              
              ledRGB2Rstate = "on";
              ledRGB2Astate = "on";
              ledRGB2Vstate = "on";

              ledRGB3Rstate = "on";
              ledRGB3Astate = "on";
              ledRGB3Vstate = "on";

              digitalWrite(ledRGB1R, HIGH); //rojo
              digitalWrite(ledRGB2V, HIGH); // verde
              digitalWrite(ledRGB3V, HIGH); //azul
              
            } else if (header.indexOf("GET /33/off") >= 0 || header.indexOf("GET /26/off") >= 0 || header.indexOf("GET /27/off") >= 0) {
              Serial.println("LED RGB 1 Apagado");
              ledRGB1Rstate = "off";
              ledRGB1Astate = "off";
              ledRGB1Vstate = "off";

              ledRGB2Rstate = "off";
              ledRGB2Astate = "off";
              ledRGB2Vstate = "off";
              
              ledRGB3Rstate = "off";
              ledRGB3Astate = "off";
              ledRGB3Vstate = "off";

              digitalWrite(ledRGB1R, LOW);
              digitalWrite(ledRGB2V, LOW);
              digitalWrite(ledRGB3V, LOW);
              
            } else if (header.indexOf("GET /22/on") >= 0 || header.indexOf("GET /21/on") >= 0 || header.indexOf("GET /19/on") >= 0) {
              Serial.println("LEDS Aules Encendidos");
              ledAzul1state = "on";
              ledAzul2state = "on";
              ledAzul3state = "on";

              digitalWrite(ledAzul1, HIGH);
              digitalWrite(ledAzul2, HIGH);
              digitalWrite(ledAzul3, HIGH);
              
            }else if (header.indexOf("GET /22/off") >= 0 || header.indexOf("GET /21/off") >= 0 || header.indexOf("GET /19/off") >= 0) {
              Serial.println("LEDS Aules Apagados");
              ledAzul1state = "off";
              ledAzul2state = "off";
              ledAzul3state = "off";

              digitalWrite(ledAzul1, LOW);
              digitalWrite(ledAzul2, LOW);
              digitalWrite(ledAzul3, LOW);
              
            }else if (header.indexOf("GET /23/on") >= 0 || header.indexOf("GET /18/on") >= 0 || header.indexOf("GET /5/on") >= 0) {
              Serial.println("LEDS Rojos Encendidos");
              ledRojo1state = "on";
              ledRojo2state = "on";
              ledRojo3state = "on";

              digitalWrite(ledRojo1, HIGH);
              digitalWrite(ledRojo2, HIGH);
              digitalWrite(ledRojo3, HIGH);
              
            }else if (header.indexOf("GET /23/off") >= 0 || header.indexOf("GET /18/off") >= 0 || header.indexOf("GET /5/off") >= 0) {
              Serial.println("LEDS Rojos Apagados");
              ledRojo1state = "off";
              ledRojo2state = "off";
              ledRojo3state = "off";

              digitalWrite(ledRojo1, LOW);
              digitalWrite(ledRojo2, LOW);
              digitalWrite(ledRojo3, LOW);
              
            }else if (header.indexOf("GET /17/on") >= 0 || header.indexOf("GET /16/on") >= 0 || header.indexOf("GET /4/on") >= 0) {
              Serial.println("LEDS Verdes Encendidos");
              ledVerde1state = "on";
              ledVerde2state = "on";
              ledVerde3state = "on";

              digitalWrite(ledVerde1, HIGH);
              digitalWrite(ledVerde2, HIGH);
              digitalWrite(ledVerde3, HIGH);
              
            }else if (header.indexOf("GET /17/off") >= 0 || header.indexOf("GET /16/off") >= 0 || header.indexOf("GET /4/off") >= 0) {
              Serial.println("LEDS Verder Apagados");
              ledVerde1state = "off";
              ledVerde2state = "off";
              ledVerde3state = "off";

              digitalWrite(ledVerde1, LOW);
              digitalWrite(ledVerde2, LOW);
              digitalWrite(ledVerde3, LOW);
              
            }else if (header.indexOf("GET /0/on") >= 0 || header.indexOf("GET /2/on") >= 0 || header.indexOf("GET /15/on") >= 0) {
              Serial.println("LEDS Verdes Encendidos");
              ledAmarillo1state = "on";
              ledAmarillo2state = "on";
              ledAmarillo3state = "on";

              digitalWrite(ledAmarillo1, HIGH);
              digitalWrite(ledAmarillo2, HIGH);
              digitalWrite(ledAmarillo3, HIGH);

              
            }else if (header.indexOf("GET /0/off") >= 0 || header.indexOf("GET /2/off") >= 0 || header.indexOf("GET /15/off") >= 0) {
              Serial.println("LEDS Verder Apagados");
              ledAmarillo1state = "off";
              ledAmarillo2state = "off";
              ledAmarillo3state = "off";

              digitalWrite(ledAmarillo1, LOW);
              digitalWrite(ledAmarillo2, LOW);
              digitalWrite(ledAmarillo3, LOW);
              
            }else if (header.indexOf("GET /33s/on") >= 0 || header.indexOf("GET /26s/on") >= 0 || header.indexOf("GET /27s/on") >= 0) {
              Serial.println("LEDS RGB Secuencia encendida");
              ledRGB1Rstate = "on";
              ledRGB1Astate = "on";
              ledRGB1Vstate = "on";

              ledRGB2Rstate = "on";
              ledRGB2Astate = "on";
              ledRGB2Vstate = "on";
              
              ledRGB3Rstate = "on";
              ledRGB3Astate = "on";
              ledRGB3Vstate = "on";

                digitalWrite(ledRGB1V, HIGH); // azul
                digitalWrite(ledRGB2A, HIGH); // azul
                digitalWrite(ledRGB3V, HIGH); //azul
                
                delay(500);
                
                digitalWrite(ledRGB1V, LOW); // azul
                digitalWrite(ledRGB2A, LOW); // azul
                digitalWrite(ledRGB3V, LOW); //azul
  
                digitalWrite(ledRGB1R, HIGH); //rojo
                digitalWrite(ledRGB2R, HIGH); //rojo
                digitalWrite(ledRGB3R, HIGH); //rojo
  
                delay(500);
  
                digitalWrite(ledRGB1R, LOW); //rojo
                digitalWrite(ledRGB2R, LOW); //rojo
                digitalWrite(ledRGB3R, LOW); //rojo
  
                digitalWrite(ledRGB1A, HIGH); //verde
                digitalWrite(ledRGB2V, HIGH); // verde
                digitalWrite(ledRGB3A, HIGH); //verde
  
                delay(500);
                
                digitalWrite(ledRGB1A, LOW); //verde
                digitalWrite(ledRGB2V, LOW); // verde
                digitalWrite(ledRGB3A, LOW); //verde
  
                digitalWrite(ledRGB1R, HIGH); //rojo
                digitalWrite(ledRGB2R, HIGH); //rojo
                digitalWrite(ledRGB3R, HIGH); //rojo
                
                digitalWrite(ledRGB1V, HIGH); // azul
                digitalWrite(ledRGB2A, HIGH); // azul
                digitalWrite(ledRGB3V, HIGH); //azul
  
                delay(500);

                digitalWrite(ledRGB1A, HIGH); //verde
                digitalWrite(ledRGB2V, HIGH); // verde
                digitalWrite(ledRGB3A, HIGH); //verde
  
                digitalWrite(ledRGB1R, LOW); //rojo
                digitalWrite(ledRGB2R, LOW); //rojo
                digitalWrite(ledRGB3R, LOW); //rojo
                
                digitalWrite(ledRGB1V, HIGH); // azul
                digitalWrite(ledRGB2A, HIGH); // azul
                digitalWrite(ledRGB3V, HIGH); //azul

               
                delay(500); 

                digitalWrite(ledRGB1R, LOW);
                digitalWrite(ledRGB1A, LOW);
                digitalWrite(ledRGB1V, LOW);
  
                digitalWrite(ledRGB2R, LOW);
                digitalWrite(ledRGB2A, LOW);
                digitalWrite(ledRGB2V, LOW);
  
                digitalWrite(ledRGB3R, LOW);
                digitalWrite(ledRGB3A, LOW);
                digitalWrite(ledRGB3V, LOW);
  
               
            
              
              
                
  
  
              //digitalWrite(ledRGB1R, HIGH); //rojo
              //digitalWrite(ledRGB1V, HIGH); // azul
              //digitalWrite(ledRGB1A, HIGH); //verde

              //digitalWrite(ledRGB2R, HIGH); //rojo
              //digitalWrite(ledRGB2A, HIGH); // azul
              //digitalWrite(ledRGB2V, HIGH); // verde

              //digitalWrite(ledRGB3R, HIGH); //rojo
              //digitalWrite(ledRGB3V, HIGH); //azul
              //digitalWrite(ledRGB3A, HIGH); //verde 
              
              
            }else if (header.indexOf("GET /33s/off") >= 0 || header.indexOf("GET /26s/off") >= 0 || header.indexOf("GET /27s/off") >= 0) {
              Serial.println("LEDS RGB secuencia Apagado");
              ledRGB1Rstate = "off";
              ledRGB1Astate = "off";
              ledRGB1Vstate = "off";

              ledRGB2Rstate = "off";
              ledRGB2Astate = "off";
              ledRGB2Vstate = "off";
              
              ledRGB3Rstate = "off";
              ledRGB3Astate = "off";
              ledRGB3Vstate = "off";

              digitalWrite(ledRGB1R, LOW);
              digitalWrite(ledRGB1A, LOW);
              digitalWrite(ledRGB1V, LOW);

              digitalWrite(ledRGB2R, LOW);
              digitalWrite(ledRGB2A, LOW);
              digitalWrite(ledRGB2V, LOW);

              digitalWrite(ledRGB3R, LOW);
              digitalWrite(ledRGB3A, LOW);
              digitalWrite(ledRGB3V, LOW);
            } 
            
            break;
          } else { //si tiene una nueva línea, borre currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // si tiene algo más que un carácter de retorno de carro,
          currentLine += c;      // agréguelo al final de la línea actual
        }
      }
    }
    // Borrar la variable de encabezado
    header = "";
    // Cerrar la conexión
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
