#include "ft_utf8.h"

// int	main(int ac, char **av)
// {
// 	int			size;
// 	size_t		i;
// 	char		str[101];
// 	int			ret;
// 	uint32_t	*s;

// 	if (ac == 1)
// 	{
// 		ret = read(0, str, 100);
// 		str[ret] = '\0';
// 		size = ret;
// 	}
// 	if (ac > 1)
// 	{
// 		size = ft_strlen(av[1]);
// 		ft_memcpy(str, av[1], size);
// 	}
// 	s = ft_ctou(str);
// 	i = -1;
// 	while (++i < ft_ustrlen(s))
// 	{
// 		uwrite(1, &(s[i]), 1);
// 		uwrite(1, (t_usym)"\n", 1);
// 	}
// 	uwrite(1, (t_usym)"\n", 1);
// 	return (0);
// }

int	main(int ac, char **av)
{
	int			size;
	size_t		i;
	char		str[101];
	int			ret;
	uint32_t	*s;

	if (ac == 1)
	{
		s = ft_ustrnew(100);
		ret = uread(0, s, 100);
		s[ret] = 0;
		size = ret;
	}
	if (ac > 1)
	{
		size = ft_strlen(av[1]);
		ft_memcpy(str, av[1], size);
		s = ft_ctou(str);
	}
	i = -1;
	while (++i < ft_ustrlen(s))
	{
		uwrite(1, &(s[i]), 1);
		uwrite(1, (t_usym*)"\n", 1);
	}
	free(s);
	uwrite(1, (t_usym*)"\n", 1);
	return (0);
}


// int	main(int ac, char **av)
// {
// 	int			size;
// 	size_t		i;
// 	char		*str;
// 	int			ret;
// 	uint32_t	*s;

// 	if (ac == 1)
// 	{
// 		ret = get_next_line(0, &str);
// 		// str[ret] = 0;
// 		// size = ret;
// 		s = ft_ctou(str);
// 	}
// 	if (ac > 1)
// 	{
// 		size = ft_strlen(av[1]);
// 		ft_memcpy(str, av[1], size);
// 		s = ft_ctou(str);
// 	}
// 	i = -1;
// 	while (++i < ft_ustrlen(s))
// 	{
// 		uwrite(1, &(s[i]), 1);
// 		uwrite(1, (t_usym*)"\n", 1);
// 	}
// 	uwrite(1, (t_usym*)"\n", 1);
// 	return (0);
// }
