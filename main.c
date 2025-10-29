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
            char c[10000]="";
            scanf(" \"%[^\"]", c); //預設輸入_"，並在遇到下一個"時停止輸入
            getchar(); //clean "
            if(s[0]=='\0'){ //if s is '\0'
                for(j=0;j<28;j++){
                    if(s[0]==dic[j]) break;
                }
                for(m=0;m<28;m++){
                    if(tolower(c[0])==dic[m]) break;
                }
                if(j<m){
                    printf("less\n");
                }
                else if(j>m){
                    printf("greater\n");
                }
                else printf("equal\n");
            }
            else{
                for(h=0;h<strlen(s);h++){
                    for(m=0;m<28;m++){
                        if(tolower(c[h])==dic[m]) break;
                    }
                    for(j=0;j<28;j++){
                        if(tolower(s[h])==dic[j]) break;
                    }
                    if(j<m){
                        printf("less\n");
                        break;
                    }
                    else if(j>m){
                        printf("greater\n");
                        break;
                    }
                    else if(strlen(s)==0) break; //j==m且s=='\0'==b strlen是0所以要故意跳出去
                    else continue;
                }
                if(m==j){
                    printf("equal\n");
                }
            }
        }

        else if(strcmp(command, "count")==0){
            int appearances=0;
            char b[10000]="";
            scanf(" \"%[^\"]\"", b);
            getchar();
            char *find = s; //find指向s的第一位
            while((find = strstr(find, b))!= NULL){ //看find裡面有沒有b然後如果有找到的話
                find++; //移到那個位子的往右一個字再繼續找
                appearances++;
            }
            printf("%d\n", appearances);
        }
        else if(strcmp(command, "backspace")==0){
            int end;
            scanf("%d", &end);
            if(end>strlen(s)) s[0]='\0';
            else s[strlen(s)-end] = '\0';
        }
        else if(strcmp(command, "toupper")==0){
            for(int i=0;i<strlen(s);i++) s[i]=toupper(s[i]);
        }
        else if(strcmp(command, "tolower")==0){
            for(int i=0;i<strlen(s);i++) s[i]=tolower(s[i]);
        }
        else if(strcmp(command, "print")==0) printf("\"%s\"\n", s);

        else if(strcmp(command, "swap")==0){
            int m;
            char x, y;
            int dk;
            getchar(); //space
            getchar(); //'
            dk=getchar();
            if(dk=='\\'){
                getchar();
                x='\0';
            }
            else x=(char)dk;
            getchar(); //'
            getchar(); //space
            getchar(); //'
            dk=getchar();
            if(dk=='\\'){
                getchar();
                y='\0';
            }
            else y=(char)dk;
            getchar(); //'
            for(m=0;m<28;m++){
                if(dic[m]==x) dic[m]=y;
                else if(dic[m]==y) dic[m]=x;
            }
        }
    }
    return 0;
}