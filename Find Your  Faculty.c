#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct std_sinup
{
    char name[10];
    char id[10];
    char Dep[5];
    char pass[8];

};

struct std_login
{
    char ID[10];
    char Pass[8];

};

struct fac_sinup
{
    char name[10];
    char id[5];
    char dep[5];
    char pass[8];


    char s_day_s1[10];
    char s_day_s2[10];

    char m_day_s1[10];
    char m_day_s2[10];

    char t_day_s1[10];
    char t_day_s2[10];

    char w_day_s1[10];
    char w_day_s2[10];

    char th_day_s1[10];
    char th_day_s2[10];
};

struct fac_login
{
    char ID[5];
    char Pass[8];
};

int main()
{
    char log_sign;
    char choice;

    int found=0;

    char stdlogin_id[10];
    char stdlogin_pass[8];

    char faclogin_ID[10];
    char faclogin_Pass[8];

    struct std_login stdlog;
    struct std_sinup stdsin;

    struct fac_login faclog;
    struct fac_sinup facsin;

    char facName[10];

    printf("Find Your Faculty\n");

    printf("1. Login\n");
    printf("2. SingUp\n");

    scanf("%c", &log_sign);

    FILE *stdlogfile;
    FILE *faclogfile;

    stdlogfile=fopen("stdlogfile.txt", "a+");
    faclogfile=fopen("faclogfile.txt", "a+");

    switch(log_sign)
    {
    case '1':

        printf("Welcome To login Panel\n");

        printf("1. Student\n");
        printf("2. Faculty\n");


        scanf("%d", &choice);
        switch(choice)
        {
        case 1:

            printf("Student Login Panel\n");

            printf("Enter Your ID:");
            scanf("%s", &stdlogin_id);
            printf("Enter Your Pass:");
            scanf("%s", &stdlogin_pass);

            stdlogfile=fopen("stdlogfile.txt", "a+");


            while(fscanf(stdlogfile," Name: %s \n ID: %s \n Department: %s \n Pass: %s \n", stdsin.name, stdsin.id, stdsin.Dep, stdsin.pass)!= EOF)
            {
                if(strcmp(stdlogin_id,stdsin.id)==0)
                {
                    if(strcmp(stdlogin_pass,stdsin.pass)==0)
                    {
                        printf("Welcome %s to login panel\n",stdsin.name );
                        found =1;

                        printf("Enter Your Faculy Name:");
                        scanf("%s",&facName);

                        faclogfile=fopen("faclogfile.txt", "a+");

                        while(fscanf(faclogfile, "Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2)!=EOF)
                        {
                            if(strcmp(facName,facsin.name)==0)
                            {
                                printf("Your faculty ID: %s \n Dep: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.id, facsin.dep, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2);
                                break;
                            }

                            else
                            {
                                printf("\nInvalid faculty name!");
                                break;
                            }
                        }

                    }
                    else
                    {
                        printf("\nInvalid Password!");
                        found =1;
                    }
                }
            }
            if(!found)
            {
                printf("Invalid ID or password. Please try again.\n");

            }

            fclose(stdlogfile);
            break;

        case 2:
            printf("Faculty Login Panel\n");

            printf("Enter Your ID:");
            scanf("%s", &faclogin_ID);
            printf("Enter Your Pass:");
            scanf("%s", &faclogin_Pass);

            faclogfile=fopen("faclogfile.txt", "a+");

            while(fscanf(faclogfile, "Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2)!= EOF)

            {
                if(strcmp(faclogin_ID,facsin.id)==0)
                {
                    if(strcmp(faclogin_Pass,facsin.pass)==0)
                    {
                        printf("Welcome %s to login panel\n",facsin.name);
                        found =1;
                        break;
                    }
                    else
                    {
                        printf("\nInvalid Password!");
                        found =1;
                    }
                }
            }
            if(!found)
            {
                printf("Invalid ID or password. Please try again.\n");

            }

            fclose(faclogfile);
            break;
        }
        break;
    case '2':
        printf("Welcome To SinUp panel\n");

        printf("1. Student\n");
        printf("2. Faculty\n");

        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Student SinUp Panel\n");

            printf("Enter Your Name:");
            scanf("%s", &stdsin.name);

            printf("Enter Your ID:");
            scanf("%s", &stdsin.id);

            printf("Enter Your Department:");
            scanf("%s", &stdsin.Dep);

            printf("Enter Your Pass:");
            scanf("%s", &stdsin.pass);

            fprintf(stdlogfile, " Name: %s \n ID: %s \n Department: %s \n Pass: %s \n", stdsin.name, stdsin.id, stdsin.Dep, stdsin.pass );
            break;

        case 2:
            faclogfile=fopen("faclogfile.txt", "a+");
            printf("Faculty SinUp Panel\n");

            printf("Enter Your Name:");
            scanf("%s", &facsin.name);

            printf("Enter Your ID:");
            scanf("%s", &facsin.id);

            printf("Enter Your Department:");
            scanf("%s", &facsin.dep);

            printf("Enter Your Pass:");
            scanf("%s", &facsin.pass);

            printf("Enter Your SUNDAY Slot-1:");
            scanf("%s", &facsin.s_day_s1);

            printf("Enter Your SUNDAY Slot-2:");
            scanf("%s", &facsin.s_day_s2);

            printf("Enter Your MONDAY Slot-1:");
            scanf("%s", &facsin.m_day_s1);

            printf("Enter Your MONDAY Slot-2:");
            scanf("%s", &facsin.m_day_s2);

            printf("Enter Your TUESDAY Slot-1:");
            scanf("%s", &facsin.t_day_s1);

            printf("Enter Your TUESDAY Slot-2:");
            scanf("%s", &facsin.t_day_s2);

            printf("Enter Your WEDNESDAY Slot-1:");
            scanf("%s", &facsin.w_day_s1);

            printf("Enter Your WEDNESDAY Slot-2:");
            scanf("%s", &facsin.w_day_s2);

            printf("Enter Your THUSDAY Slot-1:");
            scanf("%s", &facsin.th_day_s1);

            printf("Enter Your THUSDAY Slot-2:");
            scanf("%s", &facsin.th_day_s2);

            fprintf(faclogfile, "Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s \n",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2);
            break;
        }
        break;
    default:
        printf("Dhur miya bhagen");
    }
    return 0;
}
