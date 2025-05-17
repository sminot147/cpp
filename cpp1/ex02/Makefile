# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 19:53:55 by sminot            #+#    #+#              #
#    Updated: 2025/05/17 19:54:25 by sminot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ptnVSref

FILES = main.cpp\

OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
OBJ_DEPS = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.d))

CPPFLAGS = -Wall -Wextra -Werror -MMD -std=c++98
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

-include $(DEPS)

.PHONY: all clean fclean re