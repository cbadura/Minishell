
#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "./libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_arg {
	int		c;
	char	**v;
	char	**envp;
}	t_arg;

void	ft_error(char *str);
char	*valid_path(char **allpath, char *cmd);
char	*get_path(char *cmd, char *envp[]);
char	*get_next_line(int fd);
char	*ft_substr_mod(char const *s, unsigned int start, size_t len);
char	*ft_gnljoin(char *s1, char *s2);
void	medic(t_arg arg);

#endif
