
#include "./includes/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <locale.h>

//int ft_printf(char const *str, ...);

int	main(void)
{
	setlocale(LC_ALL, "");

	int	ret1;
	int	ret2;

//	ret1 = ft_printf("[%-06.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
//	ret2 = printf("[%-06.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
//	ret1 = ft_printf("[%-026.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
//	ret2 = printf("[%-026.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	ret1 = ft_printf("[%-026S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	ret2 = printf("[%-026S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	printf("retour : [%d] [%d]\n\n", ret1, ret2);

	ret1 = ft_printf("[%026S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	ret2 = printf("[%026S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	printf("retour : [%d] [%d]\n\n", ret1, ret2);

	ret1 = ft_printf("[%6.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	ret2 = printf("[%6.4S]\n", L"🧀 🧀 🧀 🧀 🧀 ");
	printf("retour : [%d] [%d]\n\n", ret1, ret2);

	return (0);
}
