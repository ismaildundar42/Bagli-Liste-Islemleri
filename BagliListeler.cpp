#include <stdio.h>
#include <stdlib.h>

// Node yapýsý
struct Node {
    int veri;
    struct Node* sonraki;
};

// Baþlangýçta boþ olan baþ (head) düðüm
struct Node* bas = NULL;

// Yeni düðüm oluþturma fonksiyonu
struct Node* dugumOlustur(int veri) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

// Baþa ekleme fonksiyonu
void basaEkle(int veri) {
    struct Node* yeniDugum = dugumOlustur(veri);
    yeniDugum->sonraki = bas;
    bas = yeniDugum;
}

// Sona ekleme fonksiyonu
void sonaEkle(int veri) {
    struct Node* yeniDugum = dugumOlustur(veri);
    if (bas == NULL) {
        bas = yeniDugum;
        return;
    }
    struct Node* temp = bas;
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }
    temp->sonraki = yeniDugum;
}

// Araya ekleme fonksiyonu
void arayaEkle(int veri, int anahtar) {
    struct Node* temp = bas;
    while (temp != NULL && temp->veri != anahtar) {
        temp = temp->sonraki;
    }
    if (temp != NULL) {
        struct Node* yeniDugum = dugumOlustur(veri);
        yeniDugum->sonraki = temp->sonraki;
        temp->sonraki = yeniDugum;
    } else {
        printf("Verisi %d olan düðüm bulunamadý.\n", anahtar);
    }
}

// Düðüm silme fonksiyonu
void dugumSil(int anahtar) {
    struct Node* temp = bas;
    struct Node* onceki = NULL;
    if (temp != NULL && temp->veri == anahtar) {
        bas = temp->sonraki;
        free(temp);
        return;
    }
    while (temp != NULL && temp->veri != anahtar) {
        onceki = temp;
        temp = temp->sonraki;
    }
    if (temp == NULL) {
        printf("Verisi %d olan düðüm bulunamadý.\n", anahtar);
        return;
    }
    onceki->sonraki = temp->sonraki;
    free(temp);
}

// Arama fonksiyonu
int dugumAra(int anahtar) {
    struct Node* temp = bas;
    while (temp != NULL) {
        if (temp->veri == anahtar) {
            return 1;
        }
        temp = temp->sonraki;
    }
    return 0;
}

// Listeyi yazdýrma fonksiyonu
void listeyiYazdir() {
    struct Node* temp = bas;
    while (temp != NULL) {
        printf("%d -> ", temp->veri);
        temp = temp->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int secim, veri, anahtar;

    while (1) {
        printf("\n--- Menü ---\n");
        printf("1. Baþa ekle\n");
        printf("2. Sona ekle\n");
        printf("3. Araya ekle\n");
        printf("4. Düðüm sil\n");
        printf("5. Düðüm ara\n");
        printf("6. Listeyi yazdýr\n");
        printf("7. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklemek istediðiniz veriyi girin: ");
                scanf("%d", &veri);
                basaEkle(veri);
                break;
            case 2:
                printf("Eklemek istediðiniz veriyi girin: ");
                scanf("%d", &veri);
                sonaEkle(veri);
                break;
            case 3:
                printf("Eklemek istediðiniz veriyi girin: ");
                scanf("%d", &veri);
                printf("Hangi düðümden sonra eklemek istiyorsunuz (veri): ");
                scanf("%d", &anahtar);
                arayaEkle(veri, anahtar);
                break;
            case 4:
                printf("Silmek istediðiniz düðümün verisini girin: ");
                scanf("%d", &anahtar);
                dugumSil(anahtar);
                break;
            case 5:
                printf("Aramak istediðiniz düðümün verisini girin: ");
                scanf("%d", &anahtar);
                if (dugumAra(anahtar)) {
                    printf("Verisi %d olan düðüm bulundu.\n", anahtar);
                } else {
                    printf("Verisi %d olan düðüm bulunamadý.\n", anahtar);
                }
                break;
            case 6:
                printf("Baðlý Liste: ");
                listeyiYazdir();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

