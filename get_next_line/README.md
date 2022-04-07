# Get Next Line
 *Reading a line from a fd is way too tedious*

### Summary:
*This project is about programming a function that returns a line read from a file descriptor*

|| **FILES** | |
|:---------------:|:---------------------:|:---------------:|
| get_next_line.c | get_next_line_utils.c | get_next_line.h |
|                 | **BONUS**             |                 |
| get_next_line_bonus.c | get_next_line_utils_bonus.c | get_next_line_bonus.h |


>Documents & Information to learn
> ### Read()
>>[Linux Read() manual](https://man7.org/linux/man-pages/man2/read.2.html)
>>
>>[fread & read](https://stackoverflow.com/questions/584142/what-is-the-difference-between-read-and-fread)
> ### Stream
>> [What is a Stream](https://stackoverflow.com/questions/38652953/what-does-stream-mean-in-c)
> ### Static variables
>> [Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/)
>> 
>> [What does static mean in C?](https://stackoverflow.com/questions/572547/what-does-static-mean-in-c)
> ### Buffer
>> [What is a buffer?](https://www.educative.io/edpresso/what-is-a-buffer-in-c)
>>
>> [What is a buffer size](https://www.quora.com/Why-is-buffer-size-set-in-a-C-program#:~:text=Using%20C%20code%2C%20user%20can,in%20whatever%20manner%20you%20want.)
> ### stdin - Standard Input
>> [streams](https://en.wikipedia.org/wiki/Standard_streams)
>> 
>> [stdin](https://man7.org/linux/man-pages/man3/stdin.3.html)
> ### stdout - Stardard Output
>> [stdout](http://www.linfo.org/standard_output.html)
> ### FILE variable
>> [What is data type of FILE](https://www.geeksforgeeks.org/data-type-file-c/)
>> 
>> [FILE I/O](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)
> ### -D gcc flag
>> [gcc preprocessor options](https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html)
---

We need to revisit our piscine - [C00 Exercise 0](https://github.com/TeriyakisaurusRex/42Piscine/blob/main/C_00/ex00/ft_putchar.c) and take a look at the write function with our new knowledge. It makes a bit more sense now
`ssize_t write(int fd, const void *__buf, size_t count);`
we know that `ssize_t` is a signed [`size_t`](https://www.geeksforgeeks.org/size_t-data-type-c-language/), and size_t is just a big integer (*size depending on OS*). [`fd`](https://en.wikipedia.org/wiki/File_descriptor) is just 0, 1 or 2, Standard input, output and error respectively.

```c
  #include <unistd.h>
  int main()
  {
    int i = -1;
    char c;
    while (i++ < 10)
    {
      str = i + '0';
      write(i, &str, 1);
    }
  }
```
testing the code above allows us to see that we can only write to console when *fd* = 0, 1 or 2. 
the const void *\*\_\_buf* was confusing at first but we know what a [void pointer](https://www.geeksforgeeks.org/void-pointer-c-cpp/) is now, it's an *anything* pointer and **const** just means we can't mess around and change its value. count is just the number of bytes i.e. `char` = 1byte.
Knowing this helps to understand what we have to do for the project, Instead of writing to *output* we must read from *input* and then store the read data into a string and return it.
`ssize_t read(int fd, void *buf, size_t count);`
using read will return a `ssize_t` which is the number of bytes read, this can be smaller than the *count* is some circumstances i.e. end of file (*very useful*). If there is an error we return -1.


Now we should be able to get a simple tester running to help us understand how read works. `read` wants a *file descripter* and standard input is 0 so you do the math on that one. The second parameter is a pointer, we want this to be a pointer to a string (or maybe a pointer to a char with *&c*). Next is the size that we a looking with, we can make that 1 byte for our tester but it can be bigger if we want.
```c
  #include <unistd.h>
  int main()
  {
    char c;
    while (read(0, &c, 1) > 0)
    {
      write(1, &c, 1);
    }
    return (0);
  }
```
```bash
$ gcc main.c && echo "Eggs" | ./a.out
```
will return `Eggs` to the command line. That is reading and writing one byte at a time. now we could do this from another file. If we make a \*.txt file and *cat* and pipe it over it should be able to read it. That will be useful for our GNL testing purposes.

Attempting to do the same code as above with a string doesn't work. Turns out we have to malloc it. We will also compile with a macro for the BUFFER_SIZE
```bash
$ gcc main.c -D BUFFER_SIZE=6 && echo "Eggs" | ./a.out
```
```c
  #include <unistd.h>
  #include <stdlib.h>
  int main()
  {
    char *s;
    s = malloc(BUFFER_SIZE);
    while (read(0, s, BUFFER_SIZE) > 0)
      {
        write(1, s, BUFFER_SIZE);
      }
    return (0);
  }
```
now that we have that working we should try to copy the buffer into a string to store it properly and then pass that back or print it out.
```c
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdio.h>
  
  char *get_next_line(int fd)
  {
    char *rtn;
    char *buf_string;
    
    if (read(fd, buf_string, BUFFER_SIZE) >= BUFFER_SIZE)
    {
      rtn = strndup(buf_string, BUFFER_SIZE);
    }
    return (rtn);
  }
  
  int main()
  {
    printf("%s", get_next_line(0));
    return (0);
  }
```
Getting too many errors tring to pipe echo so this is a good point to try to get our program to read from a file. We are going to have to use the `open` function.
`open` takes a pathname as a string i.e. `open("myfile.txt", ...)` as its first parameter and it takes flags as its other parameter, we will use `O_RDONLY` *(read-only)* for our purposes. `open` returns a file descripter *(int)* that we will use for `read`, we also have to remember that open is part of the `#include <fcntl.h>` library.
lets make a file called *test.txt* and put some data in it that we can test with.
```
File
Second Line
Third and final Line
```
now we can change our code to open and read from this file
```c
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdio.h>
  #include <fcntl.h>
  
  char *get_next_line(int fd)
  {
    char *rtn;
    char *buf_string;
    
    if (read(fd, buf_string, BUFFER_SIZE) >= BUFFER_SIZE)
    {
      rtn = strndup(buf_string, BUFFER_SIZE);
    }
    return (rtn);
  }
  
  int main()
  {
    int fd = open("test.txt", O_RDONLY); //added this line
    printf("%s", get_next_line(fd)); //and changed the parameter to take our new file descripter
    return (0);
  }
```

<img width="616" alt="image" src="https://user-images.githubusercontent.com/94874173/155053154-eeeefda3-9438-42fd-8904-decaec31e838.png">
First line is buffer moving across 10 bytes at a time, second line is what we need to return. Only read in one direction and we won't be able to go backwards, if we mess this up we will lose a bit of data in the second string. So what we can do is store that data of the partial second line in a *static variable* . Then we can use that next time gnl is called. 

---

**Testers**
- [Tripouille](https://github.com/Tripouille/gnlTester.git)
- [Aidan's Tester](https://github.com/Abaker-Hype/42-Cursus-Tester.git)

**Assumptions**
- We are reading text files, i.e. only char values and iterating one byte at a time

**Ideas**
- malloc and concatonate each char into a string until we hit the *'\\n'* character ***~~slow~~***
- count along the as we move until we hit the '\n' character then move backwards the same amount of steps. Then malloc that whole string. ***~~doesn't work~~***
- give up and cry
- steal someone elses code when they are not looking ***done***
- make it work with pipe i.e. `$echo "This" | ./a.out` ***done***
- make it work with and actual file ***done***

# Result
101 / 100
<img width="1839" alt="image" src="https://user-images.githubusercontent.com/94874173/162115891-6881a7a5-546b-4860-8876-01cc12280161.png">

