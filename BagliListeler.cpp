#include <stdio.h>
#include <stdlib.h>

// Node yap�s�
struct Node {
    int veri;
    struct Node* sonraki;
};

// Ba�lang��ta bo� olan ba� (head) d���m
struct Node* bas = NULL;

// Yeni d���m olu�turma fonksiyonu
struct Node* dugumOlustur(int veri) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

// Ba�a ekleme fonksiyonu
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
        printf("Verisi %d olan d���m bulunamad�.\n", anahtar);
    }
}

// D���m silme fonksiyonu
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
        printf("Verisi %d olan d���m bulunamad�.\n", anahtar);
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

// Listeyi yazd�rma fonksiyonu
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
        printf("\n--- Men� ---\n");
        printf("1. Ba�a ekle\n");
        printf("2. Sona ekle\n");
        printf("3. Araya ekle\n");
        printf("4. D���m sil\n");
        printf("5. D���m ara\n");
        printf("6. Listeyi yazd�r\n");
        printf("7. ��k��\n");
        printf("Se�iminizi yap�n: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklemek istedi�iniz veriyi girin: ");
                scanf("%d", &veri);
                basaEkle(veri);
                break;
            case 2:
                printf("Eklemek istedi�iniz veriyi girin: ");
                scanf("%d", &veri);
                sonaEkle(veri);
                break;
            case 3:
                printf("Eklemek istedi�iniz veriyi girin: ");
                scanf("%d", &veri);
                printf("Hangi d���mden sonra eklemek istiyorsunuz (veri): ");
                scanf("%d", &anahtar);
                arayaEkle(veri, anahtar);
                break;
            case 4:
                printf("Silmek istedi�iniz d���m�n verisini girin: ");
                scanf("%d", &anahtar);
                dugumSil(anahtar);
                break;
            case 5:
                printf("Aramak istedi�iniz d���m�n verisini girin: ");
                scanf("%d", &anahtar);
                if (dugumAra(anahtar)) {
                    printf("Verisi %d olan d���m bulundu.\n", anahtar);
                } else {
                    printf("Verisi %d olan d���m bulunamad�.\n", anahtar);
                }
                break;
            case 6:
                printf("Ba�l� Liste: ");
                listeyiYazdir();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Ge�ersiz se�im. L�tfen tekrar deneyin.\n");
        }
    }

    return 0;
}

