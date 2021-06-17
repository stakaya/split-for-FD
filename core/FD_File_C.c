#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SEP  700000
#define  FD  1400000


long FD_File_C(char*F_Path)
{
    FILE *Rfp;
    FILE *Wfp;
    char Work[1000000];
    char R_File  [256 +1];
    char W_File  [256 +1];
    char File_Num[2];
    char FdCnt;
    int  FileLen;
    int  Cnt;
    long Len;
    long E_Read;
    long E_Flg;
    memset(R_File,'\0',sizeof(R_File));
    memset(W_File,'\0',sizeof(W_File));
    memcpy(R_File,F_Path,sizeof(R_File));
    memcpy(W_File,F_Path,sizeof(W_File));
    memset(File_Num,'\0',sizeof(File_Num));
    memset(Work,'\0',sizeof(Work));

    if(( Rfp = fopen( R_File,"rb")) == NULL )
    {
        exit(0);
    }

    fseek( Rfp,0L,SEEK_END );
    Len    = ftell( Rfp );
    E_Read = Len % FD;
    E_Flg  = Len / FD;
    fseek( Rfp,0L,SEEK_SET );
    FdCnt = '1';
    File_Num[0] = FdCnt;
    FileLen = strlen(W_File);
    memcpy(W_File + FileLen ,File_Num,1);

    for( Cnt = 0  ; Cnt < E_Flg ; Cnt++ )
    {
        if (( Wfp = fopen( W_File, "wb")) == NULL)
        {
            fclose(Rfp);
            exit(0);
        } 
        fread(Work,SEP,1,Rfp);
        fwrite(Work,SEP,1,Wfp); 
        fread(Work,SEP,1,Rfp);
        fwrite(Work,SEP,1,Wfp); 
        FdCnt++;
        fclose(Wfp);
        FileLen = strlen(W_File)-1;
        File_Num[0] = FdCnt;
        memcpy(W_File + FileLen ,File_Num,1);
    }

    if (( Wfp = fopen( W_File, "wb")) == NULL)
    {
        fclose(Rfp);
        exit(0);
    } 
    if(sizeof(Work) < E_Read)
    {
        fread(Work,sizeof(Work) ,1,Rfp);
        fwrite(Work,sizeof(Work) ,1,Wfp); 
        E_Read = E_Read - sizeof(Work);
        fread(Work,E_Read ,1,Rfp);
        fwrite(Work,E_Read ,1,Wfp); 
    }
    else
    {
        fread(Work,E_Read,1,Rfp);
        fwrite(Work,E_Read,1,Wfp); 
    }
    fclose(Rfp);
    fclose(Wfp);
    return(1);
}


