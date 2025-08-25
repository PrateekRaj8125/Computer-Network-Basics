# 🌐 Basics of Socket Programming  

This folder introduces the **fundamentals of socket programming** in C using the **connectionless (UDP)** model.  
It demonstrates how two programs (a client and a server) can communicate using IP addresses and port numbers.  

---

## 📘 Coverage  

- Introduction to **Socket Programming**  
- UDP sockets (connectionless communication)  
- Using **IP address** and **port numbers** as identifiers  
- Exchanging messages between processes  

---

## 📝 Assignment  

- Write a **client** and **server** program in C.
  
  - Accept IP address and port number as command-line arguments.  
  - Both client and server exchange messages continuously.  
  - If either side receives the `"exit"` message, both should close the connection gracefully.  
  - Assume both programs run on the same host.
    
- Files
  
  - UDP Client Program - [udp_client.c]()
  - UDP Server Program - [udp server.c]()
---

## ▶️ How to Compile & Run  

### Step 1: Compile both programs  
```sh
$ gcc udp_server.c -o udp_server
$ gcc udp_client.c -o udp_client
```

