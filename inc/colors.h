/*
** colors.h for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 09:41:00 2009 valentin horner
** Last update Fri Apr 23 15:49:28 2010 Valentin Horner
*/

#ifndef COLORS_H_
# define COLORS_H_
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
# define C_GRAY		"\033[30m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_YELLOW	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_PURPLE	"\033[35m"
# define C_CYAN		"\033[36m"
# define C_WHITE	"\033[1;37m"
# define DRAW_MODE	"\033(0"
# define TEXT_MODE	"\033(B"
/*
** Colorset Strings
*/
# define BG_MODE	DRAW_MODE C_BG_BLUE C_CYAN
# define TITLE_BG_MODE	TEXT_MODE C_BG_BLUE C_CYAN
# define FG_MODE	DRAW_MODE C_BG_GRAY C_GRAY
# define TITLE_FG_MODE	TEXT_MODE C_BG_GRAY C_GRAY
# define FG_LIGHT_MODE	DRAW_MODE C_BG_GRAY C_WHITE
# define SHADOW_MODE	DRAW_MODE C_BG_BLACK
# define RESET_MODE	TEXT_MODE C_BG_BLACK C_WHITE
# define FOLDER_FG_MODE	TEXT_MODE C_BG_GRAY C_RED
# define FILE_FG_MODE	TEXT_MODE C_BG_GRAY C_BLUE
/*
** Colorset Flags
*/
# define F_BG_MODE		-1
# define F_TITLE_BG_MODE	-2
# define F_FG_MODE		-3
# define F_TITLE_FG_MODE	-4
# define F_FG_LIGHT_MODE	-5
# define F_SHADOW_MODE		-6
# define F_FOLDER_FG_MODE	-7
# define F_FILE_FG_MODE		-8

/*
** Used to move cursor on the top left of the screen
*/
# define        GOTO_BEGIN      "\033[0;0f"

/*
** Used to control terminal window
*/
# define	ESC		"\033"
# define	CSI		ESC "["
# define	RESIZE		CSI " 1 t"

#endif /* !COLORS_H_ */
