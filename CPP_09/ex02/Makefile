#******************************************************************************
#                                    MAIN                                     *
#******************************************************************************

NAME = PmergeMe

#******************************************************************************
#                                 DIRECTORIES                                 *
#******************************************************************************

OBJ_DEP_DIR = obj_n_dep/

#******************************************************************************
#                   SOURCES, OBJECTS, HEADER & DEPENDENCIES                   *
#******************************************************************************

# SRC_FOLD = srcs/

HEADER_FOLD = header/

HEADER_SRC = PmergeMe

# CPP_SRC =

HEADER_FLS = $(addsuffix .hpp, $(HEADER_SRC))

HEADER = $(addprefix $(HEADER_FOLD), $(HEADER_FLS))

# CPP_FLS = $(addsuffix .cpp, $(CPP_SRC))

# SRC = $(addprefix $(SRC_FOLD), $(CPP_FLS))

OBJ = $(addprefix $(OBJ_DEP_DIR), $(SRC:.cpp=.o))

OBJF = .cache_exists

DEP = $(addprefix $(OBJ_DEP_DIR), $(OBJ:.o=.d))

#******************************************************************************
#                                INSTRUCTIONS                                 *
#******************************************************************************

CC = c++ -g3
FLAGS = -Wall -Wextra -Werror -I. -std=c++98
RM = rm -rf

#******************************************************************************
#                                  COLORS                                     *
#******************************************************************************

RESET = \033[0m
ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
#                                COMPILATION                                  *
#******************************************************************************

all : $(NAME)
	@echo "$(ROSE)COMPILATION FINISHED, $(NAME) IS CREATED!$(RESET)"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) main.cpp PmergeMe.cpp -o $(NAME)

$(OBJ_DEP_DIR)%.o : $(HEADER) | $(OBJF)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLEU)Compiling $< to $@.$(RESET)"

$(OBJF):
	@mkdir -p $(OBJ_DEP_DIR)$(SRC_FOLD)

clean :
	@$(RM) $(OBJ_DEP_DIR)
	@echo "$(VIOLET)Suppressing objects & dependencies files of $(NAME).$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(VERT)Suppressing archives $(NAME).$(RESET)"

re : fclean all

-include $(DEP)

.PHONY : re fclean clean all