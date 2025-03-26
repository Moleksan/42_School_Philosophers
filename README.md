# 🏛️ Dining Philosophers

![Your Image Here]([[image_url](https://github.com/Moleksan/42_School_Philosophers/blob/main/_29f14337-1c4f-436e-823f-d63072f4cd9b%20(1).jpeg)](https://github.com/Moleksan/42_School_Philosophers/blob/main/Phils.jpeg?raw=true))

## 📖 Introduction  
You are here to explore one of the classic philosophical (and computer science) questions: **why philosophers, why forks, and what on earth is going on with spaghetti?** Don’t worry, get comfortable — I’ll explain everything.  

## 🔍 About the Problem  
The **"Dining Philosophers"** problem was introduced by **Edsger Dijkstra** in 1965 as an example of **the problem of concurrent access to shared resources**. Back then, it was related to **tape drives** (data storage devices using magnetic tape), but later **Tony Hoare** adapted it into a more understandable form: **a group of philosophers, a bowl of spaghetti, and a limited number of forks**.  

Philosophers sit around a circular table, thinking, eating, and sleeping. However, to eat, each philosopher needs **two forks** — but there are fewer forks than philosophers.  
The challenge is to **coordinate synchronization**, ensuring that no philosopher starves while learning how to manage **multithreading, mutexes, and resource sharing**.  

## 🤔 How Does It Work?  
The program simulates a situation where **multiple threads compete for limited resources**. A thread performs work (eating), then rests (thinking/sleeping), and later requests resources again.  

### Key Points:  
- Each philosopher has **two hands**, but **forks are limited**.  
- If synchronization is not handled correctly, a **deadlock** may occur — where no one can eat.  
- **The goal** is to distribute resources fairly while avoiding conflicts.  

## ⚙️ Threads vs. Processes  
A **process** is an executing program with its own memory and resources allocated by the operating system.  
A **thread** is a **part of a process** that performs a specific task.  

### Simply Put:  
- A **process** is a container in which a program runs.  
- A **thread** is an execution unit within a process that can run **in parallel** with other threads.  
- Each process has its own **execution environment**, including memory, system privileges, an identifier, and resources.  

## 🎯 Conclusion  
This problem is not just about philosophers and forks—it’s about **managing resources in a multithreaded environment**. Understanding it will help you grasp **threads, synchronization, and concurrent programming challenges**.  

Ready to dive in? Let’s get started! 🚀
