#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
//fonction qui est charger de recuperer l'entete dans le fichier header.txt

void getHeader(void){
char headerTxt[1024];
FILE *header=fopen("header.txt","r+");
//lecture de toute le fichier
while((fgets(headerTxt,1024,header))!=NULL){

    //attribution de l'entete aux fichiers

};
}
// recupere le footer dans un fichier txt
void getFooter(void){
char footerTxt[1024];
FILE *footer=fopen("footer.txt","r+");
//lecture de toute le fichier
while((fgets(footerTxt,1024,footer))!=NULL){

    //attribution des pieds de pages aux fichiers

};
}
int getUserSegmentNumber(void){
    int lines;
printf("veuiller saisir le nombre de lignes a segmenter dans le fichiers");
scanf("%d",lines);
lines =0;
return lines;
}

void getUserfilesAndSegment(){


//gestion de l'erreur au cas ou path >256

FILE *fileToSegment=fopen("StaticDataValeurDepenseBudget.txt","w+");
// inactive section
char fileTxtPerLine[1024];
int line=0;
int indexOfSegment=1;
char nameOfFile[255];
//inactive section
//lecture de toute le fichier
while((fgets(fileTxtPerLine,1024,fileToSegment))!=NULL){
line++;

if ((line%5000)==0){
        indexOfSegment++;


    //creation du nouveau fichier
snprintf(nameOfFile,255,"StaticDataValeurDepenseBudget%d.txt",indexOfSegment);

FILE *segment=fopen(nameOfFile,"w");

fprintf(segment,fileTxtPerLine);
fclose(segment);




};

};
fclose(fileToSegment);

printf("l'operation de segementaion est achever avec succes avons obtenue : %d fichier segmenter" , indexOfSegment);


}
//fonction principale
int main(){
    getHeader();
    getFooter();

    printf("1");
    getUserfilesAndSegment();
}






























































































































































