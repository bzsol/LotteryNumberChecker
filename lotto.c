#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char datum[50];
    int szam[5];
} lotto;

int sor = 0;

int main() {
int swapped,k;
lotto adat[1000];
char c;
char * file = "otos.csv";
FILE * fp;
fp = fopen(file,"r");

if(fp == NULL){
    perror("HIBA!");
    exit(1);
}
 // Sorok megszámlálása
for (c = getc(fp); c != EOF; c = getc(fp)) {
    if(c == '\n'){
        sor++;
    }
// 798 elvileg
}
//printf("%d\n",sor);

char string[100] = "";
int x = 0;
rewind(fp);
for(int i=0;i<sor;i++){
    fgets(string,100,fp);
    char * token = strtok(string, ";");
    strcpy(adat[i].datum,token);
    token = strtok(NULL, ";");
    adat[i].szam[0] = atoi(token);
    token = strtok(NULL, ";");
    adat[i].szam[1] = atoi(token);
    token = strtok(NULL, ";");
    adat[i].szam[2] = atoi(token);
    token = strtok(NULL, ";");
    adat[i].szam[3] = atoi(token);
    token = strtok(NULL, ";");
    adat[i].szam[4] = atoi(token);
    token = strtok(NULL, ";");

    
}
// Kiírása az adatoknak
/*
for(int i=0;i<sor;i++){
    printf( "%s\n",adat[i].datum);
    for(x = 0;x<5;x++){
    printf("%d\n",adat[i].szam[x]);
    }
}
*/
// Vizsgálat:

printf("Kerem adja meg az ottoslotto tippjet: \n");
int talalat = 0;
int kettes = 0,harmas = 0,negyes = 0,otos = 0;
int j = 0;
int tipp[5];
scanf("%d %d %d %d %d",&tipp[0],&tipp[1],&tipp[2],&tipp[3],&tipp[4]);
// Olcsó rendező ciklus
while(1) {
    swapped = 0;
    for(int i=0;i<5;i++){
    if(tipp[i]>tipp[i+1]){
        int temp = tipp[i];
        tipp[i] = tipp[i+1];
        tipp[i+1] = temp;
        swapped = 1;
    }

    }
    if(swapped == 0){
        break;
    }
}
// Vizsgáljuk meg hogy szerencsések vagyunk
puts("");
puts("");
printf("Eltalalt szamok eseten a nyertes jatek het:\n");

for(int i=0;i<sor;i++){
    for(int j = 0;j<5;j++){
        if(adat[i].szam[j] == tipp[j]){
            talalat++;
        }
    }
            if(talalat == 2){
                printf("%s\n",adat[i].datum);
                kettes++;
            }
            if(talalat == 3){
                printf("%s\n",adat[i].datum);
                harmas++;
            }
            if(talalat == 4){
                printf("%s\n",adat[i].datum);
                negyes++;
            }
            if(talalat == 5){
                printf("%s\n",adat[i].datum);
                otos++;
            }
        talalat = 0;
}
puts("");
printf("Talalatok:\n");
printf("kettes: %d\n",kettes);
printf("harmas: %d\n",harmas);
printf("negyes: %d\n",negyes);
printf("otos: %d\n",otos);
fclose(fp);

return 0;
}