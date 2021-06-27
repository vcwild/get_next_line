#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*buffer;
	char	*pos;

	size = ft_strlen(s1) + 1;
	buffer = malloc((size) * sizeof(char));
	if (buffer == NULL && s1 == NULL)
		return (NULL);
	pos = buffer;
	while (size--)
		*buffer++ = *s1++;
	return (pos);
}

char	*ft_strcpy(char *dest, char *src)
{
	char *pos;

	pos = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (pos);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dest[len] && len < size)
		len++;
	i = len;
	while (src[len - i] && (len + 1) < size)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}
