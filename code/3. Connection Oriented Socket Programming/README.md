# 🌐 Connection-Oriented Socket Programming (TCP)

This folder demonstrates **connection-oriented socket programming** in C using the **TCP protocol**.
Unlike UDP, TCP establishes a reliable connection between the client and server before exchanging data.

---

## 📘 Coverage

- Basics of **TCP socket programming**
- Connection setup (3-way handshake) and teardown
- **Client–Server communication** using `send()` and `recv()`
- Command-line arguments for flexible execution

---

## 📝 Assignment

Write a **TCP client and server program** in C with the following behavior:

- **Server**
  - Takes the port number as a command-line argument.
  - Binds to the given port and listens for incoming connections.
  - Prints the IP address and port number of the connected client.
  - Exchanges messages with the client.
  - Closes the connection when the client sends `"close"`.

- **Client**
  - Takes the server IP and port as command-line arguments.
  - Connects to the server.
  - Exchanges messages with the server.
  - Sends `"close"` to terminate the connection.

- **Files**
  - TCP server program - [tcp_server.c](https://github.com/PrateekRaj8125/Computer-Network-Basics/blob/main/code/3.%20Connection%20Oriented%20Socket%20Programming/tcp_server.c)
  - TCP client program - [tcp_client.c](https://github.com/PrateekRaj8125/Computer-Network-Basics/blob/main/code/3.%20Connection%20Oriented%20Socket%20Programming/tcp_client.c)

---

## ▶️ How to Compile & Run

### Step 1: Compile the programs

  ```sh
    gcc tcp_server.c -o server
    gcc tcp_client.c -o client
  ```

### Step 2: Start the server

  ```sh
    ./server 8080
  ```

### Step 3: Start the client (in another terminal)

  ```sh
    ./client 127.0.0.1 8080
  ```

### Step 4: Exchange messages

- Type a message in the client → server receives it.
- Type a message in the server → client receives it.
- To close the connection, type:

  ```sh
    close
  ```
  
---

## 🎯 Purpose

- Understand TCP client–server model
- Learn connection-oriented APIs:
  - `socket()`, `bind()`, `listen()`, `accept()`, `connect()`
  - `send()`, `recv()`, `close()`
- Implement graceful connection termination

---

## 📌 Notes

- Run the server before the client.
- Both programs will terminate cleanly once `"close"` is sent by the client.
