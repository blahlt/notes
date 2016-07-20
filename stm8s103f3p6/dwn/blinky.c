#define PB_ODR *(unsigned char*)0x5005
#define PB_DDR *(unsigned char*)0x5007
#define PB_CR1 *(unsigned char*)0x5008

int main()
{
	int i = 0;
    PB_DDR = 0x20; // DDR5
    PB_CR1 = 0x20; // C15
    do {
        PB_ODR ^= 0x20; // ODR5
        for (i = 0; i < 10000; i++) { }
    } while(1);
}