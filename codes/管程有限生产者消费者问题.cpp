monitor boundedbuffer; //关键词

char buffer[N];
int nextin,nextout;
int count;
cond notfull,notempty;

void append(char x){
    if(count==N){
        cwait(notfull) //防止缓冲区溢出
    }
    buffer[nextin]=x;
    nextin=(nextin+1)%n;
    count++;
    csignal(notempty);
}

void take(char x){
    if(count==0){
        cwait(notempty) //等待能进去访问
    }
    x=buffer[nextout];
    nextout=(nextout+1)%N;
    count--;
    csignal(notfull); //释放任何一个正在等待notfull的进程
}
{//管程体
    nextin=0;nextout=0;count=0;//缓冲区初始化为空
}








/////////////////////////////////////////////////////////////////////
void producer(){
    char x;
    while(true){
        produce();
        append();
    }
}

void consumer(){
    char x;
    while(true){
        take(x);
        consume(x);
    }
}


void main(){
    parbegin(consumer,producer);
}