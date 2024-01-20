
1. Understanding the Requirements:

For Minitalk, the requirements are :-
. A client sends a string to a server using UNIX signals.
. The server receives the string and prints it.
. The communication should use only SIGUSR1 and SIGUSR2.

2. Breaking Down the Problem

Lets break down these requirements into smaller parts:

Client Side:
. Needs to send a string, character by character, using signals.
. Each character must be broken down into bits and sent individually.

Server Side:
. Needs to receive signals and reconstruct them into characters.
. Must handle signals and determine whether they represent a 1 or a 0 bit

3. Planning the Implementation

Deciding how to implement each part. For example:

Client Side:

. Convert each character to its binary representation.
. Use kill to send SIGUSR1 (for bit 1) or SIGUSR2 (for bit 0) to the server.

Server Side:

. Use a signal handler to catch SIGUSR1 and SIGUSR2.
. Reconstruct each bit into a full byte (character).

4. Writing the Code

Start coding each part, focusing on one small task at a time. For instance:

Client Side:

. Write a function to iterate over each character of the string.
. For each character, use bitwise operations to send each bit as a signal.

Server Side:

. Write a signal handler that reconstructs characters from bits.
. Print the character once all bits are received.

5. Testing and Debugging
Test each part as you develop it. Ensure that the client correctly sends signals and that the server correctly interprets and reconstructs them.

6. Refining the Code
After getting a basic version working, refine your code:

Handle edge cases (e.g., what if the string is empty?).
Improve efficiency and readability.
Add comments and documentation.

- [List of signals](https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf)
