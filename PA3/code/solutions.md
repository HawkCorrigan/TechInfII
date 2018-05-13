## 2.1:

Beim spaltenweisen Vorgehen hat die CPU deutlich mehr cache-references und cache-misses, sowie etwas mehr
branch-misses. Jeweils das neu zugegriffene Array wird also neu gecached, das least recently used - Element
wird ersetzt. Da man aber danach wieder in ein neues, ungecachetes Array einsteigt, geht das immer so weiter.

## 2.2:

1. Der Identifier des allokierten (und geteilten) Speichersegments (mit 0en) wird zurückgegeben.
2. Check, ob das vorher allokierte Speichersegment zur Löschung markiert wurde.
3. Key wird mit anderen im Kernel verglichen und entscheiden ob ein neues Segment erstellt wird/nicht.
4. Durch die Angabe des gleichen pathname(s) und der gleichen proj_id.
5. Über den Rückgabewert von shmat, der auch gleichzeitig das Segment überhaupt in den virtuellen Adressraum des Prozesses bringt.
6. Über die shmid, den ersten Übergabewert.
7. Mit shmdt wird das Segment vom Prozess getrennt.



1. Mit shmctl und dem cmd IPC_RMID wird das Segment zur Löschung markiert.
2. Nein, erst wenn alle Prozesse detached sind.
3. Nach detach ist nattch 0, vorher 2. Nach shmctl und IPC_RMID ist das Segment gelöscht.
