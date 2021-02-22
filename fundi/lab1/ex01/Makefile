NAME = matr

MAIN = main.cpp

CC = g++

SRCS_CLASSES_ = Matrix_square.cpp\
	   Matrix_square_operators.cpp\
	   Matrix_square_constructors.cpp

SRCS_CLASSES = $(addprefix classes/, $(SRCS_CLASSES_))

OBJS_CLASSES=$(SRCS_CLASSES:.cpp=.o)

OBJS = $(OBJS_CLASSES)

.cpp.o:
	$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN)

