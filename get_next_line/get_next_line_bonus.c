#include "get_next_line_bonus.h"

char	*return_left(char *backup)
{
	int		i;
	char	*line;
	int		count;

	if (!(*backup))
		return (NULL);
	count = 0;
	while (backup[count] != '\n' && backup[count])
		count++;
	if (backup[count] == '\n')
		count++;
	i = -1;
	line = (char *)malloc(count + 1);
	if (!line)
		return (NULL);
	while (++i < count)
		line[i] = backup[i];
	line[count] = '\0';
	return (line);
}

char	*return_right(char *backup)
{
	char	*backup_right;
	int		backup_len;
	int		backup_left_len;
	int		i;

	backup_len = ft_strlen(backup);
	backup_left_len = 0;
	while (backup[backup_left_len] != '\n' && backup[backup_left_len])
		backup_left_len++;
	if (backup[backup_left_len] == 0)
	{
		free(backup);
		return (NULL);
	}
	if (backup[backup_left_len] == '\n')
		backup_left_len++;
	backup_right = (char *) malloc(backup_len - backup_left_len + 1);
	if (!backup_right)
		return (NULL);
	i = 0;
	while (backup[backup_left_len])
		backup_right[i++] = backup[backup_left_len++];
	backup_right[i] = '\0';
	free (backup);
	return (backup_right);
}

char *read_line(int fd, char *backup)
{
    char	*temp;
	int		rb;

	rb = 1;
	temp = (char *) malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (rb > 0 && !ft_strchr(backup,'\n'))
	{
		rb = read(fd, temp, BUFFER_SIZE);
		if (rb == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[rb] = '\0';
		backup = ft_strjoin(backup, temp);
	}
	free (temp);
    return (backup);
}

char *get_next_line(int fd)
{
   char *buffer;
   static char *backup[10240];

   if (fd < 0 || BUFFER_SIZE <= 0)
   {
       return (NULL);
   }

   backup[fd] = read_line(fd,backup[fd]);
   	if (!backup[fd])
		return (NULL);
	buffer = return_left(backup[fd]);
	backup[fd] = return_right(backup[fd]);
	return (buffer);

}