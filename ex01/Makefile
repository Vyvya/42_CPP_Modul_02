NAME = fixed
CXX = g++
FLAGS = -std=c++98 -g
FLAGS += -Wall -Werror -Wextra
RM = rm -f

SRCS = main.cpp \
		Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean re

.PHONY: all re clean fclean