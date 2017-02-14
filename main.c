#include "./includes/ft_printf.h"
#include <stdio.h>


int main(void)
{

	ft_printf("TEST%[[BG_CSM224,SP_RST]s\n", "colors");
	ft_printf("TEST%[[FG_RED,SP_RST]s\n", "colors");
	return 0;
}
