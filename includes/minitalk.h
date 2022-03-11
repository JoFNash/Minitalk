#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>

typedef struct s_message
{
	int		char_code;
	size_t	counter;
}	t_message;

t_message	g_msg;

#endif