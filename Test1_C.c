// Test 1 9h30
//n la phan tu
#include<stdio.h>
#include<math.h>

int main(){
    int arr[100], max = 0, n = 0, find, choice, value, index, pos;
    int isPrime(int n){
        if(n < 2){
            return 0;
        }
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                return 0;
            }
        }
        return 1;
    }
    while(1){
        printf("\n====Menu====\n");
        printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2.In ra gia tri cac phan tu dang quan ly\n");
        printf("3.In ra gia tri lon nhat cua mang\n");
        printf("4.In ra cac phan tu la so nguyen to trong mang\n");
        printf("5.Them mot phan tu vao trong mang\n");
        printf("6.Xoa mot phan tu trong mang\n");
        printf("7.Sap xep mang theo thu tu tang dan\n");
        printf("8.Tim kiem phan tu (nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
        printf("9.Exit\n");
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch(choice){
          case 1:
            printf("Nhap so phan tu: ");
            scanf("%d",&n);
            for(int i = 0; i < n; i++){
                printf("Phan tu thu %d : ", i + 1);
                scanf("%d",&arr[i]);
            }
            break;
            case 2:
            if(n == 0){
                printf("Array is empty ^ ^\n");
            }else{
                printf("Gia tri cac phan tu dang quan ly la : ");
                for(int i = 0; i < n; i++){
                    printf("%d\t",arr[i]);
                }
            }  
            break;
            case 3:
            if(n == 0){
                printf("Array is empty ^ ^");
            }else{
                int max = arr[0];
                //
                for(int i = 0; i < n; i++){
                    if(arr[i] > max){
                        max = arr[i];
                    }
                }
                printf("Gia tri lon nhat cua mang la : %d", max);
            }
            break;
            case 4:
            if(n == 0){
                printf("Array is empty");
            }else{
                int prime = 0;
                printf("Cac phan tu la so nguyen to trong mang la : \t");
                for(int i = 0; i < n; i++){
                if(isPrime(arr[i])){
                    printf("%d\t",arr[i]);
                    prime++;
                }
                }
                if(prime == 0){
                    printf("Khong co so nguyen to nao trong mang");
                }
            }
            break;
            case 5:
            if(n < 100){
                printf("Them phan tu vao mang : ");
                scanf("%d",&value);
                arr[n] = value;
                n++;
            }else{
            printf("Mang da day khong the them phan tu");
            printf("Am soo sorry ^ ^");
            }            
            break;
            // xoa mot phan tu trong mang
            case 6 :
            if(n == 0){
                printf("Array is empty ^ ^");
            }else{
                printf("Chon vi tri de xoa phan tu (0-%d) : ", n - 1);
                scanf("%d", &pos);
                if(pos >= 0 && pos < n){
                    for(int i = pos; i < n - 1; i++){
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }else{
                    printf("Invalid position ^ ^");
                }
            }
            break;
            case 7:
            if(n == 0){
                printf("Array is emply ^ ^");
            }else{
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                         if (arr[i] > arr[j]){
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                for(int i = 0; i < n; i++){
                    printf("%d\t",arr[i]);
                }
            }
            break;
            case 8:
            if(n == 0){
                printf("Array is emply ^ ^");
            }else{
                printf("Phan tu can tim la : ");
                scanf("%d", &index);
                find = 0;
                printf("Vi tri cua phan tu can tim trong mang la : \t");
                for(int i = 0; i < n; i++){
                    if(arr[i] == index){
                        printf("Phan tu thu %d xuat hien tai vi tri so %d .", i, index);
                        find = 1;
                    }
                    //
                }
                if(!find){
                    printf("khong tim thay phan tu %d ",i);
                }
            }
            break;
            case 9:
            printf("Thoat truong trinh !!!");
            return 0;
            break;
            default:
            printf("Lua chon khong hop le ");
            printf("Vui long chon lai ");
        }
    }
}
    