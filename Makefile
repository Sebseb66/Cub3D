# Cub3D - 3D Game like Wolfenstein

# Compile informations
NAME	=	cub3D
FLAGS	=	-Wall -Wextra -Werror -g -Ofast
MLXFLAGS = 	-lXext -lX11

#All sources files to compile
SRC = src/
SRC_RAYCASTING = src/raycasting/
SRC_CHECK = src/check/
SRC_SETUP = src/setup/
SRC_UTILS = src/utils/
SRC_FILES = $(wildcard $(SRC)/*.c) \
			$(wildcard $(SRC_RAYCASTING)/*.c) \
			$(wildcard $(SRC_CHECK)/*.c) \
			$(wildcard $(SRC_SETUP)/*.c) \
			$(wildcard $(SRC_UTILS)/*.c)
OBJS = $(addprefix $(SRC_FOLDER), $(SRC_FILES:.c=.o))

#Some colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
DEFAULT	=	\033[0m
ORANGE =   \033[0;33m

#Libs

GNL_PATH = libs/get_next_line/
GNL = $(GNL_PATH)libgnl.a

MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

# Rules
%.o: %.c
	@echo "$(ORANGE) Compiling...$<$(DEFAULT)"
	@gcc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@clear
	@printf "$(GREEN)  _____         _      ____   _____\n"
	@printf " / ____|       | |    |___ \ |  __ \\n"
	@printf "| |      _   _ | |__    __) || |  | |\n"
	@printf "| |     | | | || '_ \  |__ < | |  | |\n"
	@printf "| |____ | |_| || |_) | ___) || |__| |\n"
	@printf "| |____ | |_| || |_) | ___) || |__| |\n"
	@printf "                                                  \n"
	@make -C $(GNL_PATH) --no-print-directory -s
	@make -C $(MLX_PATH) --no-print-directory -s
	@echo "$(ORANGE) Compiling Cub3D$(RED)...$(DEFAULT)"
	@gcc $(FLAGS) $(MLX_LIB) -o $(NAME) $(OBJS) ./libs/get_next_line/libgnl.a ./mlx/libmlx.a $(MLXFLAGS) -lm
	@echo "$(GREEN) $(NAME) is ready$(DEFAULT)"

all:	$(NAME)

clean:
	@echo "$(RED) Cleaning..$(NAME)$(DEFAULT)"
	@make -C $(GNL_PATH) clean --no-print-directory -s
	@make -C $(MLX_PATH) clean --no-print-directory -s
	@rm -rf $(OBJS)

fclean:		clean
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean --no-print-directory -s
	@make -C $(GNL_PATH) fclean --no-print-directory -s
	@echo " $(RED)$(NAME) is cleaned$(DEFAULT)"

re:		fclean all
		@echo "$(ORANGE) $(NAME) recompiled successfully$(DEFAULT)"

norm:
	@echo "$(GREEN)Checking norm$(DEFAULT)"
	@norminette $(SRC_FOLDER) | grep -B 1 "Error" || echo "$(GREEN)Norme OK$(DEFAULT)"

.PHONY: all clean fclean re norm
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@rm -rf $(NAME)
