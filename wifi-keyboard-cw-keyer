//COMMENT - // 100% working script with ESP12-F wifi module // TESTED OK // KEYBOARD CW SENDER USING LAPTOP OR SMART PHONE
// this script written for hamradio project : WIFI CW KEYBOARD BY VU3AVE (ANISH VR , KERALA)
//KEY_PIN and P_CW are = pin 5 of ESP12 > cw out pin

// EEPROM STORES  time_unit data - millisecond for DIT
// recalls this data from eeprom to html page
// 3 numbers of input fields to type in a set GO the text as CW
// this script run esp12-f module in AP-Mode only
// there is no password is set to Join this Access Point (AP)


#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //Our HTML webpage contents with javascripts

// EEPROM STORAGE variables
String data;
void writeString(char add,String data);
String read_String(char add);
String recivedData;

int count = 0;
int last_sent_location=0;
int messagetocw();
#define P_CW  5  // ESP12-  (GPIO 10) // CW digital output                     
int KEY_PIN=5; // relay drive to transimit cw in port of ESP8266
int sm_time;
int TIME_UNIT = 73; // default time for DIT
bool dxing_mode = true; // put false for normal mode


String  morsecode;


String message;
String dit_time;
 int present_message_length;
 String backup_message;
String present_message;




const String  characters = "abcdefghijklmnopqrstuvwxyz1234567890?.,/-; ";
////////////////////////////// CW sender/////
String mappings[] = {
                     ".-",  // A
                     "-...",
                     "-.-.",  
                     "-..",
                     ".",  
                     "..-.",
                     "--.",  
                     "....",
                     "..",  
                     ".---",
                     "-.-",  
                     ".-..",
                     "--",  
                     "-.",
                     "---",  
                     ".--.",
                     "--.-",  
                     ".-.",
                     "...",  
                     "-",                      
                     "..-",  
                     "...-",
                     ".--",  
                     "-..-",
                     "-.--",  
                     "--..", // Z
                     ".----",  // 1
                     "..---",
                     "...--",  
                     "....-",
                     ".....",  
                     "-....",
                     "--...",  
                     "---..",
                     "----.",  
                     "-----",   // 0
                     "..--..",  // ?
                     ".-.-.-",  // .
                     "--..--",  // ,
                     "-..-.",   // /
                     "-...-",   // -   // spacing symbol
                     ".-.-." ,   // ;  //  "AR" symbol
                     ""
                      };

















//SSID and Password of your WiFi router
const char* ssid = "14-dec-2022-5";
const char* password = "";

ESP8266WebServer server(80); //Server on port 80



//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents on index.h 
 server.send(200, "text/html", s); //Send web page
}



void handleWPMTXT(){
   dit_time = server.arg("mytxt"); 
   Serial.println("received dit_time is :");
    Serial.println(dit_time);
     Serial.println("");
    server.send(200, "text/plane", dit_time);
// store eeprom to continue here...  
data = dit_time;
  Serial.print("Writing Data to address 0:");
  Serial.println(data);
//WRITING NEW WPM DATA (DIT TIME IN MILLISECOND) IN EEPROM
  writeString(0, data);  //Address 0 and String type data
  delay(10);

  TIME_UNIT = data.toInt(); // CONVERTING STRING TO INT and STORING IN TIME_UNIT (NEW WPM STORED )
}



void handleWPMBACK(){
  //////// DISPLAY STORED WPM IN HTML FILE
  recivedData = read_String(0);
  Serial.print("Read Data OF WPM FROM 0:");
  Serial.println(recivedData);
  delay(1000);
  server.send(200, "text/plane", recivedData);
}







//-----------ave edit
void handleCWTXT(){
   message = server.arg("mytxt"); 
    Serial.println(message);
    server.send(200, "text/plane", message);


present_message = message; 
message="";  


//int result= messagetocw();

     
}
//-----------ave edit


//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  pinMode(P_CW, OUTPUT);
  pinMode(KEY_PIN, OUTPUT);
  // send the FIRST CHARACTOR ONLY of the subscribed string as cw
 // int result= messagetocw();



        // reserve 200 bytes for the inputString:
      //  inputString.reserve(200);

  Serial.begin(115200);
  EEPROM.begin(512);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);



 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/cwtxt", handleCWTXT);
  server.on("/wpmtxt", handleWPMTXT);
  server.on("/wpmback", handleWPMBACK);

  server.begin();                  //Start server
  Serial.println("");
  Serial.println("HTTP server started");


  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());





// FSOR FIRST RUN >> WPM VALUE FROM EEPROM TO RUNNING PROGRAMME
// reading eeprom value of TIME_UNIT from address 0, to store in TIME_UNIT

  recivedData = read_String(0);
  Serial.print("Read Data from address 0 : ");
  Serial.println(recivedData);
  delay(1000);
if(recivedData.length() >=1){
  TIME_UNIT = recivedData.toInt(); // CONVERTING STRING TO INT and STORING IN TIME_UNIT (NEW WPM STORED )
}
// reading eeprom value of TIME_UNIT from address 0, to store in TIME_UNIT









  
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
int result= messagetocw(); // WHOLE STRING sending string as cw
  
  server.handleClient();          //Handle client requests
}











int messagetocw()
{  
  // FUNCTION messagetocw() START
 
  // int size = strlen(message);
  
 present_message_length = present_message.length(); 







if(last_sent_location > present_message_length) 
{
  last_sent_location = present_message_length;
}














  
 // int TIME_UNIT = 50; // default time for DIT


 // const int DOT = TIME_UNIT;
 // const int DASH = 3 * TIME_UNIT;
 // const int SYMBOL_SPACE = TIME_UNIT;
  //const int LETTER_SPACE = 3 * TIME_UNIT - SYMBOL_SPACE;
 // const int WORD_SPACE = 7 * TIME_UNIT - LETTER_SPACE;




  const int DOT = TIME_UNIT;
  const int DASH = 3 * TIME_UNIT;


int ss;
int ls;
int ws;
if(dxing_mode)
{
 
ss=DOT;
ls=0.2 * DOT;
ws=1 * DOT;
}
else
{


 ss=DOT;
ls=2 * DOT;
ws=5 * DOT;
}
 
  const int SYMBOL_SPACE = ss;
  const int LETTER_SPACE = ls;
  const int WORD_SPACE = ws;






  
 
 present_message.toLowerCase();
 // for (int i = 0; i < size; i++) {
    
        // const char* ch = strchr(characters, tolower(message[i]));
        char ch = characters.charAt(characters.indexOf(present_message.charAt(last_sent_location)));//
        // if (ch != NULL){
   if (ch != '\0'){
          
          // int position = ch-characters;
          int position = characters.indexOf(present_message.charAt(last_sent_location));




last_sent_location=last_sent_location+1;


          
          
          morsecode = mappings[position];
          
          // int count = strlen(morsecode);
         int count = morsecode.length();
          


          
          
          for( int j=0; j< count; j++)
          {
            
            char symbol = morsecode[j];
            
            if(symbol =='.')
            {
              sm_time = DOT;
            }
            
            if(symbol =='-')
            {
              sm_time = DASH;
            }
            digitalWrite(KEY_PIN, HIGH);


     //    tone(tonepin, my_tone_frequency);
        
        






            
            delay(sm_time);
            digitalWrite(KEY_PIN, LOW);
         //    noTone(tonepin);
            delay(SYMBOL_SPACE);
          }// for loop close2
          
          delay(LETTER_SPACE);
          
        }
        delay(WORD_SPACE);
    
 // }// for loop close1


  return 0;
 
} // FUNCTION messagetocw() close



//////// EEPROM WRITE / READ FUNCTIONS ///////////
void writeString(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}


String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
//////// EEPROM WRITE / READ FUNCTIONS ///////////







// Key the transmitter  // lambic keyer
void keyAndBeep(int speed)
{
  digitalWrite(P_CW, HIGH);            // Key down
  for (int i=0; i < speed; i++)    // Beep loop
  {
  
   delay(2);


  }
   digitalWrite(P_CW, LOW);             // Key up
 }
