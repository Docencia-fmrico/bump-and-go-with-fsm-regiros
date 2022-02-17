[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6870060&assignment_repo_type=AssignmentRepo)
# fsm_bump_go

## Explicación del Láser

### Uso de números mágicos:

He usado una regla sencilla, el array tenía msg->range.size() posiciones (760).
Usar las posiciones para quedarnos solo con un trozo es muy chapuza por lo que hice una regla de tres para compararlo con los ángulos.

La siguiente:
cte = 760/360

De esta forma sacamos una relacion entre angulos y posiciiones.

Nuestro kobuki tiene la posicion 0 justo en frente, por lo que complica recoger este abanico de posiciones.
Usando dos fors hemos conseguido recorrer ambos abanicos.

### ¿Cómo los hemos dividido?

Para sacar el primer abanico en grados sería algo así : 0º-45º
Para sacar el segundo abanico sería: 315º-360º

De esta forma solo nos fijamos en la parte de delante y de los lados.

Para pasarlo a posiciiones de array:
El primer trozo sería desde 0 hasta 45 * cte.
El segundo trozo sería desde 315 * cte hasta 360 * cte.

### ¿Cómo diferenciamos qué lado detecta?

Cuando el laser detecta un objeto a menos de 0.6m se rompe el bucle y guardamos esa posición del array en pos_objeto_

Más tarde para girar hacemos una comparaión:
Si (315 * cte < pos_objeto_ < 360 * cte):
Esto sería que hemos detectado algo por la parte izquierda del kobuki, por lo que giramos a la izq.

Sino fuese así, giramos a la derecha.

## Recordatorio

Alomejor hay algunas declaraciones en el .h y .cpp sin utilizar, por si quereis limpiar el código.
De todas formas, se puede limpiar y dejar mucho más bonito, solo hemos sido capaces de hacer que funcione perfecto, no nos ha dado tiempo a limpiarlo.
