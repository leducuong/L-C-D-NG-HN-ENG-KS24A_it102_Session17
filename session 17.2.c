#include <stdio.h>
#include <string.h>

int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_alnum(char c) {
    return is_alpha(c) || is_digit(c);
}

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void nhapChuoi(char *chuoi) {
    fgets(chuoi, 1000, stdin);
    size_t len = strlen(chuoi);
    if (chuoi[len - 1] == '\n') chuoi[len - 1] = '\0';
}

void inChuoi(char *chuoi) {
    printf("Chuoi vua nhap: %s\n", chuoi);
}

int demChuCai(char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (is_alpha(*chuoi)) dem++;
        chuoi++;
    }
    return dem;
}

int demChuSo(char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (is_digit(*chuoi)) dem++;
        chuoi++;
    }
    return dem;
}

int demKyTuDacBiet(char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (!is_alnum(*chuoi) && !is_space(*chuoi)) dem++;
        chuoi++;
    }
    return dem;
}

int main() {
    char chuoi[1000] = "";
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1: nhapChuoi(chuoi); break;
            case 2: inChuoi(chuoi); break;
            case 3: printf("So luong chu cai trong chuoi: %d\n", demChuCai(chuoi)); break;
            case 4: printf("So luong chu so trong chuoi: %d\n", demChuSo(chuoi)); break;
            case 5: printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(chuoi)); break;
            case 6: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le. Vui long nhap lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}


