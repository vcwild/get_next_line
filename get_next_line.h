#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define OPEN_MAX		_SC_OPEN_MAX
# define BUFFER_SIZE	32

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/**
 * @brief Write a function which returns a line
 * read from a file descriptor, without the newline.
 *
 * @param fd	file descriptor for reading
 * @param line	the value of what has been read
 * @return int	Returns 1 if a line has been read.
 *				Returns 0 if EOF has been reached.
 *				Returns -1 if an error has happened.
 */
int		get_next_line(int fd, char **line);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

#endif
