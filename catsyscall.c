/*
get file from args open print to fd 1 close file and repete
*/
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char errmsg[] = "error: failed to open file ";
	int fd = -1;
	char c = 0;
	if(argc == 1){// for no file arguments fd 0 is stdin
		while(read(0, &c, 1))
			write(1, &c, 1);
	}
	else{
		while(--argc > 0){
			if((fd = open(argv[argc], O_RDONLY)) == -1){// if open fails to open a file go to next iteration of loop
				write(2, errmsg, sizeof(errmsg)/ sizeof(char));
				for(int i = 0; argv[argc][i] != '\0'; ++i)
					write(2, &(argv[argc][i]), 1);
				write(2, "\n", 1);
				continue;
			}
			while(read(fd, &c, 1))
				write(1, &c, 1);
		}
	}
	return 0;
}
