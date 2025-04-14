# == Makefile pour push_swap == 

SRC_DIR = src
ALG_DIR = $(SRC_DIR)/algorithm
CMD_DIR = $(SRC_DIR)/commands
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard $(ALG_DIR)/*.c) $(wildcard $(CMD_DIR)/*.c)
OBJS = $(patsubst $(ALG_DIR)/%.c, $(OBJ_DIR)/algorithm_%.o, $(wildcard $(ALG_DIR)/*.c)) \
	   $(patsubst $(CMD_DIR)/%.c, $(OBJ_DIR)/commands_%.o, $(wildcard $(CMD_DIR)/*.c))


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes

# == Couleurs pour les messages dans le terminal ==
YELLOW = \033[1;33m
NC = \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)push_swap compiled successfully!$(NC)"

# == Compilation des fichiers .c en .o ==
$(OBJ_DIR)/algorithm_%.o: $(ALG_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/commands_%.o: $(CMD_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# == Nettoyage des fichiers objets ==
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files cleaned.$(NC)"

# == Nettoyage des fichiers objets ==
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)Executable removed.$(NC)"

# == Nettoyage des fichiers objets ==
re: fclean all

.PHONY: all clean fclean re