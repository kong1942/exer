#include <string.h>
#include <stdio.h>
int priority(char x) {
    switch(x) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    }
}

void in2post(char *infix,char *postfix){
	char Stack[1000]={'\0'};
	char *ptr = infix;
	int top = 0;
	int i = 0;

	while(*ptr){
		if(*ptr=='('){
			Stack[++top] = *ptr; 
		}
		else if(*ptr == ')'){
			while(Stack[top]!='('){
				postfix[i] = Stack[top];
				top--;
				i++;
			}
			top--;
		}
		else if(*ptr == '+'||*ptr == '-'||*ptr == '*'||*ptr == '/'){
			while(top!=0&&priority(Stack[top])>=priority(*ptr)){
					postfix[i++] = Stack[top--];
				}
				postfix[i++]=' ';
				Stack[++top] = *ptr;
		}
		else{
			postfix[i++]= *ptr;
		}
		ptr++;
	}
	while(top>0){
		postfix[i++] = Stack[top--];
	}
	
}

int main(){
	char input[5000]={'\0'};
	char output[5000]={'\0'};
	while(fgets(input,5000,stdin)){
		input[strlen(input)-1]='\0';
		in2post(input,output);
		for(int i=0;i<strlen(output);i++){
			if(output[i+1]=='+'||output[i+1]=='-'||output[i+1]=='*'||output[i+1]=='/'){
				printf("%c ",output[i]);
			}
			else{
				printf("%c",output[i]);
			}
		}
		printf("\n");
	        memset(output,'\0',strlen(output));
	}
}
