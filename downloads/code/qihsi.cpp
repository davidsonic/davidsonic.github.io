#include <iostream>
using namespace std;
int goal[5][5]= {
        {1,1,1,1,1},
        {0,1,1,1,1},
        {0,0,2,1,1},
        {0,0,0,0,1},
        {0,0,0,0,0}
};
int Map[5][5],T,pd;
int fx[8]= {1,-1,2,-2,1,-1,2,-2};
int fy[8]= {2,2,-1,-1,-2,-2,1,1};
int stx,sty;
int check() {
    int ret=0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(Map[i][j]!=goal[i][j]) ret++;
    return ret;
}
bool IDA(int left, int x,int y) {
    int h = check();
    if(!h) return true;
//    if(h-1>left) return false; //where * comes from, pruning procedure
    if(left==0) return false;
    for(int i=0; i<8; i++) {
        int x1=x+fx[i];
        int y1=y+fy[i];
        if(x1<0||x1>4||y1<0||y1>4) continue;
        swap(Map[x1][y1],Map[x][y]);
        if(IDA(left-1,x1, y1)) return true;
        swap(Map[x1][y1],Map[x][y]);
    }
    return false;
}
int main() {
    cin>>T;
    while(T--) {
        pd=0;
        for(int i=0; i<5; i++) {
            char s[10];
            scanf("%s",s);
//            printf("%s\n", s);
            for(int j=0; j<5; j++) {
                if(s[j]-'0'==0) Map[i][j]=0;
                if(s[j]-'0'==1) Map[i][j]=1;
                if(s[j]=='*') Map[i][j]=2,stx=i,sty=j;
            }
        }
//        for(int i=0;i<5;i++){
//            for(int j=0;j<5;j++)
//                printf("%d ", Map[i][j]);
//            printf("\n");
//        }
        for(int i=1; i<=15; i++)
            if(IDA(i,stx, sty)) {
                pd=i;
                break;
            }
        if(pd) cout<<pd<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}