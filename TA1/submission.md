# 1. Allgemeines

1. Virtualisierung darunter liegender Strukturen (Speicher, Netzwerk, GUI), Prozess- und Speicherverwaltung

2. Kernel, UI, Netzwerkimplementation, security **EXPAND**

3. UEFI/BIOS --> POST --> Such was bootbares(MBR boot sequence) --> VBR --> Kernel

# 2. Grundlagen

## a) Prozesse

1. Prozess ist eine ausführungsinstanz eines Programms.
    Ein Programm beschreibt Prozesse.
    Prozesse haben einen Zustand, der sich über die Zeit t ändert.
2. Das Betriebsystem übernimmt bei Prozessen die Quasi-Parallelisierung (Multitasking), also das schnelle wechseln zwischen Prozessen um einen Eindruck der gleichzeitigkeit zu vermitteln.
3. Linux nutzt Completely Fair Scheduler und nutzte O(1)-Scheduler, Windows den Windows-Scheduler, Mac nutzt den Mach-Scheduler **EXPAND**
4. **`ps`**: Zeige laufende Prozesse, *`-e`* zeige alle laufenden Prozesse
5. **`kill`**, beendet einen Prozess, benötigt PID, man kann als optionalen parameter noch das Signal angeben, z.B. `-10` oder `-SIGSTOP` 
6. **procfs** ist das process filesystem (man kann alle Prozesse wie dateien betrachten, bzw deren Infos in einer verzeichnis struktur unter /proc), man greif darauf zu wie auf normale dateien
`cd /proc && ls -lah`

## b) Speichermanagement
1. Der Hauptgrund sind die verschiedenen benötigteten Größen und geschwindigkeiten. Generell gilt in bezug auf Geschwindigkeit: CPU Cache > RAM > Festspeicher und genau umegekehrt für Größe/Kapazität.
2. Durch den eben erwähnten CPU Cache. Den gibt es als L1, L2 und L3 Cache, wobei der L1 Cache der Kleinste aber auch der Schnellste ist.
3. Management des VMM, also die Adressierung des Arbeitsspeicher für einzelne Prozesse.
4. **`free`** zeigt einem den gesamten, verfügbaren und belegten RAM-Speicher und SWAP-Speicher
Unter Windows: `Ctrl + Shift + Esc` öffnet den Taskmanager und unter Windows 10 im Tab *Leistung* sieht man die gleichen Informationen
5. SEGFAULT bezeichnet das verletzen einer/der Speicherzugriffsrichtlinie des Betriebsystems. Also ein Prozess versucht auf eine Speicheradresse zuzugreifen auf die es keine Zugrifsberechtigung hat.

## c) Input/Output
1. Interrupts/Polling, DMA
2. warten dass busy-bit nicht gesetzt ist, busy bit setzen, lesen, busy bit resetten
3. Ein interrupt ist eine Anweisung an die CPU das sie das was sie gerade macht unterbrechen soll und das interruptsignal verarbeiten soll. Ein Trap bezeichnet einen Ausführungsfehler wobei die Kontrolle vom Prozess an den Betriebsystemkernel übergeben wird.
4. Linux behandelt I/O-Geräte genauso wie alles andere wie eine Datei (frei nach dem Motto [Everything is a file](https://de.wikipedia.org/wiki/Everything_is_a_file)) somit lassen sich z.B. durch `cd /dev && ls -lah` alle verfügbaren Geräte anzeigen. (der Name der Datei beschreibt den Gerätetyp)

## d) Dateisysteme

1. Betriebssystem kümmert sich um Ordnung und Zugriffe
2. **`ls -lah`**, `-l` liste, `-a` alles, `-h` menschenlesbar bzw. `dir` auf Windows
3. Zeige alle einbindungspunkte + Laufwerksgröße + Belegter und Freier speicher
4.  
#### Linux:
* fat (max 2G per file, von allen Gängigen Betriebsystemen unterstützt)
* fat32 (max 4G per file)
* exfat
* ext2/3/4 (ohne zusatztzeiber nur auf Unix/Linux verfügbar, kein hartes Dateigrößen limit)
* vfat
* NTFS
* lvm
* zfs
* glusterfs (Server-supported)
* ceph (Server-supported)
* und noch ein paar...
#### Windows:
* NTFS
* fat
* fat32
5. **`mount`** Bindet ein Dateisystem ein, **`umount`** entfernt einen einhängepunkt

## e) Netzwerke

1. Ethernet, Wireless?
2. TCP/IP (in den varianten v4 und v6) und UDP (beides auf Layer 4) oder IP auf Layer 3
4. Linux: z.B. `ip addr` oder auch `ifconfig`
Windows: `ipconfig` gerne auch mit dem parameter `/all` 
5. Um alle offenen Ports und alle vorhandenen Verbindungen anzuzeigen.