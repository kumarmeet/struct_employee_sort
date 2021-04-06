#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int emp_id;
    char emp_name[30];
    float salary;
};

void input_emp(struct Employee[], int size);
void sort_employee_by_salary(struct Employee[], int);

int main(void)
{
    int size;
    printf("Enter how many employees do you want to sort -> ");
    scanf("%d", &size);

    struct Employee emp[size];

    input_emp(emp, size);
    sort_employee_by_salary(emp, size);
    return 0;
}

void sort_employee_by_salary(struct Employee emp[], int size)
{
    void output_emp(struct Employee[], int);
    int i, j;
    struct Employee temp;

    for (i = 1; i <= size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            if (emp[i].salary < emp[j].salary)
            {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }

    printf("Employee sort descendingly by their salary\n");
    output_emp(emp, size);
}

void output_emp(struct Employee emp[], int size)
{
    int i;

    for (i = 1; i <= size; i++)
    {
        printf("Name of %d employee -> %s\n", i, emp[i].emp_name);
        printf("ID of %d employee -> %d\n", i, emp[i].emp_id);
        printf("Salary of %d employee -> %.2f\n", i, emp[i].salary);
    }
}

void input_emp(struct Employee emp[], int size)
{
    int i;

    for (i = 1; i <= size; i++)
    {
        printf("Enter %d employee id, name and salary\n", i);
        scanf("%d", &emp[i].emp_id);
        fflush(stdin);
        scanf("%s", emp[i].emp_name);
        scanf("%f", &emp[i].salary);
    }
}