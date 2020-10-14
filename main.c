#include "libasm.h"

void	check_ft_tests()
{
	char    *buff;

    	buff = malloc(sizeof(char) * 1);
	printf("####################### FT_STRLEN ##########################\n");
	printf("str = \"%s\" \n", "");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen(""));
	printf("%-20s: \"%zu\"\n", "ft_strlen",  ft_strlen(""));
	printf("------------------------------------------------------------\n");
	printf("str = \"%s\" \n", "Hola Mundo!");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen("Hola Mundo!"));
	printf("%-20s: \"%zu\"\n", "ft_strlen",  ft_strlen("Hola Mundo!"));
	printf("------------------------------------------------------------\n");
	printf("str = \"%s\" \n", "0123456789");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen("0123456789"));
	printf("%-20s: \"%zu\"\n", "ft_strlen",  ft_strlen("0123456789"));
	printf("------------------------------------------------------------\n\n");
	printf("####################### FT_STRCMP ##########################\n");
	printf("str1 = \"%s\"\nstr2 = \"%s\"\n", "", "");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("",  ""));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("",  ""));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola", "hola");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola",  "hola"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola",  "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola mundo", "hola");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola mundo",  "hola"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola mundo",  "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola", "hola buenas");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola",  "hola buenas"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola",  "hola buenas"));
	printf("------------------------------------------------------------\n\n");
	printf("####################### FT_STRDUP ##########################\n");
	printf("str = \"%s\" \n", "");
	printf("%-20s: \"%s\"\n", "strdup",  strdup(""));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup(""));
	printf("------------------------------------------------------------\n");
	printf("str = %s \n", "AmongUs");
	printf("%-20s: \"%s\"\n", "strdup",  strdup("AmongUs"));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup("AmongUs"));
	printf("------------------------------------------------------------\n");
	printf("str = %s \n", "coronavirus :(");
	printf("%-20s: \"%s\"\n", "strdup",  strdup("coronavirus :("));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup("coronavirus :("));
	printf("------------------------------------------------------------\n");
	printf("str = %s\n\nstrdup =\n%s\nft_strdup =\n%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc sed sagittis ligula. Sed sed egestas diam, quis lacinia justo. Vivamus et dolor et diam porttitor.",
		strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc sed sagittis ligula. Sed sed egestas diam, quis lacinia justo. Vivamus et dolor et diam porttitor."),
		ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc sed sagittis ligula. Sed sed egestas diam, quis lacinia justo. Vivamus et dolor et diam porttitor."));
	printf("------------------------------------------------------------\n\n");
	printf("####################### FT_STRCPY ##########################\n");
	printf("str = %s\nstrcpy = %s  ft_strcpy = %s\n", "Hola Mundo", strcpy(buff, "Hola Mundo"), ft_strcpy(buff, "Hola Mundo"));
	printf("------------------------------------------------------------\n");
	printf("str = %s\n\nstrcpy =\n%s\nft_strcpy =\n%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vitae tincidunt quam. Sed quis mollis metus. Phasellus purus erat, commodo non vulputate vel, tincidunt ut nunc. Vivamus ac elementum diam. Orci varius natoque penatibus et magnis dis parturient montes egestas.",
		strcpy(buff, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vitae tincidunt quam. Sed quis mollis metus. Phasellus purus erat, commodo non vulputate vel, tincidunt ut nunc. Vivamus ac elementum diam. Orci varius natoque penatibus et magnis dis parturient montes egestas."),
		ft_strcpy(buff, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vitae tincidunt quam. Sed quis mollis metus. Phasellus purus erat, commodo non vulputate vel, tincidunt ut nunc. Vivamus ac elementum diam. Orci varius natoque penatibus et magnis dis parturient montes egestas."));
	printf("------------------------------------------------------------\n\n");
}

void	check_ft_write()
{
	char	buffer[604] = "In measure theory, a branch of mathematics, the Lebesgue measure, named after French mathematician Henri Lebesgue,\nis the standard way of assigning a measure to subsets of n-dimensional Euclidean space. For n = 1, 2, or 3, it\ncoincides with the standard measure of length, area, or volume. In general, it is also called n-dimensional\nvolume, n-volume, or simply volume.[1] It is used throughout real analysis, in particular to define Lebesgue\nintegration. Sets that can be assigned a Lebesgue measure are called Lebesgue-measurable; the measure of the\nLebesgue-measurable set A is here denoted by λ(A).";
	int 	fd;
	int 	rlibc;
	int		rlibasm;

	printf("######################## FT_WRITE ##########################\n");
	printf("========================= Text try ========================>\n");
	fd = open("write.txt", O_WRONLY);
	rlibc = write(fd, buffer, 603);
	printf("%-20s: \"%d\"\n", "write", rlibc);		
	close(fd);
	
	fd = open("write.txt", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 603);
	printf("%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);
	printf("------------------------------------------------------------\n");

	printf("======================== Crash try ========================>\n");
	fd = open("wrong", O_WRONLY);
	rlibc = write(fd, buffer, 603);
	perror("write errno");
	printf("%-20s: \"%d\"\n", "write", rlibc);	
	close(fd);
	printf("\n");
	
	errno = 100;
	fd = open("wrong", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 603);
	perror("ft_write errno");
	printf("%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);
	printf("------------------------------------------------------------\n");
	
	printf("======================== Screen try =======================>\n");
	printf("\n");
	rlibc = write(1, buffer, 603);
	printf("\n%-20s: \"%d\"\n\n", "write", rlibc);
	close(fd);
	
	rlibasm = ft_write(1, buffer, 603); 
	printf("\n%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);	
	printf("\n");
}

void	check_ft_read()
{
	int		fd;
	int		rlibc;
	int		rlibasm;
	char	buffer[900];

	printf("######################## FT_READ ###########################\n");
	printf("====================== Open field try =====================>\n");
	fd = open("main.c", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "read", rlibc);
	close(fd);
	fd = open("main.c", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("------------------------------------------------------------\n");
	printf("========================= Text try ========================>\n");
	fd = open("hola.txt", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	close(fd);
	printf("%-20s: \"%d\"\n", "read", rlibc);
	fd = open("hola.txt", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 50);
	printf("%-20s: \"%d\"\n", "ft_read", rlibc);
	close(fd);
	printf("------------------------------------------------------------\n");
	printf("======================== Crash try ========================>\n");
	printf("\n");
	fd = open("wrong", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	perror("read errno");
	printf("%-20s: \"%d\"\n", "read", rlibc);
	close(fd);
	printf("\n");	
	errno = 100;
	fd = open("wrong", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	perror("ft_read errno");
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("\n");
	printf("------------------------------------------------------------\n");
	printf("======================== Screen try =======================>\n");
	printf("\n");
	rlibc = read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "read", rlibc);	
	close(fd);
	printf("\n");	
	rlibasm = ft_read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("------------------------------------------------------------\n\n");

}

int main(void)
{
	check_ft_tests();
	check_ft_write();
	check_ft_read();
		return (0);
}
