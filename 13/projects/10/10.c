#include <stdio.h>

void reverse_name(char *name);

int main(void) {

    char name[81];

    printf("Enter a first and last name: ");
    fgets(name, sizeof(name), stdin);
    reverse_name(name);

    return 0;
}

void reverse_name(char *name) {

    char last_name[NAME_LEN], initial[] = {',',' ',' ', '\0'}, *p, *q;

    p = name;
    q = last_name;
    while (*p == ' ')
       p++;
    initial[2] = toupper(*p++);
    while (*p != ' ')
        p++;
    while (*p++ != '\0') {
        if (*p != ' ') {
            *q = *p;
            q++;
        }
    }
    last_name[0] = toupper(last_name[0]);
    name[0] = *q = '\0';
    strcat(name, (strcat(last_name, initial)));
}
