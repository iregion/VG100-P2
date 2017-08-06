int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
bool f1 = false, f2 = false, f3 = false, f4 = false, f5 = false;
int st1, st2, st3, st4, st5; 
int sf1, sf2, sf3, sf4, sf5;   
unsigned long st = 0;
int situation = 0;
int presituation = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  presituation = situation;
  situation = 0;
  st1 = st2 = st3 = st4 = st5 = 0;
  sf1 = sf2 = sf3 = sf4 = sf5 = false;
  st = millis();
while (millis() - st < 200)
{
t1 = analogRead(0);
t2 = analogRead(1);
t3 = analogRead(2);
t4 = analogRead(3);
t5 = analogRead(4);
f1 = digitalRead(2);
f2 = digitalRead(3);
f3 = digitalRead(4);
f4 = digitalRead(5);
f5 = digitalRead(6);
if (t1 > 50 && t1 < 300 && st1 == 0)
{
  st1 = 1;
}
if (t1 > 300)
{
  st1 = 2;
}
if (t2 > 100 && t2 < 400 && st2 == 0)
{
  st2 = 1;
}
if (t2 > 400)
{
  st2 = 2;
}
if (t3 > 100 && t3 < 300 && st3 == 0)
{
  st3 = 1;
}
if (t3 > 300)
{
  st3 = 2;
}
if (t4 > 250 && t4 < 420 && st4 == 0)
{
  st4 = 1;
}
if (t4 > 420)
{
  st4 = 2;
}
if (t5 > 100 && t5 < 300 && st5 == 0)
{
  st5 = 1;
}
if (t5 > 300)
{
  st5 = 2;
}
if (f1 == true && st1 != 0)
{
  sf1 = true;
}
if (f2 == true && st2 != 0)
{
  sf2 = true;
}
if (f3 == true && st3 != 0)
{
  sf3 = true;
}
if (f4 == true && st4 != 0)
{
  sf4 = true;
}
if (f5 == true && st5 != 0)
{
  sf5 = true;
}
Serial.write(0);
}
st = 0;

if (st1 == 1)
  situation = situation + 19683;
if (st1 == 2)
  situation = situation + 39366;
if (st2 == 1)
  situation = situation + 2187;
if (st2 == 2)
  situation = situation + 4374;
if (st3 == 1)
  situation = situation + 243; 
if (st3 == 2)
  situation = situation + 486; 
if (st4 == 1)
  situation = situation + 27;
if (st4 == 2)
  situation = situation + 54;  
if (st5 == 1)
  situation = situation + 3;
if (st5 == 2)
  situation = situation + 6;
if (sf1 == 1)
  situation = situation + 6561;
if (sf2 == 1)
  situation = situation + 729;
if (sf3 == 1)
  situation = situation + 81;
if (sf4 == 1)
  situation = situation + 9;
if (sf5 == 1)
  situation = situation + 1;
if (situation ==  presituation || situation ==  presituation * 2 || 2 * situation ==  presituation)
{
  presituation = 0;
  return;
}
else
{
switch (situation)
{
case 19683:
Serial.write(-112);
break;

case 2187:
Serial.write(-106);
break;

case 243:
Serial.write(-124);
break;

case 27:
Serial.write(-111);
break;

case 3:
Serial.write(-109);
break;

case 39366:
Serial.write(-128);
break;

case 4374:
Serial.write(-110);
break;

case 486:
Serial.write(-125);
break;

case 54:
Serial.write(-123);
break;

case 6:
Serial.write(-122);
break;

case 21870:
Serial.write(-103);
break;

case 2430:
Serial.write(-105);
break;

case 270:
Serial.write(-126);
break;

case 30:
Serial.write(-107);
break;

case 2457:
Serial.write(-61);
break;

case 2214:
Serial.write(-64);
break;
}
}
}

