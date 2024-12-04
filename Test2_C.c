//Test 2
#include<stdio.h>
int main(){
    int arr[100][100], cols = 0, rows = 0, choice;
    while(1){
        printf("=====Menu=====\n");
        printf("1.Nhap kich co va gia tri cac phan tu mang \n");
        printf("2.In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3.In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4.In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5.In ra cac phan tu nam tren duong cheo phu\n");
        printf("6.Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7.Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8.Exit\n");
        printf("Your Choice is : \n");
        scanf("%d",&choice);
    }
    switch(choice){
       // Nhap kich co va gia tri cac phan tu mang
        case 1:
        printf("Nhap so hang :");
        scanf("%d",&rows);
        printf("Nhap so cot :");
        scanf("%d",&cols);
        if(rows < 0 || rows > 100 || cols < 0 || cols > 100){
            printf("Kich co va gia tri ban nhap vao khong hop le !!!");
            break;
        }
        for(int i = 0; i < rows; i++){
            for(int j =0; j < cols; j++){
                printf("Nhap kich co va gia tri cho cac phan tu trong mang arr[%d][%d]", i + 1, j + 1);
                scanf("%d", &arr[i][j]);
            }
        }
        break;
       // In gia tri cac phan tu cua mang theo ma tran
        case 2:
        if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        printf("Gia tri cac phan tu cua mang theo ma tran la :");
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                printf("%d",arr[i][j]);
            }
        }
        break;
       // In ra cac phan tu nam tren duong bien va tinh tich
        case 3:
        if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        int product = 1;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
                    printf("%d",arr[i][j]);
                    product *= arr[i][j];
                }
            }
        }
        break;
       // In ra cac phan tu nam tren duong cheo chinh
        case 4:
        if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        for(int i = 0; i < rows; i++){
            printf("%d",arr[i][i]);
        }
        break;
       // In ra cac phan tu nam tren duong cheo phu
        case 5:
        if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        for(int i = 0; i < rows; i++){
            printf("%d", arr[i][cols -i - 1]);
        }
        break;
       // Sap xep duong cheo chinh theo thu tu tang dan
        case 6:
         if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        if(rows != cols){
            printf("Ma tran khong vuong . Khong the sap xep theo duong cheo chinh");
            break;
        }
        int a[100], h = 0;
        for(int i = 0; i < rows; i++){
            a[i] = arr[i][i];
        }
        for(int i = 0; i < h - 1; i++){
            for(int j = i + 1; i < h; j++){
                if(a[i] > a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("Duong cheo chinh sau khi duoc sap xep la : ");
        for(int i = 0; i < rows; i++){
            arr[i][i] = a[i];
        }
        break;
       // Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
        case 7:
        if(cols == 0 || rows == 0){
            printf("Array is empty ^ ^");
            break;
        }
        int t, find = 0;
        printf("Nhap phan tu can tim :");
        scanf("%d",&t);
        printf("Vi tri cua phan tu %d trong mang la :\n ",t);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(arr[i][j] == t){
                    printf("Hang : %d , cot : %d\n", i + 1, j + 1);
                    find = 1;
                }
            }
        }
        //
        if(!find){
            printf("Khong tim thay phan tu %d trong mang !!!", t);
        }
        break;
       //Exit
        case 8:
        printf("Thoat chuong trinh");
        return 0;
        default:
        printf("Lua chon khong hop le");
    }
}