#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

int main(){
	FILE *fptr;
	char word[50];
	char alphabets[25], genre[30];
	char character;
	char guess;
	int length1, length2, num;
	int x, y, z = 0, tries = 7, position = 1, a = 0;
	int check = 1, count1 = 0, count2 = 0, players = 0, choice;
	
        printf("ENTER WORD FOR OTHER PERSON TO GUESS: ");
	gets(word);
	printf("ENTER GENRE: ");
	gets(genre);
	printf("INPUT SUCCESSFULLY TAKEN. LET\'S START!");
	sleep(2);

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
	        alphabets[z] = guess;
	        z++;
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
        
		        fptr = fopen("C:\\Hangman\\scores.txt", "ab+");
	            if(fptr == NULL){
                    printf("Error!");             
                }else{
        	    getchar();        
			    int score = tries*10;
			    printf("YOUR SCORE: %d\n", score);
                printf("ENTER PLAYER NAME: ");
                char name[20];
                gets(name);
                fprintf(fptr, "%s: ", name);
                fprintf(fptr,"%d\n", score);
                fclose(fptr);
                }
            } else{
        	printf("YOU\'VE RUN OUT OF TRIES! BETTER LUCK NEXT TIME!");
        	printf("\nTHE WORD WAS... %s", word);
		    }
		}
