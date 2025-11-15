NAME := ex01
WRONG_NAME := ex01_wrong_case
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic
FILE := main.cpp \
		Animal.cpp \
		Brain.cpp \
		Dog.cpp \
		Cat.cpp
WRONG_FILE := wrong.cpp \
			  Brain.cpp \
			  WrongAnimal.cpp \
			  WrongCat.cpp
OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/, $(FILE:.cpp=.o))
WRONG_OBJ := $(addprefix $(OBJDIR)/, $(WRONG_FILE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

wrong: $(WRONG_NAME)

$(WRONG_NAME): $(WRONG_OBJ)
	$(CXX) $(CXXFLAGS) $(WRONG_OBJ) -o $(WRONG_NAME)

$(WRONG_NAME): 

re: fclean all

run:re
	clear
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

.PHONY: re clean fclean all run