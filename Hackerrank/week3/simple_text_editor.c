#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct{
    char t;
    char *hstring;
}undo;


int main() {


int Q;
scanf("%d",&Q);
     
char *text=calloc(1,sizeof(char));
int textl=0;

undo *history=malloc(Q* sizeof(undo));
int top = -1;


    for (int i = 0; i < Q; i++) {
        int op;
        scanf("%d", &op);
        if(op==1){
            char input[1000001];
            scanf("%s",input);
            int len=strlen(input);
            text=realloc(text,textl+len+1);
            strcat(text,input);
            textl+=len;
            top++;
            history[top].t='a';
            history[top].hstring=strdup(input);
        }     
        
         else if(op==2){
            int k;
            scanf("%d",&k);
            char *del = malloc(k+1);
            strncpy(del,text+textl-k,k);
            del[k]='\0';
            textl -= k;
            text[textl] ='\0';
            top++;
            history[top].t='d';
            history[top].hstring=del;
        }
        
         else if(op==3){
            int k;
            scanf("%d",&k);
            if (k>=1 && k<=textl) {
                printf("%c\n", text[k-1]);
            }
        } 
        
        else if(op==4) { 
            if(top>=0){
                undo last=history[top--];
            if(last.t=='a'){
                    int len=strlen(last.hstring);
                    textl-=len;
                    text[textl]='\0';
                }
                 else if(last.t=='d') 
                 {
                 int len =strlen(last.hstring);
                 text = realloc(text,textl+len+1);
                 strcpy(text+textl,last.hstring);
                 textl +=len;
                }
     free(last.hstring);
            }
        }
    }

    free(text);
    for(int i=0;i<=top;i++) {
        free(history[i].hstring);
    }
    free(history);
    
    return 0;
}
