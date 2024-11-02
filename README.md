## Mi Get Next Line

El objetivo de este proyecto es programar una función que devuelva una línea leída de un file descriptor. A través de este proyecto, aprenderás el concepto de variables estáticas en C y cómo manejar la lectura eficiente de archivos.

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

Los archivos de la parte bonus deben tener el sufijo `_bonus`:
- [get_next_line.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line.c)
- [get_next_line.h](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line.h)
- [get_next_line_utils.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_utils.c)

---

### Bonus

- Desarrollar `get_next_line()` utilizando solo una variable estática.
- Hacer que `get_next_line()` pueda gestionar múltiples file descriptors (fd) simultáneamente, sin perder el hilo de lectura de cada uno.

Los archivos de la parte bonus deben tener el sufijo `_bonus`:
- [get_next_line_bonus.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_bonus.c)
- [get_next_line_bonus.h](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_bonus.h)
- [get_next_line_utils_bonus.c](https://github.com/briveraarg/Get-Next-Line/blob/main/get_next_line_utils_bonus.c)

---

### Ponlo a prueba
- [mitexto.txt](https://github.com/briveraarg/Get-Next-Line/blob/main/mitexto.txt)
- [int_main.c](https://github.com/briveraarg/Get-Next-Line/blob/main/int_main.c)

---
