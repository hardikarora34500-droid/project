#include <stdio.h>
#include <string.h>

int main() {
    char room[3][20] = {"", "", ""};
    int ch, r;

    while(1) {
        printf("\n1.View 2.Book 3.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) {
            for(int i=0;i<3;i++)
                printf("Room %d: %s\n", i+1, strlen(room[i]) ? room[i] : "Empty");
        }
        else if(ch == 2) {
            printf("Room no (1-3): ");
            scanf("%d", &r);
            if(strlen(room[r-1]) == 0) {
                printf("Name: ");
                scanf("%s", room[r-1]);
            } else {
                printf("Already booked\n");
            }
        }
        else break;
    }
    return 0;
}
