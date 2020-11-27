#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Functions.h"


void ScreenInit(void)
{
    printf("____________________________________WELCOME TO SMART CLINC RESERVATION SYSTEM__________________________________________\n\n");
    printf("_________________________________________________ ITI MENUFIA _________________________________________________________\n\n");

}
void AddNode(u32 ID,u8 name[20],u32 age,u8 gender)
{
    Node *link = (Node*) malloc(sizeof(Node));

    link->ID = ID;
    strcpy(link->name,name);
    link->age = age ;
    link->gender = gender ;
    link->Next=Head;
    Head = link;
}


void PrintLinkedList(void)
{
    Node *ptr = Head;

    while(ptr != NULL)
    {
        printf("\nID:%d\tName:%s\tAge:%d\t",ptr->ID,ptr->name,ptr->age);

        if(ptr->gender=='F' || ptr->gender == 'f')
        {
            printf ("Gender: Female\n");
        }
        else if(ptr->gender=='M' || ptr->gender=='m')
        {
            printf ("Gender: Male\n");
        }
        ptr = ptr->Next;
        // printf("________________________________________________________________________________________\n");

    }

}


u8 Search(u8 ID)
{
    Node *q;
    q = &Head;

    while (q!=NULL)
    {
        if(q->ID==ID)
        {
            return ID;
        }
        q=q->Next;
    }

    return 0;
}


void Edit(void)
{
    u8 new_name[20];
    u32 new_age;
    u8 new_gender;
    u32 id;
    Node *p;

    p=Head;

    printf("_________________________________________________________________________________________\n\n");
    printf ("To Edit Patient Record Enter ID: ");
    fflush(stdin);
    if(scanf ("%d",&id))
    {
        while (p!=NULL)
        {
            if(p->ID == id)
            {
                printf("__________________________________________________________________________________________\n");
                printf("Enter New Data : \n\n");

                printf("Enter New Name : ");
                fflush(stdin);
                scanf("%s",new_name);

                printf("__________________________________________________________________________________________\n");

                printf("Enter New Age : ");
                fflush(stdin);
                scanf("%d",&new_age);

                printf("__________________________________________________________________________________________\n");

                printf("Enter New Gender F For Female M For Male : ");
                fflush(stdin);
                scanf("%c",&new_gender);

                printf("__________________________________________________________________________________________\n");

                strcpy(p->name,new_name);

                p->age=new_age;

                p->gender=new_gender;

                PrintLinkedList();
                break;
            }
            p=p->Next;
        }
    }
    else
    {
        printf("NOT VALID NUMBER !!! \n");
        Edit();
        return;
    }
}

void GetPatientRecord(void)
{
    u32 id;
    printf ("Enter ID : ");
    fflush(stdin);

    if(scanf ("%d",&id))
    {
        Node* temp;
        temp=Head;

        while(temp != NULL)
        {
            if (temp->ID==id)
            {
                printf("________________________________________________________________________________________\n\n");
                printf("ID:%d\tName:%s\tAge:%d\t",temp->ID,temp->name,temp->age);
                if(temp->gender=='F' || temp->gender == 'f')
                {
                    printf ("Gender: Female");
                }
                else if(temp->gender=='M' || temp->gender == 'm')
                {
                    printf ("Gender: Male\n");
                }
                printf("________________________________________________________________________________________\n\n");
                break;
            }
            else
            {
                temp=temp->Next;
            }
        }
    }
    else
    {
        printf("NOT VALID NUMBER !!! \n");
        GetPatientRecord();
        return;
    }

}


void PrintReservationtime(void)
{

    printf("___________________________________Slot status___________________________________________\n\n");
    for(int j=0; j<5; j++)
    {
        if(ReservationArray[j]==0)
        {
            printf ("Available Slot num %d to reserve :From %s  \n\n",j+1,Time_Slots[j]);
            printf("____________________________________________________________________________________________\n\n");
        }
        else
        {
            printf ("Reserved For ID: %d\n",ReservationArray[j]);
            printf("____________________________________________________________________________________________\n\n");
        }
    }
}





void ReservingTimeSlot(void)
{
    u32 TimeSlot;

    printf("__________________________________________________________________________________________\n\n");
    printf("Please enter Your selection :");
    fflush(stdin);
    scanf ("%d",&TimeSlot);


    if(TimeSlot==1)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[0]));
        else
            {
                ReservationArray[0]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }

    }



    else if(TimeSlot==2)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[1]));
        else
            {
                ReservationArray[1]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }



    else if(TimeSlot==3)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[2]));
        else
            {
                ReservationArray[2]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }

    else if(TimeSlot==4)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[3]));
        else
            {
                ReservationArray[3]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }

    else if(TimeSlot==5)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[4]));
        else
            {
                ReservationArray[4]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }
    printf("________________________________________________________________________________________\n\n");

}






u8 ModeSelect(void)
{

    printf ("\nFor Admin Mode Enter: 1\n\n");
    printf ("For User Mode Enter: 2\n\n");
    printf ("To Exit The System Enter: 3\n\n");
    printf ("You select : ");
    fflush(stdin);
    if(scanf ("%d",&login))
    {
        if( 1 == login)
        {
            AdminCheck();
            return 1;

        }
        else if (2 == login)
        {
            UserChoice();
            return 1;
        }

        else
        {
            printf("System Closing............\n");
            return 0;
        }
        return 1;

    }
    else
    {
        printf("NOT VALID NUMBER !!! \n");
        ModeSelect();
        return 1;
    }

}



void AdminCheck(void)
{
    u32 pw=0;
    u8 i=0;

    for(; i<=3; i++)
    {
        printf ("Enter PassWord : ");

        if(3 == i)
        {
            printf ("Sorry you tried 3 times System is locked !!!!\n");
            return;
        }

        else
        {
            scanf ("%d",&pw);

            if(1234 == pw)
            {
                printf("__________________________________________Welcome in Admin mode__________________________________________________\n\n");
                i=55;
            }

            else if (i<2)
            {

                printf ("Try Again\n\n");

            }

        }

    }


    if (56 == i)
    {
        AdminChoices();
        return;
    }

}


void AdminChoices(void)
{
    u32 id;
    while(AdminOperationSelect)
    {
        printf ("To Add New Patient Record Press :         (1)\n");
        printf ("To Edit Patient ID  :                     (2)\n");
        printf ("To Reserve a Slot With The Doctor Press : (3)\n");
        printf ("To Cancel a Reservation Press :           (4)\n");
        printf ("To Back To Main Menu Enter :              (0)\n\n");
        printf ("Enter Operation Number : ");

        scanf ("%d",&AdminOperationSelect);

        if(1 == AdminOperationSelect)
        {
            RecivingPatientData();
        }
        else if(2 == AdminOperationSelect)
        {
            Edit();
        }
        else if(3 == AdminOperationSelect)
        {
            PrintReservationtime();
            ReservingTimeSlot();
        }

        else if(4 == AdminOperationSelect)
        {
            printf ("\nEnter Patient ID: ");
            scanf ("%d",&id);
            for(u8 i=0; i<5; i++)
            {
                if(ReservationArray[i]==id)
                {
                    ReservationArray[i]=0;
                }
            }
        }

    }
    AdminOperationSelect=1;
    return;
}




void RecivingPatientData(void)
{
    u8 name[20];
    u32 age=0;
    u8 gender=0;
    u32 id;

    printf ("________________________________________________________________________________________\n\n");
    printf ("Enter ID In Numbers : ");
    fflush(stdin);
    if(scanf("%d",&id))
    {
        if( Search(id) )
        {
            printf("ID Already Exist");
            RecivingPatientData();
        }

        else

        {
            printf ("Enter Patient Name : ");
            fflush(stdin);
            scanf("%s",name);
            printf ("Age : ");
            fflush(stdin);
            scanf ("%d",&age);
            printf ("Gender F For Female M For Male: ");
            fflush(stdin);
            scanf ("%c",&gender);
            AddNode(id,name,age,gender);

            PrintLinkedList();
        }
        printf("________________________________________________________________________________________\n\n");

    }
    else
    {
        printf("NOT VALID NUMBER !!! \n");
        RecivingPatientData();
        return ;
    }
}

void UserChoice(void)
{

    while(UserOperationSelect)
    {
        printf("__________________________________________Welcome in user mode_____________________________________________\n\n");

        printf ("View patient record press :      (1)\n");
        printf ("View today's reservation press : (2)\n");
        printf ("To Back To Main Menu Enter:      (0)\n\n");
        printf ("Enter Operation Number : ");
        scanf ("%d",&UserOperationSelect);

        if(UserOperationSelect==1)
        {
            GetPatientRecord();
        }
        else if(UserOperationSelect==2)
        {
            PrintReservationtime();
        }
    }

    UserOperationSelect=1;//set user flag to 1

}

















