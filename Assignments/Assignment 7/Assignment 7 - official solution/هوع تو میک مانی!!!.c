#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

typedef struct __user{
    int credit;
    int level;
    int introduce_number;
    char username[MAX];
    int introducer;
} User;

typedef struct __cycle{
    int level;
    int users_number;
    int* users;
} Cycle;

User* users = NULL;
int users_number=0;

int founder = -1;

Cycle* levels = NULL;
int levels_number=0;
int our_profit = 0;

int level_capacity(int level){
    if(level==0)
        return 1;
    return level*level;
}

int add_user_to_level(int user,int level){
    if(level==0){
        while(level>=levels_number){
            levels = realloc(levels,(levels_number+1)*sizeof(Cycle));
            levels_number++;
        }
        levels[0].level = 0;
        levels[0].users_number = 1;
        levels[0].users = malloc(sizeof(int));
        levels[0].users[0] = user;
        return 0;
    }
    while(level < levels_number && levels[level].users_number>=level_capacity(level))
        level++;
    while(level>=levels_number){
        levels = realloc(levels,(levels_number+1)*sizeof(Cycle));
        levels[levels_number].level = levels_number;
        levels[levels_number].users_number = 0;
        levels[levels_number].users = NULL;
        levels_number++;
    }
    levels[level].users = realloc(levels[level].users,(levels[level].users_number + 1 )*sizeof(int));
    levels[level].users[levels[level].users_number] = user;
    levels[level].users_number++;
    return level;
}

void remove_user_from_level(int user,int level){
    int* tmp = malloc((levels[level].users_number-1)*sizeof(int));
    int i,j;
    for(i=0,j=0;i<levels[level].users_number;i++){
        if(levels[level].users[i]==user){
            continue;
        }
        tmp[j++] = levels[level].users[i];
    }
    free(levels[level].users);
    levels[level].users = tmp;
    levels[level].users_number = j;
}

int add_new_user(char* username,int level,int introducer,int credit){
    users = realloc(users,(users_number+1)*sizeof(User));
    User* tmp = &users[users_number];
    users_number++;
    strcpy(tmp->username,username);
    tmp->introducer = introducer;
    tmp->credit = credit;
    tmp->introduce_number = 0;
    tmp->level = add_user_to_level(users_number-1,level);
    return users_number-1;
}

int find_user(char* username){
    for(int i=0;i<users_number;i++){
        if(strcmp(users[i].username,username)==0){
            return i;
        }
    }
    return -1;
}

void divide_money_in_level(int level,int money){
    for(int i=0;i<levels[level].users_number;i++){
        users[levels[level].users[i]].credit += money / levels[level].users_number;
    }
}

void level_up(int user){
    int level = users[user].level;
    if(level==0){
        return;
    }
    if(levels[level - 1].users_number < level_capacity(level-1)){
        remove_user_from_level(user,users[user].level);
        users[user].level = level-1;
        add_user_to_level(user,users[user].level);
        return;
    }
    int user_place=0;
    for(int i=0;i<levels[level].users_number;i++){
        if(levels[level].users[i]==user){
            user_place = i;
            break;
        }
    }
    int min_user = -1;
    int min_intro = 1e9;
    int min_money = 1e9;
    for(int i=0;i<levels[level-1].users_number;i++){
        int cmp_user = levels[level-1].users[i];
        if(users[cmp_user].introduce_number < min_intro){
            min_user = i;
            min_intro = users[cmp_user].introduce_number;
            min_money = users[cmp_user].credit;
        }
        else if(users[cmp_user].introduce_number == min_intro){
            if(users[cmp_user].credit < min_money){
                min_user = i;
                min_intro = users[cmp_user].introduce_number;
                min_money = users[cmp_user].credit;
            }
        }
    }
    int min_userid = levels[level-1].users[min_user];
    remove_user_from_level(user,level);
    remove_user_from_level(min_userid,level-1);
    users[min_userid].level++;
    users[user].level--;
    add_user_to_level(user,level-1);
    add_user_to_level(min_userid,level);
}

void find_user_friends(int user,int* left,int* right){
    int level = users[user].level;
    if(levels[level].users_number<=1){
        *left = -1;
        *right = -1;
        return;
    }
    if(levels[level].users_number==2){
        *right = -1;
        if(levels[level].users[0]==user){
            *left = levels[level].users[1];
        }
        else{
            *left = levels[level].users[0];
        }
        return;
    }
    int user_place = 0;
    for(int i=0;i<levels[level].users_number;i++){
        if(levels[level].users[i]== user){
            user_place = i;
            break;
        }
    }
    int levelnum = levels[level].users_number;
    
    int left_place = levels[level].users[(user_place-1+levelnum)%levelnum];
    *left = left_place;
    int right_place = levels[level].users[(user_place+1)%levelnum];
    *right = right_place;
    if(left_place==right_place){
        *right = -1;
    }
}

int main(){
    char input[MAX];
    while(1){
        scanf(" %[^\n]",input);
        if(strstr(input,"Create_a_table_for")!=NULL){
            if(founder!=-1){
                printf("We already have a founder\n");
                continue;
            }
            char username[MAX];
            int money;
            sscanf(input,"Create_a_table_for %s with_deposit_of %d",username,&money);
            if(money<5000){
                printf("Money is not enough\n");
                continue;
            }
            founder = add_new_user(username,0,-1,money-5000);
            our_profit += 5000;
            printf("You now own a table\n");
        }
        else if(strstr(input,"Invitation_request_from")!=NULL){
            char from[MAX];
            char to[MAX];
            int money;
            sscanf(input,"Invitation_request_from %s for %s with_deposit_of %d",from,to,&money);
            if(find_user(to)!=-1){
                printf("Username already taken\n");
                continue;
            }
            int intro = find_user(from);
            int tmp_place = add_new_user(to,users[intro].level+1,intro,0);
            User* tmp = &users[tmp_place];
            users[intro].introduce_number++;
            if(users[intro].introduce_number >= 5){
                level_up(intro);
                users[intro].introduce_number = 0;
            }
            //divide_money_in_level(tmp->level,money*0.2);
            tmp->credit += money*0.2;
            users[founder].credit += money*0.1;
            users[intro].credit += money*0.05;
            our_profit += money*0.15;
            for(int i=0;i<tmp->level;i++){
                divide_money_in_level(i,money*0.5 / tmp->level);
            }
            printf("User added successfully in level %d\n",tmp->level);
        }
        else if(strstr(input,"Join_request_for")!=NULL){
            char username[MAX];
            int money;
            sscanf(input,"Join_request_for %s with_deposit_of %d",username,&money);
            if(find_user(username)!=-1){
                printf("Username already taken\n");
                continue;
            }
            int tmp_place = add_new_user(username,levels_number,-1,0);
            User* tmp = &users[tmp_place];
            //divide_money_in_level(tmp->level,money*0.15);
            tmp->credit += money*0.15;
            users[founder].credit += money*0.1;
            our_profit += money*0.25;
            for(int i=0;i<tmp->level;i++){
                divide_money_in_level(i,money*0.5 / tmp->level);
            }
            printf("User added successfully in level %d\n",tmp->level);
        }
        else if(strstr(input,"Number_of_levels")!=NULL){
            printf("%d\n",levels_number);
        }
        else if(strstr(input,"Number_of_users_in_level")!=NULL){
            int level;
            sscanf(input,"Number_of_users_in_level %d",&level);
            if(level>=levels_number){
                printf("No_such_level_found\n");
                continue;
            }
            printf("%d\n",levels[level].users_number);
        }
        else if(strstr(input,"Number_of_users")!=NULL){
            printf("%d\n",users_number);
        }
        else if(strstr(input,"Introducer_of")!=NULL){
            char username[MAX];
            sscanf(input,"Introducer_of %s",username);
            int tmp = find_user(username);
            if(tmp==-1){
                printf("No_such_user_found\n");
                continue;
            }
            if(users[tmp].introducer==-1){
                printf("No_introducer\n");
                continue;
            }
            printf("%s\n",users[users[tmp].introducer].username);
        }
        else if(strstr(input,"Friends_of")!=NULL){
            char username[MAX];
            sscanf(input,"Friends_of %s",username);
            int user = find_user(username);
            if(user==-1){
                printf("No_such_user_found\n");
                continue;
            }
            int left;
            int right;
            find_user_friends(user,&left,&right);
            if(left==-1 && right==-1){
                printf("No_friend\n");
                continue;
            }
            else if(right==-1){
                printf("%s\n",users[left].username);
            }
            else{
                printf("%s %s\n",users[left].username,users[right].username);
            }
        }
        else if(strstr(input,"Credit_of")!=NULL){
            char username[MAX];
            sscanf(input,"Credit_of %s",username);
            int user = find_user(username);
            if(user==-1){
                printf("No_such_user_found\n");
                continue;
            }
            printf("%d\n",users[user].credit);
        }
        else if(strstr(input,"Users_on_the_same_level_with")!=NULL){
            char username[MAX];
            sscanf(input,"Users_on_the_same_level_with %s",username);
            int tmp = find_user(username);
            if(tmp==-1){
                printf("No_such_user_found\n");
                continue;
            }
            int level = users[tmp].level;
            if(levels[level].users_number==1){
                printf("He_is_all_by_himself\n");
                continue;
            }
            for(int i=0;i<levels[level].users_number;i++){
                int cur = levels[level].users[i];
                if(cur==tmp)
                    continue;
                printf("%s ",users[cur].username);
            }
            printf("\n");
        }
        else if(strstr(input,"How_much_have_we_made_yet")!=NULL){
            printf("%d\n",our_profit);
        }
        else if(strstr(input,"End")!=NULL){
            break;
        }
    }
    free(users);
    free(levels);
}
