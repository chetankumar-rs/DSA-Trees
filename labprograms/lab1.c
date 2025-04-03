#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
    char name[20];
    int empid;
    char department[20];
    int salary;
};

void insert_record(FILE *fp)
{
   struct employee e;
    printf("Enter the name of the employee: ");
    scanf("%s", e.name);
    printf("Enter the employee id: ");
    scanf("%d", &e.empid);
    printf("Enter the department of the employee: ");
    scanf("%s", e.department);
    printf("Enter the salary of the employee: ");
    scanf("%d", &e.salary);
    fprintf(fp,"%d %s %s %d\n", e.empid, e.name, e.department, e.salary);
}

void display_record(FILE *fp)
{
    struct employee e;
    while(fscanf(fp,"%d %s %s %d\n", &e.empid, e.name, e.department, &e.salary) != EOF)
    {
        printf("Employee id: %d\n", e.empid);
        printf("Name: %s\n", e.name);
        printf("Department: %s\n", e.department);
        printf("Salary: %d\n", e.salary);
    }
}

void search_employee(FILE *fp)
{
    struct employee e;
    char dept[20];
    int flag = 0;
    printf("Enter the department to search: ");
    scanf("%s", dept);
    while(fscanf(fp,"%d %s %s %d\n", &e.empid,e.name,e.department,e.salary)!=EOF)
    {
        if(strcmp(e.department,dept)==0)
        {
            if(flag ==0)
            {
                printf("Employee details of department %s\n", dept);
                flag = 1;
                printf("Employee id\tName\tDepartment\tSalary\n");
                printf("-------------------------------------------------\n");  
                printf("%d\t%s\t%s\t%d\n", e.empid, e.name, e.department, e.salary);
            }
        }
        if(flag == 0)
        {
            printf("No employee found in the department %s\n", dept);
        }
    }
}

int main()
{
    FILE *fp;
    int choice;
    while(1)
    {
        printf("1.INSERT\n2.DISPLAY\n3.SEARCH\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                fp = fopen("employe.txt","a+");
                if(fp == NULL)
                {
                    printf("File not found\n");
                    exit(1);
                }
                insert_record(fp);
                fclose(fp);
                break;
            case 2:
                fp = fopen("employe.txt","r");
                if(fp == NULL)
                {
                    printf("File not found\n");
                    exit(1);
                }
                display_record(fp);
                fclose(fp);
                break;
            case 3:
                fp = fopen("employe.txt","r");
                if(fp == NULL)
                {
                    printf("File not found\n");
                    exit(1);
                }
                search_employee(fp);
                fclose(fp);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");                 
        }
    }
    return 0;
}