NAME = cub3D
SRC_DIR = srcs
SRCS = cu_parse_texture.c cu_parse_map.c cu_utils.c \
cu_init.c cub3d.c cu_load_data.c cu_cast_floor.c cu_cast_wall.c cu_draw_minimap.c \
cu_check_key.c cu_control_mouse.c cu_make_door_list.c cu_cast_door.c cu_check_hit_door.c \
cu_door_utils.c cu_parse_map_utils.c cu_parse_utils.c cu_texture_utils.c cu_cast_wall_utils.c
BNS_SRC_DIR = bonus
BNS_SRCS = cu_parse_texture_bonus.c cu_parse_map_bonus.c cu_utils_bonus.c \
cu_init_bonus.c cub3d_bonus.c cu_load_data_bonus.c cu_cast_floor_bonus.c cu_cast_wall_bonus.c cu_draw_minimap_bonus.c \
cu_check_key_bonus.c cu_control_mouse_bonus.c cu_make_door_list_bonus.c cu_cast_door_bonus.c cu_check_hit_door_bonus.c \
cu_door_utils_bonus.c cu_parse_map_utils_bonus.c cu_parse_utils_bonus.c cu_texture_utils_bonus.c cu_cast_wall_utils_bonus.c
INCS = cub.h keys.h cub_bonus.h
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BNS = $(addprefix $(OBJ_DIR)/, $(BNS_SRCS:.c=.o))
INC_DIR = incs
INCS = cub.h keys.h cub_bonus.h
LIBFT = -Ilibft -Llibft -lft
LIBFT_DIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I $(INC_DIR) -Ilibft
CLIB	= -Lmlx -lmlx -framework OpenGL -framework Appkit

ifdef WITH_BONUS
	OBJS_RES = $(OBJS_BNS)
	SRC_DIR_RES = $(BNS_SRC_DIR)
else
	OBJS_RES = $(OBJS)
	SRC_DIR_RES = $(SRC_DIR)
endif

all : $(NAME)

$(NAME) : $(OBJS_RES)
	make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(CLIB)

$(OBJ_DIR)/%.o : $(SRC_DIR_RES)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC_FLAGS) -Imlx

bonus :
	@make WITH_BONUS=1 all

clean :
	make -sC $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
