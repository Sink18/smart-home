
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
 * ./ledtest /dev/100ask_led0 on
 * ./ledtest /dev/100ask_led0 off
 */
int main(int argc, char **argv)
{
	int fd;
	char status;
	ssize_t bytesRead;  
	
	/* 1. 判断参数 */
	if (argc != 2) 
	{
		printf("Usage: %s <dev> <on | off>\n", argv[0]);
		return -1;
	}

	/* 2. 打开文件 */
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("can not open file %s\n", argv[1]);
		return -1;
	}

	// /* 3. 写文件 */
	// if (0 == strcmp(argv[2], "on"))
	// {
	// 	status = 1;
	// 	write(fd, &status, 1);
	// }
	// else
	// {
	// 	status = 0;
	// 	write(fd, &status, 1);
	// }

	/* 3. 读文件以获取LED状态 */  
    bytesRead = read(fd, &status, 1); // 读取一个字节的LED状态  
    if (bytesRead == -1)  
    {  
        perror("can not read LED status");  
        close(fd);  
        return -1;  
    }  
  
    /* 4. 输出LED状态 */  
    if (status)  
    {  
        printf("LED is on\n");  
    }  
    else  
    {  
        printf("LED is off\n");  
    }  
  
	
	close(fd);
	
	return 0;
}


