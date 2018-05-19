# Theoretische Aufgabe 3

## Aufgabe 1: Konzepte

### a)

![Diagram](code_dia.png)

- Adressbindung zur Compile-Zeit: Absolute Adressierung gebraucht, keine Relokation möglich.
- Adressbindung zur Load-Zeit: Relokation nur beim Neuladen möglich. (z.B. andere Codemodule oder Systembibliotheken)
- Adressbindung zur Laufzeit: Relokation auch während der Ausführung möglich. (dynamisch verlinkte Bibliotheken)

### b)

Nur bei der Laufzeitadressierung ist es notwendig Prozessadressen und tatsächliche speicheradressen zu trennen.

### c)

- **Swapping**: Die Daten der Prozesse werden abwechselnd in den Speicher geladen und ausgeführt.
- Demand-**Paging**: es wird von beiden Prozessen immer nur ein Teil der Daten in den Speicher geladen und ausgeführt. Bei bedarf (on Demand) werden neue Daten geladen und ersetzen (teilweise) die alten Daten.

### d)

Bei der externen Fragmentierung kann es zu den Phänomen kommen, dass obwohl genug freier Speicher für die neuen Daten vorhanden ist, kein zusammenhängender Block zur verfügung steht, und desshalb der Bereich nicht allokiert werden kann.

- **Paging**: Ich lade nur momentanbenötigte Teile in den Speicher.
- **Garbage-Collection / Compaction**: Ich räume den Speicherbereich regelmäßig auf (und schiebe Speicher zusammen.)

### e)

// TODO

### f)

// TODO

## Aufgabe 2: Virtueller Speicher - Demand Paging

### a)

![Paging](paging.png)

### b)

2<sup>32 </sup>  Adressen * 4 Bytes pro Adresse = 16 GiB

### c)

// TODO