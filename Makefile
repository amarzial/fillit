CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
SRCS = file_reader.c tile_mgr.c
INCS = libft.h fillit.h
SRCDIR = srcs/
INCDIR = includes/
SOURCES = $(addprefix $(SRCDIR), $(SRCS))
INCLUDES = $(addprefix $(INCDIR), $(INCS))
OBJECTS = $(SRCS:.c=.o)
LIBDIR = libs/
LIBRARIES = -lft
NAME = fillit

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) test.o $(OBJECTS) -L./$(LIBDIR) $(LIBRARIES)

$(OBJECTS): $(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) srcs/test.c $(SOURCES) -I./$(INCDIR)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
