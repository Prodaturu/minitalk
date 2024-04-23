# 42cursus - minitalk

![](https://github.com/Prodaturu/minitalk/workflows/norminette/badge.svg)
[](https://github.com/Prodaturu/minitalk/workflows/build/badge.svg)

## Project Information

### About

This project's goal is to use *UNIX signals* to develop a tiny data exchange program.

### Mandatory

- `server` & `client` executables
- `client` must communicate a string that is passed as a parameter to `server` *(referenced by server's process ID)* upon which the server then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**
- Follow the `Norminette` coding style

### Bonus

- Support Unicode characters

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

### Acknowledgement

Special thanks to Arvind Dhaka (intra 42: adhaka) and Akram Guediri (intra 42: aguediri) for helping me with the concepts of signals in C.
