CC = gcc

FLAGS = -g -Wall -Wextra -Werror

NAME = getNextLine
NAME_BONUS = getNextLineBonus

SRCS_DIR = ./srcs/

SOURCES =	get_next_line.c \
			get_next_line_utils.c \
			main.c

SOURCES_BONUS =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				main_bonus.c

OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), ${SOURCES:.c=.o})
OBJS_BONUS = $(addprefix $(OBJS_DIR), ${SOURCES_BONUS:.c=.o})

all : $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(FLAGS) -o $@ $^

bonus : $(NAME_BONUS)

$(NAME_BONUS) :	$(OBJS_BONUS)
				$(CC) $(FLAGS) -o $@ $^

clean :
		rm -rf $(OBJS_DIR)

fclean :	clean
			rm -f $(NAME)
			rm -f $(NAME_BONUS)

re :	fclean all

$(OBJS_DIR)main.o :	main.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(FLAGS) -o $@ -c $< -DBUFFER_SIZE=42

$(OBJS_DIR)main_bonus.o :	main_bonus.c
							mkdir -p $(OBJS_DIR)
							$(CC) $(FLAGS) -o $@ -c $< -DBUFFER_SIZE=42

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(FLAGS) -o $@ -c $< -DBUFFER_SIZE=42

.PHONY : all re clean fclean bonus