# minishell

El objetivo de este proyecto es crear un terminal sencillo: una versión personalizada de Bash. El objetivo es aprender sobre procesos, manipulación de archivos y funciones del sistema en el entorno Unix.

## Descripción

**minishell** es un proyecto que se remonta a los inicios de la informática, explorando la creación de un terminal básico para comunicarse con un sistema utilizando líneas de comando interactivas. En este proyecto, nos hemos enfrentado a desafíos similares a los que se encontraban antes de la existencia de sistemas operativos como Windows.

Las caracterísitcas que se han desarrollado han sido:

- Mostrar un *prompt* de comando para introducir comandos.
- Implementar un historial funcional.
- Buscar y ejecutar ejecutables basados en la variable PATH o rutas relativas/absolutas.
- Implementar redirecciones y pipes.
- Gestionar variables de entorno ($ seguidos de caracteres) para expandirse a sus valores.
- Gestionar `$?`, que debe expandirse al estado de salida del comando más reciente.
- Implementar *built-ins* como `echo`, `cd`, `pwd`, `export`, `unset`, `env` y `exit`.
- Manejar señales como ctrl-C, ctrl-D, ctrl-\.

## Requisitos

- El proyecto debe estar escrito en C y seguir la Norma de codificación.
- No debe haber comportamientos indefinidos ni fallos inesperados.
- La gestión de la memoria debe ser impecable para evitar fugas de memoria.
- Incluir un **Makefile** que compile los archivos fuente con las flags `-Wall -Werror -Wextra` sin recompilado.
- El **Makefile** debe contener las normas `NAME`, `all`, `clean`, `fclean` y `re`.
- Se permite el uso de la librería **readline**.

## Uso

**minishell** no recoge ningún parámetro por línea de comandos. Simplemente se lanza desde Bash con:

```bash
minishell
```

## Créditos

42 Málaga - Fundación Telefónica

- mariza
- jmorillo42
