#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n; //there will be n commands later
    scanf("%d", &n);
    char dic[28] = {'\0', ' ', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char s[100000]={'\0'};

    int i, j, m, h; //counters

    for(int i=0;i<n;i++){
        char command[10]="";
        scanf("%s", command); //句尾留下\n應該不影響這個...

        //APPEND
        if(strcmp(command, "append")==0){
            char a[10000]="";
            scanf(" \"%[^\"]", a);  //預設輸入_"，並在遇到下一個"時停止輸入
            getchar(); //clean "
            strcat(s,a);
        }

        //COMPARE (c can be letters or ' ')
        else if(strcmp(command, "compare")==0){
            char b[10000]="";
            scanf(" \"%[^\"]", b); //預設輸入_"，並在遇到下一個"時停止輸入
            getchar(); //clean "
            for(j=0; j<strlen(s) || s[0]=='\0'; j++){
                for(m=0;m<28;m++){
                    if(tolower(s[j])==dic[m]) break;
                }
                for(h=0;h<28;h++){
                    if(tolower(b[j])==dic[h]) break;
                }
                if(m<h){
                    printf("less\n");
                    break;
                }
                else if(m>h){
                    printf("greater\n");
                    break;
                }
                else if(s[0]=='\0') break; //s[0]=='\0' && c[0]=='\0', m=n=0
                else continue; //j==m && s[0]!='\0'
            }
            if(m==h){
                printf("equal\n");
            }
        }

        //COUNT
        else if(strcmp(command, "count")==0){
            int time=0;
            char c[10000]="";
            scanf(" \"%[^\"]", c);
            getchar();
            char *find = s; //find指向s的第一位
            while((find = strstr(find, c))!= NULL){ //看find裡面有沒有b然後如果有找到的話
                find++; //移到那個位子的往右一個字再繼續找
                time++;
            }
            printf("%d\n", time);
        }

        //BACKSPACE
        else if(strcmp(command, "backspace")==0){
            int trash;
            scanf("%d", &trash);
            if(trash>strlen(s)) s[0]='\0';
            else s[strlen(s)-trash] = '\0';
        }
        else if(strcmp(command, "toupper")==0){
            for(int i=0;i<strlen(s);i++) s[i]=toupper(s[i]);
        }
        else if(strcmp(command, "tolower")==0){
            for(int i=0;i<strlen(s);i++) s[i]=tolower(s[i]);
        }
        else if(strcmp(command, "print")==0) printf("\"%s\"\n", s);

        //SWAP
        else if(strcmp(command, "swap")==0){
            char x, y;
            getchar(); //space

            for(h=0;h<3;h++){
                m=getchar();
                if(m==39) continue;
                if(m==92){
                    x='\0';
                    getchar();
                }
                else x=(char)m;
            }

            getchar();
            for(h=0;h<3;h++){
                m=getchar();
                if(m==39) continue;
                if(m==92){
                    y='\0';
                    getchar();
                }
                else y=(char)m;
            }
            
            for(m=0;m<28;m++){
                if(dic[m]==x) dic[m]=y;
                else if(dic[m]==y) dic[m]=x;
                else continue;
            }
        }
    }
    return 0;
}