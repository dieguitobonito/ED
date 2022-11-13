Hola,
* Hola, espero que estés muy pero que muy bien
* Esto es una prueba de markdown en neovim

## Generar números aleatorios
Para poder realizar asignación automática de los precios y los id de los nodos
Así como crear nodos automáticamente
* Ahora resulta que `rand()` es inseguro para utilizar, que es
mejor utilizar `<random>`
* Solo puedo agregar de 50 en 50, qué raro
* Intentando saber si se puede comparar strings sin tener que capitalizarlos, parece ser que no es posible...?
* `bad_alloc` ocurre porque la memoria no alcanza, quizá sea porque tengo poquita, dependerá del equipo que ajuste la memoria

Sacando los nombres de los productos de aquí
**Foto**

Otro problema surgió de la asignación automática de nodos; no es posible
ordenar con cantidades mayores a 50 nodos, me lanza
```
free():invalid size
aborted (core dumped)
	```
Parece ser que el error se da porque no coloco un cout dentro del ciclo,
	quizá porque se agobia por mover muchas direcciones de memoria...?

	En insertsort si no coloco couts todo se va a la ñonga por alguna razón, la lista no se ordena
	Yo creo que es por mal manejo de la memoria en el programa
