NAME 	 = megaphone
CC 		 = c++
CFLAGS   = -Wall -Wextra -Werror -MMD -g3 -std=C++98
SRC_PATH = src/
OBJ_PATH = .obj/
SRC_NAME =	megaphone.cpp
OBJ_NAME = $(SRC_NAME:.cpp=.o) 
OBJ 	 = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

-include $(OBJ:%.o=%.d)

clean:
	rm -rf .obj

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) -s fclean all

.PHONY: all clean fclean re
