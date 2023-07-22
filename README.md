# Minitalk|
![Project Image](img/src.png)


### **You must create a communication program in the form of a client and a server.** ###

- The server must be started first. After its launch, it has to print its PID.

- The client takes two parameters:

- The server PID.

- The string to send.

- The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.

- Your server should be able to receive strings from several clients in a row without
needing to restart.

- The communication between your client and your server has to be done only using
UNIX signals.


<mark>You can only use these two signals: SIGUSR1 and SIGUSR2.

---
