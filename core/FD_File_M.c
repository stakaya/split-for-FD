#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SEP    700000
#define  R_MAX 1000000

long FD_File_M(char *F_Path)
{
    FILE *Rfp;
    FILE *Wfp;
    char Work[1000000];
    char R_File  [256 +1];
    char W_File  [256 +1];
    char File_Num[2];
    char FdCnt = '1';
    char *SrchP;
    int  FileLen;
    long Len;

    memset(R_File,'\0',sizeof(R_File));
    memset(W_File,'\0',sizeof(W_File));
    memset(File_Num,'\0',sizeof(File_Num));
    memset(Work,'\0',sizeof(Work));
    memcpy(R_File,F_Path,sizeof(R_File));
    memcpy(W_File,F_Path,sizeof(W_File));
    File_Num[0] = FdCnt;
    FileLen = strlen(R_File)-1;
    SrchP = strchr(W_File + FileLen,'1'); 
    *SrchP = '\0';

    if (( Wfp = fopen( W_File, "wb")) == NULL)
    {
        exit(0);
    } 
    while(1)
    {
        if(( Rfp = fopen( R_File,"rb")) == NULL )
        {
            break;
        }
        fseek( Rfp,0L,SEEK_END );
        Len    = ftell( Rfp );
        fseek( Rfp,0L,SEEK_SET );
        if( Len > R_MAX )
        {
            fread(Work,R_MAX,1,Rfp);
            fwrite(Work,R_MAX,1,Wfp); 
            Len = Len - R_MAX;
        }
        fread(Work,Len,1,Rfp);
        fwrite(Work,Len,1,Wfp); 
        fclose(Rfp);
        FdCnt++;
        FileLen = strlen(R_File) - 1;
        File_Num[0] = FdCnt;
        memcpy(R_File + FileLen ,File_Num,1);
    }

    fclose(Wfp);
    return(1);
}


