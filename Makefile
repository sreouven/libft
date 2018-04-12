FLAGS = -Wall -Wextra -Werror

HEADER = includes

CC = clang

OBJ_DIR = obj/

SRC_DIR = src/

NAME = libft.a

SRC = ft_bzero.c \
	  ft_memset.c \
	  ft_putnstr.c \
	  ft_str_upper.c \
	  ft_lltoa_base.c \
	  ft_str_lower.c \
	  ft_strlen.c \
	  ft_itoa_base.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c     \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_max.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \
	  ft_printf.c \
	  analyse.c \
	  attribut.c \
	  print_args.c \
	  print_char.c \
	  print_int.c \
	  print_str.c \
	  print_ptr.c \
	  print_unicode.c \
	  ft_unicode.c


SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:$(NAME)

$(NAME):$(OBJS)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean:clean
	@rm -rf $(NAME)

re: fclean all
