#include <Ethernet.h>
#define watering A0

static byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEA, 0x1D, 0xDC };
static byte ip[] = { 10, 0, 0, 174 };
static byte gateway[] = { 10, 0, 0, 138 };
static byte subnet[] = { 255, 255, 255, 0};

const static char strsa[13] = "GET /water";
byte strsa_pnt = 0;

EthernetServer server(9010);

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600); 
  while (!Serial) {
    ;
  }
}

void loop() {
 bool strsa_swch = false;
 EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // checking for GET /water
        if(strsa[strsa_pnt] == c && strsa_pnt < 10){
          strsa_pnt ++;
          if(strsa_pnt == 10){
            strsa_swch = true;
            strsa_pnt = 0;  
          }
        }else{
          strsa_pnt = 0;  
        }
        //
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            (strsa_swch == true ? : client.println("Refresh: 5")); // if water switch was asked, just don't refresh
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("<pre>");
            client.print("Watering: ");
            client.print(analogRead(watering));
            client.println("</pre></html>");
            if(strsa_swch){
              digitalWrite(8, 0xFFFF); // sending a lot to NPN transistor
              delay(1000); // wait
              digitalWrite(8, 0);
              strsa_swch = false;
            }
            break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }               
    }
    delay(1);
    client.stop();
  }
  delay(1);
}
