# Bitácora — Obligatorio 1

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-21— En conjunto
- Leimos la letra, implementamos Avl con ayuda del material de las presentaciones, no terminamos el ejercicio 1.
A la hora de la implementacion de Rango en Avl, comenzamos con la idea de que iba a ser parecido a buscar, pero la estrategia no funciono y tuvimos que cambiar a un  un recorrido in-order.

## 2026-10-09- En conjunto
- Terminamos el ejercicio 1, resolviendo los ultimos errores que teniamos. Utilizamos copilot para esto, ya que habian muchos errores que no sabiamos corregir, muchos de los cuales eran errores con "*"

- Comenzamos a implementar hash para el ejercicio 2 , las ideas que tuvimos para la implementacion es un array de listas que las listas guarden, la cantidad de palabras registradas por un cajon en especifico y un array de 26 espacios en 0 que cada uno representa una letra y se guarda un numero representando la cantidad de veces que aparece esa letra en el cajon de palabras, nuestra primera idea de funcion de hash fue sumar los valores ascii de cada letra de la palabra, esta idea siempre da numeros muy chicos , la distribucion va a ser mala y las listas quedan largas.

## 2026-10-16- En conjunto
- Implementamos todo el ejercicio 2, terminamos apoyandonos en claude para la funcion de hash
- La prueba de 100 pasa

## 2026-10-17- En conjunto
- Tuvimos la idea de usar min heap para tener los archivos mas chicos a simple alcanze, utilizamos el Minheap. Trabajamos plenamente en el arreglo ya que era mas facil hundir y flotar los datos a ingresar y borrar.  
- Para consolidar, cargamos los tamaños en el min heap, extraemos los dos mínimos, sumamos sus tamaños, reinsertamos el archivo nuevo y sumamos el costo hasta que queda uno.
