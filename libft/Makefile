SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c get_next_line_bonus.c get_next_line_utils_bonus.c format.c ft_printf.c ft_printf_utils.c
SRCS_BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS	= $(SRCS:%.c=%.o)
OBJS_BNS = $(SRCS_BNS:%.c=%.o)
NAME	= libft.a
LIBC	= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJS_RES = $(OBJS_BNS) $(OBJS)
else
	OBJS_RES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_RES)
	$(LIBC) $(NAME) $(OBJS_RES)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

bonus :
	@make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
