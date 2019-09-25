#include "monty.h"
int _isdigit(char *s)
{
	int i = 0;

	while(s[i])
	{
		if (s[i] < 47 || s[i] > 58 )
			return (0);
		i++;
	}
        return (1);
}
