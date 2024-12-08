#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if(n < 2) {
        return 0; 
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0; 
        }
    }
    return 1;
}
int main() {
    int arr[100], choice, n = 0, pos, value;
    while(1) {
        printf("\n=====Menu=====\n");
        printf("1. Nhap so phan tu va gia tri cho mang \n");
        printf("2. In ra cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to co trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao mang o vi tri cu the\n");
        printf("6. Xoa mot phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Dem so luong cac so hoan hao co trong mang\n");
        printf("9. Sap xep mang theo thu tu giam dan\n");
        printf("10. Tim gia tri lon thu hai co trong mang\n");
        printf("11. Tim kiem mot phan tu bang binary Search\n");
        printf("12. Dao nguoc thu tu cac phan tu co trong mang\n");
        printf("13. Xoa toan bo cac phan tu trung lap va in toan bo cac phan tu doc lap\n");
        printf("14. In cac phan tu la so chan sau do la cac phan tu so le\n");
        printf("15. Exit\n");
        printf("Your choice is: ");
        scanf("%d", &choice);

        switch(choice) {
            // Nhap so phan tu va gia tri cho mang 
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    printf("Phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            // In ra cac phan tu trong mang 
            case 2: 
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                } else {
                    printf("Gia tri cac phan tu trong mang: ");
                    for(int i = 0; i < n; i++) {
                        printf("%d", arr[i]);
                        if(i < n - 1) {
                            printf(", ");
                        }
                    }
                }
                break;
            // Dem so luong cac so nguyen to co trong mang 
            case 3: 
                if(n == 0) {
                    printf("Array is empty\n");
                } else {
                    int prime = 0;
                    for(int i = 0; i < n; i++) {
                        if(isPrime(arr[i])) {
                            prime++;
                        }
                    }
                    printf("So luong so nguyen to co trong mang la: %d\n", prime);
                    if(prime == 0) {
                        printf("Khong co so nguyen to nao trong mang\n");
                    }
                }
                break;
            // Tim gia tri nho thu hai trong mang
            case 4:
                if(n < 2) {
                    printf("Khong du hai phan tu \n");
                } else {
                    int min = arr[0], mintwo = -1;
                    for(int i = 0; i < n; i++) {
                        if(arr[i] < min) {
                            mintwo = min;
                            min = arr[i];
                        } else if(mintwo < arr[i] && min != arr[i]) {
                            mintwo = arr[i];
                        }
                    }
                    if(mintwo == -1) {
                        printf("Khong co gia tri nho thu hai trong mang\n");
                    } else {
                        printf("Gia tri nho thu hai trong mang la: %d\n", mintwo);
                    }
                }
                break;
            // Them phan tu tai mot vi tri cu the
            case 5:
                if(n < 100) {
                    printf("Nhap gia tri phan tu muon them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri (0-%d): ", n);
                    scanf("%d", &pos);
                    if(pos >= 0 && pos <= n) {
                        for(int i = n; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = value;
                        n++;
                    } else {
                        printf("Vi tri khong hop le\n");
                    }
                } else {
                    printf("Mang da day, khong the them phan tu.\n");
                } 
                break;
            // Xoa phan tu tai mot vi tri cu the
            case 6:
                if(n == 0) {
                    printf("Array is empty\n");
                } else {
                    printf("Chon vi tri de xoa phan tu (0-%d): ", n - 1);
                    scanf("%d", &pos);
                    if(pos >= 0 && pos < n) {
                        for(int i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                    } else {
                        printf("Vi tri khong hop le\n");
                    }
                }
                break;
            // Sap xep mot mang theo thu tu tang dan
            case 7:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                for(int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while(j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep tang dan: ");
                for(int i = 0; i < n; i++){
                    printf("%d", arr[i]);
                    if(i < n - 1) {
                        printf(", ");
                    }
                }
                break;
            // Dem so luong cac so hoan hao co trong mang 
            case 8:
                if(n == 0) {
                    printf("Array is empty\n");
                } else {
                    int count = 0;
                    for(int i = 0; i < n; i++) {
                        int sum = 0;
                        for(int j = 1; j <= arr[i] / 2; j++) { // Start from 1
                            if(arr[i] % j == 0) {
                                sum += j;
                            }
                        }
                        if(sum == arr[i]) {
                            count++;
                        }
                    }
                    printf("So luong cac so hoan hao trong mang: %d\n", count);
                }
                break;
            // Sap xep mang theo thu tu giam dan
            case 9:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                for(int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while(j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan: ");
                for(int i = 0; i < n; i++){
                    printf("%d", arr[i]);
                    if(i < n - 1) {
                        printf(", ");
                    }
                }
                break;
            // Tim gia tri lon thu hai co trong mang
            case 10:
                if(n < 2) {
                    printf("Khong du hai phan tu \n");
                    break;
                }
                int max = arr[0], maxtwo = -1;
                for(int i = 0; i < n; i++) {
                    if(arr[i] > max) {
                        maxtwo = max;
                        max = arr[i];
                    } else if(maxtwo < arr[i] && max != arr[i]) {
                        maxtwo = arr[i];
                    }
                }
                if(maxtwo == -1) {
                    printf("Khong co gia tri lon thu hai trong mang\n");
                } else {
                    printf("Gia tri lon thu hai trong mang la: %d\n", maxtwo);
                }
                break;
            // Tim kiem mot phan tu bang binary Search
            case 11:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                for(int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while(j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                int target = 0;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                int left = 0, right = n - 1, pos = -1;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(arr[mid] == target) {
                        pos = mid;
                        break; 
                    }
                    if(arr[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if(pos == -1) {
                    printf("Khong tim thay phan tu vua nhap\n");
                } else {
                    printf("Vi tri cua %d trong mang la: %d\n", target, pos);
                }
                break;
            // Dao nguoc thu tu cac phan tu co trong mang
            case 12:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                printf("Mang dao nguoc: ");
                for(int i = n - 1; i >= 0; i--) {
                    printf("%d ", arr[i]);
                }
                break;
            // Xoa toan bo cac phan tu trung lap va in toan bo cac phan tu doc lap
            case 13:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                int arr_b[100] = {0}, arr_c[100];
                int a = 0;
                for(int i = 0; i < n; i++) {
                    if(arr_b[arr[i]] == 0) {
                        arr_c[a] = arr[i];
                        arr_b[arr[i]] = 1;
                        a++;
                    }
                }
                printf("Xoa cac phan tu trung lap thanh cong\n");
                n = a;
                for(int i = 0; i < n; i++) {
                    arr[i] = arr_c[i];
                }
                break;
            // In cac phan tu la so chan sau do la cac phan tu so le
            case 14:
                if(n == 0) {
                    printf("Array is empty ^ ^\n");
                    break;
                }
                printf("Cac phan tu chan dung truoc le dung sau: ");
                int arr_1[100], arr_2[100], even = 0, odd = 0; 
                for(int i = 0; i < n; i++) {
                    if(arr[i] % 2 == 0) {
                        arr_1[even++] = arr[i]; 
                        arr_2[odd++] = arr[i]; 
                    }
                }
                for(int i = 0; i < even; i++) {
                    printf("%d ", arr_1[i]); 
                }
                for(int i = 0; i < odd; i++) {
                    printf("%d ", arr_2[i]); 
                }
                break;
            // Exit
            case 15:
                printf("Thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le ^ ^\n");
        }
    }
}