#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
void filesearch();
struct leader{
	char player[20];
	int score1;
};
void hangman(){
	struct leader table;
	FILE *fptr;
	int *alpha;
	char word[50];
	char alphabets[26], genre[26], result[5];
	char character;
	char guess;
	int length1, length2, num;
	int x, y, z = 0, tries = 7, position = 1, a = 0, b=0, played=0;
	int check = 1, count1 = 0, count2 = 0, players = 0, choice;
	fclose(fopen("C:\\Hangman\\scores.txt", "w"));
	do{
	printf("WELCOME TO HANGMAN! PLEASE CHOOSE FROM THE OPTIONS BELOW:\n1-PLAY\n2-TODAY\'S SUMMARY\n3-EXIT GAME\n\nENTER CHOICE: ");
	scanf("%d", &choice);
	
	if(choice==1){
			played++;
			getchar();
		    printf("\nENTER WORD FOR OTHER PERSON TO GUESS: ");
	        gets(word);
	        printf("ENTER GENRE: ");
	        gets(genre);
	        printf("INPUT SUCCESSFULLY TAKEN. LET\'S START!\n");
	        printf("PLEASE WAIT");
        	printf(".");
        	sleep(1);
        	printf(" .");
        	sleep(1);
        	printf(" .");
	        sleep(1);

	        length1 = strlen(word);
	        char empty[length1];
	        for (x=0; x<length1; x++){
		        if (word[x]==' '){
			        empty[x]=' ';
		        } else {
		            empty[x]='_';
	            }
	    
	        }
	        for (y=0; y<26; y++){
		        alphabets[y]='_';
	        }
			
	        // Clear screen
	        system("cls"); 
	        sleep(1); 
	
	        length2 = strlen(genre);
	        for (x=0; x<length2; x++){
	            genre[x] = toupper(genre[x]);
            }
	        printf("GENRE IS: %s", genre);
	        printf("\n");
	        for (x=0; x<length1; x++){
	            printf("%c", empty[x]);
	            printf(" ");
            }
            printf("\n\n");
	
		    do{
	        printf("ENTER YOUR GUESS: ");
	        fflush(stdin);
	        scanf("%c", &guess);
	        guess = tolower(guess);
	        for (y=0; y<25; y++){
	    	    if (guess == alphabets[y]){
	    		    count2++;               
		        }
		    }
	        for (x=0; x<length1; x++){
	    	    word[x] = tolower(word[x]);
			    if (guess == word[x] && count2==0){
				    empty[x] = guess;
			        count1++;
		        }
		        printf("%c", empty[x]);
		        printf(" ");
	        }
	        if (count2==0){
	    	    z = guess - 97;
	    	    *alpha = z;
	    	    alphabets[*alpha] = guess;
		    }
	        printf("\n\n");
	        check = strncmp(empty, word, length1); 
	         
	        if (count1==0 && count2==0){
	    	    printf("INCORRECT GUESS!\n");
	    	    tries--;
	    	    printf("TRIES LEFT: %d\n\n", tries);
	    	    if (tries==0){
	    		break;                      
			}             
		    }else if (count1!=0 && count2==0){
			    printf("CORRECT GUESS!\n");
			    printf("TRIES LEFT: %d\n\n", tries);
		    }else if (count2!=0){
			    printf("LETTER REPEATED!\n");
			    printf("TRIES LEFT: %d\n\n", tries);
	        }
		    count1 = 0;                  
		    count2 = 0;
		    } while (check!=0);
		    if (check==0){
		        sleep(1);
		        system("cls");  
		        sleep(1);
                printf("CONGRATULATIONS YOU\'VE GUESSED THE WORD!!");
                printf("\nTHE WORD WAS... %s\n\n", word);
                strcpy(result, "WON");
            }else{
        	    printf("YOU\'VE RAN OUT OF TRIES! BETTER LUCK NEXT TIME!");
        	    printf("\nTHE WORD WAS... %s\n\n", word);
        	    strcpy(result, "LOST");
            }
		    fptr = fopen("scores.txt", "a");
	        if(fptr == NULL){
                printf("File Not Found!");             
            }else{    
			    getchar();    
			    int score = tries*10;
			    tries=7;
			    table.score1=score;
			    printf("YOUR SCORE: %d\n", score);
                printf("ENTER PLAYER NAME: ");
                char name[20];
                gets(name);
                strcpy(table.player, name);
                fprintf(fptr, "%s %d %s\n", table.player, table.score1, result);
                fclose(fptr);
                printf("\nTODAY\'S SUMMARY UPDATED");
            }
        	printf("\n\nRETURN TO HOME?\n1. YES\n2. NO\nENTER CHOICE: ");
        	scanf("%d", &choice);
        	if (choice==1){
        		printf("PLEASE WAIT");
        		printf(".");
        		sleep(1);
        		printf(" .");
        		sleep(1);
        		printf(" .");
        		sleep(1);
        		system("cls"); 
	            sleep(1);
        		continue;
			}else{
				exit(1);
			}
	}else if (choice==2){
		filesearch();
	    printf("\n\nRETURN TO HOME?\n1. YES\n2. NO\nENTER CHOICE: ");
        	scanf("%d", &choice);
        	if (choice==1){
        		printf("PLEASE WAIT");
        		printf(".");
        		sleep(1);
        		printf(" .");
        		sleep(1);
        		printf(" .");
        		sleep(1);
        		system("cls"); 
	            sleep(1);
        		continue;
			}else{
				exit(1);
			}
	}else if(choice==3){ 
		printf("LEAVING ALREADY? :\( SEE YOU AGAIN NEXT TIME!");
		sleep(2);
		exit(1);
	}else{
		printf("INCORRECT CHOICE");
	}
	}while(choice==1);
}
void filesearch(){
	printf("FUNCTION FILE SEARCH START\n\n");
	int x=0, score;
	char name[20], result[5];
	FILE *fptr;
	fptr = fopen("scores.txt", "r");
	if (fptr==NULL){
		printf("FILE NOT FOUND\n");
	}
    printf("TODAY\'S SUMMARY:\n");
	printf("    ==============================================\n");
	printf("        NAME           SCORE           RESULT\n");
	printf("    ==============================================\n");
	while(fscanf(fptr, "%s %d %s", name, &score, result)!=EOF){
		printf("%d)", x+1);
		fflush(stdin);
		printf("\t%s\t\t%d\t\t%s\n", name, score, result);
		x++;
	}
	fclose(fptr);
    printf("\nFUNCTION FILE SEARCH END\n");
}

int main(){
	printf("HANGMAN!\n");
	/*Beep(600,450);
    Beep(750,350);
	Beep(600,450);
    Beep(750,350);
	Beep(900,900);*/
	hangman();
}
