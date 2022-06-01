# Minitalk
*create a communication program in the form of a **client** and a **server***

### Summary
You must create a communication program in the form of a client and a server.The server must be started first. After its launch, it has to print its PID. The client takes two parameters: The server PID. The string to send. The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it. The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long. Your server should be able to receive strings from several clients in a row without needing to restart. The communication between your client and your server has to be done only using UNIX signals. You can only use these two signals:***SIGUSR1*** and ***SIGUSR2***.

### Allowed Functions
- write
- ft_printf and any equivalent YOU coded
- [signal](https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm)
- [sigemptyset](https://man7.org/linux/man-pages/man3/sigemptyset.3p.html)
- [sigaddset](https://man7.org/linux/man-pages/man3/sigaddset.3p.html)
- [sigaction](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill](https://man7.org/linux/man-pages/man2/kill.2.html)
- [getpid](https://man7.org/linux/man-pages/man2/getpid.2.html)
- malloc
- free
- [pause](https://man7.org/linux/man-pages/man2/pause.2.html)
- [sleep](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [usleep](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [exit](https://man7.org/linux/man-pages/man3/exit.3.html)

## see also
- [signal.h](https://www.tutorialspoint.com/c_standard_library/signal_h.htm)
- [sigset_t](https://www.gnu.org/software/libc/manual/html_node/Signal-Sets.html)
- [signal](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigusr1 & 2](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html)

## User Signals
we can only send SIGUSR1 & SIGUSR2 for signals to send, i thought at first we could redefine the information in the signal as it is 4 bytes of info, but that is not really how signals work, we MUST use them for binary and not worry about the value of them, only that SIGUSR1 != SIGUSR2.
```c
if (SIGUSR1)
  return (1);
else if (SIGUSR2)
  return (0);
else
 return (-1)
```
## Server side
We need the server to continuously run and wait for signals and interpret them. We need to use a while(true) loop with some `signal(int sig, void (*func)(int))` in it. The function will need to reconstruct the data passed as binary one bit at a time because we are receiving either SIGUSR1 or SIGUSR2.
`signal(SIGUSRi, &reconstruct)`

## Client side
The client will be sending a stream of bits to the server, first it will have to parse the input string to bits (1s and 0s) and send them to the server

# Questions
- how does the client get the server pid
- which is the best way to deconstruct and reconstruct a string
- how does the server know when the whole message has been received
- how do i implement UFT-8 instead of ASCII


## try also
```c
#include <stdio.h>
#include <unstd.h>
#include <sys/types.h>

int main(void)
{
  printf("%d", getpid());
}
```

```c
#include <stdio.h>
int main(void)
{
  unsigned char init = 64;
  unsigned char exit = 0;
  unsigned char temp = 0;
  int a = 7;
  printf("init: %d\n", init);
  
  while (a--)
  {
    exit += init & 1;
    exit <<= 1;
    init >>= 1;
  }
  exit += init & 1;
  printf("exit: %d\n", exit);
  a = 7;
  while (a--)
  {
    temp += exit & 1;
    temp <<= 1;
    exit >>= 1;
  }
  temp += exit & 1;
  exit = temp;
  printf("final: %d", exit);
}
```
