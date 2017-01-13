/*
	GdesteTemperatura.cpp
	Leitura de temperatura do Termistor Integrado ao Fotodetector PGA400.
	Data de Criação 06/01/2017
	Autor: Leonardo de Holanda
	Email:leonardoholadanunes@live.com

*/
#include "Arduino.h"
#include "GdesteTemperatura.h"

GdesteTemperatura::GdesteTemperatura(int pin)
{
	_pin = pin;
}
float GdesteTemperatura::TempC()
{
//Método de medição equação de Steinhart–Hart
float Vin = 5.0;        // [V]       Tensão aplicada no divisor de tensão
float Raux = 10000;    // [ohm]      Resistor auxiliar
float R0 = 2252;      // [ohm]       Valor nominal do RTC a 25ºC
float T0 = 298.15;   // [K] (25?C)   Temperatura em Kelvin á 25ºC
float Vout = 0.0;   // [V]           Tensão de saida do divisor
float Rout = 0.0;  // [ohm]          Valor de resistência do NTC
//Ver Datasheet ou usar um multimetro e medir a resistencia do NTC nas duas temperaturas
float T1 = 298.15;      // [K]       Temperatura de calibração 1
float T2 = 206.15;     // [K]        Temperatura de calibração 2
float RT1 = 2252;     // [ohms]      Resistencia medida na temperatura de calibração 1
float RT2 = 500000;  // [ohms]       Resistencia medida na temperatura de calibração 2
float beta = 0.0;   // [K]           parametro Beta
float Rinf = 0.0;  // [ohm]          parametro Rinf
float aux = 0.0;
int TempK = 0.0;  // [K]             Temperatura de saída em Kelvin
int Temp = 0.0; // [C]             Temperatura de saída em ºC
	beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2));
	Rinf = R0 * exp(-beta / T0);
	//Calculo da resistencia do NTC
	aux = ((float)(analogRead(_pin)/1024.0));
	Vout = Vin * aux;
	Rout = (Raux * Vout / (Vin - Vout));
	//Calculo da temperatura
	TempK = (beta / log(Rout / Rinf));
	Temp= TempK - 273.15;
	return Temp;
}