[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6870060&assignment_repo_type=AssignmentRepo)
# fsm_bump_go

## 0. Introducción
En esta práctica utilizaremos un robot y 2 de sus sensores (láser y bumper). Se implementarán 3 versiones para el desplazamiento del robot.

Nombre del robot --> *Kobuki*

Nombre del láser -->*Rplidar*

En primer lugar, la versión 0, solo utiliza el bumper del kobuki, de forma que cuando note un obstáculo pueda esquivarlo.
Por otro lado, la versión 1, es una modificación de la versión 0 en la que se intenta esquivar obstáculos de manera inteligente.
Por último, la versión 2, implementa la utilización del láser, con ello podemos esquivar objetos antes de detectarlos con el bumper.

## 1. Version 0

### 1.0. Introducción

En esta primera versión empezaremos a tomar contacto con uno de los sensores más sencillos del kobuki, el bumper. Este sensor detecta obstáculos por el contacto, emitiendo una señal de 0 cuando no hay contacto y de 1 cuando éste es detectado. De esta forma seremos capaces de  detectar cualquier objeto que se encuentre en el camino de nuestro kobuki.

### 1.1. Objetivo

El objetivo de esta versión es que el kobuki sea capaz de navegar autonomamente sin quedarse atascado, esquivando los obstáculos de una forma sencilla, cuando choque contra ellos, retroceder y girar hacia un lado. 

### 1.2. ¿Qué hemos hecho?

Para la práctica hemos implementado la herencia y creado este primer programa como base para los siguientes. En nuestro programa simplemente utilizamos una máquina de estados que varía cuando el kobuki detecta el contacto, retrocediendo, girando y nuevamente avanzando hasta volver a chocar.

  ### [Video del funcionamiento de la version 0](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ERZZHS94AaRIvg1dBxt_WscB_xtm80WHpZEaWqBEXvW4LQ?e=JcuD3L)
  
## 2. Version 1
En esta versión, implementamos una nueva clase virtual, BaseDetected, de la que hereda la clase BumpGOEficiente. Esta clase mejora el BumpGo de la versión anterior añadiendo un cuarto estado, girar a la derecha. Ahora cuando el bumper detecta pressión, es decir choca con un objeto, gira en direccion contraria para evitarlo. Si choca en el centro, va a la izquierda. Además, hemos implementado un launcher para lanzar el nodo con parámetros de velocidad, tiempo de giro, etc.
  ### [Video del funcionamiento de la version 1]()

## Version 2

### 2.0. Introducción

Para la versión final implementaremos el uso del láser, un sensor que toma mediciones en un rango angular de 0º-360º y en un rango de distancias de 0,03m-20m. La complejidad de esta práctica radica en la toma de medidas, ya que cualquier medida fuera del rango de distancias puede ser tomada como null o infinito, además, hay que saber en que lado del kobuki está el obstaculo a esquivar. 

### 2.1. Objetivo

El objetivo final es conseguir una navegación autónoma del kobuki, siendo éste capaz de esquivar cualquier objeto sin llegar a chocarse (como en las versiones anteriores) y de forma eficiente, es decir, girar al lado contrario del obstáculo para no derivar en una navegación circular.


### 2.2. ¿Qué hemos hecho?


  ### [Video del funcionamiento de la version 2](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ETAaWriBvK5HuAAXQX6tWpQBq08uD1GSxMVqdE8Hc-Z_mQ?e=NgtHHE)
  
## Observaciones
(Problemas que hemos tenido o alguna observacion a destacar)
