#include <stdio.h>                      
#include <string.h>                     
extern long FD_File_M(char *);
extern long FD_File_C(char *);

long FD_File_Cntl(char *c_REC,char *c_FileName)
{
    long l_RTC;

    switch(*c_REC)                  
    {
        case 'M':                 
            l_RTC = FD_File_M(c_FileName);
            break;

        case 'C':                 
            l_RTC = FD_File_C(c_FileName);
            break;

        default:
            l_RTC = -1;
            break;
    }
    return(l_RTC);                  
} 
