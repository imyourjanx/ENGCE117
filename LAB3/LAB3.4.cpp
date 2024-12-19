#include <stdio.h>

struct student
{
    char name[20];
    int age;
};

void GetStudent(struct student child[][10], int *room);

int main()
{
    struct student children[20][10];
    int group;
    GetStudent(children, &group);

    printf("\n-----------------------------------------------------\n");
    for (int i = 0; i < group; i++) 
    {
        printf("Group %d:\n", i + 1);
        for (int j = 0; j < 3; j++) 
        {
            printf("Student %d: Name = %s, Age = %d\n", j + 1, children[i][j].name, children[i][j].age);
        }
    }
    printf("\n-----------------------------------------------------\n");
    return 0;
} // end function
void GetStudent(struct student child[][10], int *room)
{
    int recroom = 0;

    printf("Enter the number of groups: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++)
    {
        printf("Room %d\n", recroom + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("student %d: ", j + 1);
            scanf("%s", child[i][j].name);
            printf("Enter age: \n");
            scanf("%d", &child[i][j].age);
        }
        
        recroom++;
    }

        for (recroom = 0; recroom < *room; recroom++)
        {
            printf("Room %d: 10 students entered.\n", recroom + 1);
        }
}
