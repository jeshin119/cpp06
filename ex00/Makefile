NAME := a.out
CXX := c++
RM := rm -f
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
DBG = -g -fsanitize=address
SRCS := main.cpp\
		ScalarConverter.cpp
HEADERS := ScalarConverter.hpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

d : $(SRCS) $(HEADERS)
	$(CXX) $(DBG) $(SRCS) 
test :
	bash test.sh > out 2>&1

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) out

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re