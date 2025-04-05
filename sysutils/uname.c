#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

int main(void) 
{
    struct utsname info;
    if (uname(&info) == -1)
        perror("uname failed");;
    
    printf("%-20s %s\n", "System name:", info.sysname);
    printf("%-20s %s\n", "Host name", info.nodename);
    printf("%-20s %s\n","Release:", info.release);
    printf("%-20s %s\n", "Version:", info.version);
    printf("%-20s %s\n", "Machine:", info.machine);
    printf("%-20s %s\n", "Domain name:", info.__domainname);

    return EXIT_SUCCESS; 
}
