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
