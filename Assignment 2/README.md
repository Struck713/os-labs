# Assignment 2
By Noah Struck

## Enviroment
I have a dual boot of Kali Linux 2022.3 on my laptop. I wrote this code in C++ using Visual Studio Code and compiled it using the Clang C++ Compiler (clang++).

## Execution
Before running the program, you will need to compile it. Simply run `clang++ bankers.cpp -o bankers` in the terminal. 
Once you compile it, you should have a singular output file `bankers` which you can execute `./bankers`

## Output
```code
Allocated: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
Max: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
Available: 3 3 2
The system is in safe state. Safe sequence is: 1 3 4 0 2
```

## Data Table
This is the data table that was provided to us by Dr. Guan:
| Process | Allocation | Max | Available |
| --- | --- | --- | --- |
| P0 | 0 1 0 | 7 5 3 | 3 3 2 |
| P1 | 2 0 0 | 3 2 2 | |
| P2 | 3 0 2 | 9 0 2 | |
| P3 | 2 1 1 | 2 2 2 | |
| P4 | 0 0 2 | 4 3 3 | |

In my table.txt, I converted the table to a format using spaces as seperators.
The table.txt file is shown below:
```
0 1 0 7 5 3 3 3 2
2 0 0 3 2 2
3 0 2 9 0 2
2 1 1 2 2 2
0 0 2 4 3 3
```

## Explaination
The project calls for input from a file. I chose to read it using for loops and the extraction operator provided by C++. This program has a single function, aside from the main function. The only function, checkSafe, is an implementation of the Banke's Algorithm in C++. It first uses a loop to take the values of the max and allocation tables and generate a need table. Once we have this need table, we have a finish table to make sure that we know when we have finished with a process. We create a copy of the avaliable resources table and then we enter a while loop. Inside of the while loop, we check if the process is finished, then we make sure that all of the resources of the current process are less than the work required. If they are less than the work and we hit the end of the resource counter, we know that we have a sequence that is safe to execute all of these processes. If not, we don't have a safe sequence, we exit the loop and declare it that. 

## Problems and Lessons Learned
I didn't really have a problem with writing any of the code for this assignment. There are lots of great resources on the Internet that can help you implement a working version of the Banker's algorithm in C++. The hardest challenge that I faced was building a way to input an ability to read data from a table stored in a text file. That took me a majority of the time when I was building the project. I learned a large lesson with for-loops and while-loops in C++ when completing this project. I had a lot of my variables flipped in 2D arrays which caused me a lot of problems down the line. Luckily, I eventually fixed these problems and developed a working program. I just spent a lot more time debugging this piece of software than I should've.