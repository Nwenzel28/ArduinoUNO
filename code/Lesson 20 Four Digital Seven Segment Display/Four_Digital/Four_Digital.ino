//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,
 0x39,0x5e,0x79,0x71,0x00};

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void Display(unsigned char num)
{
  if (num >= sizeof(table)) return;  // skip if invalid index
  Serial.print("Displaying number: ");
  Serial.println(num);
  digitalWrite(latch, LOW);
  delayMicroseconds(50);  // small delay to stabilize latch
  shiftOut(data, clock, MSBFIRST, table[num]);
  delayMicroseconds(50);  // small delay before latch goes HIGH
  digitalWrite(latch, HIGH);
}


void loop() {

  for (int i = 1; i <= 15; i++) {
    Display(i); // Works
    delay(500);
    Display(i); // Not Working
    delay(1300);
  }

}
