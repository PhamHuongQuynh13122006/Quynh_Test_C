//Bai 9
#include<stdio.h>
#include<string.h>
struct dish{
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
void print(int pos, int *n){
 if (pos < 0 || pos >= *n) {
        printf("Invalid ^ ^\n");
        return;
    }
}
void printmenu(struct dish menu[], int n){
    for (int i = 0; i < n; i++){
        printf("%d. name: %s, price: %.3f VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
}
int main(){
while(1){
    int choice, pos, n=5;
    float price;
    printf("\n=====MENU=====\n");
    printf("1. In ra giá trị các phần tử có trong menu món ăn theo dạng 1. member: value\n");
    printf("2. Thêm một phần từ vào vị trí chỉ định\n");
    printf("3. Sửa một phần từ ở vị trí chỉ định\n");
    printf("4. Xóa một phần từ ở vị trí chỉ định\n");
    printf("5. Sắp xếp các phần tử \n");
    printf("6. Tìm kiếm phần tử theo name nhập vào\n");
    printf("7. Thoát\n");
    printf("Your choice is : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printmenu(menu, n);
        break;
        case 2:
        printf("Input position add new (0 - %d): ", n);
        scanf("%d", &pos);
        if(pos<0||pos>n){
            printf("Invalid ^ ^");
            break;
        }
        for(int i=n;i>pos;i--){
            menu[i]=menu[i-1];
        }
        menu[pos].id=pos+1;
        fflush(stdin);
        printf("\nInput dish add new:");
        fgets(menu[pos].name,100,stdin);
        menu[pos].name[strcspn(menu[pos].name,"\n")]='\0';
        printf("\nInput price add new:");
        scanf("%f",&menu[pos].price);
        fflush(stdin);
        n++;
        printf("After change menu is :");
        printmenu(menu, n);
        break;
        case 3:
        printf("Input position in the edit(0-%d) :",n-1);
        scanf("%d",&pos);
        print(pos,&n);
        printf("Input dish change in the menu :");
        fflush(stdin);
        fgets(menu[pos].name,100,stdin);
        menu[pos].name[strcspn(menu[pos].name,"\n")]='\0';
        printf("Input price change in the menu :");
        scanf("%f",&menu[pos].price);
        printf("After menu edit change is :");
        for(int i=n;i>pos;i--){
            menu[i]=menu[i-1];
        }
        break;
        case 4:
        printf("Position need delete in the menu (0-%d) are :",n-1);
        scanf("%d",&pos);
        print(pos,&n);
        printf("Input position in the menu :");
         for (int i = pos; i < n - 1; i++){
            menu[i] = menu[i + 1];
         }
        n--;
        printmenu(menu,n);
        break;
        case 5:
        printf("After ag in the menu is : ");
         for (int i = 0; i<n-1;i++){
            for (int j=0; j<n-i-1; j++){
                if (menu[j].price > menu[j+1].price){
                    struct dish temp = menu[j];
                    menu[j] = menu[j+1];
                    menu[j+1] = temp;
                }
            }
         }
        printmenu(menu,n);
        break;
        case 6:
        char value[100];
        printf("Input dish need found is \n:");
        fflush(stdin);
        fgets(value, 100, stdin); 
        value[strcspn(value, "\n")] = '\0';
        int check = 0;
        for(int i = 0; i < n; i++) {
            if(strcmp(menu[i].name, value) == 0) {
            printf("Found position is : %d\n", i + 1);
            printf("Dish found is : ID: %d, Name: %s, Price: %.3f VND\n", menu[i].id, menu[i].name, menu[i].price);
            check = 1;
            }
        }
        if(!check) {
            printf("Invalid ^ ^\n");       
        }
        break;
        case 7:
        printf("Exit frogram ^ ^");
        printf("Byeee !!!");
        return 0;
        default:
        printf("Invalid");
        break;
    }
}
}














