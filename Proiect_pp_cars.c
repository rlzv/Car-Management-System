#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define GREEN 2
#define BLUE 3
#define RED 12
#define YELLOW 14
#define WHITE 15
#define MAGENTA 13

void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

typedef struct masina{
    char sasiu[15],caroserie[15],marca[15];
    int km, an_fabricatie,id,pret;
    struct masina *next;    //retin date
}masina_t;
masina_t *head = NULL;
int id_curent = 0; /* ca sa sterg mai usor(identificator unic)*/

void sterge_masina(int sters_id){

    if (head == NULL){
            set_color(RED);
        printf("Stoc-ul de masini nu mai exista, va rugam adaugati masini: ");
        set_color(WHITE);
    }

    masina_t *curent = head;
    masina_t *previous = NULL;

    while (curent != NULL){
        if (curent->id == sters_id && curent == head){       //stergerea primului nod/element din lista simplu inlantuita
                head = curent->next;
                free(curent);           //dealocam memoria alocata lui curent
                break;
        }
        else if (curent->id == sters_id){   //id-ul urmatorului nod fata de cel curent [al doilea elem are un pointer catre al treilea si primu catre al doilea (face ca primul elem sa aiba legatura cu a)];;

                previous->next = curent->next;       //pun pe al urmatorul dupa cel curent elem din lista
                free(curent);
                break;
        }

        previous = curent;
        curent = curent->next;
    }

}


void filtru_an_fabricatie(){
        masina_t *curent = head;


    int an_fabricatie;
    printf("Introduceti anul: ");
    scanf("%d",&an_fabricatie);


    while(curent != NULL){
        if (curent->an_fabricatie >= an_fabricatie){
                set_color(BLUE);
            printf("ID: %d\n", curent->id);
            printf("Serie sasiu: %s\n", curent->sasiu);
            printf("Numar km rulati: %d\n", curent->km);
            printf("Anul fabricatiei: %d\n", curent->an_fabricatie);
            printf("Tip caroserie: %s\n", curent->caroserie);
            printf("Marca: %s\n", curent->marca);
            printf("Pretul: %d\n", curent->pret);
        set_color(WHITE);
            printf("\n");

        }

        curent = curent->next;
    }

}


void filtru_marca(){

    masina_t *curent = head;


    char marca[15];
    printf("Introduceti marca: ");
    scanf("%s",marca);


    while(curent != NULL){
        if (strcmp(marca, curent->marca) == 0){  //filtru pt ceva ce ii string
                set_color(BLUE);
            printf("ID: %d\n", curent->id);
            printf("Serie sasiu: %s\n", curent->sasiu);
            printf("Numar km rulati: %d\n", curent->km);
            printf("Anul fabricatiei: %d\n", curent->an_fabricatie);
            printf("Tip caroserie: %s\n", curent->caroserie);
            printf("Marca: %s\n", curent->marca);
            printf("Pretul: %d\n", curent->pret);
        set_color(WHITE);
            printf("\n");

        }

        curent = curent->next;
    }

}

void filtru_km(){

    masina_t *curent = head;


    int km;
    printf("Introduceti numarul de km: ");
    scanf("%d",&km);


    while(curent != NULL){
        if (curent->km <= km){
                set_color(BLUE);
            printf("ID: %d\n", curent->id);
            printf("Serie sasiu: %s\n", curent->sasiu);
            printf("Numar km rulati: %d\n", curent->km);
            printf("Anul fabricatiei: %d\n", curent->an_fabricatie);
            printf("Tip caroserie: %s\n", curent->caroserie);
            printf("Marca: %s\n", curent->marca);
            printf("Pretul: %d\n", curent->pret);
        set_color(WHITE);
            printf("\n");

        }

        curent = curent->next;
    }

}


void filtru_pret(){
    masina_t *curent = head;
        int pret;
    printf("Introduceti pretul maxim: ");
    scanf("%d",&pret);

    while(curent != NULL){
        if (curent->pret <= pret){
                set_color(BLUE);
            printf("ID: %d\n", curent->id);
            printf("Serie sasiu: %s\n", curent->sasiu);
            printf("Numar km rulati: %d\n", curent->km);
            printf("Anul fabricatiei: %d\n", curent->an_fabricatie);
            printf("Tip caroserie: %s\n", curent->caroserie);
            printf("Marca: %s\n", curent->marca);
            printf("Pretul: %d\n", curent->pret);
        set_color(WHITE);
            printf("\n");

        }

        curent = curent->next;
    }

}

void aduga_masina(){
    masina_t *curent = head;
    while(curent != NULL && curent->next != NULL)
        curent = curent->next;
    masina_t *masina_noua = (masina_t *) malloc(sizeof(masina_t));
    masina_noua->id = id_curent;
    id_curent++;

    printf("Introduceti seria de sasiu: ");
    scanf("%s", masina_noua->sasiu);

    printf("Numarul de km rulati: ");
    scanf("%d", &masina_noua->km);

    printf("Anul fabricatiei: ");
    scanf("%d", &masina_noua->an_fabricatie);

    printf("Tip caroserie: ");
    scanf("%s", masina_noua->caroserie);

    printf("Marca: ");
    scanf("%s", masina_noua->marca);

    printf("Pret: ");
    scanf("%d", &masina_noua->pret);


    masina_noua->next = NULL;
    if (head == NULL)
        head = masina_noua;
    else
        curent->next = masina_noua;
}
void print_masini(void){
    masina_t *curent = head;
    while(curent != NULL){
            set_color(MAGENTA);
        printf("ID:");
        set_color(YELLOW);
        printf("%d\n", curent->id);
        set_color(MAGENTA);
        printf("Serie sasiu: ");
        set_color(YELLOW);
        printf("%s\n", curent->sasiu);
        set_color(MAGENTA);
        printf("Numar km rulati ");
        set_color(YELLOW);
        printf("%d\n", curent->km);
        set_color(MAGENTA);
        printf("Anul fabricatiei: ");
        set_color(YELLOW);
        printf("%d\n", curent->an_fabricatie);
        set_color(MAGENTA);
        printf("Tip caroserie: ");
        set_color(YELLOW);
        printf("%s\n", curent->caroserie);
        set_color(MAGENTA);
        printf("Marca: ");
        set_color(YELLOW);
        printf("%s\n", curent->marca);
        set_color(MAGENTA);
        printf("Pretul: ");
        set_color(YELLOW);
        printf("%d\n", curent->pret);
        set_color(WHITE);
        printf("\n");

        curent = curent->next;

    }
    if (head == NULL){
            set_color(RED);
        printf("Nu mai exista masini in stoc!!!!\n");
    set_color(WHITE);
        return;                                     //asta opreste functia mai devreme
    }

    set_color(GREEN);
    printf("Doriti sa filtrati dupa un anumit criteru?\n");
    printf("\t1. Pret\n\t2. KM\n\t3. Marca\n\t4. An fabricatie\n\t5. Niciunul\n");
    set_color(WHITE);
    int temporary;
    scanf("%d", &temporary);
    switch (temporary){
        case (1):{
            filtru_pret();
            break;
        }
        case (2):{
            filtru_km();
            break;
        }
        case (3):{
            filtru_marca();
            break;
        }
        case (4):{
            filtru_an_fabricatie();
            break;
        }
        default:
            break;
    }
}


void load_masini() {
    FILE *f = fopen("input.txt", "r");
    masina_t* curent = head;

    while(curent != NULL && curent->next != NULL)
        curent = curent->next;

    char sasiu[15],caroserie[15],marca[15];
    int km, an_fabricatie,id,pret;


    while(fscanf(f, "%s %s %d %d %s %d", marca, sasiu, &km, &an_fabricatie, caroserie, &pret) == 6){
        masina_t *masina_noua = (masina_t *) malloc(sizeof(masina_t));
        masina_noua->id = id_curent;
        id_curent++;

        strcpy(masina_noua->marca, marca);
        strcpy(masina_noua->sasiu, sasiu);
        masina_noua->km = km;
        masina_noua->an_fabricatie = an_fabricatie;
        strcpy(masina_noua->caroserie, caroserie);
        masina_noua->pret = pret;

        masina_noua->next = NULL;

        if (head == NULL)
            head = masina_noua;
        else
            curent->next = masina_noua;
        curent = masina_noua;


    }
    fclose(f);
}

void save_masini(){
    FILE *f = fopen("input.txt", "w");
    masina_t *curent = head;
    while(curent != NULL){
        fprintf(f, "%s %s %d %d %s %d\n",curent->marca, curent->sasiu, curent->km, curent->an_fabricatie, curent->caroserie, curent->pret);

        curent = curent->next;

    }
    fclose(f);
}

void mainmenu(void)
{
    system("cls");
    set_color(WHITE);
    printf("\t==============================\n");
    set_color(RED);
    printf("\t\t\t BUN VENIT LA CACIAU DEALERS\n");
    set_color(GREEN);
    printf("\t1. VINDE MASINA\n\t2. AFISEAZA MASINI\n\t3. CUMPARA MASINA\n\t0. EXIT\n");
    set_color(WHITE);
    printf("\t==============================\n");
    set_color(YELLOW);
    printf("Introdu optiunea-->");
    set_color(WHITE);

    int alege,id_cumparare;
    scanf("%d",&alege);
    while(alege != 0){
        switch (alege){
            case (1):{
                aduga_masina();
                break;
            }
            case (2):{
                print_masini();
                system("pause");
                break;
            }
            case (3):{
                print_masini();
                if (head != NULL){              //intreaba ce masina vr sa cumperi daca exista masina
                    printf("Selecteaza ID-ul masinii: ");
                    scanf("%d", &id_cumparare);
                    sterge_masina(id_cumparare);
                }
                break;
            }
            default:
                break;

        }
        save_masini();//cand se face orice operatie se actualizeaza lista de masini!!!

        system("cls");
        printf("\t==============================\n");
        set_color(GREEN);
        printf("\t1. VINDE MASINA\n\t2. AFISEAZA MASINI\n\t3. CUMPARA MASINI\n\t0. EXIT\n");
        set_color(WHITE);
        printf("\t==============================\n");

        printf("Introdu optiunea-->");
        scanf("%d",&alege);
    }

    system("cls");
    printf("\n\n\n");
    printf("\t==============================\n");
    printf("\t\t\tMultumim client CACIAU\n");
    printf("\t\tVA MAI ASTEPTAM!!!!!\n");
    printf("\t==============================\n");
}


int main()
{
    load_masini();
    mainmenu();
    save_masini();
    return 0;
}

