# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME	= PmergeMe

CXX		= c++
CCFLAGS	= -Wall -Wextra -Werror -std=c++98 #-MMD -MP#-g
INCLU = PmergeMe.hpp PmergeMe.tpp
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) -s $(CCFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BABEBLUEB)$(NAME) CREATED!$(RESET)"

%.o: %.cpp  $(INCLU)
	$(CXX) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@echo "$(BLUE_BBG)$(NAME) REMOVED!$(RESET)"

re: fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                     COLORS                                   #
# **************************************************************************** #

COLOR_RESET = \033[0m
PINKB = \033[1;95m
REDB = \033[1;91m
ROSEB = \033[1;38;5;225m
BLUEB = \033[1;34m
BABEBLUEB = \033[1;38;5;153m
GREENB = \033[1;38;5;85m
PURPLEB = \033[1;38;5;55m
PSTL_YELLOWB = \033[1;38;2;255;253;208m
PSTL_ORGB = \033[1;38;2;255;179;102m
PSTL_PURPLEB =\033[1;38;2;204;153;255m

GREEN_BBG = \033[1;42m
BLUE_BBG = \033[1;44m
YELLOW_BBG = \033[1;43m
ORANGE_BBG = \033[1;48;5;214m