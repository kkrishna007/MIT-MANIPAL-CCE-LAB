#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h> 


int main() {

    int PORT;
    printf("Input PORT: ");
    scanf("%d", &PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation error\n");
        exit(0);
    }

    struct sockaddr_in c_addr;
    c_addr.sin_port = htons(PORT);
    c_addr.sin_family = AF_INET;
    c_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(c_addr.sin_zero, '\0', sizeof(c_addr.sin_zero));

    int size = sizeof(struct sockaddr);
    connect(sockfd, (struct sockaddr*)&c_addr, sizeof(c_addr));

    int buffer[10];
    int choice, sz;
    int odd[10] = {0};
    int even[10] = {0};
    int a = 0, b = 0;

    while (1) {
        printf("\n\n1. Sort in ascending order");
        printf("\n2. Sort in descending order");
        printf("\n3. Split into odd and even arrays");
        printf("\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
                printf("\nEnter the no of elements in array:");
                scanf("%d", &sz);
                printf("\nEnter the elements in array:");
                for (int i = 0; i < sz; i++)
                    scanf("%d", &buffer[i]);

                send(sockfd, buffer, sz * sizeof(int), 0);
                send(sockfd, &sz, sizeof(int), 0);
                send(sockfd, &choice, sizeof(int), 0);
                recv(sockfd, buffer, sz * sizeof(int), 0);
                
                printf("\nThe array in %s order is:\n", (choice == 1) ? "ascending" : "descending");
                for (int i = 0; i < sz; i++)
                    printf("%d ", buffer[i]);
                printf("\n");
                break;

            case 3:
                printf("\nEnter the no of elements in array:");
                scanf("%d", &sz);
                printf("\nEnter the elements in array:");
                for (int i = 0; i < sz; i++)
                    scanf("%d", &buffer[i]);

                send(sockfd, buffer, sz * sizeof(int), 0);
                send(sockfd, &sz, sizeof(int), 0);
                send(sockfd, &choice, sizeof(int), 0);
                recv(sockfd, odd, sz * sizeof(int), 0);
                recv(sockfd, &b, sizeof(int), 0);
                recv(sockfd, even, sz * sizeof(int), 0);
                recv(sockfd, &a, sizeof(int), 0);

                printf("\nThe odd elements in the array:\n");
                for (int i = 0; i < b; i++)
                    printf("%d ", odd[i]);
                printf("\nThe even elements in the array:\n");
                for (int i = 0; i < a; i++)
                    printf("%d ", even[i]);
                printf("\n");
                break;

            case 4:
                send(sockfd, buffer, sz * sizeof(int), 0);
                send(sockfd, &sz, sizeof(int), 0);
                send(sockfd, &choice, sizeof(int), 0);
                close(sockfd);
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

