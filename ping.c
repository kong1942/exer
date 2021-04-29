#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
char *getword(char *text,char *word){
	char *ptr = text;
	char *qtr = word;
	while(*ptr!='\0' && isspace(*ptr)){
		ptr++;	
	}
	while(*ptr!='\0' && !isspace(*ptr)){
		*qtr++=*ptr++;
	}
	*qtr='\0';
	if(qtr-word==0){
		return NULL;
	}
	return ptr;
}
 
 
int main(){
	char input[10000];
	char word[1000];
	char *ptr;
	char array[1000][1000];
 
	double stack[1000];
	int index = 0;
 
	while(fgets(input,10000,stdin)){
		ptr = input;
		int i=0;
		index=0;
		while(ptr = getword(ptr,word)){
			//printf("偵測到的值：%s\n",word);
			if(strcmp(word,"+")==0){
				stack[index-2]=stack[index-2]+stack[index-1];
				index--;
			}
			else if(strcmp(word,"-")==0){
				stack[index-2]=stack[index-2]-stack[index - 1];
				index--;
			}
			else if(strcmp(word,"*")==0){
				stack[index-2]=stack[index-2]*stack[index-1];
				index--;
			}
			else if(strcmp(word,"/")==0){
				stack[index-2]=stack[index-2]/stack[index-1];
				index--;
			}
			else{
				stack[index] = atof(word);
				index++;
			}
		}
		printf("%.2f\n",stack[index-1]);
		/*printf("\n偵測到的陣列\n");
		for(int k=0;k<i;k++){
			printf("%s\n",array[k]);
		}*/
		
		
	}
}
