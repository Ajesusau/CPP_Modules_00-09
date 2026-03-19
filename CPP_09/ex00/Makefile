# Colors ANSI
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
RESET	= \033[0m
PURPLE	= \033[38;5;141m
ORANGE	= \033[38;5;208m
TEAL	= \033[38;5;80m

NAME = btc
OBJS = $(SRCS:.cpp=.o)
HEADERS = -I ./include

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
RM = rm -f

SRCS =		main.cpp \
			src/BitcoinExchange.cpp

all: $(NAME)
	@echo "$(GREEN)✅ Build completed successfully!$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)🛠️  Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(PURPLE)📦 Creating the program: $(NAME)"
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@echo "$(MAGENTA)🗑️🧹Deleting $(NAME) .o files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✅ Done!$(RESET)"

fclean: clean
	@echo "$(RED)💥 Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

re: re_msg fclean all

new: re_msg fclean all
	@make -s clean

re_msg:
	@echo "$(ORANGE)🔄 Recreating $(NAME)...$(RESET)"

.PHONY: all libft clean fclean re new
