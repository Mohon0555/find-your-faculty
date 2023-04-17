#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct std_sinup
{
    char name[10];
    int ID[10];
    char Dep[5];
    int Pass[8];

};

struct std_login
{
    int ID[10];
    int Pass[8];

};

struct fac_sinup
{
    char Name[10];
    int ID[5];
    char Dep[5];
    int Pass[8];


    int s_day_S1[10]; // 0800-0940
    int s_day_S2[10]; //1310-1440

    int m_day_S1[10];
    int m_day_S2[10];

    int t_day_S1[10];
    int t_day_S2[10];

    int w_day_S1[10];
    int w_day_S2[10];

    int th_day_S1[10];
    int th_day_S2[10];
};

struct fac_login
{
    int ID[5];
    int Pass[8];
};

int main()
{
    char log_sign;
    int choice;

    struct std_login stdlog;
    struct std_sinup stdsin;

    struct fac_login faclog;
    struct fac_sinup facsin;

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

        printf("Wecome To login Panel\n");

        printf("1. Student\n");
        printf("2. Faculty\n");


        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Student Login Panel\n");

            printf("Enter Your ID:");
            scanf("%d", &stdlog.ID);
            printf("Enter Your Pass:");
            scanf("%d", &stdlog.Pass);
            break;

        case 2:
            printf("Faculty Login Panel\n");

            printf("Enter Your ID:");
            scanf("%d", &stdlog.ID);
            printf("Enter Your Pass:");
            scanf("%d", &stdlog.Pass);
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
            scanf("%d", &stdsin.ID);

            printf("Enter Your Department:");
            scanf("%s", &stdsin.Dep);

            printf("Enter Your Pass:");
            scanf("%d", &stdsin.Pass);
fprintf(stdlogfile, " Name: %s \n ID: %d \n Department: %s \n Pass: %d \n", stdsin.name, stdsin.ID, stdsin.Dep, stdsin.Pass );
            break;

        case 2:
            printf("Faculty SinUp Panel\n");

            printf("Enter Your Name:");
            scanf("%s", &facsin.Name);

            printf("Enter Your ID:");
            scanf("%d", &facsin.ID);

            printf("Enter Your Department:");
            scanf("%s", &facsin.Dep);

            printf("Enter Your Pass:");
            scanf("%d", &facsin.Pass);

            printf("Enter Your SUNDAY Slot-1:");
            scanf("%d", &facsin.s_day_S1);

            printf("Enter Your SUNDAY Slot-2:");
            scanf("%d", &facsin.s_day_S2);

            printf("Enter Your MONDAY Slot-1:");
            scanf("%d", &facsin.m_day_S1);

            printf("Enter Your MONDAY Slot-2:");
            scanf("%d", &facsin.m_day_S2);

            printf("Enter Your TUESDAY Slot-1:");
            scanf("%d", &facsin.t_day_S1);

            printf("Enter Your TUESDAY Slot-2:");
            scanf("%d", &facsin.t_day_S2);

            printf("Enter Your WEDNESDAY Slot-1:");
            scanf("%d", &facsin.w_day_S1);

            printf("Enter Your WEDNESDAY Slot-2:");
            scanf("%d", &facsin.w_day_S2);

            printf("Enter Your THUSDAY Slot-1:");
            scanf("%d", &facsin.th_day_S1);

            printf("Enter Your THUSDAY Slot-2:");
            scanf("%d", &facsin.th_day_S2);

            break;
        }
        break;
    default:
        printf("Dhur miya bhagen");
    }

    return 0;
}
