*This project has been created as part of the 42 curriculum by smargaro*

## Description
Lo scopo di questo progetto è quello creare una funzione che permetta, datao un flile testo, di leggere un file con fd e buffer size dati ed ritornare una riga ad ogni chiamata della stessa.

## Instructions
La funzione richiede un file descriptor e un BUFFER_SIZE utilizzato dalla funzione read. Ripetute chiamate funzione restituiranno la riga letta comprensiva del carattere '/n'. L'ultima riga ovviamente non ne sarà provvista.

## Resources
Al fine di sviluppare questa funzione, ho consultato risorse online per approfondire la comprensione del funzionamento delle variabili statiche e delle capacità delle memorie heap e stack.  Il confronto con tra peer si è rivelato prezioso per chiarire il subject e comprendere il corretto funzionamento della funzione.
### AI USAGE
L’utilizzo dell’Intelligenza Artificiale si è rivelato un valido supporto per la rapida definizione degli argomenti precedentemente menzionati.  Si è dimostrata particolarmente utile per comprendere il funzionamento della funzione read, in particolare per chiarire i dubbi riguardanti la posizione di ripartenza della lettura ad ogni chiamata alla funzione.  Inoltre, ho impiegato questa tecnologia per il debugging del codice, al fine di individuare ed analizzare eventuali errori concettuali nella gestione della memoria e delle variabili static.


## Additional sections

L’algoritmo implementato valuta l’incompatibilità dei dati assegnati alla funzione. Inizialmente, esegue una lettura del file descriptor, memorizzando i dati letti in una variabile dinamica, al fine di sfruttare la memoria heap, che offre una capacità di archiviazione superiore rispetto alla memoria statica.

Successivamente, un ciclo while verifica la presenza del carattere ‘/n’ all’interno della variabile contenente i dati letti. In assenza di tale carattere, il ciclo viene ripetuto, accodando i dati letti in una variabile statica, fino a quando la funzione read restituisce un valore maggiore di zero. Al verificarsi di tale condizione, il ciclo viene terminato.

A questo punto, viene estratta la porzione di stringa compresa tra l’inizio della stringa e il carattere ‘/n’ (incluso quest’ultimo), e viene memorizzata in una variabile per essere successivamente restituita.  La variabile statica viene quindi aggiornata per le successive invocazioni della funzione. Infine, la variabile contenente la stringa estratta viene restituita.
