#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include <stdlib.h>

//node containing 6 category with next pointer
struct node
{
    char *name[100];
    int age;
    char *address[100];
    int phone_num;
    char *bloodgroup[100];
    int id;
    int priority;
    struct node *next;
};
struct node *head= NULL;

//utility functions
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
void table();

int main()
{

    int op;
    do{
            //system("COLOR 46");
         printf("\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t WELCOME TO LIFE-CARE HOSPITAL!\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
        printf("\t\t\t4.Exit\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&op);
    switch(op)
    {
    case 1:
        head= insert(head);
        getchar();
        system("cls");
        break;
    case 2:
        head= delete(head);
        getchar();
        printf("\n");
        break;
    case 3:
        display(head);
        getchar();
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    }
}while(op!=4);
}
struct node *insert(struct node *head)
{
    int a1,pn,i1,pri;
    struct node *ptr,*p;
    char* name[100];
    char* address[100];
    char* bloodgroup[100];
    ptr=(struct node*)malloc(sizeof(struct node));

    printf("Enter patient Name:");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",ptr->name);

    printf("Enter the patient's age:");
    scanf("%d",&a1);

    printf("Enter your home address:");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",ptr->address);
  
    printf("Enter your phone number:");
    scanf("%d",&pn);

    printf("Enter the blood group of Patient:");
    scanf(" %s",ptr->bloodgroup);

    printf("Enter the ID no:");
    scanf("%d",&i1);
    
    printf("\n");
    printf("Enter your disease Number: \n");
    table();
    scanf("%d",&pri);
   
    ptr->age=a1;
    ptr->phone_num=pn;
    ptr->id=i1;
    ptr->priority=pri;

    //condition for checking empty list  /  inserting higher priority(here lower number) first
    if((head==NULL)|| pri <head->priority)
    {
        ptr->next=head;
        head=ptr;
    }
    else
        {
            p=head;
            // traversing till end of linkedlist and lower priority afterwards
            while(p->next!=NULL && p->next->priority <=pri)
            p=p->next;
            ptr->next=p->next;
            p->next=ptr;
        }
        return head;
};
struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE\n");
      
    }
    else
    {
        ptr= start;
        printf("\n Deleted Record is : %d",ptr->id);
        printf("\n");
        start=start->next;
        free(ptr);
    }
    return start;
};
void display(struct node *head)
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
        printf("\nTHERE IS NO PATIENT\n");
    else
    {
        printf("\nPriority wise appointments are: \n");
        while(ptr!=NULL)
        {
            printf("The name of patient is:%s\n",ptr->name);
            printf("The age of patient is:%d\n",ptr->age);
            printf("The address of patient is : %s\n",ptr->address);
            printf("Phone Number:%d\n",ptr->phone_num);
            printf("The blood group of patient is:%s\n",ptr->bloodgroup);
            printf("---------------------------------------------------\n");
            ptr=ptr->next;
        }
    }
    getchar();
    printf("Press any key to continue..");

}
void table()
{
    printf("\nPlease Refer this Table for your disease!\n\n");
    printf("---------------------------------------------------\n");
    printf("1.Heart disease\n");
    printf("2.Severe Buring \n");
    printf("3.Cancer\n");
    printf("4.Stroke\n");
    printf("5.Paralysis attack\n");
    printf("6.Diabetes/Dialysis Checkup\n");
    printf("7.Malaria\n");
    printf("8.Viral infection\n");
    printf("9.Common Cold\n");
    printf("---------------------------------------------------\n");
    printf("\n");
}