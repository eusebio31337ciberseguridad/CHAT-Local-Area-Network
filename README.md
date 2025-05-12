Programa de Chat Emisor-Receptor en C++

Este programa consiste en una aplicación de chat en modo consola escrita en C++, que permite la comunicación bidireccional entre dos equipos a través de sockets TCP/IP. Está dividido en dos componentes principales: emisor (cliente) y receptor (servidor).
🛠 Tecnologías Utilizadas:
   Lenguaje: C++
   API de red: Berkeley Sockets (Winsock en Windows o BSD sockets en Linux)

🧩 Estructura del Programa:
1. Receptor (Servidor):

    Crea un socket TCP y lo asocia a un puerto específico.

    Escucha conexiones entrantes (listen) y acepta una conexión (accept).

    Recibe mensajes del cliente y puede responder.

    Permanece activo hasta que se cierre manualmente o se termine la conexión.

2. Emisor (Cliente):

    Crea un socket TCP y se conecta a la IP y puerto del servidor.

    Envía mensajes de texto al servidor.

    Recibe respuestas del servidor.

    Maneja la desconexión o cierre del programa de forma segura.

🔐 Características Adicionales (Opcionales):
   Soporte multicliente mediante select() o threading.

   Manejo de errores y desconexiones inesperadas.

💡 Casos de Uso:
