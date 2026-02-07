NAME 	= philo

CC 		= gcc
CFLAGS	= -pthread -Wall -Wextra -Werror

SRCS	= main.c error.c

GREEN	= \033[0;32m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(SRCS)
	@echo "$(GREEN)Philosophers compiled successfully!$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean:clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY : all clean fclean re
