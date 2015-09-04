#include "16F877A.h"
#include <stdlib.h>

#fuses XT, NOWDT, NOPROTECT, NOLVP   // Definimos los FUSES para el uC PIC16F877

#use delay(clock=4000000)   // Frecuencia de reloj (20MHz)

// Constantes y definiciones ////////////////////////////////////////////////////////////

#define  PORTA  40
#define  PORTB  48

int IDPuertoLetra(char NroLetra) {
   if (NroLetra == 9)
      return PORTA;
   return PORTB + 3 * NroLetra;
}

void Color1(char PUERTO) { // Apagado
   output_low(PUERTO + 0);
   output_low(PUERTO + 1);
   output_low(PUERTO + 2);
}

void Color2(char PUERTO) { // Verde
   output_low (PUERTO + 0);
   output_low (PUERTO + 1);
   output_high(PUERTO + 2);
}

void Color3(char PUERTO) { // Rojo
   output_low (PUERTO + 0);
   output_high(PUERTO + 1);
   output_low (PUERTO + 2);
}

void Color4(char PUERTO) { // Amarillo
   output_low (PUERTO + 0);
   output_high(PUERTO + 1);
   output_high(PUERTO + 2);
}

void Color5(char PUERTO) { // Azul
   output_high(PUERTO + 0);
   output_low (PUERTO + 1);
   output_low (PUERTO + 2);
}

void Color6(char PUERTO) { // Turqueza
   output_high(PUERTO + 0);
   output_low (PUERTO + 1);
   output_high(PUERTO + 2);
}

void Color7(char PUERTO) { // Rosado
   output_high(PUERTO + 0);
   output_high(PUERTO + 1);
   output_low (PUERTO + 2);
}

void Color8(char PUERTO) { // Blanco
   output_high(PUERTO + 0);
   output_high(PUERTO + 1);
   output_high(PUERTO + 2);
}


void EnciendeLetra(char LETRA, char COLOR) {
   int NroLetra;
   NroLetra = LETRA - 1;
   
   switch (COLOR) {
      case 1: Color1(IDPuertoLetra(NroLetra)); break;
      case 2: Color2(IDPuertoLetra(NroLetra)); break;
      case 3: Color3(IDPuertoLetra(NroLetra)); break;
      case 4: Color4(IDPuertoLetra(NroLetra)); break;
      case 5: Color5(IDPuertoLetra(NroLetra)); break;
      case 6: Color6(IDPuertoLetra(NroLetra)); break;
      case 7: Color7(IDPuertoLetra(NroLetra)); break;
      case 8: Color8(IDPuertoLetra(NroLetra)); break;
   }
}

void main() {
   char i;
   set_tris_a(0b00000000); // Lineas RA0-RA3 salidas y RA4 entrada
   set_tris_b(0b00000000); // Puerto RB0-RB7 sensores CNY1-CNY8
   set_tris_c(0b00000000); // Puerto RC0-CNY9, RC1-EN2, RC2-EN1, RC3-RC5-SW's, 
                           // RC6-TX y RC7-RX
   set_tris_d(0b00000000); // RD0-RD2, RD4-RD7 conectado al LCD y RD3-SW OK
   set_tris_e(0b11111000); // RE0-RE3 diodos led

   do {
      for(i = 1; i <= 8; i++) {
         EnciendeLetra(10, i);
         delay_ms(500);
      }
   } while(TRUE);
}

