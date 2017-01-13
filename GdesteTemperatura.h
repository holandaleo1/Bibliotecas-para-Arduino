/*
	GdesteTemperatura.h
	Leitura de temperatura do Termistor Integrado a Fotodetector PGA400.
	Data de Criação 06/01/2017
	Autor: Leonardo de Holanda
	Email: leonardoholandanunes@live.com

*/
#ifndef GdesteTemperatura_h
#define GdesteTemperatura_h
#include "Arduino.h"
#include "math.h"
class GdesteTemperatura
{
	public:
		GdesteTemperatura(int pin);
		float TempC();
	
	private:
		int _pin;

};

#endif