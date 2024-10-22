<h1 align="center">Minitalk</h1>
<p align="center"> 
  <img src="https://img.shields.io/badge/grade-115%2F125-green?style=for-the-badge&logo=42&labelColor=gray"/>
</p>

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/">
    <img src="https://img.shields.io/badge/Signals-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Processes-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Error_Handling-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Bitwise_operation-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Binary_shift-blue?style=for-the-badge"/>
  </a>
</p>

<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#structure">Structure</a> • 
    <a href="#docs">Docs</a> • 
    <a href="#cloning">Cloning</a> • 
    <a href="#usage">Usage</a> • 
    <a href="#norms">Norms</a> • 
    <a href="#theoretical">Theoretical</a>   
  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

**Minitalk** is a project where the goal is to implement a simple data exchange program using UNIX signals (`SIGUSR1` and `SIGUSR2`). The program consists of a server and a client, where the client sends a message to the server, and the server decodes and prints it.

The objective of this project is to deepen the understanding of inter-process communication (IPC) using signals, while also ensuring that the communication is efficient and error-free.

## 🧬 Project Structure <a id="structure"></a>

This project consists of two main parts: the **client** and the **server**.

- **Server**: The server is responsible for receiving messages from the client. It decodes the signals sent by the client and displays the message in real-time. The server can handle multiple clients sequentially.
  
- **Client**: The client takes two parameters, the `server's PID` and the `message` to be sent. It encodes the message as a series of signals and sends them to the server.

Communication between the client and the server is done using only two UNIX signals: `SIGUSR1` and `SIGUSR2`.

## 🗃️ Documentation <a id="docs"></a>

For a detailed breakdown of how the project works, please visit the documentation link below:

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Minitalk/wiki">
    <img src="https://img.shields.io/badge/Minitalk_Docs-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 🫥 Cloning the Repository <a id="cloning"></a>

To clone this repository and compile the project, run the following commands:

```bash
git clone https://github.com/pin3dev/42_Minitalk.git
cd 42_Minitalk/minitalk
```
This will download the project to your local machine. Once inside the `minitalk` directory, run the provided `Makefile` to compile the project.

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

The project comes with a `Makefile` to automate the compilation process. The Makefile includes the following rules:

- `all`: Compiles the server and client programs.
- `clean`: Removes object files.
- `fclean`: Removes object files and the executables.
- `re`: Recompiles the entire project.

To compile the project, run:
```bash
make
```
This will generate the executables `server` and `client`.

### Basic Usage

1. Start the server:
   ```bash
   ./server
   ```
   The server will display its `PID`. This is required for the client to communicate with the server.

2. Send a message from the client:
   ```bash
   ./client <server-pid> "Your message here"
   ```
   The client will send the message to the server, which will then print it.

3. The server can handle multiple clients without needing to restart.

## ⚠️ Norms and Guidelines Disclaimer <a id="norms"></a>

This project follows the [**42 School Norm**](https://github.com/pin3dev/42_Cursus/blob/b9cd0fe844ddb441d0b3efb98abcee92aee49535/assets/General/norme.en.pdf) guidelines. Certain decisions in the implementation may seem unconventional, but they were necessary to comply with the strict coding standards enforced by the school.

## 📖 Theoretical Background <a id="theoretical"></a>

All the theoretical material used to study and carry out this project is organized in the tags described at the beginning of this README.
In addition, these materials can be accessed directly via the link provided below.  

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#02-Minitalk">
    <img src="https://img.shields.io/badge/Minitalk_Theory-gray?style=for-the-badge"/>
  </a>
</p>

