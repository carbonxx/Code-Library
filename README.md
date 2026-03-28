# Code-Library

## Table of Contents

- [Introduction](#introduction)
- [Electronic Computing](#electronic-computing)
- [Boolean Logic](#boolean-logic)
- [Number Systems](#number-systems)
- [Central Processing Unit(CPU)](#central-processing-unitcpu)
- [Registers, Cache and RAM](#registers-cache-and-ram)
- [Instruction and Program](#instruction-and-program)
- [Programming Language](#programming-language)
- [Data Types](#data-types)
- [Statements and Functions](#statements-and-functions)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Alan Turing](#alan-turing)
- [Software Engineering](#software-engineering)
- [Integrated Circuits](#integrated-circuits)
- [Object Oriented Programming](#object-oriented-programming)
- [API (Application Programming Interface)](#api-application-programming-interface)
- [Operating Systems](#operating-systems)
- [Memory and Storage](#memory-and-storage)
- [File System](#file-system)
- [Cloud Computing](#cloud-computing)
- [Version Control](#version-control)
- [Databases](#databases)

## Introduction

Computer science is the study of computers and computing as well as their theoretical and practical applications. Computer science applies the principles of mathematics, engineering, and logic to a plethora of functions, including algorithm formulation, software and hardware development, and artificial intelligence.

## [Electronic Computing](#electronic-computing)

A device that computes, especially a programmable electronic machine that performs high-speed mathematical or logical operations or that assembles, stores, correlates, or otherwise processes information.

## [Boolean Logic](Boolean%20Logic/Boolean_Logic.md)

Boolean logic is a branch of mathematics that deals with the values of truth and falsehood. It is a system of logic that uses only two values, 0 and 1, to represent false and true, respectively. It is also known as Boolean algebra, named after George Boole, who first described it in 1854.

### Common Boolean Operators

| Operator | Name |               Description               |
| :------: | :--: | :-------------------------------------: |
|    !     | NOT  |    Negates the value of the operand.    |
|    &&    | AND  | Returns true if both operands are true. |
|   \|\|   |  OR  | Returns true if either operand is true. |

### Nice to know Boolean Operators

| Operator |      Name       |                                           Description                                            |
| :------: | :-------------: | :----------------------------------------------------------------------------------------------: |
|    ()    |   Parentheses   | Allows you to group together keywords and control the order in which the terms will be searched. |
|    “”    | Quotation marks |                             Provides results with the exact phrase.                              |
|    \*    |    Asterisk     |                    Provides results that contain a variation of the keyword.                     |
|    ⊕     |       XOR       |                            Returns true if the operand are diffrent.                             |
|    ⊽     |       NOR       |                            Returns true if neither operand are true.                             |
|    ⊼     |      NAND       |               Returns false value only if both values of its two inputs are true.                |

## [Number Systems](Number%20System/readme.md#number-systems)

Number systems are mathematical systems for expressing numbers. A number system consists of a set of symbols that are used to represent numbers and a set of rules for manipulating those symbols. The symbols used in a number system are called numerals.

### [Types of Number Systems](Number%20System/readme.md#types-of-number-systems)

- [Positional Numeral System](Number%20System/readme.md#positional-numeral-system)
- [Sign-value Notation System](Number%20System/readme.md#sign-value-notation-system)

### [Common Positional Number Systems](Number%20System/readme.md#common-positional-number-systems)

- [Binary](Number%20System/readme.md#binary)
- [Octal](Number%20System/readme.md#octal)
- [Decimal](Number%20System/readme.md#decimal)
- [Hexadecimal](Number%20System/readme.md#hexadecimal)

### Importance Of Binary

Binary is a base-2 number system invented by Gottfried Leibniz that's made up of only two numbers or digits: 0 (zero) and 1 (one). This numbering system is the basis for all binary code, which is used to write digital data such as the computer processor instructions used every day. The 0s and 1s in binary represent OFF or ON, respectively. In a transistor, a "0" represents no flow of electricity, and a "1" represents electricity is allowed to flow. In this way, numbers are represented physically inside the computing device, permitting calculations.

Binary is still the primary language for computers and is used with electronics and computer hardware for the following reasons.

- It is a simple and elegant design.
- Binary's 0 and 1 method is quick to detect an electrical signal's off (false) or on (true) state.
- Having only two states placed far apart in an electrical signal makes it less susceptible to electrical interference.
- The positive and negative poles of magnetic media are quickly translated to binary.
- Binary is the most efficient way to control logic circuits.

## [Central Processing Unit(CPU)](CPU/readme.md#central-processing-unitcpu)

A central processing unit (CPU) is an important part of every computer. The CPU sends signals to control the other parts of the computer, almost like how a brain controls a body.
The CPU is an electronic machine that works on a list of computer things to do, called instructions. It reads the list of instructions and runs (executes) each one in order. A list of instructions that a CPU can run is a computer program. A CPU can process more than one instruction at a time on sections called Cores. A CPU with four cores may process four programs at once.
The CPU itself is made of three main components. They are:

1. [Memory or storage Unit](CPU/readme.md#memory-or-storage-unit)
2. [Control Unit](CPU/readme.md#control-unit)
3. [Arithmetic and Logic unit (ALU)](CPU/readme.md#arithmetic-and-logic-unit-alu)

## [Registers, Cache and RAM](/Registers%20Cache%20and%20RAM)

### [Register](/Registers%20Cache%20and%20RAM/readme.md#register)

Registers are small amounts of high-speed memory contained within the CPU. Registers are basically a collection of flip-flops (a circuit used to store 1 bit of memory). They are used by the processor to store small amounts of data that are needed during processing. A CPU may have several sets of registers that are called Cores. Register also helps in arithmetic and logic operations.Larger amounts of data may be stored in Cache (pronounced like cash). This is a very fast memory that is located on the same integrated circuit as the registers. It is used for data frequently needed as the program runs. Still larger amounts of data may be stored in RAM. These are integrated circuits not part of the CPU. RAM stands for random-access memory. It is essentially data and instructions that have been moved from disk storage and held until the processor needs it.

### [Cache](/Registers%20Cache%20and%20RAM/readme.md#cache)

A cache -- pronounced CASH -- is hardware or software that is used to store something, usually data, temporarily in a computing environment.

### [RAM](/Registers%20Cache%20and%20RAM/readme.md#ram)

RAM (Random Access Memory) is the hardware in a computing device where the operating system (OS), application programs and data in current use are kept so they can be quickly reached by the device's processor. RAM is the main memory in a computer. It is much faster to read from and write to than other kinds of storage, such as a hard disk drive (HDD), solid-state drive (SSD) or optical drive.

## [Instruction and Program](/Instruction%20and%20Program/readme.md#instruction-and-program)

In computer science, an instruction is a single operation of a processor defined by the processor instruction set. And a computer program is a list of instructions that tell a computer what to do. Everything a computer does is done by using a computer program. Programs stored in the memory of a computer ("internal programming") let the computer do one thing after another, even with breaks in between.

## [Programming Language](/Programming%20Language/readme.md#programming-language)

A programming language is any set of rules that convert strings, or graphical program elements in the case of visual programming languages, to various kinds of machine code output.[citation needed] Programming languages are one kind of computer language and are used in computer programming to implement algorithms.

Programming languages are mainly of two types :

1. High-level language uses a syntax similar to the English language. The source code is converted into machine-understandable machine code using a compiler or an interpreter. Java, Python are some examples of high-level programming languages.
2. Low-level programming languages work more closely to the hardware and have more control over it. They directly interact with the hardware. Two common examples of low-level languages are machine language and assembly language.

Some Languages Include:

- Python
- Java
- C++
- C
- C#

### Scripting Languages

A scripting language is a computer language that doesn't have to be compiled. One advantage of Scripting languages is that the code can be quickly edited and can be re-executed. They can be used on the server side of web applications and the client side of web applications.

Some Scripting Languages include:

- Javascript
- PHP
- Python
- Perl

## [Data Types](Data%20Types/readme.md#data-types)

A data type, in programming, is a classification that specifies which type of value a variable has and what type of mathematical, relational or logical operations can be applied to it without causing an error.

### [Primitive Data Types](Data%20Types/readme.md#primitive-data-types)

Primitive data types are the most basic data types in a programming language. They are the building blocks of more complex data types. Primitive data types are predefined by the programming language and are named by a reserved keyword.

### [Common Primitive Data Types](Data%20Types/readme.md#common-primitive-data-types)

- [Integer](Data%20Types/readme.md#integer)
- [Float](Data%20Types/readme.md#float)
- [Boolean](Data%20Types/readme.md#boolean)
- [Character](Data%20Types/readme.md#character)
- [String](Data%20Types/readme.md#string)

### [Non-Primitive Data Types](Data%20Types/readme.md#non-primitive-data-types)

Non-primitive data types are also known as reference data types. They are created by the programmer and are not defined by the programming language. Non-primitive data types are also called composite data types because they are composed of other types.

### [Common Non-Primitive Data Types](Data%20Types/readme.md#common-non-primitive-data-types)

- [Array](Data%20Types/readme.md#array)
- [Struct](Data%20Types/readme.md#struct)
- [Union](Data%20Types/readme.md#union)
- [Pointer](Data%20Types/readme.md#pointer)
- [Function](Data%20Types/readme.md#function)
- [Class](Data%20Types/readme.md#class)

## [Statements and Functions](Statements%20and%20Functions/Statements_and_Functions.md)

In computer programming, a statement is a syntactic unit of an imperative programming language that expresses some action to be carried out. A program written in such a language is formed by a sequence of one or more statements. A statement may have internal components (e.g., expressions).
There are two main types of statements in any programming language that is necessary to build the logic of a code.

1. [Conditional-Statements](Statements%20and%20Functions/readme.md#conditional-statements)

There are two types of conditional statements mainly:

- if-else
- switch case

2. [Loops](Statements%20and%20Functions/readme.md#loops)

There are three types of conditional statements mainly:

- for loop
- while loop
- do - while loop (a variation of while loop)

---

A function is a block of statements that performs a specific task. Functions accept data, process it, and return a result. Functions are written primarily to support the concept of reusability. Once a function is written, it can be called easily, without having to write the same code again and again.

Different functional languages use different syntax to write a function.

Read more about functions [here](Statements%20and%20Functions/readme.md#functions)

## [Object Oriented Programming](Object%20Oriented%20Programming/Object_Oriented_Programming.md)

Object Oriented Programming is a fundamental programming paradigm which is based on the concepts of objects and data.

It is the standard way of code that every programmer has to abide by for better readability and reusability of the code.

### \* There are four basic concepts of Object Oriented Programming:

- Abstraction
- Encapsulation
- Inheritance
- Polymorphism

Read more about these concepts of OOP [here](Object%20Oriented%20Programming/Object_Oriented_Programming.md)

## [API (Application Programming Interface)](API/API.md)

APIs (Application Programming Interfaces) allow different software systems to communicate with each other. They are commonly used to connect frontend applications with backend servers.

Read more about API basics [here](API/API.md)

## [Data Structures](Data%20Structures/Data_Structures.md)

In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data.

### Types of Data Structures

- [Array](Data%20Structures/readme.md#array)
- [Linked List](Data%20Structures/readme.md#linkedlist)
- [Stack](Data%20Structures/readme.md#stack)
- [Queue](Data%20Structures/readme.md#queue)
- [Hash Table](Data%20Structures/readme.md#hashtable)
- [Heap](Data%20Structures/readme.md#heap)
- [Tree](Data%20Structures/readme.md#tree)
- [Graph](Data%20Structures/readme.md#graph)

## [Algorithms](Algorithms/Algorithms.md)

Algorithms are the sets of steps necessary to complete computation - they are at the heart of what our devices do. And this isn’t a new concept. Since the development of math itself algorithms have been needed to help us complete tasks more efficiently, but today we’re going to take a look at a couple of modern computing problems like sorting and graph search, and show how we’ve made them more efficient so you can more easily find cheap airfare or map directions to Winterfell... or like a restaurant or something.

### [Time Complexity](Algorithms/Time%20Complexity/Time_Complexity.md)

The time complexity of an algorithm estimates how much time the algorithm will use for some input. The idea is to represent efficiency as a function whose parameter is the size of the input. By calculating the time complexity, we can find out whether the algorithm is fast enough without implementing it.

### [Sorting](Algorithms/Sorting/Sorting.md)

Sorting is the process of arranging a list of items in a particular order. For example, if you had a list of names, you might want to sort them alphabetically. Or if you had a list of numbers, you might want to put them in order from smallest to largest. Sorting is a common task, and it’s one that we can do in many different ways.

### [Searching](Algorithms/Searching/Searching.md)

Searching is algorithm for finding a certain target element inside a container. Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is stored.

### [Graph Search](Algorithms/Graph/Graph.md)

Graph search is the process of searching through a graph to find a particular node. A graph is a data structure that consists of a finite (and possibly mutable) set of vertices or nodes or points, together with a set of unordered pairs of these vertices for an undirected graph or a set of ordered pairs for a directed graph. These pairs are known as edges, arcs, or lines for an undirected graph and as arrows, directed edges, directed arcs, or directed lines for a directed graph. The vertices may be part of the graph structure or may be external entities represented by integer indices or references. Graphs are one of the most useful data structures for many real-world applications. Graphs are used to model pairwise relations between objects. For example, the airline route network is a graph in which the cities are the vertices and the flight routes are the edges. Graphs are also used to represent networks. The Internet can be modelled as a graph in which the computers are the vertices and the links between computers are the edges. Graphs are also used on social networks like LinkedIn and Facebook. Graphs are used to represent many real-world applications: computer networks, circuit design, and aeronautical scheduling to name just a few.

### [Dynamic Programming](Algorithms/Dynamic%20Programming/Dynamic_Programming.md)

Dynamic programming is both a mathematical optimization method and a computer programming method. The method was developed by Richard Bellman in the 1950s and has found applications in numerous fields, from aerospace engineering to economics. In both contexts, it refers to simplifying a complicated problem by breaking it down into simpler sub-problems in a recursive manner. While some decision problems cannot be taken apart this way, decisions that span several points in time do often break apart recursively. Likewise, in computer science, if a problem can be solved optimally by breaking it into sub-problems and then recursively finding the optimal solutions to the sub-problems, then it is said to have an optimal substructure. Dynamic programming is one way to solve problems with these properties. The process of breaking a complicated problem down into simpler sub-problems is called "divide and conquer".

### [Greedy Algorithms](Algorithms/Greedy%20Algorithms/Greedy_Algorithms.md)

Greedy algorithms are a simple, intuitive class of algorithms that can be used to find the optimal solution to some optimization problems. They are called greedy because at each step they make the choice that seems best at that moment. This means that greedy algorithms do not guarantee to return the globally optimal solution, but instead make locally optimal choices in the hope of finding a global optimum. Greedy algorithms are used for optimization problems. An optimization problem can be solved using Greedy if the problem has the following property: at every step, we can make a choice that looks best at the moment, and we get the optimal solution to the complete problem.

### [Backtracking](Algorithms/Backtracking/Backtracking.md)

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point in time (by time, here, is referred to the time elapsed till reaching any level of the search tree).

### [Branch and Bound](Algorithms/Branch%20and%20Bound/Branch_and_Bound.md)

Branch and bound is a general technique for solving combinatorial optimization problems. It is a systematic enumeration technique that reduces the number of candidate solutions by using the problem's structure to eliminate candidate solutions that cannot possibly be optimal.

### [Time Complexity and Space Complexity of Different Searching and Sorting Algorithms](Algorithms/Time%20and%20Space%20Complexity/Time_and_Space_Complexity.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Alan Turing](Alan%20Turing/Alan_Turing.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Software Engineering](Software%20Engineering/Software_Engineering.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Integrated Circuits](Integrated%20Circuits/Integrated_Circuits.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Operating Systems](Operating%20Systems/Operating_Systems.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Memory and Storage](Memory%20and%20Storage/Memory_and_Storage.md)

Content moved to its dedicated directory. Click the link above to read more.

## [File System](File%20System/File_System.md)

Content moved to its dedicated directory. Click the link above to read more.

## [Cloud Computing](Cloud%20Computing/Cloud_Computing.md)

Cloud computing is the ability to access information and applications over the Internet. Cloud computing allows users to access applications and data from any location, as long as they have an Internet connection.

Cloud computing is a type of Internet-based computing that provides shared computer processing resources and data to computers and other devices on demand.

It is a model for enabling ubiquitous, convenient, on-demand network access to a shared pool of configurable computing resources (e.g., networks, servers, storage, applications, and services) that can be rapidly provisioned and released with minimal management effort or service provider interaction.

### Types of Cloud Computing Services

- [Infrastructure as a Service (IaaS)](Cloud%20Computing/Cloud_Computing.md#infrastructure-as-a-service-iaas)
- [Platform as a Service (PaaS)](Cloud%20Computing/Cloud_Computing.md#platform-as-a-service-paas)
- [Software as a Service (SaaS)](Cloud%20Computing/Cloud_Computing.md#software-as-a-service-saas)


## [Version Control](Version%20Control/Version_Control.md)

Version control systems like Git help software teams manage changes to source code over time. Click the link to explore more.

## [Databases](Databases/Databases.md)

A database is an organized collection of data. Learn about SQL vs NoSQL by clicking the link above.

---

## Contributing

We welcome contributions to the Code Library! From fixing typos, to adding deep dives into brand new computer science topics, everything is appreciated.

Please see our [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines on how to format your entries and issue Pull Requests. Let's build the best logic and code insights document together!

Please note that this project is released with a [Contributor Code of Conduct](CODE_OF_CONDUCT.md). By participating in this project you agree to abide by its terms.
