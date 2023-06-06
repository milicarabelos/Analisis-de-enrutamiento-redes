# Análisis de sistemas de enrutamiento utilizando simulación discreta

Laboratorio 4 de la cátedra Redes y Sistemas Distribuidos 
Grupo 01
Integrantes :

-   *Bazán Tomás*
    
-   *Carabelos Milagros*
    
-   *Pereyra Carrillo Juan Cruz*

## Indice

1. [Resumen Abstracto](#Resumen-Abstracto:)

2. [Introducción](#Introducción:)

3. [Método](#Metos:)

4. [Análisis de Casos](#Parte-Mili)

5. [Resultados](#Resultados:)

6. [Discusión](#Discusión:)

7. [Bibliografía](#Bibliografía-o-Referencias)


---

## Resumen Abstracto:

Aca hay que poner dos/uno parrafitos resumiendo la totalidad del proyecto y sus resultados 
​

---

## Introducción: 

​	En este Proyecto estaremos simulando un protocolo de enrutamiento que diseñaremos, en principio, para una topología de anillo. Veamos entonces que es un protocolo de enrutamiento y que problemas trata de abordar.

​	Los protocolos de enrutamiento pertencen a la capa de red y tienen como propósito llevar paquetes de un host cualorigen a uno de destino siguiendo una ruta conveniente, veremos más adelante que este es nuestro tema central en este laboratorio. Además esta es la principal función de la capa de red, en la mayoría de redes los paquetes requieren de múltiples saltos para llegar a su destino, por eso se hacen uso de algoritmos de enrutamiento, los cuales son los encargados de decidir por cuál linea de salida deben transmitirse los paquetes que llegan a cada enrutador.

​	Como ya mencionamos, vamos a trabajar sobre un *topología de anillo*. El estudio de topologías es un tema muy amplio en las Ciencias de la Computación el cual no abordaremos en este proyecto. Dicho esto, veamos entonces de qué se trata la topología de anillo.

​	La topología de anillo consiste en una estructura donde cada dispositivo se conecta a la red en un camino circular. A su vez, cada uno  se conecta con dos dispositivos vecinos, formando la estructura de anillo. Las topologías de anillos pueden ser unidireccional o bidireccional, en nuestro caso se trata de la segunda. A esto se lo denomina topología de doble anillo (en inglés Dual Ring Topology o full-duplex). 

​	Ahora bien, ¿Qué beneficios nos da una topolgía de anillo y qué deberíamos tener en cuenta a la hora de considerarla?

​	Algunas de las ventajas de esta topología son:\

- No requiere de un nodo central o servidor que administre la conectividad entre dispositivos
- Ya que la configuración de la linea es de punto a punto con un dispositivo en cada lado. Es facil de instalar y reconfigurar, ya que para agregar o quitar dispositivos a la red solo requiere mover dos conexiones.
- Fácil identificación y aislamiento de errores.
- Costo de instalación y expansión bajo.

​	Mientras que las desventajas son:

- Una falla en uno de los dispositivos afecta a la toda la red.
- Es más lento que otras topologías (como la estrella) ya que los datos deben viajar a través de varios dispositivos de la red.
- Si es necesario instalar hardware se debe hacer en cada dispositivo, lo que lo hace más costoso.

​	Dicho esto analicemos nuestro caso de estudio y cuál será nuestro objetivo: 

​	Se nos proporciona con una red de anillo la cual consta de distintos nodos. Cada uno simula una capa de aplicación que envía o recibe el paquete, una capa de red que chequea si es el destino o no, y una capa de enlace que conecta a los dos nodos vecinos mediante dos enlaces distintos. Para enviar paquetes, lo hace en un mismo sentido siempre. Es decir que si envío a la derecha y quiero enviar un paquete a mi primer vecino a la izquierda, el paquete va a recorrer toda la red hasta llegar a su destino.

​	Tenemos que diseñar un algoritmo que mejore de alguna manera este comportamiento y analizar el rendimiento de la red antes y después de las mejoras en dos casos diferentes que serán explicado más adelante.

---



## Métodos: 
describimos la contribucion realizada, los algortmos propuestos en la tarea de diseño

---

## Parte Mili



---

## Resultados:

 Detallamos los resultados de los algoritmos diseñados y una pequeña conclusión
​

---

## Discusión:
 Sección de logros, limitaciones y posibles mejoras de los algoritmos propuestos
---



---



## Bibliografía o Referencias

- Andrew S. Tanenbaum 5ta Edición. *Computer Networks* . Ed. Pearson              <------ ESTO ES UN EJEMPLO

- [www.javatpoint.com What is a ring topology?](https://www.javatpoint.com/what-is-a-ring-topology) 06/06/2023 

-  [www.computerhope.com Ring topology]( https://www.computerhope.com/jargon/r/ringtopo.htm#advantages) 06/06/2023
