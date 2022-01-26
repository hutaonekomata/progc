#include<stdio.h>
#include<hamako.h>

typedef struct{
    char fname[20];
    char sneme[20];
    int jap;
    int math;
    int eng;
    int rank;
    double ave;
    int no;
    int sum;
    double japave;
    double mathave;
    double engave;
}student;

void showbit(int num);
void ave(int n,int k,int i,student all[]);
void sum3(int k,int i,student mem[],student all[]);
void getdata(int n,student mem[],student all[],int range[]);
void outdata(int n,student mem[],student all[],int range[]);
int getN(void);
void sort(int n,student mem[]);
void enterrank(int n,student mem[]);

int main(){
    student mem[101];
    student all[2];
    int range[7]={};
    int n;
    // 生徒人数を入力
    printf("\n\n");
    n = getN();
    printf("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\tSuccess!\n\n@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    // データを入力
    getdata(n,mem,all,range);
    // 合計を取得
    // 平均を取得
    // 並べ替え
    // 順位づけ
    // 出力
    outdata(n,mem,all,range);
    return(0);
}

void getdata(int n,student mem[],student all[],int range[]){
    char buff[256];
    int k;
    for(int i=1;i<=n;i++){
        fgets(buff, sizeof(buff), stdin);
        sscanf(buff, "%d %s %s %d %d %d",&mem[i].no,&mem[i].fname,&mem[i].sneme,&mem[i].jap,&mem[i].math,&mem[i].eng);
        mem[i].sum = mem[i].jap + mem[i].math + mem[i].eng;
        mem[i].ave = (double)mem[i].sum / 3;
        sum3(0,i,mem,all);
        range[(mem[i].sum/50)]++;
    }
    ave(n,1,0,all);
    sort(n,mem);
    enterrank(n,mem);
    return;
}

int getN(void){
    int n;
    printf("\n\n\x1b[31m<!>\033[m\x1b[4m Please enter a number from 1 to 100\x1b[0m\x1b[31m<!>\033[m\nEnter the number of people in the class => ");
    n = getint("");
    if(n<1||100<n){
        n = getN();
    }
    return(n);
}

void sum3(int k,int i,student mem[],student all[]){
    all[k].jap+=mem[i].jap;
    all[k].math+=mem[i].math;
    all[k].eng+=mem[i].eng;
    all[k].sum+=mem[i].sum;
    return;
}

void ave(int n,int k,int i,student all[]){
    all[k].japave=(double)all[i].jap / n;
    all[k].mathave=(double)all[i].math / n;
    all[k].engave=(double)all[i].eng / n;
    all[k].ave=(double)all[i].sum / n;
    return;
}

void enterrank(int n,student mem[]){
    int rank;
    for(int i=1;i<=n;i++){
        rank=n+1;
        for(int j=1;j<=n;j++){
            if(mem[i].sum>=mem[j].sum){
                rank--;
            }
        }
        mem[i].rank=rank;
    }
    return;
}

void sort(int n,student mem[]){
    for(int i=1;i<=n-1;i++){
        for(int j=i;j<=n;j++){
            if(mem[i].no>mem[j].no){
                mem[0] = mem[i];
                mem[i]=mem[j];
                mem[j]=mem[0];
            }
        }
    }
    return;
}

void outdata(int n,student mem[],student all[],int range[]){
    printf("\x1b[41m| No | First Name | Second Name |  Japanese |    Math |   English |      Sum | Rank | Average |\x1b[m\n");
    for(int i=1;i<=n;i++){
        printf("%5d %12s %13s %10d %10d %10d %10d %6d %9.2lf\n",mem[i].no,mem[i].fname,mem[i].sneme,mem[i].jap,mem[i].math,mem[i].eng,mem[i].sum,mem[i].rank,mem[i].ave);
    }
    printf("\n\t\t\t合計 %14d %10d %10d %10d\n",all[0].jap,all[0].math,all[0].eng,all[0].sum);
    printf("\t\t\t平均 %14.2lf %10.2lf %10.2lf %10.2lf\n\n",all[1].japave,all[1].mathave,all[1].engave,all[1].ave);
    int k=50;
    for(int i=0;i<7;i++){
        if(i<6){
            printf("%3d - %3d [%3d] ",k*i,k*i+49,range[i]);
        }else{
            printf("%3d       [%3d] ",k*i,range[i]);
        }
        showbit(range[i]);
        printf("\n");
    }
    return;
}

void showbit(int num){
    for(int i=0;i<num;i++){
        printf("*");
    }
    return;
}