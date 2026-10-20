# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Se usan dos árboles AVL, uno para monedas y otro para pinturas. Como el AVL se mantiene balanceado con rotaciones, su altura es O(log N), así que insertar y buscar cuestan O(log N). Rango recorre solo las ramas que pueden tener elementos dentro del intervalo, por lo que cuesta O(log N + K), siendo K la cantidad de elementos que devuelve. El espacio es O(N), por los nodos de los árboles.

## Ejercicio 2
- Se usa una tabla de hash abierto donde la clave de cada palabra es su firma (cuántas veces aparece cada letra). Como el tamaño de la tabla es un primo mayor o igual a la cantidad de palabras, cada lista tiene en promedio O(1) elementos, así que registrar y consultar cuestan O(L) en promedio, siendo L el largo de la palabra. La cantidad de cajones y el cajón más grande se guardan en contadores, así que obtenerlos cuesta O(1). El espacio es O(N), por la tabla y como máximo un nodo por palabra.

## Ejercicio 3
-  Se usa un min-heap sobre arreglo. Cada insertar y borrar cuesta O(log N), porque flotar y hundir recorren como maximo la altura del árbol. Se insertan N archivos y se hacen N − 1 consolidaciones, cada una con dos borrar y un insertar, por lo que el tiempo total es O(N log N). En espacio solo se usa el arreglo del heap, que nunca tiene más de N elementos, por lo que el espacio es O(N).

## Ejercicio 4
- Se usa orden topológico (algoritmo de Kahn) con un min-heap ordenado por prioridad. Armar las listas de adyacencia y el arreglo de dependencias cuesta O(V + A). Cada vértice entra y sale del heap una sola vez, y cada operación cuesta O(log V) porque flotar y hundir recorren como máximo la altura del árbol, por lo que el heap suma O(V log V). Cada arista se recorre una sola vez, lo que suma O(A). El tiempo total es O(A + V log V). En espacio se usan arreglos de tamaño V, las listas de adyacencia y el heap, por lo que el espacio es O(V + A).

## Ejercicio 5
- Se usa Kruskal con un min-heap y conjuntos disjuntos. Cada senderos entra y sale del heap una sola vez, a O(log E) cada operación, por lo que el heap suma O(E log E). Encontrar y unir cuestan como máximo O(log V) gracias a la unión por altura, y con compresión de caminos son casi O(1). El tiempo total es O(E log E). En espacio se usan el arreglo de senderos y el heap, O(E), y los vectores del conjunto disjunto, O(V), por lo que el espacio es O(V + E).

