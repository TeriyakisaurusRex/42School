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

Assumptions
- String is valid

Ideas
- calloc and concatenate old string with replaced parts, using ft_split and other functions
- find old base converter from piscine and use that for some of the conversions
- follow up on ft_sprintf() and ft_fprintf() 


# Result
Not Handed In Yet / 100
