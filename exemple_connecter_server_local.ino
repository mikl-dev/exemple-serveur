#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetServer local_server(80);  // creation d'un serveur web sur le port standard 80

String readString;

void setup() {
  Serial.begin(115200);
  Ethernet.begin(mac);
  local_server.begin();
  Serial.print("Server adresse: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
    EthernetClient client = local_server.available();

    if (client){
      while(client.connected()){
        if (client.available()){
          char c = client.read();
          Serial.print(c);
        
        if (readString.length()<100){
          readString = c;
        }
        if (c = '\n'){
          Serial.print(readString);
          client.println("<HTTP/1.1 200 OK>");
          client.println("<Connection-Type: text/html>");
          client.println("<Connection: close>");
          client.println("");

          client.println("!DOCTYPE html");
          client.println("<html");
          client.println("<head>");
          client.println("<title>Webserver</title>");
          client.println("</head");
          client.println("<body>");
          client.println("<p>coucou<\<p>");

          delay (1);
          client.stop();








        }
        }
      }
    }



  }