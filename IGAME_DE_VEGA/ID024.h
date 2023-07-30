
enum {NORMAL_ID024,BILLETE_ID024,INICIALIZAR_ID024};//PARA SUPER ESTADOS_ID024
enum {INACTIVO,ACTIVO,ESTADO_1,ESTADO_2};
enum {DENOM_ACEPTING_ID024,HOLDING_ID024,ESTAKED_ID024,ESTAKANDO_ID024,
      REJECTED_ID024,REJECTING_ID024,ACTIVO_BILLETE,INACTIVO_BILLETE};//ESTADOS DE PASO DE BILL


//char  PAR;
char  FLAG_IDO24_RIDLE=0;
int16 REBOTE_RIDLE=0;
char  HISTORIAL_RIDLE;
char  CONTAOR_BYTES_ID024=11;
char  BUFFER_ID024_RX[32]={0X09,0X74,0X08,0XFF,0XF1,0XFF,0XCC,0X61,0X12,0X58,0X73};
char  BUFER_ENVIO_ID024[60]={};
char  PUNT_ENV_ID024=0;
char  BYTES_A_ENVIAR_ID024=0;
char  SUPER_ESTADOS_ID024=INICIALIZAR_ID024;
char  ESTADOS_ID024=INACTIVO;
char  ROTACION=0;
char  VIENE_BILLETE_A=0;
char  VIENE_BILLETE_B=0;

CONST unsigned int TRAMA_VERSION_ID024[]={0X04,0X42,0X23,0X57,0X42,0X41,
                                          0X2D,0X31,0X32,0X2F,0X31,0X33,
                                          0X20,0X30,0X32,0X34,0X20,0X20,
                                          0X56,0X33,0X2E,0X36,0X30,0X2D,
                                          0X33,0X30,0X20,0X20,0X20,0X20,
                                          0X20,0X20,0X20,0X96,0XC7
                                         };


CONST unsigned int RESET_ID024[]      = {0X04,0X2F,0X05,0X37,0X94}  ;
CONST unsigned int CMD1_INICIALIZAR[] = {0X04,0X74,0X08,0XFF,0XF1,0XFF,0XCC,0X61}  ;
CONST unsigned int CMD2_INICIALIZAR[] = {0X04,0XB0,0X05,0XA2,0X0E};
CONST unsigned int CMD3_INICIALIZAR[] = {0X04,0XF1,0X05,0X1C,0X51};
CONST unsigned int CMD4_INICIALIZAR[] = {0X04,0X62,0X0B,0X00,0X00,0X00,0X00,0X34,0X12,0X58,0X73};
CONST unsigned int CMD5_INICIALIZAR[] = {0X04,0X82,0X05,0XB0,0X8B};
CONST unsigned int CMD6_INICIALIZAR[] = {0X04,0XF0,0X05,0XC4,0X48};

CONST unsigned int REPORTE_DISABLE1[] ={0X04,0X90,0X05,0X91,0X2D};
CONST unsigned int REPORTE_DISABLE2[] ={0X04,0XD0,0X05,0XF7,0X6B};
CONST unsigned int REPORTE_DISABLE3[] ={0X04,0X50,0X05,0X3B,0XE7};
CONST unsigned int ACK_ID024[]        ={0X04,0X01,0X05,0X14,0X2D};
CONST unsigned int TRAMA_ESTAD1[]     ={0X04,0X10,0X05,0X5D,0XA1};
CONST unsigned int TRAMA_ESTAD2[]     ={0X04,0XE3,0X07,0XF7,0X99,0X1A,0X08};
CONST unsigned int TRAMA_ORDEN_RESET[]={0X04,0X2F,0X05,0X37,0X94};

CONST unsigned int BILLETE_1A_ID024[]  ={0x04,0XF0,0X11,0X64,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XBB,0XB8};
CONST unsigned int BILLETE_1B_ID024[]  ={0x04,0XB0,0X11,0X64,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XD4,0XFB};
CONST unsigned int BILLETE_5A_ID024[]  ={0X04,0XB0,0X11,0XF4,0X01,0x00,0X00,0X00,0x00,0X00,0X00,0x00,0X00,0X00,0x00,0X5D,0X15};
CONST unsigned int BILLETE_5B_ID024[]  ={0X04,0XF0,0X11,0XF4,0X01,0x00,0X00,0X00,0x00,0X00,0X00,0x00,0X00,0X00,0x00,0X32,0X56};
CONST unsigned int BILLETE_10A_ID024[] ={0X04,0X70,0X11,0XE8,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0x00,0X8C,0X61};
CONST unsigned int BILLETE_10B_ID024[] ={0X04,0XF0,0X11,0XE8,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0x00,0X52,0XE7};
CONST unsigned int BILLETE_20A_ID024[] ={0X04,0X70,0X11,0XD0,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X5D,0X0B};
CONST unsigned int BILLETE_20B_ID024[] ={0X04,0XB0,0X11,0XD0,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XEC,0XCE};
CONST unsigned int BILLETE_50A_ID024[] ={0X04,0X70,0X11,0X88,0X13,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X19,0X6C};
CONST unsigned int BILLETE_50B_ID024[] ={0X04,0XF0,0X11,0X88,0X13,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC7,0XEA};


CONST unsigned int RECHAZA_1A_ID024[]  ={0X04,0X73,0X09,0X64,0X00,0X00,0X00,0X66,0X1C};
CONST unsigned int RECHAZA_5A_ID024[]  ={0X04,0X73,0X09,0XF4,0X01,0X00,0X00,0X75,0XA8};
CONST unsigned int RECHAZA_10A_ID024[] ={0X04,0XF3,0X09,0XE8,0X03,0X00,0X00,0XFA,0X4C};
CONST unsigned int RECHAZA_20A_ID024[] ={0X04,0XB3,0X09,0XD0,0X07,0X00,0X00,0X60,0X84};
CONST unsigned int RECHAZA_50A_ID024[] ={0X04,0XB3,0X09,0X88,0X13,0X00,0X00,0X5A,0X52};


CONST unsigned int ESTAKEDA_ID024[] ={0X04,0XF1,0X05,0X1C,0X51};
CONST unsigned int ESTAKEDB_ID024[] ={0X04,0XB1,0X05,0X7A,0X17};






//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//char  COMMANDO_A_ID003=0;
//char  ARGUMENTO_A_ID003=0;
//char  COMMANDO_A_ID024=0;
//char  ARGUMENTO_A_ID024=0;
//char  ACTIVATE_ID003=0;
//COMANDOS DE ID024 A ID003
//01 RESET
//02 ACTIVAR
//03 DESACTIVAR

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//PARAMETROS DE ENTRADA CANTIDAD DE BYTES A ENVIAR Y BUFFER CARGADO
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void SACAR_DE_BUFFER (void)
{char M1;
 PUNT_ENV_ID024=1;
 enable_interrupts(int_TBE);
 M1=BUFER_ENVIO_ID024[0];
 ENVIAR_U1(0,M1);}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void SACA_ACK(void)
{char jk;
 for(jk=0;jk<ACK_ID024[2];jk++){BUFER_ENVIO_ID024[jk]=ACK_ID024[jk];}
 BYTES_A_ENVIAR_ID024=ACK_ID024[2];
 SACAR_DE_BUFFER();
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void SACA_ENABLE(void)
{BUFER_ENVIO_ID024[0]=0X04;BUFER_ENVIO_ID024[1]=0X00;
 BYTES_A_ENVIAR_ID024=2;SACAR_DE_BUFFER();
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void SACA_DISABLE (void)
{char jk;
 if(ROTACION==3){ROTACION=0;}
 switch(ROTACION)
       {case 0:for(jk=0;jk<REPORTE_DISABLE1[2];jk++){BUFER_ENVIO_ID024[jk]=REPORTE_DISABLE1[jk];}
               BYTES_A_ENVIAR_ID024=REPORTE_DISABLE1[2];
               ROTACION=1;
               break;
        case 1:for(jk=0;jk<REPORTE_DISABLE2[2];jk++){BUFER_ENVIO_ID024[jk]=REPORTE_DISABLE2[jk];}
               BYTES_A_ENVIAR_ID024=REPORTE_DISABLE2[2];
               ROTACION=2;
               break;
        case 2:for(jk=0;jk<REPORTE_DISABLE3[2];jk++){BUFER_ENVIO_ID024[jk]=REPORTE_DISABLE3[jk];}
               BYTES_A_ENVIAR_ID024=REPORTE_DISABLE3[2];
               ROTACION=0;
               break;
       }
 SACAR_DE_BUFFER();
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
int16 calc_crc_mch(unsigned char *data, int16 n, int16 start)
{int16 w, q, c, crcval;
 crcval=start;
 for (w=0; w<n; w++)
     {c=data[w] & 0xFF;
      q=(crcval^c) & 0x0F;
      crcval=(crcval>>4)^(q*0x1081);
      q=(crcval^(c>>4)) & 0x0F;
      crcval=(crcval>>4)^(q*0x1081);
     }
 crcval=((crcval<<8)|(crcval>>8)); 
 return crcval;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//RECIBIDOS DE LA MAQUINA
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void COMANDOS_ID024_INICIALIZAR(void)
{char ML;char COMANDO_ID024;char COMANDO2;char jk;char LONGITUD1;

 LONGITUD1=BUFFER_ID024_RX[2];
 COMANDO2=BUFFER_ID024_RX[1];//SALVARLO SIN MODIFICACION
 COMANDO_ID024=COMANDO2&0X0F;//EXTRAER NIBBLE BAJO
 

 switch(COMANDO_ID024)
   {case 0X0F:ESTADOS_ID024=ESTADO_1;
              output_low(VISUAL_D);
              SACA_ACK();
              break;
    case 0X00:ESTADOS_ID024=ACTIVO;
              SACA_ACK();
              break;
    case 0X01:if(BUFFER_ID024_RX[4]!=0X2D){ESTADOS_ID024=INACTIVO;
                                           SACA_ENABLE();
                                          }//DISCRIMINAR ENTRE DESACTIVAR Y UN ACK
              if(BUFFER_ID024_RX[4]==0X2D)//CORRESPONDE A UN ACK
              {switch(ESTADOS_ID024)
                      {case ESTADO_2:ESTADOS_ID024=INACTIVO;break;
                      }
              }
              break;
    case 0x02:if(LONGITUD1==0X0B||LONGITUD1==0X0D){ESTADOS_ID024=ESTADO_2;SACA_ACK();}
              if(BUFFER_ID024_RX[2]==0X05)
                {for(jk=0;jk<TRAMA_VERSION_ID024[2];jk++){BUFER_ENVIO_ID024[jk]=TRAMA_VERSION_ID024[jk];}
                 BYTES_A_ENVIAR_ID024=TRAMA_VERSION_ID024[2];
                 SACAR_DE_BUFFER();
                 output_high(VISUAL_D);
                SUPER_ESTADOS_ID024=NORMAL_ID024;ESTADOS_ID024=INACTIVO;}
              break;
    case 0X04:ESTADOS_ID024=INACTIVO;
              SACA_ACK();
              break;
    default  :SACA_ACK();break;
   } 
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void ESTADOS_VER_ID024_INICIALIZAR(void)
{char jk;
 switch(ESTADOS_ID024)
   {case INACTIVO: SACA_DISABLE();break;
    case ACTIVO: SACA_ENABLE();break;
    case ESTADO_1:for(jk=0;jk<TRAMA_ESTAD1[2];jk++){BUFER_ENVIO_ID024[jk]=TRAMA_ESTAD1[jk];}
                  BYTES_A_ENVIAR_ID024=TRAMA_ESTAD1[2];
                  SACAR_DE_BUFFER();
                  ESTADOS_ID024=INACTIVO;
                  break;
    case ESTADO_2:for(jk=0;jk<TRAMA_ESTAD2[2];jk++){BUFER_ENVIO_ID024[jk]=TRAMA_ESTAD2[jk];}
                  BYTES_A_ENVIAR_ID024=TRAMA_ESTAD2[2];
                  SACAR_DE_BUFFER();
                  break;
   }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//CUANDO TERMINA LA CARGA DEL BILLETE ROTAR EL BUFFER BILLETE Y BORRAR
//EL REGISTRO QUE SE ACABA DE CARGAR
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void TEMPO_ID024(void)
{char NEXT;
 NEXT=BUFFER_BILLETES[0];
 PERIODO_BILL++;
 if(PERIODO_BILL==1)
 {PERIODO_BILL=0;
  if((SUPER_ESTADOS_ID024!=BILLETE_ID024)&&ESTADOS_ID024==ACTIVO)
     {if(NEXT!=0){SUPER_ESTADOS_ID024=BILLETE_ID024;
                  ESTADOS_ID024=DENOM_ACEPTING_ID024;}
     }   
 }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void COMANDOS_ID024_BILLETE(void)
{char ML;char COMANDO_ID024;char COMANDO2;char jk;char LONGITUD1;
 
 LONGITUD1=BUFFER_ID024_RX[2];
 COMANDO2=BUFFER_ID024_RX[1];//SALVARLO SIN MODIFICACION
 COMANDO_ID024=COMANDO2&0X0F;//EXTRAER NIBBLE BAJO
 
 switch(COMANDO_ID024)
   {case 0X00:SACA_ACK();
              MEMORIA_ESTADOS_ID024=ESTADOS_ID024;
              ESTADOS_ID024=ACTIVO_BILLETE;
              break;//ENABLE

    case 0X01:if(BUFFER_ID024_RX[4]!=0X2D)
                {MEMORIA_ESTADOS_ID024=ESTADOS_ID024;
                 SACA_ACK();
//                 if(ESTADOS_ID024==HOLDING_ID024)
//                   {ESTADOS_ID024=REJECTED_ID024;}                 
                 ESTADOS_ID024=INACTIVO_BILLETE; 
                }    
          
              if(BUFFER_ID024_RX[4]==0X2D)//CORRESPONDE A UN ACK
              {switch(ESTADOS_ID024)
                      {case DENOM_ACEPTING_ID024:ESTADOS_ID024=HOLDING_ID024;                                                
                                                 if(BUFFER_ID024_RX[5]==0x04)
                                                      {COMANDO2=BUFFER_ID024_RX[6];
                                                       COMANDO2=COMANDO2&0X0F;
                                                       if(COMANDO2==0X02){ESTADOS_ID024=ESTAKANDO_ID024;SACA_ACK();}//SI NO HAY ESPACIO INTERTRAMA
                                                       else{if(COMANDO2==0X03){ESTADOS_ID024=REJECTING_ID024;SACA_ACK();COMMANDO_A_ID003=DESACTIVAR_A_ID003;}
                                                            else{SACA_ENABLE();}                                                               
                                                           }    
                                                      }
                                                 break;
                       case ESTAKED_ID024:SACA_ENABLE();
                                          MEMORIA_ESTADOS_ID024=ACTIVO_BILLETE;
                                          ESTADOS_ID024=ACTIVO_BILLETE;
                                          BUFFER_BILLETES[0]=0;//SACA EL BILLETE DE LA PILA 
                                          output_high(VISUAL_D);
                                          break;
                       case REJECTED_ID024:if(MEMORIA_ESTADOS_ID024==INACTIVO_BILLETE)
                                             {SACA_DISABLE();ESTADOS_ID024=MEMORIA_ESTADOS_ID024;}
                                           else{SACA_ENABLE();
                                                ESTADOS_ID024=ACTIVO_BILLETE;}
                                           output_high(VISUAL_D);
                                           break;
                      }
              }
              break;
    case 0X02:ESTADOS_ID024=ESTAKANDO_ID024;//ORDEN PASAR BILLETE
              SACA_ACK();break;
    case 0X03:ESTADOS_ID024=REJECTING_ID024;//ORDEN PASAR BILLETE
              SACA_ACK();break;

    
    default  :SACA_ACK();break;
   } 
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void ESTADOS_VER_ID024_BILLETE(void)
{char BILLETICO;static char FLIP_FLOP=0;char jk;
 static char VECES;char OPEX1;static char VECES_ACTIVO;
 static char VECES_INACTIVO;

 COMMANDO_A_ID003=DESACTIVAR_A_ID003;
 if(FLIP_FLOP==1){FLIP_FLOP=0;}
 else {FLIP_FLOP=1;}

 BILLETICO=BUFFER_BILLETES[0];
 switch(ESTADOS_ID024)
   {case DENOM_ACEPTING_ID024:switch(BILLETICO)
                                     {case 1 :OPEX1=BILLETE_1B_ID024[2];
                                              if(FLIP_FLOP=0){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_1A_ID024[jk];}}
                                              if(FLIP_FLOP=1){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_1B_ID024[jk];}}
                                              BYTES_A_ENVIAR_ID024=BILLETE_1B_ID024[2];
                                              SACAR_DE_BUFFER();
                                              output_low(VISUAL_D);
                                              break;
                                      case 5 :OPEX1=BILLETE_5B_ID024[2];
                                              if(FLIP_FLOP=0){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_5A_ID024[jk];}}
                                              if(FLIP_FLOP=1){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_5B_ID024[jk];}}
                                              BYTES_A_ENVIAR_ID024=BILLETE_5B_ID024[2];
                                              SACAR_DE_BUFFER();
                                              output_low(VISUAL_D);
                                              break;
                                      case 10:OPEX1=BILLETE_10B_ID024[2];
                                              if(FLIP_FLOP=0){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_10A_ID024[jk];}}
                                              if(FLIP_FLOP=1){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_10B_ID024[jk];}}
                                              BYTES_A_ENVIAR_ID024=BILLETE_10B_ID024[2];
                                              SACAR_DE_BUFFER();
                                              output_low(VISUAL_D);
                                              break;
                                      case 20:OPEX1=BILLETE_20B_ID024[2];
                                              if(FLIP_FLOP=0){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_20A_ID024[jk];}}
                                              if(FLIP_FLOP=1){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_20B_ID024[jk];}}
                                              BYTES_A_ENVIAR_ID024=BILLETE_20B_ID024[2];
                                              SACAR_DE_BUFFER();
                                              output_low(VISUAL_D);
                                              break;
                                      case 50:OPEX1=BILLETE_50B_ID024[2];
                                              if(FLIP_FLOP=0){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_50A_ID024[jk];}}
                                              if(FLIP_FLOP=1){for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=BILLETE_50B_ID024[jk];}}
                                              BYTES_A_ENVIAR_ID024=BILLETE_50B_ID024[2];
                                              SACAR_DE_BUFFER();
                                              output_low(VISUAL_D);
                                              break;
                                      default:break;//ERROR RESETEAR CPU
                                     }
                              break;
    case HOLDING_ID024:SACA_ENABLE();
                       break;
    case REJECTING_ID024:VECES++;
                         if(VECES==2){VECES=0;ESTADOS_ID024=REJECTED_ID024;}
                         SACA_ENABLE();
                         break;
    case REJECTED_ID024: switch(BILLETICO)
                           {case 1 :OPEX1=RECHAZA_1A_ID024[2];
                                    for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=RECHAZA_1A_ID024[jk];}
                                    BYTES_A_ENVIAR_ID024=RECHAZA_1A_ID024[2];
                                    SACAR_DE_BUFFER();
                                    break;
                            case 5 :OPEX1=RECHAZA_5A_ID024[2];
                                    for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=RECHAZA_5A_ID024[jk];}
                                    BYTES_A_ENVIAR_ID024=RECHAZA_5A_ID024[2];
                                    SACAR_DE_BUFFER();
                                    break;
                            case 10:OPEX1=RECHAZA_10A_ID024[2];
                                    for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=RECHAZA_10A_ID024[jk];}
                                    BYTES_A_ENVIAR_ID024=RECHAZA_10A_ID024[2];
                                    SACAR_DE_BUFFER();
                                    break;
                            case 20:OPEX1=RECHAZA_20A_ID024[2];
                                    for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=RECHAZA_20A_ID024[jk];}
                                    BYTES_A_ENVIAR_ID024=RECHAZA_20A_ID024[2];
                                    SACAR_DE_BUFFER();
                                    break;
                            case 50:OPEX1=RECHAZA_50A_ID024[2];
                                    for(jk=0;jk<OPEX1;jk++){BUFER_ENVIO_ID024[jk]=RECHAZA_50A_ID024[jk];}
                                    BYTES_A_ENVIAR_ID024=RECHAZA_50A_ID024[2];
                                    SACAR_DE_BUFFER();
                                    break;
                            default:break;//ERROR RESETEAR CPU
                                     }
                         break;
    case ESTAKANDO_ID024:VECES++;
                         if(VECES==2){VECES=0;ESTADOS_ID024=ESTAKED_ID024;}
                         SACA_ENABLE();
                         break;
 
    case ESTAKED_ID024:if(FLIP_FLOP==1)
                         {for(jk=0;jk<ESTAKEDA_ID024[2];jk++){BUFER_ENVIO_ID024[jk]=ESTAKEDA_ID024[jk];}}
                          else{for(jk=0;jk<ESTAKEDB_ID024[2];jk++){BUFER_ENVIO_ID024[jk]=ESTAKEDB_ID024[jk];}}
                          BYTES_A_ENVIAR_ID024=ESTAKEDA_ID024[2];
                          SACAR_DE_BUFFER();                          
                       break;  
    case INACTIVO_BILLETE:SACA_DISABLE();
                          VECES_ACTIVO=0;
                          VECES_INACTIVO++;
                          if(VECES_INACTIVO==10)
                             {VECES_INACTIVO=0;
                              if(MEMORIA_ESTADOS_ID024==HOLDING_ID024)
                                 {ESTADOS_ID024=REJECTED_ID024;
                                  MEMORIA_ESTADOS_ID024=INACTIVO_BILLETE;}
                             }
                          break;
    case ACTIVO_BILLETE:SACA_ENABLE();
                        VECES_INACTIVO=0;
                        VECES_ACTIVO++;
                        if(VECES_ACTIVO==4)
                          {VECES_ACTIVO=0; 
                            if(BUFFER_BILLETES[0]==0)//SI CARGADO ULTIMO BILLETE ROTAR PILA
                               {BUFFER_BILLETES[0]=BUFFER_BILLETES[1];
                                BUFFER_BILLETES[1]=0;}

                           if(BUFFER_BILLETES[0]!=0)//DESPUES DE HABER ROTADO
                              {ESTADOS_ID024=DENOM_ACEPTING_ID024;
                              }
                           else{SUPER_ESTADOS_ID024=NORMAL_ID024;
                                COMMANDO_A_ID003=ACTIVAR_A_ID003;
                                ESTADOS_ID024=ACTIVO;}
                          }
                        break;
   }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void COMANDOS_ID024_NORMAL(void)
{char ML;char COMANDO_ID024;char COMANDO2;char jk;char LONGITUD1;

 LONGITUD1=BUFFER_ID024_RX[2];
 COMANDO2=BUFFER_ID024_RX[1];//SALVARLO SIN MODIFICACION
 COMANDO_ID024=COMANDO2&0X0F;//EXTRAER NIBBLE BAJO
// output_high(VISUAL_A);

 switch(COMANDO_ID024)
   {case 0X0F:ESTADOS_ID024=ESTADO_1;
              SUPER_ESTADOS_ID024=INICIALIZAR_ID024;
              COMMANDO_A_ID003=RESET_A_ID003;//DESACTIVAR ACTIVATE_ID003=0;
              output_low(VISUAL_A);
              output_low(VISUAL_D);
              SACA_ACK();
              break;
    case 0X00:ESTADOS_ID024=ACTIVO;
              COMMANDO_A_ID003=ACTIVAR_A_ID003;//ACTIVAR ACTIVATE_ID003=1;
              output_high(VISUAL_A);
              SACA_ACK();
              break;
    case 0X01:if(BUFFER_ID024_RX[4]!=0X2D){ESTADOS_ID024=INACTIVO;output_low(VISUAL_A);
                                           COMMANDO_A_ID003=DESACTIVAR_A_ID003;//DESACTIVARACTIVATE_ID003=0;
                                           SACA_ACK();}//DISCRIMINAR ENTRE DESACTIVAR Y UN ACK
              if(BUFFER_ID024_RX[4]==0X2D)//CORRESPONDE A UN ACK
              {switch(ESTADOS_ID024)
                      {case ESTADO_2:ESTADOS_ID024=INACTIVO;break;
                      }
              }
              break;
    case 0x02:if(LONGITUD1==0X0B){ESTADOS_ID024=ESTADO_2;SACA_ACK();}
              if(LONGITUD1==0X0D){SACA_ACK();}
              if(BUFFER_ID024_RX[2]==0X05)
                {for(jk=0;jk<TRAMA_VERSION_ID024[2];jk++){BUFER_ENVIO_ID024[jk]=TRAMA_VERSION_ID024[jk];}
                 BYTES_A_ENVIAR_ID024=TRAMA_VERSION_ID024[2];
                 SACAR_DE_BUFFER();
                SUPER_ESTADOS_ID024=NORMAL_ID024;ESTADOS_ID024=INACTIVO;}
              break;

    default  :SACA_ACK();break;
   }

}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void ESTADOS_VER_ID024_NORMAL (void)
{switch(ESTADOS_ID024)
   {case INACTIVO: SACA_DISABLE();
                 break;
    case ACTIVO: SACA_ENABLE();
                 break;
   }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void LISTO_BUFFER_ID024(void)
{int16 LONGITUD=0; int16 CRC_XX=0;int16 CRC_YY;
 char SIP_1;char SIP_2;char M1;char K; 

 if(BUFFER_ID024_RX[0]==0x04&&BUFFER_ID024_RX[1]==0)//CONTESTA MQ PREGUNTANDO ESTADOS
    {switch(SUPER_ESTADOS_ID024)
            {case INICIALIZAR_ID024:ESTADOS_VER_ID024_INICIALIZAR();break; 
             case BILLETE_ID024:ESTADOS_VER_ID024_BILLETE();break;
             case NORMAL_ID024:ESTADOS_VER_ID024_NORMAL();break;
            }
   }

 if(BUFFER_ID024_RX[0]==0X04)//&&BUFFER_ID024_RX[2]==CONTAOR_BYTES_ID024)//COMANDOS
     {//output_toggle(VISUAL_D);
      K=BUFFER_ID024_RX[2]-2;
      SIP_1=0;
      LONGITUD=make16(SIP_1,K);
      CRC_XX=calc_crc_mch(BUFFER_ID024_RX,LONGITUD,0);
      M1=BUFFER_ID024_RX[2]-1;
      SIP_1=BUFFER_ID024_RX[M1];
      M1=BUFFER_ID024_RX[2]-2;
      SIP_2=BUFFER_ID024_RX[M1];
      CRC_YY=make16(SIP_2,SIP_1);
      //hallar el crc de la trama en buffer validar y entarr a procesar segun se super estados
      if(CRC_XX==CRC_YY){//output_toggle(VISUAL_A);
                         switch(SUPER_ESTADOS_ID024)
                                {case INICIALIZAR_ID024:COMANDOS_ID024_INICIALIZAR();break; 
                                 case BILLETE_ID024:COMANDOS_ID024_BILLETE();break;
                                 case NORMAL_ID024:COMANDOS_ID024_NORMAL();break;
                                }
                         }

     }

BUFFER_ID024_RX[0]=254;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//ESTADOS DE INICIALIZACION
//ESTADO ACTIVO
//DESACTIVO
//ESTADO1 VIENE DESPUES DE UNA ORDEN DE RESET AL SIGUIENTE SR
//CONTESTA TRAMA CUYO COMANDO ES10
//ESTADO2 ENTRA AL RECIBIR 04 62 0B 00 00 00 00 34 12 58 73
//SALE AL RECIBIR ACK;
//CREAR UN BUFFER DE BILLETES QUE SE REVIZARA PERIODICAMENTE
//PARA DESCARGAR MIENTRAS ESTADO BILLETE DESHABILITAR BILLETERO
//