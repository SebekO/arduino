/*********
  Oprogramowanie napisane przez: Mateusz Jaros
  Szczegły projektu na www.majsterkowo.pl, wyszukaj Kontroler LED WiFi

*********/

/* Biblioteki */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h> 

/* Piny */
const int irPin = 4; // To jest 'GPIO4' (D2 na NodeMCU)

/* Objekty */
MDNSResponder mdns;
ESP8266WebServer server(80);
IRsend irsend(irPin);

/* Ustawienia sieciowe */
const char* ssid = "<li_id=content-453765>";
const char* password = "lolek70510825";
const char* device_name = "led"; // mozesz dostać sie na strone za pomoca np. http://led.local/


/* Strona internetowa
  
  Jezeli wrzucisz zawartosc strony do kodu tak:
    String webPage = R"=====(content of web page )=====";
  to nie musisz bac sie o tego typu znaki: ' " # < > / \  
  */
  
String webPage = R"=====(
  <!DOCTYPE HTML>
  <html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED CONTROLLER</title>
    <link href="https://fonts.googleapis.com/css?family=Lato:400,900&subset=latin-ext" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <style> 
      button {
      float: left;
      width: 60px;
      height: 60px;
      font-size: 15px;
      margin: 5px;
      border-radius: 30px;
      -webkit-transition-duration: 0.4s; /* Safari */
      transition-duration: 0.2s;
      cursor: pointer;
      text-align: center;
      font-family: 'Lato', sans-serif;
      font-weight: bold;
      outline:none;
      border: none;
      color:white;  }

    #container {
      max-width: 280px;
      margin: auto;
      margin-top: 50px;
      background-color: #BDB7AA;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23AAB0BD">AAB0BD</a></span>;
      border-radius: 15px;
      padding: 5px;
      padding-top: 20px;
      padding-bottom: 20px;
      margin-top: 20px; }

    .power {
      background-color: white;
      color: black; }
    .power:hover {
      border: 2px solid black;
      color: black; }

    #off {
      background-color: black;
      color: white; }
    #off:hover {
      background-color: white;
      border: 2px solid black;
      color: black; }

    #on {
      background-color: red;  
      color: white; }
    #on:hover {
      background-color: white;
      border: 2px solid red;
      color: black; }

    #red {  background-color: #FF191B;  }
    #red:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23FF191B">FF191B</a></span>;
      color: black; }

    #red1 { background-color: #FF5319;  }
    #red1:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23FF5319">FF5319</a></span>;  }

    #red2 { background-color: #FF6A5E;  }
    #red2:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23FF6A5E">FF6A5E</a></span>;  }

    #red3 { background-color: #FF926B;  }
    #red3:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23FF926B">FF926B</a></span>;  }

    #red4 { background-color: #F3F62F;  }
    #red4:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23F3F62F">F3F62F</a></span>;  }

    #green {  background-color: #288F00;  }
    #green:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23288F00">288F00</a></span>;
      color: black; }

    #green1 { background-color: #3CD45F;  }
    #green1:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%233CD45F">3CD45F</a></span>;
      color: black;
      }
    #green2 { background-color: #47E3C6;  }
    #green2:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%2347E3C6">47E3C6</a></span>;
      color: black; }

    #green3 { background-color: #44C5DE;  }
    #green3:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%2344C5DE">44C5DE</a></span>;  }

    #green4 { background-color: #289AE3;  }
    #green4:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23289AE3">289AE3</a></span>;
      color: black; }

    #blue { background-color: #122B9C;  }
    #blue:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23122B9C">122B9C</a></span>;
      color: black; }

    #blue1 {  background-color: #6C6CD4;  }
    #blue1:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%236C6CD4">6C6CD4</a></span>;
      color: black; }

    #blue2 {  background-color: #5D2AE3;  }
    #blue2:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%235D2AE3">5D2AE3</a></span>;
      color: black; }

    #blue3 {  background-color: #9025DE;  }
    #blue3:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%239025DE">9025DE</a></span>;
      color: black; }

    #blue4 {  background-color: #BE11E3;  }
    #blue4:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%23BE11E3">BE11E3</a></span>;
      color: black; }

    #white {
      background-color: white;
      color: black; }
    #white:hover {
      background-color: white;
      border: 2px solid black;
      color: black; }

    .function {
      background-color: #5A6170;
      font-size: 10px;  }
    .function:hover {
      background-color: white;
      border: 2px solid<span class="hashtag"> #<a href="https://majsterkowo.pl?s=%235A6170">5A6170</a></span>;
      color: black;
      font-size: 10px;  }

  </style>
  </head>
  <body>
    <div id="container">
      <a href="lightup"><button class="power"><i class="material-icons">brightness_5</i></button></a>
      <a href="lightdown"><button class="power"><i class="material-icons">brightness_3</i></button></a>
      <a href="off"><button id="off"><i class="material-icons">lightbulb_outline</i></button></a>
      <a href="on"><button id="on"><i class="material-icons">wb_incandescent</i></button></a>
      <div style="clear : both"></div>

      <a href="red"><button id="red">R</button></a>
      <a href="green"><button id="green">G</button></a>
      <a href="blue"><button id="blue">B</button></a>
      <a href="white"><button id="white">W</button></a>
      <div style="clear : both"></div>

      <a href="red1"><button id="red1"></button></a>
      <a href="green1"><button id="green1"></button></a>
      <a href="blue1"><button id="blue1"></button></a>
      <a href="flash"><button class="function">FLASH</button></a>
      <div style="clear : both"></div>

      <a href="red2"><button id="red2"></button></a>
      <a href="green2"><button id="green2"></button></a>
      <a href="blue2"><button id="blue2"></button></a>
      <a href="strobe"><button class="function">STROBE</button></a>
      <div style="clear : both"></div>

      <a href="red3"><button id="red3"></button></a>
      <a href="green3"><button id="green3"></button></a>
      <a href="blue3"><button id="blue3"></button></a>
      <a href="fade"><button class="function">FADE</button></a>
      <div style="clear : both"></div>

      <a href="red4"><button id="red4"></button></a>
      <a href="green4"><button id="green4"></button></a>
      <a href="blue4"><button id="blue4"></button></a>
      <a href="smooth"><button class="function">SMOOTH</button></a>
      <div style="clear : both"></div>
    </div>
  </body>
  </html>
  )=====";


/* Kody IR */
#define  IR_BPLUS  0xF700FF  
#define IR_BMINUS 0xF7807F  
#define IR_OFF    0xF740BF  
#define IR_ON     0xF7C03F  
#define IR_R    0xF720DF   
#define IR_G    0xF7A05F   
#define IR_B    0xF7609F   
#define IR_W    0xF7E01F   
#define IR_B1   0xF710EF   
#define IR_B2   0xF7906F   
#define IR_B3   0xF750AF  
#define IR_FLASH  0xF7D02F  
#define IR_B4   0xF730CF 
#define IR_B5   0xF7B04F  
#define IR_B6   0xF7708F  
#define IR_STROBE 0xF7F00F  
#define IR_B7   0xF708F7   
#define IR_B8   0xF78877   
#define IR_B9   0xF748B7   
#define IR_FADE   0xF7C837   
#define IR_B10    0xF728D7   
#define IR_B11    0xF7A857  
#define IR_B12    0xF76897  
#define IR_SMOOTH 0xF7E817  

void setup(void){
  
  delay(1000);

  /* Uruchamianie kilku (nie)waznych rzeczy */
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  irsend.begin();
  Serial.println("");

  /* Czekanie na polaczenie z WiFi */
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }

  /* Pokazanie kilku inforamcji o sieci na Serial Monitorze */
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  /* Nadawanie specjalnej nazwy */
  if(mdns.begin(device_name, WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  /* Pokazywanie odpowiedniej strony na podstawie URL
     i wysywlanie kodow IR */
  server.on("/", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Loaded main page");
  });
  server.on("/lightup", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_BPLUS, 32);
    irsend.sendNEC(IR_BPLUS, 32);
    irsend.sendNEC(IR_BPLUS, 32);
    Serial.print("Pressed: ");
    Serial.println("lightup");
    delay(1000);
  });
  server.on("/lightdown", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_BMINUS, 32);
    irsend.sendNEC(IR_BMINUS, 32);
    irsend.sendNEC(IR_BMINUS, 32);
    Serial.print("Pressed: ");
    Serial.println("lightdown");
    delay(1000); 
  });
  server.on("/off", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_OFF, 32);
    Serial.print("Pressed: ");
    Serial.println("off");
    delay(1000);
  });
  server.on("/on", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_ON, 32);
    Serial.print("Pressed: ");
    Serial.println("on");
    delay(1000); 
  });

  server.on("/red", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_R, 32);
    Serial.print("Pressed: ");
    Serial.println("red");
    delay(1000); 
  });
  server.on("/green", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_G, 32);
    Serial.print("Pressed: ");
    Serial.println("green");
    delay(1000); 
  });
  server.on("/blue", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B, 32);
    Serial.print("Pressed: ");
    Serial.println("blue");
    delay(1000); 
  });
  server.on("/white", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_W, 32);
    Serial.print("Pressed: ");
    Serial.println("white");
    delay(1000); 
  });

  server.on("/red1", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B1, 32);
    Serial.print("Pressed: ");
    Serial.println("red1");
    delay(1000); 
  });
  server.on("/green1", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B2, 32);
    Serial.print("Pressed: ");
    Serial.println("green1");
    delay(1000); 
  });
  server.on("/blue1", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B3, 32);
    Serial.print("Pressed: ");
    Serial.println("blue1");
    delay(1000); 
  });
  server.on("/flash", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_FLASH, 32);
    Serial.print("Pressed: ");
    Serial.println("flash");
    delay(1000); 
  });

  server.on("/red2", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B4, 32);
    Serial.print("Pressed: ");
    Serial.println("red2");
    delay(1000); 
  });
  server.on("/green2", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B5, 32);
    Serial.print("Pressed: ");
    Serial.println("green2");
    delay(1000); 
  });
  server.on("/blue2", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B6, 32);
    Serial.print("Pressed: ");
    Serial.println("blue2");
    delay(1000); 
  });
  server.on("/strobe", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_STROBE, 32);
    Serial.print("Pressed: ");
    Serial.println("strobe");
    delay(1000); 
  });

  server.on("/red3", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B7, 32);
    Serial.print("Pressed: ");
    Serial.println("red3");
    delay(1000); 
  });
  server.on("/green3", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B8, 32);
    Serial.print("Pressed: ");
    Serial.println("green3");
    delay(1000); 
  });
  server.on("/blue3", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B9, 32);
    Serial.print("Pressed: ");
    Serial.println("blue3");
    delay(1000); 
  });
  server.on("/fade", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_FADE, 32);
    Serial.print("Pressed: ");
    Serial.println("fade");
    delay(1000); 
  });

  server.on("/red4", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B10, 32);
    Serial.print("Pressed: ");
    Serial.println("red4");
    delay(1000); 
  });
  server.on("/green4", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B11, 32);
    Serial.print("Pressed: ");
    Serial.println("green4");
    delay(1000); 
  });
  server.on("/blue4", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_B12, 32);
    Serial.print("Pressed: ");
    Serial.println("blue4");
    delay(1000); 
  });
  server.on("/smooth", [](){
    server.send(200, "text/html", webPage);
    irsend.sendNEC(IR_SMOOTH, 32);
    Serial.print("Pressed: ");
    Serial.println("smooth");
    delay(1000); 
  });
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
} 
