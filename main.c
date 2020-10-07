/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:54:21 by agianico          #+#    #+#             */
/*   Updated: 2020/10/07 17:09:07 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_write(void)
{
	char *hello_world;
	char *empty;

	hello_world = "Coucou\n";
	empty = "";
	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(-7, NULL, 7));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(-7, NULL, 7));
}

void	check_read(void)
{
	int		fd;
	char	buff1[891];
	int		ret;

	fd = open("main.c", O_RDONLY);
	ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	check_read_aux(fd, read(fd, buff1, 890), buff1);
}

void	check_read_aux(int fd, int ret, char *buff1)
{
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
}

void	check_strdup(void)
{
	char *save;

	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", "Hello world !");
	save = strdup("Hello world !");
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save = ft_strdup("Hello world !");
	printf("%-20s: \"%s\"\n", "libasm", save);
	free(save);
	save = NULL;
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "");
	save = strdup("");
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save = ft_strdup("");
	printf("%-20s: \"%s\"\n", "libasm", save);
	free(save);
	save = NULL;
	printf("\n");
}

void	check_strlen(void)
{
	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", "");
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(""));
	printf("%-20s: %zu\n", "libasm", ft_strlen(""));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "Hello world !");
	printf("%-20s: 13\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen("Hello world !"));
	printf("%-20s: %zu\n", "libasm", ft_strlen("Hello world !"));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "abcdefghijklmnopqrstuvwxyz");
	printf("%-20s: 26\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("%-20s: %zu\n", "libasm", ft_strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("\n");
}

void	clear_buffer(char *buffer, int size)
{
	int i;

	i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void	check_strcpy(void)
{
	char buffer[30];

	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", "");
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n\n", "libasm", ft_strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "char []", "Hello world !");
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, "Hello world !"));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n\n", "libasm", ft_strcpy(buffer, "Hello world !"));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "char []", "abcdefghijklmnopqrstuvwxyz");
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer,
	"abcdefghijklmnopqrstuvwxyz"));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n\n", "libasm", ft_strcpy(buffer,
	"abcdefghijklmnopqrstuvwxyz"));
	clear_buffer(buffer, 30);
}

void	check_strcmp(void)
{
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", "Hola buenas");
	printf("%-20s: \"%s\"\n", "compared to", "Hola qué tal");
	printf("%-20s: \"%d\"\n", "libc", strcmp("Hola buenas", "Hola qué tal"));
	printf("%-20s: \"%d\"\n\n", "libasm",
	ft_strcmp("Hola buenas", "Hola qué tal"));
	printf("%-20s: \"%s\"\n", "char *", "Hola buenas");
	printf("%-20s: \"%s\"\n", "compared to", "Hola buenas");
	printf("%-20s: \"%d\"\n", "libc", strcmp("Hola buenas", "Hola buenas"));
	printf("%-20s: \"%d\"\n\n", "libasm",
	ft_strcmp("Hola buenas", "Hola buenas"));
	printf("%-20s: \"%s\"\n", "char *", "Hola buenas");
	printf("%-20s: \"%s\"\n", "compared to", "");
	printf("%-20s: \"%d\"\n", "libc", strcmp("Hola buenas", ""));
	printf("%-20s: \"%d\"\n\n", "libasm", ft_strcmp("Hola buenas", ""));
}

int		main(void)
{
	errno = 0;
	check_write();
	check_read();
	check_strdup();
	check_strlen();
	check_strcpy();
	check_strcmp();
}
