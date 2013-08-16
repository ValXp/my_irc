##
## Makefile for my_ftp in /home/horner_v/tek2/c/my_irc
## 
## Made by Valentin Horner
## Login   <horner_v@epitech.net>
## 
## Started on  Wed Apr 21 10:34:45 2010 Valentin Horner
## Last update Thu Apr 29 23:07:36 2010 valentin horner
##


NAME_0	=	serveur
NAME_1	=	client

SRC_0	=	src/main_serveur.c		\
		src/xmemory.c			\
		src/xprint.c			\
		src/t_client.c			\
		src/t_channel.c			\
		src/t_user.c			\
		src/launch_server.c		\
		src/run_loop.c			\
		src/build_set.c			\
		src/receive_command.c		\
		src/t_command.c			\
		src/interpret_command.c		\
		src/to_wordtab.c		\
		src/nick.c			\
		src/quit.c			\
		src/leave.c			\
		src/users.c			\
		src/join.c			\
		src/list.c			\
		src/msg.c			\
		src/send_new_listing.c		\
		src/goodbye_my_friend.c		\

SRC_1	=	src/main_client.c		\
		src/xmemory.c			\
		src/xprint.c			\
		src/put_window.c		\
		src/blit_char.c			\
		src/blit_string.c		\
		src/get_screen.c		\
		src/init_screen.c		\
		src/draw_screen.c		\
		src/stop_screen.c		\
		src/resize.c			\
		src/put_screen.c		\
		src/filp_screen.c		\
		src/put_bg.c			\
		src/show_line.c			\
		src/init_input.c		\
		src/draw_text.c			\
		src/gere_keys.c			\
		src/init_app.c			\
		src/connect_to_server.c		\
		src/append_message.c		\
		src/parse_command.c		\
		src/select_it.c			\
		src/build_client_set.c		\
		src/check_before_append.c	\

CFLAGS	=	-W -Wall -ansi -pedantic -Wstrict-prototypes -g -Wformat-security -Wno-format-security

IFLAGS	=	-I./inc/

OBJ_0	=	$(SRC_0:.c=.o)

OBJ_1	=	$(SRC_1:.c=.o)


CC	=	@gcc
RM	=	@rm -rf
LFLAGS	=	

###################################### FreeBSD 

CC_FreeBSD	=	@gcc

RM_FreeBSD	=	@rm -rf

LFLAGS_FreeBSD	=	-L./lib/

###################################### linux 64

CC_ia64-linux		=	@gcc

RM_ia64-linux		=	@rm -rf

LFLAGS_ia64-linux	=	-L./lib/

###################################### sun4

CC_sun4		=	@/usr/sfw/bin/gcc

RM_sun4		=	@/usr/bin/rm -rf

LFLAGS_sun4	=	-lsocket -lnsl -L./lib/

######################################
######################################

PRINT	=	@printf

DRAW_MODE	=	"(0"

TEXT_MODE	=	"(B"

TEST_CHARS	=	"(0abcdefghijklmnopqrstuvwxyz(B\n\n"

TOP_HELLO	=	"(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk(B\n"

BOTTOM_HELLO	=	"(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n(B"

HELLO	=	"(0x[35;1m(B    Compiling %s By ValXp     [0m(0x\n(0x(B[35;1m  Le premier Makefile KIKOOLOL !  [0m(0x(B\n" "My_IRC"

TOP_BYE	=	"[0m(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk(B\n"

BOTTOM_BYE	=	"[0m(0mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj(B\n"

BYE	=	"(0x(B[35;1m              My_IRC              [0m(0x\n(0x(B[35;1m         Compilation done !       [0m(0x(B\n"

BYE_UP	=	"(0x(B[35;1m              My_IRC              [0m(0x\n(0x(B[35;1m            Up-to-date !          [0m(0x(B\n"

COMPILE	=	"\r\t[34;1m[Compiling][0m\t%-25s [35;1m->[0m %s    "

LINK	=	"\t[32;1m[Linking][0m\t%s\n"

REMOVE	=	"\t[31;1m[Removing][0m\t%s\n"

CDEBUG	=	"\t[33;1m[Compiling debug ...][0m\n"

CDONE	=	"[36;1m[%s Compilation Done!][0m\n" "My_IRC"

CLEAR	=	$(PRINT) "\n"##"[H[2J"

NL	=	$(PRINT) "\n"


all	: kikoo $(NAME_0) $(NAME_1) finished

$(NAME_0)	:	$(OBJ_0)
# 			$(NL)
# 			$(PRINT) $(LINK) $(OBJ_0)
# 			$(NL)
			$(CC) -o $(NAME_0) $(OBJ_0) $(LFLAGS)
			$(PRINT) "\r[DCompiling : Done                                   \n"
#			$(PRINT) "[DOk\n"
			$(PRINT) "[33mCompiling :  "
#			$(PRINT) "Please Wait "

$(NAME_1)	:	$(OBJ_1)
# 			$(NL)
# 			$(PRINT) $(LINK) $(OBJ_1)
# 			$(NL)
			$(CC) -o $(NAME_1) $(OBJ_1) $(LFLAGS)
# 			$(PRINT) $(CDONE)
			$(PRINT) "\r[DCompiling : Done                                   \n"
#			$(PRINT) "[DOk\n"
			$(PRINT) $(TOP_BYE)
			$(PRINT) $(BYE)
			$(PRINT) $(BOTTOM_BYE)


.c.o	:
# 	$(PRINT) $(COMPILE) $< $@
	$(PRINT) "[D=>"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean	:
# 	$(PRINT) $(REMOVE) $(OBJ_0) $(OBJ_1) *~ src/*~ inc/*~
# 	$(NL)
	$(RM) $(OBJ_0) $(OBJ_1)
	$(RM) *~ src/*~ inc/*~

fclean	: clean
# 	$(PRINT) $(REMOVE) $(NAME_0) $(NAME_1)
# 	$(NL)
	$(RM) $(NAME_0) $(NAME_1)

re	: kikoo fclean $(NAME_0) $(NAME_1)

kikoo	:
	$(CLEAR)
	$(PRINT) $(TOP_HELLO)
	$(PRINT) $(HELLO)
	$(PRINT) $(BOTTOM_HELLO)
	$(PRINT) "[33mCompiling :  "
#	$(PRINT) "[33mPlease Wait "
	@sleep 1
	$(PRINT) "[D=>"

finished	:
	$(PRINT) "[D[D ..."
	$(PRINT) "\n"
	$(PRINT) $(TOP_BYE)
	$(PRINT) $(BYE_UP)
	$(PRINT) $(BOTTOM_BYE)


.PHONY:	all clean fclean re kikoo 
