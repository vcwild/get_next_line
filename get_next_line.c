#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		c %= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

static void	free_heap(char **lst)
{
	if (*lst && lst)
	{
		free(*lst);
		*lst = NULL;
	}
}

static int	get_line(int read_bytes, char **heap, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (read_bytes < 0)
		return (-1);
	else if (read_bytes == 0 && *heap[0] == '\0')
	{
		*line = ft_strdup("");
		free_heap(heap);
		return (0);
	}
	while ((*heap)[i] != '\n' && (*heap)[i] != '\0')
		i++;
	*line = ft_substr(*heap, 0, i);
	if ((*heap)[i] == '\n')
	{
		tmp = ft_strdup(*heap + i + 1);
		free(*heap);
		*heap = tmp;
		return (1);
	}
	ft_strdel(heap);
	return (0);
}

static int	bad_params(int fd, char **line, char *heap, char *buffer)
{
	return (!buffer
		|| !heap[fd]
		|| !line
		|| fd < 0
		|| BUFFER_SIZE < 1);
}

int	get_next_line(int fd, char **line)
{
	int			read_bytes;
	char		*tmp;
	char		*buffer;
	static char	*heap[OPEN_MAX];

	if (!heap[fd])
		heap[fd] = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (bad_params(fd, line, heap, buffer))
		return (-1);
	read_bytes = (int)read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (-1);
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(heap[fd], buffer);
		free_heap(&heap[fd]);
		heap[fd] = tmp;
	}
	free(buffer);
	return (get_line(read_bytes, &(heap[fd]), line));
}
