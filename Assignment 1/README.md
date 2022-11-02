# Assignment 1
By Noah Struck

## Enviroment
I have a dual boot of Kali Linux 2022.3 on my laptop. I wrote this code in C using Visual Studio code and compiled it using the Generic C Compiler (gcc).

## Execution
Before running the program, you will need to compile it. You can use the compile script that I have provided. Simply run `./compile.sh` in the terminal. 
If this does not work, you will need to give the script permissions to execute using `chmod +x compile.sh`. Then you continue with running the compilation script.

Once you compile it, you should have two output files. There should be a program named "consumer" and "producer" in the folder you ran the script in. You can now 
execute the program using the command `./producer & ./consumer &`.

## Output
```code
Producer sent item on 0: a
Consumer recieved item on 0: a
Producer sent item on 1: b
Consumer recieved item on 1: b
Producer sent item on 0: c
Consumer recieved item on 0: c
Producer sent item on 1: d
Consumer recieved item on 1: d
Producer sent item on 0: e
Consumer recieved item on 0: e
Producer sent item on 1: f
Consumer recieved item on 1: f
Producer sent item on 0: g
Consumer recieved item on 0: g
Producer sent item on 1: h
Consumer recieved item on 1: h
Producer sent item on 0: i
Consumer recieved item on 0: i
Producer sent item on 1: j
Consumer recieved item on 1: j

[1]-  Done                    ./producer
[2]+  Done                    ./consumer
```

## Explaination
Since the producer is executed first, it creates the shared memory object and then sets up the semaphores on that shared memory object. It then enters a while loop and waits for the wait semaphore to be activated by the consumer. Once the consumer posts to the wait semaphore, we know that we can produce some data for it to consume. As it produces and consumes data, we go back and forth on the semaphores in the while loop, trading off and passing data back and forth between the buffer in the shared memory space. The semaphores act as locks and protect the critical section from being accessed by two processes at once.

## Problems
The largest problem I faced with this assignment was actually understanding how the semaphores work in C and how dynamic memory works. I have never used a language like C, though I have used a very similar language, C++. It was a struggle at first to understand the syntax and how the semaphores work but once I got the hang of it, it really started to come together.

## Lessons
The largest lesson I learned when doing this lab was actually using C. I have never used it but it was a blast to use and I will definitely be doing the other labs in C instead of something like C++.