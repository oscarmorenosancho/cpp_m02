# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 09:42:47 by omoreno-          #+#    #+#              #
#    Updated: 2023/06/23 15:53:33 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= BSP

CLASSSRC	:=	Fixed.cpp Point.cpp

EXTRASRC	:=	bsp.cpp

MAINSRC		:=	main.cpp

HEADER		:=	$(CLASSSRC:.cpp=.hpp)
CLASSOBJ	:=	$(CLASSSRC:.cpp=.o)
EXTRAOBJ	:=	$(EXTRASRC:.cpp=.o)
MAINOBJ		:=	$(MAINSRC:.cpp=.o)

CC			:=	@c++
RM			:=	@rm -f
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98

all : $(NAME)

%.o : %.cpp ${HEADER} Makefile
	@echo "Compiling" $@
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : ${CLASSOBJ} ${EXTRAOBJ} ${MAINOBJ} ${HEADER} Makefile
	@echo "Linking" $@
	${CC} ${CFLAGS} ${EXTRAOBJ} ${CLASSOBJ} ${MAINOBJ} -o $@

clean :
	$(RM) $(CLASSOBJ)
	$(RM) $(EXTRAOBJ)
	$(RM) $(MAINOBJ)
	@echo "Cleaned objects"

fclean : clean
	$(RM) $(NAME)
	@echo "Cleaned executable"

re: fclean all

.PHONY : clean fclean re all