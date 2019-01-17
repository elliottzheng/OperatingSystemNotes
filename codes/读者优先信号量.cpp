//读者优先，读进程可以跟读，写进程不可以跟写

int readcount; //读进程有多少个
semaphore x=1,wsem=1; //没看懂这个x是要干嘛的
//哦哦，我知道了，这个x是用来控制对readcount的访问权限的。

void reader(){
    while(true){
        semWait(x);
        readcount++;
        if(readcount==1){ //第一个读进程需要等待
            semWait(wsem);
        }
        semSignal(x);
        READUNIT();
        semWait(x);
        readcount--; 
        if(readcount==0){
            semSignal(wsem); //最后一个读进程可以释放权限。
        }
        semSignal(x);
    }
}

void writer(){
    while(true){
        semWait(wsem);
        WRITEUNIT();
        semSignal(wsem);
    }
}

void main(){
    readcount=0;
    parbegin(reader,writer);
}