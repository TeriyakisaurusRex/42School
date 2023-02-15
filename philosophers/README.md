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

---

Learn about
- Mutexes
- Semaphores
- Time functions
- Threads

---

**Mutex Example**

```c
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread1_func(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Thread 1 is running\n");
    usleep(100000);
    printf("Thread 1 is done\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *thread2_func(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Thread 2 is running\n");
    usleep(100000);
    printf("Thread 2 is done\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
```
In this example, two threads are created with pthread_create and run concurrently. The usleep function is used to simulate some work being done by each thread. To synchronize the execution of the threads, a mutex is used. The mutex is locked with pthread_mutex_lock before each thread starts its work, and unlocked with pthread_mutex_unlock after the work is done. This ensures that only one thread can access the critical section at a time. The pthread_join function is used to wait for each thread to finish before exiting the main function.

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
```

The pthread_create function takes the following arguments:
- thread: This argument is a pointer to a pthread_t variable, which will receive the ID of the newly created thread.
- attr: This argument is a pointer to a pthread_attr_t structure, which specifies optional attributes for the new thread. This argument can be set to NULL to use the default thread attributes.
- start_routine: This argument is a pointer to a function that will be executed by the new thread. The function must take a single void * argument and return void *.
- arg: This argument is a pointer to the data that will be passed as an argument to the start_routine function.

---

## Exercises to Reinforce Learning

- Write a program that uses two threads to print out numbers 1 to 100 in order. One thread should print out the odd numbers, and the other thread should print out the even numbers. Use a mutex to synchronize the threads.
- Write a program that uses multiple threads to sort an array of integers using merge sort. Each thread should sort a portion of the array, and then the main thread should merge the sorted portions together. Use mutexes to synchronize the threads.
- Write a program that uses multiple threads to compute the sum of a large array of integers. Each thread should compute the sum of a portion of the array, and then the main thread should combine the partial sums. Use mutexes to synchronize the threads.
- Write a program that uses two threads to simulate a producer-consumer problem. One thread should generate random numbers and put them in a buffer, while the other thread should remove the numbers from the buffer and print them out. Use a mutex and a condition variable to synchronize the threads.
- Write a program that uses multiple threads to search for a target value in a large array of integers. Each thread should search a portion of the array, and then the main thread should combine the results. Use mutexes to synchronize the threads.

---


some simple example to learn from 
```c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5

pthread_mutex_t forks[NUM_FORKS];

void *philosopher(void *id) {
  int philosopher_id = *((int *)id);
  int left_fork = philosopher_id;
  int right_fork = (philosopher_id + 1) % NUM_FORKS;

  while (1) {
    printf("Philosopher %d is thinking\n", philosopher_id);
    sleep(1);

    printf("Philosopher %d is trying to grab left fork %d\n", philosopher_id,
           left_fork);
    pthread_mutex_lock(&forks[left_fork]);
    printf("Philosopher %d grabbed left fork %d\n", philosopher_id, left_fork);

    printf("Philosopher %d is trying to grab right fork %d\n", philosopher_id,
           right_fork);
    pthread_mutex_lock(&forks[right_fork]);
    printf("Philosopher %d grabbed right fork %d\n", philosopher_id,
           right_fork);

    printf("Philosopher %d is eating\n", philosopher_id);
    sleep(1);

    printf("Philosopher %d is releasing left fork %d\n", philosopher_id,
           left_fork);
    pthread_mutex_unlock(&forks[left_fork]);

    printf("Philosopher %d is releasing right fork %d\n", philosopher_id,
           right_fork);
    pthread_mutex_unlock(&forks[right_fork]);
  }
}

int main() {
  pthread_t philosophers[NUM_PHILOSOPHERS];
  int philosopher_ids[NUM_PHILOSOPHERS];

  for (int i = 0; i < NUM_FORKS; i++) {
    pthread_mutex_init(&forks[i], NULL);
  }

  for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
    philosopher_ids[i] = i;
    pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
  }

  for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }

  return 0;
}

```
