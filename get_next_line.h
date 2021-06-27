#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/resource.h>

# define OPEN_MAX		RLIMIT_NOFILE
# define BUFFER_SIZE	42

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

/**
 * @brief Allocates (with malloc(3)) and returns a newstring,
 * which is the result of the concatenationof ’s1’ and ’s2’.
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* Returns the new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Returns a pointer to a new string
 * which is a duplicate of the string s.
 *
 * @param s1 Pointer to the start of the string do be copied
 * @return char* On success, returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory
 * was available, with errno set to indicate the cause of the
 * error.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
 * The substring begins at index ’start’ and is ofmaximum size ’len’.
 * @param s		The string from which to create the substring.
 * @param start	The start index of the substring in the string’s’.
 * @param len	The maximum length of the substring.
 * @return char* Returns the substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
