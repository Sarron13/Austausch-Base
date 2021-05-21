#include <stdio.h>
#include <stdlib.h>

typedef struct baum {
    int daten;
    struct baum *links;
    struct baum *rechts;
} BinaerBaum;

BinaerBaum *erstelleBaum(int);
void erstelleEbene(BinaerBaum *, int);
void ausgabeInLevelOrder(int, BinaerBaum*);
void ausgabeEbene();

int main(void) {
    BinaerBaum *pStart = erstelleBaum(2);
    ausgabeInLevelOrder(3, pStart);
    return 0;
}

BinaerBaum *erstelleBaum(int anzahlEbenen) {
    BinaerBaum *pStart = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    BinaerBaum *pElement = pStart;

    pStart->daten = 0;
    pStart->links = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->links->daten = 1;
    pStart->rechts = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->rechts->daten = 1;
    pStart->links->links = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->links->links->daten = 2;
    pStart->links->links->links = NULL;
    pStart->links->links->rechts = NULL;
    pStart->links->rechts = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->links->rechts->daten = 2;
    pStart->links->rechts->links = NULL;
    pStart->links->rechts->rechts = NULL;
    pStart->rechts->links = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->rechts->links->daten = 2;
    pStart->rechts->links->links = NULL;
    pStart->rechts->links->rechts = NULL;
    pStart->rechts->rechts = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    pStart->rechts->rechts->daten = 2;
    pStart->rechts->rechts->links = NULL;
    pStart->rechts->rechts->rechts = NULL;

    /***************
    Erstellter Baum:

         0
        /  \
       1    1
      / \  / \
     2  2  2  2
    ***************/
    return pStart;
}

void erstelleEbene(BinaerBaum *pElement, int ebene) {
    //NOT EMPLEMENTED YET
}

/**********************************************************
Variablen & Bedeutung:
anzEbenen       => Anzahl der auszugebenen Ebenen
momentaneZEbene => momentane Zielebene (Zieltiefe)
mEbene          => momentane Ebene
zEbene          => Zielebene (Zieltiefe) [momentaneZEbene]
**********************************************************/

void ausgabeInLevelOrder(int anzEbenen, BinaerBaum *pStart) {
    int momentaneZEbene = 0;
    while (momentaneZEbene < anzEbenen) {
        ausgabeEbene(0, momentaneZEbene, pStart);
        printf("\n");
        momentaneZEbene++;
    }
}

void ausgabeEbene(int mEbene, int zEbene, BinaerBaum *pEbene) {
    if(pEbene == NULL) {
        return;
    }
    if(mEbene == zEbene) {
        printf("%d", pEbene->daten);
        return;
    }
    ausgabeEbene(mEbene+1, zEbene, pEbene->links);
    ausgabeEbene(mEbene+1, zEbene, pEbene->rechts);
    return;
}
