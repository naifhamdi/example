#define EEPEOM_DATA      PORTD 
#define EEPEOM_ADRESS_1  PORTB
#define EEPEOM_ADRESS_2  PORTC  /// ONLY C0 AND C1

#define HLT 0b1000000000000000  // Halt clock
#define MI  0b0100000000000000  // Memory address register in
#define RI  0b0010000000000000  // RAM data in
#define RO  0b0001000000000000  // RAM data out
#define IO  0b0000100000000000  // Instruction register out
#define II  0b0000010000000000  // Instruction register in
#define AI  0b0000001000000000  // A register in
#define AO  0b0000000100000000  // A register out
#define EO  0b0000000010000000  // ALU out
#define SU  0b0000000001000000  // ALU subtract
#define BI  0b0000000000100000  // B register in
#define OI  0b0000000000010000  // Output register in
#define CE  0b0000000000001000  // Program counter enable
#define CO  0b0000000000000100  // Program counter out
#define J   0b0000000000000010  // Jump (program counter in)


uint16_t cod[] = { MI|CO,  RO|II|CE,  IO|MI, RO|AI,  IO|MI, RO|BI , EO|AI , AO|OI, 0, 0,0};

byte adress=0;
void setup() {
  DDRD=B11111111;   /// SET POERD AS AN OUTPUT 
  DDRB=0XFF;   /// SET POERB AS AN OUTPUT 
  DDRC=0XFF;   /// SET POERC AS AN OUTPUT 
  EEPEOM_ADRESS_2=0B00001100;
}

void loop() {
  while(1)
  {
EEPEOM_DATA =0b10101010; 
EEPEOM_ADRESS_1= adress;
EEPEOM_ADRESS_2= adress >> 6;
EEPEOM_ADRESS_2= EEPEOM_ADRESS_2^ 0B00000100;
delay(10);
EEPEOM_ADRESS_2= EEPEOM_ADRESS_2^ 0B00000100;
delay(10);
adress++;  
  
   
  }
}
