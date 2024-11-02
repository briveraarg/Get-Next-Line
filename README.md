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

- Intenta minimizar las lecturas cada vez que se llame a `get_next_line()`. Si encuentras un salto de línea, deberás devolver la línea actual en lugar de leer el archivo completo.
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
  Libera la memoria de las variables pasadas y retorna `NULL`.

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
