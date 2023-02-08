# Philosophers

[Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

### Semaphores & Mutexes

Semaphores are a synchronization mechanism used in computer science to control access to shared resources by multiple parallel processes. They were first introduced by the Dutch computer scientist Edsger W. Dijkstra in 1965.

A semaphore is an abstract data type that consists of a counter and a set of operations that can be performed on it. The two most important operations are "wait" (also known as "acquire" or "P") and "signal" (also known as "release" or "V"). The wait operation decrements the counter and blocks the process if the counter is zero, while the signal operation increments the counter and unblocks a process that is waiting for the semaphore.

Semaphores are used in a wide range of applications, including:

Resource allocation: Semaphores can be used to control access to shared resources, such as printers, file systems, and memory.

Synchronization: Semaphores can be used to coordinate the actions of multiple processes and to ensure that they execute in the correct order.

Deadlock avoidance: Semaphores can be used to enforce the ordering of resource acquisitions and releases to avoid deadlocks.

Semaphores are a powerful tool for managing concurrent access to shared resources, but they must be used carefully to avoid synchronization problems like deadlocks and starvation.

---
Mutexes (short for mutual exclusion) and semaphores are both synchronization mechanisms used to control access to shared resources by multiple parallel processes. However, there are some differences between them.

A mutex is a locking mechanism that provides mutually exclusive access to a shared resource. When a process acquires a mutex, it locks the resource, preventing other processes from accessing it. Only one process can hold the mutex at any given time. Mutexes are usually used to implement critical sections, where a shared resource is accessed and updated.

A semaphore, on the other hand, is a signaling mechanism that allows multiple processes to access a shared resource. A semaphore has an associated count value, which represents the number of processes that can access the shared resource at any given time. When a process acquires a semaphore, its count is decremented, and when it releases the semaphore, its count is incremented. If the count is zero, any processes attempting to acquire the semaphore will block until the count becomes non-zero.

So, the main difference between mutexes and semaphores is that mutexes provide mutually exclusive access to a shared resource, while semaphores provide controlled access to a shared resource. Mutexes are used to lock resources, while semaphores are used to signal between processes. Mutexes are usually binary, meaning that they have a state of either locked or unlocked, while semaphores can have a count greater than one, allowing multiple processes to access the shared resource.
