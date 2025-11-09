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
            strncat(s, a, 100000 - strlen(s) - 1);
        }

        //COMPARE
        else if(strcmp(command, "compare")==0){
            char b[10000]="";
            scanf(" \"%[^\"]", b); //預設輸入_"，並在遇到下一個"時停止輸入
            getchar(); //clean "
            if(strlen(s)==0 && strlen(b)==0){
                printf("equal\n");
                continue;
            }
            int len_s = strlen(s), len_b = strlen(b);
            int maxlen = len_s > len_b ? len_s : len_b;
            for(j=0; j<maxlen; j++){
                char cs=(j < len_s) ? tolower(s[j]) : '\0';
                char cb=(j < len_b) ? tolower(b[j]) : '\0';

                for(m=0;m<28;m++){
                    if(cs==dic[m]) break;
                }
                for(h=0;h<28;h++){
                    if(cb==dic[h]) break;
                }

                if(m<h){
                    printf("less\n");
                    break;
                }
                else if(m>h){
                    printf("greater\n");
                    break;
                }
                if(j == maxlen-1) printf("equal\n");
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
            char x='\0', y='\0';
            getchar();
            getchar();
            m = getchar();
            if (m == '\\') {
                getchar();
                x = '\0';
            }
            else x=m;
            getchar();
            getchar();
            getchar();
            m = getchar();
            if (m == '\\') {
                getchar();
                y = '\0';
            }
            else y=m;
            getchar();
            for(m=0;m<28;m++){
                if(dic[m]==x) dic[m]=y;
                else if(dic[m]==y) dic[m]=x;
            }
        }
    }
    return 0;
}