#include <stdio.h>
#include <string.h>

struct dish {
    int id;
    char name[100];
    float price;
};

struct dish menu[100] = {
    {1,"Cháo lươn",35},
    {2,"Thịt sườn",70},
    {3,"Bún bò",30},
    {4,"MiMi",50},
    {5,"Meme",65},
};

void printmenu(struct dish menu[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. Name: %s, Price: %.3f VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

int main() {
    while (1) {
        int choice, pos, n = 5;
        printf("\n=====MENU=====\n");
        printf("1. In ra menu\n");
        printf("2. Thêm món ăn\n");
        printf("3. Sửa món ăn\n");
        printf("4. Xóa món ăn\n");
        printf("5. Sắp xếp theo giá\n");
        printf("6. Tìm kiếm theo tên\n");
        printf("7. Thoát\n");
        printf("Your choice is : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printmenu(menu, n);
                break;
            case 2:
                printf("Input position to add new (0 - %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Invalid position\n");
                    break;
                }
                for (int i = n; i > pos; i--) {
                    menu[i] = menu[i - 1];
                }
                menu[pos].id = pos + 1; 
                printf("Input dish name: ");
                getchar();
                fgets(menu[pos].name, 100, stdin);
                menu[pos].name[strcspn(menu[pos].name, "\n")] = '\0';
                printf("Input price: ");
                scanf("%f", &menu[pos].price);
                n++;
                printf("Updated menu:\n");
                printmenu(menu, n);
                break;
            case 3:
                printf("Input position to edit (0-%d): ", n-1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position\n");
                    break;
                }
                printf("Edit dish name: ");
                getchar(); 
                fgets(menu[pos].name, 100, stdin);
                menu[pos].name[strcspn(menu[pos].name, "\n")] = '\0';
                printf("Edit price: ");
                scanf("%f", &menu[pos].price);
                printf("Updated menu:\n");
                printmenu(menu, n);
                break;
            case 4:
                printf("Input position to delete (0-%d): ", n-1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position\n");
                    break;
                }
                for (int i = pos; i < n - 1; i++) {
                    menu[i] = menu[i + 1];
                }
                n--;
                printf("Updated menu after deletion:\n");
                printmenu(menu, n);
                break;
            case 5:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (menu[j].price > menu[j + 1].price) {
                            struct dish temp = menu[j];
                            menu[j] = menu[j + 1];
                            menu[j + 1] = temp;
                        }
                    }
                }
                printf("Sorted menu by price:\n");
                printmenu(menu, n);
                break;
            case 6:
                {
                    char value[100];
                    printf("Input dish name to find: ");
                    getchar(); 
                    fgets(value, 100, stdin);
                    value[strcspn(value, "\n")] = '\0';
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strcmp(menu[i].name, value) == 0) {
                            printf("Found at position: %d\n", i + 1);
                            printf("Dish found: ID: %d, Name: %s, Price: %.3f VND\n", menu[i].id, menu[i].name, menu[i].price);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Dish not found\n");
                    }
                }
                break;
            case 7:
                printf("Exit program\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
