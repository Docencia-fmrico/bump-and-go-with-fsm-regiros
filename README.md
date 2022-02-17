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

### 1.0 Introducción

En esta primera versión empezaremos a tomar contacto con uno de los sensores más sencillos del kobuki, el bumper. Este sensor detecta obstáculos por el contacto, emitiendo una señal de 0 cuando no hay contacto y de 1 cuando éste es detectado. De esta forma seremos capaces de  detectar cualquier objeto que se encuentre en el camino de nuestro kobuki.

### 1.1 Objetivo

El objetivo de esta versión es que el kobuki sea capaz de navegar autonomamente sin quedarse atascado, esquivando los obstáculos de una forma sencilla, cuando choque contra ellos, retroceder y girar hacia un lado. 

### 1.2 ¿Qué hemos hecho?

Para la práctica hemos implementado la herencia y creado este primer programa como base para los siguientes. En nuestro programa simplemente utilizamos una máquina de estados que varía cuando el kobuki detecta el contacto, retrocediendo, girando y nuevamente avanzando hasta volver a chocar.

  ### [Video del funcionamiento de la version 0](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ERZZHS94AaRIvg1dBxt_WscB_xtm80WHpZEaWqBEXvW4LQ?e=JcuD3L)
  
## 2. Version 1
(Explicacion del funcionamiento del robot en la version 1, es decir lo que deberia hacer en esta version y lo que hace)
(Insertar video de funcionamiento al final)
  ### [Video del funcionamiento de la version 1]()

## Version 2
(Explicacion del funcionamiento del robot en la version 2, aqui puedes explicar la lógica empleada para el laser consultando los códigos ya que hay cambios realizados en cuanto a las variables utilizadas en las primeras pruebas)
(Insertar video de funcionamiento al final)
  ### [Video del funcionamiento de la version 2](https://urjc-my.sharepoint.com/:v:/g/personal/da_quinga_2020_alumnos_urjc_es/ETAaWriBvK5HuAAXQX6tWpQBq08uD1GSxMVqdE8Hc-Z_mQ?e=NgtHHE)
  
## Observaciones
(Problemas que hemos tenido o alguna observacion a destacar)
