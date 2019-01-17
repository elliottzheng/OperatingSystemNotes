//if变成while,csignal变成cnotify

void append(char x){
    while(count==N){ //if变成while
        cwait(notfull); //防止缓冲区溢出
    }
    buffer[nextin]=x;
    nextin=(nextin+1)%n;
    count++;
    cnotify(notempty);
}

void take(char x){
    while(count==0){ 
        cwait(notempty) //等待能进去访问
    }
    x=buffer[nextout];
    nextout=(nextout+1)%N;
    count--;
    cnotify(notfull); //释放任何一个正在等待notfull的进程
}