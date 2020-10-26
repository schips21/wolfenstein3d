#include "libft.h"

char	*ft_strchr_n(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

int		ft_return(int flag, char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3 && flag != 0)
		free(s3);
	return (flag);
}

int		process_saved_line(char **out, char **saved_line)
{
	char *tmp;

	if (*saved_line != NULL)
	{
		if (!(tmp = ft_strdup(*saved_line)))
			return (ft_return(-1, *saved_line, 0, 0));
		free(*saved_line);
		if ((*saved_line = ft_strchr_n(tmp)))
		{
			*saved_line[0] = '\0';
			if (!(*saved_line = ft_strdup(*saved_line + 1)))
				return (ft_return(-1, tmp, 0, 0));
			*out = ft_strdup(tmp);
		}
		else
			*out = ft_strdup(tmp);
		free(tmp);
	}
	else
		*out = ft_calloc(1, sizeof(char));
	if (!*out)
		return (ft_return(-1, *saved_line, 0, 0));
	return (1);
}

int		reading(int fd, char **out, char **s)
{
	char	*tmp;
	char	*tmp1;
	int		tmp_len;

	while (!*s)
	{
		if (!(tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
		if ((tmp_len = read(fd, tmp, BUFFER_SIZE)) < 1)
			return (ft_return(tmp_len, tmp, *s, *out));
		if ((*s = ft_strchr_n(tmp)))
		{
			*s[0] = '\0';
			if (!(*s = ft_strdup(*s + 1)))
				return (ft_return(-1, tmp, *s, *out));
		}
		tmp1 = *out;
		if (!(*out = ft_strjoin(*out, tmp)))
			return (ft_return(-1, tmp, *s, tmp1));
		free(tmp);
		free(tmp1);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*saved_line;
	char			*out;
	int				flag;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((flag = process_saved_line(&out, &saved_line)) < 1)
		return (flag);
	if (saved_line == NULL)
		if ((flag = reading(fd, &out, &saved_line)) < 0)
			return (flag);
	*line = out;
	return (flag);
}
