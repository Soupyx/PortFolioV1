/* 
 * Code pour la cuve a eau de pluie
 */
// inclure la librairie écran:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* pour la Température de la cuve

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
*/

//pour le bouton

const byte bouton = 7;
boolean bp;
char pb;
char compteur;
const byte eclair = 10;

//pour le volume:

float volume = 0; //volume de la cuve
int volume_L = 0; //volume en Litre de la cuve
float hauteur_cm ; //en cm
int hauteur_cuve = 280 ; //en cm
int largeur_cuve = 220; //en cm
int longueur_cuve = 200 ; //en cm

/* Constantes pour les broches a capteur ultrason */
const byte TRIGGER_PIN = 8; // Broche TRIGGER
const byte ECHO_PIN = 9;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

/** Fonction setup() */

void setup() {

  pb = 0;
  bp = 0;
  compteur = 0;
  pinMode(eclair, OUTPUT);
  pinMode(bouton, INPUT);
   
  /* Initialise le port série */
//  Serial.begin(9600);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);

// affichage écran
  
  digitalWrite(eclair, HIGH);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("visualisation");
  lcd.setCursor(0, 1);
  lcd.print("niveau de cuve");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("dimension cuve");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" H     l     L");
  lcd.setCursor(0, 1);
  lcd.print(hauteur_cuve);
  lcd.setCursor(6, 1);
  lcd.print(largeur_cuve);
  lcd.setCursor(12, 1);
  lcd.print(longueur_cuve);
  delay(2000);
  lcd.clear();
  digitalWrite(eclair, LOW);

}

void loop() {
//bouton
bp = digitalRead(bouton);
if (bp == 1){
  pb = 1;
}
 
int compteur = 0;
while ((compteur != 4) && (pb == 1)){
  affichage();
  compteur ++;
}
pb = 0;
digitalWrite(eclair, LOW);
lcd.clear();
}

void affichage(){
lcd.clear();
   affichage_1();
delay(5000);
  affichage_2();
delay(5000); 
}

void capteur() {
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;

// calcule de la quantité d'eau
  
  hauteur_cm = (hauteur_cuve - (distance_mm / 10.0)); // calcule de la hauteur en centimetre
  volume =( hauteur_cm * largeur_cuve * longueur_cuve * 0.000001);// volume en m3, rentré dimension en mètre de la cuve (M=Hauteur * largeur * longeur)
  volume_L =(volume * 1000); //volume en litre 
}

// Affiche les résultats
// Affiche par l'écran LCD
int affichage_1() {
capteur();
digitalWrite(eclair, HIGH);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print(volume);
lcd.setCursor(6, 0);
lcd.print("Metre cube");
lcd.setCursor(0, 1);
lcd.print(volume_L);
lcd.setCursor(6, 1);
lcd.print("Litres");
}

int affichage_2() {
capteur();
lcd.clear();
lcd.setCursor(0, 1);
lcd.print(hauteur_cm);
lcd.setCursor(7, 1);
lcd.print("cm");
lcd.setCursor(0, 0);
lcd.print("Hauteur de l'eau"); 
}