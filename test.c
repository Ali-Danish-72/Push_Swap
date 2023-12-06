#include "../libft/libft.h"

int main(){
	int fd = open("output.txt", O_RDONLY);
	char *line = get_next_line(fd);
	int greater = 0;
	int lesser = 0;
	while (line)
	{
		if (atoi(line) > 5500)
			greater++;
		else
			lesser++;
		free(line);
		line = get_next_line(fd);
	}
	printf("%d cases above 5500 and %d cases below 5500", greater, lesser);
}