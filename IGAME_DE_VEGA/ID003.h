enum   {NORMAL_ID003,BILLETE_ID003,INICIALIZAR};//SUPER ESTADOS

enum   {NULO,INTERROGAR_ESTADOS,INTERROGAR_VERSION,POWER_UP_M,SET_C0_DATA,
        SET_C1_DATA,SET_C4_DATA,SET_C5_DATA,SET_C3_DATA,SET_C6_DATA,
        SET_C7_DATA,SET_80_DATA,SET_84_DATA,SET_81_DATA,SET_83_DATA,
        SET_86_DATA,SET_87_DATA,SET_89_DATA,ACTIVAR_DATA,DESACTIVAR_DATA,
        ESCROW,ACK_DATA,ORDEN_ESTAKAR_ID003,CONTESTAR_ACK_ID003};//ESTADOS SIMULADOS DE  MAQUINA SIMULADA EN PROCESO DE INICIALIZACION

enum   {DISABLE,IDLE,ACEPTING,REJECTING,DENOM_2,DENOM_5,DENOM_10,
        DENOM_20,DENOM_50,STAKING,VALID_VENT,BILL_GUARDADO,
        HOLDING};//ESTADOS EN PROCESO DE BILL


unsigned char ES_VEGA=0XFF;
unsigned char ID_CK=0;
char  klp;
char  EL_BILLETE_ID003=0;
char  ARGUMENT_BILL_ID003=0;
char  ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
char  ESTADOS_ID003_BILL=NULO;
char  SUPER_ESTADOS_ID003_MQ=INICIALIZAR;
char  BUFFER_ENVIO_ID003[50]={};
char  BUFFER_RX_ID003[70]={};
char  CONTA_ENVIO2=0;
char  PUNT_ENV_2=0;
char  CONTAOR_BYTES_U2=0;
char  BANDER_BUFFER_INU2=0;//INDICA LA LLEGADA DE UN BYTE FC

           CONST unsigned int TRAMA_B2[]             = {0xFC,0x06,0x13,0x62,0X2B,0XC9}  ;
           CONST unsigned int TRAMA_B5[]             = {0xFC,0x06,0x13,0x63,0XA2,0XD8}  ;
           CONST unsigned int TRAMA_B10[]            = {0xFC,0x06,0x13,0x64,0X1D,0XAC}  ;
           CONST unsigned int TRAMA_B20[]            = {0xFC,0x06,0x13,0x65,0X94,0XBD}  ;
           CONST unsigned int TRAMA_B50[]            = {0xFC,0x06,0x13,0x66,0X0F,0X8F}  ;
           CONST unsigned int ORDEN_PASAR[]          = {0xFC,0x05,0x42,0x39,0X036}      ;
           CONST unsigned int ESTAKANDO[]            = {0xFC,0x05,0x14,0x8A,0X01}      ;
           CONST unsigned int VENTA_VALIDA[]         = {0xFC,0x05,0x15,0x03,0X10}      ;
           CONST unsigned int GUARDADO[]             = {0xFC,0x05,0x16,0x98,0X22}      ;
           CONST unsigned int RETENIENDO[]           = {0xFC,0x05,0x19,0x6F,0XDA}      ;
                
           CONST unsigned int BILL_DESC[]       = {0xFC,0x06,0x17,0x77,0X67,0XE9}  ;
           CONST unsigned int ACEPTANDO[]       = {0xFC,0x05,0x12,0xBC,0X64}  ;
           CONST unsigned int ACTIVADO_TABLA[]  = {0XFC,0X05,0X11,0X27,0X56}  ;
           CONST unsigned int DESACTIVADO[]     = {0XFC,0X05,0X1A,0XF4,0XE8}  ;  
           CONST unsigned int POWER_UP_DATA[]   = {0XFC,0X05,0X40,0X2B,0X15}  ;
	       CONST unsigned int INITIALIZER[]     = {0XFC,0X05,0X1B,0X7D,0XF9}  ;	                
           
           CONST unsigned int SET_C0[]          = {0xFC,0x07,0xC0,0x80,0X00,0XE1,0X39}  ;
           CONST unsigned int SET_C1[]          = {0xFC,0x07,0xC1,0xFF,0X00,0X31,0X10}  ;//FF| 00| 31| 10|
           CONST unsigned int SET_C4[]          = {0xFC,0x06,0xC4,0x00,0X0C,0X9B}       ;// 00| 0C| 9B|
           CONST unsigned int SET_C5[]          = {0xFC,0x06,0xC5,0x03,0X4F,0XB0}       ;//03| 4F| B0|
           CONST unsigned int SET_C3[]          = {0xFC,0x06,0xC3,0x00,0X04,0XD6}       ;//00| 04| D6|
           CONST unsigned int SET_C6[]          = {0xFC,0x07,0xC6,0x01,0X12,0XBF,0X49}  ;//01| 12| BF| 49|
           CONST unsigned int SET_C7[]          = {0xFC,0x06,0xC7,0xFF,0X1C,0XBE}       ;//FF| 1C| BE|

           CONST unsigned int SET_89[]          = {0xFC,0x05,0x89,0xE6,0X4E};//
           CONST unsigned int SET_80[]          = {0xFC,0x05,0x80,0x27,0XD3};//
           CONST unsigned int SET_84[]          = {0xFC,0x05,0x84,0x03,0X95};//
           CONST unsigned int SET_81[]          = {0xFC,0x05,0x81,0xAE,0XC2};//
           CONST unsigned int SET_83[]          = {0xFC,0x05,0x83,0xBC,0XE1};//
           CONST unsigned int SET_86[]          = {0xFC,0x05,0x86,0x11,0XB6};//
           CONST unsigned int SET_87[]          = {0xFC,0x05,0x87,0x98,0XA7};//
           CONST unsigned int VERSION_REQUEST[] = {0xFC,0x05,0x88,0x6F,0X5F};//
           CONST unsigned int ACK_1[]           = {0XFC,0X05,0X50,0XAA,0X05};

           CONST unsigned int ACTIVAR_VEGA[]    = {0XFC,0X06,0XC3,0X00,0X04,0XD6};
           CONST unsigned int DESACTIVAR_VEGA[] = {0XFC,0X06,0XC3,0X01,0X8D,0XC7};


           CONST unsigned int ACTIVAR_BILL[]    = {0XFC,0X06,0XC7,0XFC,0X87,0X8C};
           CONST unsigned int DESACTIVAR_BILL[] = {0XFC,0X06,0XC7,0XFF,0X1C,0XBE};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//char  COMMANDO_A_ID003=0;
//char  ARGUMENTO_A_ID003=0;
//char  COMMANDO_A_ID024=0;
//char  ARGUMENTO_A_ID024=0;
//char  ACTIVATE_ID003=0;

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//RECEPCION TRAMAS DE BILLETERO
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void LISTO_BUFFER_ID003(void)
{CONTAOR_BYTES_U2=0X00;
 BANDER_BUFFER_INU2=0;
 ARGUMENT_BILL_ID003==BUFFER_RX_ID003[4];
 ESTADOS_ID003_BILL=BUFFER_RX_ID003[3];

 if(SUPER_ESTADOS_ID003_MQ==INICIALIZAR)
  {switch(ESTADOS_ID003_BILL)//lee el estado del billetero y modifica el estado de la maquina
          {case(POWER_UP_DATA[2]):ESTADOS_ID003_MQ=POWER_UP_M;
                                                   break;
           case(0X1B):ESTADOS_ID003_MQ=POWER_UP_M;
                                       break;
           case(ACK_1[2]):ESTADOS_ID003_MQ=SET_89_DATA;
                                           break;
           case(SET_89[2]):ESTADOS_ID003_MQ=INTERROGAR_VERSION;
                                            break;
           case(VERSION_REQUEST[2]):ESTADOS_ID003_MQ=SET_87_DATA;
                                    if(BUFFER_RX_ID003[4]=='V')
                                        {ES_VEGA=1;ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                         SUPER_ESTADOS_ID003_MQ=NORMAL_ID003;} 
                                    break;
           case(SET_87[2]):ESTADOS_ID003_MQ=SET_86_DATA;
                                            break;
           case(SET_86[2]):ESTADOS_ID003_MQ=SET_84_DATA;
                                            break;
           case(SET_84[2]):ESTADOS_ID003_MQ=SET_83_DATA;
                                            break;
           case(SET_83[2]):ESTADOS_ID003_MQ=SET_81_DATA;
                                            break;
           case(SET_81[2]):ESTADOS_ID003_MQ=SET_80_DATA;
                                            break;
           case(SET_80[2]):ESTADOS_ID003_MQ=SET_C0_DATA;
                                            break;
           case(SET_C0[2]):ESTADOS_ID003_MQ=SET_C1_DATA;
                                            break;
           case(SET_C1[2]):ESTADOS_ID003_MQ=SET_C3_DATA;
                                            break;
           case(SET_C3[2]):ESTADOS_ID003_MQ=SET_C4_DATA;
                                            break;
           case(SET_C4[2]):ESTADOS_ID003_MQ=SET_C5_DATA;
                                            break;
//           case(SET_C5[2]):ESTADOS_ID003_MQ=SET_C6_DATA;
//                                            break;
           case(0X4B)     :ESTADOS_ID003_MQ=SET_C6_DATA;
                           if(ES_VEGA==1){ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                          SUPER_ESTADOS_ID003_MQ=NORMAL_ID003;
                                         }
                           break;
           case(SET_C6[2]):ESTADOS_ID003_MQ=SET_C7_DATA;
                                            break;
           case(SET_C7[2]):ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;//AQUI MODIFICAR SUPER ESTADOS
                                            break;
           case(0X1A):ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;//AQUI MODIFICAR SUPER ESTADOS
                                       SUPER_ESTADOS_ID003_MQ=NORMAL_ID003;
                                       break;
          }
  } 

if(SUPER_ESTADOS_ID003_MQ==NORMAL_ID003)
   {switch(ESTADOS_ID003_BILL)//lee el estado del billetero y modifica el estado de la maquina
          {case(POWER_UP_DATA[2]):SUPER_ESTADOS_ID003_MQ=INICIALIZAR;
                                  ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                  break;
           case(0X1B):SUPER_ESTADOS_ID003_MQ=INICIALIZAR;//BILLETERO REPORTA INICIALIZANDO
                                  ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                  break;
           case(DESACTIVADO[2]):if(ACTIVATE_ID003==1)//SE REPORTA DESACTIVADO EL BILL PERO DEBERIA ESTAR ACTIVADO
                                   {ESTADOS_ID003_MQ=ACTIVAR_DATA;}
                                  break;
           case(ACTIVADO_TABLA[2]):if(ACTIVATE_ID003==0)//SE REPORTA DESACTIVADO EL BILL PERO DEBERIA ESTAR ACTIVADO
                                   {ESTADOS_ID003_MQ=DESACTIVAR_DATA;}
                                   break;
           case(ACEPTANDO[2])     :ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                   SUPER_ESTADOS_ID003_MQ=BILLETE_ID003;
                                   break;
           case(ACTIVAR_BILL[2]):if(ESTADOS_ID003_MQ==ACTIVAR_DATA)//RESPUESTA
                                   {ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;}
                                 if(ESTADOS_ID003_MQ==DESACTIVAR_DATA)//RESPUESTA
                                   {ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;}
                                 break;
           case(ACTIVAR_VEGA[2]):if(ESTADOS_ID003_MQ==ACTIVAR_DATA)//RESPUESTA
                                   {ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;}
                                 if(ESTADOS_ID003_MQ==DESACTIVAR_DATA)//RESPUESTA
                                   {ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;}
                                 break;
          }
   }

if(SUPER_ESTADOS_ID003_MQ==BILLETE_ID003)//RECIBE DE BILL
   {switch(ESTADOS_ID003_BILL)
          {case(TRAMA_B2[2]):EL_BILLETE_ID003=BUFFER_RX_ID003[4];
                             ESTADOS_ID003_MQ=ORDEN_ESTAKAR_ID003;
                             break;
           case(ACK_1[2]):switch(ESTADOS_ID003_MQ)
                                {case(ORDEN_ESTAKAR_ID003):ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                                           break;                                      
                                      
                                }                          
                          break;
           case(VENTA_VALIDA[2]):ESTADOS_ID003_MQ=CONTESTAR_ACK_ID003;
                                 switch(EL_BILLETE_ID003)
                                        {case(0x61):BUFFER_BILLETES[0]=1;
                                                    BUFFER_BILLETES[1]=0;
                                                    break;
                                         case(0x62):BUFFER_BILLETES[0]=1;
                                                    BUFFER_BILLETES[1]=1;
                                                    break;
                                         case(0x63):BUFFER_BILLETES[0]=5;
                                                    BUFFER_BILLETES[1]=0;
                                                    break;
                                         case(0x64):BUFFER_BILLETES[0]=10;
                                                    BUFFER_BILLETES[1]=0;
                                                    break;
                                         case(0x65):BUFFER_BILLETES[0]=20;
                                                    BUFFER_BILLETES[1]=0;
                                                    break;
                                         case(0x66):BUFFER_BILLETES[0]=50;
                                                    BUFFER_BILLETES[1]=0;
                                                    break;
                                        }
                                 break;
           case(ACTIVADO_TABLA[2]):SUPER_ESTADOS_ID003_MQ=NORMAL_ID003;
                                   ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                   break;

          }
   }

                     
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



void PROCESAR_COMANDOS_DE_ID024(void)
{switch(COMMANDO_A_ID003)
  {case ACTIVAR_A_ID003:ACTIVATE_ID003=1;
                        COMMANDO_A_ID003=0;//MARCA COMO PROCESADO  
                        break;
   case DESACTIVAR_A_ID003:ACTIVATE_ID003=0;
                        COMMANDO_A_ID003=0;//MARCA COMO PROCESADO  
                        break;
   case RESET_A_ID003:ACTIVATE_ID003=0;
                      COMMANDO_A_ID003=0;//MARCA COMO PROCESADO  
                      SUPER_ESTADOS_ID003_MQ=INICIALIZAR;
                      ESTADOS_ID003_MQ=POWER_UP_M;
                      break;

  }

}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//ARRIBA RESPUESTA DE BILLETERO
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//ACCION TEMPORAL DE LA MAQUINA
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void TEMPO_ID003(void)
{char ik;

 PROCESAR_COMANDOS_DE_ID024();
 if(SUPER_ESTADOS_ID003_MQ==INICIALIZAR)
 {switch(ESTADOS_ID003_MQ)//estados simulados de la maquina
        {case(INTERROGAR_ESTADOS):for(ik=0;ik<ACTIVADO_TABLA[1];ik++){BUFFER_ENVIO_ID003[ik]=ACTIVADO_TABLA[ik];}
                                                                      CONTA_ENVIO2=ACTIVADO_TABLA[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(POWER_UP_M):for(ik=0;ik<POWER_UP_DATA[1];ik++){BUFFER_ENVIO_ID003[ik]=POWER_UP_DATA[ik];}
                                                                      CONTA_ENVIO2=POWER_UP_DATA[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_89_DATA):for(ik=0;ik<SET_89[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_89[ik];}
                                                                      CONTA_ENVIO2=SET_89[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(INTERROGAR_VERSION):for(ik=0;ik<VERSION_REQUEST[1];ik++){BUFFER_ENVIO_ID003[ik]=VERSION_REQUEST[ik];}
                                                                      CONTA_ENVIO2=VERSION_REQUEST[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_87_DATA):for(ik=0;ik<SET_87[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_87[ik];}
                                                                      CONTA_ENVIO2=SET_87[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_86_DATA):for(ik=0;ik<SET_86[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_86[ik];}
                                                                      CONTA_ENVIO2=SET_86[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_84_DATA):for(ik=0;ik<SET_84[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_84[ik];}
                                                                      CONTA_ENVIO2=SET_84[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_83_DATA):for(ik=0;ik<SET_83[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_83[ik];}
                                                                      CONTA_ENVIO2=SET_83[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_81_DATA):for(ik=0;ik<SET_81[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_81[ik];}
                                                                      CONTA_ENVIO2=SET_81[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_80_DATA):for(ik=0;ik<SET_80[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_80[ik];}
                                                                      CONTA_ENVIO2=SET_80[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_C0_DATA):for(ik=0;ik<SET_C0[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C0[ik];}
                                                                      CONTA_ENVIO2=SET_C0[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);


                                                                      break;
         case(SET_C1_DATA):for(ik=0;ik<SET_C1[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C1[ik];}
                                                                      CONTA_ENVIO2=SET_C1[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_C3_DATA):for(ik=0;ik<SET_C3[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C3[ik];}
                                                                      CONTA_ENVIO2=SET_C3[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_C4_DATA):for(ik=0;ik<SET_C4[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C4[ik];}
                                                                      CONTA_ENVIO2=SET_C4[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_C5_DATA):for(ik=0;ik<SET_C5[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C5[ik];}
                                                                      CONTA_ENVIO2=SET_C5[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
         case(SET_C6_DATA):for(ik=0;ik<SET_C6[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C6[ik];}
                                                                      CONTA_ENVIO2=SET_C6[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;

         case(SET_C7_DATA):for(ik=0;ik<SET_C7[1];ik++){BUFFER_ENVIO_ID003[ik]=SET_C7[ik];}
                                                                      CONTA_ENVIO2=SET_C7[1];PUNT_ENV_2=1;
                                                                      ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                      enable_interrupts(int_TBE2);
                                                                      break;
        }
 } 

if(SUPER_ESTADOS_ID003_MQ==NORMAL_ID003)
   {switch(ESTADOS_ID003_MQ)//lee el estado del billetero y modifica el estado de la maquina
          {case(POWER_UP_DATA[2]):ESTADOS_ID003_MQ=POWER_UP_M;
                                  SUPER_ESTADOS_ID003_MQ=INICIALIZAR;
                                  ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                  break;
           case(INTERROGAR_ESTADOS):for(ik=0;ik<ACTIVADO_TABLA[1];ik++){BUFFER_ENVIO_ID003[ik]=ACTIVADO_TABLA[ik];}
                                    CONTA_ENVIO2=ACTIVADO_TABLA[1];PUNT_ENV_2=1;
                                    ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                    enable_interrupts(int_TBE2);
                                    break;
           case(ACTIVAR_DATA):if(ES_VEGA==1)
                              {for(ik=0;ik<ACTIVAR_VEGA[1];ik++){BUFFER_ENVIO_ID003[ik]=ACTIVAR_VEGA[ik];}}
                              else{for(ik=0;ik<ACTIVAR_BILL[1];ik++){BUFFER_ENVIO_ID003[ik]=ACTIVAR_BILL[ik];}}
 
                                    CONTA_ENVIO2=ACTIVAR_BILL[1];PUNT_ENV_2=1;
                                    ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                    enable_interrupts(int_TBE2);
                                    break;
           case(DESACTIVAR_DATA):if(ES_VEGA==1)
                                 {for(ik=0;ik<DESACTIVAR_VEGA[1];ik++){BUFFER_ENVIO_ID003[ik]=DESACTIVAR_VEGA[ik];}}
                                 else{for(ik=0;ik<DESACTIVAR_BILL[1];ik++){BUFFER_ENVIO_ID003[ik]=DESACTIVAR_BILL[ik];}}                       

                                    CONTA_ENVIO2=DESACTIVAR_BILL[1];PUNT_ENV_2=1;
                                    ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                    enable_interrupts(int_TBE2);
                                    break;
          }

   }

if(SUPER_ESTADOS_ID003_MQ==BILLETE_ID003)//RECIBE DE BILL
   {switch(ESTADOS_ID003_MQ)
           {case(INTERROGAR_ESTADOS):for(ik=0;ik<ACTIVADO_TABLA[1];ik++){BUFFER_ENVIO_ID003[ik]=ACTIVADO_TABLA[ik];}
                                                                         CONTA_ENVIO2=ACTIVADO_TABLA[1];PUNT_ENV_2=1;
                                                                         ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                         enable_interrupts(int_TBE2);
                                                                         break;
            case(ORDEN_ESTAKAR_ID003):for(ik=0;ik<ORDEN_PASAR[1];ik++){BUFFER_ENVIO_ID003[ik]=ORDEN_PASAR[ik];}
                                                                         CONTA_ENVIO2=ORDEN_PASAR[1];PUNT_ENV_2=1;
                                                                         ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                         enable_interrupts(int_TBE2);
                                                                         break;
            case(CONTESTAR_ACK_ID003):ESTADOS_ID003_MQ=INTERROGAR_ESTADOS;
                                      for(ik=0;ik<ACK_1[1];ik++){BUFFER_ENVIO_ID003[ik]=ACK_1[ik];}
                                                                         CONTA_ENVIO2=ACK_1[1];PUNT_ENV_2=1;
                                                                         ENVIAR_U2(0,BUFFER_ENVIO_ID003[0]);
                                                                         enable_interrupts(int_TBE2);
                                                                         break;
                                      break;
                                      

            }

   }


}
//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//PROCESO DE ACTIVACION SE USA ACTIVATE_BILL REGISTRO EN 1 ACTIVADO CUANDO
//PREGUNTO ESTADOS SI NO CORRESPONDE CON ACTIVATE  ORDENA ACTIVAR O DESACTIVAR
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX