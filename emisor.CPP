#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#define PUERTO 0

char meaning [16] [40];
char bitos [16];

void mensajes()
{
strcpy(meaning[0], "Delta clear to send");
strcpy(meaning[1], "Delta data set ready");
strcpy(meaning[2], "Trailing edge ring detector");
strcpy(meaning[3], "Delta receive line signal detec");
strcpy(meaning[4], "Clear to send (CTS)");
strcpy(meaning[5], "Data set ready (DSR)");
strcpy(meaning[6], "Ring indicator");
strcpy(meaning[7], "Receive line signal detect");
strcpy(meaning[8], "Data available");
strcpy(meaning[9], "Overrun error");
strcpy(meaning[10], "Parity error");
strcpy(meaning[11], "Framing error");
strcpy(meaning[12], "Break detectino error");
strcpy(meaning[13], "Transmitter holding register empty");
strcpy(meaning[14], "Transmitter shift register empty");
strcpy(meaning[15], "Time out error");
}

void banderas(unsigned int registro)
{
 char i;
 unsigned int filtro,fbit;
 for(i=0; i<16; i++)
 {
  filtro= 0x1 << i;
  fbit  = registro & filtro;
  fbit  = fbit >> i;
  bitos[i] = fbit;
 }
}

void pbanderas()
{
	char i;
	 for(i=0; i<16; i++)
	 {
		 printf("%35s:\t %x \n",meaning[i],bitos[i]);
	 }
}


union REGS inicializar()
{
	union REGS ent,sal;

	ent.h.ah=0x0;
	ent.h.al=0xe3;
	ent.x.dx=PUERTO;
	int86(0x14,&ent,&sal);
	return(sal);

}

union REGS enviar(char carac)
{
	union REGS ent,sal;

	ent.h.ah=0x1;
	ent.h.al=carac;
	ent.x.dx=PUERTO;
	int86(0x14,&ent,&sal);
	return(sal);

}

union REGS recibir()
{
	union REGS ent,sal;

	ent.h.ah=0x2;
	ent.x.dx=PUERTO;
	int86(0x14,&ent,&sal);
	return(sal);

}

union REGS status()
{
	union REGS ent,sal;

	ent.h.ah=0x3;
	ent.x.dx=PUERTO;
	int86(0x14,&ent,&sal);
	return(sal);

}


/*Programa Principal*/

void main()
{
	union REGS vint,vout;
	unsigned int pn;
	char para,letra;
	/*inicializacion del puerto*/
	mensajes();
	clrscr();
	pn=0;
	para=0;
	vout=inicializar();

	do
	{
		letra =getch();
		vout=enviar(letra);
		printf("%i  %i  %c \n",pn,letra,letra);
		pn++;
		para = letra;
	}while(para != '\'');
}
