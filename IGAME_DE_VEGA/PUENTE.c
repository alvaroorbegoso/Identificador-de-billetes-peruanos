//REFERENCIA DE LA PLACA IMPRESO  12895 SAS ULTIMA

#include "\RAM_PORTS.h"
#include "\ID003.h"
#include "\ID024.h"


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
//COMUNICACION CON MAQUINA
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_RDA   LEVEL=5
void serial_isr()
{int16 FG=0;char RXREG1;
 FG=U1RXREG;
 RXREG1=make8(FG,0);
 output_toggle(VISUAL_C);
 if(U1OERR){U1OERR=0;}
 ENVIAR_U2(0,FG);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//SE ENCARGA DE LLENADO DE PILA Y DETECCION DE ERRORES
//EJEMPLO DE UNA TRAMA VALIDA
//FF FF FF 0D 00 00 01 20 01 02 03 01 06 DD 58 61 FE FE FE
//COMUNICACION CON PC BUFFER_RX_PC TAMAÑO 35 BYTES
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_RDA2   LEVEL=5
void isr_int_RDA2()
{int FG=0;char RXREG2;
 FG=U2RXREG; 
 RXREG2=make8(FG,0);
 if(U2OERR){U2OERR=0;}
 output_toggle(VISUAL_B);
 ENVIAR_U1(0,FG);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//1.048SEGUNDOS LLAMAR A RUTINAS REACTIVAR ENVIOS 
//LATENCIA 3 SEGUNDOS
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#int_TIMER3 LEVEL=5
void isr_TIMER3()
{char MOLEX=0;
 output_toggle(VISUAL_D);//ENVIAR_U1(0,0x35);ENVIAR_U2(0,0x45);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//BUFFER_EMPTY
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#int_TBE LEVEL=5
void isr_TBE()
{char MOLEX=0;
 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//env_mch buffer de envio a maquina
//103 ms, de aqui se llaman rutinas de contadores para 
//encajarlos en sus respectivos buffers
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_TIMER2 LEVEL=5
void isr_timer2 ()
{char MOLEX=0;
 
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#int_TIMER1 LEVEL=5
void isr_timer1 ()
{
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void main(void) 
{

//pruebas
//PASA_BUFFER_1C();
//CONTA_RX1=0X08;
//PASA_BUFFER_11();
 CONFIG_PORTS();
 enable_interrupts(INT_TIMER3)  ;
 enable_interrupts(INT_TIMER2)  ;
 enable_interrupts(INT_TIMER1)  ;
 enable_interrupts(INT_RDA)     ;
 enable_interrupts(INT_RDA2)    ;
 enable_interrupts(INTR_GLOBAL) ; 

  while(1)
       {
       }
}
//CAMBIO DEL 15 DICIEMBRE PARA PROCESAR EL FIN DE TRAMA ATRAVEZ DE CONTEO DE
//BYTES Y COMPARACION CON EL CAMPO DE NUMERO DE BYTES Y TAMBIEN CON
//LOS TRES BYTES FE CUALQUIERA DE LAS CONDICIONES QUE SE DETECTE