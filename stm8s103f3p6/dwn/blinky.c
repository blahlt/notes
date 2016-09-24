#define PB_ODR *(unsigned char*)0x5005 // Port B data output latch register (Datasheet, 32 page, Table 7. I/O port hardware register map)
#define PB_DDR *(unsigned char*)0x5007 // Port B data direction register (Datasheet, 32 page, Table 7. I/O port hardware register map)
#define PB_CR1 *(unsigned char*)0x5008 // Port B control register 1 (Datasheet, 32 page, Table 7. I/O port hardware register map )

int main()
{
  int i = 0;
  PB_DDR = 0x20; // PB5 port as output ~ 0x20 = 0b0010 0000 (0: Input mode, 1: Output mode)
  PB_CR1 = 0x20; // PB5 port push-pull ~ 0x20 = 0b0010 0000 (In output mode (DDR = 1): (0: Pseudo open drain, 1: Push-pull))
  do {
    PB_ODR ^= 0x20; // PB5 port toggle ~ 0x20 = 0b0010 0000 (Writing to the ODR register when in output mode applies a digital value to the I/O through the latch)
    for (i = 0; i < 10000; i++) { } // delay
  } while(1);
}
