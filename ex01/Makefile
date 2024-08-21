NAME = Phonebook
CC = g++ -o -g
CFLAGZ = -Wall -Wextra -Werror -std=c++98
SRCS = 	main.cpp Contact.cpp Phonebook.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGZ) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)	$(CFLAGZ)	-o	$(NAME)	$(OBJS) 


clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)
	
re: fclean all