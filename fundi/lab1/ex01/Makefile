NAME = matr

MAIN = main.cpp

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS_DIRS = ./classes .

OBJS_DIR = ./objs

SRCS = $(wildcard $(addsuffix /*.cpp, $(SRCS_DIRS)))

OBJS = $(addprefix objs/, $(notdir $(patsubst %.cpp, %.o, $(SRCS))))

VPATH = $(SRCS_DIRS)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
