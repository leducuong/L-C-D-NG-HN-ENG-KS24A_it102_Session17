#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *mang, int *kichThuoc) {
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", kichThuoc);

    for (int i = 0; i < *kichThuoc; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);  
    }
}

void hienThiMang(int *mang, int kichThuoc) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < kichThuoc; i++) {
        printf("%d ", mang[i]); 
    }
    printf("\n");
}

int tinhTong(int *mang, int kichThuoc) {
    int tong = 0;
    for (int i = 0; i < kichThuoc; i++) {
        tong += mang[i];  
    }
    return tong;
}

int timMax(int *mang, int kichThuoc) {
    int max = mang[0]; 
    for (int i = 1; i < kichThuoc; i++) {
        if (mang[i] > max) {
            max = mang[i];
        }
    }
    return max;
}

int main() {
    int mang[100];
    int kichThuoc = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(mang, &kichThuoc);
                break;
            case 2:
                hienThiMang(mang, kichThuoc);
                break;
            case 3:
                printf("Do dai mang: %d\n", kichThuoc);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTong(mang, kichThuoc));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang: %d\n", timMax(mang, kichThuoc));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}

