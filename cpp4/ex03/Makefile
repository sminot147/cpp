NAME = a.out

FILES = main.cpp\
	AMateria.cpp\
	Ice.cpp\
	Cure.cpp\
	Character.cpp\
	MateriaSource.cpp\

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
OBJ_DEPS = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.d))

CPPFLAGS = -Wall -Wextra -Werror -MMD -std=c++98 -g3
CPP = c++

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CPP) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(OBJ_DEPS)

.PHONY: all clean fclean re
