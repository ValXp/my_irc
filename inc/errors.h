/*
** errors.h for my_ftp in /home/horner_v/proj/tek2/c/my_ftp/d_serveur
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Dec 23 19:24:18 2009 valentin horner
** Last update Wed Apr 14 00:43:56 2010 Valentin Horner
*/

#ifndef ERRORS_H_
# define ERRORS_H_

/*
** Background Colors
*/
# define C_BG_BLACK	"\033[40m"
# define C_BG_GRAY	"\033[47m"
# define C_BG_RED	"\033[41m"
# define C_BG_GREEN	"\033[42m"
# define C_BG_YELLOW	"\033[43m"
# define C_BG_BLUE	"\033[44m"
# define C_BG_PURPLE	"\033[45m"
# define C_BG_CYAN	"\033[46m"
/*
** Char Colors
*/
# define C_GRAY		"\033[1;37m"
# define C_RED		"\033[1;31m"
# define C_GREEN	"\033[1;32m"
# define C_YELLOW	"\033[1;33m"
# define C_BLUE		"\033[1;34m"
# define C_PURPLE	"\033[1;35m"
# define C_CYAN		"\033[1;36m"
# define C_BLACK	"\033[1;30m"
# define C_WHITE	"\033[1;37m"
/*
** Error messages
*/
# define FATAL		C_BG_RED C_WHITE "Fatal error : "
# define END		C_BG_BLACK C_WHITE "\n"
# define WARN		C_BG_YELLOW C_WHITE "Warning : "
# define INFO		C_BG_BLUE C_WHITE

# define MALLOC_ERROR		FATAL "No more memory space available." END
# define ERROR_SOCKET_CREATE	FATAL "Cannot create socket." END
# define ERROR_LISTENING_SOCKET	FATAL "Cannot listen on socket." END
# define ERROR_SOCKET_ACCEPT	FATAL "Cannot accept socket." END
# define ERROR_SOCKET_CONNECT	FATAL "Cannot connect socket." END
# define ERROR_FORK_FAIL	FATAL "No more process." END
# define ERROR_CONNECTION_LOST	FATAL "Connection to client lost !" END
# define ERROR_OPEN_CONF	FATAL "Cannot open configuration file !" END
# define ERROR_PARSE_CONF	FATAL "Bad syntax in configuration file !" END

#endif /* !ERRORS_H_ */
