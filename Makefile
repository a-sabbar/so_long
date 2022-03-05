NAME = so_long

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

INCLUDES = so_long.h
INCLUDESB = so_long.h

SRCB =	check_utils2_bonus.c		\
		check_utils_bonus.c			\
		ft_split_bonus.c	 		\
		check_map_bonus.c			\
		check_utils3_bonus.c		\
		so_contutil_bonus.c 		\
		ft_itoa.c					\
		main_bonus.c				\
		ft_xpm_to_image.c			\
		mini_utils_bonus.c			\
		utils_bonus.c				\
		ft_move_bonus.c 			\
		so_contutil_bonus_utils.c	\
		mini_utils1_bonus.c			\

SRC =	check_utils2.c		\
		check_utils.c		\
		ft_split.c			\
		check_map.c			\
		check_utils3.c		\
		so_contutil.c 		\
		main.c				\
		utils.c				\
		mini_utils1.c 		\
		so_contutil_utils.c \


OBJECTSB = $(SRCB:.c=.o)

ifeq ($(OBJECTS),)
	OBJECTS = $(SRC:.c=.o)
else
	OBJECTSB = $(SRC:.c=.o)
endif


all: $(NAME)

$(NAME): $(OBJECTS) | wierd_clean
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJECTS)  -o $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

# %.o : %.c $(INCLUDESB)
# 	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(OBJECTSB)
	@OBJECTS="$(OBJECTSB)" make

wierd_clean:
	@rm -rf $(OBJECTSB)

clean: wierd_clean
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all