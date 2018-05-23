1.)
a)--> 1 Buszyklus braucht 1/10^6s
	--> 18 Register zu sichern	--> 16 allgemeine R., PC, PSW
	--> 36 Zyklen / Interrupt
	--> 2,777 * 10^6

b)--> 16 Seiten/min	--> 4/15 Seiten/s	--> 15/4 s/Seite
	--> 70*90 = 6300 Zeichen/Seite
	--> 15/4 / 6300 = 0,0006 s/Zeichen 
  //? Jedenfalls hab ich die Aufgabe so interpretiert

c)--> 3,75s/Seite
	--> Ausgabe eines Zeichens = 15us (nicht DMA)
	--> Aktivierung Interrupt-Handler/Interrupt = 5us
	--> Programmierung DMA-Kontroller/Seite = 200us
	--> Bereitsstellungszeit für DMA (/Zeichen) = 1us

--> Polling = 15us * 6300 = 0,0945s
	--> 9,45% Auslastung
--> Interrupts = (15us + 5us) *6300 = 0,0315 + 0,0945s = 0,126s
	--> 12,6% Auslastung 
   //Unsicher ob das mit Interrupts so funktioniert
--> DMA = 200us + 1us*6300 = 6500us = 0,0065s
	--> 0,65% Auslastung
    
--> DMA am besten geeignet, Interrupts wegen einzelner Zeichen nur bedingt geeignet

2.)	--> ts = 2ms | 40960 bytes | 512 byte Sektor | 160 Sektoren/Spur
a)	--> 15000rpm	--> 15000/60 = 250/s	--> 1/250s /round = 0,004s /round = tr
	--> tr/2 = øtd = 2ms
b)	--> T = 2ms + 2ms + 40960/512*160 * 4ms = 6ms
c)	--> 1000/6 ~ 166 Blöcke
d)	--> 50 Blöcke	--> T = 20ms	--> 20ms = 2 + x/2 + 40960/(512*160) * x
		--> x = 18ms = tr
		--> 55,55rps	--> *60 = 3333rpm
e)	// TO-DO
