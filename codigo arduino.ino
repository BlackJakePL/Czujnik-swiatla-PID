int sensorvalue=0;      //Variables
int pv=0;
int outputvalue=0;
int led = 3;
int pwm=0;

char cv[10];            //Se crea el array que almacenará los caracteres
byte posicion=0;          //Variable para cambiar la posición de los caracteres



void setup() {
  Serial.begin(9600);   // Inicializar el puerto serial a 9600 baudios
}


void loop() {
  sensorvalue = analogRead(A0);   // Leer entrada analogica A0 y la guardamos en la variable sensorvalue
  pv = map(sensorvalue,0,590,0,100); //los valores de pv de son de 0 a 100

  Serial.println(pv);         // Enviamos dato


  if(Serial.available())      //si detectamos datos de entrada serial
  {
    memset(cv,0,sizeof(outputvalue));
    
      while(Serial.available()>0)
      {
        cv[posicion]=Serial.read();
        posicion++;                      
        pwm=map(atoi(cv),0,100,0,255);           // la función atoi nos permite convertir los números en string a int y mapeamos los valores
      }
   posicion=0;
  }
    analogWrite(led,pwm);
    delay(50);
}
