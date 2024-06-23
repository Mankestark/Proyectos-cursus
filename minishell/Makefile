NAME				=	minishell

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf

UNAME				:=	$(shell uname)

ifeq ($(UNAME), Linux)
READLINE_INC		=
READLINE_LIB		=	-lreadline
endif
ifeq ($(UNAME), Darwin)
READLINE_INC		=	-I /System/Volumes/Data/sgoinfre/goinfre/Perso/${USER}/readline/include
READLINE_LIB		=	-L /System/Volumes/Data/sgoinfre/goinfre/Perso/${USER}/readline/lib -lreadline
endif

SRC_DIR				=	src
SRCS_AST			=	ast_add_arg.c \
						ast_add_child.c \
						ast_add_redir.c \
						ast_add_sibling.c \
						ast_arg_count.c \
						ast_child_count.c \
						ast_create.c \
						ast_free.c \
						ast_is_cmd.c \
						ast_is_pipe.c \
						ast_read_count.c \
						ast_pipe_heredoc_count.c \
						ast_redir_count.c \
						ast_sibling_count.c
SRCS_AST_TOOLKIT	=	ast_delim_len.c \
						ast_delim_value.c \
						ast_expand.c \
						ast_generate.c \
						ast_new_command_node.c \
						ast_parse.c \
						ast_text_len.c \
						ast_text_value.c
SRCS_BUILDER		=	conchi_cd.c \
						conchi_echo.c \
						conchi_env.c \
						conchi_exit.c \
						conchi_export.c \
						conchi_pwd.c \
						conchi_unset.c \
						executor_builds.c
SRCS_ENVIRON		=	evd_free.c \
						evd_get.c \
						evd_is_valid.c \
						evd_load.c \
						evd_remove.c \
						evd_save.c \
						evd_set.c
SRCS_ERRORS			=	print_errors.c \
						print_error_and_exit.c
SRCS_EXECUTOR		=	executor_cmd.c \
						executor_tools.c \
						executor_handle_commands.c \
						executor_wrapper.c \
						executor.c
SRCS_LEXER			=	add_token.c \
						free_list.c \
						ft_isspace.c \
						handle_normal_token.c \
						handle_special_char.c \
						is_special_char.c \
						split_tokens.c \
						tokenizer.c
SRCS_LIBFT			=	ft_atoi.c \
						ft_strjoin.c \
						ft_calloc.c \
						ft_free_array.c \
						ft_free.c \
						ft_is_alpha.c \
						ft_is_alphanum.c \
						ft_itoa.c \
						ft_memcpy.c \
						ft_num_len.c \
						ft_putstr_fd.c \
						ft_str_cmp.c \
						ft_strchr.c \
						ft_strcpy.c \
						ft_strdup.c \
						ft_strlen.c \
						ft_strncpy.c \
						ft_strnstr.c \
						ft_strrchr.c
SRCS_MAIN			=	main.c
SRCS_REDIR			=	check_redir.c \
						heredoc.c \
						heredoc_utils.c \
						redir_utils.c
SRCS_SIGNAL			=	signal/signal.c
SRCS_STL			=	stl_add.c \
						stl_free.c \
						stl_is_pipe.c \
						stl_is_redir.c \
						stl_is_text.c
SRCS_STL_TOOLKIT	=	stl_analysis.c \
						stl_guess_type.c

VPATH 				=	src/ast \
						src/ast_toolkit \
						src/builder \
						src/environ \
						src/errors \
						src/executor \
						src/lexer \
						src/libft \
						src/main \
						src/stl \
						src/redir \
						src/signal \
						src/stl_toolkit

SRCS			=	$(addprefix $(SRC_DIR)/ast/,$(SRCS_AST)) \
					$(addprefix $(SRC_DIR)/ast_toolkit/,$(SRCS_AST_TOOLKIT)) \
					$(addprefix $(SRC_DIR)/builder/,$(SRCS_BUILDER)) \
					$(addprefix $(SRC_DIR)/environ/,$(SRCS_ENVIRON)) \
					$(addprefix $(SRC_DIR)/errors/,$(SRCS_ERRORS)) \
					$(addprefix $(SRC_DIR)/executor/,$(SRCS_EXECUTOR)) \
					$(addprefix $(SRC_DIR)/lexer/,$(SRCS_LEXER)) \
					$(addprefix $(SRC_DIR)/libft/,$(SRCS_LIBFT)) \
					$(addprefix $(SRC_DIR)/main/,$(SRCS_MAIN)) \
					$(addprefix $(SRC_DIR)/redir/,$(SRCS_REDIR)) \
					$(addprefix $(SRC_DIR)/signal/,$(SRCS_SIGNAL)) \
					$(addprefix $(SRC_DIR)/stl/,$(SRCS_STL)) \
					$(addprefix $(SRC_DIR)/stl_toolkit/,$(SRCS_STL_TOOLKIT))

OBJ_DIR			=	obj
OBJS			=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

RESET			=	\033[0m
ICYAN			=	\033[3;36m

all:				$(NAME)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(NAME):			$(OBJ_DIR) $(OBJS)
					@echo "$(ICYAN)Linking minishell$(RESET)"
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(READLINE_LIB)

$(OBJ_DIR)/%.o:		%.c
					@echo "$(ICYAN)Compiling $<$(RESET)"
					@$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean:
					@echo "$(ICYAN)Cleaning objects$(RESET)"
					@$(RM) $(OBJ_DIR)

fclean:				clean
					@echo "$(ICYAN)Cleaning executable$(RESET)"
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re