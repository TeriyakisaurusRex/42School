# ft_printf
*Because ft_putnbr() and ft_putstr() aren't enough*

Summary:
*The goal of this project is pretty straightforward. You will recode printf(). you will mainly learn about using ta variable number of arguments.*

|Files|
|-----|
|Makefile|
|Library.h|
|Libft.h|
|\*.c|

>Documents & Information to learn
> ### Variadic Functions
>> [Variadic funcitons in c](https://www.geeksforgeeks.org/variadic-functions-in-c/)
> ### va_start
>>[]()
> ### va_arg
>>[]()
> ### va_copy
>> []()
> ### va_end
>>[]()
> ### fprintf, printf, sprintf
>> [fprintf fam](https://www.ibm.com/docs/en/ztpf/2019?topic=apis-fprintf-printf-sprintf-format-write-data)
> ### flags
>> [tutorialspoint](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm)
>> 
>> [cplusplus](https://www.cplusplus.com/reference/cstdio/printf/)
>> 
>> [polytechnique](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)

## Requirements Checklist
- Don't implement the buffer management of the original **printf**
- Your function has to handle the following conversions: **cspdiuxX%**
- Your function will be compared against the original **printf**
- You must use the ar to create your library. Using the __libtool__ command is forbidden
- Your libftprintf.a has to be created at the root of your repository

| **Implementations Checklist** | **Done** |
|:-----------------------|:------:|
|`%c` Prints a single character | NYI |
|`%s` Prints a string | NYI |
|`%p` the *void* \* pointer argument has to be printed in hexadecimal format | NYI |
|`%d` Prints a decimal (base 10) number | NYI | 
|`%i` Prints an integer in base 10 | NYI |
|`%u` Prints an unsigned decimal (base 10) number | NYI |
|`%x` Prints a number in hexadecimal (base 16) lowercase format | NYI |
|`%X` Prints a number in hexadecimal (base 16) uppercase format | NYI |
|`%%` Prints a percent sign | NYI |
| **BONUS** |
|`#` Hastag Flag | NYI |
|` ` Space Flag | NYI |
|`+` Plus Flag | NYI |
| **CUSTOM** |
|`!` Red Text Flag - `\u001b[31m` | NYI |
|`@` Blue Text Flag - `\u001b[34m` | NYI |
|`&` Green Text Flag - `\u001b[32m` | NYI |
---
we start with looking at variadic functions and how they work, first we add the `<stdarg.h>` header which contains some needed bits and bobs for variadic functions, they are four [(4)](https://en.wikipedia.org/wiki/4) different methods that we can use from stdarg which are
| method | description |
| ------ | ----------- |
| `va_start(va_list POINTER, ARGUMENT_NUMBER)` | we initialize a va_list struct with this so we can access the arguments e.g va_list foo; va_start(foo, argN) |
| `va_arg(va_list POINTER, TYPE)` | accesses next the next argument |
| `va_copy(va_list DESTINATION, va_list SOURCE)` | just copies the va_list |
| `va_end(va_list POINTER)` | this ends travesal of the arguments |

va_list is a struct holding the data we need.

ft_calloc a string array for the individual strings, we find how many strings we need by iterating over the string and counting the % signs (*ignoring the char after % because it could be another %*)
then we can ft_calloc the individual strings one at a time, we take the original string up to the first % and put that in our array, then pass the %+char to a function to handle the variadic part, and that will put a string into the next array box

if we don't want to start with a variadic functions we can start with a function that takes a string and looks for `%` signs and the char after it and replace/insert something into that space i.e "This %s is valid" prints "This STRING is valid" then we can connect it to the variadic functions later.


## Base Conversion
*Hex, Octal, Binary, Decimal and Arbitrary*

[Piscine Attempt](https://github.com/TeriyakisaurusRex/42Piscine/blob/main/C_04/ex04/ft_putnbr_base.c)

- Hex / Hexidecimal / base 16 = [0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F]
- Octal / base 8 = [0,1,2,3,4,5,6,7]
- Binary / base 2 = [0,1]
- Decimal / base 10 = [0,1,2,3,4,5,6,7,8,9]

i hope you are noticing a pattern by now on how to count in different bases. They all start at 0 and have unique symbols for all the numbers up to their base - 1. classic arrays. we all know how to count in decimal but counting in the other bases is hard and confusing. 


---

Questions?
- is accessing va_arg like access read-buffer in that it changes every time we look at it?
- how does va_end actually work?
- how does string "This %s%c%p work?" work?

Error Handling
- "string %"  -> % char at last index of array 
- ""          -> empty string
- "\0"        -> null string
- "strin%g"   -> invalid char after % 
- test invalid arguments i.e. %c with string

Assumptions
- String is valid

Ideas
- calloc and concatenate old string with replaced parts, using ft_split and other functions
- find old base converter from piscine and use that for some of the conversions
- follow up on ft_sprintf() and ft_fprintf() 


# Result
Not Handed In Yet / 100
