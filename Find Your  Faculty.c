#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct std_sinup
{
    char name[20];
    char id[10];
    char Dep[5];
    char pass[8];

};
int std_sinup_fun()
{
    struct std_sinup stdsin;
    FILE *stdlogfile;

    printf("\tEnter Your Name:");
    scanf("%s", &stdsin.name);

    printf("\tEnter Your ID:");
    scanf("%s", &stdsin.id);

    printf("\tEnter Your Department:");
    scanf("%s", &stdsin.Dep);

    printf("\tEnter Your Pass:");
    scanf("%s", &stdsin.pass);

    stdlogfile=fopen("stdlogfile.txt", "a+");
    fprintf(stdlogfile, " Name: %s \n ID: %s \n Department: %s \n Pass: %s \n", stdsin.name, stdsin.id, stdsin.Dep, stdsin.pass );
}

struct fac_sinup
{
    char name[20];
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

struct fac_slot
{
    char facName[10];
    char stdName[10];
    char stdID[10];
    char slote[10];
};


int fac_sinup_fun()
{
    struct fac_sinup facsin;
    FILE *faclogfile;
    faclogfile=fopen("faclogfile.txt", "a+");
    printf("\t Enter Your Name:");
    scanf("%s", &facsin.name);
    printf("\t Enter Your ID:");
    scanf("%s", &facsin.id);
    printf("\t Enter Your Department:");
    scanf("%s", &facsin.dep);
    printf("\t Enter Your Pass:");
    scanf("%s", &facsin.pass);
    printf("\t Enter Your SUNDAY Slot-1:");
    scanf("%s", &facsin.s_day_s1);
    printf("\t Enter Your SUNDAY Slot-2:");
    scanf("%s", &facsin.s_day_s2);
    printf("\t Enter Your MONDAY Slot-1:");
    scanf("%s", &facsin.m_day_s1);
    printf("\t Enter Your MONDAY Slot-2:");
    scanf("%s", &facsin.m_day_s2);
    printf("\t Enter Your TUESDAY Slot-1:");
    scanf("%s", &facsin.t_day_s1);
    printf("\t Enter Your TUESDAY Slot-2:");
    scanf("%s", &facsin.t_day_s2);
    printf("\t Enter Your WEDNESDAY Slot-1:");
    scanf("%s", &facsin.w_day_s1);
    printf("\t Enter Your WEDNESDAY Slot-2:");
    scanf("%s", &facsin.w_day_s2);
    printf("\t Enter Your THUSDAY Slot-1:");
    scanf("%s", &facsin.th_day_s1);
    printf("\t Enter Your THUSDAY Slot-2:");
    scanf("%s", &facsin.th_day_s2);
    fprintf(faclogfile, " Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s \n",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2);
}

int main()
{
    char log_sign;
    char choice;
    char slot;

    int found=0;

    char stdlogin_id[10];
    char stdlogin_pass[8];

    char faclogin_ID[10];
    char faclogin_Pass[8];


    struct std_sinup stdsin;
    struct fac_sinup facsin;

    struct fac_slot facslot;

    char facName[10];
    printf("\n\t+--------------------------------+\n ");
    printf("\t|\t FIND YOUR FACULY \t |");
    printf("\n\t+--------------------------------+\n\n ");

    printf("\t 1. Login\n");
    printf("\t 2. SingUp\n");
    printf("\n\t Enter Your Choice: ");

    scanf("%c", &log_sign);

    FILE *stdlogfile;
    FILE *faclogfile;
    FILE *facslote;

    stdlogfile=fopen("stdlogfile.txt", "a+");
    faclogfile=fopen("faclogfile.txt", "a+");

    facslote=fopen("facslote.txt", "a+");

    switch(log_sign)
    {
    case '1':

        printf("\n\t+----------------------------------------+\n ");
        printf("\t|\t  Welcome To login Panel \t |");
        printf("\n\t+----------------------------------------+\n\n ");

        printf("\t1. Student\n");
        printf("\t2. Faculty\n");

        printf("\n\tEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:

            printf("\n\t+--------------------------------+\n ");
            printf("\t|\tStudent Login Panel \t |");
            printf("\n\t+--------------------------------+\n\n ");

            printf("\tEnter Your ID:");
            scanf("%s", &stdlogin_id);
            printf("\tEnter Your Pass:");
            scanf("%s", &stdlogin_pass);

            stdlogfile=fopen("stdlogfile.txt", "a+");

            while(fscanf(stdlogfile," Name: %s \n ID: %s \n Department: %s \n Pass: %s \n", stdsin.name, stdsin.id, stdsin.Dep, stdsin.pass)!= EOF)
            {
                if(strcmp(stdlogin_id,stdsin.id)==0)
                {
                    if(strcmp(stdlogin_pass,stdsin.pass)==0)
                    {
                        printf("\tWelcome %s to login panel\n",stdsin.name );
                        found =1;

                        printf("\tEnter Your Faculy Name:");
                        scanf("%s",&facName);

                        faclogfile=fopen("faclogfile.txt", "a+");

                        while(fscanf(faclogfile, " Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2)!= EOF)
                        {
                            if(strcmp(facName,facsin.name)==0)
                            {
                                printf(" Your faculty ID: %s \n Dep: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.id, facsin.dep, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2);

                                printf("\n\t 1. SUNDAY Slot-1");
                                printf("\n\t 2. SUNDAY Slot-2");
                                printf("\n\t 3. MONDAY Slot-1");
                                printf("\n\t 4. MONDAY Slot-2");
                                printf("\n\t 5. TUESDAY Slot-1");
                                printf("\n\t 6. TUESDAY Slot-2\n");
                                printf("\n\t 7. WEDNESSDAY Slot-1\n");
                                printf("\n\t 8. WEDNESSDAY Slot-2\n");
                                printf("\n\t 9. THUSDAY Slot-1\n");
                                printf("\n\t 10. THUSDAY Slot-2\n");

                                printf("\t \n Enter your Slote: ");

                                scanf("%d",&slot);

                                switch(slot)
                                {

                                case 1:
                                    printf("\n\t 1. SUNDAY Slot-1");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry Name: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.s_day_s1);
                                    break;
                                case 2:
                                    printf("\n\t 2. SUNDAY Slot-2");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.s_day_s2);
                                    break;
                                case 3:
                                    printf("\n\t 3. MONDAY Slot-1");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.m_day_s1);
                                    break;
                                case 4:
                                    printf("\n\t 4. MONDAY Slot-2");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.m_day_s2);
                                    break;
                                case 5:
                                    printf("\n\t 5. TUESDAY Slot-1");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.t_day_s1);
                                    break;
                                case 6:
                                    printf("\n\t 6. TUESDAY Slot-2");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.t_day_s2);
                                    break;
                                case 7:
                                    printf("\n\t 7. WEDNESSDAY Slot-1");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.w_day_s1);
                                    break;
                                case 8:
                                    printf("\n\t 8. WEDNESSDAY Slot-2");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.w_day_s2);
                                    break;

                                case 9:
                                    printf("\n\t 9. THUSDAY Slot-1");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.th_day_s1);
                                    break;
                                case 10:
                                    printf("\n\t 10. THUSDAY Slot-2");
                                    facslote=fopen("facslote.txt", "a+");
                                    fprintf(facslote, " Facultry ID: %s \n Student Name: %s \n ID: %s \n SUNDAY Slot-1: %s\n",facsin.name,stdsin.name,stdsin.id,facsin.th_day_s2);
                                    break;
                                }
                                break;
                            }

                            else
                            {
                                printf("\n\tInvalid faculty name!");
                                break;
                            }
                            fclose(faclogfile);
                        }

                    }
                    else
                    {
                        printf("\t\nInvalid Password!");
                        found =1;
                    }
                }
            }
            if(!found)
            {
                printf("\tInvalid ID or password. Please try again.\n");

            }

            fclose(stdlogfile);
            break;

        case 2:

            printf("\n\t+--------------------------------+\n ");
            printf("\t|\tFaculty Login Panel \t |");
            printf("\n\t+--------------------------------+\n\n ");

            printf("\tEnter Your ID:");
            scanf("%s", &faclogin_ID);
            printf("\tEnter Your Pass:");
            scanf("%s", &faclogin_Pass);

            faclogfile=fopen("faclogfile.txt", "a+");

            while(fscanf(faclogfile, " Name: %s \n ID: %s \n Dep: %s \n Pass: %s \n SUNDAY Slot-1: %s \n SUNDAY Slot-2: %s \n MONDAY Slot-1: %s \n MONDAY Slot-2: %s \n TUESDAY Slot-1: %s \n TUESDAY Slot-2: %s \n WEDNESDAY Slot-1: %s \n WEDNESDAY Slot-2: %s \n THUSDAY Slot-1: %s \n THUSDAY Slot-2: %s",facsin.name,facsin.id, facsin.dep, facsin.pass, facsin.s_day_s1,facsin.s_day_s2,facsin.m_day_s1,facsin.m_day_s2, facsin.t_day_s1, facsin.t_day_s2, facsin.w_day_s1, facsin.w_day_s2, facsin.th_day_s1, facsin.th_day_s2)!= EOF)

            {
                if(strcmp(faclogin_ID,facsin.id)==0)
                {
                    if(strcmp(faclogin_Pass,facsin.pass)==0)
                    {
                        printf("\n \t Welcome %s to login panel\n",facsin.name);
                        found =1;

                        faclogfile=fopen("faclogfile.txt", "a+");

                        facslote=fopen("facslote.txt", "a+");

                        while(fscanf(facslote, " Facultry: %s \n Student: %s \n ID: %s \n Slote: %s \n", facsin.name, stdsin.name, stdsin.id, facsin.s_day_s1)!= EOF)
                        {
                            if(strcmp(faclogin_ID,facsin.id)==0)
                            {

                                fprintf(facslote,"Student: %s \n ID: %s \n Slote %s", stdsin.name, stdsin.id, facsin.s_day_s1);

                            }
                            else
                            {
                                printf("\n \tno apoinment!");
                                break;
                            }
                        }


                        break;
                    }
                    else
                    {
                        printf("\n\tInvalid Password!");
                        found =1;
                    }
                }
            }
            if(!found)
            {
                printf("\tInvalid ID or password. Please try again.\n");

            }

            fclose(faclogfile);
            break;
        }
        break;

    case '2':

        printf("\n\t+----------------------------------------+\n ");
        printf("\t|\tWelcome To SinUp panel \t\t |");
        printf("\n\t+----------------------------------------+\n\n ");


        printf("\t1. Student\n");
        printf("\t2. Faculty\n");
        printf("\tEnter Your Choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\n\t+----------------------------------------+\n ");
            printf("\t|\t Student SinUp panel \t\t |");
            printf("\n\t+----------------------------------------+\n\n ");
            std_sinup_fun();
            break;

        case 2:
            printf("\n\t+----------------------------------------+\n ");
            printf("\t|\t Faculty SinUp panel \t\t |");
            printf("\n\t+----------------------------------------+\n\n ");
            fac_sinup_fun();
            break;
        }
        break;
    default:
        printf("Invalid Choice!");
    }
    return 0;
}
