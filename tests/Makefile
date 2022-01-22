NAME			= test
SRCS			= test_utils.cpp tests_vector/vec.cpp stack/stack_test.cpp tests_map/map_test.cpp
OBJS			= $(patsubst %.cpp, %.o, $(SRCS))
HEADERS			= test_utils.h
CC				= clang++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(HEADERS) $(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:

.PHONY:			all clean fclean re