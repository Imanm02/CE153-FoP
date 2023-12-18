#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int PRINT_MODE = 1;

void print(char* str){
    if(PRINT_MODE)
        printf("%s\n",str);
}

char* append(char* str,char* t){
    int len = strlen(str) + strlen(t) + 1;
    char* newstr = realloc(str , len);
    if(newstr==NULL){
        exit(0);
    }
    str = newstr;
    strcat(str,t);
    return str;
}

char* copy(char* str,int n){
    char* tmp = malloc(strlen(str)+1);
    strcpy(tmp,str);
    for(int i=0;i<n;i++){
    str = append(str,tmp);
    }
    free(tmp);
    return str;
}

char* find(char* str,char* t){
    int n = 0;
    char* tmp = str;
    while(1){
        char* x = strstr(tmp,t);
        if(x==NULL){
            break;
        }
        n++;
        tmp = x + 1;
    }
    if(n==0){
        str = append(str,t);
        return str;
    }
    char* string_num = malloc(10);
    sprintf(string_num,"%d",n);
    str = append(str,string_num);
    free(string_num);
    return str;
}

char* count_alph(char* str){
    int n = 0;
    int i = 0;
    while(str[i]!='\0'){
        if(isalpha(str[i]))
            n++;
        i++;
    }
    char string_num[10];
    sprintf(string_num,"%d",n);
    str = append(str,string_num);
    return str;
}

char* count_dig(char* str){
    int n = 0;
    int i = 0;
    while(str[i]!='\0'){
        if(isdigit(str[i]))
            n++;
        i++;
    }
    char string_num[10];
    sprintf(string_num,"%d",n);
    str = append(str,string_num);
    return str;
}

char* count_char(char* str,char t){
    int n = 0;
    int i = 0;
    while(str[i]!='\0'){
        if(t==str[i])
            n++;
        i++;
    }
    char string_num[10];
    sprintf(string_num,"%d",n);
    str = append(str,string_num);
    return str;
}

char* delete_one(char* str,int i,int len){
    for(;str[i+len]!='\0';i++){
        str[i] = str[i+len];
    }
    str[i] = '\0';
    return str;
}

char* delete(char* str,char* t){
    int i = 0;
    int t_len = strlen(t);
    while(strstr(str+i,t)!=NULL){
        i = strstr(str+i,t) - str;
        str = delete_one(str,i,t_len);
    }
    return str;
}

void reverse(char* start,char* end){
    end--;
    while(start < end){
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int main(){
    size_t MAX = 100 + 2;
    char* str = malloc(MAX);
    scanf("%s",str);
    char* input = malloc(MAX);
    char* command = malloc(20);
    while(1){
        scanf(" %[^\n]",input);
        sscanf(input,"%s",command);
        if(strcmp(command,"copy")==0){
            int x = 1;
            if(strcmp(input,"copy")!=0){
                sscanf(input,"copy %d",&x);
            }
            str = copy(str,x);
            print(str);
        }
        else if(strcmp(command,"append")==0){
            char* tmp = malloc(MAX);
            sscanf(input,"append %[^\n]",tmp);
            str = append(str,tmp);
            free(tmp);
            print(str);
        }
        else if(strcmp(command,"find")==0){
            char* tmp = malloc(MAX);
            sscanf(input,"find %[^\n]",tmp);
            str = find(str,tmp);
            free(tmp);
            print(str);
        }
        else if(strcmp(command,"count")==0){
            if(strcmp(input,"count alphabets")==0){
                str = count_alph(str);
            }
            else if(strcmp(input,"count digits")==0){
                str = count_dig(str);
            }
            else{
                char tmp;
                sscanf(input,"count %c",&tmp);
                str = count_char(str,tmp);
            }
            print(str);
        }
        else if(strcmp(command,"delete")==0){
            char* tmp = malloc(MAX);
            sscanf(input,"delete %[^\n]",tmp);
            str = delete(str,tmp);
            free(tmp);
            print(str);
        }
        else if(strcmp(command,"reverse")==0){
            if(strcmp(input,"reverse")==0){
                reverse(str,str+strlen(str));
            }
            else{
                int n,m;
                sscanf(input,"reverse %d,%d",&n,&m);
                reverse(str+n,str+m);
            }
            print(str);
        }
        else if(strcmp(command,"PRINT_MODE")==0){
            char* tmp = malloc(10);
            sscanf(input,"PRINT_MODE %[^\n]",tmp);
            if(strcmp(tmp,"ON")==0){
                PRINT_MODE = 1;
            }
            else{
                PRINT_MODE = 0;
            }
            free(tmp);
        }
        else if(strcmp(command,"print")==0){
            printf("%s\n",str);
        }
        else if(strcmp(command,"exit")==0){
            break;
        }
        else{
            break;
        }
    }
    free(str);
    free(input);
    free(command);
}