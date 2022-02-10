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

---

We need to revisit our piscine - [C00 Exercise 0](https://github.com/TeriyakisaurusRex/42Piscine/blob/main/C_00/ex00/ft_putchar.c) and take a look at the write function with our new knowledge. It makes a bit more sense now
`ssize_t write(int fd, const void *__buf, size_t count);`
we know that `ssize_t` is a signed [`size_t`](https://www.geeksforgeeks.org/size_t-data-type-c-language/), and size_t is just a big integer (*size depending on OS*). [`fd`](https://en.wikipedia.org/wiki/File_descriptor) is just 0, 1 or 2, Standard input, output and error respectively.

```
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
```
  #include <unistd.h>
  int main()
  {
    char c;
    while (read(0, &c, 1) > 0)
    {
      write(1, &c, 1);
    }
    return (0)
  }
```
```bash
$ gcc main.c && echo "Eggs" | ./a.out
```
will return `Eggs` to the command line. That is reading and writing one byte at a time. now we could do this from another file. If we make a \*.txt file and *cat* and pipe it over it should be able to read it. That will be useful for our GNL testing purposes.

Assumptions
- We are reading text files, i.e. only char values and iterating one byte at a time

Ideas
- malloc and concatonate each char into a string until we hit the *'\\n'* character
- count along the as we move until we hit the '\\n' character then move backwards the same amount of steps. Then malloc that whole string.
- give up and cry
- steal someone elses code when they are not looking
- make it work with pipe i.e. `$echo "This" | ./a.out`

# Result
Not Handed In Yet / 100
