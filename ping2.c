#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct Node{
	char word[10000];
	struct Node* next;
};
struct Node* head;
 
void Insert(char *word){
	struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->word,word);
	temp->next = head;
	head = temp;
}
 
void Inverse(){
	struct Node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		
	}
	head = prev;
		
}
 
 
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%s\n",temp->word);
		
		temp = temp->next;
	}
 
}
 
 
int main(){
	head = NULL;
	char word[10000];
	while(scanf("%s",word)!=EOF){
			Insert(word);
	}
	Print();
	Inverse();
	Print();
	//printf("\n");
}
