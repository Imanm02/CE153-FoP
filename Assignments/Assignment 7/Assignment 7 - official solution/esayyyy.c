#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int char2int(char a){
    if(a=='_')
        return 0;
    if(a=='-')
        return 1;
    if(a=='!')
        return 2;
    if(a=='@')
        return 3;
    if(a=='(')
        return 4;
    if(a==')')
        return 5;
    if(a=='%')
        return 6;
    if(a<='9' && a>='0')
        return a-'0' + 7;
    if(a<='Z' && a>='A')
        return a-'A' + 7 + 10;
    if(a<='z' && a>='a')
        return a-'a' + 7 + 10 + 26;
    return 7 + 10 + 26 + 26;
}

int cmp_char(char a,char b){
    int x = char2int(a);
    int y = char2int(b);
    if(x==y)
        return 0;
    return (x<y?-1:1);
}

int cmp_str(char* a,char* b){
    int i = 0;
    int j = 0;
    while(a[i]!='\0' && b[j]!='\0'){
        while(a[i]==' ')
            i++;
        while(b[j]==' ')
            j++;
        if(a[i]=='\0' || b[j]=='\0')
            break;
        if(cmp_char(a[i],b[j])!=0){
            return cmp_char(a[i],b[j]);
        }
        i++;j++;
    }
    if(a[i]=='\0' && b[j]=='\0')
        return 0;
    else
        return (a[i]=='\0'?-1:1);
}

void sort(char** a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j+1<n;j++){
            if(cmp_str(a[j],a[j+1])>0){
                char* tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

size_t MAX = 1000;

int main(){
    int n;
    scanf("%d ",&n);
    char** a = malloc(n * sizeof(char*));
    for(int i=0;i<n;i++){
        a[i] = malloc(MAX * sizeof(char));
        getline(&a[i],&MAX,stdin);
        if(a[i][strlen(a[i])-1]=='\n'){
            a[i][strlen(a[i])-1] = '\0';
        }
    }
    sort(a,n);
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
    return 0;
}

