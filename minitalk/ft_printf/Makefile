NAME = libftprintf.a
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
SRC_DIR = src/
INCLUDE_DIR = include/

SRC_FILES = ft_printf		\
			ft_print_char	\
			ft_print_str	\
			ft_print_radix	\
			ft_print_ptr	\
			ft_print_type	

C_FILES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
O_FILES = $(addsuffix .o, $(SRC_FILES))

$(NAME):
		$(CC) $(CCFLAGS) -I . -c $(C_FILES) 
		ar -rc $(NAME) $(O_FILES) 

all: $(NAME)

clean:
		rm -f $(O_FILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
