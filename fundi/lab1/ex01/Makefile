NAME = matr

MAIN = main.cpp

CC = g++

SRCS = classes/Matrix_square.cpp\
	   classes/Matrix_square_operators.cpp\
	   classes/Matrix_square_constructors.cpp

OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN)

