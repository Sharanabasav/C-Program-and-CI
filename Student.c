#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int marks_summation(int* marks, int number_of_students, char gender) 
{
    int i=0;
    int sum = 0;
    if (gender == 'b')
    {
        for (i = 0; i < number_of_students;)
        {
            sum = sum + marks[i];
             i = i+2;

        }
    }
    else 
    {
        for (i = 1; i < number_of_students;)
        {
            sum = sum + marks[i];
            i = i+2;

        }
    }
    return sum;
}

int main() {
    int number_of_students = 4;
    char gender = 'b';
    int sum;

    int *marks = (int *) malloc(number_of_students * sizeof (int));
    marks[0] = 35;
    marks[1] = 36;
    marks[2] = 37;
    marks[3] = 38;

    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);

    return 0;
}
