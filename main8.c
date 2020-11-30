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
    int flag;
    for (int i = 0; i < Len(s1); i++) {
        flag = 1;
        for (int j = 0; j < Len(s2); j++) {
            if (s1[i] == s2[j]) {
                ++count;
                flag = 0;
                break;
            }
        }
        if ((flag == 1) && (max_count < count)) {
            max_count = count;
            count = 0;
        }
    }
    return max_count;
}

int Leks (char*s1, char *s2)
{
     char leks[100];
     int count = 0;
     for (int i = 0; i < Len(s1); i++)
     {
         leks[count] = s1[i];
         for (int j = 0; j < Len(s2); j++)
         {
             if ((s1[i] == s2[j]) || (i == Len(s1) - 1))
             {
                 if (i == Len(s1) - 1)
                     ++count;
                 for (int k = 0; k < count; k++)
                     printf("%c", leks[k]);
                 printf("\n");
                 count = -1;
                 break;
             }
         }
         ++count;
     }

}
int main() {
    char s1[100], s2[100], s1_copy[100];
    gets(s1);
    gets(s2);
    printf("\n");
    Copy(s1, s1_copy);//5
    printf("\n");
    printf("%d\n",Len(s1));//7
    char c;
    scanf("%c", &c);
    printf("\n%d\n", Search(s1, c));//9
    printf("%d\n", Segment(s1, s2)); //11
    Leks(s1, s2);//13
    return 0;
}
