##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compilateur make, clean, fclean,re
##

NAME	= calc

CC	= gcc

RM	= rm -f

SRC	=	source/trifonc.c \
		source/infinad.c \
		source/my_strcat.c \
		source/my_put_nbr.c \
		source/my_convert_base.c \
		source/my_revstr.c \
		source/op_n_strstr/evalexp.c \
		source/op_n_strstr/is_op.c \
		source/op_n_strstr/my_isalpha.c \
		source/op_n_strstr/trans_op.c \
		source/infisup/my_strisequal.c \
		source/infisup/my_strlencomp.c \
		source/infisup/calc_else_sup.c \
		source/infisup/infisup.c \
		source/infisup/is_ret_sup.c \
		source/infisup/my_str_issup.c \
		source/infisup/corec_rep.c \
		source/infisup/is_ret_sup_else.c \
		source/gest_er/errors_plus.c \
		source/gest_er/gest_errors.c \
		source/gest_er/my_atoi.c \
		source/gest_er/my_putchar.c \
		source/gest_er/my_putstr.c \
		source/gest_er/my_strlen.c \
		source/multiplication.c \
		source/ret_add.c \
		source/modulo.c \
		source/division.c \
		source/my_itoa.c \
		source/gest_er/check_expr.c

OBJ	= $(SRC:.c=.o)

FLAG	= -I ./include

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
