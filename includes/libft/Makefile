# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmall <asmall@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 18:00:46 by asmall            #+#    #+#              #
#    Updated: 2019/11/29 17:15:28 by asmall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

PRINTF_C = ft_bigint_operations.c ft_bigint.c ft_buff_manage.c ft_handle.c ft_parse_nums.c \
ft_print_cs.c ft_print_diuoxb.c ft_print_e.c ft_print_f.c ft_print_options.c ft_print_prk.c \
ft_printf.c ft_set_options.c ft_utils_num.c ft_utils_str.c ft_color.c \

GNL_C = get_next_line.c ft_lstadd.c \

HEAD = ./headers

LIBFT_C = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c mod_compair.c mod_minus.c mod_plus.c to_power.c size_int_mass.c integer_size.c ft_strndup.c ft_is_num.c free_doub_lvl_mass.c create_int_mass.c ft_swap.c ft_chr_and_fill.c take_power.c ft_digstr_cpy.c \

DIR_O = temporary

CFILES = $(LIBFT_C) $(PRINTF_C) $(GNL_C)

PATH_C = $(addprefix ./src/libft/,$(LIBFT_C)) $(addprefix ./src/ft_printf/,$(PRINTF_C)) $(addprefix ./src/get_next_line/,$(GNL_C))

OFILES = $(CFILES:.c=.o)

PATH_O = $(addprefix $(DIR_O)/,$(OFILES))

all: $(NAME)

$(NAME): $(PATH_O)
	@ar rc $(NAME) $(PATH_O)
	@ranlib $(NAME)

$(DIR_O)/%.o: ./src/libft/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/ft_printf/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/get_next_line/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	@$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

clean:
	@rm -f temporary/*.o
	@rm -rf temporary

fclean: clean
	@rm -f $(NAME)

re: fclean all
