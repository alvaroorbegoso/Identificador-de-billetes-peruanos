//REFERENCIA DE LA PLACA IMPRESO  12895 SAS ULTIMA

#include "\RAM_PORTS.h"
#include "\ID024.h"
#include "\ID003.h"

#use      delay(clock=32000000)
#fuses    NOJTAG,NOWDT,PROTECT,WRT,NODEBUG,XT,PR_PLL

#pin_select U2TX  = PIN_B5 //COMUNICACION CON BV
#pin_select U2RX  = PIN_B8 //COMUNICACION CON BV
#pin_select U1TX  = PIN_B4  //COMUNICACION CON MAQUINA
#pin_select U1RX  = PIN_B7  //COMUNICACION CON MAQUINA


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#INT_ADDRERR
void isr_TRAP ()
{while(1){#asm
          reset
          #endasm}  
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//PARA EL CONTEO DE ESPACIO INTERTRAMA
//setup_timer3((TMR_INTERNAL | TMR_DIV_BY_64),0xFFFA); 2.56MS
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_TIMER2 LEVEL=5
void isr_timer2 ()
{char MOLEX=0;
 T2ON=0;
 disable_interrupts(int_TIMER2);
 LISTO_BUFFER_ID024();
 CONTAOR_BYTES_ID024=0;
 output_low(VISUAL_C);
 set_timer2(0);
 for(MOLEX=0;MOLEX<10;MOLEX++){BUFFER_ID024_RX[MOLEX]=200;}
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//COMUNICACION CON MAQUINA ID024
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_RDA   LEVEL=5
void serial_isr()
{int16 FG=0;char RXREG1;
 FG=U1RXREG;
 RXREG1=make8(FG,0);
 output_high(VISUAL_C); 
 
 BUFFER_ID024_RX[CONTAOR_BYTES_ID024]=RXREG1;
 CONTAOR_BYTES_ID024++;
 

 if(CONTAOR_BYTES_ID024>50){CONTAOR_BYTES_ID024=0;}

 clear_interrupt(int_TIMER2);
 if(CONTAOR_BYTES_ID024==1){set_timer2(0);T2ON=1;enable_interrupts(int_TIMER2);} 

 if(U1OERR){U1OERR=0;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//BUFFER_EMPTY
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_TBE LEVEL=5
void isr_TBE()
{char MOLEX=0;
 MOLEX=BUFER_ENVIO_ID024[PUNT_ENV_ID024];
 ENVIAR_U1(0,MOLEX);
 PUNT_ENV_ID024++;
 if(PUNT_ENV_ID024==BYTES_A_ENVIAR_ID024)
   {disable_interrupts(int_TBE);
    enable_interrupts(int_RDA);
   } 
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//COMUNICACION CON BILLETERO RECEPCION ID003
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_RDA2   LEVEL=5
void isr_int_RDA2()
{int FG=0;char RXREG2;
 FG=U2RXREG; 
 RXREG2=make8(FG,0);

 CONTAOR_BYTES_U2++;
 if(CONTAOR_BYTES_U2>55){CONTAOR_BYTES_U2=0X00;
                         BANDER_BUFFER_INU2=0;}

 if(BANDER_BUFFER_INU2=0){if(RXREG2==0XFC)
                            {CONTAOR_BYTES_U2=0X01;
                             BANDER_BUFFER_INU2=1;}                        
                         }

BUFFER_RX_ID003[CONTAOR_BYTES_U2]=RXREG2;  

if(BUFFER_RX_ID003[2]==CONTAOR_BYTES_U2) {LISTO_BUFFER_ID003();
                                          output_toggle(VISUAL_B);}


 if(U2OERR){U2OERR=0;}
 
 //ENVIAR_U1(0,FG);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//1.048SEGUNDOS LLAMAR A RUTINAS REACTIVAR ENVIOS 
//LATENCIA 3 SEGUNDOS
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#int_TIMER3 LEVEL=5
void isr_TIMER3()
{static char MOLEX=0;
 MOLEX++;
 if(MOLEX==2){TEMPO_ID003();MOLEX=0;}
 TEMPO_ID024();
// DOSIF++;
// if(DOSIF==100&&FLAGET==0){DOSIF=0;FLAGET=1;
//               BUFFER_BILLETES[0]=5;BUFFER_BILLETES[1]=5;
//	           }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//BUFFER_EMPTY
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_TBE2 LEVEL=5
void isr_TBE2()
{char MOLEX=0;  if(PUNT_ENV_2==BUFFER_ENVIO_ID003[1]){disable_interrupts(int_TBE2);
                                       CONTAOR_BYTES_U2=0X00;
                                       BANDER_BUFFER_INU2=0;}
 else {ENVIAR_U2(0,BUFFER_ENVIO_ID003[PUNT_ENV_2]);}
 PUNT_ENV_2++;
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX

#int_TIMER1 LEVEL=5
void isr_timer1 ()
{
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void main(void) 
{


CONFIG_PORTS();

//LISTO_BUFFER_ID024();


 enable_interrupts(INT_TIMER3)  ;
 T2ON=0;set_timer2(0);
 clear_interrupt(int_TIMER2);
 disable_interrupts(INT_TIMER2) ;
 enable_interrupts(INT_TIMER1)  ;
 enable_interrupts(INT_RDA)     ;
 enable_interrupts(INT_RDA2)    ;
 enable_interrupts(INTR_GLOBAL) ;

T2ON=1;set_timer2(0); 
enable_interrupts(INT_TIMER2) ;


 while(1)
    {if(!RIDLE1){set_timer2(0);}
    }

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX




}
//CAMBIO DEL 15 DICIEMBRE PARA PROCESAR EL FIN DE TRAMA ATRAVEZ DE CONTEO DE
//BYTES Y COMPARACION CON EL CAMPO DE NUMERO DE BYTES Y TAMBIEN CON
//LOS TRES BYTES FE CUALQUIERA DE LAS CONDICIONES QUE SE DETECTE