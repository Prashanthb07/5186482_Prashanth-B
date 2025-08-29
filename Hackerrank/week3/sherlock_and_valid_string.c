#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* isValid(char* s){
int f[26]={0};
for(int i=0;s[i]!='\0';i++){
if(s[i]>='a'&&s[i]<='z'){
f[s[i]-'a']+=1;
}
}
for(int i=0;i<26;i++){
printf("%d_",f[i]);
}
printf("\n");
int freq[101]={0};
int u[101]={0};
int u_count=0;
for(int i=0;i<26;i++){
if(f[i]>0&&f[i]<101){
freq[f[i]]++;
}
}
for(int i=0;i<101;i++){
printf("%d_",freq[i]);
}
printf("\n");
for(int i=1;i<101;i++){
if(freq[i]>0){
u[u_count++]=i;
}
}
for(int i=0;i<101;i++){
printf("%d_",u[i]);
}
if(u_count==1){
return "YES";
}
else if(u_count==2){
int f1=u[0];
int f2=u[1];
if((freq[f1]==1&&f1==1)||(freq[f2]==1&&f2==1)){
return "YES";
}
else if((freq[f1]==1&&f1-f2==1)||(freq[f2]==1&&f2-f1==1)){
return "YES";
}
else{
return "NO";
}
}
else{
return "NO";
}
return "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

