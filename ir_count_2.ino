int a=0;
int b=0;
void setup() {
  // put your setup code here, to run once:
pinMode(D2,INPUT);
pinMode(D3,INPUT);
pinMode(D5,OUTPUT);
Serial.begin(9600);
}

void loop() {  
  // put your main code here, to run repeatedly:

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
