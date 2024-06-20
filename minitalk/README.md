
#### minitalk/README.md

```markdown
# minitalk

## Descripción
Proyecto para la comunicación entre procesos usando señales de Unix.

## Uso
Compila el servidor y el cliente usando `make` y luego ejecuta el servidor antes de enviar mensajes con el cliente.

```sh
make
./server
./client [PID] [mensaje]
