#include "project.h"


/*************************************************************************************************/

void delay_ms(unsigned int n)
{
	unsigned int count = 0;
	unsigned int flag;
	while (count <= n)
	{
		do
		{
			flag = read_reg(SYST_CSR, (1 << 16));
		}
		while(0 == flag);
		count++;
	}
	count = 0;
}
void main(void)
{
	/*Init clock*/
	system_init();
	/*enable clock*/
	enabled_clock();
	/*Init pin*/
	pin_init();
	
	while(1)
	{
		led_on(LD3_PIN);
		delay_ms(1000); //0.5s
		led_off(LD3_PIN);
		delay_ms(1000); //0.5s
	}
}

