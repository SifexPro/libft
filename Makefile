# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 23:08:18 by Sifex             #+#    #+#              #
#    Updated: 2023/12/13 23:08:18 by Sifex            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME		=	libft.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	srcs
INC_DIR			=	includes
OBJ_DIR			=	objs
LIBFT_DIR		=	libft/
PRINTF_DIR		=	printf/
GNL_DIR			=	get_next_line/

# ------------  SOURCES  ----------------------------------------------------- #

SRC_FLS			=	$(LIBFT_FLS)\
					$(PRINTF_FLS)\
					$(GNL_FLS)\

LIBFT_FLS		=	$(LIBFT_DIR)ft_atoi.c $(LIBFT_DIR)ft_bzero.c $(LIBFT_DIR)ft_calloc.c $(LIBFT_DIR)ft_isalnum.c $(LIBFT_DIR)ft_isalpha.c $(LIBFT_DIR)ft_isascii.c $(LIBFT_DIR)ft_isdigit.c $(LIBFT_DIR)ft_isprint.c $(LIBFT_DIR)ft_itoa.c $(LIBFT_DIR)ft_memchr.c $(LIBFT_DIR)ft_memcmp.c $(LIBFT_DIR)ft_memcpy.c $(LIBFT_DIR)ft_memmove.c $(LIBFT_DIR)ft_memset.c $(LIBFT_DIR)ft_putchar_fd.c $(LIBFT_DIR)ft_putendl_fd.c $(LIBFT_DIR)ft_putnbr_fd.c $(LIBFT_DIR)ft_putstr_fd.c $(LIBFT_DIR)ft_split.c $(LIBFT_DIR)ft_strchr.c $(LIBFT_DIR)ft_strdup.c $(LIBFT_DIR)ft_striteri.c $(LIBFT_DIR)ft_strjoin.c $(LIBFT_DIR)ft_strlcat.c $(LIBFT_DIR)ft_strlcpy.c $(LIBFT_DIR)ft_strlen.c $(LIBFT_DIR)ft_strmapi.c $(LIBFT_DIR)ft_strncmp.c $(LIBFT_DIR)ft_strnstr.c $(LIBFT_DIR)ft_strrchr.c $(LIBFT_DIR)ft_strtrim.c $(LIBFT_DIR)ft_substr.c $(LIBFT_DIR)ft_tolower.c $(LIBFT_DIR)ft_toupper.c $(LIBFT_DIR)ft_lstadd_back_bonus.c $(LIBFT_DIR)ft_lstadd_front_bonus.c $(LIBFT_DIR)ft_lstclear_bonus.c $(LIBFT_DIR)ft_lstdelone_bonus.c $(LIBFT_DIR)ft_lstiter_bonus.c $(LIBFT_DIR)ft_lstlast_bonus.c $(LIBFT_DIR)ft_lstmap_bonus.c $(LIBFT_DIR)ft_lstnew_bonus.c $(LIBFT_DIR)ft_lstsize_bonus.c
PRINTF_FLS		=	$(PRINTF_DIR)ft_printf.c $(PRINTF_DIR)ft_printf_char.c $(PRINTF_DIR)ft_printf_flags.c $(PRINTF_DIR)ft_printf_flags_utils.c $(PRINTF_DIR)ft_printf_hex.c $(PRINTF_DIR)ft_printf_nbr.c $(PRINTF_DIR)ft_printf_ptr.c $(PRINTF_DIR)ft_printf_size.c $(PRINTF_DIR)ft_printf_str.c $(PRINTF_DIR)ft_printf_unsigned.c
GNL_FLS			=	$(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS			=	$(OBJS:.o=.d)

# ------------  MISC  -------------------------------------------------------- #
CC				=	cc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I $(INC_DIR)	

# ------------  RULES  ------------------------------------------------------- #

all:				${NAME}

-include $(DEPS)
$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c -o $@ $< $(IFLAGS)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@echo "Created $(OBJ_DIR)"
					@mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
					@echo "Created $(OBJ_DIR)/$(LIBFT_DIR)"
					@mkdir -p $(OBJ_DIR)/$(PRINTF_DIR)
					@echo "Created $(OBJ_DIR)/$(PRINTF_DIR)"
					@mkdir -p $(OBJ_DIR)/$(GNL_DIR)
					@echo "Created $(OBJ_DIR)/$(GNL_DIR)\n"

$(NAME):			$(OBJS)
					@ar -rsc $(NAME) ${OBJS}
					@echo "Compiled $(NAME)"

clean:	
					@$(RM) $(OBJ_DIR)
					@echo "Clean libft"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "Full clean libft"

re:				fclean all

.PHONY: 		all clean fclean re
