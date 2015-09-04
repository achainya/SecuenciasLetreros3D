#include "16F877A.h"

#fuses XT, NOWDT, NOPROTECT, NOLVP   // Definimos los FUSES para el uC PIC16F877

#use delay(clock=4000000)   // Frecuencia de reloj (20MHz)

// Constantes y definiciones ////////////////////////////////////////////////////////////

char IDPuertoLetra(char NROLETRA) {
   switch (NROLETRA) {
      case  1:  return PIN_B0; break;
      case  2:  return PIN_B3; break;
      case  3:  return PIN_B6; break;
      case  4:  return PIN_C1; break;
      case  5:  return PIN_C4; break;
      case  6:  return PIN_C7; break;
      case  7:  return PIN_D2; break;
      case  8:  return PIN_D5; break;
      case  9:  return PIN_A0; break;
      case 10:  return PIN_A3; break;
      case 11:  return PIN_E0; break;
   }
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

void EnciendeLetra(char NROLETRA, char NROCOLOR) {
   switch (NROCOLOR) {
      case 1: Color1(IDPuertoLetra(NROLETRA)); break;
      case 2: Color2(IDPuertoLetra(NROLETRA)); break;
      case 3: Color3(IDPuertoLetra(NROLETRA)); break;
      case 4: Color4(IDPuertoLetra(NROLETRA)); break;
      case 5: Color5(IDPuertoLetra(NROLETRA)); break;
      case 6: Color6(IDPuertoLetra(NROLETRA)); break;
      case 7: Color7(IDPuertoLetra(NROLETRA)); break;
      case 8: Color8(IDPuertoLetra(NROLETRA)); break;
   }
}

void main() {
   char i;
   set_tris_a(0b00000000); // Puerto A salida
   set_tris_b(0b00000000); // Puerto B salida 
   set_tris_c(0b00000000); // Puerto C salida
   set_tris_d(0b00000000); // Puerto D salida
   set_tris_e(0b11111000); // Puerto E salida
   
   output_a(0x00);
   output_b(0x00);
   output_c(0x00);
   output_d(0x00);
   output_e(0x00);

   do {
      for(i = 1; i <= 8; i++) {
         EnciendeLetra(9, i);
         delay_ms(500);
      }
   } while(TRUE);
}

