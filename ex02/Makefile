# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:02:41 by mhaile            #+#    #+#              #
#    Updated: 2024/05/21 16:02:41 by mhaile           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = PmergeMe

RM                      = rm -rf
CXX                     = c++
CXXFLAGS                = -Wall -Wextra -Werror -std=c++98 -g3

OBJDIR                  = obj
SRCS                    = main.cpp PmergeMe.cpp
OBJ_FILES               = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

$(OBJDIR)/%.o:  %.cpp
						mkdir -p $(dir $@)
						$(CXX) $(CXXFLAGS) -c $< -o $@

all:                    $(NAME)

$(NAME):                $(OBJ_FILES)
						$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
						$(RM) $(OBJ_FILES)
						$(RM) $(OBJDIR)

fclean:                 clean
						$(RM) $(NAME)

re:                     fclean $(NAME)

push:                   fclean
						git add .
						git commit -m "Updated on $(shell date +'%Y-%m-%d %H:%M:%S') by $(USER)"
						git push

.PHONY:                 all clean fclean re push