[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6870060&assignment_repo_type=AssignmentRepo)
# fsm_bump_go

## 0. Introducción
En esta práctica utilizaremos un robot y 2 de sus sensores (láser y bumper). Se implementarán 3 versiones para el desplazamiento del robot.

Nombre del robot --> *Kobuki*

Nombre del láser -->*Rplidar*

En primer lugar, la versión 0, solo utiliza el bumper del kobuki, de forma que cuando note un obstáculo pueda esquivarlo.
Por otro lado, la versión 1, es una modificación de la versión 0 en la que se intenta esquivar obstáculos de manera inteligente.
Por último, la versión 2, implementa la utilización del láser, con ello podemos esquivar objetos antes de detectarlos con el bumper.

![kobuki](https://user-images.githubusercontent.com/90764701/154570504-dec4714e-e3a4-4ba8-bfc1-0cd0553e0da6.jpg)

![kobuki con ordenador](https://user-images.githubusercontent.com/90764701/154570436-daeb5a06-6168-405d-b3c9-3d36c738faed.jpg)


## 1. Version 0

### 1.0. Introducción

En esta primera versión empezaremos a tomar contacto con uno de los sensores más sencillos del kobuki, el bumper. Este sensor detecta obstáculos por el contacto, emitiendo una señal de 0 cuando no hay contacto y de 1 cuando éste es detectado. De esta forma seremos capaces de  detectar cualquier objeto que se encuentre en el camino de nuestro kobuki.

### 1.1. Objetivo

El objetivo de esta versión es que el kobuki sea capaz de navegar autonomamente sin quedarse atascado, esquivando los obstáculos de una forma sencilla, cuando choque contra ellos, retroceder y girar hacia un lado. 

### 1.2. ¿Qué hemos hecho?

Para la práctica hemos implementado la herencia y creado este primer programa como base para los siguientes. En nuestro programa simplemente utilizamos una máquina de estados que varía cuando el kobuki detecta el contacto, retrocediendo, girando y nuevamente avanzando hasta volver a chocar.

  ### [Video del funcionamiento de la version 0](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ERZZHS94AaRIvg1dBxt_WscB_xtm80WHpZEaWqBEXvW4LQ?e=JcuD3L)
  
## 2. Version 1

### 2.0. Introducción

Esta versión es una ampliación de la primera. Utilizaremos un nuevo dato del bumper llamado state que devuelve 0 cuando es presionado por la izquierda, 1 centro y 2 derecha. este nuevo dato nos ayudará a saber en que lado se ha detectado el objeto.

### 2.1. Objetivo

El objetivo es mejorar el anterior programa de modo que ahora esquive al objeto detectado de forma eficiente. Por ejemplo, si el objeto se encuentra a la izquierda del robot que este gire a la derecha. 

### 2.2. ¿Qué hemos hecho?

#### 2.2.0 Clase BaseDetected

Implementamos una nueva clase abstracta, BaseDetected. Esta clase es de la que heredarán las proximas clases. Incluye las variables y programas básicos que deben implementar todas las clases orientadas a moverse en base a las lecturas de un sensor. Creamos una clase *BumpGoEficiente* que heredará de esta (como también hará más tarde *BumpGoLaser*).

#### 2.2.1 Ampliación de BumpGo

Esta clase mejora el BumpGo de la versión anterior añadiendo un cuarto estado, girar a la derecha. Ahora cuando el bumper detecta pressión, es decir choca con un objeto, gira en direccion contraria para evitarlo. Si choca en el centro, va a la izquierda. 

#### 2.2.2 Launcher

Hemos implementado un launcher para lanzar el nodo con parámetros de velocidad, tiempo de giro, etc. Estos parámetro se encuentran en un fichero *.yaml* , al editarlos no será necesario compilar para que cambien los valores en el programa por lo que tiene una gran ventaja. 
  ### [Video del funcionamiento de la version 1](https://drive.google.com/file/d/13FJBwNCYC927cHRqDCM2qJm89MI393FA/view?usp=sharing)

## Version 2

### 3.0. Introducción

Para la versión final implementaremos el uso del láser, un sensor que toma mediciones en un rango angular de 0º-360º y en un rango de distancias de 0,03m-20m. La complejidad de esta práctica radica en la toma de medidas, ya que cualquier medida fuera del rango de distancias puede ser tomada como null o infinito, además, hay que saber en que lado del kobuki está el obstaculo a esquivar. 

### 3.1. Objetivo

El objetivo final es conseguir una navegación autónoma del kobuki, siendo éste capaz de esquivar cualquier objeto sin llegar a chocarse (como en las versiones anteriores) y de forma eficiente, es decir, girar al lado contrario del obstáculo para no derivar en una navegación circular.


### 3.2. ¿Qué hemos hecho?

#### 3.2.1. Uso de números mágicos:

Hemos usado una regla sencilla, el array tenía *msg->range.size()* posiciones (760), por lo que hicimos una regla de tres para compararlo con los ángulos.

La siguiente:
cte = 760/360

De esta forma sacamos una relacion entre angulos y posiciones.

Nuestro kobuki tiene la posicion 0 justo en frente, por lo que complica recoger este abanico de posiciones.
Usando dos fors hemos conseguido recorrer ambos abanicos.

#### 3.2.2. ¿Cómo los hemos dividido?

Para sacar el primer abanico en grados sería algo así : 0º-45º
Para sacar el segundo abanico sería: 315º-360º

De esta forma solo nos fijamos en la parte de delante y de los lados.

Para pasarlo a posiciones de array:
El primer trozo sería desde 0 hasta 45 * cte.
El segundo trozo sería desde 315 * cte hasta 360 * cte.

#### 3.2.3. ¿Cómo diferenciamos qué lado detecta?

Cuando el láser detecta un objeto a menos de 0.6m se rompe el bucle y guardamos esa posición del array en pos_objeto_

Más tarde para girar hacemos una comparaión:
Si (315 * cte < pos_objeto_ < 360 * cte):
Esto sería que hemos detectado algo por la parte izquierda del kobuki, por lo que giramos a la izq.

Sino fuese así, giramos a la derecha.

#### 3.2.4. Implementación de parámetros

Por último hemos creado un archivo de configuración *BumpGoConfig.yaml*, para poder cambiar parámetros básicos como velocidad del kobuki, distancia de giro, etc.

  #### [Video del funcionamiento de la version 2](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ETAaWriBvK5HuAAXQX6tWpQBq08uD1GSxMVqdE8Hc-Z_mQ?e=NgtHHE)
  
