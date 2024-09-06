#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>


//fonction de segmentation
int segmentText(char nameOfRepositery [255],int numberOfLinePerFile,char FileName[255],char extension [4]){

char lineText [1024];
int numberOfLine=1;
int fileNumber=1;
char fullFilename [255];
bool canCreateFile=true;
FILE *segmentFile= NULL;
char fullFileNameOfSegmentFile[255];
snprintf(fullFilename,255,"%s.%s",FileName,extension);
FILE *file=fopen(fullFilename,"r+");

while(fgets(lineText,sizeof(lineText),file)!=NULL){

    if(canCreateFile){
            // initialisation de chaque fichier segment
        snprintf(fullFileNameOfSegmentFile,255,"%s/%s%d.%s",nameOfRepositery,FileName,fileNumber++,extension);
        segmentFile= fopen(fullFileNameOfSegmentFile,"w");
        // insertion d'un entete  a chaque ouverture du fichier
        AddHeader(segmentFile);
        canCreateFile=false;
    }else if((numberOfLine%numberOfLinePerFile)!=0){
        // insertion des donnes dans chaque fichier segment
            fprintf(segmentFile,lineText);

        }else{
            // insertion du pieds de page a la fin de l'insertion des donnees et fermeture du fichier
            Addfooter(segmentFile);
            fclose(segmentFile);
            canCreateFile=true;
        };

        numberOfLine++;


};
//messsage de fin de traitement et fermeture du fichier d'origine
printf("\n  %d fichiers  ont ete creer avec succes ",fileNumber);
fclose(file);
return 0;
 }

 // insertion d'un header sur toutes les pages

int AddHeader(FILE *segmentfile){
    char headerText[1024];
    FILE *header=fopen("header.txt","r");
    while(fgets(headerText,sizeof(headerText),header)!=NULL){
        fprintf(segmentfile,headerText);

    }
}
// fonction qui permet d'inserer un footer sur toutes les pages
int Addfooter(FILE *segmentfile){
    char footerText[1024];
    FILE *footer=fopen("footer.txt","r");
    while(fgets(footerText,sizeof(footerText),footer)!=NULL){
        fprintf(segmentfile,footerText);
    }
}
//creation du dossier qui contiendras les fichier
 void createRepository(char nameOfRepository[255]){
    mkdir(nameOfRepository);
}


 int main(void){

    printf("==========================================================================================================================================\n");
    printf("**********    **********    **********     ****         ***    **********   ***         *   **************  ***********   ***********\n");
    printf("*             *             *              *   *       *  *    *            *  *        *          *        *         *   *           *\n");
    printf("*             *             *              *    *     *   *    *            *   *       *          *        *         *   *           *\n");
    printf("*             *             *              *     *   *    *    *            *    *      *          *        *         *   *          *\n");
    printf("**********    **********    *              *       *      *    **********   *     *     *          *        *         *   ***********\n");
    printf("         *    *             *    *****     *              *    *            *      *    *          *        *         *   *         *\n");
    printf("         *    *             *    *   *     *              *    *            *       *   *          *        *         *   *          *\n");
    printf("         *    *             *        *     *              *    *            *        *  *          *        *         *   *           *\n");
    printf("**********    **********    **********     *              *    **********   *         ***          *        ***********   *            *\n");
    printf("==========================================================================================================================================\n");
    printf("\n\n==========================================================================================================================================\n");
    printf(" segmentor v1.0 est un outils permetant de segmenter un fichier html,txt,docx,php,css,js.... en plusieurs sous fichier independant \n"
           "\n\n");
    printf("==========================================================================================================================================\n");

     char nameOfRepositery [255];
     int numberOfLinePerFile;
     char nameOfSegmentFile[255];
     char FileName[255];
     char extension [4];
     // recuperation des choix du user par rapport au segment
     printf("veuiller saisir le nom du dossier dans lequel doit se situer les fichier: ");
     scanf("%s",& nameOfRepositery);
     printf("entrer le nom du fichier ( sans l'extension ):");
     scanf("%s",&FileName);
     printf("entrer l'extension du fichier (sans le '.') :");
     scanf("%s",&extension);
     printf("entrer le nombre de ligne a obtenir par fichier :");
     scanf("%d",&numberOfLinePerFile);

        // execution
     createRepository( nameOfRepositery);
     segmentText(nameOfRepositery,numberOfLinePerFile,FileName,extension);
     printf("\n\n merci d'avoir utiliser segmentor v1.0 concu par yann-morpheus Github:yann-morpheus\n");
   printf("==========================================================================================================================================\n");

 return 0;
 }


