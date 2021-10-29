#include <stdio.h>
#define MAXN 100
#define N 100

/*struct key
{
	int cheie;
	char nume[20];
	char prenume[10];
};*/

int A[MAXN];
int chei[MAXN];
//struct key chei[MAXN];
unsigned int contor;
unsigned int tab[N];

//functia insereaza un nod cu cheieN ca fiu la nodul cu cheieT
//functia retureneaza < 0 in caz de eroare
int insereaza(int cheieN, int cheieT)
{
	int i;
	for (i = 0; i < MAXN; i++)
	{
		if (chei[i] == cheieT) // i index pt T
			break;
	}
	if (chei[i] != cheieT)
	{
		printf("Insereaza(): Nu am gasit cheia pentru T nodul tata\n");
		return -1;
	}
	if (contor == MAXN)
	{
		printf("insereaza(): Arborele A este plin. contor == MAXN!\n");
		return -1;
	}
	A[contor] = i; // i este indexul pentru T 
	chei[contor] = cheieN;
	contor++;
	return 0; // totul e ok
}
//functia returneaza parintele nodului N din arborele A 
int tata(int cheieN)
{
	int i;
	for (i = 0; i < contor; i++)
	{
		if (chei[i] == cheieN)
			break;
	}
	if (chei[i] != cheieN)
	{
		printf("tata(): Nu am gasit nodul N in arborele A");
		return -1;
	}
	return chei[A[i]]; //returneaza cheia parintelui pt nodul N
}

int suprima(int cheieN) //functia suprima nodul cu cheieN su=i toti descendentii sai
{
	int i, j;
	for (i = 0; i<contor; i++)

	{
		if (chei[i] == cheieN) break;
	}
	if (chei[i] != cheieN)
	{
		printf("Suprima(): nu exista cheia pe care doriti sa o stergeti!\n");
		return -1;
	}
	chei[i] = 0;
	A[i] = 0; //radacina are si ea parinte pe 0,dar e mereu pe pozitia i=0
	for (j = 0; j < contor; j++)
	{
		if (A[j] == i) suprima(chei[j]);
	}
}
//functia returneaza primul fiu al nodului cu cheia cheieN din A
int primulfiu(int cheieN)
{
	int i, j;
	for (i = 0; i < contor; i++)
	{
		if (chei[i] == cheieN)
			break;
	}
	if (chei[i] != cheieN)
	{
		printf("primul fiu(): Nu am gasit nodul cu cheia cheieN\n");
		return -1;
	}
	for (j = 0; j < contor; j++)
	{
		if (A[j] == i)
			break;
	}
	if (A[j] != i)
	{
		printf("primulfiu(): Nodul cu cheia cheieN nu are fii.\n");
		return -1;
	}
	return chei[j]; //cheia primului fiu al nodului cu cheia cheieN
}
int radacina(void) {
	if (contor == 0) {
		/*Arborele A este vid!*/
		return -1;
	}
	else return chei[0];
}
int testvid(void) {
	if (contor == 0) 
		return -1;
	
	
}
void initializeaza(void)
{
	int i;
	for (i = 0; i < contor; i++)
	{
		chei[i] = 0;
		A[i] = 0;
	}
	contor = 0;
	return;
}
struct nod {
	int date;
	struct node* stanga;
	struct node* dreapta;
};
struct nod* newNode(int date) {
	struct nod* nod = (struct nod*)malloc(sizeof(struct nod));
	nod->date = date;
	nod->stanga = NULL;
	nod->dreapta = NULL;
	return (nod);
}
//functie pentru afisare postordine
void printPostordine(struct nod* nod) {
	if (nod == NULL)
		return;
	printPostordine(nod->stanga);//membrul stang
	printPostordine(nod->dreapta);//membrul drept
	printf("%d", nod->date);//radacina

}
//functie pentru afisare inordine
void printInordine(struct nod* nod) {
	if (nod == NULL)
		return;
	printInordine(nod->stanga);//membrul stang
	printf("%d", nod->date);//radacina
	printInordine(nod -> dreapta);//membrul drept
}

void printPreordine(struct nod*nod) {
	if (nod == NULL)
		return;
	printf("%d", nod->date);//radacina
	printPreordine(nod->stanga);//membrul stang
	printPreordine(nod->dreapta);//membrul drept

}


int main(void)
{
	struct nod* root = newNode(1);
	root->stanga = newNode(2);
	root->dreapta = newNode(3);
	root->stanga = newNode(4);
	root->dreapta = newNode(5);
	int opt, cheieN, cheieT;
	FILE* fp;
	int i,cheie;
	unsigned int num;
	

	fp = fopen("INPUT.DAT", "wb");
	if (!fp)
	{
		printf("Eroare la deschiderea fisierului.");
		perror("fopen()");
		return -1;

		fclose(fp);


	}
	fclose(fp);
	do {
		printf("\n1.Tata\n");
		printf("2.Primul fiu\n");
		printf("3.Frate drept\n");
		printf("4.Cheie\n");
		printf("5.Radacina\n");
		printf("6.Initializaeaza arbore \n");
		printf("7.Insereaza nod \n");
		printf("8.Suprima nod \n");
		printf("9.Afisare inordine\n");
		printf("10.Afisare preordine\n");
		printf("11.Afisare postordine\n");
		printf("0.Iesire\n");
		printf("Optiunea aleasa: \n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: tata(chei);
			break;
		case 2: primulfiu(chei);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:radacina();
			break;
		case 6:initializeaza();
			break;
		case 7:insereaza(chei,chei);
			break;
		case 8:printf("Dati cheia pe care doriti sa o stergeti:\n");
			scanf(" % d", &cheie);
			suprima(chei);
			break;
		case 9: printf("\n Afisarea in inordine este:");
			printInordine(root);
			break;
		case 10:printf("\n Afisarea in preordine este:");
			printPreordine(root);
			break;
		case 11:printf("\n Afisarea in postordine este:");
			printPostordine(root);
			break;
		case 0:exit(0);

		default:printf("Optiunea aleasa este gresita!\n");
			break;
		}
		
		
}
	while (opt != 0);
return 0;
}