#include <string.h>
#include <stdio.h>
#include <malloc.h>





int main(int ac,char **av)
{
    FILE* ptrFile = fopen(av[1] , "r");/*open a file to read from the argument string*/
    char mystring[255], zv[254];
    int* lenta;
    int n = 0, i = 0;/*i-position in the tape n - number of cells in the tape*/
    int st; /*position in file*/

    lenta = (int*)malloc(i * sizeof(int));/*allocate memory for the tape*/
    if (lenta==NULL)
    {
        printf ("!!! Out of memory!!!\n\n");
        return 0;
    }
    else
    {


        lenta[i] = 0;
        n=sizeof(lenta) / sizeof(lenta[0]); /* number of cells in a tape*/


        if (ptrFile == NULL)
        {
            printf ("!!! Error opening file !!!\n\n");
        }
        else
        {
            while (fscanf(ptrFile,"%s", mystring) != EOF)
            {
                if (strcmp(mystring,"movl")==0) /* go left*/
                {
                    if (i>0)
                    {
                        i--;
                        printf ("%s\n\n", mystring);
                    }
                    else
                    {
                        printf ("%s\n\n", mystring);
                        printf ("!!! It is impossible to move!!!\n\n");
                    }
                }



                if (strcmp(mystring, "movr")==0) /* go  right*/
                {
                    if (i == n-1) /*if the right is empty*/
                    {
                        i++;
                        n++;
                        lenta = realloc(lenta, i); /*increase memory and add one cell*/
                        if (lenta==NULL)
                        {
                            printf ("!!!Out of memory!!!");
                            return 0;
                        }
                        else
                        {
                            lenta[i] = 0; /*fill a new cell with zero */
                            printf ("%s\n\n", mystring);
                        }
                    }
                    else
                    {
                        i++;
                        printf ("%s\n\n", mystring);
                    }
                }



                if (strcmp(mystring, "inc")==0) /*incrimination  */
                {
                    if (lenta[i] < 255)
                    {
                        lenta[i]++; /* increase by 1*/
                        printf ("%s\n\n", mystring);
                    }
                    else
                    {
                        printf ("%s\n", mystring);
                        printf("In the cell - 255 (zero) !!!\n\n");
                        lenta[i] = 0;
                    }
                }



                if (strcmp(mystring, "dec")==0) /*decrement by 1 */
                {
                    if (lenta[i] > 0)
                    {
                        lenta[i]--;
                        printf ("%s\n\n", mystring);
                    }
                    else
                    {
                        printf ("%s\n", mystring);
                        printf("In the cell - 0 !!!\n\n");
                    }
                }



                if (strcmp(mystring, "print")==0)
                {
                    printf ("%s\n", mystring);
                    printf ("%d\n\n", lenta[i]);
                }



                if (strcmp(mystring, "printc")==0)
                {
                    printf ("%s\n", mystring);
                    printf ("%c\n\n", lenta[i]);
                }



                if (strcmp(mystring, "get")==0)
                {
                    printf ("%s\n\n", mystring);
                    printf ("Enter value 0-255\n");
                    scanf ("%d", &lenta[i]);
                }



                if (mystring[0]== '*') /* compare 1 character */
                {

                    fgets(zv, 254, ptrFile);
                    printf("*%s\n\n", zv);
                }

                if (strcmp(mystring, "end")==0)
                {
                   if (lenta[i] == 0)
                        {
                            printf ("%s\n\n", mystring);
                            return 0;
                        }
                    else
                        {
                            fseek(ptrFile, st, 0);
                            fscanf(ptrFile,"%s", mystring);
                            if ((strcmp(mystring, "end")==0) && lenta[i] > 0 )
                                {
                                    printf ("END after BEGIN - Error of infinite loop!!!\n\n");
                                    return 1;
                                }
                            else
                                {
                                    fseek(ptrFile, st, 0);
                                }
                        }
                }

                if (strcmp(mystring, "begin")==0)
                {
                    printf ("%s\n\n", mystring);
                    st = ftell(ptrFile); /* remember the position in the file after begin*/
                    if(lenta[i]==0)
                    {
                        do
                        {
                            fscanf(ptrFile,"%s", mystring);

                        }
                        while (strcmp(mystring, "end")!=0);


                        if (lenta[i] == 0)
                        {
                            printf ("%s\n\n", mystring);
                            return 0;
                        }
                        else
                        {
                            fseek(ptrFile, st, 0);
                            fscanf(ptrFile,"%s", mystring);
                            printf ("%s\n\n", mystring);

                            if ((strcmp(mystring, "end")==0) && lenta[i] > 0 )
                                {
                                    printf ("END after BEGIN - Error of infinite loop!!!\n\n");
                                    return 1;
                                }
                            else
                                {
                                    fseek(ptrFile, st, 0);
                                }
                        }
                    }
                }
            }
            free (lenta);
            fclose (ptrFile);
        }
       return 0;
    }
}


