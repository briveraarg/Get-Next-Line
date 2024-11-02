## Mi Get Next Line

El objetivo de este proyecto es programar una función que devuelva una línea leída de un file descriptor.


---

### Objetivos

- Implementar `get_next_line()` con un tamaño de buffer determinado por el flag `-D BUFFER_SIZE=xx`.
- Asegurarte de que tu función compile correctamente con y sin el flag `-D BUFFER_SIZE`.
- El programa se compilará de la siguiente manera (ejemplo con un tamaño de buffer de 42):
  ```bash
  cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c
  ```

#### Comportamiento Indeterminado

- `get_next_line()` tendrá un comportamiento indeterminado si el archivo apuntado por el descriptor de archivo (fd) ha cambiado desde la última llamada, siempre que `read()` no haya llegado al final del archivo.
- La función también tendrá un comportamiento indeterminado si se intenta leer un archivo binario.

### Consideraciones

- Se prohíbe el uso de `libft`, `lseek`, y variables globales.

Los archivos de mi GNL:
- [get_next_line.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line.c)
- [get_next_line.h](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line.h)
- [get_next_line_utils.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_utils.c)

## Funciones

- **`char *get_next_line(int fd)`**: 
  Función principal que gestiona la lectura y retorno de líneas desde un file descriptor.
  
- **`char *readmyfd(char *texread, int fd)`**: 
  Lee del file descriptor y almacena el contenido en `texread`, concatenando hasta que se encuentre un salto de línea o se agoten los bytes a leer.

- **`char *createmyline(char *texread)`**: 
  Crea una nueva línea a partir del contenido leído, retornando la línea hasta el salto de línea.

- **`char *update_texread(char *texread)`**: 
  Actualiza `texread` eliminando la línea que acaba de ser leída.

- **`char *freefree(char *texread, char *texread_print)`**: 
  Libera la memoria de las variables pasadas y retorna `NULL`.Aquí tienes el texto listo para copiar y pegar en tu archivo `README.md`:

---

### ¿Por qué es necesaria `update_texread`?

La función `get_next_line` no lee el archivo carácter por carácter. En su lugar, utiliza un búfer de tamaño fijo (`BUFFER_SIZE`) para leer en bloques de memoria desde el archivo. Esto significa que:

1. **Lectura en Bloques**: `get_next_line` utiliza la función `readmyfd` para leer datos en bloques de tamaño `BUFFER_SIZE`. Esto hace que la lectura sea más eficiente, pero también implica que puede almacenar en memoria más de una línea a la vez, si el bloque leído contiene saltos de línea (`\n`).
   
2. **Posible Acumulación de Varias Líneas**: Al leer bloques de tamaño `BUFFER_SIZE`, es posible que `readmyfd` lea más de una línea en una sola llamada o incluso una línea y parte de la siguiente. Por ejemplo, si `BUFFER_SIZE` es 20, pero una línea tiene solo 10 caracteres, `texread` podría contener esa línea **y parte de la siguiente**.

3. **Extracción de una Línea**: Para cada llamada a `get_next_line`, se extrae solo la primera línea de `texread`. Sin embargo, al hacerlo, en `texread` puede quedar almacenado contenido adicional (el bloque sobrante o la parte de la siguiente línea).

### ¿Qué hace `update_texread`?

La función `update_texread` tiene la responsabilidad de **actualizar el contenido de `texread`** después de cada línea extraída. 

1. **Elimina el Contenido Procesado**: Una vez que `createmyline` extrae la primera línea de `texread`, `update_texread` elimina esa línea procesada, dejando en `texread` únicamente el contenido pendiente.

2. **Mantiene la Continuidad de la Lectura**: Al actualizar `texread` para que solo contenga los datos no procesados, `update_texread` permite que `get_next_line` continúe de manera continua y eficiente, siempre leyendo desde donde se quedó en la última línea procesada.

### Ejemplo

Imaginemos un archivo con el siguiente contenido:
```
"Hola, Argentina!\n¿Cómo estás?\nTodo bien, gracias.\n"

```
Y un `BUFFER_SIZE` de 20.

- **Primera llamada** a `get_next_line`:
`readmyfd` lee un bloque de 20 "Hola, Argentina!\n¿Cómo "
`createmyline` extrae "Hola Argentina\n", pero **queda en `texread`**:

  ```
  "¿Cómo "

  ```

- **`update_texread` limpia `texread`** para que solo contenga "¿Cómo ", permitiendo que la siguiente llamada a `get_next_line` continúe leyendo desde esta posición.

## Resumen

La función `update_texread` es crucial para:
- **Manejar la lectura en bloques de memoria**: ajustando `texread` para que no acumule datos ya procesados.
- **Garantizar la continuidad de la lectura línea por línea**: cada llamada a `get_next_line` procesa una línea nueva sin repetir información ya leída.

Sin `update_texread`, el contenido leído podría duplicarse, y `get_next_line` no funcionaría correctamente en archivos con varias líneas o en casos donde `BUFFER_SIZE` es mayor que la longitud de una línea.

--- 

Este contenido debería ser fácil de entender para otros desarrolladores al leer el `README.md` de tu proyecto.

---

### Bonus

En la versión bonus de [get_next_line_bonus.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_bonus.c), se ha añadido la capacidad de manejar múltiples descriptores de archivo (fd) utilizando un array estático de punteros `texread`. Esto permite gestionar la lectura de líneas desde diferentes archivos sin interferencias.

- **Array Estático**: Se utiliza `static char *texread[1024]`, lo que proporciona un espacio en memoria independiente para cada descriptor de archivo, facilitando la lectura simultánea de varios archivos.

- **Verificación de fd**: La función comprueba que el fd esté en el rango de 0 a 1023. Si el fd es inválido o si `BUFFER_SIZE` es menor o igual a 0, retorna `NULL`.

Este enfoque garantiza que cada archivo se lea de manera independiente, evitando la sobreescritura de datos.


Los archivos de la parte bonus deben tener el sufijo `_bonus`:
- [get_next_line_bonus.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_bonus.c)
- [get_next_line_bonus.h](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_bonus.h)
- [get_next_line_utils_bonus.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_utils_bonus.c)

---

### Ponlo a prueba
- [mitexto.txt](https://github.com/briveraarg/Get-Next-Line/blob/main/mitexto.txt)
- [int_main.c](https://github.com/briveraarg/Get-Next-Line/blob/main/int_main.c)

---
