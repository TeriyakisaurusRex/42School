#Library#
LIBRARY = libft
OUTN = $(LIBRARY).a
NAME = $(OUTN)
#-------#

#Functions#
SRC_CHAR = ft_isalnum	\
		   ft_isascii	\
		   ft_isdigit	\
		   ft_isprint	\
		   ft_isupper	\
		   ft_islower	\
		   ft_isspace	\
		   ft_toupper	\
		   ft_tolower	\
		   ft_isalpha

SRC_CONVERSION = ft_atoi	\
				 ft_itoa

SRC_MEMORY = ft_bzero	\
			 ft_calloc	\
			 ft_memchr	\
			 ft_memcmp	\
			 ft_memcpy	\
			 ft_memmove	\
			 ft_memset	

SRC_PRINT = ft_putchar_fd	\
			ft_putnbr_fd	\
			ft_putstr_fd	\
			ft_putendl_fd	

SRC_STR = ft_split		\
		  ft_strchr		\
		  ft_strdup		\
		  ft_strddup	\
		  ft_striteri	\
		  ft_strjoin	\
		  ft_strlcat	\
		  ft_strlcpy	\
		  ft_strlen		\
		  ft_strdlen	\
		  ft_strmapi	\
		  ft_strncmp	\
		  ft_strnstr	\
		  ft_strrchr	\
		  ft_strtrim	\
		  ft_substr

SRCS = $(SRC_CHAR)			\
	   $(SRC_CONVERSION)	\
	   $(SRC_MEMORY) 		\
	   $(SRC_PRINT)			\
	   $(SRC_STR)			

BONUS_SRCS = ft_lstnew			\
			 ft_lstadd_front	\
			 ft_lstsize			\
			 ft_lstlast			\
			 ft_lstadd_back		\
			 ft_lstdelone		\
			 ft_lstclear		\
			 ft_lstiter			\
			 ft_lstmap

CFILES = $(SRCS:%=%.c)
OFILES = $(SRCS:%=%.o)

CFILES_BONUS = $(BONUS_SRCS:%=%.c)
OFILES_BONUS = $(BONUS_SRCS:%=%.o)
#---------#

#Compliler#
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#---------#

#Rules#
$(NAME):
	$(CC) $(CFLAGS) -I . -c $(CFILES)
	ar -rc $(NAME) $(OFILES)

bonus: 
	$(CC) $(CFLAGS) -I . -c $(CFILES) $(CFILES_BONUS)
	ar -rc $(NAME) $(OFILES) $(OFILES_BONUS)

all: $(NAME)

clean:
	-rm $(OFILES) $(OFILES_BONUS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
