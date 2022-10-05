#define BLYNK_PRINT Serial	// Header files for Blynk IOT Software/library
#include <BlynkSimpleEsp8266.h> #include <Blynk.h>
#include <SoftwareSerial.h>	// Serial Communication Header File /library

char auth[] = "ty8xnsSHdgIBH_Gvqouw9q9zlxu0MgM1";
//Credentials for controller to connect to Internet and app char ssid[] = "smart";
char pass[] = "123456789";

WidgetLCD lcd(V0);	// IOT app LCD pin declerations from V0 to V3 for 4LCD
WidgetLCD lcd1(V1); WidgetLCD lcd2(V2); WidgetLCD lcd3(V3);

#define B D3	// Hardware button Bill generate pin decleration

boolean stringComplete = false;	// rfid process completion identification variable
String inputString = "";		// variable to store the tag value int n = 0;	// Variables declared for Counting a,B and C items and a1,b1 and c1 for cost and t for total
int a = 0; int b = 0; int c = 0; int t = 0; int a1 = 0; int b1 = 0; int c1 = 0; int t1 = 0;
int u1 = 0;	// user 1 variable
int u2 = 0;	// user 2 variable

void setup()
{
 
Serial.begin(9600);	// Baudrate serial communication inputString.reserve(200);		// inputstring 200 character capacity (we have 12 char id)
pinMode(B, INPUT_PULLUP);	// Pin mode decleration of button
Blynk.begin(auth, ssid, pass );	// initialiing the Hardware to connect blynk cloud
lcd.clear();	// LCD IOT Display Printing commands lcd.print(0, 0, "Smart Trolley");		// Sysntax (coloum,Row." Print ");
lcd.print(0, 1, "Name:"); lcd1.clear();
lcd1.print(0, 0, "Section Items"); lcd1.print(0, 1, " A item no : "); lcd2.clear();
lcd2.print(0, 0, "B item no :");
lcd2.print(0, 1, "C item no : "); lcd3.clear();
lcd3.print(0, 0, "");
lcd3.print(0, 1, "");
delay(2000);	// wait 2 sec
}

void loop()
{
Blynk.run();	// Blynk Software commands run in loop syntax
serialEvent();	// call function for RFID reading in loop
if (stringComplete)	// if rfid is readed then enter this loop
{
Serial.println(inputString);	// print the rfid no

if (inputString == "090008D09A4B")	// 1:- USER check the rfid no for login if match then enter this loop
{
// print login name of valid tag holder
lcd.clear();	// LCD IOT commands to write lcd.print(0, 0, "Smart Trolley");
 
lcd.print(0, 1, "Name: Anushka");
stringComplete = false;		// Exit the rfid reading value inputString = "";	// make the value in the string null
in order to store another tad value
u1++;	// user 1 varable increment for detectiion of user 1
while (1)
{ // enter this loop always
Blynk.run();	// run blynk commands delay(500);
serialEvent();	// REad rfid for detecting items
if (stringComplete)	//If tag detected enter this loop
{
if (inputString == "090015210E33")	// check the tag if match enter this loop
{
lcd1.clear();	// LCD IOT commands to write lcd1.print(0, 0, "Section Items");
lcd1.print(0, 1, "A item no : ");
if (a < 1)	// If item is scaned once the count 1
{
 

write
 
lcd1.print(0, 1, "A item no : 1"); // LCD IOT commands to

a++;
stringComplete = false; inputString = "";
}
 
else if (a > 0)	// If item is scaned once again the count 0
{
 

write



}
}
 
lcd1.print(0, 1, "A item no : 0"); // LCD IOT commands to

a--;
stringComplete = false; inputString = "";
 
else if (inputString == "090008CFCF01") // check the tag if match enter this loop
{
 


write



write
 
//lcd2.clear();
lcd2.print(0, 0, "B item no :");	// LCD IOT commands to

if (b < 1)	// If item is scaned once the count 1
{
lcd2.print(0, 0, "B item no : 1");	// LCD IOT commands to

b++;
stringComplete = false; inputString = "";
}
 
else if (b > 0)	// If item is scaned once again the count 0
{
 

write



}
}
 
lcd2.print(0, 0, "B item no : 0");	// LCD IOT commands to

b--;
stringComplete = false; inputString = "";
 
else if (inputString == "090015953CB5"	)// check the tag if match enter this loop
{
 


write



write
 
//lcd3.clear();
lcd2.print(0, 1, "C item no : ");	// LCD IOT commands to

if (c < 1)	// If item is scaned once the count 1
{
lcd2.print(0, 1, "C item no : 1");	// LCD IOT commands to

c++;
stringComplete = false; inputString = "";
}
 
else if (c > 0)	// If item is scaned once again the count 0
{
lcd2.print(0, 1, "C item no : 0");	// LCD IOT commands to
write
 
c--;
stringComplete = false; inputString = "";
}
}
else	// if no match found enter this loop
{
stringComplete = false;	// make the value in the string null in order to store another tad value
inputString = "";
}
}

if (digitalRead(B) == LOW)	// If hardware button is pressed
{
 

items
 
t = (a + b + c);	// ccalculate the total no of

String toSend = "Smart Trolley Bill! \ \n";	// witer the values in
 
the string
toSend += "Name : Anushka \ \n"; toSend += "A items = ";
toSend += a;
toSend += " B items = "; toSend += b;
toSend += " C items = "; toSend += c;
toSend += " Total No of Items : "; toSend += t;
Blynk.email("anushkakanabar@gmail.com", "Smart Trolley", toSend); // enter the mail id and subject and content string to send mail of bill

if (a > 0)	// calculation of item cost
{
a1 = 10;	// a=10 rs
}
else
{
a1 = 0;
 
}
if (b > 0)
{
b1 = 15;	// b-15 rs
}
else
{
b1 = 0;
}
if (c > 0)
{
c1 = 20;	//c=20 rs
}
else
{
c1 = 0;
}
t1 = (a1 + b1 + c1);		// Calculate the cost lcd3.clear();	// LCD IOT commands to write lcd3.print(0, 0, "Total Items =");
lcd3.print(14, 0, t ); lcd3.print(0, 1, "Total Bill:"); lcd3.print(13, 1, t1);
lcd3.print(15, 1, "/-");
}
}
}

else if (inputString == "09000E235F7B")	// 2:- USER check the rfid no for login if match then enter this loop
{
// Same lines for user 2 also as user 1 lcd.clear();
lcd.print(0, 0, "Smart Trolley"); lcd.print(0, 1, "Name:UESER 1"); stringComplete = false; inputString = "";
u2++;
while (1)
{
 
Blynk.run(); delay(500); serialEvent();
if (stringComplete)
{
if (inputString == "090015210E33")
{
lcd1.clear();
lcd1.print(0, 0, "Section Items"); lcd1.print(0, 1, "A item no : ");
if (a < 1)
{
lcd1.print(0, 1, "A item no : 1"); a++;
stringComplete = false; inputString = "";
}
else if (a > 0)
{
lcd1.print(0, 1, "A item no : 0"); a--;
stringComplete = false; inputString = "";
}
}
else if (inputString == "090008CFCF01")
{
//lcd2.clear();
lcd2.print(0, 0, "B item no :"); if (b < 1)
{
lcd2.print(0, 0, "B item no : 1"); b++;
stringComplete = false; inputString = "";
}
else if (b > 0)
{
lcd2.print(0, 0, "B item no : 0"); b--;
 
stringComplete = false; inputString = "";
}
}
else if (inputString == "090015953CB5")
{
//lcd3.clear();
lcd2.print(0, 1, "C item no : "); if (c < 1)
{
lcd2.print(0, 1, "C item no : 1"); c++;
stringComplete = false; inputString = "";
}
else if (c > 0)
{
lcd2.print(0, 1, "C item no : 0"); c--;
stringComplete = false; inputString = "";
}
}
else
{
stringComplete = false; inputString = "";
}
}

if (digitalRead(B) == LOW)
{
t = (a + b + c);
String toSend = "Smart Trolley Bill! \ \n"; toSend += "Name : USER 1 \ \n";
toSend += "A items = "; toSend += a;
toSend += " B items = "; toSend += b;
toSend += " C items = ";
 
toSend += c;
toSend += " Total No of Items : "; toSend += t;
toSend += " Total Bill Amount : "; toSend += t1;
toSend += "/-"; toSend += " \ \n";
Blynk.email("anushkakanabar@gmail.com", "Smart Trolley", toSend);

if (a > 0)
{
a1 = 10;
}
else
{
a1 = 0;
}
if (b > 0)
{
b1 = 15;
}
else
{
b1 = 0;
}
if (c > 0)
{
c1 = 20;
}
else
{
c1 = 0;
}
t1 = (a1 + b1 + c1);
lcd3.clear();
lcd3.print(0, 0, "Total Items ="); lcd3.print(14, 0, t ); lcd3.print(0, 1, "Total Bill:"); lcd3.print(11, 1, t1);
 
lcd3.print(13, 1, "/-");	// user 2 :- sysntax ends
here
}
}
}

else	// if invalivalid login card detected
{
lcd.clear();	// LCD IOT commands to write lcd.print(0, 0, "Smart Trolley");
lcd.print(0, 1, "Show RFID Tag"); stringComplete = false; inputString = "";
}
}


}

void serialEvent()	// RFID LOOp
{
while (Serial.available())	// if any value is available at rx of the controller
{
n++;	// count increment to check 12 digit rfid no char inChar = (char)Serial.read();	// store the read value in
variable
inputString += inChar;		//store the value in string to read if (n >= 12)	// wait till 12 digit string gets completed
{
n = 0;
stringComplete = true;	// String completed
}
}
}

BLYNK_WRITE(V4)	// Button connected to V4 pin of iot APP
{
 
if (param.asInt() == 1)	// If button is pressed do same as hardware buton is pressed
{
if (u1 > 0)	//	Same lines of hardware button
press
{
{

t = (a + b + c); if (a > 0)
{
a1 = 10;
}
else
{
a1 = 0;
}
if (b > 0)
{
b1 = 15;
}
else
{
b1 = 0;
}
if (c > 0)
{
c1 = 20;
}
else
{
c1 = 0;
}
t1 = (a1 + b1 + c1);
String toSend = "Smart Trolley Bill! \ \n"; toSend += "Name : Anushka \ \n"; toSend += "A items = ";
toSend += a;
toSend += " B items = "; toSend += b;
 
toSend += " C items = "; toSend += c;
toSend += " Total No of Items : "; toSend += t;
toSend += " Total Bill Amount : "; toSend += t1;
toSend += "/-"; toSend += " \ \n";
Blynk.email("anushkakanabar@gmail.com", "Smart Trolley", toSend);




lcd3.clear();
lcd3.print(0, 0, "Total Items ="); lcd3.print(14, 0, t ); lcd3.print(0, 1, "Total Bill:"); lcd3.print(13, 1, t1);
lcd3.print(15, 1, "/-");
}
}
else if (u2 > 0)
{
{
t = (a + b + c); if (a > 0)
{
a1 = 10;
}
else
{
a1 = 0;
}
if (b > 0)
{
b1 = 15;
}
else
{
b1 = 0;
 
}
if (c > 0)
{
c1 = 20;
}
else
{
c1 = 0;
}
t1 = (a1 + b1 + c1);
String toSend = "Smart Trolley Bill! \ \n"; toSend += "Name : USER 1 \ \n";
toSend += "A items = "; toSend += a;
toSend += " B items = "; toSend += b;
toSend += " C items = "; toSend += c;
toSend += " Total No of Items : "; toSend += t;
toSend += " Total Bill Amount : "; toSend += t1;
toSend += "/-"; toSend += " \ \n";
Blynk.email("anushkakanabar@gmail.com", "Smart Trolley", toSend);



lcd3.clear();
lcd3.print(0, 0, "Total Items ="); lcd3.print(14, 0, t ); lcd3.print(0, 1, "Total Bill:"); lcd3.print(11, 1, t1);
lcd3.print(13, 1, "/-");	// Button pressed commands ends here
}
}

}
 
else	// if not press do nothing
{

}
}
