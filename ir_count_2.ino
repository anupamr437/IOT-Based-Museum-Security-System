int a=0; // a counts the no of people entering
int b=0; // b counts the no of people exiting
void setup() {
pinMode(D2,INPUT); // connect Signal Out pin of Infrared Sensor at Entry to pin D2 of NodeMCU Development Board
pinMode(D3,INPUT); // connect Signal Out pin of Infrared Sensor at Exit to pin D3 of NodeMCU Development Board
pinMode(D5,OUTPUT); // connect LED positive terminal to D5 of NodeMCU Development Board
Serial.begin(9600);
}

void loop() {  
  if(digitalRead(D2)==LOW)
{
  a++;
  Serial.print("entering=");
  Serial.print(a  );
  Serial.print(" leaving=");
  Serial.println(b);
  delay(800);
  }
if(digitalRead(D3)==LOW)
{
  b++;
  Serial.print("entering=");
  Serial.print(a  );
  Serial.print(" leaving=");
  Serial.println(b);
  delay(800);
}
if(a!=b)
{
    digitalWrite(D5,HIGH);
}
if(a==b)
{
  digitalWrite(D5,LOW);
}
}
