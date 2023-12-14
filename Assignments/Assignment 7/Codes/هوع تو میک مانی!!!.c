#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StringSize 1000
#define MaxUser 1000
int StartWith(const char *, const char *);
typedef struct {
    int users_count;
    int userId[MaxUser];
}Level;
typedef struct {
    int money;
    int level;
    int numOfIntro;
    char username[StringSize];
    char introducer[StringSize];
}User;
typedef struct {
    int money;
}Benjamin;
User * new_user(int money, int level, char *username,char * introducer){
    User * NewUser = malloc(sizeof(User));
    NewUser->money = money;
    NewUser->level = level;
    NewUser->numOfIntro = 0;
    memset(NewUser->username,0,StringSize); strcpy(NewUser->username,username);
    memset(NewUser->introducer,0,StringSize); strcpy(NewUser->introducer,introducer);
    return NewUser;
}
Level * new_level(){
    Level *NewLevel = malloc(sizeof(Level));
    for (int i = 0; i < MaxUser; ++i) {
        NewLevel->userId[i] = 0;
    }
    NewLevel->users_count = 0;
    return NewLevel;
}
int main() {
    Benjamin benjamin;
    benjamin.money = 0;
    char command[StringSize] = {0};
    int level_count = 0;
    int user_count = 0;
    User* Users[1000] = {NULL};
    Level* Levels[100] = {NULL};
    Users[0] = new_user(0,0,"\0","\0");
    while (1){
        memset(command,0,StringSize);
        scanf("%[^\n]s",command);
        scanf("%*c");
        if (StartWith("End",command)){
            break;
        }
        else if (StartWith("Create_a_table_for ",command)){
            char user[StringSize] = {0};
            int money = 0;
            sscanf(command,"Create_a_table_for %s with_deposit_of %d",user,&money);
            if (strlen(Users[0]->username)>0){
                printf("We already have a founder\n");
                continue;
            }
            if (money < 5000){
                printf("Money is not enough\n");
                continue;
            }
            Users[0]->money = money;
            strcpy(Users[0]->username,user);
            printf("You now own a table\n");
            user_count++;
            level_count++;
            Levels[0] = new_level();
            Levels[0]->userId[0] = 0;
            Levels[0]->users_count = 1;
            Users[0]->money -= 5000;
            benjamin.money += 5000;
        }
        else if (StartWith("Invitation_request_from",command)){
            char Introducer[StringSize] = {0};
            char Username[StringSize] = {0};
            int money = 0;
            sscanf(command,"Invitation_request_from %s for %s with_deposit_of %d",Introducer,Username,&money);
            int IntroducerIndex = 0;
            int trigger = 0;
            for (int i = 0; i < user_count; i++){
                if (!strcmp(Username,Users[i]->username)){
                    printf("Username already taken\n");
                    trigger = 1;
                    break;
                }
                if (!strcmp(Users[i]->username,Introducer)){
                    IntroducerIndex = i;
                }
            }
            if (trigger) continue;
            int IntroducerLevel = Users[IntroducerIndex]->level;
            int i = IntroducerLevel+1;
            if (Levels[i] == NULL){
                Levels[i] = new_level();
                level_count++;
            }
            while (Levels[i]->users_count >= i * i){
                i++;
                if(Levels[i] == NULL) {
                    Levels[i] = new_level();
                    level_count++;
                }
            }
            for(int k = 0; k < i; k++){
                for(int j = 0; j < Levels[k]->users_count; j++){
                    Users[Levels[k]->userId[j]]->money += (money / 2)/((i)*(Levels[k]->users_count));
                }
            }
            Users[user_count] = new_user(2*money/10,i,Username,Introducer);
            Levels[i]->userId[Levels[i]->users_count] = user_count;
            Levels[i]->users_count ++;
            Users[0]->money += 1*money/10;
            Users[IntroducerIndex]->money += 5*money/100;
            benjamin.money += 15*money/100;
            user_count++;
            Users[IntroducerIndex]->numOfIntro++;
            int UsersLevel = Users[IntroducerIndex]->level;
            int UserIndexInLevel;
            for(UserIndexInLevel = 0; UserIndexInLevel < Levels[UsersLevel]->users_count; UserIndexInLevel++){
                if (Levels[UsersLevel]->userId[UserIndexInLevel] == IntroducerIndex){
                    break;
                }
            }
            if (Users[IntroducerIndex]->numOfIntro == 5){
                if(Levels[UsersLevel-1]->users_count != (UsersLevel-1)*(UsersLevel-1)){
                    Levels[UsersLevel-1]->userId[Levels[UsersLevel-1]->users_count] = IntroducerIndex;
                    Levels[UsersLevel-1]->users_count++;
                    Levels[UsersLevel]->userId[UserIndexInLevel] = 0;
                    Users[IntroducerIndex]->level = UsersLevel-1;
                    Users[IntroducerIndex]->numOfIntro = 0;
                    for (int j = UserIndexInLevel; j < Levels[UsersLevel]->users_count ; ++j) {
                        Levels[UsersLevel]->userId[j] = Levels[UsersLevel]->userId[j+1];
                    }
                    Levels[UsersLevel]->users_count --;
                }
                else{
                    int chosen_index = 0;
                    if (Levels[UsersLevel-1]->users_count != 1) {
                        int min = Users[Levels[UsersLevel - 1]->userId[0]]->numOfIntro;
                        for (int j = 0; j < Levels[UsersLevel - 1]->users_count; ++j) {
                            if (Users[Levels[UsersLevel - 1]->userId[j]]->numOfIntro < min) {
                                min = Users[Levels[UsersLevel - 1]->userId[j]]->numOfIntro;
                                chosen_index = j;
                            }
                        }
                        if (min == Users[Levels[UsersLevel - 1]->userId[1]]->numOfIntro) {
                            int minMoney = Users[Levels[UsersLevel - 1]->userId[0]]->money;
                            for (int j = 0; j < Levels[UsersLevel - 1]->users_count; ++j) {
                                if (Users[Levels[UsersLevel - 1]->userId[j]]->money < minMoney) {
                                    minMoney = Users[Levels[UsersLevel - 1]->userId[j]]->money;
                                    chosen_index = j;
                                }
                            }
                        }
                        int ExchangeIndex = Levels[UsersLevel-1]->userId[chosen_index];
                        Users[ExchangeIndex]->level = UsersLevel;
                        for(int k = chosen_index; k < Levels[UsersLevel-1]->users_count; k++){
                            Levels[UsersLevel-1]->userId[k] = Levels[UsersLevel-1]->userId[k+1];
                        }
                        Users[IntroducerIndex]->level = UsersLevel-1;
                        for(int k = UserIndexInLevel; k < Levels[UsersLevel]->users_count; k++){
                            Levels[UsersLevel]->userId[k] = Levels[UsersLevel]->userId[k+1];
                        }
                        Levels[UsersLevel-1]->userId[Levels[UsersLevel-1]->users_count-1] = IntroducerIndex;
                        Levels[UsersLevel]->userId[Levels[UsersLevel]->users_count-1] = ExchangeIndex;
                    }else{
                        int ExchangeIndex = Levels[UsersLevel-1]->userId[0];
                        Users[ExchangeIndex]->level = UsersLevel;
                        for(int k = chosen_index; k < Levels[UsersLevel-1]->users_count; k++){
                            Levels[UsersLevel-1]->userId[k] = Levels[UsersLevel-1]->userId[k+1];
                        }
                        Users[IntroducerIndex]->level = UsersLevel-1;
                        for(int k = UserIndexInLevel; k < Levels[UsersLevel]->users_count; k++){
                            Levels[UsersLevel]->userId[k] = Levels[UsersLevel]->userId[k+1];
                        }
                        Levels[UsersLevel-1]->userId[Levels[UsersLevel-1]->users_count-1] = IntroducerIndex;
                        Levels[UsersLevel]->userId[Levels[UsersLevel]->users_count-1] = ExchangeIndex;
                    }
                }
            }
            printf("User added successfully in level %d\n",i);
        }
        else if (StartWith("Number_of_levels",command)){
            printf("%d\n",level_count);
        }
        else if (StartWith("Number_of_users_in_level",command)){
            int DesiredLevel;
            sscanf(command,"Number_of_users_in_level %d",&DesiredLevel);
            if (DesiredLevel >= level_count){
                printf("No_such_level_found\n");
            }else {
                printf("%d\n", Levels[DesiredLevel]->users_count);
            }
        }
        else if (StartWith("Number_of_users",command)){
            printf("%d\n",user_count);
        }
        else if (StartWith("Introducer_of",command)){
            char Username[StringSize] = {0};
            sscanf(command,"Introducer_of %s",Username);
            int triger = 0;
            for (int i = 0; i < user_count; i++) {
                if (!strcmp(Users[i]->username,Username)){
                    if (strlen(Users[i]->introducer)>0){
                        printf("%s\n",Users[i]->introducer);
                    }
                    else{
                        printf("No_introducer\n");
                    }
                    triger = 1;
                }
            }
            if (triger) continue;
            printf("No_such_user_found\n");
        }
        else if (StartWith("Credit_of",command)){
            char Username[StringSize] = {0};
            sscanf(command,"Credit_of %s",Username);
            int trigger = 0;
            for(int i = 0; i < user_count; i++){
                if (!strcmp(Username,Users[i]->username)){
                    printf("%d\n",Users[i]->money);
                    trigger = 1;
                }
            }
            if(trigger) continue;
            printf("No_such_user_found\n");
        }
        else if (StartWith("Users_on_the_same_level_with",command)){
            char UserName[StringSize] = {0};
            sscanf(command,"Users_on_the_same_level_with %s",UserName);
            int UserIndex = -1;
            for (int i = 0; i < user_count; ++i) {
                if (!strcmp(UserName,Users[i]->username)){
                    UserIndex = i;
                }
            }
            if (UserIndex == -1){
                printf("No_such_user_found\n");
                continue;
            }
            int UsersLevel = Users[UserIndex]->level;
            if (Levels[UsersLevel]->users_count == 1){
                printf("He_is_all_by_himself\n");
                continue;
            }
            for (int i = 0 ; i < Levels[UsersLevel]->users_count;i++){
                if(Levels[UsersLevel]->userId[i] != UserIndex){
                    printf("%s ",Users[Levels[UsersLevel]->userId[i]]->username);
                }
            }
            printf("\n");
        }
        else if (StartWith("Join_request_for",command)){
            char Username[StringSize] = {0};
            int money;
            int trigger = 0;
            sscanf(command,"Join_request_for %s with_deposit_of %d",Username,&money);
            for (int i = 0; i < user_count; i++){
                if (!strcmp(Username,Users[i]->username)){
                    trigger = 1;
                }
            }
            if (trigger) {
                printf("Username already taken\n");
                continue;
            }
            Users[user_count] = new_user(money*3/20,level_count,Username,"\0");
            Levels[level_count] = new_level();
            Levels[level_count]->userId[Levels[level_count]->users_count] = user_count;
            Levels[level_count]->users_count++;
            user_count++;
            printf("User added successfully in level %d\n",level_count);
            level_count++;
            benjamin.money += money/4;
            Users[0]->money += money/10;
            for(int k = 0; k < level_count-1; k++){
                for(int j = 0; j < Levels[k]->users_count; j++){
                    Users[Levels[k]->userId[j]]->money += (money / 2)/((level_count-1)*(Levels[k]->users_count));
                }
            }
        }
        else if (StartWith("How_much_have_we_made_yet",command)){
            printf("%d\n",benjamin.money);
        }
        else if (StartWith("Friends_of",command)){
            char Username[StringSize] = {0};
            int UserIndex = -1;
            sscanf(command,"Friends_of %s",Username);
            for(int i = 0; i < user_count; i++){
                if (!strcmp(Username,Users[i]->username)){
                    UserIndex = i;
                }
            }
            if (UserIndex == -1){
                printf("No_such_user_found\n");
                continue;
            }
            int UsersLevel = Users[UserIndex]->level;
            int LevelsUsersCount = Levels[UsersLevel]->users_count;
            int UserIndexID;
            for ( UserIndexID = 0; UserIndexID < LevelsUsersCount; UserIndexID++){
                if (Levels[UsersLevel]->userId[UserIndexID] == UserIndex){
                    break;
                }
            }
            if (Levels[UsersLevel]->users_count == 1){
                printf("No_friend\n");
                continue;
            }else if(Levels[UsersLevel]->users_count == 2){
                if (UserIndexID == 0){
                    printf("%s\n",Users[Levels[UsersLevel]->userId[1]]->username);
                }
                else{
                    printf("%s\n",Users[Levels[UsersLevel]->userId[0]]->username);
                }
            }else if (Levels[UsersLevel]->users_count == 3){
                printf("%s %s\n",
                       Users[Levels[UsersLevel]->userId[((UserIndexID-1)+LevelsUsersCount)%LevelsUsersCount]]->username,
                       Users[Levels[UsersLevel]->userId[((UserIndexID+1)+LevelsUsersCount)%LevelsUsersCount]]->username);
            }
        }
    }
    return 0;
}
int StartWith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}