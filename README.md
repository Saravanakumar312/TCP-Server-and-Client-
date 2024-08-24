
# TCP Server and Client Example

This repository contains a simple example of a TCP server and client implementation in C. The server listens for incoming connections and responds to client messages, while the client sends a message to the server and receives a response.

### Features

- **TCP Server:**
  - Listens for incoming connections on a specified port.
  - Accepts connections from clients and handles data reception.
  - Sends a predefined response to the client.

- **TCP Client:**
  - Connects to the TCP server.
  - Sends a user-defined message to the server.
  - Receives and displays the server's response.
## File Overview

- `server.c`: Contains the code for the TCP server.
- `client.c`: Contains the code for the TCP client.

## Prerequisites

- A C compiler (e.g., `gcc`)
- Basic understanding of TCP/IP networking

## Compilation

To compile the server and client programs, use the following commands:

```bash
gcc -o server server.c
gcc -o client client.c
```

## Running the Server

1. Start the server first. Open a terminal and run:

    ```bash
    ./server
    ```

   The server will start and listen for incoming connections on port 8080.

## Running the Client

1. Open another terminal and run:

    ```bash
    ./client
    ```

2. You will be prompted to enter a message to send to the server. Type your message and press Enter.

3. The client will send the message to the server and print the server's response.

## Example

**Starting the Server:**

```bash
./server
Server is running on port 8080...
```

**Client Input:**

```bash
Enter message to send to server: Hello, Server!
```

**Server Output:**

```bash
Client connected.
Client: Hello, Server!
Client disconnected.
```

**Client Output:**

```bash
Server: Hello from server
```

## Code Explanation

### `server.c`

1. **Create Socket:** Creates a TCP socket.
2. **Bind:** Binds the socket to all interfaces on port 8080.
3. **Listen:** Listens for incoming connections.
4. **Accept:** Accepts connections from clients.
5. **Receive/Send:** Receives messages from clients and sends responses.
6. **Close:** Closes the client socket after communication.

### `client.c`

1. **Create Socket:** Creates a TCP socket.
2. **Connect:** Connects to the server on port 8080.
3. **Send:** Sends a user-input message to the server.
4. **Receive:** Receives a response from the server.
5. **Close:** Closes the socket after communication.

### Example

- **Server Output:**
  ```bash
  Server is running on port 8080...
  Client connected.
  Client: [Your Message]
  Client disconnected.
  ```

- **Client Input:**
  ```bash
  Enter message to send to server: [Your Message]
  ```

- **Client Output:**
  ```bash
  Server: Hello from server
  ```
## Notes

- Ensure that the server is running before starting the client.
- You can modify the port and IP address as needed in the code.
- For better error handling and robustness, additional checks and features can be added.

## License

This code is provided under the [MIT License](LICENSE).

---

Feel free to adjust the content according to your project's specifics or any additional features you may have implemented.
