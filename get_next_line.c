#include "get_next_line.h"

/**
 * @brief Returns a pointer to the
 * first occurrence of the character c in the string s.
 *
 * @param s Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* Return a pointer to the matched character
 * or NULL if the character is not found.
 */
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

/**
 * @brief Frees the heap allocated memory and assigns heap value to NULL.
 *
 * @param heap Pointer to the area of memory to free and NULL-assign
 */
static void	nullify_heap(char **heap)
{
	if (*heap && heap)
	{
		free(*heap);
		*heap = NULL;
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
		nullify_heap(heap);
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
	nullify_heap(heap);
	return (0);
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
	if (!buffer || !line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	read_bytes = (int)read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (-1);
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(heap[fd], buffer);
		nullify_heap(&heap[fd]);
		heap[fd] = tmp;
	}
	free(buffer);
	return (get_line(read_bytes, &(heap[fd]), line));
}
