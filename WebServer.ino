#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Instanciação do objeto da classe AsyncWebServer
AsyncWebServer server(80);

const char* ssid = "*********";
const char* password = "********";

void setup() {
  // put your setup code here, to run once:
  // Conecta-se ao Ponto de acesso com as credenciais fornecidas
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.println("Connecting to WiFi..");
}
  
  // disponibiliza o url "/" com o conteúdo da String abaixo
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Ola mundo!");
  });
  // Servidor começa à ouvir os clientes
  server.begin();

  // mostra o endereço de IP
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
