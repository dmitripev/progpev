#include <stdio.h>
int Len(char*s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void Copy(char*s1, char*s2) {
    for (int i = 0; i < Len(s1)+1; i++) {
        s2[i] = s1[i];
    }
    for (int i = 0; i < Len(s2); i++) {
        printf("%c", s2[i]);
    }
}

int Search(char*s1, char sym) {
    int res = -1;
    for (int i = 0; i < Len(s1); i++) 
    {
        if (s1[i] == sym)
           res = i;
    }
    return res;
}

int Segment(char*s1, char *s2) {
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < Len(s1); i++) {
        for (int j = 0; j < Len(s2); j++) {
            if (s1[i] != s2[j]) {
                count = -1;
            }
        }
        count++;
        if (max_count < count) {
            max_count = count;
        }
    }
    return max_count;
}

int Leks (char*s1, char *s2)
{
    
}
int main() {
    char s1[100], s2[100], s1_copy[100];
    gets(s1);
    gets(s2);

    Sum(s1, s2); //1
    
    printf("\n");

    Copy(s1, s1_copy);//3

    printf("\n");

    printf("%d", Segment(s1, s2)); //5


    return 0;
}
