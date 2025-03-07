
# Minitalk

**Minitalk** is a simple project that allows communication between two processes using signals in C. This project was developed during my studies at Hive Helsinki Coding School in 2024.

## Files

- `libft/`: Custom library containing common functions used throughout the project.
- `printf/`: Custom implementation of `printf` for formatted output.
- `client.c`: The client program that sends messages to the server using signals.
- `server.c`: The server program that receives messages from the client using signals.
- `minitalk.h`: Header file containing function declarations and necessary includes.
- `LICENSE`: The license for the project.
- `Makefile`: The file used to compile the project.
- `README.md`: This README file.

## Features

- Communication between client and server using Unix signals.
- The ability to send a string from the client to the server.
- Server processes each character in the string and prints it.
- Custom signal handling to manage data transfer.

## How to Use

### 1. Clone the repository:

```bash
git clone <repository_url>
```

### 2. Compile the project:

Run the `Makefile` to compile the client and server:

```bash
make
```

### 3. Run the server:

To start the server, run:

```bash
./server
```

### 4. Run the client:

To send a message from the client to the server, run:

```bash
./client <server_pid> <message>
```

Replace `<server_pid>` with the process ID of the server and `<message>` with the message you want to send.

## License

This project is licensed under the terms of the LICENSE file.

## Acknowledgements

This project was completed as part of my coursework at Hive Helsinki Coding School in 2024. Special thanks to the instructors and peers for their support.

## Author

Created by Roman Bogoudinov during Hive Helsinki studies.