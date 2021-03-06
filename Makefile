# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 13:35:22 by dexposit          #+#    #+#              #
#    Updated: 2022/04/28 20:43:24 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR				=	ft_strlen.c		\
					ft_strlcpy.c	\
					ft_strlcat.c	\
					ft_strchr.c		\
					ft_strrchr.c	\
					ft_strncmp.c	\
					ft_strnstr.c	\
					ft_strdup.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_bzero.c		\
					ft_atoi.c
PUT				=	ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c
IS				=	ft_isalnum.c	\
					ft_isalpha.c	\
					ft_isascii.c	\
					ft_isdigit.c	\
					ft_isprint.c
MEM				=	ft_calloc.c		\
					ft_itoa.c		\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_memset.c		\
					ft_split.c		\
					ft_substr.c
TO				=	ft_tolower.c	\
					ft_toupper.c
BONUS			=	ft_lstnew_bonus.c		\
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c		\
					ft_lstlast_bonus.c		\
					ft_lstadd_back_bonus.c	\
					ft_lstdelone_bonus.c	\
					ft_lstclear_bonus.c		\
					ft_lstiter_bonus.c		\
					ft_lstmap_bonus.c

GNL				=	gnl/get_next_line.c
.SILENT:
DSTR			= $(addprefix str/, $(STR))
DPUT			= $(addprefix put/, $(PUT))
DIS				= $(addprefix isx/, $(IS))
DMEM			= $(addprefix mem/, $(MEM))
DTO				= $(addprefix tox/, $(TO))
DBON			= $(addprefix lst/, $(BONUS))
OBJS			= $(SRCS:%.c=%.o) 
STROBJ			= $(DSTR:%.c=%.o)
PUTOBJ			= $(DPUT:%.c=%.o)
ISOBJ			= $(DIS:%.c=%.o)
MEMOBJ			= $(DMEM:%.c=%.o)
TOOBJ			= $(DTO:%.c=%.o)
ALLOBJ			= $(OBJS) $(STROBJ) $(PUTOBJ) $(ISOBJ) $(MEMOBJ) $(TOOBJ)
BONUS_OBJS		= $(DBON:.c=.o)
GNL_OBJS		= $(GNL:.c=.o)
ALLBON			= $(BONUS_OBJS) $(GNL_OBJS) $(ALLOBJ)

BONUSS			= . 
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -Ignl/ -I.
NAME			= libft.a

all:			$(NAME)

$(NAME):		$(ALLOBJ)
				ar rcs $(NAME) $(ALLOBJ)

clean:
				$(RM) $(ALLOBJ) $(BONUS_OBJS) $(GNL_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUSS)

$(BONUSS):		$(ALLBON)
				ar rcs $(NAME) $(ALLBON)

.PHONY:			all clean fclean re bonus
