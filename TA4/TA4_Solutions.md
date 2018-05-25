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


3.)
a.)
RAID 0: mindestens 1 Festplatte
RAID 1: mindestens 2 Festplatten
RAID 5: mindestens 3 Festplatten
RAID 6: mindestens 4 Festplatten
maximal ist technisch nahezu beliebig

RAID 0: hoch
RAID 1: normal-schnell lesend, tief schreibend
RAID 5: tief-normal lesend, hoch schreibend
RAID 6: tief-normal lesend, hoch schreibend

Annahme dass n Festplatten
RAID0: Speicherkapazität n
RAID1: Speicherkapazität 1 (kleinste)
RAID5: Speicherkapazität n-1
RAID6: Speicherkapazität n-2

Ausfallsicherheit: (Anzahl ausfallender Festplatten)
RAID0: 0
RAID1: n-1
RAID5: 1
RAID6: 2

b.)
RAID50: Raid0-Array aus Raid5
	Sehr schnell da Schreib und Lesevorgänge auf zwei identische Festplatten-Arrays verteilt werden.
	Redundant sodass eine Festplatte ausfallen kann.

RAID51: Raid1-Array aus Raid5
	Bessere Redundanz aber schlechterer Durchsatz als Raid50
	Smin=3 Smax=4


JBOD: 	Just a bunch of disks
	Keine Redundanz
	Steuerung mehrerer Festplatten über einen Festplattencontroller
	Unabängigkeit der Disks als Vorteil?
	Mehr Speicherplatz als Raid1

Ausserdem:
Weitere Raid Kombinationen: Raid 01, Raid 03 .....
Raid 1.5 als Kombination der Vorteile von Raid 0 und Raid 1 (Lesen wie Raid0, Schreiben wie Raid 1)
Matrix Raid: Implementation verschiedener Raid Technologien auf demselben Festplatten-Array
