#include <stdio.h>
#include <string.h>

void daoNguocChuoi(char *chuoi) {
    int len = strlen(chuoi);
    for (int i = 0; i < len / 2; i++) {
        char temp = chuoi[i];
        chuoi[i] = chuoi[len - i - 1];
        chuoi[len - i - 1] = temp;
    }
}

int demSoTu(char *chuoi) {
    int dem = 0, inWord = 0;
    while (*chuoi) {
        if (*chuoi == ' ' || *chuoi == '\t' || *chuoi == '\n') inWord = 0;
        else if (!inWord) {
            inWord = 1;
            dem++;
        }
        chuoi++;
    }
    return dem;
}

void inHoaChuoi(char *chuoi) {
    while (*chuoi) {
        if (*chuoi >= 'a' && *chuoi <= 'z') *chuoi -= 32;
        chuoi++;
    }
}

void themChuoi(char *chuoi1, char *chuoi2) {
    strcat(chuoi1, chuoi2);
}

int main() {
    char chuoi[1000] = "";
    char chuoiKhac[1000] = "";
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                printf("Nhap chuoi: ");
                fgets(chuoi, 1000, stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';
                break;
            case 2: {
                char chuoiDaoNguoc[1000];
                strcpy(chuoiDaoNguoc, chuoi);
                daoNguocChuoi(chuoiDaoNguoc);
                printf("Chuoi dao nguoc: %s\n", chuoiDaoNguoc);
                break;
            }
            case 3:
                printf("So tu trong chuoi: %d\n", demSoTu(chuoi));
                break;
            case 4:
                printf("Nhap chuoi khac: ");
                fgets(chuoiKhac, 1000, stdin);
                chuoiKhac[strcspn(chuoiKhac, "\n")] = '\0';
                if (strlen(chuoiKhac) > strlen(chuoi)) printf("Chuoi khac dai hon chuoi ban dau\n");
                else if (strlen(chuoiKhac) < strlen(chuoi)) printf("Chuoi khac ngan hon chuoi ban dau\n");
                else printf("Hai chuoi co do dai bang nhau\n");
                break;
            case 5:
                inHoaChuoi(chuoi);
                printf("Chuoi sau khi in hoa: %s\n", chuoi);
                break;
            case 6:
                printf("Nhap chuoi khac de them: ");
                fgets(chuoiKhac, 1000, stdin);
                chuoiKhac[strcspn(chuoiKhac, "\n")] = '\0';
                themChuoi(chuoi, chuoiKhac);
                printf("Chuoi sau khi them: %s\n", chuoi);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

